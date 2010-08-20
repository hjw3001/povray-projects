// Henry Wagner Alphabet Character Set Include File for POV-Ray
//
// This is a set of upper case letters created for use with POV-Ray 2.x.
// Each letter is in the x-y plain of size 3 POV units wide by 4 POV units
// high. The standard size will allow for easy spacing. All the letters are
// made up of cylinders, spheres, and tori (plural of torus?). They have no
// predefined color or texture so please feel free to choose your own

#declare rad = 0.25;

#declare hchar_A =
union {
   // Angled sides
   cylinder {
      < 0.25, 0.25, 0 >,
      < 1.50, 3.75, 0 >,
      rad
   }
   cylinder {
      < 1.50, 3.75, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   // Cross piece
   cylinder {
      < 0.5, 1.0, 0 >,
      < 2.5, 1.0, 0 >,
      rad
   }
   // Rounding spheres
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 1.50, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
}

#declare hchar_B =
union {
   // Left vertical piece
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   // Top straight piece
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.00, 3.75, 0 >,
      rad
   }
   // mid straight piece
   cylinder {
      < 0.25, 2.0, 0 >,
      < 2.00, 2.0, 0 >,
      rad
   }
   // Lower straight piece
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.00, 0.25, 0 >,
      rad
   }
   object {
      difference {
         object {
            torus { 0.875, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 1, 0, 0 >, 0 }
      }
      translate < 2, 2.875, 0 >
   }
   object {
      difference {
         object {
            torus { 0.875, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 1, 0, 0 >, 0 }
      }
      translate < 2, 1.125, 0 >
   }
   // Rounding spheres
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
}

#declare hchar_C =
union {
   cylinder {
      < 1.50, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 1.50, 0.25, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 2.75, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   cylinder {
      < 0.25, 1.50, 0 >,
      < 0.25, 2.50, 0 >,
      rad
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         union {
            plane { < -1, 0, 0 >, 0 }
            plane { < 0, -1, 0 >, 0 }
         }
      }
      translate < 1.50, 1.50, 0 >
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         union {
            plane { < -1, 0, 0 >, 0 }
            plane { <  0, 1, 0 >, 0 }
         }
      }
      translate < 1.50, 2.50, 0 >
   }
}

#declare hchar_D =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 0.25, 0 >,
      < 1.50, 0.25, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 1.50, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   cylinder {
      < 2.75, 1.50, 0 >,
      < 2.75, 2.50, 0 >,
      rad
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         union {
            plane { < 0, -1, 0 >, 0 }
            plane { < 1,  0, 0 >, 0 }
         }
      }
      translate < 1.50, 1.50, 0 >
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         union {
            plane { < 0, 1, 0 >, 0 }
            plane { < 1, 0, 0 >, 0 }
         }
      }
      translate < 1.50, 2.50, 0 >
   }
}

#declare hchar_E =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 2.00, 0 >,
      < 1.75, 2.00, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 1.75, 2.00, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_F =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 2.00, 0 >,
      < 1.75, 2.00, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 1.75, 2.00, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_G =
union {
   object {
      difference {
         object { 
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 0, 1, 0 >, 0 }
      }
      translate< 1.50, 2.50, 0 >
   }
   sphere { < 2.75, 2.50, 0 >, rad }
   cylinder {
      < 1.75, 1.50, 0 >,
      < 2.75, 1.50, 0 >,
      rad
   }
   sphere { < 1.75, 1.50, 0 >, rad }
   sphere { < 2.75, 1.50, 0 >, rad }
   cylinder {
      < 2.25, 0.25, 0 >,
      < 2.25, 1.50, 0 >,
      rad
   }
   cylinder {
      < 0.25, 1.50, 0 >,
      < 0.25, 2.50, 0 >,
      rad
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         union {
            plane { <  0, -1, 0 >, 0 }
            plane { < -1,  0, 0 >, -0.75 }
         }
      }
      translate< 1.50, 1.50, 0 >
   }
}

#declare hchar_H =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 2.75, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 2.00, 0 >,
      < 2.75, 2.00, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_I =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 1.50, 0.25, 0 >,
      < 1.50, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_J =
union {
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 1.75, 1.00, 0 >,
      < 1.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
   object {
      difference {
         object {
            torus { 0.75, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 0, -1, 0 >, 0 }
      }
      translate < 1.0, 1.0, 0 >
   }
   sphere { < 0.25, 1.0, 0 >, rad }
}

#declare hchar_K =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   cylinder {
      < 0.25, 1.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 2.75, 3.75, 0 >, rad }
   cylinder {
      < 1.00, 2.35, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 2.75, 0.25, 0 >, rad }
}

#declare hchar_L =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
}

#declare hchar_M =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 2.75, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 1.50, 2.00, 0 >,
      rad
   }
   cylinder {
      < 1.50, 2.00, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 1.50, 2.00, 0 >, rad }
}

#declare hchar_N =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 2.75, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_O =
union {
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane{ < 0, 1, 0 >, 0 }
      }
      translate < 1.50, 2.50, 0 >
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane{ < 0, -1, 0 >, 0 }
      }
      translate< 1.50, 1.50, 0 >
   }
   cylinder {
      < 0.25, 1.50, 0 >,
      < 0.25, 2.50, 0 >,
      rad
   }
   cylinder {
      < 2.75, 1.50, 0 >,
      < 2.75, 2.50, 0 >,
      rad
   }
}

#declare hchar_P =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 1.50, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 1.50, 0 >,
      < 1.50, 1.50, 0 >,
      rad
   }
   object {
      difference {
         object {
            torus { 1.125, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 1, 0, 0 >, 0 }
      }
      translate < 1.50, 2.625, 0 >
   }
}

#declare hchar_Q =
union {
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane{ < 0, 1, 0 >, 0 }
      }
      translate < 1.50, 2.50, 0 >
   }
   object {
      difference {
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane{ < 0, -1, 0 >, 0 }
      }
      translate< 1.50, 1.50, 0 >
   }
   cylinder {
      < 0.25, 1.50, 0 >,
      < 0.25, 2.50, 0 >,
      rad
   }
   cylinder {
      < 2.75, 1.50, 0 >,
      < 2.75, 2.50, 0 >,
      rad
   }
   cylinder {
      < 2.00, 1.00, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 2.00, 1.00, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
}

#declare hchar_R =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 1.50, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 1.50, 0 >,
      < 1.50, 1.50, 0 >,
      rad
   }
   object {
      difference {
         object {
            torus { 1.125, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 1, 0, 0 >, 0 }
      }
      translate < 1.50, 2.625, 0 >
   }
   cylinder {
      < 1.50, 1.50, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 2.75, 0.25, 0 >, rad }
}

#declare hchar_S =
union {
   object {
      difference {
         object {
            torus { 0.875, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < -1, 0, 0 >, 0 }
      }
      translate < 1.125, 2.875, 0 >
   }
   cylinder {
      < 1.125, 3.75, 0 >,
      < 2.750, 3.75, 0 >,
      rad
   }
   sphere { < 2.750, 3.75, 0 >, rad }
   object {
      difference {
         object {
            torus { 0.875, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 1, 0, 0 >, 0 }
      }
      translate < 1.875, 1.125, 0 >
   }
   cylinder {
      < 1.125, 2.00, 0 >,
      < 1.875, 2.00, 0 >,
      rad
   }
   cylinder {
      < 0.250, 0.25, 0 >,
      < 1.875, 0.25, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
}

#declare hchar_T =
union {
   cylinder {
      < 1.50, 0.25, 0 >,
      < 1.50, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
   sphere { < 1.50, 0.25, 0 >, rad }
}

#declare hchar_U =
union {
   cylinder {
      < 0.25, 1.50, 0 >,
      < 0.25, 3.75, 0 >,
      rad
   }
   cylinder {
      < 2.75, 1.50, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
   object {
      difference { 
         object {
            torus { 1.25, 0.25 }
            rotate< 90, 0, 0 >
         }
         plane { < 0, -1, 0 >, 0 }
      }
      translate< 1.50, 1.50, 0 >
   }
}

#declare hchar_V =
union {
   cylinder {
      < 0.25, 3.75, 0 >,
      < 1.50, 0.25, 0 >,
      rad
   }
   cylinder {
      < 1.50, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
   sphere { < 1.50, 0.25, 0 >, rad }
}

#declare hchar_W =
union {
   cylinder {
      < 0.25, 3.75, 0 >,
      < 0.75, 0.25, 0 >,
      rad
   }
   cylinder {
      < 0.75, 0.25, 0 >,
      < 1.50, 1.75, 0 >,
      rad
   }
   cylinder {
      < 1.50, 1.75, 0 >,
      < 2.25, 0.25, 0 >,
      rad
   }
   cylinder {
      < 2.25, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 0.75, 0.25, 0 >, rad }
   sphere { < 1.50, 1.75, 0 >, rad }
   sphere { < 2.25, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_X =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_Y =
union {
   cylinder {
      < 1.50, 0.25, 0 >,
      < 1.50, 2.00, 0 >,
      rad
   }
   sphere { < 1.50, 0.25, 0 >, rad }
   sphere { < 1.50, 2.00, 0 >, rad }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 1.50, 2.00, 0 >,
      rad
   }
   sphere { < 0.25, 3.75, 0 >, rad }
   cylinder {
      < 1.50, 2.00, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 2.75, 3.75, 0 >, rad }
}

#declare hchar_Z =
union {
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.75, 0.25, 0 >,
      rad
   }
   cylinder {
      < 0.25, 3.75, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   cylinder {
      < 0.25, 0.25, 0 >,
      < 2.75, 3.75, 0 >,
      rad
   }
   sphere { < 0.25, 0.25, 0 >, rad }
   sphere { < 0.25, 3.75, 0 >, rad }
   sphere { < 2.75, 0.25, 0 >, rad }
   sphere { < 2.75, 3.75, 0 >, rad }
}
