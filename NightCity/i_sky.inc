// *** sky stuff

// colors
#declare moon_color=Silver/3;

// clouds texture
#declare p_clouds2 =
pigment {
    bozo
    turbulence .7
    lambda 3
    color_map {
     [0.0 color Clear]
     [0.4 color Clear]
     [0.6 color Gray60]
     [0.8 color Gray40]
     [1.0 color Clear]
    }
    scale .15
}
#declare t_clouds2=
  texture{
    pigment {
        gradient y
        pigment_map {
            [0.0 MidnightBlue]
            [0.3 p_clouds2]
            [1.0 p_clouds2]
        }
    }
    finish{ambient .1}
  }

// *** sky spheres ***
#declare skyspheres=
union{
 // clouds
 sphere {<0,0,0>,1
  hollow
  texture{t_clouds2}
  scale <240000,50000,240000>
  scale <1,1,1>
  rotate 32*y
  no_shadow
 }
 // stars
 sphere {<0,0,0>,1
  hollow
  texture{
   pigment{
    crackle
    color_map{
     [0.0 Black]
     [0.85 Black]
//     [0.9 White]
     [1.0 White]
    }
    scale .002
   }
   finish{ambient 30}
  }
  scale 260000
  no_shadow
 }
}

// *** moon :
#declare moon=
union{
 light_source{
  0 Silver*.4+MidnightBlue*.3
 }
 sphere{<0,0,0>,.5
  texture{
   pigment{
    bozo
    turbulence .8
    octaves 13
    color_map{
     [0.0 Gray*.9]
     [0.2 Gray*.9]
     [0.4 White*.9]
     [0.7 White*.9]
     [1.0 Gray*.9]
    }
    scale .3
   }
   finish{ambient .9}
  }
  hollow
  no_shadow
  scale 5000
 }
 sphere{<0,0,0>,1
  hollow
  no_shadow
  material{
   texture{
    pigment { color rgbt <1,1,1,1>}
    finish { ambient 0 diffuse 0 }
   }
   interior{
     media {
     emission 0.0005
     intervals 12
     samples 1, 10
     confidence 0.9999
     variance 1/1000
     density {
       spherical
       cubic_wave
       turbulence .05
       color_map {
         [0.0 Black]
         [1.0 White]
       }
       frequency 1
     }
     scale .5
    }
   }
  }
  scale 8000
 }
 translate 250000*z
}


