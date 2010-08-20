// SmallLight.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 100;
    #declare FF = 200;
#end

#declare initGen = seed(360);
#declare LightHeight = 1;
#declare CycleSpeed = 15;

#declare counter = 0;
#while (counter < 360)
    #declare LightPower = (mod(FN,CycleSpeed)/CycleSpeed) + rand(initGen);
    
    #if (LightPower > 1.0)
        #declare LightPower = LightPower - 1.0;
    #end
    
    #if (LightPower > 0.5)
        #declare LightPower = 1.0 - LightPower;
    #end
    
    #declare LightPower = LightPower + 0.5;
    
    union {
        box {
            < -(LightHeight/2), 0, -(LightHeight/2) >,
            <  (LightHeight/2), LightHeight, (LightHeight/2) >
            texture {
                Brass_Texture
                normal { granite .1 scale .1 }
                finish { reflection { .01, .3 } diffuse .7 }
            }
        }
        sphere {
            < 0, 0, 0 >,
            ((LightHeight/2) * 0.9)
            scale < 1, .2, 1 >
            translate < 0, LightHeight, 0 >
            texture {
                pigment { color Med_Purple }
                finish {
                    ambient LightPower
                    diffuse 0
                }
            }
        }
        translate < (sin(counter) * StadiumRadius) - StadiumCenter, PodHeight, (cos(counter) * StadiumRadius) >
    }
    #declare counter = counter + 1;
#end