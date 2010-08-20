// scaffolding.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#macro GenerateScaffolding(_width,_wSegments,_height,_hSegments,_depth,_dSegments,_diameter)
    // Generate the main width supports
    #declare widthCounter = 0;
    #while (widthCounter < _width)
        #declare heightCounter = 0;
        #while (heightCounter < _height)
            #declare depthCounter = 0;
            #while (depthCounter < _depth)
            
                #declare depthCounter = depthCounter + 1;
            #end

            #declare heightCounter = heightCounter + 1;        
            #end
        #end
    
        #declare widthCounter = widthCounter + 1;
    #end    

