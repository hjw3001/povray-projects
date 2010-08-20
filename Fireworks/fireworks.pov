// POV-Ray 3.1 Scene Description File
// "Fireworks" copyright September 2000 Rune S. Johansen
// 
// Recommended rendering and encoding: 100 frames at 25 fps
// 
// This scene requires MegaPov 0.7:
// http://nathan.kopp.com/patched.htm
   
   #version unofficial megapov 1.1;
   
   #include "pyrotech.inc"
   
   #declare Clock = clock;
   
   Pyrotech1 (
      <+8,-1,30>-y*(Clock*2)*(Clock*2), 18, // location, size
      Clock*2, // local clock
      1, 200, 0.013, // type, number_of_glows, brightness
      <0.5,0.5,0.3>, <0.8,0.8,0.6>, 2, 1 // color1, color2, seed, illuminate
   )
   
   Pyrotech1 (
      <-8,-2,30>-y*((Clock-0.3)*2)*((Clock-0.3)*2), 16, // location, size
      (Clock-0.3)*2, // local clock
      2, 100, 0.026, // type, number_of_glows, brightness
      <0.0,0.0,0.0>, <0.8,0.2,1.0>, 2, 1 // color1, color2, seed, illuminate
   )
   
   Pyrotech1 (
      <+5,+5,30>-y*((Clock-0.5)*2)*((Clock-0.5)*2), 17, // location, size
      (Clock-0.5)*2, // local clock
      2, 200, 0.013, // type, number_of_glows, brightness
      <0.0,0.0,0.0>, <0.4,1.0,0.5>, 2, 1 // color1, color2, seed, illuminate
   )
   
// A plane with some smokey pattern
/*
   plane {
      -z, 0 translate 100*z
      pigment {
         wrinkles
         scale 50
         color_map {
            [0.3, color rgb 0.0]
            [1.0, color rgb 0.3]
         }
      }
      finish {ambient 0 diffuse 1}
   }
*/