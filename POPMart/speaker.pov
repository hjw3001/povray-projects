#include "colors.inc"
#include "finish.inc"

#declare Speaker = difference {
   box {
      < -1.9, -1.9, -1.4 >,
      <  1.9,  1.9,  0 >
   }
   union {
      box {
         < -1.7, -1.7, -1.5 >,
         <  1.7,  1.7, -1.3 >
      }
      #declare xCount = -1.4;
      #while (xCount <= 1.4)
         #declare yCount = -1.4;
         #while (yCount <= 1.4)
            cylinder {
               < xCount, yCount, -1.5 >,
               < xCount, yCount, -1.25 >,
               0.125            
            }                     
            #declare yCount = yCount + 0.4;
         #end
         #declare xCount = xCount + 0.4;
      #end

   }
   texture {
      pigment { color Orange }
      finish {
         ambient 0.4
         diffuse 0.5
      }
   }
}

object { Speaker }

camera {
    location < -5, 5, -5 >
    look_at < 0, 0, 0 >
}

light_source { < 1000, 1000, -1000 > color rgb 0.6 }

light_source {
    < 0, 115, 0>
    color rgb 0.2
    media_interaction off
    shadowless
}
