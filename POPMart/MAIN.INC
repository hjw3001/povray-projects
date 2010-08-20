// main.inc
//
// Written by: Henry Wanger (henryw@panix.com)

#include "colors.inc"
#include "textures.inc"
// #include "POPatmos.inc"
#include "field.inc"
#include "stage.inc"
#include "scrframe.inc"
#include "screen.inc"
#include "arch.inc"
#include "olive.inc"
#include "sky.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"
#include "stadium.inc"
#include "lemon.inc"
#include "camera.inc"
#include "support1.inc"
#include "support2.inc"
#include "support3.inc"
#include "support4.inc"
#include "support5.inc"
#include "support6.inc"
#include "support.inc"

object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}

object {
   Lemon
   texture {
      pigment { rgb < 0.2, 0.2, 0.2 > }
      finish {
         ambient 0.4
         diffuse 0.7
         brilliance 6.0
         reflection 0.6
         phong 0.8
         phong_size 120
     }
   }
   rotate < 20, 0, 0 >
   rotate < 0, 90, 0 >
   translate < 60, 30, 175 >
}
