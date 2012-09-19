// TestSGI.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare ColumnOld =
   union {
      box {
         < -4, 0, -4 >,
         < 4, 2, 4 >
      }
      cylinder {
         < 0, 2, 0 >,
         < 0, 3, 0 >,
         1.5
      }
      cylinder {
         < 0, 3, 0 >,
         < 0, 20, 0 >,
         1.2
      }
      box {
         < -3, 20, -3 >,
         < 3, 21, 3 >
      }
      texture {
          White_Marble
          scale 5
      }
      finish { reflection 0.1 }
}

