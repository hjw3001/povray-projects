// testarea.pov

#declare displayStadium = true;
#declare useRad = true;

#if (clock_on=1)
    #declare FN = frame_number;
    #declare rfact = clock * 360;
#else
    #declare FN = 10;
    #declare rfact = 270;
#end

global_settings{
    assumed_gamma 2.2
    #if (useRad = true)
    /*
    radiosity{
        pretrace_start 0.04
        pretrace_end 0.01
        count 200
        recursion_limit 3
        nearest_count 10
        error_bound 0.5
    }
    */
    #end
}

#include "colors.inc"
#include "finish.inc"
#include "field.inc"
#if (displayStadium = true)
#include "stadium.inc"
#include "stage.inc"
#include "scrframe.inc"
#include "olive.inc"
#include "SpkTower.inc"
#end

#declare XTrans = 120;
#declare ZTrans = 140;

#include "SpinLght.inc"

#declare boxHeight = 50;

box {
    < -100, 0, -1 >
    <  -80, boxHeight,  1 >
    pigment { color Red }
}

box {
    <  100, 0, -1 >
    <   80, boxHeight,  1 >
    pigment { color Blue }
}
/*
box {
    < -1, 0,  80 >,
    <  1, boxHeight, 100 >
    pigment { color Yellow }
}
*/
box {
    < -1, 0,  -80 >,
    <  1, boxHeight, -100 >
    pigment { color Plum }
}

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

#declare lightPower = 0.5;
#if (useRad = true)
    #declare LightColor= < 1, 0.67, 0.21 >;
    
    #declare N=3;       // Divisions per side
    #declare DX=13/N;   // Dimensions of sub patches
    #declare DZ=10.5/N;
    #declare lightHeight1 = 25;
    #declare lightHeight2 = 1;
    #declare lightHeight3 = 45;

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

    /*    
    #declare SubPatch = light_source {
        < 0, lightHeight2, -1.5 >
        color LightColor*7
        area_light DX*y, DZ*z, 4, 4 jitter adaptive 0
        spotlight radius -90 falloff 90 tightness 1 point_at < 0, lightHeight2, -100 > // for cosine falloff
        fade_power 2 fade_distance (DX+DZ)/2
    }
    
    #declare i=0;#while (i<N)
      #declare j=0;#while (j<N)
         light_source{SubPatch translate<0,i*DX-(13-DX)/2,j*DZ-(10.5-DZ)/2>}
      #declare j=j+1;#end
    #declare i=i+1;#end
    */
    
#else
    light_source { < 1000, 1000, -1000 > color red 1.0 green 1.0 blue 1.0 }
#end

camera {
    // location < 20, 5, -5 >
    // look_at < 0, 12, -100 >
    
    // location < 0, 200, -45 >
    // look_at < 0, 1, -55 >
    
    location ThirdStadiumLevelSource(270)
    look_at < 0, 15, 185 >
    
    // location < 20, 5, -100 >
    // look_at < 0, (boxHeight/2), 0 >
}

#if (displayStadium = true)
object {
   Stadium
   texture { Concrete1 }
}
#end
/*
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

*/