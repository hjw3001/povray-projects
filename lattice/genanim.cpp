// genanim.cpp
//
// This program generates animate.bat which renders out the POV animation
//
// Written by: Henry Wagner (henryw@panix.com)

#include <stdio.h>

main()
{
   int c2 = 100, c3;
   float phase = 0.0, c1;
   FILE *o;

   o = fopen("animate.bat","w");

   fprintf(o,"@echo off\n" );

   for(c1 = 0.0; c1 < 90.0; c1 += 7.5) {
      fprintf(o, "rotate %.1f\n", c1 );
      fprintf(o, "mphase %f\n", phase );
      fprintf(o, "c:\\povray3\\povray +Ilattice.pov +oframe%d.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000\n", c2 );
      c2++;
      phase += 1.0/12.0;
   }

   fprintf(o, "c:\\alchemy\\alchemy frame105.tga -o -8 -w palette.bmp\n" );

   for( c3 = 100; c3 < c2; c3++ )
      fprintf(o, "c:\\alchemy\\alchemy frame%d.tga -f palette.bmp -o -8 -w frame%d.bmp\n", c3, c3 );

   fclose(o);
   return(0);
}