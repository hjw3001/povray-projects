// guardlight.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare use_blur = 20*0;
#declare use_radiosity = 0;
#declare rad_brightness = 2;

global_settings {
    assumed_gamma 2.2
    #if (use_radiosity)
        max_trace_level 6
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

#include "colors.inc"
#include "metals.inc"
#include "guardlight.inc"

object {
    GuardLight(Red)
    translate < 0, 0, 0 >
}

camera {
    location < 2, 0.6, 2 >
    look_at < 0, 0.5, 0 >
}

light_source {
    < 1000, 1000, 1000 >
    color White+Gold
}
