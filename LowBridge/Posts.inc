// posts.inc

#declare Small_Rail = box {
   < -0.02, 0, -0.2 >,
   <  0.02, 1.8,  0.2 >
}

#declare Posts = union {
   object {
      Small_Post
      translate < -10, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -20, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -30, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -40, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -50, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -60, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -70, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -80, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -90, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -100, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -110, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -120, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -130, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -140, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -150, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -160, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -170, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -180, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -190, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -200, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < -210, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 0, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 10, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 20, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 30, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 40, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 50, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 60, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 70, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 80, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 90, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 100, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 110, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 120, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 130, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 140, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 150, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 160, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 170, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 180, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 190, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 200, 19.5, -18.5 >
   }
   object {
      Small_Post
      translate < 210, 19.5, -18.5 >
   }
}

#declare Ball_Base = difference {
   difference {
      sphere { < 0, 0, 0 >, 0.6 }
      sphere { < 0, 0, 0 >, 0.5 }
   }
   plane { < 0, 1, 0 > 0.4 }
}

#declare Lamp_Arm = union {
   cylinder {
      < 0, 0, 0 >,
      < 2, 0, 0 >,
      0.25
   }
   sphere { < 2, 0, 0 >, 0.25 }
   cylinder {
      < 2, 0, 0 >,
      < 2, 2, 0 >
      0.25
   }
   object {
      Ball_Base
      rotate < 180, 0, 0 >
      translate < 2, 2.5, 0 >
   }
   sphere {
      < 2, 2.5, 0 >, 0.1
      texture {
         pigment { color White }
         finish {
            diffuse 0.0
            ambient 1.0
         }
      }
   }
   sphere {
      < 2, 2.5, 0 >, 0.59
      texture {
         NBglass
      }
   }
   texture { T_Brass_2C }
}

#declare Lamp = union {
   cylinder {
      < 0, 0, 0 >,
      < 0, 0.5, 0 >,
      1.0
      texture { Bridge_Texture }
   }
   cone {
      < 0,  0.5, 0 >, 0.6
      < 0, 10.0, 0 >, 0.5
      texture { T_Brass_2C }
   }
   sphere {
      < 0, 10, 0 >, 0.6
      texture { T_Brass_2C }
   }
   cylinder {
      < 0, 10, 0 >,
      < 0, 13, 0 >,
      0.25
      texture { T_Brass_2C }
   }
   object {
      Ball_Base
      rotate < 180, 0, 0 >
      translate < 0, 13.5, 0 >
      texture { T_Brass_2C }
   }
   sphere {
      < 0, 13.5, 0 >, 0.1
      texture {
         pigment { color White }
         finish {
            diffuse 0.0
            ambient 1.0
         }
      }
   }
   sphere {
      < 0, 13.5, 0 >, 0.59
      texture {
         NBglass
      }
   }
   object {
      Lamp_Arm
      translate < 0, 10, 0 >
   }
   object {
      Lamp_Arm
      rotate < 0, 120, 0 >
      translate < 0, 10, 0 >
   }
   object {
      Lamp_Arm
      rotate < 0, 240, 0 >
      translate < 0, 10, 0 >
   }
}

#declare Lamps = union {
   object {
      Lamp
      translate < -225, 19, 100 >
   }
   object {
      Lamp
      translate < -225, 19, 180 >
   }
   object {
      Lamp
      translate < -225, 19, 260 >
   }

   object {
      Lamp
      translate < -440, 19, -20 >
   }
   object {
      Lamp
      translate < -360, 19, -20 >
   }
   object {
      Lamp
      translate < -280, 19, -20 >
   }
   object {
      Lamp
      translate < -200, 19, -20 >
   }
   object {
      Lamp
      translate < -120, 19, -20 >
   }
   object {
      Lamp
      translate < -40, 19, -20 >
   }
   object {
      Lamp
      translate < 40, 19, -20 >
   }
   object {
      Lamp
      translate < 120, 19, -20 >
   }
   object {
      Lamp
      translate < -200, 19, 20 >
   }
   object {
      Lamp
      translate < -120, 19, 20 >
   }
   object {
      Lamp
      translate < -40, 19, 20 >
   }
   object {
      Lamp
      translate < 40, 19, 20 >
   }
   object {
      Lamp
      translate < 120, 19, 20 >
   }
}

#declare Rail_Section = union {
   object {
      Small_Rail
      translate < -4.05, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -3.6, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -3.15, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -2.7, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -2.25, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -1.8, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -1.35, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -0.9, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < -0.45, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 0, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 4.05, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 3.6, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 3.15, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 2.7, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 2.25, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 1.8, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 1.35, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 0.9, 20.2, -18.5 >
   }
   object {
      Small_Rail
      translate < 0.45, 20.2, -18.5 >
   }
}

#declare Railing = union {
   box {
      < -200, 20, -18.7 >,
      <  200, 20.2, -18.3 >
   }
   box {
     < -200, 22, -18.7 >,
     <  200, 22.2, -18.3 >
   }
   object {
      Rail_Section
      translate < 5, 0, 0 >
   }
   object {
      Rail_Section
      translate < 15, 0, 0 >
   }
   object {
      Rail_Section
      translate < 25, 0, 0 >
   }
   object {
      Rail_Section
      translate < 35, 0, 0 >
   }
   object {
      Rail_Section
      translate < 45, 0, 0 >
   }
   object {
      Rail_Section
      translate < 55, 0, 0 >
   }
   object {
      Rail_Section
      translate < 65, 0, 0 >
   }
   object {
      Rail_Section
      translate < 75, 0, 0 >
   }
   object {
      Rail_Section
      translate < 85, 0, 0 >
   }
   object {
      Rail_Section
      translate < 95, 0, 0 >
   }
   object {
      Rail_Section
      translate < 105, 0, 0 >
   }
   object {
      Rail_Section
      translate < 115, 0, 0 >
   }
   object {
      Rail_Section
      translate < 125, 0, 0 >
   }
   object {
      Rail_Section
      translate < 135, 0, 0 >
   }
   object {
      Rail_Section
      translate < 145, 0, 0 >
   }
   object {
      Rail_Section
      translate < 155, 0, 0 >
   }
   object {
      Rail_Section
      translate < 165, 0, 0 >
   }
   object {
      Rail_Section
      translate < 175, 0, 0 >
   }
   object {
      Rail_Section
      translate < 185, 0, 0 >
   }
   object {
      Rail_Section
      translate < 195, 0, 0 >
   }
   object {
      Rail_Section
      translate < -5, 0, 0 >
   }
   object {
      Rail_Section
      translate < -15, 0, 0 >
   }
   object {
      Rail_Section
      translate < -25, 0, 0 >
   }
   object {
      Rail_Section
      translate < -35, 0, 0 >
   }
   object {
      Rail_Section
      translate < -45, 0, 0 >
   }
   object {
      Rail_Section
      translate < -55, 0, 0 >
   }
   object {
      Rail_Section
      translate < -65, 0, 0 >
   }
   object {
      Rail_Section
      translate < -75, 0, 0 >
   }
   object {
      Rail_Section
      translate < -85, 0, 0 >
   }
   object {
      Rail_Section
      translate < -95, 0, 0 >
   }
   object {
      Rail_Section
      translate < -105, 0, 0 >
   }
   object {
      Rail_Section
      translate < -115, 0, 0 >
   }
   object {
      Rail_Section
      translate < -125, 0, 0 >
   }
   object {
      Rail_Section
      translate < -135, 0, 0 >
   }
   object {
      Rail_Section
      translate < -145, 0, 0 >
   }
   object {
      Rail_Section
      translate < -155, 0, 0 >
   }
   object {
      Rail_Section
      translate < -165, 0, 0 >
   }
   object {
      Rail_Section
      translate < -175, 0, 0 >
   }
   object {
      Rail_Section
      translate < -185, 0, 0 >
   }
   object {
      Rail_Section
      translate < -195, 0, 0 >
   }

   texture { Rail_Texture }
}