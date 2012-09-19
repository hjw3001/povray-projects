// genanim.cpp
//
// Written by: Henry Wagner (henryw@panix.com)

#include <stdio.h>

main()
{
   int c1;
   FILE *o;

   o = fopen("genfight.bat","w");

   fprintf(o, "@echo off\n" );
   for (c1 = 0; c1 < 360; c1 += 4) {
      fprintf(o, "rotate %d\n", c1);
      fprintf(o, "c:\\povray3\\povray +Lc:\\povray3\\include +Ifighter.pov +Oframe%d.tga +FT +q11 +r9 +a0.300 +j1.000 -W240 -H180 -P\n", c1 + 100);
   }

   fclose(o);
   return(0);
}
