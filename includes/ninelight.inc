// ninelight.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare BoxWH = 1.5;
#declare BoxD = 0.5;
#declare LightRad = 0.15;

#declare NineBoxTexture = texture {
    pigment { color rgb 0.1 }
}

#macro NineLight(useLights)
union {
    // The box that holds the lights
    box {
        < -(BoxWH/2), 0, BoxD >,
        <  BoxWH/2, BoxWH, 0 >
        texture { NineBoxTexture }
    }
    
    #declare xCounter = 1;
    
    union {
    #while (xCounter < 4)
        #declare yCounter = 1;
        #while (yCounter < 4)
            #if (useLights = true)
                light_source {
                    < (0.25*BoxWH*xCounter), (0.25*BoxWH*yCounter), 0 >
                    color White+Gold
                    fade_distance 20
                    fade_power 3
                    media_attenuation on
                    looks_like {
                        sphere {
                            < 0, 0, 0 >,
                            LightRad
                            scale < 1, 1, 0.9 >
                            texture {
                                pigment { color White+Gold }
                                finish { ambient 1 diffuse 0 }
                            }
                        }
                    }
                }
            #else
                sphere {
                    < (0.25*BoxWH*xCounter), (0.25*BoxWH*yCounter), 0 >,
                    LightRad
                    scale < 1, 1, 0.9 >
                    texture {
                        pigment { color White+Gold }
                        finish { ambient 1 diffuse 0 }
                    }
                }
            #end
        #declare yCounter = yCounter + 1;
        #end
        #declare xCounter = xCounter + 1;
    #end
        translate < -(BoxWH/2), 0, 0 >
    }
}
#end
