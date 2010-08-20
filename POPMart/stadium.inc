// stadium.inc
//
// Written by: Henry Wagner (povray@henrywagner.org)
//
// Stuff that changes

#include "math.inc"

#declare rFireoffset = 0.1;
#declare gFireoffset = 0.1;
#declare bFireoffset = 0.1;

#declare detailLevel = 1;

#declare Concrete = texture {
    pigment {
        granite
        turbulence 1.5
        color_map {
            [0 .25 color White color Gray75]
            [.25 .5 color White color Gray75]
            [.5 .75 color White color Gray75]
            [.75 1.1 color White color Gray75]
        }
    }
    finish {
        ambient 0.2
        diffuse 0.3
        crand 0.03
        reflection 0
    }
    normal {
        dents .5
        scale .5
    }
}

#declare Concrete1 = texture {
    pigment {
        granite
        turbulence 1.5
        color_map {
            [0 .25 color White color Gray95]
            [.25 .5 color White color White]
            [.5 .75 color White color White]
            [.75 1.1 color White color Gray85]
        }
    }
    finish {
        ambient 0.2
        diffuse 0.3
        crand 0.003
        reflection 0
    }
    normal {
        dents .5
        scale .5
    }
}

#macro ResetVars()
    #declare l1inRad = 0.0;		// Level 1, inner radius
    #declare l1outRad = 0.0;	// Level 1, outer radius
    
    #declare l2inRad = 0.0;
    #declare l2outRad = 0.0;
    
    #declare l3inRad = 0.0;
    #declare l3outRad = 0.0;
    
    #declare tx1 = 0.0;
    #declare tx2 = 0.0;
    #declare tx3 = 0.0;
    #declare tx4 = 0.0;
    #declare tz1 = 0.0;
    #declare tz2 = 0.0;
    #declare tz3 = 0.0;
    #declare tz4 = 0.0;
    
    #declare tax1 = 0.0;
    #declare tax2 = 0.0;
    #declare tax3 = 0.0;
    #declare tax4 = 0.0;
    #declare taz1 = 0.0;
    #declare taz2 = 0.0;
    #declare taz3 = 0.0;
    #declare taz4 = 0.0;
    
    #declare l1inA = 24;		// All the A and B values for the ellipsoids
    #declare l1inB = 18;		// A is in the Z direction
    #declare l1outA = 30;		// B is in the X direction
    #declare l1outB = 24;
    
    #declare l2inA = 24;
    #declare l2inB = 20;
    #declare l2outA = 30;
    #declare l2outB = 26;
    
    #declare l3inA = 25;
    #declare l3inB = 22;
    #declare l3outA = 31;
    #declare l3outB = 28;
    
    #declare l1inLowY = 0;		// Level 1, Inner Low Y
    #declare l1inHighY = 15;	// Level 1, Inner High Y
    #declare l1outLowY = 0;	    // Level 1, Outer Low Y
    #declare l1outHighY = 55;	// Level 1, Outer High Y
    
    #declare l2inLowY = 43; 	// Level 2, Inner Low Y
    #declare l2inHighY = 52;	// Level 2, Inner High Y
    #declare l2outLowY = 80;	// Level 2, Outer Low Y
    #declare l2outHighY = 95;	// Level 2, Outer High Y
    
    #declare l3inLowY = 78;	    // Level 3, Inner Low Y
    #declare l3inHighY = 87;	// Level 3, Inner High Y
    #declare l3outLowY = 138;	// Level 3, Outer Low Y
    #declare l3outHighY = 147;	// Level 3, Outer High Y
#end
//****************************************************************************************
// Helper function, gets used a bunch of times
//****************************************************************************************
#macro ComputeXZ (xVal, zVal, sAngle, A, B)
    #local foundMatch = false;
    
	#if (sAngle = 0)
		#declare zVal = 0.0;
		#declare xVal = B * 10.0;
		#local foundMatch = true;
	#end
	
	#if (sAngle = 360)
		#declare zVal = 0.0;
		#declare xVal = B * 10.0;
		#local foundMatch = true;
	#end
	
	#if (sAngle = 90)
		#declare zVal = A * 10.0;
		#declare xVal = 0.0;
		#local foundMatch = true;
	#end
	
	#if (sAngle = 180)
		#declare zVal = 0.0;
		#declare xVal = B * 10.0;
		#local foundMatch = true;
    #end

	#if (sAngle = 270)
		#declare zVal = A * 10.0;
		#declare xVal = 0.0;
		#local foundMatch = true;
	#end	

	#if (foundMatch = false)
		#declare tanTheta = tan(sAngle * pi / 180.0);
		#declare top = ((B*B)*(tanTheta*tanTheta)) + (A*A);
		#declare bottom = A*A*B*B;
		#declare base = top / bottom;
		#declare tx = sqrt (1 / base);

		#declare tz = sqrt ( (A*A) - ((A*A*tx*tx)/(B*B)));
		
		#declare xVal = tx * 10.0;
		#declare zVal = tz * 10.0;
	#end

	#if (sAngle > 90)
	    #if (sAngle < 270)
		    #declare xVal = -xVal;
		#end    
	#end	
	
	#if (sAngle > 180)
	    #if (sAngle < 360)
		    #declare zVal = -zVal;
		#end    
	#end	
#end

//****************************************************************************************
#macro ComputeXZExtended (xVal, zVal, sAngle, A, B, iFudge, bExtend)
    #local foundMatch = false;
    
	#if (sAngle = 0)
		#declare zVal = 0.0;
		#declare xVal = B * 10.0;
		#declare xVal = xVal + iFudge;
		#if (bExtend)
			#declare xVal = xVal + 1;
		#end
		#local foundMatch = true;
	#end
	
    #if (sAngle = 360)
		#declare zVal = 0.0;
		#declare xVal = B * 10.0;
		#declare xVal = xVal + iFudge;
		#if (bExtend)
			#declare xVal = xVal + 1;
		#end
		#local foundMatch = true;
	#end	
	
	#if (sAngle = 90)
		#declare zVal = A * 10.0;
		#declare zVal = zVal + iFudge;
		#if (bExtend = 1)
			#declare zVal = zVal + 1;
		#end	
		#declare xVal = 0.0;
		#local foundMatch = true;
	#end

	#if (sAngle = 180)
		#declare zVal = zVal + 0.0;
		#declare xVal = B * 10.0;
		#declare xVal = xVal + iFudge;
		#if (bExtend = 1)
			#declare xVal = xVal + 1;
		#end
		#local foundMatch = true;
	#end

	#if (sAngle = 270)
		#declare zVal = A * 10;
		#declare zVal = zVal + iFudge;
		#if (bExtend = 1)
			#declare zVal = zVal + 1;
		#end	
		#declare xVal = 0.0;
		#local foundMatch = true;
	#end	

	#if (foundMatch = false)
		#declare tanTheta = tan(sAngle * pi / 180.0);
		#declare top = ((B*B)*(tanTheta*tanTheta)) + (A*A);
		#declare bottom = A*A*B*B;
		#declare base = top / bottom;
		#declare tx = sqrt (1 / base);

		#declare tz = sqrt ( (A*A) - ((A*A*tx*tx)/(B*B)));
		
		#declare xVal = tx * 10.0;
		#declare zVal = tz * 10.0;
		#declare xVal = xVal + iFudge;
		#declare zVal = zVal + iFudge;
		#if (bExtend = 1)
			#declare xVal = xVal + 1;
			#declare zVal = zVal +  1;
		#end	
	#end

	#if (sAngle > 90)
	    #if (sAngle < 270)
		    #declare xVal = -xVal;
		#end    
	#end	
	
	#if (sAngle > 180)
	    #if (sAngle < 360)
		    #declare zVal = -zVal;
		#end    
	#end	
#end

//****************************************************************************************
#macro GenerateLighers(_inA, _inB, _yBase, _lightRad, _lightDepth, _numLights, _secAngle)
    #declare lightRand = seed(360);
    
    #declare counter = 0;
    #while (counter < _numLights)
        // Randomly pick an angle
        #declare lightAngle = rand(lightRand) * 360;
        
        // Randomly pick a depth
        #declare lightDepth = rand(lightRand) * _lightDepth;
        
        #declare A = lightDepth + _inA;
        #declare B = lightDepth + _inB;
        
        #declare tanTheta = tan(lightAngle * pi / 180.0);
		#declare top = ((B*B)*(tanTheta*tanTheta)) + (A*A);
		#declare bottom = A*A*B*B;
		#declare base = top / bottom;
		#declare tx = sqrt (1 / base);

		#declare tz = sqrt ( (A*A) - ((A*A*tx*tx)/(B*B)));
		
		#declare xVal = tx * 10.0;
		#declare zVal = tz * 10.0;
		
		#if (lightAngle > 90)
    	    #if (lightAngle < 270)
    		    #declare xVal = -xVal;
    		#end    
    	#end	
    	
    	#if (lightAngle > 180)
    	    #if (lightAngle < 360)
    		    #declare zVal = -zVal;
    		#end    
    	#end	

        #declare yVal = _yBase+(tand(_secAngle)*(lightDepth*10))+1;
		// #debug concat("xVal ", str(xVal,0,0), "\n")
		// #debug concat("yVal ", str(yVal,0,0), "\n")
		// #debug concat("zVal ", str(zVal,0,0), "\n")
		
		sphere {
		    < xVal, yVal, zVal >, (rand(lightRand) * _lightRad)
		    texture {
                pigment { rgb < 0.858824 + (rand(lightRand) * rFireoffset) - (rFireoffset/2),
                                0.858824 + (rand(lightRand) * gFireoffset) - (gFireoffset/2),
                                0.439216 + (rand(lightRand) * bFireoffset) - (bFireoffset/2) > }
                finish {
                    ambient 1
                    diffuse 0
                }
            }
		}
        
        #declare counter = counter + 1;
    #end
#end

#declare yHeight = 5;
ResetVars()
#declare FirstStadiumLevelSource = function {
   spline {
       natural_spline
    #declare i = 0;
    #while (i < 360)
		// Draw the current lower section
		ComputeXZ ( tx1, tz1, i, l1inA, l1inB )
		ComputeXZ ( tx2, tz2, i+10, l1inA, l1inB )
		ComputeXZ ( tx3, tz3, i, l1outA, l1outB )
		ComputeXZ ( tx4, tz4, i+10, l1outA, l1outB )
		
		// Draw top face
		i, < (tx1 + ((tx3 - tx1)/2)), (yHeight + l1inHighY + ((l1outHighY - l1inHighY)/2)), (tz1 + ((tz3 - tz1)/2)) >
		
		#declare i = i + 1;
	#end
	}
}

ResetVars()
#declare SecondStadiumLevelSource = function {
   spline {
       natural_spline
    #declare i = 0;
    #while (i < 360)
		// Draw the current middle section
		ComputeXZ ( tx1, tz1, i, l2inA, l2inB )
		ComputeXZ ( tx2, tz2, i+10, l2inA, l2inB )
		ComputeXZ ( tx3, tz3, i, l2outA, l2outB )
		ComputeXZ ( tx4, tz4, i+10, l2outA, l2outB )
		
		// Draw top face
		i, < (tx1 + ((tx3 - tx1)/2)), (yHeight + l2inHighY + ((l2outHighY - l2inHighY)/2)), (tz1 + ((tz3 - tz1)/2)) >
		
		#declare i = i + 1;
	#end
	}
}

ResetVars()
#declare ThirdStadiumLevelSource = function {
   spline {
       natural_spline
    #declare i = 0;
    #while (i < 360)
		// Draw the current top section
		ComputeXZ ( tx1, tz1, i, l3inA, l3inB )
		ComputeXZ ( tx2, tz2, i+10, l3inA, l3inB )
		ComputeXZ ( tx3, tz3, i, l3outA, l3outB )
		ComputeXZ ( tx4, tz4, i+10, l3outA, l3outB )
		
		// Draw top face
		i, < (tx1 + ((tx3 - tx1)/2)), (yHeight + l3inHighY + ((l3outHighY - l3inHighY)/2)), (tz1 + ((tz3 - tz1)/2)) >

		#declare i = i + 1;
	#end
	}
}

ResetVars()

#declare Stadium = union {
    #declare i = 0;
    #while (i < 360)
		// Draw the current lower section
		ComputeXZ ( tx1, tz1, i, l1inA, l1inB )
		ComputeXZ ( tx2, tz2, i+10, l1inA, l1inB )
		ComputeXZ ( tx3, tz3, i, l1outA, l1outB )
		ComputeXZ ( tx4, tz4, i+10, l1outA, l1outB )
		
		// Draw the front face
		triangle { < tx1, l1inLowY, tz1 >,
		           < tx1, l1inHighY, tz1 >,
				   < tx2, l1inLowY, tz2 > }

		triangle { < tx1, l1inHighY, tz1 >,
		           < tx2, l1inLowY, tz2 >,
		           < tx2, l1inHighY, tz2 > }

		// Draw top face
		triangle { < tx1, l1inHighY, tz1 >,
		           < tx3, l1outHighY, tz3 >,
		           < tx2, l1inHighY, tz2 > }

		triangle { < tx3, l1outHighY, tz3 >,
		           < tx2, l1inHighY, tz2 >,
		           < tx4, l1outHighY, tz4 > }

		// Draw the rear face
		triangle { < tx3, l1outLowY, tz3 >,
		           < tx3, l1outHighY, tz3 >,
				   < tx4, l1outLowY, tz4 > }

		triangle { < tx3, l1outHighY, tz3 >,
		           < tx4, l1outLowY, tz4 >,
		           < tx4, l1outHighY, tz4 > }

		// Draw the connection between lower and mid section
		ComputeXZ ( tx1, tz1, i, l1outA, l1outB )
		ComputeXZ ( tx2, tz2, i+10, l1outA, l1outB )
		ComputeXZ ( tx3, tz3, i, l2outA, l2outB )
		ComputeXZ ( tx4, tz4, i+10, l2outA, l2outB )
		
		// Draw the front face
		triangle { < tx1, l1outHighY, tz1 >,
		           < tx2, l1outHighY, tz2 >,
				   < tx4, l2outLowY, tz4 > }

		triangle { < tx1, l1outHighY, tz1 >,
		           < tx4, l2outLowY, tz4 >,
		           < tx3, l2outLowY, tz3 > }

		// Draw the current middle section
		ComputeXZ ( tx1, tz1, i, l2inA, l2inB )
		ComputeXZ ( tx2, tz2, i+10, l2inA, l2inB )
		ComputeXZ ( tx3, tz3, i, l2outA, l2outB )
		ComputeXZ ( tx4, tz4, i+10, l2outA, l2outB )
		
		// Draw the front face
		triangle { < tx1, l2inLowY, tz1 >,
		           < tx1, l2inHighY, tz1 >,
				   < tx2, l2inLowY, tz2 > }

		triangle { < tx1, l2inHighY, tz1 >,
		           < tx2, l2inLowY, tz2 >,
		           < tx2, l2inHighY, tz2 > }

		// Draw top face
		triangle { < tx1, l2inHighY, tz1 >,
		           < tx3, l2outHighY, tz3 >,
		           < tx2, l2inHighY, tz2 > }

		triangle { < tx3, l2outHighY, tz3 >,
		           < tx2, l2inHighY, tz2 >,
		           < tx4, l2outHighY, tz4 > }

		// Draw the rear face
		triangle { < tx3, l2outLowY, tz3 >,
		           < tx3, l2outHighY, tz3 >,
				   < tx4, l2outLowY, tz4 > }

		triangle { < tx3, l2outHighY, tz3 >,
		           < tx4, l2outLowY,  tz4 >,
		           < tx4, l2outHighY, tz4 > }

		// Draw bottom face
		triangle { < tx1, l2inLowY, tz1 >,
		           < tx3, l2outLowY, tz3 >,
		           < tx2, l2inLowY, tz2 > }

		triangle { < tx3, l2outLowY, tz3 >,
		           < tx2, l2inLowY, tz2 >,
		           < tx4, l2outLowY, tz4 > }

		// Draw the connection between mid and high section
		ComputeXZ ( tx1, tz1, i, l2outA, l2outB )
		ComputeXZ ( tx2, tz2, i+10, l2outA, l2outB )
		ComputeXZ ( tx3, tz3, i, l3outA, l3outB )
		ComputeXZ ( tx4, tz4, i+10, l3outA, l3outB )
		
		// Draw the front face
		triangle { < tx1, l2outHighY, tz1 >,
		           < tx2, l2outHighY, tz2 >,
				   < tx4, l3outLowY, tz4 > }

		triangle { < tx1, l2outHighY, tz1 >,
		           < tx4, l3outLowY, tz4 >,
		           < tx3, l3outLowY, tz3 > }

		// Draw the current top section
		ComputeXZ ( tx1, tz1, i, l3inA, l3inB )
		ComputeXZ ( tx2, tz2, i+10, l3inA, l3inB )
		ComputeXZ ( tx3, tz3, i, l3outA, l3outB )
		ComputeXZ ( tx4, tz4, i+10, l3outA, l3outB )
		
		// Draw the front face
		triangle { < tx1, l3inLowY, tz1 >,
		           < tx1, l3inHighY, tz1 >,
				   < tx2, l3inLowY, tz2 > }

		triangle { < tx1, l3inHighY, tz1 >,
		           < tx2, l3inLowY, tz2 >,
		           < tx2, l3inHighY, tz2 > }

		// Draw top face
		triangle { < tx1, l3inHighY, tz1 >,
		           < tx3, l3outHighY, tz3 >,
		           < tx2, l3inHighY, tz2 > }

		triangle { < tx3, l3outHighY, tz3 >,
		           < tx2, l3inHighY, tz2 >,
		           < tx4, l3outHighY, tz4 > }
		
		// Draw the steps
		// Draw the seat top
		// Orginally this loop was commented out
		#if (detailLevel > 1)
    		#declare  l3Temp = 0;
    		#while (l3Temp < 60)
    			ComputeXZExtended ( tax1, taz1, i, l3inA, l3inB, l3Temp, 0 )
    			ComputeXZExtended ( tax2, taz2, i+10, l3inA, l3inB, l3Temp, 0 )
    			ComputeXZExtended ( tax3, taz3, i, l3inA, l3inB, l3Temp, 1 )
    			ComputeXZExtended ( tax4, taz4, i+10, l3inA, l3inB, l3Temp, 1 )
    
    			// Draw the current top section
    			triangle { < tax1, l3inHighY + l3Temp, taz1 >,
    			           < tax3, l3inHighY + l3Temp, taz3 >,
    			           < tax2, l3inHighY + l3Temp, taz2 > }
    
    			triangle { < tax3, l3inHighY + l3Temp, taz3 >,
    			           < tax2, l3inHighY + l3Temp, taz2 >,
    			           < tax4, l3inHighY + l3Temp, taz4 > }
    
    			// Draw the seat front
    			triangle { < tax1, l3inHighY + l3Temp, taz1 >,
    			           < tax1, l3inHighY + l3Temp + 1, taz1 >,
    			           < tax2, l3inHighY + l3Temp, taz2 > }
    
    			triangle { < tax1, l3inHighY + l3Temp + 1, taz1 >,
    			           < tax2, l3inHighY + l3Temp, taz2 >,
    			           < tax2, l3inHighY + l3Temp + 1, taz2 > }
    			           
    			#declare l3Temp = l3Temp + 1;           
    		#end
    	#end		           

		// Draw the rear face
		triangle { < tx3, l3outLowY, tz3 >,
		           < tx3, l3outHighY, tz3 >,
				   < tx4, l3outLowY, tz4 > }

		triangle { < tx3, l3outHighY, tz3 >,
		           < tx4, l3outLowY, tz4 >,
		           < tx4, l3outHighY, tz4 > }

		// Draw bottom face
		#if (detailLevel > 1)
    		// Orginally these two triangles were commented out
    		triangle { < tx1, l3inLowY, tz1 >,
    		           < tx3, l3outLowY, tz3 >,
    		           < tx2, l3inLowY, tz2 > }
    
    		triangle { < tx3, l3outLowY, tz3 >,
    		           < tx2, l3inLowY, tz2 >,
    		           < tx4, l3outLowY, tz4 > }
    	#end	           

		#declare i = i + 1;
	#end
}
