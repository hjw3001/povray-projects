// genstays.cpp
//
// This program generates all the support wires for the balloon object.
//
// Written by: Henry Wagner (henryw@panix.com)
// Started: 12/28/96

#include <stdio.h>
#include <math.h>

void main()
{
   FILE *o;
   int c1, angle, stRad = 2;
   double x1, z1, x2, z2, r1, r2;
   double r2d = 3.1415927 / 180.0; // To convert degrees to radians

   float y1 = 500;
   float y2 = 100;

   r1 = (double) 500.0;
   r2 = (double) 450.0;

   o = fopen("stays.inc", "w");

   fprintf(o, "// stays.inc\n" );
   fprintf(o, "//\n" );
   fprintf(o, "// Generated by: Henry Wagner (henryw@panix.com)\n\n" );

   fprintf(o, "#declare Stays = union {\n" );

   // Create the outer pieces
   for (angle = 0; angle < 360; angle += 10) {
      x1 = r1 * cos(r2d*angle);
      z1 = r1 * sin(r2d*angle);

      x2 = r2 * cos(r2d*(angle + 5));
      z2 = r2 * sin(r2d*(angle + 5));

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      %d\n", stRad );
      fprintf(o, "   }\n" );

      x2 = r2 * cos(r2d*(angle - 5));
      z2 = r2 * sin(r2d*(angle - 5));

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      %d\n", stRad );
      fprintf(o, "   }\n" );
   }

   y1 = 450;
   r1 = 50.0;
   y2 = 100;

   // Create the inner pieces
   for (angle = 0; angle < 360; angle += 10) {
      x1 = r1 * cos(r2d*angle);
      z1 = r1 * sin(r2d*angle);

      x2 = r2 * cos(r2d*(angle + 5));
      z2 = r2 * sin(r2d*(angle + 5));

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      %d\n", stRad );
      fprintf(o, "   }\n" );

      x2 = r2 * cos(r2d*(angle - 5));
      z2 = r2 * sin(r2d*(angle - 5));

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      %d\n", stRad );
      fprintf(o, "   }\n" );
   }

   r1 = 0;
   y1 = y2;

   // Create the connection pieces
   for (angle = 0; angle < 360; angle += 10) {
      x1 = r1 * cos(r2d*angle);
      z1 = r1 * sin(r2d*angle);

      x2 = r2 * cos(r2d*angle);
      z2 = r2 * sin(r2d*angle);

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      %d\n", stRad );
      fprintf(o, "   }\n" );
   }

   y1 = -70;
   r1 = 60.0;
   y2 = -200;
   r2 = 50.0;

   // Create the inner pieces
   for (angle = 0; angle < 360; angle += 10) {
      x1 = r1 * cos(r2d*angle);
      z1 = r1 * sin(r2d*angle);

      x2 = r2 * cos(r2d*(angle + 5));
      z2 = r2 * sin(r2d*(angle + 5));

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      .5\n", stRad );
      fprintf(o, "   }\n" );

      x2 = r2 * cos(r2d*(angle - 5));
      z2 = r2 * sin(r2d*(angle - 5));

      fprintf(o, "   cylinder {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      .5\n", stRad );
      fprintf(o, "   }\n" );
   }

   y1 = 500.0;
   r1 = 500;
   y2 = 100.0;
   r2 = 450.0;

   // Create the spheres
   for (angle = 0; angle < 360; angle += 10) {
      x1 = r1 * cos(r2d*angle);
      z1 = r1 * sin(r2d*angle);

      x2 = r2 * cos(r2d*(angle+5));
      z2 = r2 * sin(r2d*(angle+5));

      fprintf(o, "   sphere {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x1, y1, (float) z1);
      fprintf(o, "      4\n" );
      fprintf(o, "      texture { T_Brass_5E }\n" );
      fprintf(o, "   }\n" );
      fprintf(o, "   sphere {\n" );
      fprintf(o, "      < %.3f, %.3f, %.3f >,\n", (float) x2, y2, (float) z2);
      fprintf(o, "      4\n" );
      fprintf(o, "      texture { T_Brass_5E }\n" );
      fprintf(o, "   }\n" );
   }


   fprintf(o, "}\n" );
   fclose(o);
}