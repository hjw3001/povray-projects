// stage1.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare use_blur = 20*0;
#declare use_radiosity = 0;
#declare rad_brightness = 2;
#declare useLight = false;
#declare displayU2Fans = false;
#declare displayLightTowers = true;

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

#include "colors.inc"
#include "finish.inc"
#include "metals.inc"
#include "textures.inc"
#include "hwcolors.inc"
#include "ninelight.inc"
#include "guardlight.inc"
#include "stage.inc"
#include "zootv.inc"
#include "videowalls.inc"
#include "stadium.inc"
// #include "Fireworks.inc"
// #include "whiteroombasic.inc"
#include "SpinLght.inc"

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 3546;
    #declare FF = 600;
#end

#declare XTrans = 120;
#declare ZTrans = 140;

#if (displayU2Fans = true)
    #include "u2fan.inc"
    // GenerateLighters(18, 24, 15, 0.5, 6, 3000, 33.69)
    // GenerateLighters(20, 24, 52, 0.5, 4, 3000, 47.07)
    // GenerateLighters(22, 25, 87, 0.5, 3, 3000, 63.4349)

    GenerateFieldCrowd(100)
#end

#if (displayLightTowers = true)
    #include "LightTower.inc"
    object {
        LightTower()
        rotate < 0, 180, 0 >
        translate < 146, 147, -264 >
    }
    object {
        LightTower()
        rotate < 0, 180, 0 >
        translate < -146, 147, -264 >
    }
    object {
        LightTower()
        rotate < 0, 180, 0 >
        translate < -146, 147, 264 >
    }
    object {
        LightTower()
        rotate < 0, 180, 0 >
        translate < 146, 147, 264 >
    }
#end

union {
    object { Zoo_Red }
    object { Zoo_Green }
    translate < -50, 60, 170 >
}

object {
    SmallVideoScreen
    translate < -26, 10, 182 >
}

object {
    SmallVideoScreen
    translate < 26, 10, 182 >
}

object {
    SmallVideoScreen
    translate < -11, 21, 185 >
}

object {
    SmallVideoScreen
    translate < 11, 21, 185 >
}

object {
    LargeTWoSectionVideoScreen
    translate < -25, 22, 190 >
}

object {
    LargeTWoSectionVideoScreen
    translate < 68, 18, 177 >
}

object {
    TVScreen
    translate < -3, 21, 185 >
}

object {
    TVScreen
    translate < 3, 21, 185 >
}

#declare nineLightZ = 178;

object {
    NineLight(useLight)
    translate < -70, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -60, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -50, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -40, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -30, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 70, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 60, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 50, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 40, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 30, 10, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 33, 20, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 33, 30, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 33, 40, nineLightZ >
}

object {
    NineLight(useLight)
    translate < 33, 50, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -33, 20, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -33, 30, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -33, 40, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -33, 50, nineLightZ >
}

object {
    NineLight(useLight)
    translate < -18, 21, 185 >
}

object {
    NineLight(useLight)
    translate < 18, 21, 185 >
}

object {
    NineLight(useLight)
    translate < 0, 21, 185 >
}

// Deck above Larry
union {
    box {
        < -20, 20.5, 180 >,
        <  20, 21.0, 187 >
        texture { Stage_Black }
    }
    box {
        < -20, 10, 180 >,
        < -19.5, 20.5, 180.5 >
        texture { Stage_Black }
    }
    box {
        < -20, 10, 186.5 >,
        < -19.5, 20.5, 187 >
        texture { Stage_Black }
    }
    box {
        < 19.5, 10, 180 >,
        < 20, 20.5, 180.5 >
        texture { Stage_Black }
    }
    box {
        < 19.5, 10, 186.5 >,
        < 20, 20.5, 187 >
        texture { Stage_Black }
    }
    box {
        < -20, 21, 180 >,
        <  20, 21.05, 180.2 >
        texture { Stage_White }    
    }
    box {
        < -20, 21, 186.8 >,
        <  20, 21.05, 187 >
        texture { Stage_White }    
    }
    box {
        < -20, 21, 180.2 >,
        < -19.8, 21.05, 186.8 >
        texture { Stage_White }    
    }
    box {
        < 19.8, 21, 180.2 >,
        < 20, 21.05, 186.8 >
        texture { Stage_White }    
    }
}

#declare StageCameraDest = function {
   spline {
       natural_spline
       0.0, <  75,  50,  180 >
       0.25 <  50,  55,  100 >
       0.5, <   0,  35,    0 >
       0.75 < -50,  15,  100 >
       1.0, < -75,  10,  190 >
   }
}

#declare GuardLightCameraSource = function {
   spline {
       natural_spline
       1,  < 247, 148.6, -148.2 >
       50, < 266, 148.6, -102.2 >
       100, < 277, 148.6, -54.2 >
       150,  < 281, 148.6, -5.2 >
   }
}

#declare GuardLightCameraDest = function {
   spline {
       natural_spline
       1,  < 246, 147.8, -148 >
       50, < 265, 147.8, -102 >
       100, < 276, 147.8, -54 >
       150,  < 280, 147.8, -5 >
   }
}

#declare SpinLightCameraSource = function {
   spline {
       natural_spline
       151, < 126, 2, 128 >
       351, < 126, 2, 128 >
   }
}

#declare SpinLightCameraDest = function {
   spline {
       natural_spline
       151, < 112, 5, 140 >
       351, < 112, 5, 140 >
   }
}

#declare ZooTVCameraSource = function {
   spline {
       natural_spline
       352, < -63, 63, 166 >
       430, < -50, 40, 150 >
       530, < -20, 30, 120 >
       630, <   0,  5,  80 >
   }
}

#declare ZooTVCameraDest = function {
   spline {
       natural_spline
       352, < -55, 59, 170 >
       430, <   0, 20, 180 >
       530, <   0, 30, 180 >
       630, <   0, 30, 180 >
   }
}

#declare CloseUpCameraSource = function {
   spline {
       natural_spline
       631, < 10, 22, 180 >
       731, < 10, 22, 180 >
       3546, < 10, 10.5, 167 >
   }
}

#declare CloseUpCameraDest = function {
   spline {
       natural_spline
       631, < 11, 25, 185 >
       731, < 11, 25, 185 >
       3546, <   -25, 26, 185 >
   }
}

camera {
    // Select camera and destination based on elapsed time
    #switch (FN)
        // Start out by flying up and over the stadium, then start flying in
        #range (1, 150)
            location GuardLightCameraSource(FN)
            look_at GuardLightCameraDest(FN)
            #break;
        #range (151, 351)
            location SpinLightCameraSource(FN)
            look_at SpinLightCameraDest(FN)
            #break;
        #range (352, 630)
            location ZooTVCameraSource(FN)
            look_at ZooTVCameraDest(FN)
            #break;
        #range (631, 3546)
            location CloseUpCameraSource(FN)
            look_at CloseUpCameraDest(FN)
            #break;
    #end
   // Animation
   // location ZooTVCameraSource(FN/FF)
   // look_at ZooTVCameraDest(FN/FF)
   
   // Guard Light
   // location GuardLightCameraSource(FN/FF)
   // look_at GuardLightCameraDest(FN/FF)
   
   // location < 0, 5.5, 169 >
   // location OliveCameraSource(FN/FF)
   // look_at StageCameraDest(FN/FF)
   
   // Distant stage view
   //location < 50, 50, 50 >
   //look_at < 0, 30, 180 >
   
   // Spin Light
   // location < 126, 2, 128 >
   // look_at < 112, 5, 140 >
   
   // Light tower
   // location < 180, 175, -275 >
   // look_at < 126, 160, -234 >
   // location < 0, 5, 0 >   
   // look_at < 146, 167, -264 >
   
   // ZooTV logo view
   //location < -70, 70, 160 >
   //look_at  < -50, 60, 170 >
   
   // Center stage view
   //location < 0, 40, 50 >
   //look_at < 0, 30, 180 >

   // Super close up of Zoo TV
   // location < -63, 63, 166 >   
   // look_at < -55, 59, 170 >
   
   // Rear field
   // location < 10, 5.5, -220 >
   // look_at < 0, -70, 180 >
   
   #if (use_blur)
      focal_point ZooTVCameraDest(FN/FF)
      aperture .125
      blur_samples use_blur
   #end
}   

plane { < 0, 1, 0 >, 0 pigment { color White } }

object {
    Stadium
    texture { Concrete1 }
}

object {
    Spin_Light
    translate < XTrans, 0, ZTrans >
}

object {
    Spin_Light
    rotate < 0, 90, 0 >
    translate < XTrans, 0, -ZTrans >
}
                       
object {
    Spin_Light
    rotate < 0, 180, 0 >
    translate < -XTrans, 0, ZTrans >
}

object {
    Spin_Light
    rotate < 0, 270, 0 >
    translate < -XTrans, 0, -ZTrans >
}
