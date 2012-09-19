// camera.inc
//
// Written by: Henry Wagner (henrywagner@henrywagner.org)

#declare CameraSource = function {
   spline {
       natural_spline
       0.0, < -StadiumCenter-100,   6 + PodHeight, 500 > // Outside the stadium
       0.1, < -StadiumCenter-100, 170 + PodHeight, 500 > // Outside the stadium
       0.2, < -StadiumCenter+85,  600 + PodHeight,  40 > // Aireal View
       0.4, < -StadiumCenter-20,  200 + PodHeight,  20 > // 300 level
       0.6, < -StadiumCenter-20,   50 + PodHeight,   1 > // Mid Field
       0.6, < -StadiumCenter-85,  5.8 + PodHeight,  40 > // B-Stage
       0.7, < -StadiumCenter-180, 105 + PodHeight,  85 > // Olive
       0.75,< -StadiumCenter-70,   50 + PodHeight,   0 >
       0.8, < -StadiumCenter-171,  10 + PodHeight, -70 > // Lower left looking up
       0.85,< -StadiumCenter-140,  30 + PodHeight,   0 >
       0.9, < -StadiumCenter-135,  45 + PodHeight,  50 > // Lemon
   }
}

#declare CameraDest = function {
   spline {
       natural_spline
       0.0, < -StadiumCenter,     90 + PodHeight,  0 > // Outside the stadium
       0.2, < -StadiumCenter-10,  20 + PodHeight,  0 > // Aireal View
       0.4, < -StadiumCenter-160, 60 + PodHeight,  0 > // Mid field
       0.6, < -StadiumCenter-190, 40 + PodHeight,  0 > // B-Stage
       0.7, < -StadiumCenter-192, 95 + PodHeight, 91 > // Olive
       0.8, < -StadiumCenter-198, 70 + PodHeight, 40 > // Lower left looking up
       0.9, < -StadiumCenter-175, 30 + PodHeight, 60 > // Lemon
   }
}

#declare SpkTowerCameraSource = function {
   spline {
       natural_spline
       0.3,  < -StadiumCenter+210,  5 + PodHeight,  50 >
       0.31, < -StadiumCenter+220,  7 + PodHeight,  45 >
       0.4,  < -StadiumCenter+230,  9 + PodHeight,   0 >
       0.49, < -StadiumCenter+220, 12 + PodHeight, -45 >
       0.5,  < -StadiumCenter+210, 15 + PodHeight, -50 >
   }
}

#declare SpkTowerCameraDest = function {
   spline {
       natural_spline
       0.3, < -StadiumCenter+150, 30 + PodHeight,  60 >
       0.4, < -StadiumCenter+160, 40 + PodHeight,   0 >
       0.5, < -StadiumCenter+150, 30 + PodHeight, -50 >
   }
}

#declare OliveCameraSource = function {
   spline {
       natural_spline
       0.5,  < -StadiumCenter-180, 105 + PodHeight, 85 >
       0.55, < -StadiumCenter-185, 108 + PodHeight, 90 >
       0.6,  < -StadiumCenter-190, 110 + PodHeight, 95 >
   }
}

#declare LemonCameraSource = function {
   spline {
       natural_spline
       0.6,  < -StadiumCenter-175, 35 + PodHeight, 55 >
       0.65, < -StadiumCenter-135, 45 + PodHeight, 50 >
       0.7,  < -StadiumCenter-155,  6 + PodHeight, 75 >
   }
}

#declare LemonCameraDest = function {
   spline {
       natural_spline
       0.6,  < -StadiumCenter-175, 30 + PodHeight, 60 >
       0.65, < -StadiumCenter-175, 30 + PodHeight, 60 >
       0.7,  < -StadiumCenter-175, 23 + PodHeight, 60 >
   }
}

#declare StageCameraDest = function {
   spline {
       natural_spline
       0.8,   < -StadiumCenter-180, 50 + PodHeight,  75 >
       0.825, < -StadiumCenter-100, 55 + PodHeight,  50 >
       0.9,   < -StadiumCenter,     35 + PodHeight,   0 >
       0.975, < -StadiumCenter-100, 15 + PodHeight, -50 >
       1.0,   < -StadiumCenter-190, 10 + PodHeight, -75 >
   }
}

#declare ArchCameraSource = function {
   spline {
       natural_spline
       0.7,  < -StadiumCenter-185, 60 + PodHeight,  40 >
       0.75, < -StadiumCenter-150, 70 + PodHeight,   0 >
       0.8,  < -StadiumCenter-185, 80 + PodHeight, -40 >
   }
}

#declare ArchCameraDest = function {
   spline {
       natural_spline
       0.7,  < -StadiumCenter-178, 70 + PodHeight, 0 >
       0.75, < -StadiumCenter-178, 65 + PodHeight, 0 >
       0.8,  < -StadiumCenter-178, 60 + PodHeight, 0 >
   }
}

#declare NumCameras = 20;
#declare cameraCount = 0;
#declare CameraLocationArray = array[NumCameras];
#declare CameraLookAtArray = array[NumCameras];

// 0
#declare CameraLocationArray[cameraCount] = < -StadiumCenter, 800, 30 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter, 21, 0 >;
#declare cameraCount = cameraCount + 1;

// 1
#declare CameraLocationArray[cameraCount] = < -400, 40, 0 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter, 21, 0 >;
#declare cameraCount = cameraCount + 1;

// 2
#declare CameraLocationArray[cameraCount] = < -StadiumCenter, 25, 0 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter-StadiumCenter, 30, 0 >;
#declare cameraCount = cameraCount + 1;

// 3
#declare CameraLocationArray[cameraCount] = < sin(radians(rfact)) * 20, 24, cos(radians(rfact)) * 20 >;
#declare CameraLookAtArray[cameraCount] = < 0, 29, 0 >;
#declare cameraCount = cameraCount + 1;

// 4
#declare CameraLocationArray[cameraCount] = < -70, 25, -540 >;
#declare CameraLookAtArray[cameraCount] = < 0, 45, -525 >;
#declare cameraCount = cameraCount + 1;

// 5
#declare CameraLocationArray[cameraCount] = < 0, 100, -525 >;
#declare CameraLookAtArray[cameraCount] = < 0,  20, -525 >;
#declare cameraCount = cameraCount + 1;

// 6
#declare CameraLocationArray[cameraCount] = < (TempleCenter-370), 40, 80 >;
#declare CameraLookAtArray[cameraCount] = < TempleCenter, 39, 0 >;
#declare cameraCount = cameraCount + 1;

// 7
#declare CameraLocationArray[cameraCount] = < sin(radians(rfact)) * (TempleCenter-370), 24, cos(radians(rfact)) * (TempleCenter-370) >;
#declare CameraLookAtArray[cameraCount] = < TempleCenter, 39, 0 >;
#declare cameraCount = cameraCount + 1;

// 8
#declare CameraLocationArray[cameraCount] = < (sin(radians(rfact)) * (TempleCenter-370)) + (TempleCenter), 40, cos(radians(rfact)) * (TempleCenter-370) >;
#declare CameraLookAtArray[cameraCount] = < TempleCenter, 39, 0 >;
#declare cameraCount = cameraCount + 1;

// 9
#declare CameraLocationArray[cameraCount] = < (sin(radians(rfact)) * (TempleCenter+300)) , 40, cos(radians(rfact)) * (TempleCenter+300) >;
#declare CameraLookAtArray[cameraCount] = < TempleCenter, 39, 0 >;
#declare cameraCount = cameraCount + 1;

// 10
#declare CameraLocationArray[cameraCount] = < 200 + TempleCenter + TempleOffsetX,  21 + PodHeight, -240 + TempleOffsetZ >;
#declare CameraLookAtArray[cameraCount] = < 380 + TempleCenter + TempleOffsetX, 70 + PodHeight, TempleOffsetZ >;
#declare cameraCount = cameraCount + 1;
/*
#declare CameraLocationArray[cameraCount] = < 450 + TempleCenter + TempleOffsetX, 25 + PodHeight, -20 + TempleOffsetZ >;
#declare CameraLookAtArray[cameraCount] = < 380 + TempleCenter + TempleOffsetX, 70 + PodHeight, TempleOffsetZ >;
#declare cameraCount = cameraCount + 1;
*/

// 11 -- Above and behind the stadium with Temple in distance
#declare CameraLocationArray[cameraCount] = < -(StadiumCenter/2)-StadiumCenter+70, 240, -(StadiumCenter/2)+100 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter, 90, 0 >;
#declare cameraCount = cameraCount + 1;

// 12 -- Standing center stage looking out to mid field
#declare CameraLocationArray[cameraCount] = < -StadiumCenter-169, 5.5 + PodHeight, 0 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter, 35 + PodHeight, 0 >;
#declare cameraCount = cameraCount + 1;

// 13 - Looking at Arch from back of stadium
#declare CameraLocationArray[cameraCount] = < -StadiumCenter-150, 70 + PodHeight, 0 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter-178, 65 + PodHeight, 0 >;
#declare cameraCount = cameraCount + 1;

// 14 - Looking at Olive
#declare CameraLocationArray[cameraCount] = < -StadiumCenter-185, 108 + PodHeight, 90 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter-192, 95 + PodHeight, 91.057 >;
#declare cameraCount = cameraCount + 1;

// 15 - Top Light Start
#declare CameraLocationArray[cameraCount] = < -StadiumCenter-191, 10 + PodHeight, -60 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter-198, 75.3125 + PodHeight, -30 >;
#declare cameraCount = cameraCount + 1;

// 16 - Top Light End
#declare CameraLocationArray[cameraCount] = < -StadiumCenter-191, 60 + PodHeight, 50 >;
#declare CameraLookAtArray[cameraCount] = < -StadiumCenter-198, 70 + PodHeight, 40 >;
#declare cameraCount = cameraCount + 1;

// 17 - Speaker Tower
#declare CameraLocationArray[cameraCount] = SpkTowerCameraSource(0.5);
#declare CameraLookAtArray[cameraCount] = SpkTowerCameraDest(0.5);
#declare cameraCount = cameraCount + 1;
