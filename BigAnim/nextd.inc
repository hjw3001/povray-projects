// This is the title screen-animation for Next Dimension graphics by Henry
// Wagner.

#include "column1.inc" // This has the definitions for the candles
#include "window.inc"  // This has the definitions for the Stained-Glass 
                       // windows 
#include "sgi.inc"
#include "nexttest.inc"

// This begins the Pantheon structure
// These are the steps up to the base
#declare PantheonSteps = union {
   box {
      < 360, 1, -80 >,
      < 362, 2, 160 >
   }
   cylinder {
      < 362, 1.9, -80 >,
      < 362, 1.9, 160 >,
      0.1
   }
   box {
      < 362, 1, -80 >,
      < 364, 4, 160 >
   }
   cylinder {
      < 364, 3.9, -80 >,
      < 364, 3.9, 160 >,
      0.1
   }
   box {
      < 364, 1, -80 >,
      < 366, 6, 160 >
   }
   cylinder {
      < 366, 5.9, -80 >,
      < 366, 5.9, 160 >,
      0.1
   }
   box {
      < 366, 1, -80 >,
      < 368, 8, 160 >
   }
   cylinder {
      < 368, 7.9, -80 >,
      < 368, 7.9, 160 >,
      0.1
   }
   box {
      < 368,  1, -80 >,
      < 370, 10, 160 >
   }
   cylinder {
      < 370, 9.9, -80 >,
      < 370, 9.9, 160 >,
      0.1
   }
   box {
      < 370,  1, -80 >,
      < 372, 12, 160 >
   }
   box {
      < 372,  1, -80 >,
      < 374, 14, 160 >
   }
   box {
      < 374,  1, -80 >,
      < 376, 16, 160 >
   }
   box {
      < 376,  1, -80 >,
      < 378, 18, 160 >
   }
   box {
      < 378,  1, -80 >,
      < 380, 20, 160 >
   }
   // These are the two sides platforms
   box {
      < 360,  1, -100 >,
      < 380, 20,  -80 >
   }
   box {
      < 360,  1, 160 >,
      < 380, 20, 180 >
   }
   // This is the main base which supports the temple
   box {
      < 380,  1, -100 >,
      < 640, 20,  180 >
   }

   texture {
      Grnt10
      scale 10
      finish { Shiny }
   }
}

#declare SGILogos = union {
    object {
       sgi_logo
       rotate< 0, 0, 45 >
       rotate< 0, 45, 0 >
       translate< 370, 30, -90 >
    }
    object {
       sgi_logo
       rotate< 0, 0, 45 >
       rotate< 0, 45, 0 >
       translate< 370, 30, 170 >
    }
}


// These are the columns that surround the temple.
// These are the columns across the front
#declare PantheonColumns = union {
    object {
       column
       translate < 390, 20, 170 >
    }
    object {
       column
       translate < 390, 20, 150 >
    }
    object {
       column
       translate < 390, 20, 130 >
    }
    object {
       column
       translate < 390, 20, 110 >
    }
    object {
       column
       translate < 390, 20,  90 >
    }
    object {
       column
       translate < 390, 20,  70 >
    }
    object {
       column
       translate < 390, 20,  10 >
    }
    object {
       column
       translate < 390, 20, -10 >
    }
    object {
       column
       translate < 390, 20, -30 >
    }
    object {
       column
       translate < 390, 20, -50 >
    }
    object {
       column
       translate < 390, 20, -70 >
    }
    object {
       column
       translate < 390, 20, -90 >
    }
    // These are the columns down the right side
    object {
       column
       translate < 410, 20, -90 >
    }
    object {
       column
       translate < 430, 20, -90 >
    }
    object {
       column
       translate < 450, 20, -90 >
    }
    object {
       column
       translate < 470, 20, -90 >
    }
    object {
       column
       translate < 490, 20, -90 >
    }
    // Leave two missing for the entrance
    object {
       column
       translate < 550, 20, -90 >
    }
    object {
       column
       translate < 570, 20, -90 >
    }
    object {
       column
       translate < 590, 20, -90 >
    }
    object {
       column
       translate < 610, 20, -90 >
    }
    object {
       column
       translate < 630, 20, -90 >
    }
    // These are the rear columns
    object {
       column
       translate < 630, 20, -70 >
    }
    object {
       column
       translate < 630, 20, -50 >
    }
    object {
       column
       translate < 630, 20, -30 >
    }
    object {
       column
       translate < 630, 20, -10 >
    }
    object {
       column
       translate < 630, 20,  10 >
    }
    object {
       column
       translate < 630, 20,  30 >
    }
    object {
       column
       translate < 630, 20,  50 >
    }
    object {
       column
       translate < 630, 20,  70 >
    }
    object {
       column
       translate < 630, 20,  90 >
    }
    object {
       column
       translate < 630, 20, 110 >
    }
    object {
       column
       translate < 630, 20, 130 >
    }
    object {
       column
       translate < 630, 20, 150 >
    }
    object {
       column
       translate < 630, 20, 170 >
    }
    // These are the side columns
    object {
       column
       translate < 610, 20, 170 >
    }
    object {
       column
       translate < 590, 20, 170 >
    }
    object {
       column
       translate < 570, 20, 170 >
    }
    object {
       column
       translate < 550, 20, 170 >
    }
    object {
       column
       translate < 530, 20, 170 >
    }
    object {
       column
       translate < 470, 20, 170 >
    }
    object {
       column
       translate < 450, 20, 170 >
    }
    object {
       column
       translate < 430, 20, 170 >
    }
    object {
       column
       translate < 410, 20, 170 >
    }
}

// This is the roof over the Pantheon
#declare PantheonRoof = difference {
   box {
      < 380, 116, -100 >,
      < 640, 120,  180 >
   }
   cylinder {
      < 510, 115, 40 >,
      < 510, 121, 40 >,
      70.0
   }
   texture { Grnt5 scale 10 }
}

// These are the candles that go on the surrounding columns
#declare PantheonCandles = union {
    object {
       candle
       rotate< 0, 90, 0 >
       translate< 384, 70, 150 >
    }
    object {
       candle
       rotate< 0, 90, 0 >
       translate< 384, 70, -70 >
    }
    object {
       candle
       translate< 430, 70, -96.8 >
    }
    object {
       candle
       translate< 610, 70, -96.8 >
    }
    object {
       candle
       rotate< 0, -90, 0 >
       translate< 636.8, 70, -70 >
    }
    object {
       candle
       rotate< 0, -90, 0 >
       translate< 636.8, 70, 150 >
    }
    object {
       candle
       rotate< 0, 180, 0 >
       translate< 610, 70, 176.8 >
    }
    object {
       candle
       rotate< 0, 180, 0 >
       translate< 410, 70, 176.8 >
    }
}
 
// These are the four walls which surround the temple
#declare PantheonWalls = union {
    difference {
       box { // This is the front wall
          < 400,  20, -80 >,
          < 401, 116, 160 >
       }
       box { // This is the main enterance
          < 399, 20, 30 >,
          < 402, 60, 50 >
       }
       texture {
          Grnt5
          scale 10
          finish { Shiny }
       }
    }
    difference {
       box { // This is the right wall
          < 401,  20, -79 >,
          < 620, 116, -80 >
          texture{
             Grnt5
             scale 10
             finish { Shiny }
          }
       }
       object {
          sub_frame
          // rotate< 0, 90, 0 >
          translate< 510, 20, -79.5 >
       }
    }
    // This places the Stained Glass Window into the scene
    object {
       window
       // rotate< 0, 90, 0 >
       translate< 510, 20, -79.5 >
    }
    
    difference {
       box { // This is the left wall
          < 401,  20, 160 >,
          < 620, 116, 159 >
          texture{ Grnt5 scale 10 }
       }
       object {
          sub_frame
          translate< 510, 20, 159.5 >
       }
    }
    object {
       window
       rotate< 0, 180, 0 >
       translate< 510, 20, 159.5 >
    }
    
    box { // This is the rear wall
          < 619,  20, -79 >,
          < 620, 116, 159 >
          texture{ Grnt5 scale 10 }
    }
}
