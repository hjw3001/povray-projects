// main.pov
//
// Written by: Henry Wagner

#version 3.5;
global_settings { assumed_gamma 2.2 }

#include "colors.inc"
#include "stones.inc"
#include "stoneold.inc"
#include "textures.inc"
#include "metals.inc"
#include "marble.inc"
#include "crypt.inc"
#include "columns.inc"
#include "environofog.inc"

/*
difference {
   box {
      < -15, 10, -15 >,
      <  15, 30,  15 >
   }
   union {
      cylinder {
         < -16, 10, -6 >,
         <  16, 10, -6 >,
         5.0
      }
      cylinder {
         < -16, 10, 6 >,
         <  16, 10, 6 >,
         5.0
      }
      cylinder {
         < -6, 10, -16 >,
         < -6, 10,  16 >,
         5.0
      }
      cylinder {
         < 6, 10, -16 >,
         < 6, 10,  16 >,
         5.0
      }
   }
   texture {
      T_Stone24
      scale 1
   }
}
*/

// These are the walls
/*
union {
   box {
      < -15,  0, -12 >,
      < -12, 30,  12 >
   }
   box {
      < 12,  0, -12 >,
      < 15, 30,  12 >
   }
   box {
      < -12,  0, -15 >,
      <  12, 30, -12 >
   }
   box {
      < -12,  0, 12 >,
      <  12, 30, 15 >
   }
   texture {
      pigment { color LightGray }
      finish { Mirror }
   }
}
*/

// These are the columns
object { MyColumns }

object { Crypt }

// light_source { < 50, 8, 50 > color White }
// light_source { < -50, 8, 50 > color White }

camera {
   location < 16, 5, 16 >
   up < 0, 1, 0 >
   right < 4/3, 0, 0 >
   // look_at< 100, 20, 70 >
   look_at < 48, 8, 40 >
}

light_source { < 16, 4, 16 > color White }
//light_source { < -16, 14,  16 > color White }
//light_source { <  16, 14, -16 > color White }
//light_source { <  16, 14,  16 > color White }

/*
light_source {
   < 42, 12, 42 >
   color red 0.7 green 0.7 blue 0.7
   spotlight
   point_at < -100, 0, -50 >
   radius 10
   falloff 15
   tightness 1
   atmospheric_attenuation on
}

light_source {
   < -6, 14, -6 >
   color White
   spotlight
   point_at < -6, 0, -6 >
   radius 20
   falloff 45
   tightness 1
   atmospheric_attenuation on
}

light_source {
   < -6, 14, 6 >
   color White
   spotlight
   point_at < -6, 0, 6 >
   radius 20
   falloff 45
   tightness 1
   atmospheric_attenuation on
}

light_source {
   < 6, 14, -6 >
   color White
   spotlight
   point_at < 6, 0, -6 >
   radius 20
   falloff 45
   tightness 1
   atmospheric_attenuation on
}

light_source {
   < 6, 14, 6 >
   color White
   spotlight
   point_at < 6, 0, 6 >
   radius 20
   falloff 45
   tightness 1
   atmospheric_attenuation on
}
*/

// Ground
plane {
   < 0, 1, 0 >, 0
   texture {
      tiles {
         texture {
            Green_Marble
            finish {
               reflection 0.13
               phong 1
               phong_size 300
            }
         }
      tile2
         texture {
            Green_Marble
            finish {
               reflection 0.13
               phong 1
               phong_size 300
            }
            rotate < 0, 90, 0 >
         }
      }
   }
   scale 3
}
