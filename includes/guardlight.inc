// guardlight.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare baseRad = 0.12;
#declare baseHeight = 0.3;

#declare coneRad = 0.15;
#declare coneHeight = 0.05;

#declare lightRad = 0.11;
#declare lightHeight = 0.6;
#declare sphereScale = 0.8;

#declare loopRad = 0.22;
#declare loopThick = 0.014;

#declare GuardMetal = texture {
    pigment { color Silver }
    finish { F_MetalA }
}

#macro GuardLight()

#declare GuardLightCycleSpeed = 40;

#if (clock_on = 1)
    #declare glFN = frame_number;
#else
    #declare glFN = 50;
#end

#if ((mod(glFN,GuardLightCycleSpeed)/GuardLightCycleSpeed) > 0.5)
    #declare GuardLightOn = false;
#else
    #declare GuardLightOn = true;
#end

union {
    cylinder {
        < 0, 0, 0 >,
        < 0, baseHeight, 0 >,
        baseRad
        texture { GuardMetal }
    }
    cone {
        < 0, baseHeight, 0 >, baseRad
        < 0, baseHeight + coneHeight, 0 >, coneRad
        texture { GuardMetal }
    }
    cylinder {
        < 0, baseHeight + coneHeight, 0 >,
        < 0, baseHeight + coneHeight + lightHeight, 0 >,
        lightRad
        #if (GuardLightOn = true)   
           texture { Red_Neon }
        #else
           texture { Red_Glass }
        #end
    }
    sphere {
        < 0, 0, 0 >,
        lightRad
        scale < 1, sphereScale, 1 >
        translate < 0, baseHeight + coneHeight + lightHeight, 0 >
        #if (GuardLightOn = true)   
           texture { Red_Neon }
        #else
           texture { Red_Glass }
        #end
    }
    
    torus {
        loopRad, loopThick
        translate < 0, baseHeight + coneHeight + (lightHeight / 4), 0 >
        texture { GuardMetal }
    }
    torus {
        loopRad, loopThick
        translate < 0, baseHeight + coneHeight + (lightHeight / 4 * 2), 0 >
        texture { GuardMetal }
    }
    torus {
        loopRad, loopThick
        translate < 0, baseHeight + coneHeight + (lightHeight / 4 * 3), 0 >
        texture { GuardMetal }
    }
    difference {
        torus {
            loopRad, loopThick
            rotate < 90, 0, 0 >
            scale < 1, sphereScale, 1 >
        }
        plane { < 0, -1, 0 >, 0 }
        translate < 0, baseHeight, 0 >
        texture { GuardMetal }
    }
    difference {
        torus {
            loopRad, loopThick
            rotate < 0, 0, 90 >
            scale < 1, sphereScale, 1 >
        }
        plane { < 0, -1, 0 >, 0 }
        translate < 0, baseHeight, 0 >
        texture { GuardMetal }
    }
    difference {
        torus {
            loopRad, loopThick
            rotate < 90, 0, 0 >
            scale < 1, sphereScale, 1 >
        }
        plane { < 0, 1, 0 >, 0 }
        translate < 0, baseHeight+lightHeight, 0 >
        texture { GuardMetal }
    }
    difference {
        torus {
            loopRad, loopThick
            rotate < 0, 0, 90 >
            scale < 1, sphereScale, 1 >
        }
        plane { < 0, 1, 0 >, 0 }
        translate < 0, baseHeight+lightHeight, 0 >
        texture { GuardMetal }
    }
    
    cylinder {
        < -loopRad, baseHeight, 0 >,
        < -loopRad, baseHeight+lightHeight, 0 >,
        loopThick
        texture { GuardMetal }
    }
    cylinder {
        < loopRad, baseHeight, 0 >,
        < loopRad, baseHeight+lightHeight, 0 >,
        loopThick
        texture { GuardMetal }
    }
    cylinder {
        < 0, baseHeight, -loopRad >,
        < 0, baseHeight+lightHeight, -loopRad >,
        loopThick
        texture { GuardMetal }
    }
    cylinder {
        < 0, baseHeight, loopRad >,
        < 0, baseHeight+lightHeight, loopRad >,
        loopThick
        texture { GuardMetal }
    }
    
}
#end
