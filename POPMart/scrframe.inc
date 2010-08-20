// scrframe.inc
//
// The frame from the screen
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare Neon_Rad = 0.4;
#declare frameFront = 195;
#declare frameBack = 196;

#declare Frame_Material = texture {
   pigment { color red 1.0 green 0.3922 blue 1.0 }
   finish {
      metallic
      ambient 0.6
      diffuse 0.7
      roughness 0.001
   }
}

#declare Red_Neon = texture {
   pigment { color red 1 green 0 blue 0 }
   finish {
      ambient 1.0
      diffuse 0.0
   }
}

#declare Green_Neon = texture {
   pigment { color red 0 green 1 blue 0 }
   finish {
      ambient 1.0
      diffuse 0.0
   }
}

#declare Yellow_Neon = texture {
   pigment { color red 1 green 1 blue 0 }
   finish {
      ambient 1.0
      diffuse 0.0
   }
}

#declare Screen_Frame = union {
   // This is the size of the screen
   // triangle { < 75, 10, 200 >, < 95, 85, 200 >, < -75, 10, 200 > }
   // triangle { < -75, 10, 200 >, < 95, 85, 200 >, < -65, 75, 200 > }

   // Left Side, front face
   triangle { < -75, 10, frameFront >, < -71, 10, frameFront >, < -65, 75, frameFront > }
   triangle { < -71, 10, frameFront >, < -65, 75, frameFront >, < -61, 75, frameFront > }

   // Left Side, left face
   triangle { < -75, 10, frameFront >, < -65, 75, frameFront >, < -65, 75, frameBack > }
   triangle { < -75, 10, frameFront >, < -75, 10, frameBack >, < -65, 75, frameBack > }

   // Left Side, right face
   triangle { < -71, 10, frameFront >, < -61, 75, frameFront >, < -61, 75, frameBack > }
   triangle { < -71, 10, frameFront >, < -71, 10, frameBack >, < -61, 75, frameBack > }

   // Left Side, back face
   triangle { < -75, 10, frameBack >, < -71, 10, frameBack >, < -65, 75, frameBack > }
   triangle { < -71, 10, frameBack >, < -65, 75, frameBack >, < -61, 75, frameBack > }

   // Top, front face
   triangle { < -65, 75, frameFront >, < 95, 85, frameFront >, < -65, 70, frameFront > }
   triangle { < -65, 70, frameFront >, < 95, 85, frameFront >, <  91, 80, frameFront > }

   // Top, right face
   triangle { < 91, 80, frameFront >, < 95, 85, frameFront >, < 95, 85, frameBack > }
   triangle { < 91, 80, frameFront >, < 91, 80, frameBack >, < 95, 85, frameBack > }

   // Top, bottom face
   triangle { < -65, 70, frameFront >, < 91, 80, frameFront >, < 91, 80, frameBack > }
   triangle { < -65, 70, frameFront >, < -65, 70, frameBack >, < 91, 80, frameBack > }

   // Top, top face
   triangle { < -65, 75, frameFront >, < 95, 85, frameFront >, < 95, 85, frameBack > }
   triangle { < -65, 75, frameFront >, < -65, 75, frameBack >, < 95, 85, frameBack > }

   // Top, back face
   triangle { < -65, 75, frameBack >, < 95, 85, frameBack >, < -65, 70, frameBack > }
   triangle { < -65, 70, frameBack >, < 95, 85, frameBack >, <  91, 80, frameBack > }
}

#declare Screen_Neon = union {
   cylinder  { < -74, 10, 195 >, < -64, 74, 195 >, Neon_Rad }
   sphere { < -64, 74, 195 >, Neon_Rad }
   cylinder { < -64, 74, 195 >, < 94, 84, 195 >, Neon_Rad }
   sphere { < 94, 84, 195 >, Neon_Rad }
   cylinder  { < -72, 10, 195 >, < -62, 71, 195 >, Neon_Rad }
   sphere { < -62, 71, 195 >, Neon_Rad }
   cylinder { < -62, 71, 195 >, < 91, 81, 195 >, Neon_Rad }
   sphere { < 91, 81, 195 >, Neon_Rad }
}

object {
   Screen_Frame
   texture { Frame_Material }
}

object {
   Screen_Neon
   texture { Green_Neon }
}
