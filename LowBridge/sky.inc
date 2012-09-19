// sky.inc

// Dark cloudy sky
sky_sphere {
    pigment {
        wrinkles
        turbulence 0.3
        omega 0.707
        octaves 5
        color_map {
            [0.0 color DustyRose * 2.5]
            [0.2 color Orange ]
            [0.8 color SlateBlue * 0.25]
            [1.0 color SkyBlue]
        }
        scale <0.5, 0.2, 1000>
    }
}