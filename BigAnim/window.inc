// This is the big stained glass window for the Greek Partheon type structure
// Created by: Henry Wagner Graphic Designs. Started 4/24/94

#declare frame =
union {
   box {
      < -25, 20, -0.5 >,
      <  25, 65,  0.5 >
   }
   cylinder {
      <   0, 65, -0.5 >,
      <   0, 65,  0.5 >,
      25.0
   }
   texture{ GOLD1 } // Defined in column1.inc
}

#declare sub_frame =
union {
   box {
      < -25, 20, -1.5 >,
      <  25, 65,  1.5 >
   }
   cylinder {
      < 0, 65, -1.5 >,
      < 0, 65,  1.5 >,
      25.0
   }
   texture{ Grnt5 scale 10 }
}
  
#declare cutframe =
difference {
   object {
      frame
   }
   union {
      // This is the cut-out for the large circle
      // cylinder {
      //    < 0, 65, -1 >,
      //    < 0, 65,  1 >,
      //    24.0
      // }
      // These are the cut-outs for the upper section
      box {
         < -4, 43, -1 >,
         <  4, 81,  1 >
      }
      cylinder {
         <  0, 85, -1 >,
         <  0, 85,  1 >,
         4.0
      }
      box {
         < -12, 43, -1 >,
         <  -5, 78,  1 >
      }
      cylinder {
         <  -8.5, 82, -1 >,
         <  -8.5, 82,  1 >,
         4.0
      }
      box {
         <  5, 43, -1 >,
         < 12, 78,  1 >
      }
      cylinder {
         <  8.5, 82, -1 >,
         <  8.5, 82,  1 >,
         4.0
      }
      box {
         < -21, 46, -1 >,
         < -13, 71,  1 >
      }
      cylinder {
         < -17, 75, -1 >,
         < -17, 75,  1 >,
         4.0
      }
      box {
         < 13, 46, -1 >,
         < 21, 71,  1 >
      }
      cylinder {
         < 17, 75, -1 >,
         < 17, 75,  1 >,
         4.0
      }
      box {
         < -24, 46, -1 >,
         < -22, 66,  1 >
      }
      cylinder {
         < -23, 67, -1 >,
         < -23, 67,  1 >,
         1.0
      }
      box {
         < 22, 46, -1 >,
         < 24, 66,  1 >
      }
      cylinder {
         < 23, 67, -1 >,
         < 23, 67,  1 >,
         1.0
      }
      // This is the cut-out for the cross
      box {
         < -1, 21, -1 >,
         <  1, 42,  1 >
      }
      box {
         < -7, 34, -1 >,
         <  7, 36,  1 >
      }
      // This is the cut-out for the corner box
      box {
         < -24, 21, -1 >,
         < -17, 32,  1 >
      }
      box {
         <  17, 21, -1 >,
         <  24, 32,  1 >
      }
      // This is the cut-out for the middle lower box
      box {
         < -16, 21, -1 >,
         < -10, 30,  1 >
      }
      box {
         <  10, 21, -1 >,
         <  16, 30,  1 >
      }
      // This is the cut-out for the inside lower box
      box {
         < -9, 21, -1 >,
         < -2, 28,  1 >
      }
      box {
         <  2, 21, -1 >,
         <  9, 28,  1 >
      }
      // This is the cut-out for the four circles around the cross
      cylinder {
         < -4, 31, -1 >,
         < -4, 31,  1 >,
         2
      }
      cylinder {
         < -4, 39, -1 >,
         < -4, 39,  1 >,
         2
      }
      cylinder {
         <  4, 31, -1 >,
         <  4, 31,  1 >,
         2
      }
      cylinder {
         <  4, 39, -1 >,
         <  4, 39,  1 >,
         2
      }
      // These are the cut-outs for the boxes next to the cross
      box {
         < -11.5, 31, -1 >,
         <  -8.0, 42,  1 >
      }
      box {
         <   8.0, 31, -1 >,
         <  11.5, 42,  1 >
      }
      // These are the cut-outs for the smaller circles
      cylinder {
         < -18, 40, -1 >,
         < -18, 40,  1 >,
         6.0
      }
      cylinder {
         <  18, 40, -1 >,
         <  18, 40,  1 >,
         6.0
      }
      texture{ GOLD1 }
   }
}

#declare window =
union {
   object {
      cutframe
   }
   union {
      // This is the cut-out for the large circle
      // cylinder {
      //    < 0, 65, -0.25 >,
      //    < 0, 65,  0.25 >,
      //    24.0
      //    texture{ ORANGE_GLASS }
      // }
      // These are the cut-outs for the upper section
      merge {
         box {
            < -4, 43, -0.25 >,
            <  4, 81,  0.25 >
         }
         cylinder {
            <  0, 85, -0.25 >,
            <  0, 85,  0.25 >,
            4.0
         }
         texture{ RED_GLASS }
      }
      merge {
         box {
            < -12, 43, -0.25 >,
            <  -5, 78,  0.25 >
         }
         cylinder {
            <  -8.5, 82, -0.25 >,
            <  -8.5, 82,  0.25 >,
            4.0
         }
         texture{ ORANGE_GLASS }
      }
      merge {
         box {
            <  5, 43, -0.25 >,
            < 12, 78,  0.25 >
         }
         cylinder {
            <  8.5, 82, -0.25 >,
            <  8.5, 82,  0.25 >,
            4.0
         }
         texture{ ORANGE_GLASS }
      }
      merge {
         box {
            < -21, 46, -0.25 >,
            < -13, 71,  0.25 >
         }
         cylinder {
            < -17, 75, -0.25 >,
            < -17, 75,  0.25 >,
            4.0
         }
         texture{ YELLOW_GLASS }
      }
      merge {
         box {
            < 13, 46, -0.25 >,
            < 21, 71,  0.25 >
         }
         cylinder {
            < 17, 75, -0.25 >,
            < 17, 75,  0.25 >,
            4.0
         }
         texture{ YELLOW_GLASS }
      }
      merge {
         box {
            < -24, 46, -0.25 >,
            < -22, 66,  0.25 >
         }
         cylinder {
            < -23, 67, -0.25 >,
            < -23, 67,  0.25 >,
            1.0
         }
         texture{ GREEN_GLASS }
      }
      merge {
         box {
            < 22, 46, -0.25 >,
            < 24, 66,  0.25 >
         }
         cylinder {
            < 23, 67, -0.25 >,
            < 23, 67,  0.25 >,
            1.0
         }
         texture{ GREEN_GLASS }
      }
   
      // This is the cut-out for the cross
      box {
         < -1, 21, -0.25 >,
         <  1, 42,  0.25 >
         texture{ PURPLE_GLASS }
      }
      box {
         < -7, 34, -0.25 >,
         <  7, 36,  0.25 >
         texture{ PURPLE_GLASS }
      }
      // This is the cut-out for the corner box
      box {
         < -24, 21, -0.25 >,
         < -17, 32,  0.25 >
         texture{ RED_GLASS }
      }
      box {
         <  17, 21, -0.25 >,
         <  24, 32,  0.25 >
         texture{ RED_GLASS }
      }
      // This is the cut-out for the middle lower box
      box {
         < -16, 21, -0.25 >,
         < -10, 30,  0.25 >
         texture{ ORANGE_GLASS }
      }
      box {
         <  10, 21, -0.25 >,
         <  16, 30,  0.25 >
         texture{ ORANGE_GLASS }
      }
      // This is the cut-out for the inside lower box
      box {
         < -9, 21, -0.25 >,
         < -2, 28,  0.25 >
         texture{ YELLOW_GLASS }
      }
      box {
         <  2, 21, -0.25 >,
         <  9, 28,  0.25 >
         texture{ YELLOW_GLASS }
      }
      // This is the cut-out for the four circles around the cross
      cylinder {
         < -4, 31, -0.25 >,
         < -4, 31,  0.25 >,
         2
         texture{ AQUA_GLASS }
      }
      cylinder {
         < -4, 39, -0.25 >,
         < -4, 39,  0.25 >,
         2
         texture{ YELLOW_GLASS }
      }
      cylinder {
         <  4, 31, -0.25 >,
         <  4, 31,  0.25 >,
         2
         texture{ YELLOW_GLASS }
      }
      cylinder {
         <  4, 39, -0.25 >,
         <  4, 39,  0.25 >,
         2
         texture{ AQUA_GLASS }
      }
      // These are the cut-outs for the boxes next to the cross
      box {
         < -11.5, 31, -0.25 >,
         <  -8.0, 42,  0.25 >
         texture{ GREEN_GLASS }
      }
      box {
         <   8.0, 31, -0.25 >,
         <  11.5, 42,  0.25 >
         texture{ GREEN_GLASS }
      }
      // These are the cut-outs for the smaller circles
      cylinder {
         < -18, 40, -0.25 >,
         < -18, 40,  0.25 >,
         6.0
         texture{ YELLOW_GLASS }
      }
      cylinder {
         <  18, 40, -0.25 >,
         <  18, 40,  0.25 >,
         6.0
         texture{ YELLOW_GLASS }
      }
   }
}
