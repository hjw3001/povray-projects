// lamp light color
#declare lamp_color=Gold*.7+Turquoise*.4;
// wood post
#declare wood_trunk=
union{
 intersection{
  cylinder{<0,-300,0>,<0,55,0>,5}
  plane{y,0 rotate -50*x translate <-6,55,0>}
  plane{y,0 rotate  50*x translate < 6,55,0>}
  texture{T_Wood7 rotate 90*x}
  texture{
   pigment{
    bozo
    turbulence 0.5
    color_map{
     [0.0 DarkBrown]
     [0.1 Clear]
     [1.0 Clear]
    }
    scale <10,50,10>
    scale .1
    translate -300*y
   }
  }
  texture{
   pigment{
    gradient y
    turbulence 0.05
    color_map{
     [0.0 DarkTan*.5 filter 0.3]
     [1.0 Clear]
    }
    scale 350
    translate -300*y
   }
  }
  translate 5*z
 }
 cylinder{<0,0,1>,<0,0,-1>,3 pigment{Gray30} normal{granite} translate <0,27,0>}
 cylinder{<0,0,1>,<0,0,-1>,2 texture{Glass} translate <0,27,-2>}
 cylinder{<0,0,1>,<0,0,-1>,3 pigment{Gray30} normal{granite} translate <0,37,0>}
 cylinder{<0,0,1>,<0,0,-1>,2 texture{Glass} translate <0,37,-2>}
 box{<-4,-300,1>,<4,-200,-2> texture{Chrome_Texture normal{crackle scale .2}}}
}
// lamp metal texture
#declare t_lamp=
texture{
 pigment{Copper*.5+Brown*.25}
 normal{crackle scale .2}
 finish{F_MetalB}
}
// lamp object
#declare lamp_object=
union{
  union{
   box{<-3,0,2>,<3,20,0>}
   sphere{<0,0,0>,1 scale <1,1,0.5> translate <0,2,2>}
   sphere{<0,0,0>,1 scale <1,1,0.5> translate <0,18,2>}
   texture{t_lamp}
  }
  union{
   cylinder{<0,-1,0>,<0,20,0>,2}
   intersection{
    torus{20,2 rotate 90*z}
    plane{y,0 inverse}
    plane{z,0 inverse rotate 50*x}
    translate <0,20,-20>
   }
   cylinder{<0,0,0>,<0,20,0>,1.5
    rotate -33*x translate <0,31.5,-3.5>
   }
   rotate -40*x
   translate 10*y
   texture{t_lamp}
  }
  union{
   difference{
    intersection{
     union{
      cone{<0,0,0>,10,<0,0,10>,3.5}
      intersection{
       sphere{<0,0,0>,10}
       plane{z,0}
      }
     }
     plane{y,0 inverse}
     hollow
    }
    sphere{<0,0,0>,8}
    texture{t_lamp}
    hollow
   }
   sphere{<0,0,0>,7.9
    hollow
    scale <1,0.4,1>
    texture{
     Glass2
     pigment{transmit 1}
     finish{ambient 3}
    }
   }
   hollow
   rotate 1*x
   translate <0,36,-51>
  }
}
// whole streetlamp object
#declare lamp=
union{
 // lamp components
 union{
  object{wood_trunk}
  object{lamp_object}
  translate 300*y
 }
 // light
 #if (at_nigth)
 union{
  // this is the tricky media-cone
  cone{
   <0,0,0>,0,<0,-1,0>,1
   hollow
   no_shadow
   material{
    texture{
     pigment { color rgbt <1,1,1,1>}
     finish { ambient 0 diffuse 0 }
    }
    interior{
     media {  // faked atmosphere (atmosphering scattering is too slow)
      emission 0.0015
      intervals 12
      samples 1, 10
      confidence 0.9999
      variance 1/1000
      density {
        planar
        cubic_wave
        turbulence .1
        color_map {
          [0.0 lamp_color*.01]
          [1.0 lamp_color]
        }
        frequency 1
      }
     }
    }
    translate .5*y
   }
   scale 600
   translate 10*y
  }
  // a little media for the glow
  intersection{
   sphere{<0,0,0>,1}
   plane{y,0}
   hollow
   no_shadow
   material{
    texture{
     pigment { color rgbt <1,1,1,1>}
     finish { ambient 0 diffuse 0 }
    }
    interior{
     media {
      emission 0.05
      intervals 12
      samples 1, 10
      confidence 0.9999
      variance 1/1000
      density {
        spherical
        turbulence .1
        color_map {
          [0.0 Black]
          [0.5 lamp_color*.5]
          [1.0 lamp_color*.5+White*.5]
        }
        frequency 1
      }
     }
    }
    scale .5
   }
   scale 27
  }
  // the spot light
  light_source{
   <0,5,0>
   color lamp_color
   spotlight radius 20 falloff 60 tightness 0 point_at <0,-336,0>
//   area_light <12,0,0>,<0,0,12>,4,4 jitter adaptive 1
   fade_distance 400
   fade_power 2
  }
  // faked reflected light from the floor
  light_source{
   <0,-337,0>
   color lamp_color*.25
   fade_distance 800
   fade_power 4
   shadowless
  }
  translate <0,336,-52>
 }
 #end
}
// lamp without light for the distant ones
#declare lamp2=
union{
 object{wood_trunk}
 object{lamp_object}
 translate 300*y
}
// *** LITTLE LAMP FOR THE BANNERS ***
#declare lamp_color=White*.7+Turquoise*.4;
#declare ltlamp=
union{
 object{lamp_object}
 #if (at_nigth)
 union{
  // a little media for the glow
  intersection{
   sphere{<0,0,0>,1}
   plane{y,0}
   hollow
   no_shadow
   material{
    texture{
     pigment { color rgbt <1,1,1,1>}
     finish { ambient 0 diffuse 0 }
    }
    interior{
     media {
      emission 0.05
      intervals 12
      samples 1, 10
      confidence 0.9999
      variance 1/1000
      density {
        spherical
        turbulence .1
        color_map {
          [0.0 Black]
          [1.0 lamp_color*.5]
        }
        frequency 1
      }
     }
    }
    scale .75
   }
   scale 30
  }
  // the spot light
  light_source{
   <0,5,0>
   color lamp_color*1.5
   spotlight radius 30 falloff 60 tightness 2 point_at <0,-200,50>
   fade_distance 200
   fade_power 4
  }
  translate <0,36,-52>
 }
 #end
}
