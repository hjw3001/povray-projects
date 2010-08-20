// videowalls.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"
#include "finish.inc"
#include "metals.inc"
#include "textures.inc"
#include "hwcolors.inc"
#include "videowalls.inc"
#include "whiteroom.inc"

object {
    TVScreen
    translate < 3, 21, 185 >
}

camera {
   location < 1, 22, 181 >   
   look_at < 3, 21.75, 185 >
}

// light_source { < 1000, 1000, -1000 > color White+Gold }

// plane { < 0, 1, 0 >, 0 pigment { color Green } }
