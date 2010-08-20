// u2fan2.pov
//
// Created by: Henry Wagner (povray@henrywagner.org)

#declare displayStadium = true;
#declare displayU2Fans = true;
#declare fancyLights = false;

#include "colors.inc"
#include "field.inc"
#if (displayU2Fans = true)
#include "u2fan.inc"
#end
// #include "stage.inc"
#if (displayStadium = true)
#include "stadium.inc"
/*
#include "scrframe.inc"
#include "screen.inc"
#include "olive.inc"
#include "arch.inc"
#include "speakers.inc"
#include "SpeaNeon.inc"
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
*/
#end

global_settings {
    ambient_light rgb < 1, 1, 1 > * 2
}

#if (clock_on=1)
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare FN = 1;
    #declare FF = 1;
#end

#if (displayU2Fans = true)
GenerateFieldCrowd(500)
#end

#if (clock_on=1)
    #declare rfact = clock;
    #declare FN = frame_number;
    #declare FF = final_frame;
#else
    #declare rfact = 1;
    #declare FN = 150;
    #declare FF = 1000;
#end

#if (displayStadium = true)
#declare U2FanCameraSource = function {
   spline {
       natural_spline
       0.0, <  30, 3.0, 164 >
       0.4  <   0, 5.5, 164 >
       1.0, < -20,  10, 140 >
   }
}
#end

camera {
    // location < 0, 5.5, 164 >
    #if (displayStadium = true)
    location U2FanCameraSource(FN/FF)
    // location FirstStadiumLevelSource(310)
    #else
    location < 10, 500, -100 >
    #end
    look_at < 0, 5, -20 >
}

#if (displayStadium = true)
object {
    Stadium
    texture { Concrete1 }
}
#end


#if (fancyLights = true)
#declare numLights = 18;
#declare lightPowerArray = array[numLights];
#declare lightDirArray = array[numLights];
#declare lightSpdArray = array[numLights];
#declare maxLightPower = 0.7;

#declare lCounter = 0;
#declare initGen = seed(360);
#while (lCounter < numLights)
    #declare lightPowerArray[lCounter] = rand(initGen) * maxLightPower;
    #if (lightPowerArray[lCounter] > (maxLightPower/2))
        #declare lightDirArray[lCounter] = true;
    #else
        #declare lightDirArray[lCounter] = false;
    #end
    #declare lightSpdArray[lCounter] = (rand(initGen) * 0.02) + 0.02;
    #declare lCounter = lCounter + 1;
#end

#declare fCounter = 0;
// #declare initVal = 0.04;

#while (fCounter < FN)
    #declare lCounter = 0;
    #while (lCounter < numLights)
        #if (lightDirArray[lCounter] = true)
            #declare lightPowerArray[lCounter] = lightPowerArray[lCounter] + lightSpdArray[lCounter];
            #if (lightPowerArray[lCounter] > maxLightPower)
                #declare lightDirArray[lCounter] = false;
            #end
        #else
            #declare lightPowerArray[lCounter] = lightPowerArray[lCounter] - lightSpdArray[lCounter];
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
#declare lightHeight2 = 45;
#declare lightHeight3 = 65;
#declare boxHeight = 50;

#macro GenerateBoxLight(xCord, yCord, zCord, lightNum)
union {
    box {
        < (xCord - 2), (yCord - 2), 201.0 >,
        < (xCord + 2), (yCord + 2), 200.5 >
        no_shadow
        pigment { rgb < 0, 0, 0 > }
        finish { ambient 0.78 diffuse 0 }
    }
    box {
        < (xCord - 2), (yCord - 2), 200.5 >,
        < (xCord + 2), (yCord + 2), 200.0 >
        no_shadow
        pigment { rgb < (lightPowerArray[lightNum] * 2), (lightPowerArray[lightNum] * 2), (lightPowerArray[lightNum] * 2) > }
        finish { ambient 0.78 diffuse 0 }
    }
    light_source {
        < xCord, yCord, 200 >
        color rgb < (lightPowerArray[lightNum] * 2), (lightPowerArray[lightNum] * 2), (lightPowerArray[lightNum] * 2) > * lightPowerArray[lightNum]
        area_light x, y, 2, 2 jitter adaptive 0
        spotlight radius -90 falloff 90 tightness 1 point_at < xCord, yCord, -100 > // for cosine falloff
        fade_power 2 fade_distance 200
    }
}
#end

GenerateBoxLight(-65, 25, 201.5, 0)
GenerateBoxLight(-65, 45, 201.5, 1)
GenerateBoxLight(-65, 65, 201.5, 2)

GenerateBoxLight(-37, 25, 201.5, 3)
GenerateBoxLight(-37, 45, 201.5, 4)
GenerateBoxLight(-37, 65, 201.5, 5)

GenerateBoxLight(-9, 25, 201.5, 6)
GenerateBoxLight(-9, 45, 201.5, 7)
GenerateBoxLight(-9, 65, 201.5, 8)

GenerateBoxLight(19, 25, 201.5, 9)
GenerateBoxLight(19, 45, 201.5, 10)
GenerateBoxLight(19, 65, 201.5, 11)

GenerateBoxLight(47, 25, 201.5, 12)
GenerateBoxLight(47, 45, 201.5, 13)
GenerateBoxLight(47, 65, 201.5, 14)

GenerateBoxLight(75, 25, 201.5, 15)
GenerateBoxLight(75, 45, 201.5, 16)
GenerateBoxLight(75, 65, 201.5, 17)
#else
light_source {
    < -1000, 1000, 1000 >
    color rgb 0.4
}
light_source {
    < 0, 115, 0>
    color rgb 0.7
    media_interaction off
    shadowless
}
#end
