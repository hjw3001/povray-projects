// *** macro camion()
//
// parametros :
//
// + textura de la pintura exterior
// + encendido de las luces (on/off)
// + angulo de las ruedas delanteras

#macro camion(t_pintura_exterior,luces,angulo_ruedas)

// *** debug control ***
#declare test_text=0;
#declare usar_chasis=1;
#declare usar_ruedas=1;
#declare usar_carroc=1;
#declare manual_bound=0;

// *** texturas fijas ***
#if (test_text)
// *** test textures ***
#declare t_pintura_interior=
texture{pigment{DarkTan*.5}}
#declare t_goma_rueda=
texture{pigment{Gray30}}
#declare t_metal_llanta=
texture{pigment{Gray}}
#declare t_metal_chasis=
texture{Rusty_Iron}
#declare t_cristal_luna=
//texture{pigment{Gray}}
texture{Glass}
#declare m_cristal_faro=
material{texture{pigment{White}}}
#declare t_cristal_piloto=
texture{pigment{Red}}
#declare t_metal_faro=
texture{pigment{Gray}}
#else
// *** final textures ***
#declare t_pintura_interior=
texture{
 pigment{DarkTan*.5}
 normal{granite}
}
#declare t_goma_rueda=
texture{
 pigment{Gray20}
}
#declare t_metal_llanta=
texture{
 T_Chrome_2A
}
#declare t_metal_chasis=
texture{
 Rusty_Iron
}
#declare t_cristal_luna=
texture{
 pigment{Gray10}
 normal{bumps .1 scale 50}
 finish{Mirror}
}
#declare m_cristal_faro=
material{
 texture{
  pigment{
   #if (luces)
    rgbt 1
   #else
    rgbf 1
   #end
  }
  finish {
   ambient 0
   diffuse 0
   reflection 0.5
   phong 0.3
   phong_size 60
  }
 }
 interior{
  ior 1.5
  #if (luces)
   media{
    intervals 1
    samples 2, 4
    emission .1
    density {
     spherical
     cubic_wave
     turbulence .1
     color_map {
      [0.0 Gold*.1+White*.1]
      [1.0 White*.1]
     }
     frequency 1
    }
   }
  #end
 }
}
#declare t_cristal_piloto=
texture{
 Ruby_Glass
 normal{gradient y scale .1}
 #if (luces)
  finish{ambient .5}
 #end
}
#declare t_metal_faro=
texture{Chrome_Texture}
#end

// *** medidas de control ***
#declare ancho_rueda=20;
#declare radio_rueda=60*.5;
#declare ancho_llanta=19.5;
#declare radio_llanta=44.0*.5;
#declare ancho_camion=200.0;
#declare largo_camion=460.0;
#declare alto_camion=251.0;
#declare altura_bajos=30;
#declare altura_capo=70;
#declare dist_ejed=largo_camion*.5-80;
#declare dist_ejet=largo_camion*.5-70;
#declare radio_eje=2;
#declare pos_rdi=<-ancho_camion*.5+ancho_rueda*.5,radio_rueda,-dist_ejed>;
#declare pos_rdd=< ancho_camion*.5-ancho_rueda*.5,radio_rueda,-dist_ejed>;
#declare pos_rti=<-ancho_camion*.5+ancho_rueda*.5,radio_rueda, dist_ejet>;
#declare pos_rtd=< ancho_camion*.5-ancho_rueda*.5,radio_rueda, dist_ejet>;

// *** ruedas ***
#if (usar_ruedas)
#declare neumatico=
union{
 difference{
  superellipsoid{
   <1,.2>
   rotate 90*y
   scale <ancho_rueda*.5,radio_rueda,radio_rueda>
  }
  cylinder{
   <-ancho_rueda*.6,0,0>
   < ancho_rueda*.6,0,0>
   radio_llanta+.1
  }
  texture{t_goma_rueda
   scale <ancho_rueda*.5,radio_rueda,radio_rueda>
  }
 }
 torus{
  radio_rueda-5,4.8
  rotate 90*z
  scale <0.8,1,1>
  translate -ancho_rueda*.45*x
  texture{t_goma_rueda}
 }
}
#declare llanta=
height_field{
 png "llanta2"
 water_level 0.1
 translate -.5
 rotate -90*x
 rotate  90*y
 scale <6,radio_llanta*2,radio_llanta*2>
 texture{t_metal_llanta}
}
#declare conjunto_rueda=
cylinder{
 <-.5,0,0>,<.5,0,0>,radio_llanta*.8
 texture{Brass_Metal}
}
#declare rueda=
union{
 object{neumatico}
 object{llanta translate -ancho_rueda*.5*x}
 object{conjunto_rueda}
}
#declare ruedas=
union{
 object{rueda rotate angulo_ruedas*y translate pos_rdi} // delantera izquierda
 object{rueda rotate (180+angulo_ruedas)*y translate pos_rdd}
 object{rueda translate pos_rti}
 object{rueda rotate 180*y translate pos_rtd}
}
#end

// *** chasis ***
#if (usar_chasis)
#declare eje=
cylinder{
 <-ancho_camion*.5+ancho_rueda,0,0>
 < ancho_camion*.5-ancho_rueda,0,0>
 radio_eje
 texture{t_metal_chasis}
}
#declare chasis=
union{
 object{eje translate <0,radio_rueda,-dist_ejed>}
 object{eje translate <0,radio_rueda, dist_ejet>}
}
#end

// *** carroceria ***
#if (usar_carroc)
#declare sp_ruedas=
intersection{
 difference{
  torus{radio_rueda*1.1,5 rotate -90*z scale <2,1,1>
   texture{t_metal_llanta}
  }
  cylinder{<-6,0,0>,<6,0,0>,radio_rueda*1.1
   texture{t_pintura_interior}
  }
 }
 plane{y,-radio_rueda+altura_bajos inverse
  texture{t_metal_llanta}
 }
}
#declare faro=
sphere{0,1 scale <40,10,25>}
#declare piloto=
sphere{0,1 scale <40,12,25>}
#declare luz_faro=
union{
 torus{10,1
  texture{t_metal_llanta}
  rotate 90*x
 }
 light_source{
  0
  White+Gold
  fade_distance 1000
  fade_power 8
  spotlight
  radius 10
  falloff 19
  tightness 2
  point_at <0, -altura_capo, -300>
 }
 cone{<0,0,-10>,5,<0,-altura_capo,-300>,80
  pigment{
   gradient z
   color_map{
    [0.0 White*.9+Gold*.2 filter 0.9]
    [0.9 Clear]
    [1.0 Clear]
   }
   scale 350
  }
  finish{Luminous}
  hollow
  no_shadow
 }
 sphere{<0,0,0>,1
  pigment { color rgbf<1, 1, 1, 1> }
  finish { ambient 0 diffuse 0 }
  interior{
   media {
    emission 0.05
    intervals 10
    samples 1, 10
    confidence 0.9999
    variance 1/1000
    density {
     spherical
     cubic_wave
     turbulence .1
     color_map {
      [0.0 Black]
      [0.4 Gold*.2]
      [1.0 Gold+White*.5]
     }
     frequency 1
    }
   }
  }
  no_shadow
  hollow
  scale 30
 }
}
#declare galibo=
union{
 torus{10,1
  texture{t_metal_llanta}
  rotate 90*x
 }
 sphere{<0,0,0>,1
  pigment { color rgbf<1, 1, 1, 1> }
  finish { ambient 0 diffuse 0 }
  interior{
   media {
    emission 0.05
    intervals 10
    samples 1, 10
    confidence 0.9999
    variance 1/1000
    density {
     spherical
     cubic_wave
     turbulence .1
     color_map {
      [0.0 Black]
      [0.4 Gold*.2]
      [1.0 Gold+White*.5]
     }
     frequency 1
    }
   }
  }
  no_shadow
  hollow
  scale 30
 }
 scale .4
}
#declare retro=
union{
 cylinder{<0,9,-.5>,<0,9,.5>,6}
 cylinder{<0,3,-.5>,<0,3,.5>,6}
 cylinder{<0,-3,-.5>,<0,-3,.5>,6}
 cylinder{<0,-9,-.5>,<0,-9,.5>,6}
 texture{t_pintura_interior}
}
#declare cabina_base=
intersection{
 box{
  -.5,.5
  scale <ancho_camion*.9,altura_capo,largo_camion*.3>
 }
 plane{y,0 rotate -60*x translate -50*z}
 plane{x,0 rotate 10*z translate ancho_camion*.4*x}
 plane{x,0 inverse rotate -10*z translate -ancho_camion*.4*x}
}
#declare cabina=
union{
 difference{
  object{cabina_base}
  object{cabina_base scale <1.1,.85,.85>}
  object{cabina_base scale <.85,.85,1.1>}
  texture{t_pintura_exterior}
 }
 superellipsoid{<.1,.5>
  rotate -90*x
  scale .5
  scale <ancho_camion*.7,20,largo_camion*.1>
  rotate -35*x
  texture{t_pintura_exterior}
  translate altura_capo*.7*y
 }
 object{retro translate < ancho_camion*.45,-10,-largo_camion*.1>}
 object{retro translate <-ancho_camion*.45,-10,-largo_camion*.1>}
}
#declare cristal_cabina=
object{cabina_base scale .9
 texture{t_cristal_luna}
}
#declare rejilla=
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
  texture{t_pintura_interior}
 }
 box{<-150,-50,1>,<150,50,2>
  texture{t_pintura_exterior}
 }
 scale <.3,.2,.5>
}
#declare parachoques=
box{
 -.5,.5
 scale <ancho_camion,10,30>
 texture{t_metal_llanta}
}
#declare carroceria=
union{
 // caja
 superellipsoid{
  <.1,.1>
  rotate 90*x
  scale .5
  scale <ancho_camion,alto_camion-altura_bajos,largo_camion*.6>
  texture{t_pintura_exterior}
  translate <0,(alto_camion-altura_bajos)*.5+altura_bajos,largo_camion*.2>
 }
 // morro
 intersection{
  box{
   -.5,.5
   scale <ancho_camion*.9,altura_capo,largo_camion*.5>
  }
  plane{y,0 rotate -40*x translate <0,10,-110>}
  texture{t_pintura_exterior}
  translate <0,altura_capo*.5+altura_bajos,-largo_camion*.5+largo_camion*.3>
 }
 object{cabina
  translate <0,altura_capo*1.5+altura_bajos,-largo_camion*.5+largo_camion*.3>
 }
 object{cristal_cabina
  translate <0,altura_capo*1.5+altura_bajos,-largo_camion*.5+largo_camion*.3>
 }
 object{parachoques translate <0,altura_bajos,-largo_camion*.45>}
 object{parachoques translate <0,altura_bajos,largo_camion*.46>}
 object{rejilla translate <-5,altura_bajos+25,-largo_camion*.47>}
 object{rejilla translate <5,altura_bajos+25,-largo_camion*.47>}
 // luces faros
 #if (luces)
 object{luz_faro translate <( ancho_camion*.5-25),altura_capo-24,-largo_camion*.5+22>}
 object{luz_faro translate <(-ancho_camion*.5+25),altura_capo-24,-largo_camion*.5+22>}
 object{galibo translate <( ancho_camion*.5-20),alto_camion-24,-largo_camion*.12>}
 object{galibo translate <(-ancho_camion*.5+20),alto_camion-24,-largo_camion*.12>}
 #end
 // matricula delantera
 box{-.5,.5
  texture{
   pigment{
    image_map{png "im_matri"}
   }
   finish{F_MetalA}
   translate -.5
  }
  scale <44,9,.5>
  translate <0,altura_bajos,-largo_camion*.5+4>
 }
 // luces pilotos
 #if (luces)
 light_source{
  0
  Red*.5
  fade_distance 100
  fade_power 4
  translate <( ancho_camion*.5-10),altura_capo-3,largo_camion*.5>
 }
 sphere{<0,0,0>,1
  pigment { color rgbf<1, 1, 1, 1> }
  finish { ambient 0 diffuse 0 }
  interior{
   media {
    emission 0.05
    intervals 10
    samples 1, 10
    confidence 0.9999
    variance 1/1000
    density {
     spherical
     cubic_wave
     turbulence .1
     color_map {
      [0.0 Black]
      [1.0 OrangeRed*.5+Red*.5]
     }
     frequency 1
    }
   }
  }
  no_shadow
  hollow
  scale 20
  translate <( ancho_camion*.5-10),altura_capo-3,largo_camion*.5>
 }
 light_source{
  0
  Red*.5
  fade_distance 100
  fade_power 4
  translate <(-ancho_camion*.5+10),altura_capo-3,largo_camion*.5>
 }
 sphere{<0,0,0>,1
  pigment { color rgbf<1, 1, 1, 1> }
  finish { ambient 0 diffuse 0 }
  interior{
   media {
    emission 0.05
    intervals 10
    samples 1, 10
    confidence 0.9999
    variance 1/1000
    density {
     spherical
     cubic_wave
     turbulence .1
     color_map {
      [0.0 Black]
      [1.0 OrangeRed*.5+Red*.5]
     }
     frequency 1
    }
   }
  }
  no_shadow
  hollow
  scale 20
  translate <(-ancho_camion*.5+10),altura_capo-3,largo_camion*.5>
 }
 #end
 // matricula trasera
 box{-.5,.5
  texture{
   pigment{
    image_map{png "im_matri"}
   }
   finish{F_MetalA}
   translate -.5
  }
  rotate 180*y
  scale <44,9,.5>
  translate <0,altura_bajos,largo_camion*.5+1>
 }
 // spoilers ruedas
 object{sp_ruedas rotate -7*z translate < ancho_camion*.47,radio_rueda,-dist_ejed>}
 object{sp_ruedas rotate  7*z translate <-ancho_camion*.47,radio_rueda,-dist_ejed>}
 object{sp_ruedas rotate -7*z translate < ancho_camion*.47,radio_rueda, dist_ejet>}
 object{sp_ruedas rotate  7*z translate <-ancho_camion*.47,radio_rueda, dist_ejet>}
}
#end

// *** devuelve el camion montado ***
union{
 #if (usar_ruedas)
  object{ruedas}
 #end
 #if (usar_chasis)
  object{chasis}
 #end
 #if (usar_carroc)
  object{carroceria}
 #end
}

#end // fin de la macro camion()
