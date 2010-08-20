// stadium.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare use_blur    =20*0;  // blur samples (0=off)
#declare use_radiosity =false;
#declare rad_brightness=2;
global_settings{
 max_trace_level 6
 assumed_gamma 2.2
 #if (use_radiosity)
  radiosity{
   #if (use_radiosity=2)
    // save settings
    pretrace_start .05 pretrace_end .01
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

#version unofficial megapov 1.1;

#include "colors.inc"
#include "finish.inc"
#include "stadium.inc"
#include "field.inc"
// #include "sky.inc"

#include "stage.inc"
#include "scrframe.inc"
#include "screen.inc"
#include "arch.inc"
#include "olive.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"
#include "lemon.inc"
#include "support1.inc"
#include "support2.inc"
#include "support3.inc"
#include "support4.inc"
#include "support5.inc"
#include "support6.inc"
#include "support.inc"
#include "TopLght.inc"
#include "TopLight.inc"
#include "SpkTower.inc"

#include "SpinLght.inc"
// #include "environofog.inc"

global_settings { assumed_gamma 2.2 }

#if (clock_on=1)
    #declare rfact = clock * 360;
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare rfact = 0;
    #declare FN = 180;
    #declare FF = 200;
#end

#declare LemonYellow=0;
#declare LemonSpinFactor=360 * 10;

object { TopLightRig }

object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}

DisplayPOPMartScreen("stadium")

#declare CameraSource = function {
   spline {
       natural_spline
       0.0, < 500,   6, 100 > // Outside the stadium
       0.1, < 500, 170, 100 > // Outside the stadium
       0.2, <  40, 600, -85 > // Aireal View
       0.4, <  20, 200,  20 > // 300 level
       0.6, <   1,  50,  20 > // Mid Field
       0.6, <  40, 5.8,  85 > // B-Stage
       0.7, <  85, 105, 180 > // Olive
       0.75,<   0,  50,  70 >
       0.8, < -70,  10, 171 > // Lower left looking up
       0.85,<   0,  30, 140 >
       0.9, <  50,  45, 135 > // Lemon
   }
}

#declare CameraDest = function {
   spline {
       natural_spline
       0.0, <  0, 90,    0 > // Outside the stadium
       0.2, <  0, 20,   10 > // Aireal View
       0.4, <  0, 60,  160 > // Mid field
       0.6, <  0, 40,  190 > // B-Stage
       0.7, < 91, 95,  192 > // Olive
       0.8, < 40, 70,  198 > // Lower left looking up
       0.9, < 60, 30,  175 > // Lemon
   }
}

#declare SpkTowerCameraSource = function {
   spline {
       natural_spline
       0.3, <  50,  5, -210 >
       0.31, <  45,  7, -220 >
       0.4, <   0,  9, -230 >
       0.49, < -45, 12, -220 >
       0.5, < -50, 15, -210 >
   }
}

#declare SpkTowerCameraDest = function {
   spline {
       natural_spline
       0.3, <  60,  30, -150 >
       0.4, <   0,  40, -160 >
       0.5, < -50,  30, -150 >
   }
}

#declare OliveCameraSource = function {
   spline {
       natural_spline
       0.0, < 85, 105, 180 >
       0.5, < 90, 108, 185 >
       1.0, < 95, 110, 190 >
   }
}

#declare LemonCameraSource = function {
   spline {
       natural_spline
       0.0, <  55,  35, 175 >
       0.5, <  50,  45, 135 >
       1.0, <  75,  6, 155 >
   }
}

#declare LemonCameraDest = function {
   spline {
       natural_spline
       0.0, < 60, 30, 175 >
       0.5, < 60, 30, 175 >
       1.0, < 60, 23, 175 >
   }
}

#declare StageCameraDest = function {
   spline {
       natural_spline
       0.8,   <  75,  50,  180 >
       0.825, <  50,  55,  100 >
       0.9,   <   0,  35,    0 >
       0.975, < -50,  15,  100 >
       1.0,   < -75,  10,  190 >
   }
}

#declare ArchCameraSource = function {
   spline {
       natural_spline
       0.7,  <  40, 60, 185 >
       0.75, <   0, 70, 150 >
       0.8,  < -40, 80, 185 >
   }
}

#declare ArchCameraDest = function {
   spline {
       natural_spline
       0.7,  < 0, 70, 178 >
       0.75, < 0, 65, 178 >
       0.8,  < 0, 60, 178 >
   }
}

/*
#declare sphereCount = 1;
#while (sphereCount <= 200)
    sphere {
        CameraSource(sphereCount/200), 2
        pigment { color Blue }
    }
    sphere {
        CameraDest(sphereCount/200), 2
        pigment { color Yellow }
    }
    
    #declare sphereCount = sphereCount + 1;
#end
*/

camera {
    // Original outside view
    // location < 500, 170, 100 >
    // look_at < 0, 20, 0 >
    // Air
    // location CameraSource(FN/FF)
    // look_at CameraDest(FN/FF)
    
    // Select camera and destination based on elapsed time
    #switch (FN/FF)
        // Start out by flying up and over the stadium, then start flying in
        #range (0, 0.3)
            location CameraSource(FN/FF)
            look_at CameraDest(FN/FF)
            #break;
        
        // Then pan by the Speaker Towers    
        #range (0.3, 0.5)
            location SpkTowerCameraSource(FN/FF)
            look_at SpkTowerCameraDest(FN/FF)
            #break;
        
        // Then checkout the Olive
        #range (0.5, 0.6)
            location OliveCameraSource(FN/FF)
            look_at < 91.057, 95, 192 >
            #break;
        
        // Then checkout the Lemon         
        #range (0.6, 0.7)
            location LemonCameraSource(FN/FF)
            look_at LemonCameraDest(FN/FF)
            #break;
            
        // The check out the Speakers
        #range (0.7, 0.8)
            location ArchCameraSource(FN/FF)
            look_at ArchCameraDest(FN/FF)
            #break;

        // Look out from the stage            
        #range (0.8, 1.0)
            location < 0, 15.5, 190 >
            look_at StageCameraDest(FN/FF)        
            #break;

        #else
            location CameraSource(FN/FF)
            look_at CameraDest(FN/FF)
    #end
    
    // location CameraSource(0.2)
    // look_at CameraDest(0.2)
}
/*
light_source {
    < 1000, 1000, 1000 >
    color White
    media_interaction off
}
*/

object {
   Lemon
   texture {
      #if (LemonYellow = 1)
        pigment { color Yellow }
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
}

light_source {
    < 0, 15, 0>
    color rgb 0.7
    media_interaction off
    shadowless
}
