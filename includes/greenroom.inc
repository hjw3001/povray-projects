// whiteroom.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

/*
#default {
  texture {
    pigment {rgb 1}
    finish {
      ambient 0.0
      diffuse 0.6
      specular 0.3
    }
  }
}
*/
global_settings {
  max_trace_level 10
}

light_source {
  0*x
  color rgb 1
  area_light
  <75, 0, 0> <0, 0, 75>
  2, 2
  adaptive 4
  jitter
  translate <0, 400, 0>
  rotate <10, 55, 0>
}

box {
  <-75, 401, -75> <75, 402, 75>
  no_shadow
  texture {
    pigment {color rgb 2}
    finish {ambient 2 }
  }
  rotate <10, 55, 0>
}

/*
fog {
  fog_type   2
  distance   40
  color      rgb <1, 1, .9>
  fog_offset 0.0
  fog_alt    2
  turbulence 0.0
}


fog {
  fog_type   2
  distance   50
  color      rgb <1, .7, .7>
  fog_offset 0.0
  fog_alt    1
  turbulence 0.0
}
*/

box {
  <-1000, -1, -1000> <1000, 0, 1000>
  texture { GroundOldTexture }
}

// background { color rgb 1 }  
