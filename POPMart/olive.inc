// olive.inc
//
// Definition for the olive and toothpick
//
// Written by: Henry Wagner (povray@henrywagner.org)

#include "functions.inc"

#if (clock_on=1)
    #declare FN = mod(frame_number, 30);
    #switch (FN)
        #range(0, 5)
            #declare neonRedBrightness = FN;
            #break                      
        #range(5,25)
            #declare neonRedBrightness = 5;
            #break                      
        #range(25,30)
            #declare neonRedBrightness = 5 - (FN - 25);
            #break                      
        #else
            #declare neonRedBrightness = 0;        
    #end
    #declare FN = mod(frame_number, 35);
    #switch (FN)
        #range(0, 5)
            #declare neonGreenBrightness = FN;
            #break                      
        #range(5,30)
            #declare neonGreenBrightness = 5;
            #break                      
        #range(30,35)
            #declare neonGreenBrightness = 5 - (FN - 30);
            #break                      
        #else
            #declare neonGreenBrightness = 0;        
    #end
#else
    #declare neonRedBrightness = 5;
    #declare neonGreenBrightness = 5;
#end

#declare Toothpick = cone {
   < 71, 9, 192 >, 1.5,
   < 96.76, 110, 192 >, 0.0
   texture {
      pigment { color Orange }
      finish {
         ambient 0.5
         diffuse 0.4
         roughness 0.001
      }
   }
}

#declare Olive = union {
   sphere {
      < 0, 0, 0 >, 2
      scale < 1.6, 1, 1 >
      texture {
         pigment { color Yellow }
         finish {
            metallic
            specular 1
            roughness 0.001
            ambient 0.6
            diffuse 0.4
            reflection 0.01
         }
      }
   }
   cylinder {
      < 0, 0, 0 >,
      < -3.21, 0, 0 >,
      1.05
      texture {
         pigment { color red 1.0 green 0.0 blue 0.0 }
         finish {
            ambient 1.0
            diffuse 0.0
            reflection .25
            // refraction 1
            // ior 1.5
            specular 1
            roughness .001
         }
      }
   }

   torus {
      3.9, 0.12
      
      pigment { color rgbt 1 }
      finish { ambient 4.0 diffuse 0 reflection 0.5}
      hollow
      interior {
        media {
            emission rgb <1, 0.01, 0.001> * neonRedBrightness
            // emission rgb color_val * 15
            density {
                function { f_torus(x,y,z,3.9,0.06) }
            }
        }
      }
/*
      texture {
         pigment { color red 0.9 green 0.0 blue 0.0 }
         finish {
         #if (displayNeon = true)
            ambient 0.9
         #else
            ambient 0.5
         #end
            diffuse 0.0
            reflection .25
            // refraction 1
            // ior 1.5
            specular 1
            roughness .001
         }
      }
*/
      rotate < -15, 0, 0 >
      rotate < 0, 0, 25 >
      rotate < 0, 5, 0 >
   }

   torus {
      4.2, 0.12

      pigment { color rgbt 1 }
      finish { ambient 4.0 diffuse 0 reflection 0.5}
      hollow
      interior {
        media {
            emission rgb <0.01, 1, 0.001> * neonGreenBrightness
            // emission rgb color_val * 15
            density {
                function { f_torus(x,y,z,4.2,0.06) }
            }
        }
      }
/*
      texture {
         pigment { color red 0.0 green 0.9 blue 0.0 }
         finish {
         #if (displayNeon = false)
            ambient 0.9
         #else
            ambient 0.5
         #end
            diffuse 0.0
            reflection .25
            // refraction 1
            // ior 1.5
            specular 1
            roughness .001
         }
      }
*/
      rotate < 15, 0, 0 >
      rotate < 0, 0, 25 >
      rotate < 0, 5, 0 >
   }
}  

object { Toothpick }

object {
   Olive
   rotate < 0, 0, -10 >
   translate < 93.5, 98, 192 >
}
