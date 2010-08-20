// speakers.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#macro GenerateSpeakers(_width,_height,_depth,_space,_rows,_columns)
    #declare rowCounter = 0;
    #while (rowCounter < _rows)
        #declare columnCounter = 0;
        #while (columnCounter < _columns)
            box {
                < (-_width/2),       0, (-_depth/2) >,
                <  (_width/2), _height,  (_depth/2) >
                translate < (_width + _space) * rowCounter, (_height + _space) * columnCounter, 0 >
            }
            #declare columnCounter = columnCounter + 1;        
        #end
        #declare rowCounter = rowCounter + 1;
    #end
#end
