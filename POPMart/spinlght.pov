// SpinLght.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)

#version 3.5;

global_settings { assumed_gamma 2.2 }

#declare displayStadium = true;
#declare displayChairs = true;
#declare displayScreen = true;
#declare displayLemon = true;

#declare XTrans = 120;
#declare ZTrans = 140;

#include "colors.inc"
#include "finish.inc"
#include "SpinLght.inc"
#include "arch.inc"
#include "Stage.inc"
#include "olive.inc"
#include "speakers.inc"
#include "Scrframe.inc"
#include "SpeaNeon.inc"
#if (displayScreen = true)
#include "screen.inc"
#end
#if (displayStadium = true)
#include "stadium.inc"
#end
#include "field.inc"
// #include "environofog.inc"
// #include "atmos.inc"
#include "SpkTower.inc"
#if (displayChairs = true)
#include "fldchrs.inc"
#end
#if (displayLemon = true)
#include "lemon.inc"
#end
#if (displayScreen = true)
#include "support1.inc"
#include "support2.inc"
#include "support3.inc"
#include "support4.inc"
#include "support5.inc"
#include "support6.inc"
#include "support.inc"
#include "TopLght.inc"
#include "TopLight.inc"
#end

#if (clock_on=1)
    #declare rfact = clock * 360;
    #declare cclock = clock;
#else
    #declare rfact = 160;
    #declare cclock = 0;
#end

#declare LemonYellow=0;
#declare LemonSpinFactor=360 * 10;

background { color Black }

#if (displayScreen = true)
object { TopLightRig }
#end

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
/*
#declare CameraSourceHighRes = function {
   spline {
       linear_spline
       0.0, <     0,  15,  185 > // Standing center stage
       0.1, < -78.5, 5.5, -132 > // Back left corner of field
       0.2, < -27.5, 5.5, -132 > // Back left aisle of field
       0.3, < -27.5, 5.5,  132 > // Closer up in left aisle
       0.4, ThirdStadiumLevelSource(0)
       0.5, SecondStadiumLevelSource(180)
       0.6, FirstStadiumLevelSource(270)
       0.7, <    50,  45,  135 > // Looking at the Lemon
       0.8, <  27.5,   6,  142 > // Looking at the Lemon from the crowd
       0.9, <    80,   3,  132 > // Front right corner for field crowd
   }
}

#declare CameraDestHighRes = function {
   spline {
       linear_spline
       0.0, <  0,  4,   0 > // Looking out to the center of the field
       0.1, <  0, 15, 185 > // Looking at center stage
       0.2, <  0, 15, 185 > // Looking at center stage
       0.3, <  0, 15, 185 > // Looking at center stage
       0.4, <  0, 15, 185 > // Looking at center stage
       0.5, <  0, 15, 185 > // Looking at center stage
       0.6, <  0, 15, 185 > // Looking at center stage
       0.7, < 60, 30, 175 > // Looking at the Lemon
       0.8, < 60, 30, 175 > // Looking at the Lemon
       0.9, <  0,  4,   0 > // Looking out to the center of the field
   }
}
*/
#declare CameraSource = function {
   spline {
       natural_spline
       0.0, <     0, 15,  185 > // Standing center stage
       // 0.2, < -78.5, 10,  132 > // Back left corner of field
       0.4, < -78.5,  5, -132 > // Back left corner of field
       0.6, <     0, 20,    0 > // Back left aisle of field
       1.0, <  78.5,  5,  132 > // Back left corner of field
   }
}

#declare CameraDest = function {
   spline {
       natural_spline
       0.0, <  0,  4, -132 > // Looking out to the center of the field
       1.0, <  0, 15,  185 > // Looking at center stage
   }
}

camera {
   // location < 15, 12, 0 >
   // look_at < -100, 5, 0 >
   
   // location < 40, 600, 85 >
   // location FirstStadiumLevelSource(rfact)
   /*
   #switch (rfact)
    #range (0, 120)
        location ThirdStadiumLevelSource(rfact)
        #break
    #range (120, 240)
        location SecondStadiumLevelSource(rfact)
        #break
    #else
        location FirstStadiumLevelSource(rfact)
   #end
   look_at < 0, 15, 185 >
   */
   
   // location FirstStadiumLevelSource(rfact)
   
   // Back left corner of seats
   // location < -78.5, 5.5, -132 >
   
   // Back left asle of seats
   // location < -27.5, 5.5, -132 >
   
   // Center stage
   // look_at < 0, 15, 185 >
    
   // look_at FirstStadiumLevelSource(rfact)
   // look_at < 0, 20, 10 >
   
   // location < 15, 5, 9 >
   
   // location < 0, 15, 185 >
   // look_at < 0, 4, 0 >
   location CameraSource(cclock)
   look_at CameraDest(cclock)
   // look_at < 0, 4, 0 >
}

/*
#declare j = 10;
#declare sRad = 1;

#while (j < 360)
    sphere { FirstStadiumLevelSource(j), sRad pigment { color Red } }
    sphere { SecondStadiumLevelSource(j), sRad pigment { color Green } }
    sphere { ThirdStadiumLevelSource(j), sRad pigment { color Blue } }
    
    #declare j = j + 10;
#end
*/
#if (displayStadium = true)
object {
   Stadium
   texture { Concrete1 }
}
#end

light_source { <0, 115, 170> color rgb 0.7
  media_interaction off
}

light_source { <0, 50, -170> color rgb 0.7
  media_interaction off
  shadowless
}

/*
light_source {
    < 1000, 1000, 1000 >
    color White
}
*/

#if (displayChairs = true)
object {
    FieldSeating
    translate < -78.5, 0, -132 >
}
#end

#if (displayLemon = true)
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
#end
