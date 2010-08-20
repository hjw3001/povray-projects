// TopLight.pov
//
// Test scene for the TopLightRig
//
// Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "TopLght.inc"
#include "TopLight.inc"
#include "scrframe.inc"
// #include "screen.inc"
// #include "olive.inc"
// #include "arch.inc"
// #include "stadium.inc"

object { TopLightRig }

light_source { < 1000, 1000, -1000 > color red 1.0 green 1.0 blue 1.0 }

camera {
   location < -60, 60, 191 >
   // look_at < 40, 70, 198 >
   look_at < -60, 75.3125, 198 >
}

light_source { <0, 15, 0> color rgb 0.7
  media_interaction off
  shadowless
}
/*
object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}
*/