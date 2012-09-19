// main.pov
//
// This is the main POV-Ray file for the city scene.
//
// Written by: Henry Wagner (povray@henrywagner.org)
// Started: 12/25/96

#include "colors.inc"
#include "waves.inc"
#include "water.inc"
#include "sky1.inc"

#declare Building_Metal = texture {
   pigment { color Black }
   finish {
      ambient 0.25
      brilliance 4
      diffuse 0.5
      metallic
      specular 0.80
      roughness 1/80
      reflection 0.3
   }
}

#declare Window_Light = texture {
   pigment { color White }
   finish {
      metallic
      ambient 1.0
      diffuse 0.0
   }
}

#include "city.inc"


object { ocean }

object {
   POV_City
}

object {
   POV_City
   translate < -1250, 0, -1250 >
   rotate < 0, 90, 0 >
   translate < -1250, 0, 1250 >
}

object {
   POV_City
   translate < -1250, 0, -1250 >
   rotate < 0, 180, 0 >
   translate < 3750, 0, 1250 >
}

object {
   POV_City
   translate < -1250, 0, -1250 >
   rotate < 0, 270, 0 >
   translate < 6250, 0, 0 >
}


light_source {
   < 0, 0, 10000 >
   color White
   area_light < 0, 10000, 0 >, < 10000, 0, 0 >, 5, 5
   adaptive 1
   jitter
}

camera {
   location < 3500, 20, 4000 >
   look_at <   0, 250, 0 >
}
