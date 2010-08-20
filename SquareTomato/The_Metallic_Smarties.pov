// MegaPOV 1.2.1 Scene File "The Metallic Smarties HDRI.pov"
// created by Adrian Jackson
// Date: 18.02.2006   
// Web Site: www.squaretomato.co.uk/povray
//-----------------------------------------------------------------------------------------

#version unofficial megapov 1.2;

//-----------------------------------------------------------------------------------------
//includes---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
 
#include "colors.inc"

//-----------------------------------------------------------------------------------------
//Global Set Up----------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#declare use_dof=0;  // (0=off, 1=on)
#declare pp=0; // (0=off, 1=on)
#declare rad_brightness=1.0;

#declare DepthMin=0; //post processing
#declare DepthMax=60; //post processing


global_settings{                     
max_trace_level 15
assumed_gamma 2.0
radiosity{
  pretrace_start 0.08 pretrace_end 0.001
  //always_sample off
  count 1000
  nearest_count 20
  error_bound 0.35
  recursion_limit 1   

  low_error_factor 0.2
  gray_threshold 0.0
  minimum_reuse 0.005

  brightness 1.0 
  adc_bailout 0.01/2

  //normal on
  //randomize on
  }
}


//-----------------------------------------------------------------------------------------
//Textures---------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------


#declare twhite = texture{pigment{White} finish{ambient 0 reflection .24 diffuse 0.9}
}

//#declare r_col=seed(2234);
#declare r_col=seed(2239);


//-----------------------------------------------------------------------------------------
//Objects----------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------	               

#declare ystart=0;

#declare ball=
sphere{
 0,1 hollow
 scale <0.8,0.4,0.8>
}
                                                                          
//-----------------------------------------------------------------------------------------
//Scene------------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------	

plane {y, ystart texture{twhite}} 

union{
 // outer loop -------------------
 #declare NrX = - 2.5;  // start x
 #declare EndNrX =  2.5;// end   x
 #while (NrX< EndNrX+1)
  // inner loop ------------------
  #declare NrZ = 0;     // start z
  #declare EndNrZ =  25; // end   z
  #while (NrZ< EndNrZ+1)

  
        #local rfi=1.2;
        #local s_smartie=rgb <rand(r_col),rand(r_col),rand(r_col)>; 
        
        object {ball translate <NrX,0.4,NrZ>
                texture {pigment {s_smartie} finish {reflection {s_smartie*rfi,s_smartie.gray*rfi} conserve_energy}}}
  
 
  #declare NrZ = NrZ + 5.5; // next Nr z
  #end // -------------- end of loop z
  // end inner loop
 #declare NrX = NrX + 2.5;  // next Nr x
 #end // --------------- end of loop x
// end of outer loop
} // end of union ----------------------


//-----------------------------------------------------------------------------------------
//Lighting---------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

sphere {
  0,300
  pigment {image_map {
  hdr "studio-light-to-hdr.hdr" once interpolate 2 map_type 1}} finish { ambient 1.2 diffuse 0 } 
  hollow
  scale <-1,1,1>
  translate <0,0,0>
  rotate <0,-90,0>}

//-----------------------------------------------------------------------------------------
//Camera-----------------------------------------------------------------------------------    
//-----------------------------------------------------------------------------------------

#declare blur_amt=0;

#declare cam3 = camera {#declare cl=<0,ystart+6,-13>;
                        //#declare la=<-0.7,ystart,2.0>;
                        #declare la=<0,ystart,4.5>;  
                        //right x*1280/1024
                        location cl
                        angle 30
                        look_at la
                        #if (use_dof)
                          focal_point la
                          aperture 0.01
                          blur_samples blur_amt
                          confidence 0.999           // [0...1] when to move on while sampling (smaller is less accurate)
                          variance 1/10000            // [0...1] how precise to calculate (smaller is more accurate)
                        #end}   
                        

camera {cam3}