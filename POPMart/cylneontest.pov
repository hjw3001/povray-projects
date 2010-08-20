#version unofficial MegaPov 1.2;

#include "colors.inc"
#include "shapes.inc"   
#include "textures.inc"
#include "functions.inc"

#declare useRad = false;
#declare displayPlane = true;

global_settings{
    assumed_gamma 2.2
#if (useRad)
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
#end
}

#declare useNeonEffect = true;

#declare emis_val_def = 15;
#declare field_strengh_def = 10;
#declare field_limit_def = 0.05;

#declare emis_val = emis_val_def;
#declare field_strengh = field_strengh_def;
#declare field_limit = field_limit_def;

#switch (frame_number)
  #range(0,100)
    #declare emis_val = frame_number;
    #break
  #range(100,200)
    #declare field_strengh = frame_number - 100;
    #break  
  #range(200,300)
    #declare field_limit = frame_number - 200;
    #break  
  #range(300,400)
    #declare emis_val = frame_number - 300;
    #declare field_strengh = frame_number - 300;
    #break  
  #range(400,500)
    #declare emis_val = frame_number - 400;
    #declare field_limit = frame_number - 400;
    #break  
  #range(500,600)
    #declare field_strengh = frame_number - 500;
    #declare field_limit = frame_number - 500;
    #break  
  #else  
    #declare emis_val = frame_number - 600;
    #declare field_strengh = frame_number - 600;
    #declare field_limit = frame_number - 600;
#end

#macro DisplayNeonTorus(color_val, trans_val) 
// #declare neon_light = torus {
cylinder {
    < 0, 0, -5 >,
    < 0, 0, 5>, 2

    pigment { color rgbt 1 }
    finish { ambient 14.0 diffuse 0 reflection 0.5}
    hollow

    #if (useNeonEffect)    
    interior {
        media {
            // emission rgb <1, 0.01, 0.001> * 15
            emission rgb color_val * emis_val
            density {
                // Five extra parameters required:
                // 1. Field Strength 
                // 2. Field Limit 
                // 3. SOR Switch 
                // 4. SOR Offset 
                // 5. SOR Angle
                function { f_algbr_cyl1(x,y,z,field_strengh,field_limit,false,0,0) }
            }
        }
    }
    #end
    translate trans_val 
}
#end                             

#if (displayPlane)
plane {
   < 0, 1, 0 >, -5
      texture {
         pigment { color Yellow }
         finish {
            metallic
            specular 1
            roughness 0.001
            ambient 0.6
            diffuse 0.4
            reflection 0.01
         }
      }
}
#end

DisplayNeonTorus( < 1, 0.01, 0.001 >, < 0, 0, 0 > )

#declare source = 10;

camera {
   location < source, source, source >
   look_at < 0, 0, 0 >
}

