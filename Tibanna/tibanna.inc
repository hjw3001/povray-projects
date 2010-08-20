// tibanna.inc
//
// A Tibanna gas mine to be placed off in the distance.
//
// Written by: Henry Wagner (henryw@panix.com)
// Started: 12/15/1996

#declare Main_Metal = texture {
   pigment { P_Copper3 }
   finish {
      ambient 0.35
      brilliance 3
      diffuse 0.3
      metallic
      specular 0.80
      roughness 1/20
      reflection 0.1
   }
}

#declare Light_Sphere = texture {
   pigment { color rgbt <1, 1, 1, 1> }
   finish {
      ambient 1
      brilliance 3
      diffuse 0
   }
}

#declare Main_Distance = 780.0;
#declare Top_Main_Distance = 120.0;

#declare Connector_Shaft = union {
   cylinder {
      < 0, 0, 0 >,
      < 0, 20, 0 >,
      14.0
   }
   cone {
      < 0, 20, 0 >, 14.0
      < 0, 30, 0 >, 10.0
   }
   cylinder {
      < 0, 30, 0 >,
      < 0, 100, 0 >,
      10.0
   }
   cone {
      < 0, 100, 0 >, 10.0
      < 0, 110, 0 >, 14.0
   }
   cylinder {
      < 0, 110, 0 >,
      < 0, 130, 0 >,
      14.0
   }
   texture { Main_Metal }
}

#declare Main_Container = union {
   cylinder {
      < -30, -30, -30 >,
      < -30,   0, -30 >,
      10.0
   }
   cylinder {
      < -30, -30, 30 >,
      < -30,   0, 30 >,
      10.0
   }
   cylinder {
      < 30, -30, -30 >,
      < 30,   0, -30 >,
      10.0
   }
   cylinder {
      < 30, -30, 30 >,
      < 30,   0, 30 >,
      10.0
   }
   cylinder {
      < 0, -30, 0 >,
      < 0,   0, 0 >,
      20.0
   }
   cylinder {
      < 0, 0, 0 >,
      < 0, 20, 0 >,
      100.0
   }
   cylinder {
      < 0, 20, 0 >,
      < 0, 26, 0 >,
      90.0
   }
   cylinder {
      < 0, 26, 0 >,
      < 0, 160, 0 >,
      100.0
   }
   sphere {
      < 0, 0, 0 >, 100.0
      scale < 1. 0.8, 1 >
      translate < 0, 160, 0 >
   }
   texture { Main_Metal }
}

#declare Top_Small_Container = union {
   cylinder {
      < -5,  0, -5 >,
      < -5, 10, -5 >,
      2.0
   }
   cylinder {
      < -5,  0,  5 >,
      < -5, 10,  5 >,
      2.0
   }
   cylinder {
      <  5,  0, -5 >,
      <  5, 10, -5 >,
      2.0
   }
   cylinder {
      <  5,  0,  5 >,
      <  5, 10,  5 >,
      2.0
   }
   cylinder {
      < 0, 10, 0 >,
      < 0, 50, 0 >,
      15.0
   }
   sphere {
      < 0, 0, 0 >,
      15.0
      scale < 1, 0.8, 1 >
      translate < 0, 50, 0 >
   }
   texture { Main_Metal }
}

#declare Top_Big_Container = union {
   cylinder {
      < -15, -15, -15 >,
      < -15,   0, -15 >,
      5.0
   }
   cylinder {
      < -15, -15, 15 >,
      < -15,   0, 15 >,
      5.0
   }
   cylinder {
      < 15, -15, -15 >,
      < 15,   0, -15 >,
      5.0
   }
   cylinder {
      < 15, -15, 15 >,
      < 15,   0, 15 >,
      5.0
   }

   cylinder {
      < 0, 0, 0 >,
      < 0, 20, 0 >,
      30.0
   }
   cylinder {
      < 0, 20, 0 >,
      < 0, 26, 0 >,
      25.0
   }
   cylinder {
      < 0, 26, 0 >,
      < 0, 120, 0 >,
      30.0
   }
   sphere {
      < 0, 0, 0 >, 30.0
      scale < 1, 0.8, 1 >
      translate < 0, 120, 0 >
   }
   texture { Main_Metal }
}

#declare Main_Container_Ring = union {
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 18, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 36, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 54, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 72, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 90, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 108, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 126, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 144, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 162, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 180, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 198, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 216, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 234, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 252, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 270, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 288, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 306, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 324, 0 >
   }
   object {
      Main_Container
      translate < Main_Distance, 0, 0 >
      rotate < 0, 342, 0 >
   }
}

#declare Top_Main_Ring = union {
   object {
      Top_Big_Container
      translate < Top_Main_Distance, 0, 0 >
   }
   object {
      Top_Big_Container
      translate < Top_Main_Distance, 0, 0 >
      rotate < 0, 60, 0 >
   }
   object {
      Top_Big_Container
      translate < Top_Main_Distance, 0, 0 >
      rotate < 0, 120, 0 >
   }
   object {
      Top_Big_Container
      translate < Top_Main_Distance, 0, 0 >
      rotate < 0, 180, 0 >
   }
   object {
      Top_Big_Container
      translate < Top_Main_Distance, 0, 0 >
      rotate < 0, 240, 0 >
   }
   object {
      Top_Big_Container
      translate < Top_Main_Distance, 0, 0 >
      rotate < 0, 300, 0 >
   }
}

#declare Small_Container = union {
   cylinder {
      < 0, -12, 0 >,
      < 0,  12, 0 >,
      5.0
   }
   sphere {
      < 0, 0, 0 >, 5.0
      scale < 1. 0.8, 1 >
      translate < 0, 12, 0 >
   }
   sphere {
      < 0, 0, 0 >, 5.0
      scale < 1. 0.8, 1 >
      translate < 0, -12, 0 >
   }
   texture { Main_Metal }
}

#declare Bot_Rod = union {
   cone {
      < 0, 0, 0 >, 15.0
      < 0, -400, 0 >, 8.0
   }
   sphere {
      < 0, 0, 0 >, 8.0
      scale < 1, 0.8, 1 >
      translate < 0, -400, 0 >
   }
   texture { Main_Metal }
}
