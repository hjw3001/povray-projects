// balloon.pov
//
// This is a test scene file for the balloon object.
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)
// Started: 12/28/96

#include "colors.inc"
#include "metals.inc"

#declare Balloon_Texture = texture {
   // pigment { color < 0.929411, 0.945098, 0.545098 > }
   // pigment { color < 1.0, 0.917647, 0.396078 > }
   pigment { color < 0.945098, 0.690196, 0.043137 > }
   finish {
      specular  0.55
      roughness 0.15
   }
}

#declare Window_Light = texture {
   pigment { color White }
   finish {
      ambient 1.0
      diffuse 0.0
   }
}

#include "window15.inc"
#include "detail2.inc"
#include "detail3.inc"
#include "balloon.inc"

// Use the same camera position as the final rendering position
camera {
   location < 300, -55,   1950 >
   // look_at  <   0, -54, -10000 >
   look_at  < 400, -25, 1800 >
/*
   aperture 2
   focal_point <0, 0, 0>

   blur_samples 7
   confidence 0.5             // default is 0.9
   variance 1/64              // default is 1/128 (0.0078125)
*/
/*
   blur_samples 37
   confidence 0.975           // default is 0.9
   variance 1/255             // default is 1/128 (0.0078125)
*/
}

// Use the same light positions as the final rendering positions
/*
light_source { < 10000, 10000, 10000 > color White }
light_source { < 10000, -10000, 10000 > color White }
*/

light_source {
   < 10000, 0, 0 >
   color White
   area_light < 0, 10000, 0 >, < 0, 0, 10000 >, 5, 5
   adaptive 1
   jitter
}

object {
   Balloon
   scale 0.08
   translate < 400, -25, 1800 >
}

object {
   Balloon
   scale 0.08
   translate < 700, 10, 1300 >
}
