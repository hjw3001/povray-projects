// *** LEFT SIDEWALK ***
#macro lsidewalk(r_s)
#local r_ls=seed(rand(r_s));
#local num_br=10;
#local cnt_br=1;
union{
#while (cnt_br<=num_br)
 union{
  union{
   box{<450,0,-44.5>,<504.5,10,44.5> rotate <(-.125+.25*rand(r_ls)),(-.125+.25*rand(r_ls)),(-.125+.25*rand(r_ls))>}
   box{<505,0,-44.5>,<564.5,10,44.5> rotate <(-.125+.25*rand(r_ls)),(-.125+.25*rand(r_ls)),(-.125+.25*rand(r_ls))>}
   texture{
    pigment{Gray}
    normal{quilted 1 turbulence .1 scale 10 rotate 45*y}
   }
   texture{
    pigment{
     wrinkles
     turbulence 0.3
     lambda 3
     color_map{
      [0.0 DarkTan*.5 filter .5]
      [1.0 Clear]
     }
     scale 30
    }
    translate 1000*rand(r_ls)
   }
  }
  box{<565,0,-44.5>,<575,10,44.5> rotate <(-.125+.25*rand(r_ls)),(-.125+.25*rand(r_ls)),(-.125+.25*rand(r_ls))>
   texture{
    pigment{Gray*.5+Gray*.5*rand(r_ls)}
    normal{granite scale 4}
   }
   texture{
    pigment{
     wrinkles
     turbulence 0.3
     lambda 3
     color_map{
      [0.0 Tan]
      [1.0 Clear]
     }
     scale 30
    }
    translate 1000*rand(r_ls)
   }
  }
  translate (-450+45+90*(cnt_br-1))*z
 }
 #local cnt_br=cnt_br+1;
#end
}
#end
// *** RIGHT SIDEWALK ***
#macro rsidewalk(r_s)
#local r_rs=seed(rand(r_s));
#local num_br=10;
#local cnt_br=1;
union{
#while (cnt_br<=num_br)
 union{
  union{
   box{<-164.5,0,-44.5>,<-60.5,10,44.5> rotate <(-.125+.25*rand(r_rs)),(-.125+.25*rand(r_rs)),(-.125+.25*rand(r_rs))>}
   box{<-61,0,-44.5>,<0,10,44.5> rotate <(-.125+.25*rand(r_rs)),(-.125+.25*rand(r_rs)),(-.125+.25*rand(r_rs))>}
   texture{
    pigment{Gray}
    normal{quilted 1 turbulence .1 scale 10 rotate 45*y}
   }
   texture{
    pigment{
     wrinkles
     turbulence 0.3
     lambda 3
     color_map{
      [0.0 DarkTan filter .25]
      [1.0 Clear]
     }
     scale 30
    }
    translate 1000*rand(r_rs)
   }
  }
  box{<-175,0,-44.5>,<-165,10,44.5> rotate <(-.125+.25*rand(r_rs)),(-.125+.25*rand(r_rs)),(-.125+.25*rand(r_rs))>
   texture{
    pigment{Gray*.5+Gray*.5*rand(r_rs)}
    normal{granite scale 4}
   }
   texture{
    pigment{
     wrinkles
     turbulence 0.3
     lambda 3
     color_map{
      [0.0 Tan]
      [1.0 Clear]
     }
     scale 30
    }
    translate 1000*rand(r_rs)
   }
  }
  translate (-450+45+90*(cnt_br-1))*z
 }
 #local cnt_br=cnt_br+1;
#end
}
#end
// *** FABRIC WINDOW ***
#declare window=
union{
 union{
  difference{
   box{<-150,-50,-2>,<150,50,2>}
   box{<-150+2,-50+2,-3>,<150-2,50-2,3>}
  }
  box{<-150+2,-2,-2>,<150-2,2,2>}
  box{<-150+2,-25-2,-2>,<150-2,-25+2,2>}
  box{<-150+2,25-2,-2>,<150-2,25+2,2>}
  box{<-2,-50+2,-2>,<2,50-2,2>}
  box{<-50-2,-50+2,-2>,<-50+2,50-2,2>}
  box{<50-2,-50+2,-2>,<50+2,50-2,2>}
  box{<-100-2,-50+2,-2>,<-100+2,50-2,2>}
  box{<100-2,-50+2,-2>,<100+2,50-2,2>}
  texture{
   pigment{
    bozo turbulence .4
    color_map{
     [0.0 Flesh]
     [1.0 Tan]
    }
    scale 40
   }
   normal{granite scale 2}
  }
 }
 box{<-150+2,-50+2,-.1>,<150-2,50-2,.1>
  texture{Glass}
 }
}
// *** FABRIC ***
#macro fabric(r_fabric,ch)
#local t_fabric=
texture{
 pigment{
  brick color Flesh color Tan
 }
 normal{granite scale 4}
 scale <3,3,10>
}
texture{
 pigment{
  bozo
  turbulence 0.5
  lambda 3
  color_map{
   [0.0 White]
   [0.9 White]
   [0.9 Clear]
   [1.0 Clear]
  }
  scale 150
 }
 normal{bozo}
}
texture{
 pigment{
  wrinkles
  turbulence 0.3
  lambda 3
  color_map{
   [0.0 DarkTan filter .6]
   [1.0 Clear]
  }
  scale 80
 }
}
texture{
 pigment{
  gradient y
  turbulence 0.05
  color_map{
   [0.0 DarkTan*.5 filter 0.3]
   [0.5 Clear]
   [1.0 Clear]
  }
  scale 500
  translate 2*y
 }
}
union{
 union{
  difference{
   box{<-450,-1,-450>,<450,400,450>}
   box{<-445,0,-445>,<445,395,445>}
   box{<440,200,-375>,<455,300,-75>}
   box{<440,200,75>,<455,300,375>}
   box{<-440,200,-375>,<-455,300,-75>}
   box{<-440,200,75>,<-455,300,375>}
  }
  mesh{
   triangle{<450,400,-450>,<450,500,450>,<450,400,450>}
  }
  mesh{
   triangle{<-450,400,-450>,<-450,500,450>,<-450,400,450>}
  }
  texture{t_fabric translate 10000*rand(r_fabric)*x}
 }
 object{window rotate -90*y translate <444,250,-75-150>}
 object{window rotate -90*y translate <444,250,75+150>}
 object{window rotate 90*y translate <-444,250,-75-150>}
 object{window rotate 90*y translate <-444,250,75+150>}
 mesh{
  triangle{<450,400,-450>,<-450,400,-450>,<450,500,450>}
  triangle{<450,500,450>,<-450,500,450>,<-450,400,-450>}
  texture{pigment{brick color Flesh color Tan scale 4}}
 }
 #if (ch)
 cone{<0,0,0>,50,<0,1000,0>,25
  texture{pigment{brick color Flesh color Tan scale 4}}
 }
 object{chimey_smoke(50,5,20,White*.025,White*.05,20,<2,0,0>,seed(rand(r_fabric))) translate <0,1000,0>}
 #end
 object{lsidewalk(rand(seed(67)))}
}
#end
// *** WOOD WALL MACRO ***
#macro wall(r_w)
#local cnt_brd=1;
#local num_brd=10+int(3*rand(r_w));
#local sz=900/num_brd;
union{
#while (cnt_brd<=num_brd)
 box{
  <0+rand(r_w),0,-sz*.5+.2*rand(r_w)>,<10-rand(r_w),230+20*rand(r_w),sz*.5-.2*rand(r_w)>
  texture{T_Wood1 normal{wood scale .1}
   scale 12 rotate 90*x translate 100*rand(r_w)}
  texture{
   pigment{
    bozo
    turbulence 0.2
    color_map{
     [0.0 Clear]
     [1.0 DarkTan*.5 filter 0.5]
    }
    scale 200
   }
   translate 1000*rand(r_w)
  }
  texture{
   pigment{
    gradient y
    turbulence 0.05
    color_map{
     [0.0 DarkTan*.5 filter 0.5]
     [0.9 Clear]
     [1.0 Clear]
    }
    scale 250
    translate 20*y
   }
   translate 1000*rand(r_w)*x
  }
  rotate (-.5+rand(r_w))*z
  translate (-450+sz*.5+sz*(cnt_brd-1))*z
 }
 #if (rand(r_w)>.85)
  box{-.5,.5
   scale <.1,90,60>
   texture{
    pigment{
     image_map{png "im_ban1"}
     rotate 90*y
     scale 150
     translate 1000*rand(r_w)
    }
   }
   texture{
    pigment{
     bozo
     turbulence 0.6
     color_map{
      [0.0 rgb <rand(r_w),rand(r_w),rand(r_w)> filter 0.75]
      [0.6 DarkTan*.2 filter .5]
      [0.7 rgb <rand(r_w),rand(r_w),rand(r_w)> filter 0.75]
      [1.0 DarkTan*.5 filter .5]
     }
     scale 20
    }
    finish{Dull}
    translate 1000*rand(r_w)
   }
   translate <-.2,90+50*rand(r_w),-450+900*rand(r_w)>
  }
 #end
 #local cnt_brd=cnt_brd+1;
#end
 object{rsidewalk(rand(seed(467)))}
}
#end
// *** ROAD ***
#macro road(r_road)
#local t_asphalt=
texture{
 pigment{Gray30}
}
texture{
 pigment{
  crackle turbulence .3
  color_map{
   [0.0 Gray10]
   [0.01 DarkTan filter 0.6]
   [1.0 Clear]
  }
 }
 scale 500
}
texture{
 pigment{
  bozo turbulence .5
  color_map{
   [0.0 Gray20 filter .2]
   [0.2 DarkTan filter 0.6]
   [1.0 Clear]
  }
 }
 scale 150
}
texture{
 pigment{
  gradient x turbulence .01
  color_map{
   [0.0 Clear]
   [0.5 Gray filter 0.5]
   [1.0 Clear]
  }
 }
 normal{granite scale 2/150}
 scale 150
}
#local t_pyellow=
texture{
 pigment{Yellow*.8+White*.2}
}
texture{
 pigment{
  crackle turbulence .3
  color_map{
   [0.0 Gray10]
   [0.01 DarkTan filter 0.6]
   [1.0 Clear]
  }
 }
 normal{granite scale 2/150}
 scale 500
}
// *** ROAD OBJECT ***
union{
 box{<-400,-1,-450>,<400,0,450>
  texture{t_asphalt translate 10000*rand(r_road)*y}
 }
 box{<-265,-1,-450>,<-260,0.01,450>
  texture{t_pyellow translate 10000*rand(r_road)}
 }
 box{<270,-1,-450>,<275,0.01,450>
  texture{t_pyellow translate 10000*rand(r_road)}
 }
 box{<-10,-1,-450>,<-5,0.01,450>
  texture{t_pyellow translate 10000*rand(r_road)}
 }
 box{<5,-1,-450>,<10,0.01,450>
  texture{t_pyellow translate 10000*rand(r_road)}
 }
}
#end
// *** BANNERS ***
#declare pata=
union{
 box{<-4,0,0>,<4,360,4>}
 box{<-4,0,0>,<4,360,4> rotate -15*x translate 100*z}
 texture{pigment{DarkBrown} finish{metallic}}
}
#declare ad_1=
box{<-400,0,0>,<400,300,5>
 pigment{
  image_map{png "im_ban3"}
  translate -.5
  scale <800,300,1>
  translate <0,150,0>
 }
}
#declare ad_2=
box{<-400,0,0>,<400,300,5>
 pigment{
  image_map{png "im_ban1"}
  translate -.5
  scale <800,300,1>
  translate <0,150,0>
 }
}
#declare ad_3=
box{<-400,0,0>,<400,300,5>
 pigment{
  image_map{png "im_ban2"}
  translate -.5
  scale <800,300,1>
  translate <0,150,0>
 }
 finish{ambient .5}
}
#declare banner1=
union{
 difference{
  box{<-410,-10,-1>,<410,310,6>}
  box{<-400,0,-2>,<400,300,7>}
  pigment{Gray20} finish{Shiny}
  translate 270*y
 }
 object{ad_1
  translate 270*y
 }
 object{pata translate <-350,0,5>}
 object{pata translate < 350,0,5>}
 object{pata translate <-250,0,5>}
 object{pata translate < 250,0,5>}
 object{pata translate <-150,0,5>}
 object{pata translate < 150,0,5>}
 object{pata translate <-50,0,5>}
 object{pata translate < 50,0,5>}
 object{ltlamp scale .5 rotate -25*x translate < 100,270+310,-5>}
 object{ltlamp scale .5 rotate -25*x translate <-100,270+310,-5>}
 object{ltlamp scale .5 rotate -25*x translate < 300,270+310,-5>}
 object{ltlamp scale .5 rotate -25*x translate <-300,270+310,-5>}
}
#declare banner2=
union{
 difference{
  box{<-410,-10,-1>,<410,310,6>}
  box{<-400,0,-2>,<400,300,7>}
  pigment{Gray20} finish{Shiny}
  translate 270*y
 }
 object{ad_2
  translate 270*y
 }
 object{pata translate <-350,0,5>}
 object{pata translate < 350,0,5>}
 object{pata translate <-250,0,5>}
 object{pata translate < 250,0,5>}
 object{pata translate <-150,0,5>}
 object{pata translate < 150,0,5>}
 object{pata translate <-50,0,5>}
 object{pata translate < 50,0,5>}
 object{ltlamp scale .5 rotate -25*x translate < 100,270+310,-5>}
 object{ltlamp scale .5 rotate -25*x translate <-100,270+310,-5>}
 object{ltlamp scale .5 rotate -25*x translate < 300,270+310,-5>}
 object{ltlamp scale .5 rotate -25*x translate <-300,270+310,-5>}
}
