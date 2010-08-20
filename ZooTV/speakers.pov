// speakers.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"
#include "speakers.inc"
#include "scaffolding.inc"
#include "whiteroombasic.inc"

union {
    GenerateSpeakers(0.9, 0.9, 0.3, 0.1, 10, 20)
    pigment { rgb 0.1 }
}

union {
    GenerateScaffolding(8,12,5,3,0.1,0.04)
    translate < 0, 0, 1 >
    texture {
        pigment { color Red }
        finish { metallic }
    }
}

camera {
    location < -4, 5, -22 >
    look_at < 5, 10, 0 >
}
