#include "colors.inc"
#include "field.inc"
#include "fldchrs.inc"
#include "Stage.inc"
// #include "screen.inc"
// #include "SpkTower.inc"

#include "TopLght.inc"
#include "TopLight.inc"
#include "scrframe.inc"
#include "support1.inc"
#include "support2.inc"
#include "support3.inc"
#include "support4.inc"
#include "support5.inc"
#include "support6.inc"
#include "support.inc"
// #include "screen.inc"
#include "olive.inc"
#include "arch.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"


global_settings {
    ambient_light rgb < 1, 1, 1 > * 2
}

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 1;
    #declare FF = 1;
#end

#declare FldChrsCameraSource = function {
   spline {
       natural_spline
       0.0, < -20, 6.0, -30 >
       1.0, <  20, 6.0, -25 >
   }
}

#declare FldChrsCameraDest = function {
   spline {
       natural_spline
       0.0, < -20, 3.0, 5 >
       1.0, <  20, 3.0, 0 >
   }
}


camera {
   //location < 20, 600, 25 >
   // look_at < 10, 2, 10 >
	
   // Back left asle of seats
   // location < -27.5, 10, -132 >
   
   // Center stage
   // look_at < 0, 15, 185 >

   location FldChrsCameraSource(FN/FF)
   look_at FldChrsCameraDest(FN/FF)
   // look_at < 0, 5, -20 >
}

light_source {
   // < -1000, 1000, -1000 >
   < -1000, 1000, 1000 >
   color White
}

// InitU2FanData(6720)

object {
   FieldSeating
   translate < -78.5, 0, -132 >
}