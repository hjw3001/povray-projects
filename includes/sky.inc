// sky.inc
//
// This file contains the POV information about the sky for my kitchen scene
//
// Scale 1 inch = 1 POV unit
//
// Written by: Henry Wagner
// Started: 9/24/1995

sphere { <0, 0, 0>, 300000
   pigment {
      gradient <0, 1, 0>
      colour_map {
         [0, 0.8  colour red 1   green 0.3 blue 0
                  colour red 0.7 green 0.7 blue 1]
         [0.8, 1  colour red 0.7 green 0.7 blue 1
                  colour red 0.7 green 0.7 blue 1]
      }
      scale <300000,  300000,  300000.0>
      quick_colour red 0.7  green 0.7 blue 1.0
   }
   finish {
      ambient 0.7 
      diffuse 0   /* we don't want clouds casting shadows on the sky */
   }
}

// This is the sun
light_source {
   < 0, 0, 0 > color Orange
   looks_like {
      sphere {
         < 0, 0, 0 >, 20000
         texture {
            pigment { color Orange }
            finish {
               ambient 1.0
               diffuse 0.0
            }
            normal { bumps 0.2 }
         }
      }
      translate < -263113.9338, 0, 95765.64012 >
   }
}

//CLOUDS
sphere{ <0, 0, 0>, 1 no_shadow
   texture { 
      pigment {
         bozo
         turbulence 1.0
         octaves 3
         lambda 6
         color_map { 
            [ 0.00 0.6 color Clear  color  Clear ]
            [ 0.94     color Gray70 filter .100  ]
            [ 0.97     color Gray60 filter .075  ]
            [ 1.00     color Gray70 filter .050  ]
         }
      }
      finish {
         ambient .7
         diffuse 0
      }
      scale 1/15
   }
   scale <260000, 10000, 50000>
   rotate < 0, 90, 0 >
}
