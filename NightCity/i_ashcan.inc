// *** TRASHCAN ***
#declare t_can=
texture{
 Aluminum
 normal {bumps -0.1 scale <1, 0.001, 0.001>}
 scale 5
 finish{Phong_Dull metallic reflection .1}
}
texture{
 pigment{
  bozo
  turbulence 0.3
  color_map{
   [0 Clear]
   [0.2 Clear]
   [0.2 DarkTan filter 0.8]
   [1 DarkTan/2 filter 0.9]
  }
  scale <20,85,20>
 }
 normal{dents 2 scale 2}
}
#declare can_height=80;
#declare can_rad_min=25;
#declare can_rad_maj=30;
#declare num_cyl=36;
#declare cnt_cyl=1;
#declare can_body=
union{
 difference{
  cone{
   <0,0,0>,can_rad_min,<0,can_height,0>,can_rad_maj
  }
  #while (cnt_cyl<=num_cyl)
   cylinder{
    <0,5,0>,<0,can_height-5,0>,4
    scale <1,1,.5>
    rotate -1*x
    translate -27.5*z
    rotate (360*cnt_cyl/num_cyl)*y
   }
   #declare cnt_cyl=cnt_cyl+1;
  #end
  torus{can_rad_min,.3}
  bounded_by{cylinder{<0,-0.1,0>,<0,can_height+.1,0>,can_rad_maj+.1}}
 }
 difference{
  torus{12,2 scale <0.3,1,1>}
  plane{x,0}
  translate <27,can_height-2,0>
 }
 difference{
  torus{12,2 scale <0.3,1,1>}
  plane{x,0 inverse}
  translate <-27,can_height-2,0>
 }
 texture{t_can rotate 90*z}
}
#declare can_cover=
union{
 cylinder{<0,can_height+.1,0>,<0,can_height+3,0>,can_rad_maj-1}
 intersection{
  cone{<0,can_height+3,0>,can_rad_maj-1,<0,can_height+8,0>,0.01}
  plane{y,can_height+6}
 }
 torus{12,2 rotate -90*x scale <1,0.3,1> translate (can_height+7)*y}
 texture{t_can}
}
#declare can=
union{
 difference{
  object{can_body}
  object{can_body scale 0.98 translate 2*y}
 }
 object{can_cover rotate 3*z}
}
