#include "colors.inc"
#include "field.inc"
#include "fldchrs.inc"
#include "arch.inc"
#include "Stage.inc"
#include "olive.inc"
#include "speakers.inc"
#include "Scrframe.inc"
#include "SpeaNeon.inc"
#include "screen.inc"
// #include "SpkTower.inc"

camera {
	//location < 20, 600, 25 >
	// look_at < 10, 2, 10 >
	
   // Back left asle of seats
   location < -27.5, 10, -132 >
   
   // Center stage
   look_at < 0, 15, 185 >

}

light_source {
	< -1000, 1000, -1000 >
	color White
}

object {
    FieldSeating
    translate < -78.5, 0, -132 >
}