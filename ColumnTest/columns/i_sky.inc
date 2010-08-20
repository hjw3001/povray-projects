/*
  Persistence of Vision Ray Tracer Scene Description File

  Tierra v1.0 - Sky & Sun include, using Skylight

  --   
  Jaime Vives Piqueres, Apr-May-Jun 2004.

*/

// *** sky sphere and sun using CIE_Skylight and sunpos.inc ***
// random position
#ifndef(Al)    #declare Al=int(90*rand(r_sun)); #end
#ifndef(Az)    #declare Az=int(360*rand(r_sun)); #end
#ifndef(North) #declare North=<-1+2*rand(r_sun),0,-1+2*rand(r_sun)>; #end
#include "CIE_Skylight"
// ignore SunColor from Skylight, use blackbody model
#declare c_sun=Blackbody(2000+(6000*Al/90));
light_source{ 
 SolarPosition, Light_Color(c_sun, 10)
 parallel point_at 0
 #if (use_area)
 area_light 800*x,800*z,8,8 jitter adaptive 1 orient circular
 #end
 looks_like{
  sphere{0,Sun_Size hollow
   texture{pigment{rgbt 1} finish{diffuse 0}}
   interior{media{emission Light_Color(c_sun,.001)}}
  }
 }
}



