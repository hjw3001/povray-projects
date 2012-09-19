// lemon.inc
//
// Written by: Henry Wagner (povray@henrywagner.org)

#declare nMirrors = 0;
#declare lAngle = 65;
#declare Lemon = union {

    #declare lRadius = 19.0 / sin (pi / 180.0 * lAngle);

    // float cSide = 0.25f; // The length of a side of a Lemon mirror
    #declare cSide = 2;

    #declare xBase = lRadius * cos (pi / 180.0 * lAngle); 
	#declare xBase = xBase - 0.5;

	// float x1, z1, x2, z2, x3, z3, x4, z4;

    #declare yAngle = lAngle * -1;
    #while (yAngle < lAngle)			
		#declare tx1 = lRadius * cos ( pi / 180.0 * yAngle );
		#declare tx1 = tx1 - xBase;
		#declare tx2 = lRadius * cos ( pi / 180.0 * (yAngle + cSide ) );
		#declare tx2 = tx2 - xBase;
		#declare y1 = lRadius * sin ( pi / 180.0 * yAngle );
		#declare y2 = lRadius * sin ( pi / 180.0 * (yAngle + cSide ) );

        #declare zAngle = 0;
		#while (zAngle < 360)
			// x = r * cos(theta)
			// y = r * sin(theta)
			#declare x1 = tx1 * cos ( zAngle * pi / 180.0 );
			#declare z1 = tx1 * sin ( zAngle * pi / 180.0 );

			#declare x2 = tx1 * cos ( (zAngle+cSide) * pi / 180.0 );
			#declare z2 = tx1 * sin ( (zAngle+cSide) * pi / 180.0 );

			#declare x3 = tx2 * cos ( zAngle * pi / 180.0 );
			#declare z3 = tx2 * sin ( zAngle * pi / 180.0 );

			#declare x4 = tx2 * cos ( (zAngle+cSide) * pi / 180.0 );
			#declare z4 = tx2 * sin ( (zAngle+cSide) * pi / 180.0 );

			triangle { < x1, y1, z1 >,
			           < x4, y2, z4 >,
			           < x3, y2, z3 > }

			triangle { < x1, y1, z1 >,
			           < x2, y1, z2 >,
			           < x4, y2, z4 > }

			#declare nMirrors = nMirrors + 1;
			#declare zAngle = zAngle + cSide;
		#end
		#declare yAngle = yAngle + cSide;
	#end
}
