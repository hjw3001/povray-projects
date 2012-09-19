// This is an include file contain additional textures created or modified
// by Henry Wagner Graphic Designs.

#include "stones.inc"

#declare RED_GLASS = texture {
    finish { ambient 0.1
             diffuse 0.7
             phong 1.0
             phong_size 70.0
             refraction 1
             ior 1.2 }
    pigment { color Red filter 0.96 }
}


#declare BLUE_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Blue filter 0.96 }
}

#declare YELLOW_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Yellow filter 0.96 }
}

#declare AQUA_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Aquamarine filter 0.96 }
}

#declare MAROON_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Maroon filter 0.96 }
}

#declare ORANGE_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Orange filter 0.96 }
}

#declare PURPLE_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Plum filter 0.96 }
}

// Green Glass for windows.
#declare GREEN_GLASS = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            refraction 1
            ior 1.2 }
   pigment { color Green filter 0.96 }
}

#declare BLUE_ENGINE = texture {
   finish { ambient 0.1
            diffuse 0.7
            phong 1.0
            phong_size 70.0
            reflection 0.2 }
   pigment { color Blue }
}

#declare GRAY_SEMIGLOSS = texture {
    finish { ambient 0.1
             diffuse 0.7
             phong 1.0
             phong_size 70.0
             reflection 0.3 }
    pigment { color Gray40 }
}

#declare CHROME_GIFMAP = texture {
    finish { ambient 0.1
             diffuse 0.7
             brilliance 6.0
             reflection 0.6
             phong 0.8
             phong_size 120 }
    pigment { color Gray20 }
}

#declare SHINY_SILVER = texture {
   finish {
      metallic
      reflection 0.6
      brilliance 6.0
      phong 0.8
      phong_size 120
      ambient 0.1
      diffuse 0.7
   }
   pigment {
      color Gray20
   }
}

#declare BRASS_GIFMAP = texture {
    finish { metallic
             ambient 0.1
             diffuse 0.8
             brilliance 6.0
             reflection 0.4
             phong 0.8
             phong_size 120 }
    pigment { color red 0.578 green 0.422 blue 0.195 }
}

#declare GOLD = texture {
    finish { metallic
             ambient 0.1
             diffuse 0.8
             brilliance 6.0
             reflection 0.6
             phong 1.0
             phong_size 80 }
    pigment { color red 0.6 green 0.4 blue 0.2 }
}

#declare GOLD1 = texture {
    finish { metallic
             ambient 0.3
             diffuse 0.7
             brilliance 8.0
             specular 0.8
             roughness 0.1
             reflection 0.01
             phong 1.0
             phong_size 80
    }
    pigment {
       color red 0.6
       green 0.4
       blue 0.2
    }
}

#declare GOLD2 = texture {
    finish { metallic
             ambient 0.1
             diffuse 0.8
             brilliance 6.0
             reflection 0.1
             phong 1.0
             phong_size 80 }
    pigment { color red 0.6 green 0.4 blue 0.2 }
}

// Created for Henry Wagner Graphic Designs

#declare BLUE_METAL = texture {
   finish {
      metallic
      ambient 0.2
      diffuse 0.8
      brilliance 6.0
      reflection 0.1
      phong 1.0
      phong_size 80 }
   pigment { color NewMidnightBlue }
}

#declare CYAN_METALIC = texture {
    finish { metallic
             ambient 0.1
             diffuse 0.8
             brilliance 6.0
             reflection 0.6
             phong 1.0
             phong_size 80 }
    pigment { 
             agate
             color_map {
                        [ 0.0, 0.3  color blue 0.9
                                    color blue 0.8 ]
                        [ 0.3, 1.00 color blue 0.8
                                    color blue 0.4 ]
             }
    }
}

#declare WHITE_METAL = texture {
   finish { metallic
            ambient 0.1
            diffuse 0.8
            brilliance 6.0
            // reflection 0.6
            phong 1.0
            phong_size 80 }
   pigment { color White }
}

#declare BLACK_BOX = texture {
   finish { metallic
            ambient 0.1
            diffuse 0.8
            brilliance 6.0
            reflection 0.6
            phong 1.0
            phong_size 80 }
   pigment { color Black }
}

#declare CREAM_PLASTIC = texture {
    finish { ambient 0.1
             diffuse 0.7
             phong 1.0
             phong_size 70.0 }
    pigment { color Tan }
}

// Henry Wagner's JADE for 3ds files.
#declare JADE = texture {
 finish {
    reflection 0.6
    ambient 0.1
    diffuse 0.8
    brilliance 6.0
 }
 pigment
  {marble
   turbulence 1.8
   color_map
    {[0.0, 0.8   color red 0.1 green 0.6 blue 0.1
                 color red 0.0 green 0.3]
     [0.8, 1.001 color red 0.1 green 0.6 blue 0.1
                 color red 0.0 green 0.2]
    }
 }
}

// Mirror for surface.
// #declare MIRROR = texture {
//  finish 
//  {ambient 0  
//   diffuse 0 
//   reflection 1
//  }
// pigment { color Green }
// }
#declare MIRROR = texture {
 finish 
  { reflection 0.6 }
 pigment
  { marble
    turbulence 1.8
    color_map
    { [0.0, 0.8   color red 0.1 green 0.6 blue 0.1
                  color red 0.0 green 0.3]
      [0.8, 1.001 color red 0.1 green 0.6 blue 0.1
                  color red 0.0 green 0.2]
    }
 }
}

#declare GREEN_METAL = texture {
 finish
  {metallic
   ambient 0.2
   diffuse 0.7
   brilliance 6
   reflection 0.25
   phong 0.75
   phong_size 80
  }
 pigment
  { color red 0.8 green 1 blue 0.95 }
}

// Beautiful military brass texture!
#declare WARBIRD_ENGINE = texture {
   pigment { color red 0.70  green 0.56  blue 0.37 }
   finish {
       ambient 0.35
       diffuse 1.00
       brilliance 15
       phong 0.41
       phong_size 5
   }
}

#declare BLUE_AGATE = 
 pigment 
  {agate
   color_map 
    {[0.0, 0.5   color red 0.30 green 0.30 blue 0.50
                 color red 0.30 green 0.30 blue 0.50]
     [0.5, 0.55  color red 0.30 green 0.30 blue 0.50
                 color red 0.20 green 0.20 blue 0.30]
     [0.55, 0.6  color red 0.20 green 0.20 blue 0.30
                 color red 0.25 green 0.25 blue 0.35]
     [0.6, 0.7   color red 0.25 green 0.25 blue 0.35
                 color red 0.15 green 0.15 blue 0.26]
     [0.7, 0.8   color red 0.15 green 0.15 blue 0.26
                 color red 0.10 green 0.10 blue 0.20]
     [0.8, 0.9   color red 0.10 green 0.10 blue 0.20
                 color red 0.30 green 0.30 blue 0.50]
     [0.9, 1.001 color red 0.30 green 0.30 blue 0.50
                 color red 0.10 green 0.10 blue 0.20]
    }
  }

// Beautiful military brass texture!
#declare NEW_BRASS = texture {
   pigment { color red 0.70  green 0.56  blue 0.37 }
   finish {
       ambient 0.35
       diffuse 1.00
       brilliance 15
       phong 0.41
       phong_size 5
   }
}

// A couple highly reflective metal textures.
#declare POLISHED_CHROME = texture {
    pigment { Gray20 }
    finish {
        ambient 0.1
        diffuse 0.7
        brilliance 6.0
        reflection 0.6
        phong 0.8
        phong_size 120
    }
}

#declare CHROME = texture {
    pigment { Gray20 }
    finish {
        ambient 0.1
        diffuse 0.7
        brilliance 6.0
        reflection 0.6
        phong 0.8
        phong_size 120
    }
}

//------------- Dark Brown & Tan swirl Granite with gray undertones
/*
#declare BROWN_BRICK =
texture{pigment{color Black}}
texture{Grnt17a scale <3, 6, 2> rotate <0, 0, 50>}
texture{Grnt3a scale <1, 2, 1> rotate <0, 0, -50>
        finish{phong 1.0 phong_size 90}
}
*/
// White marble with black veins.
#declare WHITE_MARBLE = 
 pigment 
  {marble
   turbulence 1
   color_map 
    {[0.0, 0.8  color red 0.9 green 0.9 blue 0.9
                color red 0.5 green 0.5 blue 0.5]
     [0.8, 1.01 color red 0.5 green 0.5 blue 0.5
                color red 0.2 green 0.2 blue 0.2]
    }
  }

#declare OLD_METAL = texture {
   finish {
    metallic
    ambient 0.25
    diffuse 0.65
    reflection 0.1
    brilliance 6
    phong 1
    phong_size 100 }
   pigment { color Gray20 }
}

// Light tan wood with brown rings.
#declare TAN_WOOD = 
 pigment 
  {wood
   turbulence 0.1
   color_map 
    {[0.0, 0.8  color red 0.888 green 0.600 blue 0.3
                color red 0.888 green 0.600 blue 0.3]
     [0.8, 1.01 color red 0.6   green 0.4   blue 0.2
                color red 0.4   green 0.3   blue 0.2]
    }
  }

// An excellent lead crystal glass!
#declare CRYSTAL = texture {
    pigment
    { color red 0.98 green 0.98 blue 0.98 filter 0.9 }
    finish 
    { ambient 0.1
      diffuse 0.1
      specular 0.8
      reflection 0.1
      refraction 0.9
      ior 1.45
      roughness 0.0003
      phong 1 
      phong_size 400
    }
}

#declare WWood = texture {
   pigment {
      wood
      turbulence 0.1
      colour_map {
         [ 0.0 0.35 colour red 0.7  green 0.4
                    colour red 0.7  green 0.4  ]
         [ 0.35 1.0 colour red 0.95 green 0.62
                    colour red 0.95 green 0.62 ]
      }
      scale <0.6, 1000.0, 0.6>
      translate <200.0, 0.0, 100.0>
   }
   finish {
      specular 1
      roughness 0.02
   }
}

#declare BWood = texture {
   pigment {
      wood
      turbulence 0.1
      colour_map {
         [ 0.0 0.55 colour red 0.45 green 0.25
         colour red 0.45 green 0.25 ]
         [ 0.55 1.0 colour red 0.30 green 0.16
         colour red 0.30 green 0.16 ]
      }
      scale <0.6, 1000.0, 0.6>
      translate <100.0, 0.0, -200.0>
   }
   finish {
      specular 1
      roughness 0.02
   }
}
