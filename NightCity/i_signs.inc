// *** traffic signals ***
#declare t_sign_dirt=
  texture{
   pigment{
    bozo turbulence .3
    color_map{
     [0.0 DarkTan filter 0.3]
     [0.1 Clear]
     [0.9 DarkTan filter 0.4]
     [1.0 Clear]
    }
   }
   finish{ambient .3}
   scale .5
  }
#declare vel_limit=
union{
 cylinder{
  <0,0,-.5>,<0,0,-.01>,.5
  texture{
   pigment{image_map{png "im_sign2" once}}
   translate -.5
   scale 1.15
  }
  texture{t_sign_dirt translate 100}
 }
 cylinder{
  <0,0,-.01>,<0,0,.01>,.49
  texture{T_Chrome_1B normal{bumps scale .5}}
  texture{t_sign_dirt translate 10}
 }
 scale <50,50,2>
}

#declare no_adv=
union{
 cylinder{
  <0,0,-.5>,<0,0,.5>,.45
  texture{
   pigment{image_map{png "im_sign3" once}}
   translate -.5
   scale 1.01
  }
  texture{t_sign_dirt translate 200}
 }
 cylinder{
  <0,0,-.01>,<0,0,.01>,.4
  texture{pigment{Gray}}
 }
 scale <55,55,2>
}

#declare no_park=
union{
 cylinder{
  <0,0,-.45>,<0,0,.45>,.45
  texture{
   pigment{image_map{png "im_sign4" once}}
   translate -.5
   scale 1.01
  }
  texture{t_sign_dirt translate 300}
 }
 cylinder{
  <0,0,-.01>,<0,0,.01>,.4
  texture{pigment{Gray}}
 }
 scale <50,50,2>
}
#declare precaucion=
box{-.5,.5
 texture{
   pigment{image_map{png "im_sign1" once}}
   translate -.5
   scale 1.01
 }
 texture{t_sign_dirt translate 400}
 scale <120,75,2>
}
