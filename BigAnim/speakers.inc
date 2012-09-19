// speakers.inc
//
// Definitions for the big, orange, speakers.
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare R1 = -5;
#declare R2 = -10;
#declare R3 = -15;
#declare R4 = -20;
#declare R5 = -30;

#declare Speaker = difference {
   box {
      < -1.9, -1.9, -1.4 >,
      <  1.9,  1.9,  0 >
   }
   box {
      < -1.7, -1.7, -1.5 >,
      <  1.7,  1.7, -1.3 >
   }
}

#declare Speaker_0 = object {
   Speaker
   translate < 0, 0, -14.8 >
}

#declare Speaker_1 = object {
   Speaker
   translate < 0, 0, -14.66 >
}

#declare Speaker_2 = object {
   Speaker
   translate < 0, 0, -14.25 >
}

#declare Speaker_3 = object {
   Speaker
   translate < 0, 0, -13.9 >
}

#declare Speaker_4 = object {
   Speaker
   translate < 0, 0, -13.4 >
}

#declare Speaker_5 = object {
   Speaker
   translate < 0, 0, -13.1 >
}

#declare Speaker_Mount_0 = union {
   object {
      Speaker_0
      rotate < 0, -90, 0 >
   }
   object {
      Speaker_0
      rotate < 0, -70, 0 >
   }
   object {
      Speaker_0
      rotate < 0, -50, 0 >
   }
   object {
      Speaker_0
      rotate < 0, -30, 0 >
   }
   object {
      Speaker_0
      rotate < 0, -10, 0 >
   }
   object {
      Speaker_0
      rotate < 0, 10, 0 >
   }
   object {
      Speaker_0
      rotate < 0, 30, 0 >
   }
   object {
      Speaker_0
      rotate < 0, 50, 0 >
   }
   object {
      Speaker_0
      rotate < 0, 70, 0 >
   }
   object {
      Speaker_0
      rotate < 0, 90, 0 >
   }

   translate < 0, 80, 178 >
}

#declare Speaker_Mount_1 = union {
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, -90, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, -70, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, -50, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, -30, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, -10, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, 10, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, 50, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, 70, 0 >
   }
   object {
      Speaker_1
      rotate < R1, 0, 0 >
      rotate < 0, 90, 0 >
   }

   translate < 0, 76.7, 178 >
}

#declare Speaker_Mount_2 = union {
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, -90, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, -70, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, -50, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, -30, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, -10, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, 10, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, 50, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, 70, 0 >
   }
   object {
      Speaker_2
      rotate < R2, 0, 0 >
      rotate < 0, 90, 0 >
   }

   translate < 0, 73.6, 178 >
}

#declare Speaker_Mount_3 = union {
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, -90, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, -70, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, -50, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, -30, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, -10, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, 10, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, 50, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, 70, 0 >
   }
   object {
      Speaker_3
      rotate < R3, 0, 0 >
      rotate < 0, 90, 0 >
   }

   translate < 0, 70.55, 178 >
}

#declare Speaker_Mount_4 = union {
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, -90, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, -70, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, -50, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, -30, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, -10, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, 10, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, 50, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, 70, 0 >
   }
   object {
      Speaker_4
      rotate < R4, 0, 0 >
      rotate < 0, 90, 0 >
   }

   translate < 0, 67.5, 178 >
}

#declare Speaker_Mount_5 = union {
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, -90, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, -70, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, -50, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, -30, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, -10, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, 10, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, 30, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, 50, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, 70, 0 >
   }
   object {
      Speaker_5
      rotate < R5, 0, 0 >
      rotate < 0, 90, 0 >
   }

   translate < 0, 65.7, 178 >
}
