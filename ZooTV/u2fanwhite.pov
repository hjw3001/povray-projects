// u2fanwhite.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare use_blur = 20*0;
#declare use_radiosity = 2;
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
#include "u2fan.inc"
#include "whiteroom.inc"

#declare ranGen = seed(360);

GenerateU2Fan(ranGen, 0)

camera {
    location < 5, 4, 5 >
    look_at < 0, 3, 0 >
}
