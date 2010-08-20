// ninelight.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"
#include "ninelight.inc"

NineLight()

camera {
    location < 2, 1, -2 >
    look_at  < 0, 0.75, 0 >
}

light_source {
    < -1000, 1000, -1000 >
    color White+Gold
}

plane {
    < 0, 1, 0 >, 0
    pigment { color Green }
}
