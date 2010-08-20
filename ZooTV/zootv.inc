// zootv.inc
//
// This is the neon Zoo TV logo used at the top of the Zoo TV stage
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare BIGR = 0.30;
#declare LITR = 0.25;

#declare ZooTVRedCycleSpeed = 30;
#declare ZooTVGreenCycleSpeed = 20;

#if (clock_on = 1)
    #declare ZooFN = frame_number;
#else
    #declare ZooFN = 50;
#end

#if ((mod(ZooFN,ZooTVRedCycleSpeed)/ZooTVRedCycleSpeed) > 0.5)
    #declare DisplayRedNeon = false;
#else
    #declare DisplayRedNeon = true;
#end

#if ((mod(ZooFN,ZooTVGreenCycleSpeed)/ZooTVGreenCycleSpeed) > 0.5)
    #declare DisplayGreenNeon = false;
#else
    #declare DisplayGreenNeon = true;
#end

#declare Zoo_Red = merge {
   cylinder {
      < -10.5, -3, 0 >,
      <  -4.5, -3, 0 >,
      BIGR
   }
   cylinder {
      < -10.5,  3, 0 >,
      <  -4.5,  3, 0 >,
      BIGR
   }
   cylinder {
      < -10.5, -3, 0 >,
      <  -4.5,  3, 0 >,
      BIGR
   }
   sphere { < -10.5, -3, 0 >, BIGR }
   sphere { < -10.5,  3, 0 >, BIGR }
   sphere { <  -4.5, -3, 0 >, BIGR }
   sphere { <  -4.5,  3, 0 >, BIGR }

   torus {
      3.0, BIGR
      rotate < 90, 0, 0 >
   }

   torus {
      3.0, BIGR
      rotate < 90, 0, 0 >
      translate < 7.5, 0, 0 >
   }

   #if (DisplayRedNeon = true)   
      texture { Red_Neon }
   #else
      texture { Red_Glass }
   #end
}

#declare Zoo_Green = merge {
   // This is the T
   cylinder {
      < 0,  1.2, 0 >,
      < 0, -1.6, 0 >,
      LITR
   }
   cylinder {
      < -1.4, 1.2, 0 >,
      <  1.4, 1.2, 0 >,
      LITR
   }
   sphere { <    0, -1.6, 0 >, LITR }
   sphere { < -1.4,  1.2, 0 >, LITR }
   sphere { <  1.4,  1.2, 0 >, LITR }

   // This is the V
   union {
      cylinder {
         < -1.4,  1.2, 0 >,
         <  0.0, -1.6, 0 >,
         LITR
      }
      cylinder {
         <  1.4,  1.2, 0 >,
         <  0.0, -1.6, 0 >,
         LITR
      }
      sphere { < -1.4,  1.2, 0 >, LITR }
      sphere { <  1.4,  1.2, 0 >, LITR }
      sphere { <  0.0, -1.6, 0 >, LITR }

      translate < 7.5, 0, 0 >
   }

   #if (DisplayGreenNeon = true)   
      texture { Green_Neon }
   #else
      texture { Green_Glass }
   #end
}
