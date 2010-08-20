// main.pov
//
// My entry in the Jan/Feb 1998 Internet Raytracing Competition
//
// Written by: Henry Wagner (povray@henrywagner.org)

#version 3.5;
global_settings { assumed_gamma 2.2 }

#include "main.inc" // Contains all the .inc files

background { Black }

// light_source { < 1000, 1000, -1000 > color red 1 green 1 blue 0.705882 atmosphere off }
light_source {
    < -1000, 1000, -1000 >
    color red .4 green .4 blue 0.1705
    // atmosphere off
}

/*
light_source { 
  < 220, 90, 0 > color red 1 green 1 blue 1
  spotlight
  point_at < 33.5, 30, 140 >
  radius 1.5
  falloff 2.5
  tightness 2
  atmospheric_attenuation on
}

light_source { 
  < -220, 90, 0 > color red 1 green 1 blue 1
  spotlight
  point_at < 31.5, 30, 140 >
  radius 1.5
  falloff 2.5
  tightness 2
  atmospheric_attenuation on
}
*/

camera {
   // Dynamic
//   location < C_X1, C_Y1, C_Z1 >
//   right < 16/9, 0, 0 >
//   look_at < 0, 70, 190 >
   // B stage
  location < 40, 5.8, 85 >
  right < 4/3, 0, 0 >
  look_at < 0, 40, 190 >
   // Air
//   location < 40, 450, 85 >
//   right < 16/9, 0, 0 >
//   look_at < 0, 20, 10 >
   // 300 level
//   location < 1, 95, -230 >
//   right < 16/9, 0, 0 >
//   look_at < 0, 20, 190 >
  // Mid field
//   location < 1, 5, 40 >
//   right < 16/9, 0, 0 >
//   look_at < 0, 70, 190 >
}
