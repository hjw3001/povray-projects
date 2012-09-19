// sky.pov

#include "colors.inc"
#include "sky1.inc"

plane { < 0, 1, 0 >, 0 pigment { color Blue } }

camera {
   location < 200, 3, -100 >
   // location <  1, 3, -50 >
   look_at  <  0, 15,   0 >
}

light_source { < 100,  1000, -1000 > color White }
