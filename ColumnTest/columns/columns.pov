/*
  Persistence of Vision Ray Tracer Scene Description File

  COLUMNS - A simple scene to practice Wings3D modelling.

  Idea after a render by Craftwerk Graphics (coloseum).

  --   
  Jaime Vives Piqueres, Aug-Sept 2004.

  ***
  Usage notes:

  + this scene uses a 3 pass technique, the third being postprocessed:

    1) Render first with use_rad=2 and the rest switched off. On this pass
       you can use half the final resolution.
    2) Then set use_rad=1 and the rest to your desired values, except 
       use_media, wich remains at 0.
    3) If you want the additional media layer for postprocesing, rename the
       image from last pass and render a third time with all set to 0 and
       use_media=1. Then use your favorite image manipulation software to mix 
       the third and second pass images.   

*/
#version 3.5;


// ***************
// *** globals ***
// ***************
#declare use_rad  =2;  // 0=off, 1=load, 2=save 
#declare use_blur =0;  // x8 = blur_samples used
#declare use_area =0;  // on/off
#declare use_media=0;  // on/off (for postprocesed media)
#declare use_grass=0;  // on/off
#declare use_plant=0;  // on/off
global_settings{
 max_trace_level 32 // raised for the cumulus containers
 assumed_gamma 1.5  // raised a bit for contrast
 #if (use_rad)
 radiosity{ 
  // save settings
  #if (use_rad=2) 
    pretrace_start 0.08 pretrace_end   0.01
    count 150 nearest_count 20 error_bound .25
//    count 50 nearest_count 10 error_bound .5
    recursion_limit 2
    low_error_factor 1
    gray_threshold 0.0
    minimum_reuse 0.015
    brightness 1
    always_sample off
    save_file "columns.rad"
    normal off
    media off
  #else
    // load settings  
    pretrace_start 1 pretrace_end 1 
    load_file "columns.rad" 
    error_bound .25
//    error_bound .5
    recursion_limit 2
    always_sample off  
    brightness 1
    normal off
    media off
  #end
 }
 #end
}
#default{
 texture{
  finish{
   ambient 0 
   // if using media make the objects black to obtain a media mask for postp.
   #if (use_media) 
   diffuse 0
   #end
  }
 }
}


// *************************
// *** standard includes ***
// *************************
#include "colors.inc"
#include "textures.inc"
#include "functions.inc"


// *******************************
// *** CIE & LIGHTSYS includes ***
// *******************************
#include "CIE.inc"
#include "lightsys.inc"          
#declare Lightsys_Brightness=1;
CIE_ColorSystemWhitepoint(CIE_ColSys,Daylight2Whitepoint(6500))


// ****************************
// *** sun & sky parameters ***
// ****************************
#declare r_sun=seed(243); // seed for random sun placement
// skylight params:
#declare Current_Turbidity=3; // skylight turbidity (influences haze)
#declare Intensity_Mult   =3; // skylight intensity
#declare Max_Vertices  =5000; // skylight mesh resolution
#declare Sun_Size      =5000; // aparent size of the sun
// sun placement settings (uses rand seed if these are not specified)
//#declare Az   =310;
//#declare Al   = 42;
//#declare North=<-0.8944,0.0000,0.4473>;
#include "i_sky.inc"


// ***************
// *** COLUMNS ***
// ***************

// photographic textures "proceduralized"
#if (use_rad<2)
#declare p_map=
pigment{image_map{jpeg "im_concrete.jpg"}}
#declare p_mapf=
pigment{image_map{jpeg "im_concrete.jpg" transmit all .75}}
#declare t_map=
texture{ // first layer is little turbulenced, only to avoid pixelization
 pigment{
   p_map
   scale 100 warp{turbulence .3 lambda 3} scale .01
   translate <-.5,0,0> scale 5
 }
}
texture{ // second layer is to avoid repetition
 pigment{
   p_mapf
   warp{turbulence 1 lambda 3}
   scale 100 warp{turbulence .3 lambda 3} scale .01
 }
 scale 7
}
#else
#declare t_map=texture{pigment{Gray}}
#end

// model exported from Wings and converted to macro to get random instances
#include "i_column-tiles.inc"

// create half circle of exterior columns
#declare nc=30; 
#declare ic=0;
#declare r_col=seed(747);
#declare ex_arches=
union{
 #while (ic<nc)
  object{column(t_map,10000*rand(r_col))
   scale <.1,.08,.1>
   translate <0,0,-8>
   rotate (ic*90/nc)*y
  }
  #declare ic=ic+1;
 #end
 rotate 85*y
}

// create half circle of interior columns
#declare nc=26;
#declare ic=0;
#declare in_arches=
union{
 #while (ic<nc)
  object{column(t_map,10000*rand(r_col))
   scale <.1,.08,.1>
   translate <0,0,-7.5>
   rotate (ic*90/nc)*y
  }
  #declare ic=ic+1;
 #end
 rotate 85*y
}

// arches ceiling (CSG)
#declare nc=28;
#declare ic=0;
#declare ceiling=
union{
 #while (ic<nc)
  intersection{
   difference{
    cylinder{<-.2,0,0>,<.2,0,0>,.3}
    cylinder{<-.201,0,0>,<.201,0,0>,.195}
    cylinder{<-.201,.195,0>,<.201,.195,0>,.001}
    cylinder{<-.201,.195,0>,<.201,.195,0>,.001 rotate 30*x}
    cylinder{<-.201,.195,0>,<.201,.195,0>,.001 rotate -30*x}
    cylinder{<-.201,.195,0>,<.201,.195,0>,.001 rotate 60*x}
    cylinder{<-.201,.195,0>,<.201,.195,0>,.001 rotate -60*x}
    scale <1.09,1,1.02>
   }
   plane{y,0 inverse}
   texture{t_map scale .1 translate (-100+200*rand(r_col))*x}
   translate <0,0,-7.75>
   rotate (ic*90/nc)*y
  }
  #declare ic=ic+1;
 #end
 rotate 84*y
}

// stone texture from a cut of the lower part of im_concrete.jpg
#declare t_floor=
#if (use_rad<2)
texture{
 pigment{
  image_map{jpeg "im_floor.jpg"} 
  scale 10 warp{turbulence 1 lambda 3} scale .1
 }
 translate (-100+500*rand(r_col))*x
 rotate 90*x
}
#else
texture{pigment{Gray}}
#end

// stone object
#if (use_rad<2)
#declare floor_tile=
superellipsoid{<.1,.1> rotate 90*x scale .5}
#else
#declare floor_tile=
box{-.5,.5}
#end

// old grass include
#include "i_grass.inc" 

// circles of stones & grass
#declare nc=115;
#declare ic=0;
#declare arches_floor=
union{
#while (ic<nc)
object{floor_tile
 scale <.1,.055,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-8.1>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.1,.055,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-8>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.1,.055,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-7.9>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.099,.055,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-7.8>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.098,.055,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-7.7>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.097,.055,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-7.6>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.096,.06,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-7.5>
 rotate (ic*90/nc)*y
}
object{floor_tile
 scale <.094,.06,.105>
 texture{t_floor translate 33*rand(r_col)}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 translate <0,.025,-7.4>
 rotate (ic*90/nc)*y
}
#if (use_grass)
#if (rand(r_col)>.5)
object{grass(rand(r_col)) 
 scale (1+rand(r_col))*.0015
 texture{pigment{DarkGreen}}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 #if (rand(r_col)>.5)
  translate <.05,.05,-7.95>
 #else
  translate <.05,.05,-7.85>
 #end
 rotate (ic*90/nc)*y
}
#else
object{grass(rand(r_col))
 scale (1+rand(r_col))*.0015
 texture{pigment{DarkGreen}}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 #if (rand(r_col)>.5)
  translate <-.05,.05,-7.95>
 #else
  translate <-.05,.05,-7.75>
 #end
 rotate (ic*90/nc)*y
}
#end
#if (rand(r_col)>.5)
object{grass(rand(r_col)) 
 scale (1+rand(r_col))*.0015
 texture{pigment{DarkGreen}}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 #if (rand(r_col)>.5)
  translate <.05,.05,-7.55>
 #else
  translate <.05,.05,-7.65>
 #end
 rotate (ic*90/nc)*y
}
#else
object{grass(rand(r_col))
 scale (1+rand(r_col))*.0015
 texture{pigment{DarkGreen}}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 #if (rand(r_col)>.5)
  translate <-.05,.05,-7.55>
 #else
  translate <-.05,.05,-7.85>
 #end
 rotate (ic*90/nc)*y
}
#end
#if (rand(r_col)>.5)
object{grass(rand(r_col)) 
 scale (1+rand(r_col))*.0015
 texture{pigment{DarkGreen}}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 #if (rand(r_col)>.5)
  translate <.05,.05,-7.55>
 #else
  translate <.05,.05,-7.95>
 #end
 rotate (ic*90/nc)*y
}
#else
object{grass(rand(r_col))
 scale (1+rand(r_col))*.0015
 texture{pigment{DarkGreen}}
 rotate <-1+2*rand(r_col),0,-1+2*rand(r_col)>
 #if (rand(r_col)>.5)
  translate <-.05,.05,-7.65>
 #else
  translate <-.05,.05,-7.85>
 #end
 rotate (ic*90/nc)*y
}
#end
#end // use gras
#declare ic=ic+1;
#end
rotate 85*y
}

// setup the colosseum 
union{
object{ex_arches translate .05*y}
object{in_arches translate .05*y}
object{ceiling translate .61*y}
object{arches_floor}
}

// filling plane
plane{y,0 texture{t_floor scale .1}}


// *************
// *** PLANT ***
// *************
#if (use_plant)
#declare usar_detalle=1;
#declare p_tree1=DarkGreen*.5+Gray10+Gold*.1;
#declare p_tree2=DarkGreen*.6+Gold*.2;
#declare p_tree3=DarkGreen*.6+Gray20;
#declare p_leaf1=DarkGreen*.6+Gray20;
#declare p_leaf2=DarkGreen*.6+Gray10+Gold*.1;
#declare p_leaf3=DarkGreen*.6+Gold*.2;
#declare p_leaf4=DarkGreen*.5+Gold*.3;
#include "plant02.inc" 
#include "TOMTREE.inc"
object{TREE scale .125 translate <-7.7,0,2.1>}
#end


// *************************
// *** ATMOSPHERIC MEDIA ***
// *************************
#if (use_media)
sphere{0,9 hollow no_shadow}
media{
  intervals 4
  scattering{2,c_sun*.1}
}
#end


// **************
// *** camera ***
// **************
camera{ 
 location <-7.85,.15,-1>
 up 0.000024*y right 0.000036*x
 direction 0.000085*z
 look_at <-7.8,.2,1>
 #if (use_blur>0)
  aperture .01 blur_samples 8*use_blur 
  focal_point <-7.8,.2,2.1>
 #end
}



