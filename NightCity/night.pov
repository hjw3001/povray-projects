/*

  "NIGTH CITY", IRTC 03-04-2000, topic "The City".

  Jaime Vives Piqueres, (?)2000.

*/

#version 3.1;
global_settings{
// ambient_light 4
 max_trace_level 64
}


// *** STANDARD INCLUDES ***
#include "colors.inc"
#include "textures.inc"
#include "woods.inc"
#include "metals.inc"
#include "skies.inc"
#include "consts.inc"


// *** OWN INCLUDES ***
#include "i_macros.inc"


// *** CONTROL ***
#declare use_lamps   =1;
#declare use_scenario=1;
#declare use_adit_scn=1;
#declare use_papers  =1;
#declare use_city    =1; // 2=without glow
#declare use_sky     =1;
#declare use_cars    =1;
#declare car_lamps_sw=1;
#declare use_cans    =1;
#declare use_cont    =1;
#declare use_people  =1;
#declare at_nigth    =1;


// *** STREET LAMPS ***
#if (use_lamps)
#include "i_lamp.inc"
// lamps with light and media cone
#declare num_lamps=10;
#declare cnt_lamps=1;
#while (cnt_lamps<num_lamps)
 object{lamp rotate -90*y translate <-298,0,-1500+1800*(cnt_lamps-1)>}
 object{lamp rotate  90*y translate < 298,0,-600+1800*(cnt_lamps-1)>}
 #declare cnt_lamps=cnt_lamps+1;
#end
// far lamps without light and media
#declare num_lamps=14;
#declare cnt_lamps=11;
#while (cnt_lamps<num_lamps)
 object{lamp2 rotate -90*y translate <-298,0,-1500+1800*(cnt_lamps-1)>}
 object{lamp2 rotate  90*y translate < 298,0,-600+1800*(cnt_lamps-1)>}
 #declare cnt_lamps=cnt_lamps+1;
#end
#end


// *** CABLE BETWEEN LAMPS ***
#if (use_lamps)
#declare rc=20;
#declare t_cable=texture{pigment{Gray40}}
#declare px=298;
#declare cnt_cables=1;
#declare num_cables=10;
#while (cnt_cables<=num_cables)
 // two cables at left...
 object{hanging_cable(< px,330, -2400+1800*(cnt_cables-1)>,< px,330, -600+1800*(cnt_cables-1)>,2,18,rc,texture{t_cable})}
 object{hanging_cable(< px,340, -2400+1800*(cnt_cables-1)>,< px,340, -600+1800*(cnt_cables-1)>,2,18,rc,texture{t_cable})}
 // ...and two more at rigth.
 object{hanging_cable(<-px,330,-3300+1800*(cnt_cables-1)>,<-px,330,-1500+1800*(cnt_cables-1)>,2,18,rc,texture{t_cable})}
 object{hanging_cable(<-px,340,-3300+1800*(cnt_cables-1)>,<-px,340,-1500+1800*(cnt_cables-1)>,2,18,rc,texture{t_cable})}
 #declare cnt_cables=cnt_cables+1;
#end
#end


// *** STREET SCENARIO ***
#if (use_scenario)
#include "i_scnrio.inc"  // miscelaneous scenery objects

// --- FABRICS ---
#declare rfabric=seed(9642);
#declare r_s=seed(6467);
#declare num_fab=10;
#declare cnt_fab=1;
#while (cnt_fab<=num_fab)
 object{fabric(rand(rfabric),1) translate <-850,0,-1800+900*(cnt_fab-1)>}
 #declare cnt_fab=cnt_fab+1;
#end
#declare num_fab=6;
#declare cnt_fab=1;
#declare right_fab=
union{
#while (cnt_fab<=num_fab)
 object{fabric(rand(rfabric),1) translate <-850,0,900+900*cnt_fab>}
 #declare cnt_fab=cnt_fab+1;
#end
}
#declare num_fab=6;
#declare cnt_fab=1;
#declare right_fab2=
union{
#while (cnt_fab<=num_fab)
 object{fabric(rand(rfabric),0) translate <-850,0,900+900*cnt_fab>}
 #declare cnt_fab=cnt_fab+1;
#end
}
object{right_fab translate <3000,0,2000>}
object{right_fab2 translate <3000,0,14000>}
object{right_fab2 translate <3000,0,26000>}

// --- ADITIONAL SIDEWALKS ---
#declare num_sid=8;
#declare cnt_sid=1;
#while (cnt_sid<=num_sid)
 object{lsidewalk(rand(r_s)) translate <-850,0,900*(15+cnt_sid)>}
 #declare cnt_sid=cnt_sid+1;
#end

// --- LONELY SIDEWALKS (at right background) ---
#declare num_sid=8;
#declare cnt_sid=1;
#while (cnt_sid<=num_sid)
 object{rsidewalk(rand(r_s)) translate <460,0,900*(15+cnt_sid)>}
 #declare cnt_sid=cnt_sid+1;
#end

// --- WOOD WALL (at right) ---
#declare r_w=seed(367);
// --- first section ---
#declare num_woods=18;
#declare cnt_woods=1;
#while (cnt_woods<=num_woods)
 object{wall(r_w) translate <460,0,-1800+900*(cnt_woods-1)>}
 #declare cnt_woods=cnt_woods+1;
#end
// --- second section ---
#declare num_woods=13;
#declare cnt_woods=1;
#while (cnt_woods<=num_woods)
 object{wall(r_w) translate <460,0,900*(24+cnt_woods)>}
 #declare cnt_woods=cnt_woods+1;
#end
// --- wall ends ---
object{wall(r_w) rotate 90*y translate <10+900,0,450+900*15>}
object{wall(r_w) rotate 90*y translate <10+900*2,0,450+900*15>}
object{wall(r_w) rotate 90*y translate <10+900*3,0,450+900*15>}
object{wall(r_w) rotate -90*y translate <10+900,0,450+900*25>}
// --- additional woods at left ---
#declare num_woods=8;
#declare cnt_woods=1;
#while (cnt_woods<=num_woods)
 object{wall(r_w) translate <-460,0,900*(7+cnt_woods)>}
 #declare cnt_woods=cnt_woods+1;
#end
// --- end ---
object{wall(r_w) rotate 90*y translate <-460-450,0,450+900*15>}
object{wall(r_w) rotate 90*y translate <-460-450-900,0,450+900*15>}

// --- ROAD "CHUNKS" ---
#declare r_road=seed(5387);
#declare num_road=51;
#declare cnt_road=1;
#while (cnt_road<=num_road)
 object{road(r_road) translate <0,0,-1800+900*(cnt_road-1)>}
 #declare cnt_road=cnt_road+1;
#end
// --- hide possible holes on the ground ---
plane{y,-2 pigment{DarkTan}}
#end


#if (use_adit_scn)
// --- AD BANNERS (at right) ---
object{banner1 rotate 90*y translate <500,0,1500>}
object{banner2 rotate 90*y translate <500,0,4000>}
object{banner1 rotate 90*y translate <500,0,10000>}

// --- SEMAPHORES ---
#include "i_semaf.inc"
object{semaforo translate <305,0,300>}
object{semaforo translate <305,0,300+1800*3>}
object{semaforo translate <305,0,300+1800*6>}
object{semaforo translate <305,0,300+1800*9>}
object{semaforo2 rotate 180*y translate <-305,0,900>}
object{semaforo2 rotate 180*y translate <-305,0,-900+1800*4>}
object{semaforo2 rotate 180*y translate <-305,0,-900+1800*7>}
object{semaforo2 rotate 180*y translate <-305,0,-900+1800*10>}
object{no_adv translate <305,125,300-10>}
object{no_park translate <305,125,300-10+1800*3>}
object{precaucion rotate 90*y translate <305-10,230,-600+1800*2>}

// --- WRINKLED PAPPERS ---
#if (use_papers)
#include "i_papers.inc"
object{papers}
#end

// *** ASHCANS ***
#if (use_cans=1)
 #include "i_ashcan.inc"
 object{can translate <-365,13.5,5905>}
#end

// *** TRASH CONTAINER ***
#if (use_cont=1)
 #include "i_cont.inc"
 object{container
  rotate -90*y
  translate <-400+45,80,5980>
 }
#end

#end // adit_scn


// *** PEOPLE WALKING ***
#if (use_people)
#include "i_people.inc"
#declare r_pers=seed(1345);
#declare num_pers=6;
#declare cnt_pers=1;
#while (cnt_pers<=num_pers)
 object{person(20+20*rand(r_pers),r_pers)
  translate <330+30*rand(r_pers),10,3200+29000*rand(r_pers)>
 }
 #declare cnt_pers=cnt_pers+1;
#end
#end // use people


// *** DISTANT CITY ***
#if (use_city)
#include "i_city.inc"
object{dist_builds translate <0,0,50000>}
#if (use_city=1)
object{city_glow translate <-2900+6400,0,55000>}
#end
#end


// *** CARS ***
#if (use_cars)
#include "i_coche.inc"
#include "i_camion.inc"
#declare t_carr1=texture{pigment{NavyBlue*.25} finish{Phong_Shiny reflection .3}}
#declare t_carr2=texture{pigment{OrangeRed} finish{Phong_Shiny reflection .3}}
#declare t_carr3=texture{pigment{SteelBlue} finish{Phong_Shiny reflection .3}}
#declare t_carr4=texture{pigment{White} finish{Phong_Shiny reflection .3}}
object{coche(t_carr1,car_lamps_sw,0) rotate 180*y translate <120,0,25000>}
object{coche(t_carr2,car_lamps_sw,0) rotate 180*y translate <120,0,12000>}
object{coche(t_carr3,car_lamps_sw,0) rotate 180*y translate <118,0,2600>}
object{camion(t_carr4,car_lamps_sw,0) translate <-130,0,8000>}
#end


// *** SKY ***
#if (at_nigth)
 // --- nigth sky with polution clouds ---
 #if (use_sky)
 #include "i_sky.inc"
 object{skyspheres rotate 5*y}
 object{moon rotate <-6,4,0>}
 #end
#else
 // --- sun for tests ---
 sky_sphere{S_Cloud2}
 light_source{
  <-6000,10000,-15000>
  White+Gold
 }
#end


// *** CAMERA (with ugly hand-coded ratio) ***
camera{
 location <-170,275,-2500>
 right 800/454*x
 direction 4*z
 look_at <22,270,2200>
 rotate -1*x
}


// *** last minute addition: my signature on the wall ***
box{
 -.5,.5
 texture{
  material_map{
   gif "im_firma1"
   texture{pigment{Clear}}
   texture{pigment{DarkGreen*.5}}
  }
  translate -.5
 }
 scale <200,50,.1>
 rotate -90*y
 translate <-339,145,-1420>
}
