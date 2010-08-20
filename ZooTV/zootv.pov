// zootv.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare use_blur = 20*0;
#declare use_radiosity = 1;
#declare rad_brightness = 2;

global_settings {
    max_trace_level 6
    assumed_gamma 2.2
    #if (use_radiosity)
        radiosity {
        #if (use_radiosity = 2)
            // save settings
            pretrace_start 0.5 pretrace_end 0.1
            count 200 nearest_count 20 error_bound .25
            recursion_limit 1
            normal on
            brightness rad_brightness
            save_file "data.rad"
        #else
            // load settings
            pretrace_start 1 pretrace_end 1
            always_sample off
            error_bound .25
            recursion_limit 1
            normal on
            brightness rad_brightness
            load_file "data.rad"
        #end
        }
    #end
}
 
#declare LightCycleSpeed = 20;

#if (clock_on = 1)
    #declare LSpd = frame_number;
#else
    #declare LSpd = 50;
#end

#if ((mod(LSpd,LightCycleSpeed)/LightCycleSpeed) > 0.5)
    #declare useLight = false;
#else
    #declare useLight = true;
#end

#declare useLight = false;

#declare nineLightZ = 2;

#include "colors.inc"
#include "finish.inc"
#include "textures.inc"
#include "hwcolors.inc"
#include "zootv.inc"
#include "whiteroom.inc"
#include "videowalls.inc"
#include "ninelight.inc"

union {
    object { Zoo_Red }
    object { Zoo_Green }
    translate < 0, 3.5, 0 >
}

object {
    SmallVideoScreen
    rotate < 0, -85, 0 >
    translate < -5.5, 0, -7.5 >
}
/*
object {
    LargeTWoSectionVideoScreen
    rotate < 0, -55, 0 >
    translate < -25, 0, 18 >
}
*/
union {
    object {
        TVScreen
    }
    object {
        TVScreen
        rotate < 0, 0, 90 >
        rotate < 0, -20, 0 >
        translate < -TVScreenWidth + 1.15, (TVScreenWidth/2), 0 >
    }
    rotate < 0, -55, 0 >
    translate < 10.6, 0, -6 >
}

camera {
   location < 17.3, 3.5, -8.3 >
   look_at < -3, 0.5, 0 >
   #if (use_blur)
       focal_point < -3, 0.5, 0 >
       aperture .125
       blur_samples use_blur
   #end
}

object {
    NineLight(useLight)
    translate < 0, 0, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -5, 0, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 5, 0, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -10, 0, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 10, 0, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -15, 0, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -20, 0, nineLightZ >
}
