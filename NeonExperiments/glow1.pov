#version unofficial MegaPov 1.1;

#declare Brightness = 54;

#default {
  texture {
    pigment { color rgb 1.5 }
    finish { diffuse 1 ambient 0.0 }
  }
}


camera {
  location    <-92, -12, -35>
  direction   z*1.5
  right       1.33333*x
  look_at     <-73, 0.0, 0>
}



#macro Glow(Color)
  media {
    emission 1
    density {
      cylindrical
      poly_wave 5
      density_map {
        [0 rgb 0]
        [1 rgb Color]
      }
    }
    method 3
  }
#end


#declare ls = union {

  cylinder {
    <0, 0, 0> <0, 10, 0> 1
    hollow on
    pigment { rgbt 1 }
    interior { Glow(<1.0, 1, 1>*Brightness) }
    no_image
  }
  cylinder {
    <0, 0, 0> <0, 10, 0> 1
    hollow on
    pigment { rgbt 1 }
    interior { Glow(<0.1, 0.2, 1.0>*Brightness) }
    no_radiosity
  }
  rotate <-90, 0, 0>
  translate <-70, 24, 0>
}

object { ls rotate <0, -20, 0> }
object { ls rotate <0, 0, 0> }
object { ls rotate <0, 20, 0> }
object { ls rotate <0, 40, 0> }
object { ls rotate <0, 60, 0> }
object { ls rotate <0, 80, 0> }
object { ls rotate <0, 100, 0> }
