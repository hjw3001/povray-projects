// This is a small city that I started developing to be used as a base for
// my space ships. It is only partially finished, mabye one day I will get
// back to it.
//
//	Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "shapes.inc"
#include "shapesq.inc"
#include "chars.inc"
#include "stones.inc"
#include "stoneold.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "3dsmater.inc"

// #include "fighter.inc"
#include "basecity.inc"

camera {
// These are the backdrop camera locations
//   location < 26000, 150, 12000 >
   location < 26000, 20000, 22000 >
   look_at  < 0, 7000, 8000 >
//   location < 37000, 6500, 14500 >
//   look_at  < 38400, 6000, 15000 >
}

// This is a light on the side of the Pantheon
// light_source{ < 66000, 20000, 30000 >color White }
/*
object {
   Ship
   translate < 18000, 12310, 15000 >
   rotate    < 90, 0, 0 >
   scale 10
}
*/
