// SpkTower.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)
                              
#declare displayStadium = true;
#declare displayDetails = false;
#declare displayU2Fans = true;

#include "colors.inc"
#include "finish.inc"
                    
#include "SpkTower.inc"
#include "field.inc"

#if (displayStadium = true)
#include "stadium.inc"
#include "stage.inc"
#include "scrframe.inc"
#include "olive.inc"
#end

#if (displayDetails = true)
#include "arch.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"
#end

#if (clock_on=1)
    #declare rfact = clock * 360;
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare rfact = 270;
    #declare FN = 100;
    #declare FF = 200;
#end

//light_source { < 1000, 1000, -1000 > color red 1.0 green 1.0 blue 1.0 }

#declare SpkTowerCameraSource = function {
   spline {
       natural_spline
       0.0, <  50,  5, -210 >
       0.1, <  45,  7, -220 >
       0.5, <   0,  9, -230 >
       0.9, < -45, 12, -220 >
       1.0, < -50, 15, -210 >
   }
}

#declare SpkTowerCameraDest = function {
   spline {
       natural_spline
       0.0, <  60,  30, -150 >
       // 0.1, <  55,  40, -150 >
       0.5, <   0,  10, -160 >
       // 0.9, < -25,  40, -150 >
       1.0, < -50,  30, -150 >
   }
}

#if (displayStadium = true)
object {
   Stadium
   texture { Concrete1 }
}
#end

camera {
   // 300 level
   // location < 20, 5, -220 >
   // look_at < 0, 40, -160 >
   
   location ThirdStadiumLevelSource(rfact)
   look_at SpkTowerCameraDest(FN/FF)


   // Mid field, looking at light tower
   // location < 1, 5, -20 >
   // look_at < 0, 60, -160 >

   // Aireal view
   // location < 40, 450, 85 >
   // look_at < 0, 20, 10 >

   // B stage
//   location < 40, 5.8, 85 >
//   right < 16/9, 0, 0 >
//   look_at < 0, 40, 190 >
}
/*
light_source {
    < 0, 15, 0>
    color rgb 0.7 * ambientLightIntensity
    media_interaction off
    shadowless
}
*/

#declare numLights = 6;
#declare lightPowerArray = array[numLights];
#declare lightDirArray = array[numLights];

#declare lCounter = 0;
#declare initGen = seed(360);
#while (lCounter < numLights)
    #declare lightPowerArray[lCounter] = rand(initGen) * 0.5;
    #if (lightPowerArray[lCounter] > 0.25)
        #declare lightDirArray[lCounter] = true;
    #else
        #declare lightDirArray[lCounter] = false;
    #end
    #declare lCounter = lCounter + 1;
#end

#declare fCounter = 0;
#declare initVal = 0.05;

#while (fCounter < FN)
    #declare lCounter = 0;
    #while (lCounter < numLights)
        #if (lightDirArray[lCounter] = true)
            #declare lightPowerArray[lCounter] = lightPowerArray[lCounter] + initVal;
            #if (lightPowerArray[lCounter] > 0.5)
                #declare lightDirArray[lCounter] = false;
            #end
        #else
            #declare lightPowerArray[lCounter] = lightPowerArray[lCounter] - initVal;
            #if (lightPowerArray[lCounter] < 0)
                #declare lightPowerArray[lCounter] = 0;
                #declare lightDirArray[lCounter] = true;
            #end
        #end
        #declare lCounter = lCounter + 1;
    #end
    #declare fCounter = fCounter + 1;
#end


#declare N=3;       // Divisions per side
#declare DX=13/N;   // Dimensions of sub patches
#declare DZ=10.5/N;
#declare lightHeight1 = 25;
#declare lightHeight2 = 1;
#declare lightHeight3 = 45;
#declare boxHeight = 50;

box {
    < -2, ((boxHeight/2) - 2), 202 >,
    <  2, ((boxHeight/2) + 2), 200 >
    no_shadow
    pigment { rgb < (lightPowerArray[0] * 2), (lightPowerArray[0] * 2), (lightPowerArray[0] * 2) > }
    finish { ambient 0.78 diffuse 0 }
}
light_source {
    < 0, (boxHeight/2), 200 >
    // color LightColor*lightPower
    color rgb < (lightPowerArray[0] * 2), (lightPowerArray[0] * 2), (lightPowerArray[0] * 2) > * lightPowerArray[0]
    area_light x, y, 4, 4 jitter adaptive 0
    spotlight radius -90 falloff 90 tightness 1 point_at < 0, (boxHeight/2), -100 > // for cosine falloff
    fade_power 2 fade_distance 200
}

box {
    < 22, ((boxHeight/2) - 2), 202 >,
    < 18, ((boxHeight/2) + 2), 200 >
    no_shadow
    pigment { rgb < (lightPowerArray[1] * 2), (lightPowerArray[1] * 2), (lightPowerArray[1] * 2) > }
    finish { ambient 0.78 diffuse 0 }
}
light_source {
    < 20, (boxHeight/2), 200 >
    color rgb < (lightPowerArray[1] * 2), (lightPowerArray[1] * 2), (lightPowerArray[1] * 2) > * lightPowerArray[1]
    area_light x, y, 4, 4 jitter adaptive 0
    spotlight radius -90 falloff 90 tightness 1 point_at < 20, (boxHeight/2), -100 > // for cosine falloff
    fade_power 2 fade_distance 200
}

box {
    < -22, ((boxHeight/2) - 2), 202 >,
    < -18, ((boxHeight/2) + 2), 200 >
    no_shadow
    pigment { rgb < (lightPowerArray[2] * 2), (lightPowerArray[2] * 2), (lightPowerArray[2] * 2) > }
    finish { ambient 0.78 diffuse 0 }
}
light_source {
    < -20, (boxHeight/2), 200 >
    color rgb < (lightPowerArray[2] * 2), (lightPowerArray[2] * 2), (lightPowerArray[2] * 2) > * lightPowerArray[2]
    area_light x, y, 4, 4 jitter adaptive 0
    spotlight radius -90 falloff 90 tightness 1 point_at < -20, (boxHeight/2), -100 > // for cosine falloff
    fade_power 2 fade_distance 200
}



box {
    < -2, ((boxHeight) - 2), 202 >,
    <  2, ((boxHeight) + 2), 200 >
    no_shadow
    pigment { rgb < (lightPowerArray[3] * 2), (lightPowerArray[3] * 2), (lightPowerArray[3] * 2) > }
    finish { ambient 0.78 diffuse 0 }
}
light_source {
    < 0, (boxHeight), 200 >
    // color LightColor*lightPower
    color rgb < (lightPowerArray[3] * 2), (lightPowerArray[3] * 2), (lightPowerArray[3] * 2) > * lightPowerArray[3]
    area_light x, y, 4, 4 jitter adaptive 0
    spotlight radius -90 falloff 90 tightness 1 point_at < 0, (boxHeight), -100 > // for cosine falloff
    fade_power 2 fade_distance 200
}

box {
    < 22, ((boxHeight) - 2), 202 >,
    < 18, ((boxHeight) + 2), 200 >
    no_shadow
    pigment { rgb < (lightPowerArray[4] * 2), (lightPowerArray[4] * 2), (lightPowerArray[4] * 2) > }
    finish { ambient 0.78 diffuse 0 }
}
light_source {
    < 20, (boxHeight), 200 >
    color rgb < (lightPowerArray[4] * 2), (lightPowerArray[4] * 2), (lightPowerArray[4] * 2) > * lightPowerArray[4]
    area_light x, y, 4, 4 jitter adaptive 0
    spotlight radius -90 falloff 90 tightness 1 point_at < 20, (boxHeight), -100 > // for cosine falloff
    fade_power 2 fade_distance 200
}

box {
    < -22, ((boxHeight) - 2), 202 >,
    < -18, ((boxHeight) + 2), 200 >
    no_shadow
    pigment { rgb < (lightPowerArray[5] * 2), (lightPowerArray[5] * 2), (lightPowerArray[5] * 2) > }
    finish { ambient 0.78 diffuse 0 }
}
light_source {
    < -20, (boxHeight), 200 >
    color rgb < (lightPowerArray[5] * 2), (lightPowerArray[5] * 2), (lightPowerArray[5] * 2) > * lightPowerArray[5]
    area_light x, y, 4, 4 jitter adaptive 0
    spotlight radius -90 falloff 90 tightness 1 point_at < -20, (boxHeight), -100 > // for cosine falloff
    fade_power 2 fade_distance 200
}

#if (displayU2Fans = true)
#include "u2fan.inc"

#declare ranGen = seed(360);

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

}    
#end