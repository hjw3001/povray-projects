// LightTower.inc
//
// POV model of a stadium light tower.
//
// Created by: Henry Wagner (povray@henrywagner.org)

#version unofficial megapov 1.1;

#declare TowerHeight = 80;
#declare MainTowerDiameter = 0.8;
#declare CrossBarLength = 15;
#declare CrossBarDiamenter = 0.5;
#declare CrossBarSpacing = 6.7;
#declare NumCrossBars = 6;
#declare NumLightsPerBar = 10;
#declare LightDiameter = 0.62;

#declare RsA = seed(574647);

#declare useLight = false;

#declare TowerMetal = texture {
    pigment { color rgb 0.9 }
}

#declare LightConeMetal = texture {
    pigment { color rgb 0.5 }
}

#macro LightBall()
    #if (useLight = true)
        light_source {
            < 0, 0, 0>,
    	    color White+Gold
    	    glow { size 0.01 type 0}
    	    fade_distance 10 fade_power .001
        }
    #else
        sphere {
            < 0, 0, 0 >, LightDiameter
            texture {
                pigment { color White+Gold }
                finish { ambient 1 diffuse 0 }
            }
        }
    #end
#end

#macro LightTower()
    union {
        cylinder {
            < 0, 0, 0 >,
            < 0, TowerHeight, 0 >,
            MainTowerDiameter
        }
        sphere {
            < 0, 0, 0 >,
            MainTowerDiameter
        }
        sphere {
            < 0, TowerHeight, 0 >,
            MainTowerDiameter
        }
        // Create the cross bars the hold the lights
        #declare counter = 0;
        #declare crossBarHeight = TowerHeight / 2;
        #while (counter < NumCrossBars)
            cylinder {
                < -(CrossBarLength/2), crossBarHeight, 0 >,
                <  (CrossBarLength/2), crossBarHeight, 0 >,
                CrossBarDiamenter
            }
            sphere {
                < -(CrossBarLength/2), crossBarHeight, 0 >,
                CrossBarDiamenter
            }
            sphere {
                <  (CrossBarLength/2), crossBarHeight, 0 >,
                CrossBarDiamenter
            }
            // Add the light balls to the cross bar
            #declare lightBallCount = 0;
            #declare lightPosition = -(CrossBarLength/2) + (CrossBarLength/(NumLightsPerBar + 1));
            #while (lightBallCount < NumLightsPerBar)
                union {
                    cylinder {
                        < 0, 0,  LightDiameter >,
                        < 0, 0,  LightDiameter+.1 >,
                        LightDiameter
                        texture { LightConeMetal }                    
                    }
                    cone {
                        < 0, 0,  LightDiameter >, LightDiameter
                        < 0, 0, -LightDiameter >, (LightDiameter*2)
                        open
                        texture { LightConeMetal }
                    }
                    object {
                        LightBall()
                    }
                    rotate < -45, 0, 0 >
                    translate < lightPosition, crossBarHeight, -(CrossBarDiamenter+LightDiameter) >
                }
                #declare lightBallCount = lightBallCount + 1;
                #declare lightPosition = lightPosition + (CrossBarLength/(NumLightsPerBar + 1));
            #end
            
            #declare counter = counter + 1;
            #declare crossBarHeight = crossBarHeight + CrossBarSpacing;
        #end
        texture { TowerMetal }        
    }
#end
