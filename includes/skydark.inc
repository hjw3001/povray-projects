// sky1.inc

// #include "skies.inc"

#declare SkyPower = 0.6 - ((clock * 0.6) * 4);
#if (SkyPower < 0)
    #declare SkyPower = 0;
#end

#declare T_Cloud2 =
texture {
    pigment {
        bozo
        turbulence 1.5
        octaves 10
        omega .5
        lambda 2.5
        color_map {
            [0.0, 0.5 color rgbt<.75, .75, .75, 0>
                      color rgbt<.9, .9, .9, .9> ]
            [0.5, 0.7 color rgbt<.9, .9, .9, .9>
                      color rgbt<1, 1, 1, 1> ]
            [0.7, 1.0 color rgbt<1, 1, 1, 1>
                      color rgbt<1, 1, 1, 1> ]
        }
    }

    finish {
        // ambient 0.9
        ambient SkyPower
        // diffuse 0.1
        diffuse 0.0
    }
}

fog { color rgb < 0.7, 0.9, 1 > distance 60000 }

sphere {
   < 0, 0, 0 >, 60000
   no_shadow
   hollow
   texture {
      pigment { color NewMidnightBlue }
      finish {
         ambient SkyPower
         diffuse 0.0
      }
   }
   scale < 2, 0.2, 2 >
}

// The clouds
sphere {
   < 0, 0, 0 >, 59990
   no_shadow
   hollow
   texture { 
      T_Cloud2
      scale 7500
   }
   scale < 2, 0.2, 2 >
}
