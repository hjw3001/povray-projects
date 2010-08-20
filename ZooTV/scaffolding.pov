// scaffolding.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"
#include "scaffolding.inc"
#include "whiteroombasic.inc"

camera {
    location < -4, 5, -22 >
    look_at < 8, 10, 0 >
}

object {
    GenerateScaffolding(8,12,5,3,0.1,0.04)
    texture {
        pigment { rgb 0.1 }
        finish { metallic }
    }
}
