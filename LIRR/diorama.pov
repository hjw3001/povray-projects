#include "colors.inc"
 
#declare SCALE = 87.1;

camera {
  location  <-10.0, 14.0, -32.0>
  //location < -16, 20, -2 >
  up y
  sky y
  look_at   <0.0, 0.0, 0.0>
  //look_at < -16.5,22.5,0>
  // angle 30
}

light_source {
  <2000, 3000, -2700>
  color rgb <1.0, 1.0, 1.0>
}

box {
    < -(SCALE/2), -0.25, -(SCALE/2) >,
    <  (SCALE/2),     0,  (SCALE/2) >
    pigment { color Tan }
}
