// SmallLight.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#include "colors.inc"               
#include "textures.inc"
#include "skies.inc"

#declare use_blur    =20*0;  // blur samples (0=off)
#declare use_radiosity =0;
#declare rad_brightness=2;
global_settings{
 max_trace_level 6
 assumed_gamma 2.2
 #if (use_radiosity)
  radiosity{
   #if (use_radiosity=2)
    // save settings
    pretrace_start .05 pretrace_end .01
    count 200 nearest_count 20 error_bound .25
    recursion_limit 1
    normal on
    brightness rad_brightness
    save_file "data.rad"
   #else
    // load settings
    pretrace_start 1 pretrace_end 1
    always_sample off
    error_bound .25
    recursion_limit 1
    normal on
    brightness rad_brightness
    load_file "data.rad"
   #end
  }
 #end
}
#default{texture{finish{ambient 0}}}


#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 100;
    #declare FF = 200;
#end

#declare initGen = seed(360);
#declare LightHeight = 1;
#declare CycleSpeed = 15;

#declare outCounter = -2;

#while (outCounter < 10)
    #declare counter = -2;
    #while (counter < 10)
        #declare LightPower = (mod(FN,CycleSpeed)/CycleSpeed) + rand(initGen);
        
        #if (LightPower > 1.0)
            #declare LightPower = LightPower - 1.0;
        #end
        
        #if (LightPower > 0.5)
            #declare LightPower = 1.0 - LightPower;
        #end
        
        #declare LightPower = LightPower + 0.5;
        
        union {
            box {
                < -(LightHeight/2), 0, -(LightHeight/2) >,
                <  (LightHeight/2), LightHeight, (LightHeight/2) >
                texture {
                    Brass_Texture
                    normal{granite .1 scale .1} 
                    finish{reflection{.01,.3} diffuse .7}
                }
            }
            sphere {
                < 0, 0, 0 >,
                ((LightHeight/2) * 0.9)
                scale < 0, .2, 0 >
                translate < 0, LightHeight, 0 >
                texture {
                    pigment { color Med_Purple }
                    finish {
                        ambient LightPower
                        diffuse 0
                    }
                }
            }
            translate < counter, 0, outCounter >
        }
        #declare counter = counter + 2;
    #end
    
    #declare outCounter = outCounter + 2;
#end

light_source {
    < 1000, 1000, -1000 >
    color White+Gold
    parallel
    point_at < 0, 0, 0 >
}

camera {
    location < -1, 2.4, -1 >
    look_at < 2, .5, 2 >
     #if (use_blur)
         focal_point < 2, .5, 2 >
         aperture .125
         blur_samples use_blur
     #end
}

#declare r_ls=seed(6467);

plane {
    < 0, 1, 0 >, 0
    /*
    texture {
        pigment { color Green }
        normal{granite .1 scale .1} 
        finish{reflection{.01,.3} diffuse .7}
    }
    */
    texture{
    pigment{Gray}
    normal{quilted 1 turbulence .1 scale 10 rotate 45*y}
   }
   texture{
    pigment{
     wrinkles
     turbulence 0.3
     lambda 3
     color_map{
      [0.0 DarkTan*.5 filter .5]
      [1.0 Clear]
     }
     scale 30
    }
    translate 1000*rand(r_ls)
   }

}

sky_sphere { S_Cloud2 }
