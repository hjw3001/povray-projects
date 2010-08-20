// field.inc
//
// Definition for the stadium field.
//
// Written by: Henry Wagner (povray@henrywagner.org)

// For starters the field will be a green box. For (hopeful) simplicity in placing
// everything the center of the field will be the origin, and eventually the center
// of the stadium. The dimensions of the field will be 400'x180'

#declare T_Grass= texture {
  pigment { color rgb <0.5, 1.15, 0.3> }
  finish {
    specular 0.1
    diffuse 0.3
    brilliance 1.6
    ambient <0.8, 0.9, 1.4>*0.03
  }
  normal {
    granite 0.5
    accuracy 0.01
    scale 0.12
  }
}

plane {
    < 0, 1, 0 >, 0
    pigment { color rgb < 0, 1, 0 > }
    finish{ diffuse 0.75 ambient 0 }
    // texture { T_Grass }
}
