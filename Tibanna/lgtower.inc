// lgtower.inc
//
// This file contains the POV objects that make up the light towers.
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)
// Started: 12/15/1996

#version unofficial megapov 1.1;

#declare RsA = seed(574647);

#declare Light_Pole = union {
   cylinder {
      < 0, -90, 0 >,
      < 25, -90, 0 >,
      2.0
      texture { Main_Metal }
   }                                                       
   light_source {
      < 25, -90, 0 >
	  color rgb 0.045*< rand(RsA), rand(RsA), rand(RsA)>
      glow { size rand(RsA)*0.5 type int(rand(RsA))}
      fade_distance 10 fade_power 5
   }
}
   
#declare Light_Tower = union {
   cylinder {
      < 0, 0, 0 >,
      < 0, -30, 0 >,
      20.0
   }
   cylinder {
      < 0, -30, 0 >,
      < 0, -35, 0 >,
      16.0
   }
   cylinder {
      < 0, -35, 0 >,
      < 0, -45, 0 >,
      20.0
   }
   cone {
      < 0, -45, 0 >, 20.0
      < 0, -55, 0 >, 15.0
   }
   cylinder {
      < 0, -55, 0 >,
      < 0, -65, 0 >,
      10.0
   }
   cylinder {
      < 0, -65, 0 >,
      < 0, -73, 0 >,
      20.0
   }
   cone {
      < 0, -73, 0 >, 20.0
      < 0, -80, 0 >, 5.0
   }
   cylinder {
      < 0, -80, 0 >,
      < 0, -100, 0 >,
      5.0
   }
   object { Light_Pole }
   object {
      Light_Pole
      rotate < 0, 45, 0 >
   }
   object {
      Light_Pole
      rotate < 0, 90, 0 >
   }
   object {
      Light_Pole
      rotate < 0, 135, 0 >
   }
   object {
      Light_Pole
      rotate < 0, 180, 0 >
   }
   object {
      Light_Pole
      rotate < 0, 225, 0 >
   }
   object {
      Light_Pole
      rotate < 0, 270, 0 >
   }
   object {
      Light_Pole
      rotate < 0, 315, 0 >
   }
   cone {
      < 0, -100, 0 >, 5.0
      < 0, -130, 0 >, 0.0
   }
   texture { Main_Metal }
}
