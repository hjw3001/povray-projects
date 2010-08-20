// water.inc
//
// This file contains the POV information for the ocean. The water is taken
// from one of my earlier scenes of the Pantheon.
//
// Scale 1 inch = 1 POV unit
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)
// Started: 9/24/1995

#if (clock_on=1)
    #declare wave_phase = clock;
#else
    #declare wave_phase = 0;
#end


#declare M_Watx =
material {
  texture {
    pigment {
      color rgbt <0.4,0.5,0.3, 0.9>
    }
     normal {
        waves 0.05
        frequency 2000.0
        scale 4000.0
        phase wave_phase
     }
    finish {
      diffuse 0.5
      ambient 0.0

      reflection {
        0.05, 1.0
        fresnel on
      }

      conserve_energy

      specular 0.4
      roughness 0.003
    }
  }
  interior {
    ior 1.33
    fade_distance 0.5
    fade_power 1001
  }
}

/*

#include "povwaves.inc"
#declare Scale_Z = 0.02;

isosurface {
  function {
    y - Waves(0, 4.4, 0, 250) * Scale_Z*0.15
  }

  max_gradient 2

  contained_by { box { <-1001, -0.81, -1001>, <1001, 0.08, 1001> } }

  material { M_Watx }
  hollow on
  photons {
    target
    reflection on
    collect off
  }
}
*/
#declare ocean = plane {
     < 0, 1, 0 >, 0.0
     material {
      M_Watx
      // texture {
         // T_Silver_1C
         /* -- What I had been using
         pigment { color NewMidnightBlue }
         normal {
            waves 0.05
            frequency 2000.0
            scale 4000.0
            phase wave_phase
         }
         finish {
            reflection 0.6
            roughness 1
         }
         */
         /* -- New texture, didn't work well
         finish {
            diffuse 0.0
            ambient -0.2

            reflection {
               0.0, 0.95
               fresnel on
            }

            conserve_energy

            specular 0.4
            roughness 0.007
         }
         */
      // }
      // interior {
      //   ior 1.31
      //   fade_distance 5
      //   fade_power 1001.0
      //   fade_color <0.02, 0.20, 0.06>
      // }
     }
   // }
   /*
   plane {
      < 0, 1, 0 >, -5
      pigment { color Blue }
      hollow on
   }
   */
}

#declare oceanOff = plane { < 0, 1, 0 >, 0 pigment { color Blue } }
