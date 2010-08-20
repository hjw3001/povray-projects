#version 3.5;
global_settings {assumed_gamma 1.0}
camera {location <0, 0,-12.0> look_at 0 angle 30 }
#declare Container_T= texture {
   pigment {rgbt <1,1,1,1>}
   finish {ambient 0 diffuse 0}
}

#declare Scale=2;

box {                  //The reference
   <-1,-1,0>,<1,1,.3>
   hollow
   texture {Container_T}
   interior {
      media {
         intervals 1         
         samples 1,1          
         emission 1
      }
   }
   translate <-2.1,0,0>
}

box {                  //Object scaled twice as big
   <-1,-1,0>,<1,1,.3>  //looks different but same
   hollow                          //particle density
   texture {Container_T}
   interior {
      media {
         intervals 1         
         samples 1,1          
         emission 1
      }
   }
   scale Scale
   translate<0,0,12>
}

box {                  //Object scaled twice as big       
   <-1,-1,0>,<1,1,.3>  //looks the same but particle
   hollow                          //density scaled down
   texture {Container_T}
   interior {
      media {
         intervals 1         
         samples 1,1          
         emission 1/Scale
      }
   }
   scale Scale
   translate<0,0,12>
   translate<4.2,0,0>
}