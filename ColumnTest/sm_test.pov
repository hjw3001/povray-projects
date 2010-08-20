// ***********************************************************
// Persistence Of Vision Ray Tracer Scene Description File
// File name  : pHDRI-test.pov
// Version    : 3.6
// Description: spherical map demo (for pHDRI-test.pov)
// Date       : Jun-2004
// Author     : Jaime Vives Piqueres
// ***********************************************************

// When usng your own scenes to generate spherical maps,
// remember to make the camera look horizontally and place
// it at an apropiated height.

#version 3.5;

global_settings{
 assumed_gamma 1.0
 ambient_light 0.0
 radiosity{count 150}
}

#include "colors.inc"

box{-.5,.5
 scale <500,250,500>
 pigment{rgb 1}
 translate 125*y
}

/*
light_source{
 <0,220,0>
 rgb Gold*10000
 fade_distance 1
 fade_power 2
}
*/
light_source{
 <230,170,0>
 rgb Gold*10000
 fade_distance 1
 fade_power 2
}
light_source{
 <-230,170,0>
 rgb SkyBlue*10000
 fade_distance 1
 fade_power 2
}


camera{
 spherical
 up y right 2*x
 location <0,80,-1>
 look_at <0,80,0>
}
