// glgtower.cpp
//
// This program random places Light Towers around the base.
//
// Written by: Henry Wagner (henryw@panix.com)
// Started: 12/15/1996

#include <stdio.h>
#include <stdlib.h>

void main (int argc, char *argv[])
{
   FILE *o;
   int c;

   if (argc < 2) {
      printf("\nERROR: You must pass in the number of Light Towers to place\n");
      exit(0);
   }
   else {
      randomize();

      o = fopen("lgtpos.inc", "w");

      fprintf(o, "// lgtpos.inc\n" );
      fprintf(o, "//\n" );
      fprintf(o, "// Generated by: Henry Wagner (henryw@panix.com)\n\n" );

      fprintf(o, "#declare Light_Towers = union {\n" );
      for (c = 0; c < atoi(argv[1]); c++) {
	 fprintf(o, "   object {\n" );
	 fprintf(o, "      Light_Tower\n" );
	 fprintf(o, "      translate < %d, -80, 0 >\n", random(350) + 470);
	 fprintf(o, "      rotate < 0, %d, 0 >\n", random(360) );
	 fprintf(o, "   }\n" );
      }
      fprintf(o, "}\n" );

      fclose(o);
   }
}

