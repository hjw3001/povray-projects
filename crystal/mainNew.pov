// main.pov
//
// Written by: Henry Wagner (henryw@panix.com)

#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "finish.inc"
#include "frame.inc"
#include "enviro.inc"

#version 3.5;

object { Metal_Frame }

// These are the windows
union {
   triangle { < -50, 0, -50 >, < 0, 100, 0 >, < 50, 0, -50 > }
   triangle { < -50, 0, -50 >, < 0, 100, 0 >, < -50, 0, 50 > }
   triangle { <  50, 0, -50 >, < 0, 100, 0 >, < 50, 0, 50 > }
   triangle { < 50, 0, 50 >, < 0, 100, 0 >, < -50, 0, 50 > }

   texture { T_Glass1 }
}

light_source { < 1000, 1000, -1000 > color White }

camera {
   location < 100, 10, -100 >
   look_at < 0, 50, 0 >
}
   
plane {
   < 0, 1, 0 >, 0
   pigment { color Green }
}

// Dark cloudy sky
sky_sphere {
    pigment {
        wrinkles
        turbulence 0.3
        omega 0.707
        octaves 5
        color_map {
            [0.0 color DustyRose * 2.5]
//            [0.2 color DustyRose ]
            [0.2 color Orange ]
//            [0.8 color DarkSlateGray * 0.5]
            [0.8 color SlateBlue * 0.25]
            [1.0 color SkyBlue]
        }
        scale <0.5, 0.1, 1000>
    }
}
