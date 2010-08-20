// fldchrs.inc
//
// Creates the seating on the field

// Configure the layout of the chairs
#include "u2fan.inc"

#declare chairXSize = 1.5;
#declare chairYSize = 4.0;
#declare chairZSize = 1.5;
#declare chairTubeDia = 0.05;

#declare numSectsWide = 3;
#declare numSectsLong = 4;
#declare numChairsInRow = 28;
#declare numRowsInSect = 20;

#declare spaceBetweenChairs = 0.25;
#declare spaceBetweenRows = 2.0;
#declare spaceBetweenSectsX = 5.0;
#declare spaceBetweenSectsZ = 5.0;

#declare useRandowRotation = true;
#declare ranGen = seed(360);
#declare fanCounter = 0;

// Create a single chair
#declare Chair = union {
    // Back supports
    cylinder {
		< -(chairXSize/2),          0,  (chairZSize/2) >,
		< -(chairXSize/2), chairYSize, -(chairZSize/2) >,
		chairTubeDia
	}
    cylinder {
		<  (chairXSize/2),          0,  (chairZSize/2) >,
		<  (chairXSize/2), chairYSize, -(chairZSize/2) >,
		chairTubeDia
	}
    cylinder {
		< -(chairXSize/2), chairYSize, -(chairZSize/2) >,
		<  (chairXSize/2), chairYSize, -(chairZSize/2) >,
		chairTubeDia
	}
	sphere {
		< -(chairXSize/2), chairYSize, -(chairZSize/2) >,
	    chairTubeDia
	}
	sphere {
		< (chairXSize/2), chairYSize, -(chairZSize/2) >,
	    chairTubeDia
	}
	
	// Front of seat supports
    cylinder {
		< -(chairXSize/2),              0, -(chairZSize/2) >,
		< -(chairXSize/2), (chairYSize/2),  (chairZSize/2) >,
		chairTubeDia
	}
    cylinder {
		<  (chairXSize/2),              0, -(chairZSize/2) >,
		<  (chairXSize/2), (chairYSize/2),  (chairZSize/2) >,
		chairTubeDia
	}
	
	// The seat
	box {
	    < -(chairXSize/2),  (chairYSize/2), -(chairZSize/2) >,
	    <  (chairXSize/2), ((chairYSize/2)+chairTubeDia), (chairZSize/2) >
	}    
	
    texture {
	    pigment { color White }
	    finish { metallic }
	}
}

// object { Chair }

// Create a section of chairs
#declare ChairSection = union {
	#declare rowsInSectCount = 0;

	#declare rowSectPos = 0;
	#while (rowsInSectCount < numRowsInSect)
		#declare chairRowPos = 0;
		#declare chairsInRowCount = 0;
		#while (chairsInRowCount < numChairsInRow)
			object {
				Chair
				#if (useRandowRotation = true)
                    rotate < 0, ((rand(ranGen) * 8) - 4), 0 >
				#end
				translate < chairRowPos, 0, rowSectPos >
			}
			object {
    			union {
                    GenerateU2Fan(ranGen, fanCounter)
                    #declare fanCounter = fanCounter + 1;
                    texture { SkinTexture }
    				translate < chairRowPos, 0, (rowSectPos+2) >
                }    
            }
			#declare chairRowPos = chairRowPos + chairXSize + spaceBetweenChairs;
			#declare chairsInRowCount = chairsInRowCount + 1;
		#end
		#declare rowSectPos = rowSectPos + chairZSize + spaceBetweenRows;
		#declare rowsInSectCount = rowsInSectCount + 1;
	#end
}

// object { ChairSection }

// Create all the sections
#declare FieldSeating = union {
    #declare sectWideCount = 0;
    
    #declare sectWidePos = 0;
    
    #while (sectWideCount < numSectsWide)
        #declare sectLongCount = 0;
        #declare sectDepthPos = 0;
    	#while (sectLongCount < numSectsLong)
    		object {
    			ChairSection
    			translate < sectWidePos, 0, sectDepthPos >
    		}
    		#declare sectDepthPos = sectDepthPos + ((chairZSize + spaceBetweenRows) * numRowsInSect) + spaceBetweenSectsZ;
    		#declare sectLongCount = sectLongCount + 1;
    	#end
    	#declare sectWidePos = sectWidePos + ((chairXSize + spaceBetweenChairs) * numChairsInRow) + spaceBetweenSectsX;
    	#declare sectWideCount = sectWideCount + 1;
    #end
}
