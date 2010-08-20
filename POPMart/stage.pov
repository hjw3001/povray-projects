// stage.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "finish.inc"
#include "arch.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"
#include "olive.inc"
#include "scrframe.inc"
// #include "screen.inc"
#include "stadium.inc"
// #include "enviro.inc"
#include "stage.inc"
#include "field.inc"
// #include "enviro.inc"
#include "support1.inc"
#include "support2.inc"
#include "support3.inc"
#include "support4.inc"
#include "support5.inc"
#include "support6.inc"
#include "support.inc"
#include "TopLght.inc"
#include "TopLight.inc"
#include "SpkTower.inc"

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 200;
    #declare FF = 200;
#end

#declare StageCameraDest = function {
   spline {
       natural_spline
       0.0, <  75,  50,  180 >
       0.25 <  50,  55,  100 >
       0.5, <   0,  35,    0 >
       0.75 < -50,  15,  100 >
       1.0, < -75,  10,  190 >
   }
}

// light_source { < 1000, 1000, -1000 > color White }

camera {
   location < 0, 15.5, 190 >
   // location OliveCameraSource(FN/FF)
   look_at StageCameraDest(FN/FF)
}

object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}

/*
light_source {
    < 0, 115, 0>
    color rgb 0.7
    media_interaction off
    shadowless
}
*/