// stage.inc
//
// This is the base of the main stage, catwalk, and b stage.
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare useBStage = false;

#declare Stage_Black = texture {
   pigment { color Gray35 }
}

#declare Stage_White = texture {
   pigment { color White }
}

#declare Main_Stage = union {
   // Main top stage
   box {
      < -75,  0, 170 >,
      <  75, 10, 200 >
      texture { Stage_Black }
   }
   union {
      box {
         < -75, 10, 170 >,
         <  75, 10.1, 170.4 >
      }
      box {
         < -75, 10, 170 >,
         < -74.6, 10.1, 200 >
      }
      box {
         < 74.6, 10, 170 >,
         < 75, 10.1, 200 >
      }
      box {
         < -75, 10, 199.6 >,
         <  75, 10.1, 200 >
      }
      texture { Stage_White }
   }
   // walkway in front of the stage
   box {
      < -75, 0, 165 >,
      <  75, 5, 170 >
      texture { Stage_Black }
   }
   union {
      box {
         < -75, 5, 165 >,
         <  75, 5.1, 165.4 >
      }
      box {
         < -75, 5, 165 >,
         < -74.6, 5.1, 170 >
      }
      box {
         < 74.6, 5, 165 >,
         < 75, 5.1, 170 >
      }
      box {
         < -75, 5, 169.6 >,
         <  75, 5.1, 170 >
      }
      texture { Stage_White }
   }
   // b stage catwalk
   #if (useBStage = true)
   box {
      < 30, 0, 100 >,
      < 35, 4, 170 >
      texture { Stage_Black }
   }
   #end
}

object { Main_Stage }