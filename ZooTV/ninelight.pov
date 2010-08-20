// ninelight.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"
#include "ninelight.inc"
#include "field.inc"

#declare nineLightZ = 178;

object {
    NineLight(true)
    translate < -70, 10, nineLightZ >
}

camera {
    location < -70, 5, 0 >
    // location < -70, 100, nineLightZ >
    look_at < -70, 10, nineLightZ >
}
/*
fog {
    distance 150
    color rgb<0.5, 0.5, 0.5>
    // fog_type 2
}
*/