// *** macro to pose simple people on ramdom walking poses ***
#macro person(ang,r_pers)
#local t_cloth_u=
texture{
 pigment{rgb <rand(r_pers),rand(r_pers),rand(r_pers)>}
 normal{wrinkles}
}
#local t_cloth_l=
texture{
 pigment{rgb .1+rand(r_pers)*.5}
 normal{quilted}
}
#local t_skin=texture{pigment{Pink*.25+Orange*.25+Flesh*.5}}
#local p1=<0,155,0>;
#local p2a=<-15,138,0>;
#local p2b=<15,138,0>;
#local p3=<0,118,0>;
#local p4=<0,90,0>;
#local p5a=<-9,82,0>;
#local p5b=<9,82,0>;
#declare cabeza=
union{
 sphere{0,.5 scale <15,20,20> texture{t_skin}}
 intersection{
  sphere{0,.501 scale <15,20,20>}
  plane{y,5 inverse}
  texture{pigment{DarkBrown}}
 }
 intersection{
  sphere{0,.501 scale <15,20,20>}
  plane{y,5}
  plane{z,0 inverse}
  texture{pigment{DarkBrown}}
 }
}
#declare brazo_i=
union{
 cone{<0,0,0>,3.5,<0,-30,0>,3
  texture{t_cloth_u}
 }
 union{
  cone{<0,0,0>,3,<0,-28,0>,2
   texture{t_cloth_u}
  }
  box{-.5,.5
   scale <7,12,2>
   texture{t_skin}
   translate (-28-6)*y
  }
  rotate ang*x
  translate -30*y
 }
}
#declare brazo_d=object{brazo_i}
#declare cuerpo=
superellipsoid{<.1,.1>
 rotate 90*x
 scale .45
 scale <33,40,12>
 texture{t_cloth_u}
}
#declare pelvis=
cylinder{
 <-13,0,0>,<13,0,0>,8
 texture{t_cloth_l}
}
#declare pierna_i=
union{
 cone{<0,0,0>,7,<0,-35,0>,5}
 union{
  cone{<0,0,0>,5,<0,-35,0>,3}
  intersection{
   box{-.5,.5}
   plane{y,0 rotate -10*x}
   scale <10,10,28> translate <0,-35,-12>
  }
  rotate -ang*x translate -35*y
 }
 texture{t_cloth_l}
}
#declare pierna_d=object{pierna_i}
union{
 object{cabeza scale 1.1 translate p1}
 object{brazo_i rotate ang*x translate p2a}
 object{brazo_d rotate -ang*x translate p2b}
 object{cuerpo translate p3}
 object{pelvis translate p4}
 object{pierna_i rotate -ang*x translate p5a}
 object{pierna_d rotate ang*x translate p5b}
 translate -6*y
}
#end

