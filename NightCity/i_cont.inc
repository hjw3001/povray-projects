//*** trash container

// textures
#declare t_cont_dirty=
texture{
 pigment{
  gradient y
  turbulence 0.8
  color_map{
   [0 Clear]
   [0.2 Clear]
   [0.2 DarkTan filter 0.5]
   [1 DarkTan/2 filter 0.7]
  }
  scale <40,100,40>
 }
 normal{dents 2 scale 2}
}
#declare t_cont_plastic=
texture{
 pigment{HuntersGreen+Green*.2}
 normal{granite .05 scale 2}
 finish{Phong_Shiny reflection 0.025}
}
texture{t_cont_dirty}
#declare t_cont_label=
texture{
 pigment{
  gradient y
  color_map{
   [0.0 color Red]
   [0.5 color Red]
   [0.5 color White]
   [1.0 color White]
  }
  translate -.5
  scale 12
  rotate 45*z
  translate 100*x
 }
 normal{granite .05}
 finish{Phong_Shiny reflection 0.05}
}
texture{t_cont_dirty}

// container body
#declare r_spk=seed(968);
#declare num_spk=20;
#declare cnt_spk=1;
#declare cont_body=
difference{
 intersection{
  superellipsoid{
   <.2,.2>
   rotate 90*x
   scale <55,50,40>
  }
  plane{y,45}
 }
 #while (cnt_spk<=num_spk)
  box{-1,1
   rotate <360*rand(r_spk),360*rand(r_spk),360*rand(r_spk)>
   translate <-55.5+rand(r_spk),-50+100*rand(r_spk),-40+80*rand(r_spk)>
  }
  box{-1,1
   rotate <360*rand(r_spk),360*rand(r_spk),360*rand(r_spk)>
   translate <55.5-rand(r_spk),-50+100*rand(r_spk),-40+80*rand(r_spk)>
  }
  box{-1,1
   rotate <360*rand(r_spk),360*rand(r_spk),360*rand(r_spk)>
   translate <-55+110*rand(r_spk),-50+100*rand(r_spk),-40.5+rand(r_spk)>
  }
  box{-1,1
   rotate <360*rand(r_spk),360*rand(r_spk),360*rand(r_spk)>
   translate <-55+110*rand(r_spk),-50+100*rand(r_spk),40.5-rand(r_spk)>
  }
  #declare cnt_spk=cnt_spk+1;
 #end
 texture{t_cont_plastic}
 bounded_by{box{<-55.1,-50.1,-40.1>,<55.1,50.1,40.1>}}
}

// container lid
#declare r_spk=seed(968);
#declare num_spk=20;
#declare cnt_spk=1;
#declare cont_lid=
difference{
 intersection{
  superellipsoid{
   <.2,.2>
   rotate 90*x
   scale <55,50,40>
   scale 1.05
   rotate -5*x
  }
  plane{y,45 inverse}
 }
 #while (cnt_spk<=num_spk)
  box{-1,1
   rotate <360*rand(r_spk),360*rand(r_spk),360*rand(r_spk)>
   translate <-55+110*rand(r_spk),50.5-rand(r_spk),-40+80*rand(r_spk)>
  }
  #declare cnt_spk=cnt_spk+1;
 #end
 texture{t_cont_plastic translate 40*y}
 translate 1*y
}

// label with red/white lines
#declare cont_label=
 intersection{
  intersection{
   superellipsoid{
    <.2,.2>
    rotate 90*x
    scale <55,50,40>
   }
   plane{y,45}
   scale 1.001
  }
  plane{y,20}
  plane{y,-20 inverse}
  plane{x,45 inverse}
  plane{z,-30}
  texture{t_cont_label}
 }

// wheels
#declare cont_wheels=
union{
 union{
  cylinder{<0,0,-1.5>,<0,0,1.5>,10 translate <-50,-60,-35>}
  cylinder{<0,0,-1.5>,<0,0,1.5>,10 translate < 50,-60,-35>}
  cylinder{<0,0,-1.5>,<0,0,1.5>,10 translate <-50,-60, 35>}
  cylinder{<0,0,-1.5>,<0,0,1.5>,10 translate < 50,-60, 35>}
  texture{pigment{Gray30}}
 }
 // wheel protectors
 union{
  intersection{
   union{
    cylinder{<0,0,-1.8>,<0,0,1.8>,11 translate <-50,-60,-35>}
    cylinder{<0,0,-1.8>,<0,0,1.8>,11 translate < 50,-60,-35>}
    cylinder{<0,0,-1.8>,<0,0,1.8>,11 translate <-50,-60, 35>}
    cylinder{<0,0,-1.8>,<0,0,1.8>,11 translate < 50,-60, 35>}
   }
   plane{y,-58 inverse}
  }
  cylinder{<0,-1,0>,<0,5,0>,3 translate <-45,-55,-30>}
  cylinder{<0,-1,0>,<0,5,0>,3 translate < 45,-55,-30>}
  cylinder{<0,-1,0>,<0,5,0>,3 translate <-45,-55, 30>}
  cylinder{<0,-1,0>,<0,5,0>,3 translate < 45,-55, 30>}
 }
 union{
  // side handles (for the machine)
  sphere{<0,0,0>,5 scale <0.3,1,1> translate <-55,10,0>}
  sphere{<0,0,0>,5 scale <0.3,1,1> translate < 55,10,0>}
  cylinder{<-54,10,0>,<-60,10,0>,3}
  cylinder{<-60,10,0>,<-63,10,0>,3.5}
  cylinder{<54,10,0>,<60,10,0>,3}
  cylinder{<60,10,0>,<63,10,0>,3.5}
 }
 texture{Chrome_Texture normal{dents}}
}

// *** make the container
#declare container=
union{
 object{cont_body}
 object{cont_label}
 object{cont_lid}
 object{cont_wheels}
}
