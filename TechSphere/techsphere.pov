// POV-Ray 3.1 Scene Description File
// "Tech Sphere" copyright October 2000 Rune S. Johansen
   
// 2 steps are needed to get the final image.
// NOTE: You can skip the first step (step 0), because I've done it for you.
// Only if you change something in the image you may have to redo step 0
   
// Step 0 creates an image with a white glow. This image is needed in step 1.
// - Step 0 requires MegaPOV 0.5 !
// - Set "Step" to 0
// - Render the image (a resolution of 100x75 with no antialiasing is enough) 
// - In a paint program convert the image to grayscale
//   and save it as "techsphereglow.png"
   
// Step 1 creates the final image
// - Step 1 can be rendered with official POV-Ray 3.1
// - Set "Step" to 1
// - Render the image (at any resoltion you like)
   
   #declare Step = 1;
   
   #declare GlowColor = <0.0,1.0,0.5>;
   
   camera {
      location -10*z
      angle 20
      look_at 0
      rotate 10*x+40*y
   }
   
   #if (Step=0)

//    create white light for the media
      light_source {0, color 1.5}
      
//    the media requires MegaPOV
      #version unofficial MegaPOV 0.5;

   #else

//    create green light to light up the sphere from inside
      light_source {0, color 1.5*GlowColor}

//    create two white lights to light sphere from outside
      light_source {<+1,+2,-3>*1000, color 1}
      light_source {<-1,-2,+3>*1000, color 1}

   #end
   
   #declare Normal =
   normal {
      bump_map {
         png
         "maze.png"
         map_type 0
         interpolate 4
         bump_size 3
      }
      scale 1.5
   }
   
// The number of pieces in the sphere is 6 * Panels^2
   #declare Panels = 5;
   
   #macro Vectors2Matrix (vA,vB,vC,vD)
      matrix <vA.x,vA.y,vA.z,vB.x,vB.y,vB.z,vC.x,vC.y,vC.z,vD.x,vD.y,vD.z>
   #end
   
   #macro Perpendiculize (V1,V2)
      vnormalize(vcross(vcross(V2,V1),V2))
   #end
   
// The section is an intersection of two planes, making an angle
   #declare Section =
   intersection {
      plane {+x, 0 rotate (45/Panels-0.5)*-y}
      plane {-x, 0 rotate (45/Panels-0.5)*+y}
   }
   
   #declare Seed1 = seed(0);
   #declare Seed2 = seed(1);
   #declare Seed3 = seed(0);
   
// The sphere is made of 6 sides (like if it was a cube).
// This macro cretates one side.
// Each side has 5x5 pieces.
// Two loops are used to create the grid of pieces.
   #macro Side()
      union {
         #declare C = 0;
         #declare Cm = Panels-1;
         #while (C<=Cm)
            #declare D = 0;
            #declare Dm = Panels-1;
            #while (D<=Dm)
               
               #declare Cv = C/Cm;
               #declare Dv = D/Dm;
               
               #declare PanelP =
               vnormalize(
                  <
                     -tan((45-90*Dv)*(1-(1/Panels))*pi/180),
                     tan((45-90*Cv)*(1-(1/Panels))*pi/180),
                     -1
                  >
               );
               #declare PanelZ = -PanelP;
               #declare PanelX = Perpendiculize(x,PanelZ);
               #declare PanelY = vcross(PanelZ,PanelX);
               #declare PanelT = transform{Vectors2Matrix(PanelX,PanelY,PanelZ,PanelP)}
//             Create one piece. It's an intersection of a hirizontal and
//             a vertical section, and some other things.
               union {
                  intersection {
                     object {Section rotate 90*z rotate (45-90*Cv)*(1-(1/Panels))*x}
                     object {Section             rotate (45-90*Dv)*(1-(1/Panels))*y}
                     sphere {0, 1}
                     sphere {0, 0.94 inverse}
                     bounded_by {
                        box {
                           <+1.6/Panels,+1.6/Panels,-1>, <-1.6/Panels,-1.6/Panels,-0.5>
                           rotate (45*x-90*x*Cv)*(1-(1/Panels))
                           rotate (45*y-90*y*Dv)*(1-(1/Panels))
                        }
                     }
                  }
                  cylinder {0.5*PanelP, 0.95*PanelP, 0.05 no_shadow}
                  pigment {rgb rand(Seed1)*0.2+0.8}
                  finish {ambient 0.1*Step diffuse 0.9*Step phong 0.2*Step metallic 0.5}
                  normal {
                     Normal
                     translate <rand(Seed2),rand(Seed2),1>
                     rotate 360*z*rand(Seed2)
                     transform PanelT
                  }
//                Translate out randomly some of the pieces
                  #if (rand(Seed3)>0.5)
                     translate 0.15*pow(rand(Seed3),2)*PanelP
                  #end
               }
               
               #declare D = D+1;
            #end
            #declare C = C+1;
         #end
      }
   #end

// Create the 6 sides that make up the sphere
   object {Side() rotate <+000,+000,+000>}
   object {Side() rotate <+090,+000,-090>}
   object {Side() rotate <+000,+180,+000>}
   object {Side() rotate <+090,+000,+090>}
   object {Side() rotate <+090,+000,+000>}
   object {Side() rotate <+270,+090,+000>}
   
   sphere {
      0, 0.7
      pigment {color GlowColor}
      finish {ambient 1*Step diffuse 0}
      no_shadow
   }
   
// And here comes the special effects!
   
   #if (Step=0)
      
//    Create white scattering media for glowing effect
      sphere {
         0, 1
         hollow
         pigment {color rgbf 1}
         interior {
            media {
               method 3
               scattering {1, rgb 1 extinction 0}
               intervals 1
               samples 100, 100
               confidence 0.9
               variance 1/1000
               density {
                  spherical
                  color_map {
                     [0.0, rgb 0.0]
                     [0.5, rgb 1.0]
                  }
               }
            }
         }
         scale 2
      }
      
   #else
      
//    Make an image of the glow in front of the camera
      plane {
         -z, 3
         texture {
            material_map {
               png "techsphereglow.png" once
               interpolate 4
               #declare X = 0;
               #declare Y = 255;
               #while (X<Y)
                  texture {
                     pigment {color GlowColor transmit 1-(X/Y)*0.75}
                     finish {ambient 1 diffuse 0}
                  }
                  #declare X = X+1;
               #end
            }
            translate -0.5
            scale <4/3,1,1>*1.85
         }
         rotate 10*x+40*y // rotate similar as the camera is rotated
      }
      
//    Put in the maze-like background behind the sphere.
      plane {
         -z, -3
         texture {
            material_map {
               png "maze.png"
               #declare X = 0;
               #declare Y = 255;
               #while (X<Y)
                  texture {
                     pigment {color <0.4,0.2,0.0>*(X/Y)+<0.0,0.0,0.1>*(1-X/Y)}
                     finish {ambient 1 diffuse 0}
                  }
                  #declare X = X+1;
               #end
            }
            translate -0.5
            scale 2
            rotate 15*z
         }
         rotate 10*x+40*y // rotate similar as the camera is rotated
      }
      
   #end
   