// balloon.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)
// Started: 12/15/1996

#version unofficial megapov 1.1;

#include "stays.inc"

#declare Light_Rod = union {
   cylinder {
      < 0, -350, 0 >,
      < 20, -350, 0 >,
      2.0
      texture { Balloon_Texture }
   }
   light_source {
      < 20, -350, 0 >
      color White
      glow { size 0.5 type 2 }
      fade_distance 3 fade_power 2
   }
}

#declare Balloon = union {
   object {
      Stays
   }
   object {
      torus { 500, 3 }
      translate < 0, 500, 0 >
   }
   object {
      torus { 450, 3 }
      translate < 0, 100, 0 >
   }

   sphere {
      < 0, 0, 0 >, 50
      scale < 1, .8, 1 >
      translate < 0, 450, 0 >
   }

   // This is the main body connector
   cone {
      < 0, 450, 0 >, 50.0
      < 0, -400, 0 >, 0.0
   }
   light_source {
      < 0, -401, 0 >
      color White
      glow { size 0.5 type 2 }
      fade_distance 3 fade_power 2
   }

   // This is the shade for the passenger area
   cone {
      < 0, 200, 0 >, 335.714
      < 0, 280, 0 >, 244.2857
      open
   }

   object {
      Light_Rod
   }
   object {
      Light_Rod
      rotate < 0, 30, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 60, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 90, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 120, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 150, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 180, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 210, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 240, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 270, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 300, 0 >
   }
   object {
      Light_Rod
      rotate < 0, 330, 0 >
   }

   cylinder {
      < 0, -200, 0 >,
      < 0, -210, 0 >,
      50.0
   }

   cone {
      < 0, -70, 0 >, 60.0
      < 0, -40, 0 >, 150.0
   }
   object {
      Main_Detail_2
      rotate < 0, 180, 0 >
      translate < 0, -70, 0 >
   }
   cone {
      < 0, -40, 0 >, 150.0
      < 0, -20, 0 >, 200.0
   }
   difference {
      cylinder {
         < 0, -20, 0 >,
         < 0, 0, 0 >,
         180.0
      }
      object {
         Main_Window_1
         translate < 0, -10, 0 >
      }
   }
   cylinder {
      < 0, -19, 0 >,
      < 0,  -1, 0 >,
      179.0
      texture { Window_Light }
   }

   cone {
      < 0,  0, 0 >, 200.0
      < 0, 20, 0 >, 230.0
   }
   cylinder {
      < 0, 20, 0 >,
      < 0, 25, 0 >,
      230.0
   }
   object {
      Main_Detail_1
      translate < 0, 25, 0 >
   }

   difference {
      difference {
         sphere {
            < 0, 0, 0 >, 500.0
            scale < 1, 1.1, 1 >
         }
         box {
            < -505, -1000, -505 >,
            <  505,     0,  505 >
         }
      }
      sphere {
         < 0, 0, 0 >, 499.0
         scale < 1, 1.1, 1 >
      }
      translate < 0, 500, 0 >
   }

   light_source { < 0, 1000, 0 > color White }

   texture { Balloon_Texture }
}