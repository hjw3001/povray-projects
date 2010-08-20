#include "colors.inc"
 
#declare SCALE = 87.1;
#declare HEIGHT = 5;
#declare FOAM_THICKNESS = 1/12;
#declare EYES = 5.8;
#declare ROOM = 20;
#declare WALL_HEIGHT = 8;
#declare LIGHT_HEIGHT = WALL_HEIGHT - 0.25;

camera {
  location  <-8.0, EYES, -9.0>
  up y
  sky y
  look_at   <0.0, HEIGHT, 0.0>
}

light_source {
  <0 , LIGHT_HEIGHT, 0>
  color rgb <1.0, 1.0, 1.0>
}

union {
    box {
        < -6, (HEIGHT - FOAM_THICKNESS), -6 >,
        <  6, HEIGHT,        -4 >
    }
    box {
        < -6, (HEIGHT - FOAM_THICKNESS), 4 >,
        <  6, HEIGHT,        6 >
    }
    box {
        < -6, (HEIGHT - FOAM_THICKNESS), -4 >,
        < -4, HEIGHT,         4 >
    }
    box {
        < 4, (HEIGHT - FOAM_THICKNESS), -4 >,
        < 6, HEIGHT,         4 >
    }
    pigment { color Tan }
}

// Floor
box {
    < -(ROOM/2), -1, -(ROOM/2) >,
    <  (ROOM/2),  0,  (ROOM/2) >
    pigment { color Grey }
}

// Walls
union {
    box {
        < -(ROOM/2), 0, -(ROOM/2) >,
        <  (ROOM/2), WALL_HEIGHT, -(ROOM/2) >
    }
    box {
        < -(ROOM/2), 0, (ROOM/2) >,
        <  (ROOM/2), WALL_HEIGHT, (ROOM/2) >
    }
    box {
        < (ROOM/2), 0, -(ROOM/2) >,
        < (ROOM/2), WALL_HEIGHT, (ROOM/2) >
    }
    box {
        < -(ROOM/2), 0, -(ROOM/2) >,
        < -(ROOM/2), WALL_HEIGHT, (ROOM/2) >
    }
    pigment { color White }    
}

// Ceiling
box {
    < -(ROOM/2), WALL_HEIGHT, -(ROOM/2) >,
    <  (ROOM/2), WALL_HEIGHT + 1,  (ROOM/2) >
    pigment { color White }
}
