// Fireworks.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "pyrotech.inc"

#declare initGen = seed(360);

// #declare FireWorksClock = clock;
#declare FireWorksClock = .23;

// #declare Brightness = 0.013;
#declare Brightness = 0.018;
#declare Illumination = 0.2;
#declare MaxSize = 120;
                         
#declare NumShells = 10;
#declare counter = 0;
#while (counter < NumShells)
    Pyrotech1 (
        // <+8,-1,30>-y*(FireWorksClock*2)*(FireWorksClock*2), 18, // location, size
        < (rand(initGen) * 80) - StadiumCenter, ((rand(initGen) * 80) + 190), rand(initGen) * 80 >, (rand(initGen) * 20) + MaxSize
        (FireWorksClock-rand(initGen))*2, // local clock
        1, 200, Brightness, // type, number_of_glows, brightness
        <rand(initGen),rand(initGen),rand(initGen)>, <rand(initGen),rand(initGen),rand(initGen)>, 2, Illumination // color1, color2, seed, illuminate
    )
    #declare counter = counter + 1;
#end
 