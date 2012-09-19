// water.inc
//
// This file contains the POV information for the ocean. The water is taken
// from one of my earlier scenes of the Pantheon.
//
// Scale 1 inch = 1 POV unit
//
// Written by: Henry Wagner
// Started: 9/24/1995

#declare ocean = union {
   plane { < 0, 1, 0 >, 0.0
      texture {
         // T_Silver_1C
         pigment { color NewMidnightBlue }
      }
      normal {
         waves 0.05
         frequency 2000.0
         scale 4000.0
         phase WAVE_PHASE
      }
      finish {
         reflection 0.6
         roughness 1
      }
   }
   plane {
      < 0, 1, 0 >, -5
      pigment { color Blue }
   }
}

#declare ocean1 = plane { < 0, 1, 0 >, 0 pigment { color Blue } }