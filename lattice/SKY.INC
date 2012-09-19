// sky.inc
//
// This is the POV 3.0 sunset sky

// Dark cloudy sky
sky_sphere {
    pigment {
        wrinkles
        turbulence 0.3
        omega 0.707
        octaves 5
        color_map {
            [0.0 color DustyRose * 2.5]
//            [0.2 color DustyRose ]
            [0.2 color Orange ]
//            [0.8 color DarkSlateGray * 0.5]
            [0.8 color SlateBlue * 0.25]
            [1.0 color SkyBlue]
        }
        scale <0.5, 0.1, 1000>
    }
}

// The Sun's halo
#declare SunGlow =
texture {
   pigment { colour Clear }
   halo {
      linear
      max_value 1.0
      spherical_mapping
      emitting
      colour_map {
         [0.15 color rgbf <1.0, 0.0, 0.0,  0.0> ]
         [0.75 color rgbf <1.0, 1.0, 0.0,  1.0> ]
      }
      samples 10
   }
}

#declare Sun =
union {
    sphere { 0, 1
        hollow
        no_shadow
        texture { SunGlow }
        scale 0.75
        scale < 3, 3, 3 >
        // translate <0, 0.05, 0>
    }
    sphere { 0, 0.1
        no_shadow
        hollow
        pigment { Orange filter 0.5}
        finish { ambient 0.75 }
    }
    scale < 1, 0.8, 1 >
    scale 18000
    translate < 100000, -1025, 150000 >
}

object { Sun }
