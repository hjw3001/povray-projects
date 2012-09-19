// simple example of wrapping a TGA file onto a sphere.
// PoV source by cjcason@yarrow.wt.uwa.edu.au (100032,1644 on CIS).

// see earthmap.doc for credits for original idea and bitmaps

#include "environofog.inc"

camera
{
  location  <0,   5,   -15>
  direction <0,   0,   1.5>
  up        <0,   1,   0>
  right     <1.33,0,   0>
  look_at   <0.0, 0.0, 0.0>
}

// Light source
object { light_source { <0,0,-5> color red 1 green 1 blue 1 } }

object
{
  sphere { <0,0,0> 4.5 }
  pigment {image_map { gif "mars4.gif" map_type 1 interpolate 2 }}
  finish {ambient 1}
  rotate <0,0,-5>
}
