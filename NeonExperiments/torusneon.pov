#version unofficial MegaPov 1.2;

#include "colors.inc"
#include "shapes.inc"   
#include "textures.inc"
#include "functions.inc"

global_settings{
    assumed_gamma 2.2
    radiosity {
        pretrace_start 0.08
        pretrace_end 0.01
        low_error_factor .8
        count 100
        nearest_count 20
        recursion_limit 4
        error_bound 1
        brightness 1
        media on
    }
}

#macro DisplayNeonTorus(color_val, trans_val) 
// #declare neon_light = torus {
torus {
    2, 0.1

    pigment { color rgbt 1 }
    finish { ambient 4.0 diffuse 0 reflection 0.5}
    hollow
    interior {
        media {
            // emission rgb <1, 0.01, 0.001> * 15
            emission rgb color_val * 35
            density {
                function { f_torus(x,y,z,2,0.05) }
            }
        }
    }
    translate trans_val 
}
#end

// object { neon_light }
DisplayNeonTorus( < 1, 0.01, 0.001 >, < 0, 0, 0 > )
DisplayNeonTorus( < 0.01, 1, 0.001 >, < 0, 0.5, 0 > )
DisplayNeonTorus( < 0.01, 0.001, 1 >, < 0, -0.5, 0 > )

sphere {
   < 0, -0.5, 0 > 1.8
   pigment { color Yellow }
}

#declare source = 3;

camera {
   location < source, source, source >
   look_at < 0, 0, 0 >
}

