// scaffolding.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"
#include "skies.inc"
#include "scaffolding.inc"

plane {
    < 0, 1, 0 >, 0
    pigment { color Green }
}

light_source {
    < 10000, 10000, -10000 >
    color White+Gold
    parallel
    point_at < 0, 0, 0 >
}

camera {
    location < -4, 5, -22 >
    look_at < 5, 10, 0 >
}

sky_sphere { S_Cloud2 }
