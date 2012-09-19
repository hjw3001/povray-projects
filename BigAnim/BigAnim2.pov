// BigAnim.pov
//
// Main POV file for long animation sequence.
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#version unofficial megapov 1.1;

#declare use_blur = 20*0;
#declare use_radiosity = 0;
#declare rad_brightness = 2;

global_settings {
    assumed_gamma 2.2
    #if (use_radiosity)
        max_trace_level 6
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
    #declare cameraIndex = frame_number;
    #declare cameraFN = frame_number;
    #declare cameraFF = final_frame;
#else
    #declare cameraIndex = 17;
    #declare cameraFN = 0.65;
    #declare cameraFF = 1;
#end

#declare displayStadium = true;
#declare displayPOPMart = true;
#declare displayU2Fans = true;
#declare displayBridges = false;
#declare displayTestSGI = false;
#declare displayPyramid = false;
#declare displayLattice = false;
#declare displayTemple = false;
#declare displayWater = false;
#declare displaySky = true;
#declare displayFireworks = false;
#declare displaySmallLights = false;
#declare usePhotons = false;
#declare Clock = clock;

#declare LightPower = 0.6;
/*
#declare LightPower = 0.6 - ((Clock * 0.6) * 4);
#if (LightPower < 0)
    #declare LightPower = 0;
#end
*/

// Scene positions
#declare StadiumCenter = 880;
#declare StadiumRadius = StadiumCenter - 480;
#declare CenterPodRadius = 50;
#declare BridgeLength = 440;
#declare TemplePodRadius = 230;
#declare TempleOffsetX = -510;
#declare TempleOffsetZ = -40;
#declare TempleCenter = (CenterPodRadius + BridgeLength + TemplePodRadius - 23);
#declare PodHeight = 19;
#declare LemonYellow=1;
#declare LemonSpinFactor=360 * 10;

#if (clock_on = 1)
    #declare rfact = clock * 360;
#else
    #declare rfact = 0;
#end

#include "camera.inc"

// Base includes
#include "colors.inc"
#include "shapes.inc"
#include "chars.inc"
#include "metals.inc"
#include "textures.inc"
#include "golds.inc"
#include "glass.inc"
#include "3dsmater.inc"
#include "hwcolors.inc"

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
    #include "lemon.inc"
    #if (displayU2Fans = true)
        #include "u2fan.inc"
    #end
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

#if (displayU2Fans = true)
    GenerateFieldCrowd(600)
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

object {
   Lemon
   texture {
      #if (LemonYellow = 1)
        pigment { color Yellow }
        finish {
           metallic
           ambient 0.4
           diffuse 0.7
           specular 1
           roughness 0.001
           reflection 0.01
        }
      #else
        pigment { rgb < 0.2, 0.2, 0.2 > }
        finish {
            ambient 0.4
            diffuse 0.7
            brilliance 6.0
            reflection 0.6
            phong 0.8
            phong_size 120
        }
     #end
   }
   rotate < 0, clock * LemonSpinFactor, 0 > // Rotate the Lemon for animation
   rotate < 20,  0, 0 > // Tilt the Lemon
   rotate <  0, 90, 0 > // Rotate into final position
   translate < 60, 30, 175 >
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
    translate < TempleOffsetX, 0, TempleOffsetZ >
    // Move to center of Temple Pod 
    translate < TempleCenter, PodHeight, 0 >
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

/*
camera {
    location CameraLocationArray[cameraIndex]
    look_at CameraLookAtArray[cameraIndex]
    #if (use_blur)
        focal_point CameraLookAtArray[cameraIndex]
        aperture .125
        blur_samples use_blur
    #end
}
*/

camera {
    // Original outside view
    // location < 500, 170, 100 >
    // look_at < 0, 20, 0 >
    // Air
    // location CameraSource(FN/FF)
    // look_at CameraDest(FN/FF)
    
    // Select camera and destination based on elapsed time
    #switch (cameraFN/cameraFF)
        // Start out by flying up and over the stadium, then start flying in
        #range (0, 0.3)
            #declare CameraLocation = CameraSource(cameraFN/cameraFF);
            #declare CameraLookAt = CameraDest(cameraFN/cameraFF);
            #break;
        
        // Then pan by the Speaker Towers    
        #range (0.3, 0.5)
            #declare CameraLocation = SpkTowerCameraSource(cameraFN/cameraFF);
            #declare CameraLookAt = SpkTowerCameraDest(cameraFN/cameraFF);
            #break;
        
        // Then checkout the Olive
        #range (0.5, 0.6)
            #declare CameraLocation = OliveCameraSource(cameraFN/cameraFF);
            #declare CameraLookAt = < -StadiumCenter-192, 95 + PodHeight, 91.057 >;
            #break;
        
        // Then checkout the Lemon         
        #range (0.6, 0.7)
            #declare CameraLocation = LemonCameraSource(cameraFN/cameraFF);
            #declare CameraLookAt = LemonCameraDest(cameraFN/cameraFF);
            #break;
            
        // The check out the Speakers
        #range (0.7, 0.8)
            #declare CameraLocation = ArchCameraSource(cameraFN/cameraFF);
            #declare CameraLookAt = ArchCameraDest(cameraFN/cameraFF);
            #break;

        // Look out from the stage            
        #range (0.8, 1.0)
            #declare CameraLocation = < -StadiumCenter-190, 15.5 + PodHeight, 0 >;
            #declare CameraLookAt = StageCameraDest(cameraFN/cameraFF);
            #break;

        #else
            #declare CameraLocation = CameraSource(cameraFN/cameraFF);
            #declare CameraLookAt = CameraDest(cameraFN/cameraFF);
    #end
    location CameraLocation
    look_at CameraLookAt
    #if (use_blur)
        focal_point CameraLookAt
        aperture .125
        blur_samples use_blur
    #end
}

// light_source { < -10000, 10000, -10000 > color rgb (White+Gold)*LightPower media_interaction off shadowless }
// light_source { < -10000, 10000,  10000 > color rgb (White+Gold)*LightPower media_interaction off shadowless }
// light_source { <  10000, 10000,  10000 > color rgb (White+Gold)*LightPower media_interaction off shadowless }

light_source {
    <  10000, 10000, -10000 >
    color (White+Gold)*LightPower
    parallel
    point_at < 0, 19, 0 >
}
