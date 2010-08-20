// sky.inc
//
// Nice sky, for day time renderings.
//
// Written by: Henry Wagner

#include "skies.inc"

fog { color rgb < 0.7, 0.9, 1 > distance 6000 }

sphere {
   < 0, 0, 0 >, 6000
   hollow
   texture {
      pigment { color Black }
      finish {
         ambient 1.0
         diffuse 0.0
      }
   }
   scale < 2, 0.2, 2 >
}

// The clouds
sphere {
   < 0, 0, 0 >, 5900
   no_shadow
   hollow
   texture { 
      T_Cloud2
      scale 750
   }
   scale < 2, 0.2, 2 >
}
