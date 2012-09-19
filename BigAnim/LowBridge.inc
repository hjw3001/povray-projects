#version unofficial megapov 1.1;

#declare usePhotons = false;

#declare Bridge_Texture = texture {
   pigment { color red 0.960784 green 1.0 blue 0.908235 }
   finish {
      crand 0.02
      diffuse 0.5
      ambient 0.2
      specular 0.5
      roughness 0.25
   }
}

#declare Rail_Texture = texture {
   pigment { color HuntersGreen }
   finish {
      diffuse 0.5
      ambient 0.2
      specular 0.5
      roughness 0.15
   }
}

#declare Small_Post = union {
   box {
      < -0.5, 0, -0.5 >,
      <  0.5, 3,  0.5 >
   }
   triangle { < -0.5, 3, -0.5 >, < 0.5, 3,   -0.5 >, <  0.3, 3.2, -0.3 > }
   triangle { < -0.5, 3, -0.5 >, < 0.3, 3.2, -0.3 >, < -0.3, 3.2, -0.3 > }

   triangle { <  0.5, 3, -0.5 >, < 0.5, 3,    0.5 >, <  0.3, 3.2,  0.3 > }
   triangle { <  0.5, 3, -0.5 >, < 0.3, 3.2,  0.3 >, <  0.3, 3.2, -0.3 > }

   triangle { < -0.5, 3,  0.5 >, < 0.5, 3,    0.5 >, <  0.3, 3.2,  0.3 > }
   triangle { < -0.5, 3,  0.5 >, < 0.3, 3.2,  0.3 >, < -0.3, 3.2,  0.3 > }

   triangle { < -0.5, 3, -0.5 >, < 0.5, 3,    0.5 >, <  0.3, 3.2,  0.3 > }
   triangle { <  0.5, 3, -0.5 >, < 0.3, 3.2,  0.3 >, <  0.3, 3.2, -0.3 > }

   triangle { < -0.3, 3.2, -0.3 >, < 0.3, 3.2, -0.3 >, <  0.3, 3.2, 0.3 > }
   triangle { < -0.3, 3.2, -0.3 >, < 0.3, 3.2,  0.3 >, < -0.3, 3.2, 0.3 > }
   
   photons{collect off}
}

#include "posts.inc"

#declare Z_Dist = 10;

#declare Small_Support = object {
   box {
      < -0.5, 0, -3 >,
      <  0.5, 15, 3 >
   }
   photons { target reflection on refraction off }
}

#declare Big_Support = union {
   box {
      < -1.25, 0, -3 >,
      <  1.25, 15, 3 >
   }
   box {
      < -1.25, 0, -3.6 >,
      <  1.25, 5, -3.0 >
   }
   box {
      < -1, 5, -3.3 >,
      <  1, 8, -3.0 >
   }
   box {
      < -0.5, 8, -3.2 >,
      <  0.5, 10, 3.0 >
   }
   photons { target reflection on refraction off }
}

#declare Arch_Section_1 = union {
   object {
      Small_Support
      translate < -30, 0, 0 >
   }
   object {
      Small_Support
      translate < -20, 0, 0 >
   }
   object {
      Small_Support
      translate < -10, 0, 0 >
   }
   object { Small_Support }
   object {
      Small_Support
      translate < 10, 0, 0 >
   }
   object {
      Small_Support
      translate < 20, 0, 0 >
   }
   object {
      Small_Support
      translate < 30, 0, 0 >
   }
   photons { target reflection on refraction off }
}

#declare Arch_Section_2 = difference {
   object { Arch_Section_1 }
   cylinder {
      < 0, -50, -4 >,
      < 0, -50,  4 >,
      64.5
   }
   photons { target reflection on refraction off }
}

#declare Arch_Section_4 = difference {
   difference {
      cylinder {
         < 0, -50, -3.5 >,
         < 0, -50,  3.5 >,
         64.5
      }
      cylinder {
         < 0, -50, -3.6 >,
         < 0, -50,  3.6 >,
         63.5
      }
   }
   plane { < 0, 1, 0 >, 0 }
   texture { Bridge_Texture }
}

#declare Arch_Section = union {
   object { Arch_Section_2 }
   object { Arch_Section_4 }
}

#declare LowBridge = union {
   object {
      Big_Support
      translate < -200, 0, -Z_Dist >
   }
   object {
      Arch_Section
      translate < -160, 0, -Z_Dist >
   }
   object {
      Big_Support
      translate < -120, 0, -Z_Dist >
   }
   object {
      Arch_Section
      translate < -80, 0, -Z_Dist >
   }
   object {
      Big_Support
      translate < -40, 0, -Z_Dist >
   }
   object {
      Arch_Section
      translate < 0, 0, -Z_Dist >
   }
   object {
      Big_Support
      translate < 40, 0, -Z_Dist >
   }
   object {
      Arch_Section
      translate < 80, 0, -Z_Dist >
   }
   object {
      Big_Support
      translate < 120, 0, -Z_Dist >
   }
   object {
      Arch_Section
      translate < 160, 0, -Z_Dist >
   }

   object {
      Big_Support
      rotate < 0, 180, 0 >
      translate < -200, 0, Z_Dist >
   }
   object {
      Arch_Section
      translate < -160, 0, Z_Dist >
   }
   object {
      Big_Support
      rotate < 0, 180, 0 >
      translate < -120, 0, Z_Dist >
   }
   object {
      Arch_Section
      translate < -80, 0, Z_Dist >
   }
   object {
      Big_Support
      rotate < 0, 180, 0 >
      translate < -40, 0, Z_Dist >
   }
   object {
      Arch_Section
      translate < 0, 0, Z_Dist >
   }
   object {
      Big_Support
      rotate < 0, 180, 0 >
      translate < 40, 0, Z_Dist >
   }
   object {
      Arch_Section
      translate < 80, 0, Z_Dist >
   }
   object {
      Big_Support
      rotate < 0, 180, 0 >
      translate < 120, 0, Z_Dist >
   }
   object {
      Arch_Section
      translate < 160, 0, Z_Dist >
   }
   object {
      Big_Support
      rotate < 0, 180, 0 >
      translate < 200, 0, Z_Dist >
   }
   box {
      < -220, 15.0, -14 >,
      <  220, 16.5,  14 >
   }
   triangle { < -220, 16.5, -14 >, < 220, 16.5, -14 >, <  220, 19, -20 > }
   triangle { < -220, 16.5, -14 >, < 220, 19.0, -20 >, < -220, 19, -20 > }
   box {
      < -220, 19, -20 >,
      <  220, 19.5, 20 >
   }
   box {
      < -220, 19.5, -20 >,
      <  220, 19.8, -17 >
   }
   box {
      < -220, 19.5,  17 >,
      <  220, 19.8,  20 >
   }
   object { Posts }
   object {
      Posts
      translate < 0, 0, 37 >
   }
   /*
   box {
      < -600, 19.0, -20 >,
      < -220, 19.5,  20 >
   }
   box {
      < -250, 19.0, 20 >,
      < -230, 19.5, 500 >
   }
   */
   object { Lamps }
    
   object { Railing }
    
   object {
      Railing
      translate < 0, 0, 37 >
   }

   texture { Bridge_Texture }
}

// This is the main building
/*
union {
   box {
      < -600, 19.5,  30 >,
      < -260, 22.5, 200 >
   }
   box {
      < -400, 19.5, 20 >,
      < -380, 20.0, 30 >
   }
   box {
      < -400, 20.0, 22 >,
      < -380, 20.5, 30 >
   }
   box {
      < -400, 20.5, 24 >,
      < -380, 21.0, 30 >
   }
   box {
      < -400, 21.0, 26 >,
      < -380, 21.5, 30 >
   }
   box {
      < -400, 21.5, 28 >,
      < -380, 22.0, 30 >
   }
   texture { Bridge_Texture }
}
*/
/*
#if (usePhotons = true)
box {
    < -220, -1, -50 >,
    <  220,  0,  50 >
    photons { target reflection on refraction off }
    material {
       M_Watx
    }
    hollow on
}
#end
*/
// light_source { < 1000,  400, -1000 > color White media_interaction off }
/*
light_source { < 500,  400, -1000 > color White }
light_source { < 0,  400, -1000 > color White }
light_source { < -500,  400, -1000 > color White }
light_source { < -1000,  400, -1000 > color White }
*/
/*
light_source {
   < 0, 500, -1000 >
   color White
   area_light < 2000, 0, 0 >, < 0, 500, 0 >, 5, 5
   adaptive 1
   jitter
}
*/
// Use this for the ground to block the remaining water

/*
#declare T_Grass=
texture {
  pigment { color rgb <0.5, 1.15, 0.3> }
  finish {
    specular 0.1
    diffuse 0.3
    brilliance 1.6
    ambient <0.8, 0.9, 1.4>*0.03
  }
  normal {
    granite 0.5
    accuracy 0.01
    scale 0.12
  }
}

union {
   // This box supports the trees
   box {
      < -250, -5, -1000 >,
      < -190,  1,  5000 >
   }
   // The triangles form a hill to block the water beyond
   triangle { < -200, -5, -1000 >, < -200, -5, 5000 >, < -220, 19,  5000 > }
   triangle { < -200, -5, -1000 >, < -220, 19, 5000 >, < -220, 19, -1000 > }

   box {
      < -10000, 0, -5000 >,
      <   -220, 19, 5000 >
   }
   texture { T_Grass }
}
*/
/*
  camera 180 30 -80    0 15 0
  camera 180  3 -80   80 15 0
  camera 180 25 -10 -220 24 0
*/

#declare CameraSource = function {
   spline {
       natural_spline
       0.0, < 170, 3, 30 >
       0.25, < 180,  9, -80 >
       0.5, < 180, 30, -80 >
       0.8, < 180, 25, -10 >
       1.0, < 123, 35,  22 >
   }
}

#declare CameraDest = function {
   spline {
       natural_spline
       0.0, < 0, 20, 0 >
       0.25, <   80, 15, 0 >
       0.5, <    0, 15, 0 >
       0.8, <  60, 24, 0 >
       1.0, < 120, 30.3,  20 >
   }
}

/*
camera {
   // The original location when I got back to the scene
   // location < 180, 3, -80 >
   location CameraSource(FN/FF)
   
   // location < 180, 25, -10 >
   // location <  1, 3, -50 >
   up < 0, 1, 0 >
   right < 4/3, 0, 0 >
   
   // The original destination when I got back to the scene
   // look_at  <  80, 15,   0 >
   look_at CameraDest(FN/FF)
   
   // look_at < -220, 24, 0 >
   // location < C_X1, C_Y1, C_Z1 >
   // look_at  < C_X2, C_Y2, C_Z2 >
}
*/
// The heightfield object is in the X-Z plane, centered on the origin, 
// and extends +/- 0.5 units in the X and Z directions
/*
object {
   height_field {tga "ridge1.tga" }
   hollow
   scale < 1000, 400, 1000 >      // reduce height
   translate <-500, -100, -500>
   texture { 
      pigment {color White} 
      finish {phong 0.1 ambient 0.2} 
   }
}

object {
   height_field {tga "ridgring.tga" }
   hollow
   scale < 4000, 2000, 4000 >      // reduce height
   translate <-2000, -150, -2000>
   texture { 
      pigment {color White} 
      finish {phong 0.1 ambient 0.2} 
   }
}
*/