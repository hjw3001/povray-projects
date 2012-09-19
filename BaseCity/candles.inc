#declare Candles = union {
   cylinder { /* This is the piece which sticks out */
      < 0, 0, 0 >,
      < 0, 0, -100 >,
      25.0
   }
   cylinder { /* This is the support for the upper portion */
      < 0, -50, -100 >,
      < 0, 200, -100 >,
      25.0
   }
   sphere { /* This is the ball on the bottom portion */
      < 0, -50, -100 >, 25.0
   }
   cylinder { /* This is the cross bar for the candles */
      < -200, 200, -100 >,
      <  200, 200, -100 >,
      25.0
   }
   sphere { /* This is an end cap for the cross bar */
      < -200, 200, -100 >, 25.0
   }
   sphere { /* This is the other end cap for the cross bar */
      < 200, 200, -100 >, 25.0
   }   
   cylinder { /* This is one of the candles */
      < -150, 200, -100 >,
      < -150, 350, -100 >,
      25.0
   }
   cone {
      < -150, 350, -100 >, 25.0
      < -150, 360, -100 >, 30.0
   }
   sphere {
      < -150, 385, -100 >, 30.0
      texture { YELLOW_GLASS }
   }
   light_source {
      < -150, 400, -100 >
      color Yellow
      spotlight
      point_at
      < -150, 0, -100 >
      radius 90
      falloff 135
   }
   cylinder { /* This is another candle */
      < 150, 200, -100 >,
      < 150, 350, -100 >,
      25.0
   }
   cone {
      < 150, 350, -100 >, 25.0
      < 150, 360, -100 >, 30.0
   }
   sphere {
      < 150, 385, -100 >, 30.0
      texture{ YELLOW_GLASS }
   }
   light_source {
      < 150, 400, -100 >
      color Yellow
      spotlight
      point_at
      < 150, 0, -100 >
      radius 90
      falloff 135
   }
   texture{ Polished_Brass }
}
