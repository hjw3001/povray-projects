#include "candles.inc"

#declare wavephase = 0.1;

// This is the sidewalk texture
#declare Concrete = texture {
   pigment { color Wheat }
   scale 10
}

// This is the glass for red lights
#declare Red_Glass = texture { T_Ruby_Glass }

// This is the structure for the columns for the greek temple
#declare column =
union {
   // This is the base of the column
   box {
      < -900,    0, -900 >,
      <  900, 1000,  900 >
      texture {
         Grnt5
         finish { Shiny }
         scale 10
      }
   }

   cylinder {
      < 0, 1000, 0 >,
      < 0, 1800, 0 >,
      800.0
      texture {
         Grnt3
         finish { Shiny }
         scale 10
      }
   }

   cylinder {
      < 0,  1800, 0 >,
      < 0, 10000, 0 >,
      600.0
      texture {
         Grnt2
         finish { Shiny }
         scale 10
      }
   }

   cylinder {
      < 0, 10000, 0 >,
      < 0, 12000, 0 >,
      650.0
      texture {
         Grnt3
         finish { Shiny }
         scale 10
      }
   }

   cylinder {
      < 0, 12000, 0 >,
      < 0, 12500, 0 >,
      700.0
      texture {
         Grnt0
         finish { Shiny }
         scale 10
      }
   }

   box {
      < -750, 12500, -750 >,
      <  750, 13000,  750 >
      texture {
         Grnt14
         finish { Shiny }
         scale 10
      }
   }
}

// This is the ring that goes around the elevated walkways
#declare Ring = difference {
   cylinder {
      < 0, 0, -25 >,
      < 0, 0,  25 >,
      800.0
   }
   cylinder {
      < 0, 0, -26 >,
      < 0, 0,  26 >,
      750.5
   }
   texture{ T_Gold_3B }
}

#declare Big_Ring = difference {
   cylinder {
      < -50, 0, 0 >,
      <  50, 0, 0 >,
      1050.0
   }
   cylinder {
      < -51, 0, 0 >,
      <  51, 0, 0 >,
      1000.5
   }
   texture{ T_Gold_3B }
}

#declare Sky_Light = difference {
   union {
      cylinder {
         < -1000, 0, 0 >,
         <  1000, 0, 0 >,
         1000.0
         texture{ Glass }
      }
      object {
         Big_Ring
         translate< -950, 0, 0 >
      }
      object {
         Big_Ring
         translate< -500, 0, 0 >
      }
      object {
         Big_Ring
         translate< 950, 0, 0 >
      }
      object {
         Big_Ring
         translate< 500, 0, 0 >
      }
      object {
         Big_Ring
      }
      box {
         < -950,  990, -50 >,
         <  950, 1050,  50 >
         texture{ T_Gold_3B }
      }
   }
   box {
      < -1010, -1010, -1010 >,
      <  1010,     0,  1010 >
      texture{ Glass }
   }
}

plane { // This is the ground
   < 0, 1, 0 >, 0
   pigment{ Black }
}

sphere { // This is the sky
   < 0, 0, 0 >, 5000000
   texture { pigment { Apocalypse } scale 1000000 }
}

// This is the sun
light_source { < 100000, 500000, -20000 > color White }

// This is the sidewalk for the spaceport
box {
   < -20000, 0, -14000 >,
   <  26000, 1,  22000 >
   texture{ Concrete }
}

union { // These are the support columns for the flight-deck
   cylinder {
      < -12000,     0, -4000 >,
      < -12000, 10000, -4000 >,
      1000.0
   }
   cylinder {
      < -12000,     0, 10000 >,
      < -12000, 10000, 10000 >,
      1000.0
   }
   cylinder {
      < 16000,     0, 16000 >,
      < 16000, 10000, 16000 >,
      1000.0
   }
   cylinder {
      < 16000,     0, -4000 >,
      < 16000, 10000, -4000 >,
      1000.0
   }
   cylinder {
      < 2000,     0, -4000 >,
      < 2000, 10000, -4000 >,
      1000.0
   }
   texture {
      pigment{ SteelBlue }
      finish { Shiny }
   }
}

// These are the elevated walkways
union {
   cylinder {
      < -12000, 7000, -4000 >,
      < -12000, 7000, 10000 >,
      750.0
   }
   cylinder {
      < -30000, 7000, -2000 >,
      < -30000, 7000,  8000 >,
      750.0
   }
   cylinder {
      < -30000, 7000, 3000 >,
      < -12000, 7000, 3000 >,
      750.0
   }
   cylinder {
      < -12000, 7000, 7000 >,
      <   4000, 7000, 7000 >,
      750.0
   }
   cylinder {
      < -32000, 7000,  -8000 >,
      < -32000, 7000, -22000 >,
      750.0
   }
   cylinder {
      < -34000, 7000, -28000 >,
      < -28000, 7000, -28000 >,
      750.0
   }
   cylinder {
      < -28000, 7000, -27000 >,
      < -11000, 7000, -27000 >,
      750.0
   }
   cylinder {
      < -12000, 7000,  -4000 >,
      < -12000, 7000, -25000 >,
      750.0
   }
   cylinder {
      < 16000, 7000, -4000 >,
      < 16000, 7000, 16000 >,
      750.0
   }
   texture{ Glass }
}

// These are the rings around the cylinders
union {
   object {
      Ring
      translate< -12000, 7000, -2000 >
   }
   object {
      Ring
      translate< -12000, 7000, 0 >
   }
   object {
      Ring
      translate< -12000, 7000, 2000 >
   }
   object {
      Ring
      translate< -12000, 7000, 4000 >
   }
   object {
      Ring
      translate< -12000, 7000, 6000 >
   }
   object {
      Ring
      translate< -12000, 7000, 8000 >
   }
   object {
      Ring
      translate< -30000, 7000, -2000 >
   }
   object {
      Ring
      translate< -30000, 7000, 0 >
   }
   object {
      Ring
      translate< -30000, 7000, 2000 >
   }
   object {
      Ring
      translate< -30000, 7000, 4000 >
   }
   object {
      Ring
      translate< -30000, 7000, 6000 >
   }
   object {
      Ring
      translate< -30000, 7000, 8000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -14000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -16000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -18000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -20000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -22000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -24000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -26000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -28000, 7000, 3000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -10000, 7000, 7000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -8000, 7000, 7000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -6000, 7000, 7000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -4000, 7000, 7000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -2000, 7000, 7000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< 0, 7000, 7000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< 2000, 7000, 7000 >
   }
   object {
      Ring
      translate< -32000, 7000, -8000 >
   }
   object {
      Ring
      translate< -32000, 7000, -10000 >
   }
   object {
      Ring
      translate< -32000, 7000, -12000 >
   }
   object {
      Ring
      translate< -32000, 7000, -14000 >
   }
   object {
      Ring
      translate< -32000, 7000, -16000 >
   }
   object {
      Ring
      translate< -32000, 7000, -18000 >
   }
   object {
      Ring
      translate< -32000, 7000, -20000 >
   }
   object {
      Ring
      translate< -32000, 7000, -28000 >
   }
   object {
      Ring
      translate< -30000, 7000, -28000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -26000, 7000, -27000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -24000, 7000, -27000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -22000, 7000, -27000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -20000, 7000, -27000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -18000, 7000, -27000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -16000, 7000, -27000 >
   }
   object {
      Ring
      rotate< 0, 90, 0 >
      translate< -14000, 7000, -27000 >
   }
   object {
      Ring
      translate< -12000, 7000, -6000 >
   }
   object {
      Ring
      translate< -12000, 7000, -8000 >
   }
   object {
      Ring
      translate< -12000, 7000, -10000 >
   }
   object {
      Ring
      translate< -12000, 7000, -12000 >
   }
   object {
      Ring
      translate< -12000, 7000, -14000 >
   }
   object {
      Ring
      translate< -12000, 7000, -16000 >
   }
   object {
      Ring
      translate< -12000, 7000, -18000 >
   }
   object {
      Ring
      translate< -12000, 7000, -20000 >
   }
   object {
      Ring
      translate< -12000, 7000, -22000 >
   }
   object {
      Ring
      translate< 16000, 7000, -2000 >
   }
   object {
      Ring
      translate< 16000, 7000, 0 >
   }
   object {
      Ring
      translate< 16000, 7000, 2000 >
   }
   object {
      Ring
      translate< 16000, 7000, 4000 >
   }
   object {
      Ring
      translate< 16000, 7000, 6000 >
   }
   object {
      Ring
      translate< 16000, 7000, 8000 >
   }
   object {
      Ring
      translate< 16000, 7000, 10000 >
   }
   object {
      Ring
      translate< 16000, 7000, 12000 >
   }
   object {
      Ring
      translate< 16000, 7000, 14000 >
   }
}

// These are the boxed which form the runways
union {
   box {
      < -16000, 10000, -6000 >,
      <  -8000, 10010, 12000 >
   }
   box {
      < -8000, 10000, -6000 >,
      < 14000, 10010, -2000 >
   }
   box {
      < 14000, 10000, -10000 >,
      < 18000, 10010,   2000 >
   }
   box { 
      < 18000, 10000, -6000 >,
      < 22000, 10010, -2000 >
   }
   // These triangles form the sides of the octagon
   triangle {
      < 10000, 10000, -2000 >,
      < 14000, 10000, -2000 >,
      < 14000, 10000,  2000 >
   }
   triangle {
      < 10000, 10010, -2000 >,
      < 14000, 10010, -2000 >,
      < 14000, 10010,  2000 >
   }
   triangle {
      < 10000, 10000, -2000 >,
      < 10000, 10010, -2000 >,
      < 14000, 10000,  2000 >
   }
   triangle {
      < 14000, 10000,  2000 >,
      < 14000, 10010,  2000 >,
      < 10000, 10010, -2000 >
   }
   triangle {
      < 18000, 10000, -2000 >,
      < 18000, 10000,  2000 >,
      < 22000, 10000, -2000 >
   }
   triangle {
      < 18000, 10010, -2000 >,
      < 18000, 10010,  2000 >,
      < 22000, 10010, -2000 >
   }
   triangle {
      < 18000, 10000,  2000 >,
      < 18000, 10010,  2000 >,
      < 22000, 10000, -2000 >
   }
   triangle {
      < 22000, 10000, -2000 >,
      < 22000, 10010, -2000 >,
      < 18000, 10010,  2000 >
   }
   triangle {
      < 18000, 10000,  -6000 >,
      < 18000, 10000, -10000 >,
      < 22000, 10000,  -6000 >
   }
   triangle {
      < 18000, 10010,  -6000 >,
      < 18000, 10010, -10000 >,
      < 22000, 10010,  -6000 >
   }
   triangle {
      < 22000, 10000,  -6000 >,
      < 22000, 10010,  -6000 >,
      < 18000, 10000, -10000 >
   }
   triangle {
      < 18000, 10000, -10000 >,
      < 18000, 10010, -10000 >,
      < 22000, 10010,  -6000 >
   }
   triangle {
      < 10000, 10000,  -6000 >,
      < 14000, 10000,  -6000 >,
      < 14000, 10000, -10000 >
   }
   triangle {
      < 10000, 10010,  -6000 >,
      < 14000, 10010,  -6000 >,
      < 14000, 10010, -10000 >
   }
   triangle {
      < 10000, 10000,  -6000 >,
      < 10000, 10010,  -6000 >,
      < 14000, 10000, -10000 >
   }
   triangle {
      < 14000, 10000, -10000 >,
      < 14000, 10010, -10000 >,
      < 10000, 10010,  -6000 >
   }
   box {
      < 14000, 10000,  2000 >,
      < 18000, 10010, 18000 >
   }
   triangle {
      < 12000, 10000, 18000 >,
      < 14000, 10000, 18000 >,
      < 14000, 10000, 16000 >
   }
   triangle {
      < 12000, 10010, 18000 >,
      < 14000, 10010, 18000 >,
      < 14000, 10010, 16000 >
   }
   triangle {
      < 12000, 10000, 18000 >,
      < 12000, 10010, 18000 >,
      < 14000, 10000, 16000 >
   }
   triangle {
      < 14000, 10000, 16000 >,
      < 14000, 10010, 16000 >,
      < 12000, 10010, 18000 >
   }
   triangle {
      < 12000, 10000, 18000 >,
      < 12000, 10010, 18000 >,
      < 14000, 10000, 18000 >
   }
   triangle {
      < 14000, 10000, 18000 >,
      < 14000, 10010, 18000 >,
      < 12000, 10010, 18000 >
   }
   triangle {
      < 18000, 10000, 18000 >,
      < 18000, 10000, 16000 >,
      < 20000, 10000, 18000 >
   }
   triangle {
      < 18000, 10010, 18000 >,
      < 18000, 10010, 16000 >,
      < 20000, 10010, 18000 >
   }
   triangle {
      < 18000, 10000, 16000 >,
      < 18000, 10010, 16000 >,
      < 20000, 10000, 18000 >
   }
   triangle {
      < 20000, 10000, 18000 >,
      < 20000, 10010, 18000 >,
      < 18000, 10010, 16000 >
   }
   triangle {
      < 20000, 10000, 18000 >,
      < 20000, 10010, 18000 >,
      < 18000, 10000, 18000 >
   }
   triangle {
      < 18000, 10000, 18000 >,
      < 18000, 10010, 18000 >,
      < 20000, 10010, 18000 >
   }
   texture {
      pigment{ SteelBlue }
      finish { Shiny }
   }
}

// This is the base of the control tower
cylinder {
   < 4000,     0, 8000 >,
   < 4000, 12000, 8000 >,
   2000.0
   texture {
      pigment{ LightSteelBlue }
      finish{ Shiny }
   }
}

// This is the roof of the enterance to the control tower
box {
   <    0, 1000,  4000 >,
   < 8000, 1001, 12000 >
   texture {
      pigment{ LightSteelBlue }
      finish{ Shiny }
   }
}

// This is the enterance to the control tower
difference {
   box {
      <    0,    1,  4000 >,
      < 8000, 1000, 12000 >
      texture{ T_Brass_4D }
   }
   union {
      // This is the main cutout for the lobby
      box {
         <    1,   2,  4001 >,
         < 7999, 999, 11999 >
      }
      // These are the windows
      box {
         < 7998,  10, 4010 >,
         < 8001, 990, 5000 >
      }
      box {
         < 7998,  10, 5100 >,
         < 8001, 990, 6000 >
      }
      box {
         < 7998,  10, 6100 >,
         < 8001, 990, 7000 >
      }
      box {
         < 7998,  10, 7100 >,
         < 8001, 990, 8000 >
      }
      box {
         < 7998,  10, 8100 >,
         < 8001, 990, 9000 >
      }
      box {
         < 7998,  10,  9100 >,
         < 8001, 990, 10000 >
      }
      box {
         < 7998,  10, 10100 >,
         < 8001, 990, 11000 >
      }
      box {
         < 7998,  10, 11100 >,
         < 8001, 990, 11990 >
      }
      box {
         <   10,  10, 3999 >,
         < 1000, 990, 4002 >
      }
      box {
         < 1100,  10, 3999 >,
         < 2000, 990, 4002 >
      }
      box {
         < 2100,  10, 3999 >,
         < 3000, 990, 4002 >
      }
      box {
         < 3100,  10, 3999 >,
         < 4000, 990, 4002 >
      }
      box {
         < 4100,  10, 3999 >,
         < 5000, 990, 4002 >
      }
      box {
         < 5100,  10, 3999 >,
         < 6000, 990, 4002 >
      }
      box {
         < 6100,  10, 3999 >,
         < 7000, 990, 4002 >
      }
      box {
         < 7100,  10, 3999 >,
         < 7990, 990, 4002 >
      }
      box {
         < -1,  10, 4010 >,
         <  2, 990, 5000 >
      }
      box {
         < -1,  10, 5100 >,
         <  2, 990, 6000 >
      }
      box {
         < -1,  10, 6100 >,
         <  2, 990, 7000 > 
      }
      box {
         < -1,  10, 7100 >,
         <  2, 990, 8000 >
      }
      box {
         < -1,  10, 8100 >,
         <  2, 990, 9000 >
      }
      box {
         < -1,  10,  9100 >,
         <  2, 990, 10000 >
      }
      box {
         < -1,  10, 10100 >,
         <  2, 990, 11000 >
      }
      box {
         < -1,  10, 11100 >,
         <  2, 990, 11990 >
      }
      box {
         <   10,  10, 11998 >,
         < 1000, 990, 12001 >
      }
      box {
         < 1100,  10, 11998 >,
         < 2000, 990, 12001 >
      }
      box {
         < 2100,  10, 11998 >,
         < 3000, 990, 12001 >
      }
      box {
         < 3100,  10, 11998 >,
         < 4000, 990, 12001 >
      }
      box {
         < 4100,  10, 11998 >,
         < 5000, 990, 12001 >
      }
      box {
         < 5100,  10, 11998 >,
         < 6000, 990, 12001 >
      }
      box {
         < 6100,  10, 11998 >,
         < 7000, 990, 12001 >
      }
      box {
         < 7100,  10, 11998 >,
         < 7990, 990, 12001 >
      }
      texture {
         pigment { Jade }
         scale 5
      }
   }
}

// This is the lobby window
box {
   <    0.5,   1.5,  4000.5 >,
   < 7999.5, 999.5, 11999.5 >
   texture{ Glass }
}

// This is a light source inside the lobby
light_source{ < 4000, 800, 5000 > color White }

// This is the midsection of the control tower
sphere {
   < 4000, 14000, 8000 >, 3000.0
   texture {
      pigment{ LightSteelBlue }
      finish{ Shiny }
   }
}

// This is the top of the control tower
difference {
   cylinder {
      < 4000, 16000, 8000 >,
      < 4000, 19000, 8000 >,
      2000.0
   }
   cylinder {
      < 4000, 17000, 8000 >,
      < 4000, 18100, 8000 >,
      2001.0
   }
   texture {
      pigment{ LightSteelBlue }
      finish{ Shiny }
   }
}

// This is the window near the top of the control tower
cylinder {
   < 4000, 17000, 8000 >,
   < 4000, 18100, 8000 >,
   2000.0
   texture { Green_Glass }
}
// This is the light inside the control tower
light_source {
   < 4000, 18090, 8000 >
   color Green
   spotlight
   point_at < 4000, 17000, 8000 >
   radius 60
   falloff 75
}

// This is the torus around the tower

// This is Henry Wagner Graphic Designs Galactic Headquarters
// This is the sidewalk
box {
   < -44000, 0, -14000 >,
   < -24000, 1,  22000 >
   texture{ Concrete }
}

// This is the building structure
union {
   // This is the south tower
   box {
      < -38000,     1, -8000 >,
      < -26000, 20000, -2000 >
   }
   // This is the north tower
   box {
      < -38000,     1,  8000 >,
      < -26000, 20000, 14000 >
   }
   // This is the low cross building
   box {
      < -34000,    1, -2000 >,
      < -30000, 2000,  8000 >
   }
   texture {
      pigment{ color NewMidnightBlue }
      finish{ Shiny }
   }
}

// These are the supports for the sign
union {
   cylinder {
      < -28000, 20000, -5000 >,
      < -28000, 22000, -5000 >,
      500.0
   }
   cylinder {
      < -28000, 20000, 11000 >,
      < -28000, 22000, 11000 >,
      500.0
   }
   box {
      < -29000, 22000, -7500 >,
      < -27000, 22100, 13500 >
   }
   texture { T_Gold_3B }
}

// These are the letters for the sign
union {
   object {
      char_H
      rotate < 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -6650 >
   }
   object {
      char_E
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -5900 >
   }
   object {
      char_N
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -5150 >
   }
   object {
      char_R
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -4400 >
   }
   object {
      char_Y
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -3650 >
   }
   object {
      char_W
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -2350 >
   }
   object {
      char_A
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -1600 >
   }
   object {
      char_G
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -850 >
   }
   object {
      char_N
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, -100 >
   }
   object {
      char_E
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 650 >
   }
   object {
      char_R
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 1400 >
   }
   object {
      char_G
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 2700 >
   }
   object {
      char_R
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 3450 >
   }
   object {
      char_A
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 4200 >
   }
   object {
      char_P
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 4950 >
   }
   object {
      char_H
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 5700 >
   }
   object {
      char_I
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 6350 >
   }
   object {
      char_C
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 7000 >
   }
   object {
      char_D
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 8300 >
   }
   object {
      char_E
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 9050 >
   }
   object {
      char_S
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 9800 >
   }
   object {
      char_I
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 10450 >
   }
   object {
      char_G
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 11100 >
   }
   object {
      char_N
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 11850 >
   }
   object {
      char_S
      rotate< 0, -90, 0 >
      scale 160.71
      translate< -28000, 22100, 12600 >
   }
   texture {
      pigment { Blue_Agate }
      finish { Shiny }
      scale 5
   }
}

difference {
   // This is the enterance
   box {
      < -30000,    1, 1000 >,
      < -28000, 1000, 5000 >
      texture {
         pigment { color NewMidnightBlue }
         finish { Shiny }
      }
   }
   // These are the cutouts for the windows
   union {
      // This is the main interior
      box {
         < -29995,    2, 1005 >,
         < -28005, 1001, 4995 >
      }
      box {
         < -28006,  10, 1010 >, 
         < -27999, 900, 2000 >
      }
      box {
         < -28006,  10, 4100 >,
         < -27999, 900, 4990 >
      }
      box {
         < -28006,  10, 2100 >,
         < -27999, 900, 3000 >
      }
      box {
         < -28006,  10, 3100 >,
         < -27999, 900, 4000 >
      }
      box {
         < -29990,  10,  999 >,
         < -29000, 990, 1006 >
      }
      box {
         < -28900,  10,  999 >,
         < -28010, 990, 1006 >
      }
      box {
         < -29990,  10, 4994 >,
         < -29000, 990, 5001 >
      }
      box {
         < -28900,  10, 4994 >,
         < -28010, 990, 5001 >
      }

      texture { T_Gold_3B }
   }
}

// This is the window for the lobby of HWGDGH
box {
   < -29998,   .5, 1002 >,
   < -28002, 1000, 4998 >
   texture{ Glass }
}

// This is the pool in the lobby
union {
   box {
      < -29500,  1, 2000 >,
      < -29450, 20, 4000 >
   }
   box {
      < -28550,  1, 2000 >,
      < -28500, 20, 4000 >
   }
   box {
      < -29450,  1, 2000 >,
      < -28550, 20, 2050 >
   }
   box {
      < -29450,  1, 3950 >,
      < -28550, 20, 4000 >
   }
   texture { pigment { Blood_Marble } scale 5 }
}

// This is the water for the pool
box {
   < -29450,  1, 2050 >,
   < -28550, 18, 3950 >
   pigment { Blue }
   normal {
      waves 0.05
      frequency 5000.0
      scale 3000.0
      phase wavephase
   }
   finish { reflection 0.8 }
}
   
// This is the light inside the HWGDGH lobby
light_source{ < -29000, 800, 3000 > color White }

// These are the sky lights above the enterance
object {
   Sky_Light
   translate< -29000, 1000, 2000 >
}
object {
   Sky_Light
   translate< -29000, 1000, 4000 >
}

// This is the sidewalk for the cylinder building
box {
   < -44000, 0, -32000 >,
   < -24000, 1, -18000 >
   texture{ Concrete }
}

// These are the towers for the cylinder buildings
union {
   cylinder {
      < -36000,     1, -26000 >,
      < -36000, 18000, -26000 >,
      5000.0
   }
   cylinder {
      < -32000,     1, -22000 >,
      < -32000, 16000, -22000 >,
      2000.0
   }
   cylinder {
      < -34000,     1, -22000 >,
      < -34000, 13000, -22000 >,
      1700.0
   }
   cylinder {
      < -28000,     1, -28000 >,
      < -28000, 10000, -28000 >,
      2000.0
   }
   texture{ pigment{ color Plum } finish{ Shiny } }
}

// This is the sidewalk for the pointed building
box {
   < -20000, 0, -32000 >,
   <  -2000, 1, -18000 >
   texture{ Concrete }
}

// These are the four sides of the triangle building
   union {
      triangle {
         < -16000,     1, -20000 >,
         < -16000,     1, -30000 >,
         < -11000, 19000, -25000 >
      }
      triangle {
         < -16000,     1, -20000 >,
         <  -6000,     1, -20000 >,
         < -11000, 19000, -25000 >
      }
      triangle {
         <  -6000,     1, -20000 >,
         <  -6000,     1, -30000 >,
         < -11000, 19000, -25000 >
      }
      triangle {
         < -16000,     1, -30000 >,
         <  -6000,     1, -30000 >,
         < -11000, 19000, -25000 >
      }
      texture{ Gold_Texture }
   }

// This is the sidewalk for the supply depot
box {
   <  2000, 0, -32000 >,
   < 26000, 1, -18000 >
   texture{ Concrete }
}

// These are the fuel spheres
union {
   sphere { <  8000, 5500, -26000 >, 5000 }
   sphere { < 20000, 5500, -26000 >, 5000 }
   texture { T_Chrome_3B }
}

// These are the supports for the fuel spheres
union {
   cylinder {
      < 6000,    1, -24000 >,
      < 6000, 5500, -24000 >,
      100.0
   }
   cylinder {
      < 6000,    1, -28000 >,
      < 6000, 5500, -28000 >,
      100.0
   }
   cylinder {
      < 10000,    1, -24000 >,
      < 10000, 5500, -24000 >,
      100.0
   }
   cylinder {
      < 10000,    1, -28000 >,
      < 10000, 5500, -28000 >,
      100.0
   }
   cylinder {
      < 18000,    1, -24000 >,
      < 18000, 5500, -24000 >,
      100.0
   }
   cylinder {
      < 18000,    1, -28000 >,
      < 18000, 5500, -28000 >,
      100.0
   }
   cylinder {
      < 22000,    1, -24000 >,
      < 22000, 5500, -24000 >,
      100.0
   }
   cylinder {
      < 22000,    1, -28000 >,
      < 22000, 5500, -28000 >,
      100.0
   }
   texture { T_Brass_1A }
}

// This is this sidewalk for U2 ZOO TV Plaza
box {
   < -44000, 0, 26000 >,
   <  -2000, 1, 36000 >
   texture{ Concrete }
}

// This is sidewalk for the Pantheon structure
box {
   < 30000, 0, -14000 >,
   < 66000, 1,  22000 >
   texture{ Concrete }
}

// These are the steps up to the temple
union {
   // These are the steps
   box { 
      < 36000,   1, -8000 >,
      < 36200, 200, 16000 >
   }
   box {
      < 36200,   1, -8000 >,
      < 36400, 400, 16000 >
   }
   box {
      < 36400,   1, -8000 >,
      < 36600, 600, 16000 >
   }
   box {
      < 36600,   1, -8000 >,
      < 36800, 800, 16000 >
   }
   box {
      < 36800,    1, -8000 >,
      < 37000, 1000, 16000 >
   }
   box {
      < 37000,    1, -8000 >,
      < 37200, 1200, 16000 >
   }
   box {
      < 37200,    1, -8000 >,
      < 37400, 1400, 16000 >
   }
   box {
      < 37400,    1, -8000 >,
      < 37600, 1600, 16000 >
   }
   box {
      < 37600,    1, -8000 >,
      < 37800, 1800, 16000 >
   }
   box {
      < 37800,    1, -8000 >,
      < 38000, 2000, 16000 >
   }
   // These are the two sides of the steps
   box {
      < 36000,    1, -10000 >,
      < 38000, 2000,  -8000 >
      texture { Grnt10 scale 10 }
   }
   box {
      < 36000,    1, 16000 >,
      < 38000, 2000, 18000 >
      texture { Grnt10 scale 10 }
   }
   // This is the main base which supports the temple
   box {
      < 38000,    1, -10000 >,
      < 64000, 2000,  18000 >
   }
   texture { pigment { White_Marble } scale 5 }
}

// These are the columns for the temple
object {
   column
   translate < 39000, 2000, 17000 >
}
object {
   column
   translate < 39000, 2000, 15000 >
}

// This is the test candle
object {
   Candles
   rotate < 0, 90, 0 >
   translate < 38400, 10000, 15000 >
}
 
object {
   column
   translate < 39000, 2000, 13000 >
}
object {
   column
   translate < 39000, 2000, 11000 >
}
object {
   column
   translate < 39000, 2000,  9000 >
}
object {
   column
   translate < 39000, 2000,  7000 >
}
object {
   column
   translate < 39000, 2000,  5000 >
}
object {
   column
   translate < 39000, 2000,  3000 >
}
object {
   column
   translate < 39000, 2000,  1000 >
}
object {
   column
   translate < 39000, 2000, -1000 >
}
object {
   column
   translate < 39000, 2000, -3000 >
}
object {
   column
   translate < 39000, 2000, -5000 >
}
object {
   column
   translate < 39000, 2000, -7000 >
}
object {
   Candles
   rotate < 0, 90, 0 >
   translate < 38400, 10000, -7000 >
}
object {
   column
   translate < 39000, 2000, -9000 >
}
// This is the south side
object {
   column
   translate < 41000, 2000, -9000 >
}
object {
   column
   translate < 43000, 2000, -9000 >
}
object {
   column
   translate < 45000, 2000, -9000 >
}
object {
   column
   translate < 47000, 2000, -9000 >
}
object {
   column
   translate < 49000, 2000, -9000 >
}
object {
   column
   translate < 51000, 2000, -9000 >
}
object {
   column
   translate < 53000, 2000, -9000 >
}
object {
   column
   translate < 55000, 2000, -9000 >
}
object {
   column
   translate < 57000, 2000, -9000 >
}
object {
   column
   translate < 59000, 2000, -9000 >
}
object {
   column
   translate < 61000, 2000, -9000 >
}
object {
   column
   translate < 63000, 2000, -9000 >
}
// These are the east columns
object {
   column
   translate < 63000, 2000, -7000 >
}
object {
   column
   translate < 63000, 2000, -5000 >
}
object {
   column
   translate < 63000, 2000, -3000 >
}
object {
   column
   translate < 63000, 2000, -1000 >
}
object {
   column
   translate < 63000, 2000,  1000 >
}
object {
   column
   translate < 63000, 2000,  3000 >
}
object {
   column
   translate < 63000, 2000,  5000 >
}
object {
   column
   translate < 63000, 2000,  7000 >
}
object {
   column
   translate < 63000, 2000,  9000 >
}
object {
   column
   translate < 63000, 2000, 11000 >
}
object {
   column
   translate < 63000, 2000, 13000 >
}
object {
   column
   translate < 63000, 2000, 15000 >
}
object {
   column
   translate < 63000, 2000, 17000 >
}
object {
   column
   translate < 61000, 2000, 17000 >
}
object {
   column
   translate < 59000, 2000, 17000 >
}
object {
   column
   translate < 57000, 2000, 17000 >
}
object {
   column
   translate < 55000, 2000, 17000 >
}
object {
   column
   translate < 53000, 2000, 17000 >
}
object {
   column
   translate < 51000, 2000, 17000 >
}
object {
   column
   translate < 49000, 2000, 17000 >
}
object {
   column
   translate < 47000, 2000, 17000 >
}
object {
   column
   translate < 45000, 2000, 17000 >
}
object {
   column
   translate < 43000, 2000, 17000 >
}
object {
   column
   translate < 41000, 2000, 17000 >
}

// This is the roof over the Pantheon
box {
   < 38000, 15000, -10000 >,
   < 64000, 16000,  18000 >
   texture { pigment { White_Marble } scale 5 }
}
