// column1.inc
//
// This file contains definitions for a candle and column.
//
// by: Henry Wagner Graphic Designs. Started 4/24/94
//
// This is the definition for the gold material used on the candle and
// column. It is very shiny but has no reflection. This seems to work
// better for this application of gold.
//
// This is a candle which can be mounted on the column or any other object.
// The candle points in the -z direction ( by default ) use:
// rotate< 0, -90, 0 > to make it point left ( +x )
// rotate< 0, 180, 0 > to make it point back ( +z )
// rotate< 0,  90, 0 > to make it point right( -x )

#declare candle = union {
   union {
      // This is the piece that sticks out from column
      cylinder {
         < 0, 0,  0 >,
         < 0, 0, -2 >,
         0.5
      }
      // This is the cross support
      cylinder {
         < -2, 0, -2 >,
         <  2, 0, -2 >,
         0.5
      }
      // This is one of the candles
      cylinder {
         < -1.5, 0, -2 >,
         < -1.5, 2, -2 >,
         0.25
      }
      // This is the other candle
      cylinder {
         < 1.5, 0, -2 >,
         < 1.5, 2, -2 >,
         0.25
      }

      texture { T_Gold_3B }
   }

   sphere { < -1.5, 3, -2 >, 1 texture{ YELLOW_GLASS } } 
   sphere { <  1.5, 3, -2 >, 1 texture{ YELLOW_GLASS } } 
} // End of candle definition

#declare column = union {
   box {
      < -8, 0, -8 >,
      <  8, 1,  8 >
      texture {
         Grnt5
         scale 10
         finish { Shiny }
      }
   }
   cylinder {
      < 0, 1, 0 >,
      < 0, 3, 0 >,
      7.5
      texture {
         Grnt6
         scale 10
         finish { Shiny }
      }
   }
   object {
      torus { 6.5, 1 }
      texture { T_Gold_3B }
      translate < 0, 4, 0 >
   }
   // This is the main section
   cylinder {
      < 0,  3, 0 >,
      < 0, 94, 0 >,
      7.0
      texture {
         Grnt8
         scale 10
         finish { Shiny }
      }
   }
   /*
   union {
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 12, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 24, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 36, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 48, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 60, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 72, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 84, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 96, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 108, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 120, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 132, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 144, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 156, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 168, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 180, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 192, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 204, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 216, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 228, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 240, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 252, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 264, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 276, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 288, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 300, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 312, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 324, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 336, 0 >
      }
      cylinder {
         < 0,  3, -6.2 >,
         < 0, 94, -6.2 >,
         1.0
         rotate < 0, 348, 0 >
      }
      texture {
         Grnt8
         scale 10
         finish { Shiny }
      }
   }
   */

   // This begins the upper portion
   cylinder {
      < 0, 90, 0 >,
      < 0, 92, 0 >,
      7.5
      texture {
         Grnt9
         scale 10
         finish { Shiny }
      }
   }
   // These are the Gold spheres that surround the top
   union {
      sphere { <  7.00, 91,  0.00 >, 0.9 }
      sphere { <  4.95, 91,  4.95 >, 0.9 }
      sphere { < -7.00, 91,  0.00 >, 0.9 }
      sphere { <  4.95, 91, -4.95 >, 0.9 }
      sphere { <  0.00, 91,  7.00 >, 0.9 }
      sphere { < -4.95, 91, -4.95 >, 0.9 }
      sphere { <  0.00, 91, -7.00 >, 0.9 }
      sphere { < -4.95, 91,  4.95 >, 0.9 }
      sphere { <  2.68, 91,  6.47 >, 0.9 }
      sphere { < -2.68, 91,  6.47 >, 0.9 }
      sphere { <  2.68, 91, -6.47 >, 0.9 }
      sphere { < -2.68, 91, -6.47 >, 0.9 }
      sphere { <  6.47, 91,  2.68 >, 0.9 }
      sphere { <  6.47, 91, -2.68 >, 0.9 }
      sphere { < -6.47, 91,  2.68 >, 0.9 }
      sphere { < -6.47, 91, -2.68 >, 0.9 }

      texture { T_Gold_3B }
   }

   object {
      torus { 6.5, 1 }
      translate< 0, 93, 0 >
      texture {
         Grnt11
         scale 10
         finish { Shiny }
      }
   }
   box {
      < -8, 94, -8 >,
      <  8, 96,  8 >
      texture {
         Grnt12
         scale 10
         finish { Shiny }
      }
   }
} // End of column definition
