// support.inc
//
// Written by: Henry Wagner (povray@henrywagner.org)

object {
   Support1
   translate < -65, 0, 201.5 >
}

object {
   Support2
   translate < -37, 0, 201.5 >
}

object {
   Support3
   translate < -9, 0, 201.5 >
}

object {
   Support4
   translate < 19, 0, 201.5 >
}

object {
   Support5
   translate < 47, 0, 201.5 >
}

object {
   Support6
   translate < 75, 0, 201.5 >
}

union {
   cylinder {
      < -64, 78, 199 >,
      <  76, 88, 199 >,
      0.3
   }
   cylinder {
      < -64, 78, 197 >,
      <  76, 88, 197 >,
      0.3
   }
   cylinder {
      < -64, 76, 198 >,
      <  76, 86, 198 >,
      0.3
   }

   texture {
      pigment { color red 0.7 green 0.7 blue 0.7 }
      finish { metallic }
   }
}
