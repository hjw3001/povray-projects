// main.pov
//
// Written by: Henry Wagner (povray@henrywagner.org)
// Started: 2/8/97

#version 3.1
global_settings { assumed_gamma 2.2 }

#include "colors.inc"
#include "woods.inc"

#declare Cabin_Wood_1 = texture {
   T_Wood1
   scale < 3.5, 3.5, 6 >
}

#declare Short_Log = object {
   cylinder {
      < 0, 0, -7 >,
      < 0, 0,  7 >,
      0.5
   }
}

#declare Long_Log = object {
   cylinder {
      < -8.5, 0, 0 >,
      <  8.5, 0, 0 >,
      0.5
   }
}

// This is the ground plane
plane { < 0, 1, 0 >, 0 pigment { color Green } }

camera {
   location < -15, 5.8, -15 >
   look_at < 0, 4.0, 6 >
}

light_source {
   < -1000, 1000, -1000 >
   color White
}

union {
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 1.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 2.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 3.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 4.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 5.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 6.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 7.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 8.0, 0 >
   }
}

union {
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 1.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 2.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 3.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 4.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 5.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 6.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 7.0, 0 >
   }
   object {
      Long_Log
      texture {
         Cabin_Wood_1
         rotate < 0, 90, 0 >
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 8.0, 0 >
   }
   translate < 0, 0, 12 >
}

union {
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 0.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 1.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 2.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 3.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 4.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 5.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 6.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < -1.2, 0, 0 >
         rotate < 2, 0, 0 >
      }
      translate < 0, 7.5, 0 >
   }
   translate < 7.5, 0, 6 >
}

union {
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -3.1 >
      }
      translate < 0, 0.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -0.23 >
      }
      translate < 0, 1.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -1.25 >
      }
      translate < 0, 2.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -0.45 >
      }
      translate < 0, 3.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -0.8 >
      }
      translate < 0, 4.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -1.3 >
      }
      translate < 0, 5.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -0.4 >
      }
      translate < 0, 6.5, 0 >
   }
   object {
      Short_Log
      texture {
         Cabin_Wood_1
         translate < 0, 0, -2.2 >
      }
      translate < 0, 7.5, 0 >
   }
   translate < -7.5, 0, 6 >
}
