// *** yerba ***
#macro grass(rg)

#local ry=seed(1000*rg);
#local num_leaves=6+6*rand(ry);
#local cnt_leaves=1;
#local min_height=5;
#local max_height=8;
#local medium_radius=.3;
#local base_radius=.6;

mesh{
#while (cnt_leaves<=num_leaves)
 #include "i_leaf.inc"
 #declare cnt_leaves=cnt_leaves+1;
#end
}

#end


