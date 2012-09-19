// GenerateCrystal.java
//
// Written by: Henry Wagner (henryw@panix.com)

import java.io.*;
import java.lang.*;

public class GenerateCrystal {
   public static void BuildCrystal(String filename) throws IOException {
      File o = new File(filename);
      int level = 10, height = 0, j, minPoint, maxPoint, baseLength;
      float sw = 1.0f;
      float cw = 0.4f;
      FileOutputStream os = new FileOutputStream(o);
      PrintStream ps = new PrintStream(os);

      ps.println( "// " + filename);
      ps.println( "//");
      ps.println( "// Written by: Henry Wagner (henryw@panix.com)" );

      ps.println( "#declare Metal_Frame = union {" );

      for( int i = level; i >= 0; i--) { // decrement the size with each level
         baseLength = i * 10; // This is the length of each side
         minPoint = (baseLength/2) * -1; // Center the object around the y axis
         maxPoint = Math.abs(minPoint);

         for ( j = minPoint; j <= maxPoint; j += 10) // Start creating some spheres
            ps.println( "   sphere { < " + j + ", " + height + ", " + minPoint + " >, " + sw + " }");

         if (i > 0) {
            for ( j = minPoint; j <= maxPoint; j += 10)
               ps.println( "   sphere { < " + j + ", " + height + ",  " + maxPoint + " >, " + sw + " }");
   
            for ( j = (minPoint + 10); j <= (maxPoint - 10); j += 10)
              ps.println( "   sphere { < " + minPoint + ", " + height + ", " + j + " >, " + sw + " }");
            
            for ( j = (minPoint + 10); j <= (maxPoint - 10); j += 10)
               ps.println( "   sphere { <  " + maxPoint + ", " + height + ", " + j + " >, " + sw + " }");

            // Create the connecting cylinders
            for ( j = minPoint; j <= (maxPoint - 10); j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + j + ", " + height + ", " + minPoint + " >," );
               ps.println( "      < " + (j + 10) + ", " + height + ", " + minPoint + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }

            for ( j = minPoint; j <= (maxPoint - 10); j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + j + ", " + height + ", " + maxPoint + " >," );
               ps.println( "      < " + (j + 10) + ", " + height + ", " + maxPoint + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }
   
            for ( j = minPoint; j <= (maxPoint - 10); j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + minPoint + ", " + height + ", " + j + " >," );
               ps.println( "      < " + minPoint + ", " + height + ", " + (j + 10) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }

            for ( j = minPoint; j <= (maxPoint - 10); j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + maxPoint + ", " + height + ", " + j + " >," );
               ps.println( "      < " + maxPoint + ", " + height + ", " + (j + 10) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }
         }

         if (i != level) {
            for ( j = minPoint; j <= maxPoint; j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + j + ", " + height + ", " + minPoint + " >," );
               ps.println( "      < " + (j - 5) + ", " + (height - 10)  + ", " + (minPoint - 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");

               ps.println( "   cylinder {" );
               ps.println( "      < " + j + ", " + height + ", " + minPoint + " >," );
               ps.println( "      < " + (j + 5) + ", " + (height - 10)  + ", " + (minPoint - 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }
            for ( j = minPoint; j <= maxPoint; j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + j + ", " + height + ", " + maxPoint + " >," );
               ps.println( "      < " + (j - 5) + ", " + (height - 10)  + ", " + (maxPoint + 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");

               ps.println( "   cylinder {" );
               ps.println( "      < " + j + ", " + height + ", " + maxPoint + " >," );
               ps.println( "      < " + (j + 5) + ", " + (height - 10)  + ", " + (maxPoint + 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }
            for ( j = minPoint; j <= maxPoint; j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + minPoint + ", " + height + ", " + j + " >," );
               ps.println( "      < " + (minPoint - 5) + ", " + (height - 10)  + ", " + (j - 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");

               ps.println( "   cylinder {" );
               ps.println( "      < " + minPoint + ", " + height + ", " + j + " >," );
               ps.println( "      < " + (minPoint - 5) + ", " + (height - 10)  + ", " + (j + 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }
            for ( j = minPoint; j <= maxPoint; j += 10) {
               ps.println( "   cylinder {" );
               ps.println( "      < " + maxPoint + ", " + height + ", " + j + " >," );
               ps.println( "      < " + (maxPoint + 5) + ", " + (height - 10)  + ", " + (j - 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");

               ps.println( "   cylinder {" );
               ps.println( "      < " + maxPoint + ", " + height + ", " + j + " >," );
               ps.println( "      < " + (maxPoint + 5) + ", " + (height - 10)  + ", " + (j + 5) + " >," );
               ps.println( "      " + cw  );
               ps.println( "   }");
            }
         }   

         height += 10;
      }

      ps.println( "   texture {" );
      ps.println( "      T_Gold_3B" );
      ps.println( "   }" );
      ps.println( "}" );

      ps.close();
      os.close();
   }

   public static void main(String[] argv) {
      try {
         BuildCrystal("frame.inc");
      } catch(IOException e) {
         System.err.println(e.getMessage());
      }
   }
}
