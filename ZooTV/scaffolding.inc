// scaffolding.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)


// _width in X axis, how many vertical sections (from 0 to _height)
// _depth in Z axix, how many vertical sections (from 0 to _height)
// _space the distance between vertical segments
#macro GenerateScaffolding(_width,_height,_depth,_space,_bigDiameter,_smallDiameter)
    union {
        #declare zLoc = 0;
        #declare zCounter = 0;
        #while (zCounter <= _depth)
            #declare xLoc = 0;
            #declare xCounter = 0;
            #while (xCounter <= _width)
                cylinder {
                    < xLoc,       0, zLoc >,
                    < xLoc, _height, zLoc >
                    _bigDiameter
                }
                // Cap the tops
                sphere {
                    < xLoc, _height, zLoc >, _bigDiameter
                }
                #declare xLoc = xLoc + _space;
                #declare xCounter = xCounter + 1;
            #end
            #declare zLoc = zLoc + _space;
            #declare zCounter = zCounter + 1;
        #end

        #declare yLoc = _space;
        #while (yLoc <= _height)
            #declare xLoc = 0;
            #declare xCounter = 0;
            #while (xCounter <= _width)
                cylinder {
                    < xLoc, yLoc,               0 >,
                    < xLoc, yLoc, (_depth*_space) >
                    _bigDiameter
                }
                #declare xLoc = xLoc + _space;
                #declare xCounter = xCounter + 1;
            #end
            #declare yLoc = yLoc + _space;
        #end

        #declare yLoc = _space;
        #while (yLoc <= _height)
            #declare zLoc = 0;
            #declare zCounter = 0;
            #while (zCounter <= _depth)
                cylinder {
                    <               0, yLoc, zLoc >,
                    < (_width*_space), yLoc, zLoc >
                    _bigDiameter
                }
                #declare zLoc = zLoc + _space;
                #declare zCounter = zCounter + 1;
            #end
            #declare yLoc = yLoc + _space;
        #end

        // Small Diameter bars
        #declare yLoc = 0;
        #while (yLoc < _height)
            #declare zLoc = 0;
            #declare zCounter = 0;
            #while (zCounter < _depth)
                #declare xLoc = 0;
                #declare xCounter = 0;
                #while (xCounter < _width)
                    cylinder {
                        < xLoc, yLoc, zLoc >,
                        < (xLoc+_space), yLoc+_space, zLoc >
                        _smallDiameter
                    }
                    cylinder {
                        < xLoc, yLoc+_space, zLoc >,
                        < (xLoc+_space), yLoc, zLoc >
                        _smallDiameter
                    }
                    cylinder {
                        < xLoc, yLoc, zLoc >,
                        < xLoc, yLoc+_space, zLoc+_space >
                        _smallDiameter
                    }
                    cylinder {
                        < xLoc, yLoc+_space, zLoc >,
                        < xLoc, yLoc, zLoc+_space >
                        _smallDiameter
                    }
                    #declare xLoc = xLoc + _space;
                    #declare xCounter = xCounter + 1;
                #end
                #declare zLoc = zLoc + _space;
                #declare zCounter = zCounter + 1;
            #end
            #declare yLoc = yLoc + _space;
        #end
        
    }
#end