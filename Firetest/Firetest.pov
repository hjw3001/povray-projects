// firetest.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#if (clock_on=1)
    #declare FN = frame_number;
#else
    #declare FN = 0;
#end

#declare use_blur    =20*0;  // blur samples (0=off)
#declare use_radiosity =0;
#declare rad_brightness=2;
global_settings{
 max_trace_level 6
 assumed_gamma 2.2
 #if (use_radiosity)
  radiosity{
   #if (use_radiosity=2)
    // save settings
    pretrace_start .05 pretrace_end .01
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

#declare rFireOffset = 0.1;
#declare gFireOffset = 0.1;
#declare bFireOffset = 0.1;

#declare ranGen = seed(574647);

#declare loopCounter = 0;
#while (loopCounter < FN)
    #declare tempVal = rand(ranGen);
    #declare loopCounter = loopCounter + 1;
#end
                                  
#declare FireTexture = texture {
}

#declare sCounter = 0;
#while (sCounter < 10)
    sphere {
        < sCounter, 1, 0 >, 0.1
        texture {
            pigment { rgb < 0.858824 + (rand(ranGen) * rFireOffset) - (rFireOffset/2),
                            0.858824 + (rand(ranGen) * gFireOffset) - (gFireOffset/2),
                            0.439216 + (rand(ranGen) * bFireOffset) - (bFireOffset/2) > }
            finish {
                ambient 1
                diffuse 0
            }
        }
    }
    #declare sCounter = sCounter + 1;
#end

camera {
    location < 0, .2, -6 >
    look_at < 3.2, 1, 0 >
}