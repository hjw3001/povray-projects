// simple example of wrapping a TGA file onto a sphere.
// PoV source by cjcason@yarrow.wt.uwa.edu.au (100032,1644 on CIS).

// see earthmap.doc for credits for original idea and bitmaps

#declare mars = object
{
  sphere { <0,0,0> 4.5 }
  pigment {image_map { gif "mars4.gif" map_type 1 interpolate 2 }}
  finish {ambient 1}
  rotate <0,0,-5>
}
