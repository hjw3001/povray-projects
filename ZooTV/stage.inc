// stage.inc
//
// This is the base of the main stage, catwalk, and b stage.
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare useBStage = false;

#include "speakers.inc"
// #include "scaffolding.inc"

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
      < -30, 0, 100 >,
      < -35, 4, 170 >
      texture { Stage_Black }
   }
   #end
}

#declare Left_Speakers = union {
    GenerateSpeakers(2.7, 2.7, 0.4, 0.3, 10, 15)
    translate < -65, 10, 180 >
    /*
    < -65, 10, 180 >,
    < -35, 55, 185 >
   */
    texture { Stage_Black }
}

#declare Right_Speakers = union {
    GenerateSpeakers(2.7, 2.7, 0.4, 0.3, 10, 15)
    translate < 35, 10, 180 >
    /*
    < 35, 10, 180 >,
    < 65, 55, 185 >
    */
    texture { Stage_Black }
}
/*
light_source {
    < -20, 12, 195 >
    color Blue+Gold
    spotlight
    radius 100
    falloff 20
    point_at < -65, 45, 180 >
    fade_distance 160
    fade_power 3
}

light_source {
    < 20, 12, 195 >
    color Blue+Gold
    spotlight
    radius 100
    falloff 20
    point_at < 65, 45, 180 >
    fade_distance 160
    fade_power 3
}
*/
object { Main_Stage }
object { Left_Speakers }
object { Right_Speakers }
object {
    GuardLight()
    translate < -50, 55, 182.5 >
}
object {
    GuardLight()
    translate < 50, 55, 182.5 >
}