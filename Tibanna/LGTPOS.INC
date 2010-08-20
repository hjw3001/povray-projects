// lgtpos.inc
//
// Created by: Henry Wagner (henrywagner@henrywagner.org)

#declare initGen = seed(360);

#macro GenerateLightTower()
    object {
        Light_Tower
        translate < ((rand(initGen)*350) + 470), -80, 0 >
        rotate < 0, (rand(initGen) * 360), 0 >
    }
#end

#declare Light_Towers = union {
    #declare loopCounter = 0;
    #while (loopCounter < 9)
        GenerateLightTower()
        #declare loopCounter = loopCounter + 1;
    #end
}
