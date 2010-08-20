// hwcolors.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "stones.inc"
#include "stoneold.inc"
#include "textures.inc"
#include "glass.inc"

#declare HWGlassFinish = finish { F_Glass10 }

#if (clock_on=1)
    #declare TN = frame_number;
#else
    #declare TN = 0;
#end


#declare GroundTileTexture = texture {
    tiles {
        texture { Sandalwood }
    tile2
        texture { DMFWood1 }
    }
    scale 10
}

#declare GroundOldTexture = texture {   
    tiles {
        texture { Jade normal { granite .1 scale .1 } finish { reflection{.01, .3} diffuse .7 } }
    tile2
        texture { Stone3 normal { granite .1 scale .1 } finish { reflection{.01, .3} diffuse .7 } }
    }
    scale 10
}

#declare Red_Neon = texture {
   pigment { color Red }
   finish  {
      specular 0.6
      roughness 0.002
      ambient 1
      diffuse 0.1
      reflection {
        0.05, 1.0
      }
   }
}

#declare Green_Neon = texture {
   pigment { color Green }
   finish  {
      specular 0.6
      roughness 0.002
      ambient 1
      diffuse 0.1
      reflection {
        0.05, 1.0
      }
   }
}

#declare Red_Glass = texture {
   pigment { color Red }
   finish  { HWGlassFinish }
}

#declare Green_Glass = texture {
   pigment { color Green }
   finish  { HWGlassFinish }
}

#declare Stage_Black = texture {
   pigment { color Gray35 }
}

#declare Stage_White = texture {
   pigment { color White }
}

#declare TVZooBaby = pigment {
   image_map {gif "ColorBars2.gif"}
}

