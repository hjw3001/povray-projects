// FireTest.pov
//
// written by: Henry Wagner

#version unofficial megapov 1.1;

#include "colors.inc"
#include "pyrotech.inc"
#include "stadium.inc"

#declare initGen = seed(360);

plane { < 0, 1, 0 >, 0 pigment { color Green } }

camera {
    location < 200, 150, 0 >
    look_at  < 0, 180, 0 >
}

#declare Clock = clock;
//#declare Clock = .23;

// #declare Brightness = 0.013;
#declare Brightness = 0.018;
#declare Illumination = 0.2;
                         
#declare NumShells = 10;
#declare counter = 0;
#while (counter < NumShells)
    Pyrotech1 (
        // <+8,-1,30>-y*(Clock*2)*(Clock*2), 18, // location, size
        < rand(initGen) * 80, ((rand(initGen) * 80) + 100), rand(initGen) * 80 >, (rand(initGen) * 20) + 80
        (Clock-rand(initGen))*2, // local clock
        1, 200, Brightness, // type, number_of_glows, brightness
        <rand(initGen),rand(initGen),rand(initGen)>, <rand(initGen),rand(initGen),rand(initGen)>, 2, Illumination // color1, color2, seed, illuminate
    )
    #declare counter = counter + 1;
#end

object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}
