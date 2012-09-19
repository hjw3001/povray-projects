// Persistence Of Vision raytracer version 2.0 sample file.

// By Dan Farmer
// Parabolic arches on the water.  Is this the St. Louis McDonalds? 

#include "colors.inc"
#include "shapes.inc"
#include "stones.inc"
#include "textures.inc"

#include "waves.inc"
#include "enviro.inc"

camera {
   location <60.0, 0.0, -135.0>
   direction <0.0, 0.0, 2.0>
   up  <0.0, 1.0, 0.0>
   right <4/3, 0.0, 0.0>
   look_at <0.0, 0.0, 0.0>
}

// Light 
light_source {<200.0, 200.0, -150.0> colour red 1 green .5 }

// Now draw the sky (From sunset.inc)
sphere { <0.0, 0.0, 0.0>, 300.0

   pigment {
      gradient y
      colour_map {
         [0.0 0.8  colour red 0.5 green 0.1 blue 0.7
                   colour red 0.1 green 0.1 blue 0.9]
         [0.8 1.0  colour red 0.1 green 0.1 blue 0.9
                   colour red 0.1 green 0.1 blue 0.9]
      }
      quick_color red 0.7  green 0.7 blue 1.0
      scale 300.0
   }
   finish { ambient 1 }
}

// Put in a few clouds 
sphere { <0.0, 0.0, 0.0>, 259.0

   pigment {
      bozo
      turbulence 0.7
      colour_map {
         [0.0 0.6  colour red 1.0 green 1.0 blue 1.0 filter 1.0
                   colour red 1.0 green 1.0 blue 1.0 filter 1.0]
         [0.6 0.8  colour red 1.0 green 1.0 blue 1.0 filter 1.0
                   colour red 1.0 green 1.0 blue 1.0]
         [0.8 1.001 colour red 1.0 green 1.0 blue 1.0
                    colour red 0.8 green 0.8 blue 0.8]
      }
      quick_colour red 0.7 green 0.7 blue 1.0
      scale <100.0, 20.0, 100.0>
   }
   finish { ambient 1 }
}


// Define the ocean surface 
plane { y, -10.0

   pigment { Blue }
   normal {
      waves 0.05
      frequency 5000.0
      scale 3000.0
      phase WAVE_PHASE
   }
   finish { reflection 0.8 }
}

/* Put a floor underneath to catch any errant waves from the ripples */
plane { y, -11.0
   pigment { Blue }
   finish {
      ambient 1.0
      diffuse 0.0
   }
}

// Create the arches using CSG difference between two "squashed" paraboloids
difference {
   object { Paraboloid_Y
      scale <20.0, 20.0, 5.0>
      rotate 180*x
   }
   object { Paraboloid_Y
      scale <15.0, 20.0, 15.0>
      rotate 180*x
      translate -2*y
   }

   finish { Metal }
   pigment { White }

   /* Move the whole thing to where I should've
    designed it in the first place!!  */

   translate <0.0, 30.0, -25.0>
}

difference {
   object { Paraboloid_Y
      scale <20.0, 20.0, 5.0>
      rotate 180*x
   }
   object { Paraboloid_Y
      scale <15.0, 20.0, 15.0>
      rotate 180*x
      translate -2*y
   }

   finish { Metal }
   pigment { White }

   /* Move the whole thing to where I should've
    designed it in the first place!!  */
   translate <0.0, 30.0, 50.0>
}
