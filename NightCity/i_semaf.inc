// *** SEMAPHORES ***
#include "i_signs.inc"
#declare caja_luz=
union{
  difference{
   box{<-8,-10,-10>,<8,10,30>}
   box{<-8,-10,-10>,<8,10,30> scale .95}
   cylinder{<0,0,-15>,<0,0,5>,6}
  }
  intersection{
   difference{
    cylinder{<0,0,-35>,<0,0,0>,6}
    cylinder{<0,0,-36>,<0,0,1>,5.75}
   }
   plane{y,0 inverse}
  }
  texture{pigment{SteelBlue*.5+Gray20} normal{granite scale 2} finish{Shiny}}
 }
#declare semaforo=
union{
 union{
  cone{<0,0,0>,10,<0,50,0>,9}
  cone{<0,40,0>,7,<0,200,0>,5}
  intersection{
   torus{100,5 rotate -90*x}
   plane{y,0 inverse}
   plane{x,0 inverse}
   translate <-100,200,0>
  }
  cone{<-165,300,0>,3.5,<-100,300,0>,5}
  texture{pigment{SteelBlue*.5+Gray20} normal{granite scale 2} finish{Shiny}}
 }
 cylinder{<0,179,0>,<0,181,0>,9
   texture{T_Chrome_3A}
 }
 object{caja_luz translate <-170,300-5,-10>}
 object{caja_luz translate <-170,310-5,-10>}
 object{caja_luz translate <-170,290-5,-10>}
 sphere{0,8 scale <1,1,.1> texture{Glass} translate <-170,290-5,-20>}
 sphere{0,8 scale <1,1,.1> texture{Glass2} translate <-170,300-5,-20>}
 sphere{0,8 scale <1,1,.1> texture{Glass} translate <-170,310-5,-20>}
 // *** TRAFFIC SIGNS ***
 object{vel_limit translate <0,180,-10>}
 // orange light
 #if (at_nigth)
 light_source{
  0
  OrangeRed
  fade_distance 300
  fade_power 8
  translate <-170,300-5,-15>
 }
 intersection{
  sphere{<0,0,0>,1}
  plane{z,0}
  hollow
  no_shadow
  material{
   texture{
    pigment { color rgbt <1,1,1,1>}
    finish { ambient 0 diffuse 0 }
   }
   interior{
    media {
     emission 0.05
     intervals 12
     samples 1, 10
     confidence 0.9999
     variance 1/1000
     density {
       spherical
       turbulence .1
       color_map {
         [0.0 Black]
         [0.7 OrangeRed*.3]
         [0.8 OrangeRed]
         [1.0 Yellow]
       }
       frequency 1
     }
    }
   }
   scale .9
  }
  scale 50
  translate <-170,300-5,-30>
 }
 #end
}
#declare semaforo2=
union{
 union{
  cone{<0,0,0>,10,<0,40,0>,8}
  cone{<0,40,0>,7,<0,200,0>,5}
  intersection{
   torus{100,5 rotate -90*x}
   plane{y,0 inverse}
   plane{x,0 inverse}
   translate <-100,200,0>
  }
  cone{<-165,300,0>,3.5,<-100,300,0>,5}
  cylinder{<0,179,0>,<0,181,0>,9}
  texture{pigment{SteelBlue*.5+Gray20} normal{granite scale 2} finish{Shiny}}
 }
 object{caja_luz translate <-170,300-5,-10>}
 object{caja_luz translate <-170,310-5,-10>}
 object{caja_luz translate <-170,290-5,-10>}
 sphere{0,8 scale <1,1,.1> texture{Glass} translate <-170,290-5,-20>}
 sphere{0,8 scale <1,1,.1> texture{Glass2} translate <-170,300-5,-20>}
 sphere{0,8 scale <1,1,.1> texture{Glass} translate <-170,310-5,-20>}
 // *** TRAFFIC SIGNS ***
 object{vel_limit translate <0,180,-10>}
 // orange light
 #if (at_nigth)
 light_source{
  0
  OrangeRed
  fade_distance 300
  fade_power 8
  translate <-170,300-5,-15>
 }
 #end
}
