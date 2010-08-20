// enviro.inc
//
// Written by: Henry Wagner (povray@henrywagner.org)
// Started: 8/6/2003

#version 3.5;

#declare Radiosity=on;
#declare Photons=off;
#declare show_Fog=false;

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

global_settings{
  // max_trace_level 15
  // assumed_gamma 2.2

  #if (Radiosity=on)
    radiosity{
      pretrace_start 0.08
      pretrace_end   0.01
      count 230
      
      nearest_count 5
      error_bound 1 // was 0.3
      recursion_limit 2
      
      low_error_factor 0.5
      gray_threshold 0.0
      minimum_reuse 0.015
      brightness 1

      adc_bailout 0.01/2
      normal on
    }
  #end

  #if (Photons=on)
    photons {
      spacing 0.002
    }
  #end

}

#if (show_Fog)
fog{
   fog_type 2
   fog_alt 1.2
   fog_offset 0
   color rgbt <0.60, 0.68, 0.82, 0.0>
   distance 700
   up y
}
#end
