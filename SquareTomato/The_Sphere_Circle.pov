// POV-Ray 3.6 Scene File "The Sphere Circle.pov"
// created by Adrian Jackson
// Date: 02.03.2006  
// Web Site: www.squaretomato.co.uk/povray
//-----------------------------------------------------------------------------------------

//#version 3.6;  
#version unofficial megapov 1.21;

//-----------------------------------------------------------------------------------------
//includes---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

#include "rad_def.inc"        

#include "pprocess.inc"

//-----------------------------------------------------------------------------------------
//Global Settings--------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#declare use_blur=0; 

#declare pp=0; // (0=off, 1=on)

#declare DepthMin=10; //post processing
#declare DepthMax=20; //post processing

global_settings {
	max_trace_level 20
	assumed_gamma 1
	radiosity { Rad_Settings( Radiosity_Fast, on, on ) }
//// adding a photon{} block to global_settings activates photon mapping.
// photons also need to be adjusted for light sources and objects.

  photons {
    spacing 0.01                 // specify the density of photons
    //count 500000               // alternatively use a total number of photons

    //gather min, max            // amount of photons gathered during render [20, 100]
    //media max_steps [,factor]  // media photons
    jitter 0.0                 // jitter phor photon rays
    //max_trace_level 5          // optional separate max_trace_level
    //adc_bailout 1/255          // see global adc_bailout
    //save_file "filename"       // save photons to file
    //load_file "filename"       // load photons from file
    autostop 0                 // photon autostop option
    //radius 10                  // manually specified search radius
    // (---Adaptive Search Radius---)
    //steps 1
    //expand_thresholds 0.2, 40
  }
  #if (pp=1) 
        post_process{ 
          PP_Depth(DepthMin,DepthMax)
          save_file concat("depthmap_",output_filename(0))}  
  #end      
}

//-----------------------------------------------------------------------------------------
//Macros-----------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#macro XZonacircle (circle_radius, circle_angle)

        #declare X = circle_radius*cos(radians(circle_angle));
        #declare Z = circle_radius*sin(radians(circle_angle));
        
#end 

//-----------------------------------------------------------------------------------------
//Textures---------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#default { pigment { rgb 1 } finish { diffuse .7 ambient 0 } }

#declare Glass = 
texture {
    pigment { rgbf <0.98, 0.98, 0.98, 0.9> }
    //pigment { rgbf <223/255, 234/255, 245/255, 0.9> }
    finish  {
        ambient 0.1
        diffuse 0.1
        reflection 0.1
        specular 0.8
        roughness 0.0003
        phong 1 
        phong_size 400
     }
}     

#declare t_white = texture {pigment {rgb < 1.0, 1.0, 1.0>}}

#declare t_glass = material{texture {Glass} 
                            interior {ior 1.5 fade_colour <0.5, 0.5, 0.5> fade_distance .5 fade_power 2 dispersion 1.0}}         


//-----------------------------------------------------------------------------------------
//Objects----------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#declare Ball = sphere{<0,0,0>,0.5 hollow on}         

//-----------------------------------------------------------------------------------------
//Scene------------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

plane { y, -.01 texture { t_white } }

                 
#declare circle_radius=2.7;   
#declare circle_steps=8;
#declare circle_angle=360/circle_steps;
 
#while ( circle_angle < 360+(360/circle_steps) ) 

        XZonacircle (circle_radius, circle_angle)
        object {Ball translate<X,0.5,Z> material {t_glass}                    
                photons{target         // spacing multiplier for photons hitting the object
                        refraction on
                        reflection on
                        //collect off       // ignore photons
                        //pass_through      // do not influence photons
                }}
  
        #declare circle_angle = circle_angle + (360/circle_steps);
#end  

background { rgb .8 }

//-----------------------------------------------------------------------------------------
//Lighting---------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------


// An area light (creates soft shadows)
// WARNING: This special light can significantly slow down rendering times!
/*
light_source {
  0*x                 // light's position (translated below)
  color rgb 1.0       // light's color
  area_light
  <4, 0, 0> <0, 0, 4> // lights spread out across this distance (x * z)
  8, 8                // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0          // 0,1,2,3...
  jitter              // adds random softening of light
  circular            // make the shape of the light circular
  orient              // orient light
  translate <-5, 15, 30>   // <x y z> position of light


  fade_power 2 fade_distance vlength(<-5,15,30>)
  photons {refraction on
           reflection on
           //area_light
	  } 
} */


light_source {
  0*x                 // light's position (translated below)
  color rgb 1.0       // light's color
  area_light
  <4, 0, 0> <0, 0, 4> // lights spread out across this distance (x * z)
  8, 8                // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0          // 0,1,2,3...
  jitter              // adds random softening of light
  circular            // make the shape of the light circular
  orient              // orient light
  translate <20, 15, -45>   // <x y z> position of light


  fade_power 2 fade_distance vlength(<20,15,-45>)
  photons {refraction on
           reflection on
           //area_light
	  } 
}     


light_source {
  0*x                 // light's position (translated below)
  color rgb 1.0       // light's color
  area_light
  <4, 0, 0> <0, 0, 4> // lights spread out across this distance (x * z)
  8, 8                // total number of lights in grid (4x*4z = 16 lights)
  adaptive 0          // 0,1,2,3...
  jitter              // adds random softening of light
  circular            // make the shape of the light circular
  orient              // orient light
  translate <-20, 15, -45>   // <x y z> position of light


  fade_power 2 fade_distance vlength(<-20,15,-45>)
  photons {refraction on
           reflection on
           //area_light
	  } 
}    



//-----------------------------------------------------------------------------------------
//Camera-----------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#declare cl=<0,8,-20>;
#declare la=<0,0,0>;   
#declare fp=<0,0+.8+.1,-3>; 

camera {location cl
        angle 20
        look_at la
        #if (use_blur)
          focal_point fp
          aperture .3
          blur_samples use_blur
        #end}

