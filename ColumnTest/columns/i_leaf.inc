#declare r_leaf=seed(1000*rand(ry));
#declare num_sections=10;
#declare cnt_sections=0;
#declare leaf_height=min_height+(max_height-min_height)*rand(r_leaf);
#declare sect_height=leaf_height/num_sections;
#declare leaf_radius=medium_radius*.5+medium_radius*rand(r_leaf);
#declare leaf_decr=leaf_radius/num_sections;
#declare act_height=0; //sect_height;
#declare ant_height=0;
#declare act_z=0;
#declare ant_z=0;
#declare curve_rad=leaf_height*.2+leaf_height*.8*rand(r_leaf);
#declare z_decr=sect_height*rand(r_leaf);
 #local rpl=rand(r_leaf);
 #while (cnt_sections<=num_sections)
  triangle{
   vrotate(<-leaf_radius,ant_height,ant_z-(base_radius*rpl)>,<0,360*rpl,0>),
   vrotate(< leaf_radius,ant_height,ant_z-(base_radius*rpl)>,<0,360*rpl,0>),
   vrotate(<-leaf_radius,act_height,act_z-(base_radius*rpl)>,<0,360*rpl,0>)
  }
  triangle{
   vrotate(< leaf_radius,ant_height,ant_z-(base_radius*rpl)>,<0,360*rpl,0>),
   vrotate(< leaf_radius,act_height,act_z-(base_radius*rpl)>,<0,360*rpl,0>),
   vrotate(<-leaf_radius,act_height,act_z-(base_radius*rpl)>,<0,360*rpl,0>)
  }
  #declare ant_z=act_z;
  #declare act_z=act_z-z_decr;
  #declare ant_height=act_height;
  #declare act_height=curve_rad*sin(pi*cnt_sections/num_sections);
  #declare leaf_radius=leaf_radius-leaf_decr;
  #declare cnt_sections=cnt_sections+1;
 #end

