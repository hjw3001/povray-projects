// lattice.pov
//
// This is a 5x5x5 lattice of gold spheres and blue cylinders connecting
// the spheres together.
//
// Written by: Henry Wagner (povray@henrywagner.org)
// Started: 9/24/1995

#version 3.5;

#include "colors.inc"
#include "textures.inc"
#include "metals.inc"
#include "sky1.inc"
#include "rotate.inc"
// #include "phase.inc"
#include "waves.inc"
#include "water.inc"
#include "enviro.inc"

// #include "camera.inc" // Need camera.cpp to generate this
#include "lattice.inc" // Contains the definitions for the lattice object

camera {
   // For wide screen shot
   // location < 65, 8, 65 >
   // up < 0, 1, 0 >
   // right < 5, 0, 0 >
   // look_at < -40, 0, 40 >
   // For standard shot
   location < -58, -30, -153 >
   up < 0, 1, 0 >
   // right < 1.777, 0, 0 >
   right < 16/9, 0, 0 >
   look_at < 0, 0, 0 >
}

// light_source { < 1000, 1000, 1000 > color White }

object {
   lattice
   rotate < 0, R1, 0 >
}

object {
   ocean
   translate < 0, -50, 0 >
}
