// u2fan.pov
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#version unofficial megapov 1.1;

#declare use_blur = 20*0;
#declare use_radiosity = 2;
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

#include "colors.inc"
#include "u2fan.inc"
#include "field.inc"
#include "stadium.inc"
#include "Fireworks.inc"

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 100;
    #declare FF = 200;
#end

#declare U2FanCameraSource = function {
   spline {
       natural_spline
       0.0, <   5.5, 4, 6 >
       0.5, <  -5.0, 3, 10 >
       1.0, < -15.5, 2, 6 >
   }
}

#declare U2FanCameraDest = function {
   spline {
       natural_spline
       0.0, <   0, 3.0, 2 >
       1.0, < -10. 3.5, 2 >
   }
}

camera {
   location U2FanCameraSource(FN/FF)
   look_at U2FanCameraDest(FN/FF)
}

object {
   Stadium
   texture { Concrete1 }
}

//#include "fldchrs.inc"

#declare ranGen = seed(360);

// object { Chair }

InitU2FanData(28)
/*
camera {
    location < 5.5, 4, 6 >
    look_at < 0, 3, 2 >
}
*/
union {
    union {
        GenerateU2Fan(ranGen, 0)
        translate < 0, 0, 0 >
    }
    union {
        GenerateU2Fan(ranGen, 1)
        translate < 2.5, 0, 0 >
    }
    union {
        GenerateU2Fan(ranGen, 2)
        translate < -2.5, 0, 0 >
    }
    union {
        GenerateU2Fan(ranGen, 3)
        translate < -5, 0, 0 >
    }
    union {
        GenerateU2Fan(ranGen, 4)
        translate < -7.5, 0, 0 >
    }
    union {
        GenerateU2Fan(ranGen, 5)
        translate < -10, 0, 0 >
    }
    union {
        GenerateU2Fan(ranGen, 6)
        translate < -12.5, 0, 0 >
    }

    union {
        GenerateU2Fan(ranGen, 7)
        translate < 0, 0, 2 >
    }
    union {
        GenerateU2Fan(ranGen, 8)
        translate < 2.5, 0, 2 >
    }
    union {
        GenerateU2Fan(ranGen, 9)
        translate < -2.5, 0, 2 >
    }
    union {
        GenerateU2Fan(ranGen, 10)
        translate < -5, 0, 2 >
    }
    union {
        GenerateU2Fan(ranGen, 11)
        translate < -7.5, 0, 2 >
    }
    union {
        GenerateU2Fan(ranGen, 12)
        translate < -10, 0, 2 >
    }
    union {
        GenerateU2Fan(ranGen, 13)
        translate < -12.5, 0, 2 >
    }

    union {
        GenerateU2Fan(ranGen, 14)
        translate < 0, 0, 4 >
    }
    union {
        GenerateU2Fan(ranGen, 15)
        translate < 2.5, 0, 4 >
    }
    union {
        GenerateU2Fan(ranGen, 16)
        translate < -2.5, 0, 4 >
    }
    union {
        GenerateU2Fan(ranGen, 17)
        translate < -5, 0, 4 >
    }
    union {
        GenerateU2Fan(ranGen, 18)
        translate < -7.5, 0, 4 >
    }
    union {
        GenerateU2Fan(ranGen, 19)
        translate < -10, 0, 4 >
    }
    union {
        GenerateU2Fan(ranGen, 20)
        translate < -12.5, 0, 4 >
    }

    union {
        GenerateU2Fan(ranGen, 21)
        translate < 0, 0, -2 >
    }
    union {
        GenerateU2Fan(ranGen, 22)
        translate < 2.5, 0, -2 >
    }
    union {
        GenerateU2Fan(ranGen, 23)
        translate < -2.5, 0, -2 >
    }
    union {
        GenerateU2Fan(ranGen, 24)
        translate < -5, 0, -2 >
    }
    union {
        GenerateU2Fan(ranGen, 25)
        translate < -7.5, 0, -2 >
    }
    union {
        GenerateU2Fan(ranGen, 26)
        translate < -10, 0, -2 >
    }
    union {
        GenerateU2Fan(ranGen, 27)
        translate < -12.5, 0, -2 >
    }

}    
/*
light_source {
    < 10000, 10000, 10000 >
    color White + Gold
    parallel
    point_at < 0, 0, 0 >
}
*/