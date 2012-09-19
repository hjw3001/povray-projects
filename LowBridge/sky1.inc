// sky1.inc

#include "skies.inc"

fog { color rgb < 0.7, 0.9, 1 > distance 60000 }

sphere {
   < 0, 0, 0 >, 60000
   hollow
   texture {
      pigment { color NewMidnightBlue }
      finish {
         ambient 1.0
         diffuse 0.0
      }
   }
   scale < 2, 0.2, 2 >
}

// The clouds
sphere {
   < 0, 0, 0 >, 59990
   no_shadow
   hollow
   texture { 
      T_Cloud2
      scale 7500
   }
   scale < 2, 0.2, 2 >
}
/*
light_source { <-300, 300, -1000> color red 0.75 green 0.5 blue 0.3 }
light_source { <-300, 210, 500>   color red 0.25 green 0.1 blue 0.0 }
*/