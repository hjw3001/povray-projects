// arch.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "finish.inc"

#include "arch.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"
#include "olive.inc"
#include "scrframe.inc"
#include "screen.inc"
#include "stage.inc"
#include "field.inc"
#include "support1.inc"
#include "support2.inc"
#include "support3.inc"
#include "support4.inc"
#include "support5.inc"
#include "support6.inc"
#include "support.inc"
#include "TopLght.inc"
#include "TopLight.inc"

#declare useRad = false;                        
#declare useStadium = false;
#declare useLights = true;

global_settings{
    assumed_gamma 2.2
    #if (useRad = true)
    radiosity{
        pretrace_start 0.04
        pretrace_end 0.01
        count 200
        recursion_limit 3
        nearest_count 10
        error_bound 0.5
    }
    #end
}

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 100;
    #declare FF = 200;
#end

DisplayPOPMartScreen("arch")

#declare ArchCameraSource = function {
   spline {
       natural_spline
       0.0, <  40, 60, 185 >
       0.5, <   0, 6, 50 >
       1.0, < -40, 80, 185 >
   }
}

#declare ArchCameraDest = function {
   spline {
       natural_spline
       0.0, < 0, 70, 178 >
       0.5, < 0, 38, 178 >
       1.0, < 0, 60, 178 >
   }
}

#declare ArchPanDest = function {
   spline {
       natural_spline
       0.0, < -25, 10, 180 >
       0.5, <   0, 38, 180 >
       1.0, <  25, 10, 180 >
   }
}

camera {
   // location ArchCameraSource(FN/FF)
   // look_at ArchCameraDest(FN/FF)
   
   //location < 0, 15, 175 > // 175
   //look_at ArchPanDest(FN/FF)
   
   location < 0, 101, 155 >
   look_at  < 0, 0, 200 >
}

object { TopLightRig }

#if (useStadium)
    #include "stadium.inc"
    object {
        Stadium
        texture {
            pigment { color Gray75 }
            finish { diffuse 0.7 }
        }
    }
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