// POPatmos.inc
//
// Written by: Henry Wagner (henryw@panix.com)

//
// Atmosphere with isotropic scattering (independent of incident light). 
//

#declare Atmosphere1 = atmosphere {
  type 1
  samples 20        // Number of samples in first distance interval
  distance 1000       // Atmosphere density, similar to fog
  scattering 0.3    // Reflectivity of atmosphere, determines brightness
  aa_level 8        // Level of binary subdivision in case of aa
  aa_threshold 0.1  // Threshold for aa to push in
  jitter 0.25       // Amount of sample jittering
}

//
// Atmosphere with Mie cattering, hazy atmosphere (dependent of incident light). 
//

#declare Atmosphere2 = atmosphere {
  type 2
  samples 20        // Number of samples in first distance interval
  distance 50       // Atmosphere density, similar to fog
  scattering 1      // Reflectivity of atmosphere, determines brightness
  aa_level 8        // Level of binary subdivision in case of aa
  aa_threshold 0.1  // Threshold for aa to push in
  jitter 0.25       // Amount of sample jittering
}

//
// Atmosphere with Mie scattering, murky atmosphere (dependent of incident light). 
//

#declare Atmosphere3 = atmosphere {
  type 3
  samples 20        // Number of samples in first distance interval
  distance 50       // Atmosphere density, similar to fog
  scattering 1      // Reflectivity of atmosphere, determines brightness
  aa_level 8        // Level of binary subdivision in case of aa
  aa_threshold 0.1  // Threshold for aa to push in
  jitter 0.25       // Amount of sample jittering
}

//
// Atmosphere with Rayleigh scattering (dependent of incident light). 
//

#declare Atmosphere4 = atmosphere {
  type 4
  samples 20        // Number of samples in first distance interval
  distance 50       // Atmosphere density, similar to fog
  scattering 0.3    // Reflectivity of atmosphere, determines brightness
  aa_level 8        // Level of binary subdivision in case of aa
  aa_threshold 0.1  // Threshold for aa to push in
  jitter 0.25       // Amount of sample jittering
}

//
// Use atmosphere. 
//

atmosphere { Atmosphere1 }
