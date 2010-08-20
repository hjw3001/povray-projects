// detail.cpp
//
// This program generates random detail objects for the Tibanna Gas Mine.
//
// Parameters:
//  * filename
//  * objectName
//  * minimum radius
//  * maximum radius
//  * number of objects
//
// Written by: Henry Wagner (henryw@panix.com)
// Started: 12/28/96

#version unofficial megapov 1.1;

#macro GenerateTibannaDetail(c1, c2, minr, maxr, nObjects, distance)
    #declare distance = maxr - minr;

    randomize(); // Seed the random number generator


    #declare TibannaDetails = union {

    #declare counter = 0;
    
    #while (counter < nObjects)
	 c2 = random(4);

	 if (c2 == 0) {
	    // Create a simple box
	    box {
	        < -%d,  0, -%d >,\n", (random(5) + 1), (random(5) + 1)); // Add 1 to eliminate zero values
	        <  %d, %d,  %d >\n", (random(5) + 1), (random(15) + 3), (random(5) + 1));
	    }
	 else if (c2 == 1) {
	    #local cHeight = (rand(initRand) *15) + 3;
	    // Create a simple cylinder
	       union {
	          cylinder {
	             < 0, 0, 0 >,
	             < 0, %d, 0 >,\n", cHeight ); // Make it atleast 3 units tall
	             %d\n", (random(3) + 1));
	          }
	          sphere { 0, 1
	    	 pigment { color rgbt <1, 1, 1, 1> }
	    	 halo {
	    	    emitting
	    	    spherical_mapping
	    	    linear
	    	    color_map {
	    	       [ 0 color rgbt <1, 1, 0.5,  1.0> ]
	    	       [ 1 color rgbt <1, 1, 1, -1.0> ]
	                }
	    	    samples 10
	             }
	           	 hollow
	    	 scale 5
	             translate < 0, %d, 0 >\n", cHeight + 1 );
	          }
	 }
	 else if (c2 == 2) {
	    // Create a simple sphere
	    sphere {
	          < 0, 0, 0 >, ((rand(initRan) * 13) + 1)
	    }
	 else if (c2 == 3) {
	    // Create a simple cone
	    cone {
	       < 0, 0, 0 >, %d\n", (random(3) + 1));
	       < 0, %d, 0 >, %d\n", (random(15) + 3), (random(3) + 1));
	    }
	    translate < %d, 0, 0 >\n", random(distance) + minr);
	    rotate < 0, (rand(initRand) * 360), 0 >
	    }
      }

      }
        #declare counter = counter + 1;
    #end
#end
