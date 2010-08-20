// olive.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "finish.inc"
#include "olive.inc"
// #include "scrframe.inc"
// #include "screen.inc"
// #include "stadium.inc"
// #include "enviro.inc"
#include "field.inc"
#include "stage.inc"

#declare useLights = false;

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 200;
    #declare FF = 200;
#end

#if (useLights)
    light_source { < 1000, 1000, -1000 > color rgb 0.6 }

    light_source {
        < 0, 115, 0>
        color rgb 0.2
        media_interaction off
        shadowless
    }
#end

#declare OliveCameraSource = function {
   spline {
       natural_spline
       0.0, < 85, 105, 180 >
       0.5, < 90, 108, 185 >
       1.0, < 95, 110, 190 >
   }
}

camera {
   // location < 85, 105, 180 >
   location OliveCameraSource(FN/FF)
   look_at < 91.057, 95, 192 >
}
/*
object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}
*/