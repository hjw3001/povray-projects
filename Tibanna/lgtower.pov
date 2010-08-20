// lgtower.pov
//
// This is a test scene file for the Light_Tower object
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)
// Started: 12/15/1996

#version 3.0
global_settings { assumed_gamma 2.2 }

#include "colors.inc"
#include "metals.inc"

#declare Main_Metal = texture {
   pigment { P_Copper3 }
   finish {
      ambient 0.35
      brilliance 2
      diffuse 0.3
      metallic
      specular 0.80
      roughness 1/20
      reflection 0.05
   }
}

#include "lgtower.inc"

object { Light_Tower }

camera {
   location < 120, -60, 120 >
   look_at < 0, -59, 0 >
}

light_source { < 1000, 100, 1000 > color White }