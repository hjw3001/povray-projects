// fighter.pov
//
// This is a simple space fighter created for POV-Ray
//
// Written by: Henry Wagner (povray@henrywagner.org)

#version 3.5;

#include "colors.inc"
#include "textures.inc"
#include "golds.inc"

#include "fighter.inc"
// #include "stars.inc"

#if (clock_on=1)
    #declare rfact = clock;
#else
    #declare rfact = 0;
#end    `

light_source {
    <  1000, 1000, -1000 >
    color White+Gold
    photons {
        reflection on
        refraction on
    }
}

light_source {
    < -1000, 1000, -1000 >
    color White+Gold
    photons {
        reflection on
        refraction on
    }
}

camera {
   location < 1500, 600, -500 >
   look_at  < 0, 0, 0 >
   up < 0, 1, 0 >
   right < 16/9, 0, 0 >
}

// object { STAR_FIELD }
object {
   Ship
   rotate < 0, rfact, 0 >
}
