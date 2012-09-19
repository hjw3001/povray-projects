#if (clock_on = 1)
    #declare tlRot = clock;
#else
    #declare tlRot = 0.5;
#end

#declare TopLightRig = union {
   object {
      TopLight
      translate < -65, 75, 198 >
   }
   object {
      TopLight
      translate < -60, 75.3125, 198 >
   }
   object {
      TopLight
      // rotate < (sin(tlRot) * 30), 0, 0 >
      translate < -55, 75.625, 198 >
   }
   object {
      TopLight
      translate < -50, 75.9375, 198 >
   }
   object {
      TopLight
      translate < -45, 76.25, 198 >
   }
   object {
      TopLight
      translate < -40, 76.5625, 198 >
   }
   object {
      TopLight
      translate < -35, 76.875, 198 >
   }
   object {
      TopLight
      translate < -30, 77.1875, 198 >
   }
   object {
      TopLight
      translate < -25, 77.5, 198 >
   }
   object {
      TopLight
      translate < -20, 77.8125, 198 >
   }
   object {
      TopLight
      translate < -15, 78.125, 198 >
   }
   object {
      TopLight
      translate < -10, 78.4375, 198 >
   }
   object {
      TopLight
      translate < -5, 78.75, 198 >
   }
   object {
      TopLight
      translate < 0, 79.0625, 198 >
   }
   object {
      TopLight
      translate < 5, 79.375, 198 >
   }
   object {
      TopLight
      translate < 10, 79.6875, 198 >
   }
   object {
      TopLight
      translate < 15, 80, 198 >
   }
   object {
      TopLight
      translate < 20, 80.3125, 198 >
   }
   object {
      TopLight
      translate < 25, 80.625, 198 >
   }
   object {
      TopLight
      translate < 30, 80.9375, 198 >
   }
   object {
      TopLight
      translate < 35, 81.25, 198 >
   }
   object {
      TopLight
      translate < 40, 81.5625, 198 >
   }
   object {
      TopLight
      translate < 45, 81.875, 198 >
   }
   object {
      TopLight
      translate < 50, 82.1875, 198 >
   }
   object {
      TopLight
      translate < 55, 82.5, 198 >
   }
   object {
      TopLight
      translate < 60, 82.8125, 198 >
   }
   object {
      TopLight
      translate < 65, 83.125, 198 >
   }
   object {
      TopLight
      translate < 70, 83.4375, 198 >
   }
   object {
      TopLight
      translate < 75, 83.75, 198 >
   }
   object {
      TopLight
      translate < 80, 84.0625, 198 >
   }
   object {
      TopLight
      translate < 85, 84.375, 198 >
   }
   object {
      TopLight
      translate < 90, 84.6875, 198 >
   }
   object {
      TopLight
      translate < 95, 85, 198 >
   }
}
