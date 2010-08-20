// TopLght.inc
//
// Written by: Henry Wagner (povray@henrywagner.org)

#if (clock_on = 1)
    #declare FN = frame_number;
    #declare counter = 0;
    #declare maxVal = 30;
    #declare sIndex = 0.0;
    #declare sInc = 1/maxVal;
    #while (counter < FN)
        #declare sIndex = sIndex + sInc;
        #if (sIndex > 1.0)
            #declare sIndex = sIndex - 1.0;        
        #end
        #declare counter = counter + 1;    
    #end
#else
    #declare sIndex = 0.5;
#end

#declare TopLightColors = function {
   spline {
       natural_spline
       0.0,  < 1, 1, 1 >
       0.25, < 1, 1, 0 >
       0.5,  < 1, 0, 1 >
       0.75, < 0, 1, 1 >
       1.0,  < 1, 1, 1 >
   }
}

#declare TopLight = union {
   cylinder {
      < 0, 0, 0 >,
      < 0, -4, 0 >,
      0.5
      texture {
         pigment { color red 0.2 green 0.2 blue 0.2 }
         finish {
            metallic
            ambient 0.5
            diffuse 0.4
         }
      }
   }
   sphere {
      < 0, 0, 0 >, 0.45
      scale < 1, 0.4, 1 >
      texture {
         pigment { color rgb TopLightColors(sIndex) }
         finish {
            ambient 1.0
            diffuse 0.0
         }
      }
      translate < 0, -4, 0 >
   }
}

// EOF
