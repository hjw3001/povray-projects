// stage.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare use_blur = 20*0;
#declare use_radiosity = 0;
#declare rad_brightness = 2;
#declare useLight = false;
#declare displayU2Fans = true;

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
#include "whiteroombasic.inc"
#include "u2fan.inc"
// #include "Fireworks.inc"

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 0;
    #declare FF = 200;
#end

#if (displayU2Fans = true)
    // GenerateLighters(18, 24, 15, 0.5, 6, 3000, 33.69)
    // GenerateLighters(20, 24, 52, 0.5, 4, 3000, 47.07)
    // GenerateLighters(22, 25, 87, 0.5, 3, 3000, 63.4349)

    GenerateFieldCrowd(6720)
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

#declare ZooTVCameraSource = function {
   spline {
       natural_spline
       0.0, < -57, 67, 184 >
       0.2, < -57, 67, 184 >
       1.0, < -40, 5.5, -220 >
       1.0, < 10, 5.5, -220 >
   }
}

#declare ZooTVCameraDest = function {
   spline {
       natural_spline
       0.0, < 0, 0, 0 >
       0.2, < 0, 0, 0 >
       0.8, < 0, -70, 180 >
       1.0, < 0, -70, 180 >
   }
}

camera {
   // Animation
   location ZooTVCameraSource(FN/FF)
   look_at ZooTVCameraDest(FN/FF)

   // location < 0, 5.5, 169 >
   // location OliveCameraSource(FN/FF)
   // look_at StageCameraDest(FN/FF)
   
   // Distant stage view
   // location < 50, 50, 50 >
   // look_at < 0, 30, 180 >
   
   // ZooTV logo view
   // location < -70, 70, 160 >
   // look_at  < -50, 60, 170 >
   
   // Center stage view
   // location < 0, 40, 50 >
   // look_at < 0, 30, 180 >
   
   // Rear field
   // location < 10, 5.5, -220 >
   // look_at < 0, -70, 180 >

   // Super close up of Zoo TV
   // location < -63, 63, 166 >   
   // look_at < -55, 59, 170 >
   #if (use_blur)
      focal_point < -55, 59, 170 >
      aperture .125
      blur_samples use_blur
   #end
}   
/*
object {
   Stadium
   texture {
      pigment { color Gray75 }
      finish { diffuse 0.7 }
   }
}
*/

/*
light_source {
    < 0, 115, 0>
    color rgb 0.7
    media_interaction off
    shadowless
}
*/

// plane { < 0, 1, 0 >, 0 pigment { color Green } }

object {
    Stadium
    texture { Concrete1 }
}