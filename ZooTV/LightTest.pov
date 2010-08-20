// LightTest.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

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
#include "finish.inc"
#include "metals.inc"
#include "textures.inc"
#include "stadium.inc"
#include "field.inc"
#include "u2fan.inc"

global_settings {
    ambient_light rgb < 1, 1, 1 > * 2
}

// GenerateLighters(18, 24, 15, 0.5, 6, 3000, 33.69)
// GenerateLighters(20, 24, 52, 0.5, 4, 3000, 47.07)
// GenerateLighters(22, 25, 87, 0.5, 3, 3000, 63.4349)

// GenerateFieldCrowd(6720)

camera {
    location < 0, 35.5, 170 >
    look_at < 0,  35, 0 >
}

object {
    Stadium
    texture { Concrete1 }
}
