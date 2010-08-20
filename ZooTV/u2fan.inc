// u2fan.inc
//
// Generate a U2 Fan with random characteristics

#version unofficial megapov 1.2;

#if (clock_on=1)
    #declare FN = frame_number;
#else
    #declare FN = 0;
#end

#declare RsA = seed(574647);

#declare rFireoffset = 0.1;
#declare gFireoffset = 0.1;
#declare bFireoffset = 0.1;

#declare rSkinOffset = 0.2;
#declare gSkinOffset = 0.3;
#declare bSkinOffset = 0.2;

// #declare numFans = 6720;
// #declare numFans = 35;
#declare numFans = 6720;

// Torso
#declare fanTorsoRot = array[numFans];
#declare fanTorsoDir = array[numFans];
#declare fanTorsoSpd = array[numFans];

// Upper Left Arm
#declare fanUpperLeftArmRot = array[numFans];
#declare fanUpperLeftArmDir = array[numFans];
#declare fanUpperLeftArmSpd = array[numFans];

// Upper Right Arm
#declare fanUpperRightArmRot = array[numFans];
#declare fanUpperRightArmDir = array[numFans];
#declare fanUpperRightArmSpd = array[numFans];

// Lower Left Arm
#declare fanLowerLeftArmRot = array[numFans];
#declare fanLowerLeftArmDir = array[numFans];
#declare fanLowerLeftArmSpd = array[numFans];

// Lower Right Arm
#declare fanLowerRightArmRot = array[numFans];
#declare fanLowerRightArmDir = array[numFans];
#declare fanLowerRightArmSpd = array[numFans];

#declare initGen = seed(360);
#declare nOffset = 4;

#declare counter = 0;
#while (counter < numFans)
    #declare fanTorsoRot[counter] = (rand(initGen) * 60) - 30;
    #if (fanTorsoRot[counter] < 0)
        #declare fanTorsoDir[counter] = false;
    #else
        #declare fanTorsoDir[counter] = true;
    #end
    #declare fanTorsoSpd[counter] = (rand(initGen) * 3) + 1;

    #declare fanUpperLeftArmRot[counter] = (rand(initGen) * -40) - 140;
    #if (fanUpperLeftArmRot[counter] < 0)
        #declare fanUpperLeftArmDir[counter] = false;
    #else
        #declare fanUpperLeftArmDir[counter] = true;
    #end
    #declare fanUpperLeftArmSpd[counter] = (rand(initGen) * 3) + 2;

    #declare fanUpperRightArmRot[counter] = (rand(initGen) * -40) - 140;
    #if (fanUpperRightArmRot[counter] < 0)
        #declare fanUpperRightArmDir[counter] = false;
    #else
        #declare fanUpperRightArmDir[counter] = true;
    #end
    #declare fanUpperRightArmSpd[counter] = (rand(initGen) * 3) + 2;

    #declare fanLowerLeftArmRot[counter] = (rand(initGen) * -45);
    #if (fanLowerLeftArmRot[counter] < 0)
        #declare fanLowerLeftArmDir[counter] = false;
    #else
        #declare fanLowerLeftArmDir[counter] = true;
    #end
    #declare fanLowerLeftArmSpd[counter] = (rand(initGen) * 3) + 2;

    #declare fanLowerRightArmRot[counter] = (rand(initGen) * -45);
    #if (fanLowerRightArmRot[counter] < 0)
        #declare fanLowerRightArmDir[counter] = false;
    #else
        #declare fanLowerRightArmDir[counter] = true;
    #end
    #declare fanLowerRightArmSpd[counter] = (rand(initGen) * 3) + 2;

    #declare counter = counter + 1;
#end

#if (clock_on=1)
    // Increment the lights to the new position
    #declare loopCounter = 0;
    #while (loopCounter < FN)
        #declare fanCounter = 0;
        #while (fanCounter < numFans)
            #if (fanTorsoDir[fanCounter] = true)
                #declare fanTorsoRot[fanCounter] = fanTorsoRot[fanCounter] + fanTorsoSpd[fanCounter];
                #if (fanTorsoRot[fanCounter] >= 30)
                    #declare fanTorsoDir[fanCounter] = false;
                #end
            #else
                #declare fanTorsoRot[fanCounter] = fanTorsoRot[fanCounter] - fanTorsoSpd[fanCounter];
                #if (fanTorsoRot[fanCounter] <= -30)
                    #declare fanTorsoDir[fanCounter] = true;
                #end
            #end

            #if (fanUpperLeftArmDir[fanCounter] = true)
                #declare fanUpperLeftArmRot[fanCounter] = fanUpperLeftArmRot[fanCounter] + fanUpperLeftArmSpd[fanCounter];
                #if (fanUpperLeftArmRot[fanCounter] >= -130)
                    #declare fanUpperLeftArmDir[fanCounter] = false;
                #end
            #else
                #declare fanUpperLeftArmRot[fanCounter] = fanUpperLeftArmRot[fanCounter] - fanUpperLeftArmSpd[fanCounter];
                #if (fanUpperLeftArmRot[fanCounter] <= -180)
                    #declare fanUpperLeftArmDir[fanCounter] = true;
                #end
            #end

            #if (fanUpperRightArmDir[fanCounter] = true)
                #declare fanUpperRightArmRot[fanCounter] = fanUpperRightArmRot[fanCounter] + fanUpperRightArmSpd[fanCounter];
                #if (fanUpperRightArmRot[fanCounter] >= -130)
                    #declare fanUpperRightArmDir[fanCounter] = false;
                #end
            #else
                #declare fanUpperRightArmRot[fanCounter] = fanUpperRightArmRot[fanCounter] - fanUpperLeftArmSpd[fanCounter];
                #if (fanUpperRightArmRot[fanCounter] <= -180)
                    #declare fanUpperRightArmDir[fanCounter] = true;
                #end
            #end

            #if (fanLowerLeftArmDir[fanCounter] = true)
                #declare fanLowerLeftArmRot[fanCounter] = fanLowerLeftArmRot[fanCounter] + fanLowerLeftArmSpd[fanCounter];
                #if (fanLowerLeftArmRot[fanCounter] >= 0)
                    #declare fanLowerLeftArmDir[fanCounter] = false;
                #end
            #else
                #declare fanLowerLeftArmRot[fanCounter] = fanLowerLeftArmRot[fanCounter] - fanLowerLeftArmSpd[fanCounter];
                #if (fanLowerLeftArmRot[fanCounter] <= -60)
                    #declare fanLowerLeftArmDir[fanCounter] = true;
                #end
            #end

            #if (fanLowerRightArmDir[fanCounter] = true)
                #declare fanLowerRightArmRot[fanCounter] = fanLowerRightArmRot[fanCounter] + fanLowerRightArmSpd[fanCounter];
                #if (fanLowerRightArmRot[fanCounter] >= 0)
                    #declare fanLowerRightArmDir[fanCounter] = false;
                #end
            #else
                #declare fanLowerRightArmRot[fanCounter] = fanLowerRightArmRot[fanCounter] - fanLowerRightArmSpd[fanCounter];
                #if (fanLowerRightArmRot[fanCounter] <= -60)
                    #declare fanLowerRightArmDir[fanCounter] = true;
                #end
            #end

            #declare fanCounter = fanCounter + 1;        
        #end    
        #declare loopCounter = loopCounter + 1;
    #end
#end
    
#macro GenerateU2Fan(ranGen, fanNum)
// Setup the proporations
#local headSize = (rand(ranGen) * 0.05) + 0.2;

#local neckDia = (rand(ranGen) * 0.075) + 0.025;
#local neckLength = 0.4;

#local shirtTexture = texture {
    pigment { rgb < rand(ranGen), rand(ranGen), rand(ranGen) > }
}

#local shortsTexture = texture {
    pigment { rgb < rand(ranGen), rand(ranGen), rand(ranGen) > }
}

#local shoeTexture = texture {
    pigment { rgb < rand(ranGen), rand(ranGen), rand(ranGen) > }
}

#local fireTexture = texture {
    pigment { rgb < 0.858824 + (rand(ranGen) * rFireoffset) - (rFireoffset/2),
                    0.858824 + (rand(ranGen) * gFireoffset) - (gFireoffset/2),
                    0.439216 + (rand(ranGen) * bFireoffset) - (bFireoffset/2) > }
    finish {
        ambient 1
        diffuse 0
    }
}

#local SkinTexture = texture {
    pigment { rgb < 0.96 + (rand(ranGen) * rSkinOffset) - (rSkinOffset/2),
                    0.80 + (rand(ranGen) * gSkinOffset) - (gSkinOffset/2),
                    0.69 + (rand(ranGen) * bSkinOffset) - (bSkinOffset/2) > }
    finish {
        phong .1
        phong_size 40
    }
}

#local shoulderLength = (rand(ranGen) * 1) + 0.5;
#local shoulderDia = (rand(ranGen) * 0.2) + 0.05;

#local torsoLength = (rand(ranGen) * 0.5) + 1.3;
#local torsoDia = (rand(ranGen) * 0.1) + 0.25;
#local torsoRot = fanTorsoRot[fanNum];

#local waistLength = (rand(ranGen) * 0.2) + 0.7;
#local waistDia = (rand(ranGen) * 0.05) + 0.175;

#local upperLegLength = (rand(ranGen) * 0.2) + 1.2;
#local upperLegDia = (rand(ranGen) * 0.05) + 0.1;

#local kneeDia = (rand(ranGen) * 0.025) + 0.1;

#local lowerLegLength = (rand(ranGen) * 0.2) + 1.4;
#local lowerLegDia = (rand(ranGen) * 0.02) + 0.06;

#local upperArmLength = (rand(ranGen) * 0.1) + 0.5;
#local upperArmDia = (rand(ranGen) * 0.01) + 0.05;

#local upperArmRotLeft = fanUpperLeftArmRot[fanNum];
#local upperArmRotRight = fanUpperRightArmRot[fanNum];

#local elbowDia = (rand(ranGen) * 0.01) + 0.08;

#local lowerArmLength = (rand(ranGen) * 0.1) + 0.8;
#local lowerArmDia = (rand(ranGen) * 0.01) + 0.03;

#local lowerArmRotLeft = fanLowerLeftArmRot[fanNum];
#local lowerArmRotRight = fanLowerRightArmRot[fanNum];

#local handDia = (rand(ranGen) * 0.01) + 0.05;

#local footLength = (rand(ranGen) * 0.1) + 0.6;
#local footWidth = (rand(ranGen) * 0.1) + 0.25;
#local footHeight = (rand(ranGen) * 0.01) + 0.02;

#local lightHand = (rand(ranGen) * 10);
#local hasLight = (rand(ranGen) * 10);

#local lightClip = 7.1;

// What makes up a person?

union {
    // Head
    sphere {
        < 0, torsoLength + neckLength, 0 >,
        headSize
        texture { SkinTexture }
    }
    // Neck
    cylinder {
        < 0, torsoLength, 0 >,
        < 0, torsoLength + neckLength, 0 >,
        neckDia
        texture { SkinTexture }    
    }
    // Shoulders
    cylinder { 
        < -(shoulderLength/2), torsoLength, 0 >,
        <  (shoulderLength/2), torsoLength, 0 >,
        shoulderDia
        texture { shirtTexture }
    }
    union {
        sphere {
            < -(shoulderLength/2), torsoLength, 0 >,
            shoulderDia
            texture { shirtTexture }
        }
        // Add arm
        union {
            cone {
                < 0, 0, 0 >, shoulderDia
                < 0, -upperArmLength, 0 >, upperArmDia
                texture { shirtTexture }
            }
            sphere {
                < 0, -upperArmLength, 0 >,
                elbowDia
                texture { SkinTexture }
            }
            // Add lower arm
            union {
                cone {
                    < 0, 0, 0 >, elbowDia
                    < 0, -lowerArmLength, 0 >, lowerArmDia
                }
                // Add the hand
                sphere {
                    < 0, -lowerArmLength, 0 >,
                    handDia
                }
                // Add the lighter
                #if (hasLight > lightClip)
                    #if (lightHand > 5)
                    /*
                    light_source {
                        < 0, (-lowerArmLength-(handDia*2)), 0>,
            		    color rgb 0.045*< rand(RsA), rand(RsA), rand(RsA)>
            		    glow { size rand(RsA)*0.5 type int(rand(RsA))}
            		    fade_distance 3 fade_power 2
        	        }
        	        */
      	            sphere {
      	                < 0, 0, 0 >, (rand(RsA)*0.3)
      	                scale < 0.1, 1, 0.1 >
                        texture { fireTexture }
                        translate < 0, (-lowerArmLength-(handDia*2)), 0>
                    }
        	        #end
        	    #end              
                texture { SkinTexture }
                rotate < lowerArmRotLeft, 0, 0 >
                translate < 0, -upperArmLength, 0 >
            }
            rotate < upperArmRotLeft, 0, 0 >
            translate < -(shoulderLength/2), torsoLength, 0 >
        }
    }
    union {
        sphere {
            < (shoulderLength/2), torsoLength, 0 >,
            shoulderDia
            texture { shirtTexture }
        }
        // Add arm
        union {
            cone {
                < 0, 0, 0 >, shoulderDia
                < 0, -upperArmLength, 0 >, upperArmDia
                texture { shirtTexture }
            }
            sphere {
                < 0, -upperArmLength, 0 >,
                elbowDia
                texture { SkinTexture }
            }
            // Add lower arm
            union {
                cone {
                    < 0, 0, 0 >, elbowDia
                    < 0, -lowerArmLength, 0 >, lowerArmDia
                }
                // Add the hand
                sphere {
                    < 0, -lowerArmLength, 0 >,
                    handDia
                }
                // Add the lighter
                #if (hasLight > lightClip)
                    #if (lightHand < 5)
                    /*
                    light_source {
                        < 0, (-lowerArmLength-(handDia*2)), 0>,
            		    color rgb 0.045*< rand(RsA), rand(RsA), rand(RsA)>
            		    glow { size rand(RsA)*0.5 type int(rand(RsA))}
            		    fade_distance 3 fade_power 2
        	        }
        	        */
      	            sphere {
      	                < 0, 0, 0 >, (rand(RsA)*0.3)
      	                scale < 0.1, 1, 0.1 >
                        texture { fireTexture }
                        translate < 0, (-lowerArmLength-(handDia*2)), 0>
                    }
        	        #end
        	    #end              
                texture { SkinTexture }
                rotate < lowerArmRotRight, 0, 0 >
                translate < 0, -upperArmLength, 0 >
            }            
            rotate < upperArmRotRight, 0, 0 >
            translate < (shoulderLength/2), torsoLength, 0 >        
        }
    }
    // Torso
    sphere {
        < 0, 0, 0 >,
        torsoDia
        texture { shirtTexture }
    }
    cylinder {
        < 0, 0, 0 >,
        < 0, torsoLength, 0 >,
        torsoDia
        texture { shirtTexture }
    }
    sphere {
        < 0, torsoLength, 0 >,
        torsoDia
        texture { shirtTexture }
    }
    rotate < 0, torsoRot, 0 >
    translate < 0, upperLegLength + lowerLegLength, 0 >
}

// Waist
union {
    cylinder {
        < -(waistLength/2), 0, 0 >,
        <  (waistLength/2), 0, 0 >,
        waistDia
    }
    sphere {
        < -(waistLength/2), 0, 0 >,
        waistDia
    }
    sphere {
        < (waistLength/2), 0, 0 >,
        waistDia
    }
    texture { shortsTexture }
    translate < 0, upperLegLength + lowerLegLength, 0 >
}

// Two feet
union {
    // Add Upper Leg
    cone {
        < 0, 0, 0 >, waistDia
        < 0, -upperLegLength, 0 >, upperLegDia
        texture { shortsTexture }
    }
    object {
        union {
            // Add Knee
            sphere {
                < 0, 0, 0 >,
                kneeDia    
                texture { SkinTexture }
            }
            // Add lower leg
            cone {
                < 0, 0, 0 >, kneeDia
                < 0, -lowerLegLength, 0 >, lowerLegDia
                texture { SkinTexture }
            }
            // Add foot
            object {    
                box {
                    < -(footWidth/2), -footHeight,            -0.1 >,
                    <  (footWidth/2),           0, (footLength-0.1)>
                    texture { shoeTexture }
                }
                // Do foot rotation
                translate < 0, footHeight, 0 >
                translate < 0, -lowerLegLength, 0 >
            }
        }
        translate < 0, -upperLegLength, 0 >
    }
    translate < -(waistLength/2), upperLegLength + lowerLegLength, 0 >    
}

union {
    // Add Upper Leg
    cone {
        < 0, 0, 0 >, waistDia
        < 0, -upperLegLength, 0 >, upperLegDia
        texture { shortsTexture }
    }
    object {
        union {
            // Add Knee
            sphere {
                < 0, 0, 0 >,
                kneeDia
                texture { SkinTexture }    
            }
            // Add lower leg
            cone {
                < 0, 0, 0 >, kneeDia
                < 0, -lowerLegLength, 0 >, lowerLegDia
                texture { SkinTexture }
            }
            // Add foot
            object {    
                box {
                    < -(footWidth/2), -footHeight,            -0.1 >,
                    <  (footWidth/2),           0, (footLength-0.1)>
                    texture { shoeTexture }
                }
                // Do foot rotation
                translate < 0, footHeight, 0 >
                translate < 0, -lowerLegLength, 0 >
            }
        }
        translate < 0, -upperLegLength, 0 >
    }
    translate < (waistLength/2), upperLegLength + lowerLegLength, 0 >    
}
#end

#macro GenerateFieldCrowd(numFans)
    #declare fanCounter = 0;
    #declare fanPositions = array[numFans];
    
    #while (fanCounter < numFans)
        object {
            union {
                GenerateU2Fan(initGen, fanCounter)
                #declare transZ = (rand(initGen) * 410) - 240;
                #declare transX = rand(initGen) * (sqrt( (1 - ((transZ*transZ) / (240*240))) * (175*175)));
                #if (rand(initGen) < 0.5)
                    #declare transX = transX * -1;
                #end
                translate < transX, 0, transZ >
            }
        }
        #declare fanCounter = fanCounter + 1;
    #end
#end
