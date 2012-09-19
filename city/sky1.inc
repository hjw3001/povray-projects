// sky1.inc

#include "skies.inc"

#declare New_Sky = texture {
    pigment {
        wrinkles
        turbulence 0.2
        omega 0.707
        octaves 5
        color_map {
            [0.0 color Black]
//            [0.2 color SkyBlue ]
//            [0.8 color SlateBlue * 0.25]
            [1.0 color NewMidnightBlue]
        }
        translate 0.15*y
    }
}
// texture { T_Cloud1 }

// Dark cloudy sky
/*
sky_sphere {
    pigment {
        wrinkles
        turbulence 0.2
        omega 0.707
        octaves 5
        color_map {
            [0.0 color Black]
//            [0.2 color SkyBlue ]
//            [0.8 color SlateBlue * 0.25]
            [1.0 color NewMidnightBlue]
        }
        translate 0.15*y
      // scale <0.5, 0.2, 1000>
      scale < 500, 0.2, 1000 >
   }
   pigment { P_Cloud1 }
}
*/
sky_sphere {
    pigment { Black }
    pigment {
        bozo
        turbulence 1.5
        octaves 10
        omega .5
        lambda 2.5
        color_map {
            [0.0, 0.5 color rgbf<.75, .75, .75, 0>
                      color rgbf<.9, .9, .9, .9> ]
            [0.5, 0.7 color rgbf<.9, .9, .9, .9>
                      color rgbf<1, 1, 1, 1> ]
            [0.7, 1.0 color rgbf<1, 1, 1, 1>
                      color rgbf<1, 1, 1, 1> ]
        }
    scale <1, 0.3, 10>
    }
    pigment {
        bozo
        turbulence 0.6
        octaves 10
        omega .5
        lambda 2.5
        color_map {
            [0.0, 0.4 color rgbf<.75, .75, .75, 0>
                      color rgbf<.9, .9, .9, .9> ]
            [0.4, 0.7 color rgbf<.9, .9, .9, .9>
                      color rgbf<1, 1, 1, 1> ]
            [0.7, 1.0 color rgbf<1, 1, 1, 1>
                      color rgbf<1, 1, 1, 1> ]
        }
    scale <1, 0.3, 10>
    }
/*
    pigment {
        bozo
        turbulence 0.8
        octaves 10
        omega .5
        lambda 2.5
        color_map {
            [0.0, 0.4 color rgbf<.75, .75, .75, 0>
                      color rgbf<.9, .9, .9, .9> ]
            [0.4, 0.6 color rgbf<.9, .9, .9, .9>
                      color rgbf<1, 1, 1, 1> ]
            [0.6, 1.0 color rgbf<1, 1, 1, 1>
                      color rgbf<1, 1, 1, 1> ]
        }
    scale <1, 0.3, 10>
    }
*/
}
