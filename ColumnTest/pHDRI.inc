/*

  Pseudo-HDRI mapping macro

  --
  Jaime Vives Piqueres, Jun. 2004 - <jaime@ignorancia.org>

  http://www.ignorancia.org

*/

// Parameters:
//		+ name of the image to map (string)
//		+ type of the image to map (string)
//		+ luminosity curve exponent (integer)
//		+ amount of ambient light (float)
//		+ amount of filter for the image shell (float)
#include "consts.inc"
#macro
pseudoHDRI_sphere(map_name,map_kind,light_exponent,light_ambient,light_filter)

// declare image pigments
#local p_image=
pigment{
 image_map{ // these are only the types I use...
  #if (strcmp(map_kind,"jpeg")=0) jpeg map_name #end
  #if (strcmp(map_kind,"png")=0) png map_name #end
  #if (strcmp(map_kind,"tga")=0) tga map_name #end
  #if (strcmp(map_kind,"ppm")=0) ppm map_name #end
  #if (strcmp(map_kind,"bmp")=0) bmp map_name #end
  map_type 1
  interpolate 2 // perhaps innecesary for some maps
 }
}
#local p_image_filtered=
pigment{
 image_map{ // these are only the types I use...
  #if (strcmp(map_kind,"jpeg")=0) jpeg map_name #end
  #if (strcmp(map_kind,"png")=0) png map_name #end
  #if (strcmp(map_kind,"tga")=0) tga map_name #end
  #if (strcmp(map_kind,"ppm")=0) ppm map_name #end
  map_type 1
  interpolate 2 // perhaps innecesary for some maps
  filter all light_filter 
 }
}

// convert the image into a function of a image_map
#local fp=function{pigment{p_image}}

// environment object
union{
 sphere{0,1
  hollow no_shadow
  texture{
   pigment{
    function{fp(x,y,z).gray}
    poly_wave light_exponent
    color_map{
    [0.0 rgb 0]
    [1.0 rgb light_ambient]
    }
   }
   finish{diffuse 0 ambient 1}
  }
 }
 sphere{0,.999
  hollow no_shadow
  texture{
   pigment{p_image_filtered}
   finish{diffuse 0 ambient 1}
  }
 }
}

#end // en of macro DRM


