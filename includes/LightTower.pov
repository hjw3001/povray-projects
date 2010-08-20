// LightTower.pov

#include "colors.inc"
#include "LightTower.inc"


LightTower()

plane { < 0, 1, 0 >, 0 pigment { color Green } }

// light_source { < 1000, 1000, -1000 > color White+Gold }

camera {
    // location < 0, 30, -20 >
    // look_at < 0, 30, 0 >
    location < 0, 200, -10 >
    look_at < 0, 0, 0 >
}