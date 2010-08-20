// *** macro coche()
//
// parametros :
//
// + textura de la pintura exterior
// + encendido de las luces (on/off)
// + angulo de las ruedas delanteras

#macro coche(t_pintura_exterior,luces,angulo_ruedas)

// *** debug control ***
#declare test_text=0;
#declare usar_chasis=1;
#declare usar_ruedas=1;
#declare usar_carroc=1;
#declare manual_bound=1;

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
 Polished_Chrome
}
#declare t_metal_chasis=
texture{
 Rusty_Iron
}
#declare t_cristal_luna=
texture{
 pigment{Gray10}
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
#declare ancho_rueda=25;
#declare radio_rueda=55.3*.5;
#declare ancho_llanta=18.5;
#declare radio_llanta=38.0*.5;
#declare ancho_coche=172.0;
#declare largo_coche=360.0;
#declare alto_coche=151.0;
#declare altura_bajos=20;
#declare altura_capo=50;
#declare dist_ejed=largo_coche*.5-80;
#declare dist_ejet=largo_coche*.5-70;
#declare radio_eje=2;
#declare pos_rdi=<-ancho_coche*.5+ancho_rueda*.5,radio_rueda,-dist_ejed>;
#declare pos_rdd=< ancho_coche*.5-ancho_rueda*.5,radio_rueda,-dist_ejed>;
#declare pos_rti=<-ancho_coche*.5+ancho_rueda*.5,radio_rueda, dist_ejet>;
#declare pos_rtd=< ancho_coche*.5-ancho_rueda*.5,radio_rueda, dist_ejet>;

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
 <-ancho_coche*.5+ancho_rueda,0,0>
 < ancho_coche*.5-ancho_rueda,0,0>
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
  torus{radio_rueda*1.1,5 rotate -90*z scale <.6,1,1>
   texture{t_pintura_exterior}
  }
  cylinder{<-6,0,0>,<6,0,0>,radio_rueda*1.1
   texture{t_pintura_interior}
  }
 }
 plane{y,-radio_rueda+altura_bajos inverse
  texture{t_pintura_exterior}
 }
}
#declare retrovisor=
 union{
  intersection{
   difference{
    sphere{0,1}
    sphere{0,.9}
   }
   plane{z,.2}
   scale <14,7,7>
   texture{t_pintura_exterior}
  }
  intersection{
   sphere{0,.9}
   plane{z,.1}
   scale <14,7,7>
   texture{finish{Mirror}}
  }
}
#declare faro=
sphere{0,1 scale <40,10,25>}
#declare piloto=
sphere{0,1 scale <40,12,25>}
#declare luz_faro=
union{
 light_source{
  0
  White+Gold
  fade_distance 1600
  fade_power 4
  spotlight
  radius 5
  falloff 10
  tightness 2
  point_at <0, -altura_capo, -800>
 }
/*
 cone{<0,0,-10>,5,<0,-altura_capo,-400>,80
  pigment{
   gradient z
   color_map{
    [0.0 White*.9+Gold*.2 filter 0.9]
    [0.9 Clear]
    [1.0 Clear]
   }
   scale 450
  }
  finish{Luminous}
  hollow
  no_shadow
 }
 */
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
  scale 10
 }
}
#declare carroceria=
union{
 // parte baja comun
 intersection{
  difference{
   superellipsoid{
    <.3,.5>
    rotate -90*x
    scale .5
    scale <ancho_coche,alto_coche-altura_bajos,largo_coche>
    texture{t_pintura_exterior}
    translate ((alto_coche-altura_bajos)*.5)*y
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda,-dist_ejed>
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda, dist_ejet>
   }
   box{<-ancho_coche*.2,-.5,-10>,<ancho_coche*.2,.5,20>
    texture{t_pintura_interior}
    translate <0,altura_capo-5.5,-largo_coche*.5>
   }
   superellipsoid{
    <.2,.2>
    scale .5
    scale <47,12,4>
    texture{t_pintura_exterior}
    translate <0,altura_capo,largo_coche*.5>
   }
   union{
    object{faro translate <( ancho_coche*.5-10),altura_capo-5,-largo_coche*.5+5>}
    object{faro translate <(-ancho_coche*.5+10),altura_capo-5,-largo_coche*.5+5>}
    object{piloto translate <( ancho_coche*.5-10),altura_capo-5,largo_coche*.5-5>}
    object{piloto translate <(-ancho_coche*.5+10),altura_capo-5,largo_coche*.5-5>}
    texture{t_metal_faro}
   }
  }
  plane{y, altura_bajos inverse
   texture{t_pintura_interior}
  }
  plane{y, altura_capo
   texture{t_pintura_exterior}
  }
  #if (manual_bound)
  bounded_by{
   box{
    <-ancho_coche*.5-2,altura_bajos-.1,-largo_coche*.5-2>
    <ancho_coche*.5+2,altura_capo+.1,largo_coche*.5+2>
   }
  }
  #end
 }
 // Morro
 intersection{
  difference{
   superellipsoid{
    <.3,.9>
    rotate -90*x
    scale .5
    scale <ancho_coche,(alto_coche-altura_bajos)*.5,largo_coche>
    texture{t_pintura_exterior}
    translate ((alto_coche-altura_bajos)*.4)*y
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda,-dist_ejed>
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda, dist_ejet>
   }
   box{<-ancho_coche*.2,-.5,-10>,<ancho_coche*.2,.5,20>
    texture{t_pintura_interior}
    translate <0,altura_capo-5.5,-largo_coche*.5>
   }
   union{
    object{faro translate <( ancho_coche*.5-10),altura_capo-5,-largo_coche*.5+5>}
    object{faro translate <(-ancho_coche*.5+10),altura_capo-5,-largo_coche*.5+5>}
    texture{t_metal_faro}
   }
  }
  plane{y, altura_capo inverse
   texture{t_pintura_exterior}
  }
  plane{z,dist_ejet-10
   texture{t_pintura_exterior}
  }
  #if (manual_bound)
  bounded_by{
   box{
    <-ancho_coche*.5-2,altura_capo-.1,-largo_coche*.5-2>
    <ancho_coche*.5+2,altura_capo+30,dist_ejet-10+.1>
   }
  }
  #end
 }
 // faros
 intersection{
  union{
   object{faro scale 0.98 translate <( ancho_coche*.5-10),altura_capo-5,-largo_coche*.5+5>}
   object{faro scale 0.98 translate <(-ancho_coche*.5+10),altura_capo-5,-largo_coche*.5+5>}
  }
  superellipsoid{
   <.3,.9>
   rotate -90*x
   scale .5
   scale <ancho_coche,(alto_coche-altura_bajos)*.5,largo_coche>
   translate ((alto_coche-altura_bajos)*.4)*y
  }
  superellipsoid{
   <.3,.5>
   rotate -90*x
   scale .5
   scale <ancho_coche,alto_coche-altura_bajos,largo_coche>
   translate ((alto_coche-altura_bajos)*.5)*y
  }
  hollow
  material{m_cristal_faro}
  #if (manual_bound)
  bounded_by{
   union{
    sphere{0,1 scale <40.1,10.1,25.1> translate <( ancho_coche*.5-10),altura_capo-5,-largo_coche*.5+5>}
    sphere{0,1 scale <40.1,10.1,25.1> translate <(-ancho_coche*.5+10),altura_capo-5,-largo_coche*.5+5>}
   }
  }
  #end
 }
 // luces faros
 #if (luces)
 object{luz_faro translate <( ancho_coche*.5-20),altura_capo-3,-largo_coche*.5+5>}
 object{luz_faro translate <(-ancho_coche*.5+20),altura_capo-3,-largo_coche*.5+5>}
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
  translate <0,altura_capo-13,-largo_coche*.5-2>
 }
 // trasera
 intersection{
  difference{
   superellipsoid{
    <.3,.5>
    rotate -90*x
    scale .5
    scale <ancho_coche,(alto_coche-altura_bajos)*.7,largo_coche>
    texture{t_pintura_exterior}
    translate (altura_capo-10)*y
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda,-dist_ejed>
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda, dist_ejet>
   }
   superellipsoid{
    <.2,.2>
    scale .5
    scale <47,12,4>
    texture{t_pintura_exterior}
    translate <0,altura_capo,largo_coche*.5>
   }
   union{
    object{piloto translate <( ancho_coche*.5-10),altura_capo-5,largo_coche*.5-5>}
    object{piloto translate <(-ancho_coche*.5+10),altura_capo-5,largo_coche*.5-5>}
    texture{t_metal_faro}
   }
  }
  plane{y, altura_capo inverse
   texture{t_pintura_exterior}
  }
  plane{z,dist_ejet inverse
   texture{t_pintura_exterior}
  }
  #if (manual_bound)
  bounded_by{
   box{
    <-ancho_coche*.5-2,altura_capo-.1,dist_ejet-1>
    <ancho_coche*.5+2,altura_capo+50,largo_coche*.5+2>
   }
  }
  #end
 }
 intersection{
  difference{
   superellipsoid{
    <.3,.5>
    rotate -90*x
    scale .5
    scale <ancho_coche,(alto_coche-altura_bajos)*.7,largo_coche>
    texture{t_pintura_exterior}
    translate (altura_capo-10)*y
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda,-dist_ejed>
   }
   cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
    texture{t_pintura_interior}
    translate <0,radio_rueda, dist_ejet>
   }
   superellipsoid{
    <.2,.2>
    scale .5
    scale <47,12,4>
    texture{t_pintura_exterior}
    translate <0,altura_capo,largo_coche*.5>
   }
   union{
    object{piloto translate <( ancho_coche*.5-10),altura_capo-5,largo_coche*.5-5>}
    object{piloto translate <(-ancho_coche*.5+10),altura_capo-5,largo_coche*.5-5>}
    texture{t_metal_faro}
   }
  }
  plane{y, altura_capo inverse
   texture{t_pintura_exterior}
  }
  plane{z,dist_ejet inverse
   texture{t_pintura_exterior}
  }
  #if (manual_bound)
  bounded_by{
   box{
    <-ancho_coche*.5-2,altura_capo-.1,dist_ejet-1>
    <ancho_coche*.5+2,altura_capo+50,largo_coche*.5+2>
   }
  }
  #end
  rotate 180*y
  translate (dist_ejet*2)*z
 }
 // pilotos
 intersection{
  union{
   object{piloto translate <( ancho_coche*.5-10),altura_capo-5,largo_coche*.5-5>}
   object{piloto translate <(-ancho_coche*.5+10),altura_capo-5,largo_coche*.5-5>}
  }
  superellipsoid{
   <.3,.5>
   rotate -90*x
   scale .5
   scale <ancho_coche,(alto_coche-altura_bajos)*.7,largo_coche>
   translate (altura_capo-10)*y
  }
  superellipsoid{
   <.3,.5>
   rotate -90*x
   scale .5
   scale <ancho_coche,alto_coche-altura_bajos,largo_coche>
   translate ((alto_coche-altura_bajos)*.5)*y
  }
  texture{t_cristal_piloto}
  #if (manual_bound)
  bounded_by{
   union{
    sphere{0,1 scale <40.1,10.1,25.1> translate <( ancho_coche*.5-10),altura_capo-5,largo_coche*.5-5>}
    sphere{0,1 scale <40.1,10.1,25.1> translate <(-ancho_coche*.5+10),altura_capo-5,largo_coche*.5-5>}
   }
  }
  #end
 }
 // luces pilotos
 #if (luces)
 light_source{
  0
  Red*.5
  fade_distance 100
  fade_power 4
  translate <( ancho_coche*.5-10),altura_capo-3,largo_coche*.5-10>
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
  translate <( ancho_coche*.5-25),altura_capo-3,largo_coche*.5>
 }
 light_source{
  0
  Red*.5
  fade_distance 100
  fade_power 4
  translate <(-ancho_coche*.5+10),altura_capo-3,largo_coche*.5-10>
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
  translate <(-ancho_coche*.5+25),altura_capo-3,largo_coche*.5>
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
  translate <0,altura_capo,largo_coche*.5-2>
 }
 // paragolpes
 difference{
  superellipsoid{
   <.3,.4>
   rotate -90*x
   scale .5
   scale <ancho_coche+2,20,largo_coche+4>
   texture{t_pintura_exterior}
   translate (altura_capo-13)*y
  }
  superellipsoid{
   <.3,.4>
   rotate -90*x
   scale .5
   scale <ancho_coche+2,20,largo_coche+4>
   scale <0.99,1.1,0.99>
   texture{t_pintura_exterior}
   translate (altura_capo-13)*y
  }
  cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
   texture{t_pintura_interior}
   translate <0,radio_rueda,-dist_ejed>
  }
  cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
   texture{t_pintura_interior}
   translate <0,radio_rueda, dist_ejet>
  }
  #if (manual_bound)
  bounded_by{
   box{
    <-ancho_coche*.5-2,altura_capo-13-11,-largo_coche*.5-3>
    <ancho_coche*.5+2,altura_capo-13+11,largo_coche*.5+3>
   }
  }
  #end
 }
 // spoiler bajos
 difference{
  superellipsoid{
   <.3,.4>
   rotate -90*x
   scale .5
   scale <ancho_coche*.98,10,largo_coche*.95>
   texture{t_pintura_exterior}
   translate (altura_bajos)*y
  }
  superellipsoid{
   <.3,.4>
   rotate -90*x
   scale .5
   scale <ancho_coche*.98,10,largo_coche*.95>
   scale <0.99,1.1,0.99>
   texture{t_pintura_exterior}
   translate (altura_bajos)*y
  }
  cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
   texture{t_pintura_interior}
   translate <0,radio_rueda,-dist_ejed>
  }
  cylinder{<-ancho_coche*.51,0,0>,<ancho_coche*.51,0,0>,radio_rueda*1.1
   texture{t_pintura_interior}
   translate <0,radio_rueda, dist_ejet>
  }
  #if (manual_bound)
  bounded_by{
   box{
    <-ancho_coche*.5,altura_bajos-6,-largo_coche*.5>
    < ancho_coche*.5,altura_bajos+6,largo_coche*.5>
   }
  }
  #end
 }
 // cristal
 intersection{
  intersection{
   sphere{0,.5 scale <ancho_coche,80,largo_coche*.7>}
   // lunas laterales
   sphere{0,.5 scale <ancho_coche*.96,172,largo_coche> translate <0,-35,0>}
   // luna trasera
   sphere{0,.5 scale <ancho_coche*1.1,180,largo_coche> translate <0,-35,-45>}
   // parabrisas
   sphere{0,.5 scale <ancho_coche*1.1,160,largo_coche*.9> rotate -2*x translate <0,-30,35>}
   rotate -4*x
  }
  plane{y,31}
  scale <1,1,1.1>
  translate <0,(altura_capo+16),30>
  texture{t_cristal_luna}
 }
 // techo
 intersection{
  intersection{
   sphere{0,.5 scale <ancho_coche,80,largo_coche*.7>}
   sphere{0,.5 scale <ancho_coche*.96,172,largo_coche> translate <0,-35,0>}
   sphere{0,.5 scale <ancho_coche*1.1,180,largo_coche> translate <0,-35,-45>}
   sphere{0,.5 scale <ancho_coche*1.1,160,largo_coche*.9> rotate -2*x translate <0,-30,35>}
   rotate -4*x
  }
  plane{y,31 inverse}
  scale <1,1,1.1>
  translate <0,(altura_capo+16),30>
  texture{t_pintura_exterior}
 }
 // retrovisor
 object{retrovisor rotate -5*y translate <ancho_coche*.51,altura_capo+19,-25>}
 object{retrovisor rotate  5*y translate <-ancho_coche*.51,altura_capo+19,-25>}
 // spoilers ruedas
 object{sp_ruedas rotate -7*z translate < ancho_coche*.47,radio_rueda,-dist_ejed>}
 object{sp_ruedas rotate  7*z translate <-ancho_coche*.47,radio_rueda,-dist_ejed>}
 object{sp_ruedas rotate -7*z translate < ancho_coche*.47,radio_rueda, dist_ejet>}
 object{sp_ruedas rotate  7*z translate <-ancho_coche*.47,radio_rueda, dist_ejet>}
 // aleron?
}
#end

// *** devuelve el coche montado ***
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

#end // fin de la macro coche()
