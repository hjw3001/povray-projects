// This is a POV model of the Silicon Graphics logo.
//
// Written by: Henry Wagner		Started: 6/28/94

#declare sgi_logo =
union {
   cylinder {
      < 6, -6, -4 >,
      < 6,  4, -4 >,
      1.0
   }
   cylinder {
      < 4, -6, -6 >,
      < 4,  4, -6 >,
      1.0
   }
   cylinder {
      < 6, -4, 6 >,
      < 6,  4, 6 >,
      1.0
   }
   cylinder {
      < 6, 4, -4 >,
      < 6, 4,  6 >,
      1.0
   }
   sphere { < 6,  4, -4 >, 1.0 }
   sphere { < 6,  4,  6 >, 1.0 }
   sphere { < 6, -4,  6 >, 1.0 }
   cylinder {
      <  6, -4, 6 >,
      < -4, -4, 6 >,
      1.0
   }
   sphere { < -4, -4, 6 >, 1.0 }
   cylinder {
      < -4, -4, 6 >,
      < -4,  6, 6 >,
      1.0
   }
   sphere{ < -4, 6, 6 >, 1.0 }
   cylinder{
      < -4, 6, 6 >,
      <  4, 6, 6>,
      1.0
   }
   sphere{ < 4, 6, 6 >, 1.0 }
   cylinder{
      < 4, 6, 6 >,
      < 4, 6, -4 >,
      1.0
   }
   sphere{ < 4, 6, -4 >, 1.0 }
   cylinder{
      <  4, 6, -4 >,
      < -6, 6, -4 >,
      1.0
   }
   sphere{ < -6, 6, -4 >, 1.0 }
   cylinder{
      < -6, 6, -4 >,
      < -6, 6,  4 >,
      1.0
   }
   sphere{ < -6, 6, 4 >, 1.0 }
   cylinder{
      < -6,  6, 4 >,
      < -6, -4, 4 >,
      1.0
   }
   sphere{ < -6, -4, 4 >, 1.0 }
   cylinder {
      < -6, -4,  4 >,
      < -6, -4, -6 >,
      1.0
   }
   sphere { < -6, -4, -6 >, 1.0 }
   cylinder{
      < -6, -4, -6 >,
      < -6,  4, -6 >,
      1.0
   }
   sphere{ < -6, 4, -6 >, 1.0 }
   cylinder {
      < -6, 4, -6 >,
      <  4, 4, -6 >,
      1.0
   }
   sphere{ < 4, 4, -6 >, 1.0 }
   sphere{ < 4, -6, -6 >, 1.0 }
   cylinder{
      <  4, -6, -6 >,
      < -4, -6, -6 >,
      1.0
   }
   sphere{ < -4, -6, -6 >, 1.0 }
   cylinder {
      < -4, -6, -6 >,
      < -4, -6,  4 >,
      1.0
   }
   sphere{ < -4, -6, 4 >, 1.0 }
   cylinder{
      < -4, -6, 4 >,
      <  6, -6, 4 >,
      1.0
   }
   sphere{ < 6, -6, 4 >, 1.0 }
   cylinder {
      < 6, -6,  4 >,
      < 6, -6, -4 >,
      1.0
   }
   sphere{ < 6, -6, -4 >, 1.0 }
   texture { T_Gold_2B }
}
