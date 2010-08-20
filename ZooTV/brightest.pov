// brightest.pov
//
// Written by: Henry Wagner

#declare use_blur = 20*0;
#declare use_radiosity = 0;
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

#include "colors.inc"

plane { < 0, 1, 0 >, 0 pigment { color Green } }

#declare counter = 1;

#while (counter < 11)
light_source {
    < counter, 1, 0 >
    color White+Gold
    fade_distance 0.6
    fade_power 2
    looks_like {
        sphere {
            < counter, 1, 0 >, 0.4
            texture {
                pigment { color White+Gold }
                finish {
                    ambient 1
                    diffuse 0
                    // brilliance counter
                }
            }
        }
    }
}
    #declare counter = counter + 1;
#end

camera {
    location < 4, 0.4, -7 >
    look_at  < 5, 0.5, 0 >
}