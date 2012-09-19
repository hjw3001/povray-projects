// lamp.pov
//
// Test file for bridge lamp
//
// Written by: Henry Wagner (povray@henrywagner.org)
// Started: 11/30/96

#include "colors.inc"
#include "metals.inc"

#declare Ball_Base = difference {
   difference {
      sphere { < 0, 0, 0 >, 0.6 }
      sphere { < 0, 0, 0 >, 0.5 }
   }
   plane { < 0, 1, 0 > 0.4 }
}

#declare Lamp_Arm = union {
   cylinder {
      < 0, 0, 0 >,
      < 2, 0, 0 >,
      0.25
   }
   sphere { < 2, 0, 0 >, 0.25 }
   cylinder {
      < 2, 0, 0 >,
      < 2, 2, 0 >
      0.25
   }
   object {
      Ball_Base
      rotate < 180, 0, 0 >
      translate < 2, 2.5, 0 >
   }
   sphere {
      < 2, 2.5, 0 >, 0.59
      pigment { color White }
   }
   texture { T_Brass_2C }
}

#declare Lamp = union {
   cylinder {
      < 0, 0, 0 >,
      < 0, 0.5, 0 >,
      1.0
      pigment { color Tan }
   }
   cone {
      < 0, 0.5, 0 >, 0.75
      < 0, 10.0, 0 >, 0.5
      texture { T_Brass_2C }
   }
   sphere {
      < 0, 10, 0 >, 0.6
      texture { T_Brass_2C }
   }
   cylinder {
      < 0, 10, 0 >,
      < 0, 13, 0 >,
      0.25
      texture { T_Brass_2C }
   }
   object {
      Ball_Base
      rotate < 180, 0, 0 >
      translate < 2, 13.5, 0 >
      texture { T_Brass_2C }
   }
   sphere {
      < 2, 13.5, 0 >, 0.59
      pigment { color White }
   }
   object {
      Lamp_Arm
      translate < 0, 10, 0 >
   }
   object {
      Lamp_Arm
      rotate < 0, 120, 0 >
      translate < 0, 10, 0 >
   }
   object {
      Lamp_Arm
      rotate < 0, 240, 0 >
      translate < 0, 10, 0 >
   }
}

object { Lamp }

camera {
   location < 15, 3, -15 >
   look_at < 0, 5, 0 >
}

light_source { < 100,  1000, -1000 > color White }
light_source { < 100, -1000, -1000 > color White }
