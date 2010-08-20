// SpinLght.inc
//
// POV definition for spining box light.
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare SpinLightCycleSpeed = 100;

#if (clock_on = 1)
    #declare slFN = frame_number;
#else
    #declare slFN = 25;
#end

#declare spin_angle = (mod(slFN,SpinLightCycleSpeed)/SpinLightCycleSpeed) * 360;

#declare Box_Texture = texture {
   pigment { color rgb 0.1 }
   finish { metallic }
}

#declare Spin_Light_Base = difference {
   box {
      < -1, 0, -1 >,
      <  1, 5,  1 >
   }
   cylinder {
      < 0, 1, 0 >,
      < 0, 6, 0 >,
      0.8
   }
   texture { Box_Texture }
}

#declare Spin_Section = union {
   difference {
      box {
         < -1, -1.0, -1 >,
         <  1, -0.9,  1 >
      }
      cylinder {
         < 0, -1.1, 0 >,
         < 0, -0.8, 0 >,
         0.8
      }
      texture { Box_Texture }
   }
   difference {
      box {
         < 0.9, -0.9, -1 >,
         < 1.0,  1.0,  1 >
      }
      cylinder {
         < 0.8, 0.0, 0.0 >,
         < 1.1, 0.0, 0.0 >,
         0.8
      }
      texture { Box_Texture }
   }
   union {
      triangle { < -1, -0.9, -1 >, <  0.9, -0.9, -1 >, < 0.9, 1.0, -1 > }
      triangle { < -1, -0.9,  1 >, <  0.9, -0.9,  1 >, < 0.9, 1.0,  1 > }
      triangle { < -1, -0.9, -1 >, < -1.0, -0.9,  1 >, < 0.9, 1.0,  1 > }
      triangle { < -1, -0.9, -1 >, <  0.9,  1.0,  1 >, < 0.9, 1.0, -1 > }

      texture { Box_Texture }
   }

   // The Mirror
   /*
   union {
      triangle { < -0.9, -0.9, -0.99 >, < -0.9, -0.9, 0.99 >, < 0.9, 0.9,  0.99 > }
      triangle { < -0.9, -0.9, -0.99 >, <  0.9,  0.9, 0.99 >, < 0.9, 0.9, -0.99 > }

      texture {
         pigment { color rgb <0.578, 0.422, 0.195> }
         finish { Mirror }
      }
   }
   */
}

#declare Spin_Section_w_Light = union {
   object {
      Spin_Section
      rotate < 0, 0, -90 >
   }
   object {
      light_source {
         < 0, -0.1, 0 >
         color White+Gold * 0.25
         spotlight
         point_at < 0, -10, 0 >
         radius 10
         falloff 3
         tightness 2
         media_attenuation on
      }
   }
   rotate < (spin_angle*1.5), 0, 0 >
}

#declare Spin_Section_Together = union {
   object { Spin_Section }
   object {
      Spin_Section_w_Light
      translate < 2, 0, 0 >
   }
}

#declare Spin_Light = union {
   object { Spin_Light_Base }

   object {
      Spin_Section_Together
      rotate < 0, spin_angle, 0 >
      translate < 0, 6, 0 >
   }

}

// EOF
