// This is a test for additional objects for the nextd.pov file
//
// Written by: Henry Wagner     Started: 6/26/94

// Begin adding on the triangle top piece
#declare PantheonCrown = union {
   // Top slanted pieces
   triangle{ < 380, 120, -100 >, < 450, 120, -100 >, < 450, 165,   40 > }
   triangle{ < 380, 120, -100 >, < 450, 165,   40 >, < 380, 165,   40 > }
   triangle{ < 380, 120,  180 >, < 450, 120,  180 >, < 450, 165,   40 > }
   triangle{ < 450, 165,   40 >, < 380, 165,   40 >, < 380, 120,  180 > }
   // Back piece   triangle{ < 450, 120, -100 >, < 450, 120,  180 >, < 450, 165,   40 > }
   // Front rim pieces
   triangle{ < 380, 120, -100 >, < 380, 165,   40 >, < 380, 160,   40 > }
   triangle{ < 380, 120,  -95 >, < 380, 160,   40 >, < 380, 120, -100 > }
   triangle{ < 380, 120,  180 >, < 380, 165,   40 >, < 380, 160,   40 > }
   triangle{ < 380, 120,  180 >, < 380, 120,  175 >, < 380, 160,   40 > }
   // Front indented piece
   triangle{ < 390, 120,  -95 >, < 390, 160,   40 >, < 390, 120,  175 > }
   // Front indented connecting pieces
   triangle{ < 390, 120,  -95 >, < 380, 120,  -95 >, < 390, 160,   40 > }
   triangle{ < 380, 120,  -95 >, < 380, 160,   40 >, < 390, 160,   40 > }
   triangle{ < 380, 120,  175 >, < 390, 120,  175 >, < 390, 160,   40 > }
   triangle{ < 380, 120,  175 >, < 380, 160,   40 >, < 390, 160,   40 > }

   texture{ Grnt5 scale 10 }
}

#declare PantheonText = union {
   object {
      char_H
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 140 >
   }
   object {
      char_E
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 132 >
   }
   object {
      char_N
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 124 >
   }
   object {
      char_R
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 116 >
   }
   object {
      char_Y
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 108 >
   }
   object {
      char_W
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 98 >
   }
   object {
      char_A
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 90 >
   }
   object {
      char_G
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 82 >
   }
   object {
      char_N
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 74 >
   }
   object {
      char_E
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 66 >
   }
   object {
      char_R
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 58 >
   }
   object {
      char_G
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 40 >
   }
   object {
      char_R
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 32 >
   }
   object {
      char_A
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 24 >
   }
   object {
      char_P
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 16 >
   }
   object {
      char_H
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 8 >
   }
   object {
      char_I
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, 3 >
   }
   object {
      char_C
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -2 >
   }
   object {
      char_D
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -10 >
   }
   object {
      char_E
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -18 >
   }
   object {
      char_S
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -26 >
   }
   object {
      char_I
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -31 >
   }
   object {
      char_G
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -36 >
   }
   object {
      char_N
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -44 >
   }
   object {
      char_S
      scale 1.5
      rotate< 0, 90, 0 >
      scale< 1.5, 1, 1 >
      translate< 380, 120, -52 >
   }

   texture {
      T_Stone24
      finish { Shiny }
      scale 5
   }
}
