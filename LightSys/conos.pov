// +w256 +h256 +a0.1

#include "colors.inc"
#include "textures.inc"

global_settings{
 radiosity{
  pretrace_start .1 pretrace_end .01
  count 160 nearest_count 20 error_bound .25
  recursion_limit 1
 }
}

sphere{
 0,10e5
 pigment{
  White
 }
 finish{ambient .9}
}

light_source{
 <0,100,-100>
 White*.05
}

plane{y,0
 pigment{White}
 finish{diffuse 1}
}

plane{z,10000 rotate 82*x
 pigment{White}
 finish{diffuse 1}
}

#declare cono=
union{
 superellipsoid{ 
  <.1,.1> rotate 90*x
  scale <7,1,7>
  translate .5*y
 }
 cone{
  <0,0,0>,5,<0,20,0>,1
 }
 pigment{
  gradient y
  color_map{
   [0.0 OrangeRed]
   [0.4 OrangeRed]
   [0.4 White]
   [0.7 White]
   [0.7 OrangeRed]
   [1.0 OrangeRed]
  }
  scale 20
 }
 finish{specular .9 diffuse .9 reflection{.1}}
}

object{cono translate <7,0,2>}
object{cono scale .75 rotate 60*y translate <-6,0,-7>}

camera{
 location <-1,18,-70>
 up 1*y
 right 1*x
 direction 2*z
 look_at <0,8,0>
}

