// support.pov
//
// Test POV file for stage supports
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare displayStadium = true;
#declare useRad = true;

#include "colors.inc"
#include "support1.inc"
#include "field.inc"
#if (displayStadium = true)
#include "stadium.inc"
#end

global_settings{
    assumed_gamma 2.2
    #if (useRad = true)
    radiosity{
        pretrace_start 0.04
        pretrace_end 0.01
        count 200
        recursion_limit 3
        nearest_count 10
        error_bound 0.5
    }
    #end
}

object { Support1 }

#if (useRad = true)
    #declare LightColor= < 1, 0.67, 0.21 >;
    
    #declare N=3;       // Divisions per side
    #declare DX=13/N;   // Dimensions of sub patches
    #declare DZ=10.5/N;
    #declare lightHeight1 = 25;
    #declare lightHeight2 = 35;
    #declare lightHeight3 = 45;
    
    #declare SubPatch = light_source {
        < 0, lightHeight2, -1.5 >
        color LightColor*7
        area_light DX*y, DZ*z, 4, 4 jitter adaptive 0
        spotlight radius -90 falloff 90 tightness 1 point_at < 0, lightHeight2, -100 > // for cosine falloff
        fade_power 2 fade_distance (DX+DZ)/2
    }
    
    #declare i=0;#while (i<N)
      #declare j=0;#while (j<N)
         light_source{SubPatch translate<0,i*DX-(13-DX)/2,j*DZ-(10.5-DZ)/2>}
      #declare j=j+1;#end
    #declare i=i+1;#end
    
#else
    light_source { < 1000, 1000, -1000 > color red 1.0 green 1.0 blue 1.0 }
#end

box {
    < -2, 33, -1.49 >,
    <  2, 37, -1.4 >
    no_shadow
    pigment { rgb < 1, 1, 1 > }
    finish { ambient 0.78 diffuse 0 } 
}

camera {
   location < 10, 6, -60 >
   look_at < 0, 35, 0 >
}

#if (displayStadium = true)
object {
   Stadium
   texture { Concrete1 }
}
#end
