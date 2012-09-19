// marble.inc
//
// Written by: Henry Wagner
// Started 10/8/1995

#declare Green_Marble = texture {
   pigment {
      granite
      turbulence .25
      color_map {
         [0.0,0.5 color green 0.0 blue 0.0 red 0.0
                  color green 0.18 blue 0.05 red 0.05]
         [0.5, 1.00 color green 0.2 blue 0.1 red 0.13
                  color green 0.25 blue 0.115 red 0.155]
      }
   }
   finish {
      diffuse 0.55
      specular 0.1
   }
   normal {
      granite 0.15
      scale 0.06
   }
   /*
   finish {
      ambient .25
      diffuse .75
   }
   */
   scale .75
   rotate z*50
}

texture {
  pigment {
     marble
     turbulence .75
     color_map {
        [0.0,0.65 color rgbf <1,1,1,1> 
                  color rgbf <1,1,1,1>]
        [0.65, 1.00 color rgbf <.525,1,.5,1>
                    color rgbf <1,1,1,.75>]
     }
  }
  finish {
     ambient .5
     diffuse .5
  }
  scale .5
  rotate <50,45,0>
}

texture {
   pigment {
      marble
      turbulence .5
      color_map {
         [0.0,0.95 color rgbf <1,1,1,1> 
                   color rgbf <1,1,1,1>]
         [0.95, 1.00 color rgbf <1,1,1,1>
                     color rgbf <1,1,1,.35>]
      }
   }
   finish {
      specular .5
      roughness .01
   }
   rotate <50,35,0>
   scale .5
}

#declare Gray_Marble = texture {
   pigment {
      granite
      turbulence .75
      color_map {
         [0,.9 color Gray60 color Gray80]
         [.9,1 color Gray80 color Gray90]
      }
   }
   finish {
      ambient .75
   }
}
texture {
   pigment {
      marble
      turbulence .75
      color_map {
         [0.0,0.5 color rgbf <1,1,1,1>
                  color rgbf <1,1,1,1>]
         [0.5, 1.00 color rgbf <.8,.8,.8,1>
                    color rgbf <1,1,1,.5>]
      }
   }
   finish {
      ambient .75
   }
   scale .5
   rotate <0,-45,0>
}
texture {
   pigment {
      marble
      turbulence .5
      color_map {
         [0.0,0.95 color rgbf <1,1,1,1>
                   color rgbf <1,1,1,1>]
         [0.95, 1.00 color rgbf <.5,.5,.5,.9>
                     color rgbf <1,1,1,.5>]
      }
   }
   finish {
      specular .25
      roughness .025
   }
   scale .5
   rotate <0,-90,0>
}
