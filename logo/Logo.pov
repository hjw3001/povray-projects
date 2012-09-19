// My new, smaller, logo
//
// Henry Wagner Graphic Designs
//
//	by: Henry Wagner	Started: 3/6/95
#include "colors.inc"
#include "shapes.inc"
#include "stones.inc"
#include "stoneold.inc"
#include "textures.inc"
#include "3dsmater.inc"
#include "hchars.inc"
#include "golds.inc"

#declare ROTX = 0;

#if (clock_on=1)
    #declare ROTY = 90 - clock;
    #if (clock < 45)
        #declare lightColor = < clock/45, clock/45, clock/45 >;
    #else
        #declare lightColor = < 1, 1, 1 >;
    #end
#else
    #declare ROTY = 0;
    #declare lightColor = < 1, 1, 1 >;
#end

union {
   difference {
      union {
         box {
            < -5, 0, -0.5 >,
            <  0, 5,  0.5 >
         }
         cylinder {
            < -5, 0, 0 >,
            < -5, 5, 0 >,
            0.5
         }
         sphere {
            < -5, 5, 0 >, 0.5
         }
         cylinder {
            < -5, 5, 0 >,
            <  0, 5, 0 >,
            0.5
         }
         texture { T_Stone24 scale 6 }
         finish { Shiny }
      }
      union {
         object {
            hchar_H
            translate < -4, 0.5, -0.5 >
         }
         object {
            hchar_W
            translate < -1.5, 0, 0 >
            rotate < 0, 180, 0 >
            translate <  1.5, 0, 0 >
            translate < -4.0, 0.5, 0.5 >
         }
         texture { T_Gold_3C }
      }
   }
   difference {
      union {
         box {
            < 0, -5, -0.5 >,
            < 5,  0,  0.5 >
         }
         cylinder {
            < 0, -5, 0 >,
            < 5, -5, 0 >,
            0.5
         }
         sphere {
            < 5, -5, 0 >, 0.5
         }
         cylinder {
            < 5,  0, 0 >,
            < 5, -5, 0 >,
            0.5
         }
         texture { T_Stone24 scale 6 }
         finish { Shiny }
      }
      union {
         object {
            hchar_D
            translate< 1, -4.5, -0.5 >
         }
         object {
            hchar_G
            translate < -1.5, 0, 0 >
            rotate < 0, 180, 0 >
            translate <  1.5, 0, 0 >
            translate <  1, -4.5, 0.5 >
         }
         texture { T_Gold_3C }
      }
   }
   difference {
      union {
         box {
            < 0, 0, -0.5 >,
            < 5, 5,  0.5 >
         }
         cylinder {
            < 5, 0, 0 >,
            < 5, 5, 0 >,
            0.5
         }
         sphere {
            < 5, 5, 0 >, 0.5
         }
         cylinder {
            < 0, 5, 0 >,
            < 5, 5, 0 >,
            0.5
         }
         texture { EMBWood1 scale 3.5 }
         finish { Shiny }
      }
      union {
         object {
            hchar_W
            translate < 1, 0.5, -0.5 >
         }
         object {
            hchar_H
            translate < 1, 0.5, 0.5 >
         }
         texture { T_Gold_3C }
      }
   }
   difference {
      union {
         box {
            < -5, -5, -0.5 >,
            <  0,  0,  0.5 >
         }
         cylinder {
            < -5,  0, 0 >,
            < -5, -5, 0 >,
            0.5
         }
         sphere {
            < -5, -5, 0 >, 0.5
         }
         cylinder {
            < -5, -5, 0 >,
            <  0, -5, 0 >,
            0.5
         }
         texture {
            EMBWood1
            scale 3.5
         }
         finish { Shiny }
      }
      union {
         object {
            hchar_G
            translate < -4, -4.5, -0.5 >
            texture { T_Gold_3C }
         }
         object {
            hchar_D
            translate < -1.5, 0, 0 >
            rotate < 0, 180, 0 >
            translate < 1.5, 0, 0 >
            translate < -4, -4.5, 0.5 >
         }
         texture { T_Gold_3C }
      }
   }
   rotate< 0, ROTY, 0 >
   rotate< ROTX, 0, 0 >
}

camera {
   location < 0, 0.5, -16 >
   look_at  < 0, 0.0, 0 >
}

light_source { <  1000, 1000, -1000 > color rgb lightColor }
light_source { < -1000, 1000, -1000 > color rgb lightColor }
