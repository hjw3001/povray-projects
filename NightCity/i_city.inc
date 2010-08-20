// *** DISTANT BUILDINGS ***
#declare city_ambient=1;     // ambient for the window lights texture
#declare p_scale=1.5;        // scale          "
#declare p_turb=0.0;         // turbulence     "
#declare w_black_level=.3;   // level of black "
#declare p_windows=          // pattern        "
pigment{
 spotted
}
#declare f_windows=          // finish for windows lights texture
finish{Luminous ambient city_ambient reflection .3}
#declare t_distb=
texture{
 pigment{
  p_windows
  turbulence p_turb
  color_map{
   [0.0 Gold*.5+White*.5]
   [0+w_black_level Black]
   [0.9 Black]
   [0.925 Red]
   [0.95 Green]
   [0.975 Blue]
   [1.0 Black]
  }
  scale p_scale
 }
 finish{f_windows}
 translate 50
}
#declare t_distbuild1=
texture{
  brick
  texture{pigment{Tan} finish{ambient .1}}
  texture{t_distb}
  brick_size <1.5,30000000,1.5>
  mortar .7
  scale 101
  rotate -90*x
}
#declare t_distbuild2=
texture{
  brick
  texture{pigment{White} finish{ambient .1}}
  texture{t_distb}
  brick_size <1.5,30000000,1.5>
  mortar .7
  scale 101
  rotate -90*x
}
#declare t_distbuild3=
texture{
  brick
  texture{pigment{DarkTan} finish{ambient .1}}
  texture{t_distb}
  brick_size <1.5,30000000,1.5>
  mortar .7
  scale 101
  rotate -90*x
}
#declare t_distbuild4=
texture{
  brick
  texture{pigment{Gray} finish{ambient .1}}
  texture{t_distb}
  brick_size <1.5,30000000,1.5>
  mortar .7
  scale 101
  rotate -90*x
}
// distant city
#declare r_build=seed(258);
#declare r_build2=seed(47318);
#declare num_b=250;
#declare cnt_b=1;
#declare dist_builds=
union{
 #while (cnt_b<=num_b)
  #if (rand(r_build)>.25)
  box{-.5,.5
   #if (rand(r_build)>.25)
   rotate 45*y
   #end
  #else
  cylinder{<0,-.5,0>,<0,.5,0>,.5
  #end
   translate .5*y
   scale <1000+500*rand(r_build),1000+4000*rand(r_build),500+1500*rand(r_build)>
   translate <-20000+40000*rand(r_build),0,-5000+100000*rand(r_build)>
   #if (rand(r_build2)<.25)
    texture{t_distbuild1 translate 200*rand(r_build2)}
   #else
    #if (rand(r_build2)<.33)
     texture{t_distbuild2 translate 200*rand(r_build2)}
    #else
     #if (rand(r_build2)<.5)
      texture{t_distbuild3 translate 200*rand(r_build2)}
     #else
      texture{t_distbuild4 translate 200*rand(r_build2)}
     #end
    #end
   #end
  }
  #declare cnt_b=cnt_b+1;
 #end
}
// *** GLOW EFFECT FOR THE DISTANT BUILDINGS ***
#declare city_glow=
intersection{
 sphere{<0,0,0>,1}
 plane{y,0 inverse}
 hollow
 no_shadow
 material{
  texture{
   pigment { color rgbt <1,1,1,1>}
   finish { ambient 0 diffuse 0 }
  }
  interior{
   media {
    emission 0.00001
    intervals 10
    samples 1, 10
    confidence 0.9999
    variance 1/1000
    density {
      planar
      turbulence .1
      color_map {
        [0.0 Black]
        [0.1 lamp_color]
        [0.2 Black]
        [1.0 lamp_color*.5]
      }
      frequency 1
    }
   }
  }
 }
 scale <64000,4000,48000>
}
