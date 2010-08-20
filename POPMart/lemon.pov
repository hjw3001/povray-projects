// lemon.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "finish.inc"
#include "lemon.inc"
#include "stage.inc"
#include "field.inc"
#include "sky.inc"
// #include "enviro.inc"

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 1;
    #declare FF = 1;
#end

#declare LemonYellow=0;
#declare LemonSpinFactor=360;

// light_source { < 1000, 1000, 1000 > color White }

#declare LemonCameraSource = function {
   spline {
       natural_spline
       0.0, <  55,  35, 175 >
       0.5, <  50,  45, 135 >
       1.0, <  75,  6, 155 >
   }
}

#declare LemonCameraDest = function {
   spline {
       natural_spline
       0.0, < 60, 30, 175 >
       0.5, < 60, 30, 175 >
       1.0, < 60, 23, 175 >
   }
}

camera {
   // location <  50,  45, 135 >
   // location LemonCameraSource(FN/FF)
   location LemonCameraSource(1)
   //look_at < 60, 30, 175 >
   // look_at LemonCameraDest(FN/FF)
   look_at LemonCameraDest(1)
}

object {
   Lemon
   texture {
      #if (LemonYellow = 1)
        pigment { color Yellow }
      #else
        pigment { rgb < 0.2, 0.2, 0.2 > }
        finish {
            ambient 0.4
            diffuse 0.7
            brilliance 6.0
            reflection 0.6
            phong 0.8
            phong_size 120
        }
     #end
   }
   rotate < 0, clock * LemonSpinFactor, 0 > // Rotate the Lemon for animation
   rotate < 20,  0, 0 > // Tilt the Lemon
   rotate <  0, 90, 0 > // Rotate into final position
   translate < 60, 30, 175 >
}

light_source {
    < 0, 115, 0>
    color rgb 0.7
    media_interaction off
    shadowless
}
