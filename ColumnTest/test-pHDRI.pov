// *********************************************************
// Persistence Of Vision Ray Tracer Scene Description File
// File name  : pHDRI-test.pov
// Version    : 3.6
// Description: test of the "pseudoHDRI" include (pHDRI.inc)
// Date       : Jun-2004
// Author     : Jaime Vives Piqueres
// Note	      : render sm_test.pov first 
// *********************************************************

// Set use_radiosity to 2 and render at half of the desired resolution,
// then set it to 1 and render the second pass at the final resolution.
// You may need to tweak rad_brightness and/or the paramteres of the 
// pHDRI macro for each spherical map.

#include "colors.inc"
#include "textures.inc"
#include "stones.inc"
#include "metals.inc"
#include "woods.inc"


// **************
// *** global ***
// **************
#declare use_blur    =7*0;  // blur samples (0=off)
#declare use_radiosity =1;  
#declare rad_brightness=2;
global_settings{
 max_trace_level 6
 assumed_gamma 2.2
 #if (use_radiosity)
  radiosity{
   #if (use_radiosity=2)
    // save settigns
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


// ********************
// *** TEST OBJECTS ***
// ********************
#if (use_radiosity=1)
#declare t_metal=
texture{
 pigment{Gray10} 
 finish{reflection{.6,.9} diffuse .25}
}
#declare t_paint=
texture{
 pigment{ForestGreen}
 finish{reflection {.1,.2}}
 normal{bumps .1}
}
#else
#declare t_metal=
texture{pigment{Gray}}
#declare t_paint=
texture{pigment{ForestGreen}}
#end
sphere{0,.75
 texture{t_metal}
 translate <0,.75,.2>
}
cylinder{-2*x,2*x,.5 
 texture{t_paint}
 rotate 40*y translate <-.2,.5,3>
}


// *************
// *** TABLE ***
// *************
#declare table=
cylinder{-.5*y,.5*y,.5
 scale <50,1,50>
 #if (use_radiosity=1)    
 texture{
  pigment{checker color Gray color Firebrick scale 4}
  normal{granite .1 scale .1} 
  finish{reflection{.01,.3} diffuse .7}
 }
 #else
 texture{pigment{Gray} normal{granite .1 scale .1}}
 #end
 translate -.5*y
}
object{table rotate 27*y}


// ****************************
// *** Pseudo-HDRI lighting ***
// ****************************
#declare r_h=seed(293);
#include "pHDRI.inc"
// please, render sm_test.pov first!
#declare sm_type="tga"
#declare sm_file="sm_test.tga"
object{
 #if (use_radiosity=2)
  pseudoHDRI_sphere(sm_file,sm_type,2,4,.5)
 #else
  pseudoHDRI_sphere(sm_file,sm_type,1,2,.5)
 #end
 scale 800 rotate 10*y
}
// these other maps must be downloaded separately from the same place,
// as there will be a growing collection of spherical maps for pHDRI
/*
#declare sm_type="jpeg"
#declare sm_file="sm_jvp_patio-2.jpg"
object{
 #if (use_radiosity=2)
  pseudoHDRI_sphere(sm_file,sm_type,2,6,.5)
 #else
  pseudoHDRI_sphere(sm_file,sm_type,1,3,.5)
 #end
 scale 800 rotate 10*y
}
*/
/*
#declare sm_type="jpeg"
#declare sm_file="sm_jvp_office.jpg"
object{
 #if (use_radiosity=2)
  pseudoHDRI_sphere(sm_file,sm_type,2,9,.5)
 #else
  pseudoHDRI_sphere(sm_file,sm_type,1,4,.5)
 #end
 scale 800 rotate 10*y
}
*/


// **************
// *** camera ***
// **************
#declare cl=<0,2,-8>;
#declare la=<-.1,.5,0>;
camera{
 location cl
 up 2.4*y
 right 3.2*x
 direction 8.5*z
 look_at la
 #if (use_blur)
 focal_point la
 aperture .125
 blur_samples use_blur
 #end
}

