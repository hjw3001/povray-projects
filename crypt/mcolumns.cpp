// mcolumns.cpp
//
// Written by: Henry Wagner

#include <stdio.h>

main()
{
   int c1, c2;
   FILE *o;

   o = fopen("columns.inc","w");

   fprintf(o, "// columns.inc\n" );
   fprintf(o, "//\n" );
   fprintf(o, "// Generated by: Henry Wagner\n\n" );

   fprintf(o, "#declare Column = union {\n" );
   fprintf(o, "   // This is the main shaft\n" );
   fprintf(o, "   difference {\n" );
   fprintf(o, "      cylinder {\n" );
   fprintf(o, "         < 0,  0, 0 >,\n" );
   fprintf(o, "         < 0, 10, 0 >,\n" );
   fprintf(o, "         1.0\n" );
   fprintf(o, "      }\n" );
   fprintf(o, "      object {\n" );
   fprintf(o, "         torus { 1, 0.1 }\n" );
   fprintf(o, "         translate < 0, 0.5, 0 >\n" );
   fprintf(o, "      }\n" );
   fprintf(o, "      texture {\n" );
   fprintf(o, "         Grnt8\n" );
   fprintf(o, "         scale 1\n" );
   fprintf(o, "      }\n" );
   fprintf(o, "      finish { Phong_Shiny }\n" );
   fprintf(o, "   }\n" );

   fprintf(o, "   object {\n" );
   fprintf(o, "      torus { 1, 0.15 }\n" );
   fprintf(o, "      translate < 0, 0.75, 0 >\n" );
   fprintf(o, "      texture { T_Gold_5D }\n" );
   fprintf(o, "   }\n" );

   fprintf(o, "   object {\n" );
   fprintf(o, "      torus { 1, 0.4 }\n" );
   fprintf(o, "      texture {\n" );
   fprintf(o, "         Grnt8\n" );
   fprintf(o, "         scale 1\n" );
   fprintf(o, "      }\n" );
   fprintf(o, "      finish { Phong_Shiny }\n" );
   fprintf(o, "   }\n" );
   fprintf(o, "   object {\n" );
   fprintf(o, "      torus { 1, 0.2 }\n" );
   fprintf(o, "      translate < 0, 9.8, 0 >\n" );
   fprintf(o, "      texture {\n" );
   fprintf(o, "         Grnt8\n" );
   fprintf(o, "         scale 1\n" );
   fprintf(o, "      }\n" );
   fprintf(o, "      finish { Phong_Shiny }\n" );
   fprintf(o, "   }\n" );
   fprintf(o, "   cylinder {\n" );
   fprintf(o, "      < 0,  9, 0 >,\n" );
   fprintf(o, "      < 0, 10, 0 >,\n" );
   fprintf(o, "      1.1\n" );
   fprintf(o, "      texture {\n" );
   fprintf(o, "         Grnt8\n" );
   fprintf(o, "         scale 1\n" );
   fprintf(o, "      }\n" );
   fprintf(o, "      finish { Phong_Shiny }\n" );
   fprintf(o, "   }\n" );

   for ( c1 = 0; c1 < 360; c1 += 30 ) {
      fprintf(o, "   sphere {\n" );
      fprintf(o, "      < 1.05, 9.4, 0 >, 0.15\n" );
      fprintf(o, "      rotate < 0, %d, 0 >\n", c1 );
      fprintf(o, "      texture { T_Gold_5D }\n" );
      fprintf(o, "   }\n" );
   }

   fprintf(o, "}\n" );

   fprintf(o, "#declare MyColumns = union {\n" );
   for ( c1 = 12; c1 <= 102; c1 += 12 ) {
      for( c2 = 12; c2 <= 102; c2 += 12 ) {
	 fprintf(o, "   object {\n" );
	 fprintf(o, "      Column\n" );
	 fprintf(o, "      translate < %d, 0, %d >\n", c1, c2 );
	 fprintf(o, "   }\n" );
      }
   }
   fprintf(o, "}\n" );

   fclose(o);
   return(0);
}