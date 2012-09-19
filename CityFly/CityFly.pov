// CityFly.pov
// Written by: Henry Wagner (povray@henrywagner.org)

#include "colors.inc"
#include "metals.inc"

#declare maxX = 10;
#declare maxY = 10;
#declare maxZ = 1;

#declare heightArray = array[maxX][maxZ];

#declare ranGen = seed(maxY);

#declare xCount = 0;
#declare zCount = 0;

#while (xCount < maxX)
    #while (zCount < maxZ)
        box {
            #declare heightArray[xCount][zCount] = rand(ranGen);
            < xCount, 0, zCount >,
            < xCount + 1, heightArray[xCount][zCount], zCount + 1 >
            pigment { color Red }
        }
        /*
        sphere {
            < xCount + 0.5, heightArray[xCount][zCount], zCount + 0.5 >, 0.2
            pigment { color Blue }
        }
        */
        #declare zCount = zCount + 1;
    #end
    #declare zCount = 0;
    #declare xCount = xCount + 1;
#end

#declare xCount = 0.0;
#declare zCount = 0.0;
#declare sCount = 0.0;
#declare FlySpline = function {
   spline {
     cubic_spline
      -0.001, < 0, 0  , 0>
      #while (xCount < maxX)
        #while (zCount < maxZ)
            #warning concat("sCount is: ", str(sCount, 5, 0))
            #warning concat("foo is: ", str((1.0 / (maxX * maxZ)), 5, 0))
            sCount, < xCount + 0.5, heightArray[xCount][zCount] + 1, zCount + 0.5 >
            #declare sCount = sCount + (1 / (maxX * maxY));
            #declare zCount = zCount + 1.0;
        #end
        #declare zCount = 0.0;
        #declare xCount = xCount + 1.0;
      #end
       1.001, < maxX   , maxY  , maxZ>
   }
}

#declare xCount = 0;
#declare zCount = 0;

#while (xCount < maxX)
    #while (zCount < maxZ)
        sphere {
            FlySpline(xCount), 0.22
            pigment { color Blue }
        }
        #declare zCount = zCount + 0.2;
    #end
    #declare zCount = 0;
    #declare xCount = xCount + 0.2;
#end

#declare C = clock;
camera {
   // location FlySpline(C)
   location < maxX + 2, maxY + 2, maxZ + 2>
   up < 0, 1, 0 >
   right < 4/3, 0, 0 >
   look_at < (maxX / 2), 0, (maxZ / 2) >
}

light_source { <  100000, 100000, -100000 > color White }
