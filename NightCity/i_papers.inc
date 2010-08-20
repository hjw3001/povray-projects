// wrinkled paper texture
// has many colors, scaled up to show diferent on each paper
#declare t_paper=
texture{
 pigment{
  bozo
  color_map{
   [0.0 White]
   [0.1 Flesh]
   [0.2 Red]
   [0.3 White]
   [0.4 Flesh]
   [0.5 White]
   [0.6 DarkGreen]
   [0.7 White]
   [0.8 Flesh]
   [0.9 White]
   [1.0 Tan]
  }
  scale 20
 }
}
// with a bit of dirt
texture{
 pigment{
  bumps
  color_map{
   [0.0 Clear]
   [1.0 DarkBrown]
  }
  scale 10
 }
}
// place pappers on the road and sidewalks
#declare r_pap=seed(7824);
#declare num_pap=40;
#declare cnt_pap=1;
#declare papers=
union{
#while (cnt_pap<=num_pap)
 #if (rand(r_pap)>.7)
 object{
  wrinkled_paper(r_pap,15+3*rand(r_pap))
  texture{t_paper translate 1000*rand(r_pap)}
  scale <1,.5,1>
  translate <-30+60*rand(r_pap),3,-3000+12000*rand(r_pap)>
 }
 #end
 object{
  wrinkled_paper(r_pap,15+3*rand(r_pap))
  texture{t_paper translate 1000*rand(r_pap)}
  scale <1,.5,1>
  translate <-300+60*rand(r_pap),3,-3000+12000*rand(r_pap)>
 }
 object{
  wrinkled_paper(r_pap,15+3*rand(r_pap))
  texture{t_paper translate 1000*rand(r_pap)}
  scale <1,.5,1>
  translate <240+60*rand(r_pap),3,-3000+12000*rand(r_pap)>
 }
 object{
  wrinkled_paper(r_pap,15+3*rand(r_pap))
  texture{t_paper translate 1000*rand(r_pap)}
  scale <1,.5,1>
  translate <-300-200*rand(r_pap),13,-3000+12000*rand(r_pap)>
 }
 object{
  wrinkled_paper(r_pap,15+3*rand(r_pap))
  texture{t_paper translate 1000*rand(r_pap)}
  scale <1,.5,1>
  translate <300+300*rand(r_pap),13,-3000+12000*rand(r_pap)>
 }
 #declare cnt_pap=cnt_pap+1;
#end
}