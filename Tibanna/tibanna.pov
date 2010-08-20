// tibanna.pov
//
// Test POV scene file for the Tibanna gas mine
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)
// Started: 12/15/1996

#version 3.5;

#declare useRad = false;

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

#include "colors.inc"
#include "metals.inc"
// #include "stars.inc"

/*
light_source { < 1000, 1000, 1000 > color White }
light_source { < 1000, -1000, 1000 > color White }
*/

light_source {
   < 10000, 0, 0 >
   color White
   area_light < 0, 10000, 0 >, < 0, 0, 10000 >, 5, 5
   adaptive 1
   jitter
}

#declare Window_Light = texture {
   pigment { color White }
   finish {
      ambient 1.0
      diffuse 0.0
   }
}

#declare Balloon_Texture = texture {
   // pigment { color < 0.929411, 0.945098, 0.545098 > }
   // pigment { color < 1.0, 0.917647, 0.396078 > }
   pigment { color < 0.945098, 0.690196, 0.043137 > }
   finish {
      specular  0.55
      roughness 0.15
   }
}

#include "tibanna.inc"
#include "lgtower.inc"
#include "lgtpos.inc"
#include "window1.inc"
#include "window2.inc"
#include "window3.inc"
#include "window4.inc"
#include "window5.inc"
#include "window6.inc"
#include "window7.inc"
#include "window8.inc"
#include "window9.inc"
#include "window10.inc"
#include "window11.inc"
#include "window12.inc"
#include "window13.inc"
#include "window14.inc"
#include "detail1.inc"

// Include files for the balloons
#include "window15.inc"
#include "detail2.inc"
#include "detail3.inc"
#include "balloon.inc"

object {
   Balloon
   scale 0.08
   translate < 470, -25, 1800 >
}

object {
   Balloon
   scale 0.08
   translate < 640, 10, 1300 >
}

camera {                     
   location < 550, -55,   1400 >
   look_at < 640, 30, 1300 >
//   location < 300, -55,   2150 >
//   look_at  <   0, -54, -10000 >
/*
   aperture 2
   focal_point <0, 0, 0>

   blur_samples 37
   confidence 0.975           // default is 0.9
   variance 1/255             // default is 1/128 (0.0078125)
*/
}

union {
   difference {
      cylinder {
         < 0, -80, 0 >,
         < 0, -30, 0 >,
         830.0
      }
      union {
         object {
            Main_Windows
            translate < 0, -40, 0 >
         }
         object {
            Main_Windows_2
            translate < 0, -60, 0 >
         }
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, -79, 0 >,
      < 0, -31, 0 >,
      829.0
      texture { Window_Light }
   }
   object {
      Light_Towers
   }
   cylinder {
      < 0, -98, 0 >,
      < 0, -80, 0 >,
      450.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, -118, 0 >,
      < 0, -98, 0 >,
      350.0
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, -118, 0 >,
         < 0, -138, 0 >,
         300.0
      }
      object {
         Bot_Window_1
         translate < 0, -128, 0 >
      }
      texture { Main_Metal }
   }
   object {
      torus { 300, 20 }
      translate < 0, -148.0, 0 >
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, -148, 0 >,
         < 0, -188, 0 >,
         320.0
      }
      union {
         object {
            Bot_Window_2
            translate < 0, -158, 0 >
         }
         object {
            Bot_Window_3
            translate < 0, -168, 0 >
         }
         object {
            Bot_Window_4
            translate < 0, -178, 0 >
         }
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, -149, 0 >,
      < 0, -187, 0 >,
      319.0
      texture { Window_Light }
   }
   cylinder {
      < 0, -119, 0 >,
      < 0, -137, 0 >,
      299.0
      texture { Window_Light }
   }

   cylinder {
      < 0, -188, 0 >,
      < 0, -220, 0 >,
      100.0
      texture { Main_Metal }
   }
   object {
      torus { 220, 20 }
      translate < 0, -240, 0 >
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, -240, 0 >,
         < 0, -270, 0 >,
         240.0
      }
      object {
         Bot_Window_8
         translate < 0, -258, 0 >
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, -241, 0 >,
      < 0, -269, 0 >,
      239.0
      texture { Window_Light }
   }

   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 30, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 60, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 90, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 120, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 150, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 180, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 210, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 240, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 270, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 300, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 80, -270, 0 >,
      < 80, -320, 0 >,
      5.0
      rotate < 0, 330, 0 >
      texture { Main_Metal }
   }

   difference {
      cylinder {
         < 0, -320, 0 >,
         < 0, -340, 0 >,
         300.0
      }
      object {
         Bot_Window_6
         translate < 0, -330, 0 >
      }
      texture { Main_Metal }
   }

   cylinder {
      < 0, -321, 0 >,
      < 0, -339, 0 >,
      299.0
      texture { Window_Light }
   }

   object {
      Bot_Detail_1
      translate < 0, -320, 0 >
      texture { Main_Metal }
   }

   cone {
      < 0, -340, 0 >, 300.0
      < 0, -350, 0 >, 90.0
      texture { Main_Metal }
   }

   cone {
      < 0, -400, 0 >, 90.0
      < 0, -410, 0 >, 200.0
      texture { Main_Metal }
   }
   cone {
      < 0, -410, 0 >, 200.0
      < 0, -440, 0 >, 210.0
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, -440, 0 >,
         < 0, -460, 0 >,
         210.0
      }
      object {
         Bot_Window_5
         translate < 0, -450, 0 >
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, -441, 0 >,
      < 0, -459, 0 >,
      209.0
      texture { Window_Light }
   }
   cone {
      < 0, -460, 0 >, 150.0
      < 0, -490, 0 >, 80.0
      texture { Main_Metal }
   }
   cone {
      < 0, -490, 0 >, 80.0
      < 0, -500, 0 >, 120.0
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, -500, 0 >,
         < 0, -520, 0 >,
         120.0
      }
      object {
         Bot_Window_7
         translate < 0, -510, 0 >
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, -501, 0 >,
      < 0, -519, 0 >,
      119.0
      texture { Window_Light }
   }
   cone {
      < 0, -520, 0 >, 120.0
      < 0, -540, 0 >, 90.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, -540, 0 >,
      < 0, -550, 0 >,
      90.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, -550, 0 >,
      < 0, -560, 0 >,
      70.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, -560, 0 >,
      < 0, -580, 0 >,
      50.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, -580, 0 >,
      < 0, -590, 0 >,
      60.0
      texture { Main_Metal }
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 60, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 90, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 120, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 150, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 180, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 210, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 240, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 270, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 300, 0 >
   }
   object {
      Small_Container
      translate < 61, -585, 0 >
      rotate < 0, 330, 0 >
   }

   object {
      Bot_Rod
      translate < 40, -590, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 60, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 90, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 120, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 150, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 180, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 210, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 240, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 270, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 300, 0 >
   }
   object {
      Bot_Rod
      translate < 40, -590, 0 >
      rotate < 0, 330, 0 >
   }

   object { Main_Container_Ring }

   object {
      Connector_Shaft
      translate < 80, 275, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 60, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 90, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 120, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 150, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 180, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 210, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 240, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 270, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 300, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 275, 0 >
      rotate < 0, 330, 0 >
   }
   cylinder {
      < 0, 260, 0 >,
      < 0, 275, 0 >,
      120.0
      texture { Main_Metal }
   }
   cone {
      < 0, 260, 0 >, 120.0
      < 0, 250, 0 >,  80.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, 200, 0 >,
      < 0, 250, 0 >,
      80.0
      texture { Main_Metal }
   }
   cone {
      < 0, 180, 0 >, 100.0
      < 0, 200, 0 >,  80.0
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, 160, 0 >,
         < 0, 180, 0 >,
         100.0
      }
      object {
         Mid_Window_1
         translate < 0, 170, 0 >
      }
      texture { Main_Metal }
   }

   cylinder {
      < 0, 161, 0 >,
      < 0, 179, 0 >,
      99.0
      texture { Window_Light }
   }
   cone {
      < 0, 130, 0 >, 100.0
      < 0, 145, 0 >, 60.0
      texture { Main_Metal }
   }
   cone {
      < 0, 145, 0 >, 60.0
      < 0, 160, 0 >, 100.0
      texture { Main_Metal }
   }

   object {
      Connector_Shaft
      translate < 80, 0, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 30, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 30, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 60, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 60, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 90, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 90, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 120, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 120, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 150, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 150, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 180, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 180, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 210, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 210, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 240, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 240, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 270, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 270, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 300, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 300, 0 >
   }
   object {
      Connector_Shaft
      translate < 80, 0, 0 >
      rotate < 0, 330, 0 >
   }
   cylinder {
      < 80, -30, 0 >,
      < 80,   0, 0 >,
      14.0
      texture { Main_Metal }
      rotate < 0, 330, 0 >
   }
   
   cylinder {
      < 0, 435, 0 >,
      < 0, 445, 0 >,
      110.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, 445, 0 >,
      < 0, 460, 0 >,
      170.0
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, 460, 0 >,
         < 0, 470, 0 >,
         160.0
      }
      object {
         Top_Window_1
         translate < 0, 465, 0 >
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, 461, 0 >,
      < 0, 469, 0 >,
      159.0
      texture { Window_Light }
   }
   cylinder {
      < 0, 470, 0 >,
      < 0, 490, 0 >,
      170.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, 490, 0 >,
      < 0, 510, 0 >,
      150.0
      texture { Main_Metal }
   }
   object {
      torus { 150, 20 }
      translate < 0, 490, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 0, 510, 0 >,
      < 0, 525, 0 >,
      120.0
      texture { Main_Metal }
   }
   cylinder {
      < 0, 525, 0 >,
      < 0, 555, 0 >,
      100.0
      texture { Main_Metal }
   }

   difference {
      cylinder {
         < 0, 555, 0 >,
         < 0, 585, 0 >,
         150.0
      }
      object {
         Top_Window_2
         translate < 0, 565, 0 >
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, 556, 0 >,
      < 0, 584, 0 >,
      149.0
      texture { Window_Light }
   }

   object {
      Top_Main_Ring
      translate < 0, 600, 0 >
   }

   cone {
      < 0, 585, 0 >, 25.0
      < 0, 800, 0 >, 10.0
      texture { Main_Metal }
   }

   cone {
      < 0, 800, 0 >, 10.0
      < 0, 820, 0 >, 30.0
      texture { Main_Metal }
   }

   object {
      torus { 60.0, 10.0 }
      translate < 0, 830, 0 >
      texture { Main_Metal }
   }
   cylinder {
      < 0, 830, 0 >,
      < 0, 865, 0 >,
      50.0
      texture { Main_Metal }
   }
   difference {
      cylinder {
         < 0, 830, 0 >,
         < 0, 865, 0 >,
         70.0
      }
      object {
         Top_Window_3
         translate < 0, 850, 0 >
      }
      texture { Main_Metal }
   }
   cylinder {
      < 0, 836, 0 >,
      < 0, 864, 0 >,
      69.0
      texture { Window_Light }
   }

   object {
      torus { 60.0, 10.0 }
      translate < 0, 855, 0 >
      texture { Main_Metal }
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 22.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 67.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 112.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 157.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 202.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 247.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 292.5, 0 >
   }

   object {
      Top_Small_Container
      translate < 50, 865, 0 >
      rotate < 0, 337.5, 0 >
   }

   // This cylinder runs top to bottom connecting all the sections
/*
   cylinder {
      < 0, -500, 0 >,
      < 0,  800, 0 >,
      20.0
      texture { Main_Metal }
   }
*/
}
