// videowalls.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#if (clock_on=1)
    #declare trainFrame = frame_number;
#else
    #declare trainFrame = 100;
#end

#declare gbFrame = concat("video\\frames\\ztv", str((trainFrame),-4,0), ".bmp");
// #declare frameString = concat("..\\..\\hww\\laptop\\video\\train\\123-",trainFrame),"_IMG.JPG");
#declare gbVideo = pigment {
   image_map {sys gbFrame}
}

#declare TVBoxTexture = texture {
    pigment { color rgb 0.1 }
}

#declare TVScreenWidth = 3.0;
#declare TVScreenDepth = 1.0;
#declare TVScreenRim = 0.1;

#declare SmallVideoWidth = 11.2;
#declare SmallVideoDepth = 2.0;

#declare LargeTwoWidth = 20;
#declare LargeTwoDepth = 2.0;

#declare TVScreen = union {
    // The TV box
    difference {
        box {
            < -(TVScreenWidth/2), 0, -(TVScreenDepth/2) >,
            <  (TVScreenWidth/2), (TVScreenWidth*3/4), TVScreenDepth/2 >
        }
        box {
            < -(TVScreenWidth/2)+TVScreenRim, TVScreenRim, -TVScreenDepth >,
            <  (TVScreenWidth/2)-TVScreenRim, (TVScreenWidth*3/4)-TVScreenRim, TVScreenDepth >
        }
        texture { TVBoxTexture }
    }
    // The TV screen
    box {
        < -(TVScreenWidth/2)+TVScreenRim, TVScreenRim, -(TVScreenDepth/2) >,
        <  (TVScreenWidth/2)-TVScreenRim, (TVScreenWidth*3/4)-TVScreenRim, (TVScreenDepth/2) >
        texture {
            pigment { gbVideo scale < 3, 2.25, 1 > translate < -1.5, 0, 0 > }
            finish { ambient 1 diffuse 0 }
        }
    }
}

#declare SmallVideoScreen = union {
    // The TV box
    difference {
        box {
            < -(SmallVideoWidth/2), 0, -(SmallVideoDepth/2) >,
            <  (SmallVideoWidth/2), (SmallVideoWidth*3/4), SmallVideoDepth/2 >
        }
        box {
            < -(SmallVideoWidth/2)+TVScreenRim, TVScreenRim, -(SmallVideoDepth/2)-TVScreenRim >,
            <  (SmallVideoWidth/2)-TVScreenRim, (SmallVideoWidth*3/4)-TVScreenRim, (SmallVideoDepth/2)-TVScreenRim >
        }
        texture { TVBoxTexture }
    }
    // The TV screen
    box {
        < -(SmallVideoWidth/2)+TVScreenRim, TVScreenRim, -(SmallVideoDepth/2)-TVScreenRim >,
        <  (SmallVideoWidth/2)-TVScreenRim, (SmallVideoWidth*3/4)-TVScreenRim, (SmallVideoDepth/2)-TVScreenRim >
        texture {
            pigment { gbVideo scale < 11.2, 8.4, 1 > translate < -5.6, 0, 0 > }
            finish { ambient 1 diffuse 0 }
        }
    }
}

#declare LargeTWoSectionVideoScreen = union {
    // The bottom TV box
    difference {
        box {
            < -(LargeTwoWidth/2), 0, -(LargeTwoDepth/2) >,
            <  (LargeTwoWidth/2), (LargeTwoWidth*3/4), LargeTwoDepth/2 >
        }
        box {
            < -(LargeTwoWidth/2)+TVScreenRim, TVScreenRim, -LargeTwoDepth >,
            <  (LargeTwoWidth/2)-TVScreenRim, (LargeTwoWidth*3/4)-TVScreenRim, LargeTwoDepth >
        }
        texture { TVBoxTexture }
    }
    // The bottom TV screen
    box {
        < -(LargeTwoWidth/2)+TVScreenRim, TVScreenRim, -(LargeTwoDepth/2)-TVScreenRim >,
        <  (LargeTwoWidth/2)-TVScreenRim, (LargeTwoWidth*3/4)-TVScreenRim, (LargeTwoDepth/2)-TVScreenRim >
        texture {
            pigment { gbVideo scale < 20, 15, 1 > translate < -10, 0, 0 > }
            finish { ambient 1 diffuse 0 }
        }
    }

    // The top TV box
    difference {
        box {
            < -(LargeTwoWidth/2), 0, -(LargeTwoDepth/2) >,
            <  (LargeTwoWidth/2), (LargeTwoWidth*3/4), LargeTwoDepth/2 >
        }
        box {
            < -(LargeTwoWidth/2)+TVScreenRim, TVScreenRim, -LargeTwoDepth >,
            <  (LargeTwoWidth/2)-TVScreenRim, (LargeTwoWidth*3/4)-TVScreenRim, LargeTwoDepth >
        }
        translate < 0, (LargeTwoWidth*3/4), 0 > 
        texture { TVBoxTexture }
    }
    // The top TV screen
    box {
        < -10, 15+TVScreenRim, -1 >,
        <  10, 30-TVScreenRim,  1 >
        texture {
            pigment { TVZooBaby scale < 20, 15, 1 > translate < -10, 15, 0 > }
            finish { ambient 1 diffuse 0 }
        }
    }
}
