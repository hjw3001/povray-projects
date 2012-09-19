// BigAnim.pov
//
// Main POV file for long animation sequence.
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#version unofficial megapov 1.1;

#declare use_blur = 20*0;
#declare use_radiosity = 1;
#declare rad_brightness = 2;

global_settings {
    max_trace_level 6
    assumed_gamma 2.2
    #if (use_radiosity)
        radiosity {
        #if (use_radiosity = 2)
            // save settings
            pretrace_start 0.5 pretrace_end 0.1
            count 200 nearest_count 20 error_bound .25
            recursion_limit 1
            normal on
            brightness rad_brightness
            save_file "data.rad"
        #else
            // load settings
            pretrace_start 1 pretrace_end 1
            always_sample off
            error_bound .25
            recursion_limit 1
            normal on
            brightness rad_brightness
            load_file "data.rad"
        #end
        }
    #end
}
// #default { texture { finish ambient 0 } }

#if (clock_on = 1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 100;
    #declare FF = 200;
#end

#declare displayStadium = true;
#declare displayPOPMart = true;
#declare displayBridges = true;
#declare displayTestSGI = false;
#declare displayPyramid = false;
#declare displayLattice = false;
#declare displayTemple = true;
#declare displayWater = true;
#declare displaySky = false;
#declare displayFireworks = true;
#declare displaySmallLights = true;
#declare usePhotons = false;
#declare Clock = clock;

#declare LightPower = 0.6 - ((Clock * 0.6) * 4);
#if (LightPower < 0)
    #declare LightPower = 0;
#end

// Scene positions
#declare StadiumCenter = 880;
#declare StadiumRadius = StadiumCenter - 480;
#declare CenterPodRadius = 50;
#declare BridgeLength = 440;
#declare TemplePodRadius = 230;
#declare TempleCenter = (CenterPodRadius + BridgeLength + TemplePodRadius - 23);
#declare PodHeight = 19;

// Base includes
#include "colors.inc"
#include "shapes.inc"
#include "stoneold.inc"
#include "chars.inc"
#include "metals.inc"
#include "textures.inc"
#include "golds.inc"
#include "glass.inc"
#include "3dsmater.inc"

#if (displaySky = true)
    #include "skydark.inc"
#end

#include "water.inc"

// Column and Sphere
#if (displayTestSGI = true)
    #include "TestSGI.inc"
#end

// Low Bridge
#if (displayBridges = true)
    #include "LowBridge.inc"
#end

// Pantheon files
#if (displayTemple = true)
    #include "nextd.inc"   // This is the include file for the temple and scene
    #include "swirl.inc"
    #include "frame.inc"
#end

// POP Mart files
#if (displayStadium = true)
    #include "stadium.inc"
#end

#if (displayPOPMart = true)
    #include "stage.inc"
    #include "scrframe.inc"
    #include "screen.inc"
    #include "arch.inc"
    #include "olive.inc"
    #include "speakers.inc"
    #include "SpeaNeon.inc"
    #include "support1.inc"
    #include "support2.inc"
    #include "support3.inc"
    #include "support4.inc"
    #include "support5.inc"
    #include "support6.inc"
    #include "TopLght.inc"
    #include "TopLight.inc"
    #include "SpkTower.inc"
#end

// Fireworks
#if (displayFireworks = true)
    #include "Fireworks.inc"
#end

// Space Ship Files

// Pyramid files
#if (displayPyramid = true)
    #include "frame.inc"
#end

// Lattice files
#if (displayLattice = true)
    #include "lattice.inc"
#end

// Tree files

// Small Lights
#if (displaySmallLights = true)
    #include "smalllight.inc"
#end

#if (clock_on = 1)
    #declare rfact = clock * 360;
#else
    #declare rfact = 0;
#end

#declare GroundTileTexture = texture {
    tiles {
        texture { Sandalwood }
    tile2
        texture { DMFWood1 }
    }
    scale 10
}

#declare GroundOldTexture = texture {   
    tiles {
        texture { Jade normal { granite .1 scale .1 } finish { reflection{.01, .3} diffuse .7 } }
    tile2
        texture { Stone3 normal { granite .1 scale .1 } finish { reflection{.01, .3} diffuse .7 } }
    }
    scale 10
}

union {
    cylinder {
        < 0, -10, 0 >,
        < 0, PodHeight, 0 >,
        CenterPodRadius
    }
    torus {
        CenterPodRadius, PodHeight
    }
    texture { GroundOldTexture }
}

union {
    cylinder {
        < 0, -10, 0 >,
        < 0, PodHeight, 0 >,
        TemplePodRadius
    }
    torus {
        TemplePodRadius, PodHeight
    }
    texture { GroundOldTexture }
    translate < TempleCenter, 0, 0 >
}

union {
    cylinder {
        < 0, -10, 0 >,
        < 0, PodHeight, 0 >,
        StadiumRadius
    }
    torus {
        StadiumRadius, PodHeight
    }
    texture { GroundOldTexture }
    translate < -StadiumCenter, 0, 0 >
}

union {
    cylinder {
        < 0, -10, 0 >,
        < 0, PodHeight, 0 >,
        50
    }
    torus {
        50, PodHeight
    }
    texture { GroundOldTexture }
    translate < 0, 0, 525 >
}

union {
    cylinder {
        < 0, -10, 0 >,
        < 0, PodHeight, 0 >,
        50
    }
    torus {
        50, PodHeight
    }
    texture { GroundOldTexture }
    translate < 0, 0, -525 >
}

// TestSGI section
#if (displayTestSGI = true)
    sphere {
        < 0, 39, 0 > 10
        texture{ Polished_Chrome }
        photons { target reflection on }
    }
    
    object { ColumnOld translate < -15, PodHeight, -15 > }
    object { ColumnOld translate < -15, PodHeight,  15 > }
    object { ColumnOld translate <  15, PodHeight,  15 > }
    object { ColumnOld translate <  15, PodHeight, -15 > }
#end
// End TestSGI section

// Low Bridge section
#if (displayBridges = true)
    object { LowBridge translate <  260, 0, 0 > }
    object { LowBridge translate < -260, 0, 0 > }
    object { LowBridge rotate < 0, 90, 0 > translate <  0, 0,  260 > }
    object { LowBridge rotate < 0, 90, 0 > translate <  0, 0, -260 > }
#end

// POP Mart scene
#if (displayStadium = true)
    object {
        Stadium
        texture { Concrete1 }
        rotate < 0, -90, 0 >
        translate < -StadiumCenter, PodHeight, 0 >
    }
#end

#if (displayPOPMart = true)
object {
    Main_Stage
    rotate < 0, -90, 0 >
    translate < -StadiumCenter, PodHeight, 0 >
}

object {
   Arch
   texture {
      pigment { color Yellow }
      finish {
         metallic
         ambient 0.6
         diffuse 0.7
         specular 1
         roughness 0.001
         reflection 0.01
      }
   }
   translate < 0, 10, 180 >
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, 19, 0 >
}

object {
   Arch_Neon
   texture {
      pigment { color Green }
      finish {
         #if (displayNeon = true)
            ambient 1.0
         #else
            ambient 0.5
         #end
         diffuse 0.0
         reflection .25
         specular 1
         roughness .001
      }
   }
   translate < 0, 10, 180 >
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
   Screen_Frame
   texture { Frame_Material }
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
   Screen_Neon
   texture { Green_Neon }
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
   POPScreen
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
   Toothpick
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
   Olive
   rotate < 0, 0, -10 >
   translate < 93.5, 98, 192 >
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

union {
   object { Speaker_Mount_0 }
   object { Speaker_Mount_1 }
   object { Speaker_Mount_2 }
   object { Speaker_Mount_3 }
   object { Speaker_Mount_4 }
   object { Speaker_Mount_5 }
   
   texture {
      pigment { color Orange }
      finish {
         ambient 0.4
         diffuse 0.5
      }
   }
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
   Speaker_Neon
   texture {
      pigment { color Red }
     finish {
     #if (displayNeon = true)
        ambient 0.9
     #else
        ambient 0.5
     #end
        diffuse 0.0
        reflection .25
        specular 1
        roughness .001
     }
   }
   translate < 0, 81, 178 >
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

union {
    object {
       Support1
       translate < -65, 0, 201.5 >
    }
    
    object {
       Support2
       translate < -37, 0, 201.5 >
    }
    
    object {
       Support3
       translate < -9, 0, 201.5 >
    }
    
    object {
       Support4
       translate < 19, 0, 201.5 >
    }
    
    object {
       Support5
       translate < 47, 0, 201.5 >
    }
    
    object {
       Support6
       translate < 75, 0, 201.5 >
    }
    
    union {
       cylinder {
          < -64, 78, 199 >,
          <  76, 88, 199 >,
          0.3
       }
       cylinder {
          < -64, 78, 197 >,
          <  76, 88, 197 >,
          0.3
       }
       cylinder {
          < -64, 76, 198 >,
          <  76, 86, 198 >,
          0.3
       }
    
       texture {
          pigment { color red 0.7 green 0.7 blue 0.7 }
          finish { metallic }
       }
    }
   rotate < 0, -90, 0 >
   translate < -StadiumCenter, PodHeight, 0 >
}

object {
    TopLightRig
    rotate < 0, -90, 0 >
    translate < -StadiumCenter, PodHeight, 0 >
}
#end

// Temple
#if (displayTemple = true)
union {
    object { PantheonSteps }
    object { SGILogos }
    object { PantheonColumns }
    object { PantheonRoof }
    object { PantheonCandles }
    object { PantheonWalls }
    object { PantheonCrown }
    object { PantheonText }
    // Account for odd position of Temple
    // Center around middle of main room
    translate < -510, 0, -40 >
    // Move to center of Temple Pod 
    translate < TempleCenter, 19, 0 >
}
#end

// The Gold Lattice
#if (displayLattice = true)
    object {
        lattice
        scale 0.5
        translate < 0, 45, 525 >
    }
#end

// Crystal Pyramid
#if (displayPyramid = true)
    union {
        object { Metal_Frame }
    
        // These are the windows
        union {
           triangle { < -50, 0, -50 >, < 0, 100, 0 >, < 50, 0, -50 > }
           triangle { < -50, 0, -50 >, < 0, 100, 0 >, < -50, 0, 50 > }
           triangle { <  50, 0, -50 >, < 0, 100, 0 >, < 50, 0, 50 > }
           triangle { < 50, 0, 50 >, < 0, 100, 0 >, < -50, 0, 50 > }
        
           texture { T_Glass1 }
        }
        scale 0.5
        translate < 0, 19, -525 >    
    }
#end

// Water base
#if (displayWater = true)
object {
    ocean
    photons { collect off }
}
#else
    object { oceanOff }
#end

#declare loc = < -(StadiumCenter/2)-StadiumCenter+70, 240, -(StadiumCenter/2)+100 >;
#declare lat = < -StadiumCenter, 90, 0 >;
camera {
    // location < -StadiumCenter, 800, 30 >
    // look_at < -StadiumCenter, 21, 0 >
    // location < -400, 40, 0 >
    // look_at < -StadiumCenter, 21, 0 >
    // location < -StadiumCenter, 25, 0 >
    // look_at  < -StadiumCenter-StadiumCenter, 30, 0 >
    // location < sin(radians(rfact)) * 20, 24, cos(radians(rfact)) * 20 >
    // look_at < 0, 29, 0 >
    // location < -70, 25, -540 >
    // look_at  <   0, 45, -525 >
    // location < 0, 100, -525 >
    // look_at  < 0,  20, -525 >
    // location < (TempleCenter-370), 40, 80 >
    // location < sin(radians(rfact)) * (TempleCenter-370), 24, cos(radians(rfact)) * (TempleCenter-370) >
    // location < (sin(radians(rfact)) * (TempleCenter-370)) + (TempleCenter), 40, cos(radians(rfact)) * (TempleCenter-370) >
    // location < (sin(radians(rfact)) * (TempleCenter+300)) , 40, cos(radians(rfact)) * (TempleCenter+300) >
    // look_at < TempleCenter, 39, 0 >
    location loc
    look_at lat
    #if (use_blur)
        focal_point lat
        aperature .125
        blur_samples use_blur
    #end
}

// light_source { < -10000, 10000, -10000 > color rgb (White+Gold)*LightPower media_interaction off shadowless }
// light_source { < -10000, 10000,  10000 > color rgb (White+Gold)*LightPower media_interaction off shadowless }
// light_source { <  10000, 10000,  10000 > color rgb (White+Gold)*LightPower media_interaction off shadowless }
light_source {
    <  10000, 10000, -10000 >
    color rgb (White+Gold)*LightPower
    parallel
    point_at < 0, 19, 0 >
}
