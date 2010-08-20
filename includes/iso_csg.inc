// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %                                                                   %
// %   IsoCSG Library - version 0.7                                    %
// %                                                                   %
// %   iso_csg.inc - CSG-like operations with isosurface functions     %
// %                                                                   %
// %   written June 2001 - June 2003                                   %
// %   by Christoph Hormann <chris_hormann@gmx.de>                     %
// %   and ABX <abx@abx.art.pl>                                        %
// %                                                                   %
// %   MegaPOV 1.0 adapted version (sor_spline, f_triangle)            %
// %                                                                   %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %                                                                   %
// %   Feel free to use this file for your povray work, I encourage    %
// %   you to contact me if you have ideas for improvements.           %
// %                                                                   %
// %   This is an experimental version so syntax and used methods      %
// %   are subject to changes.                                         %
// %                                                                   %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#ifdef(iso_CSG_Inc_Temp)
// do nothing
#else
#declare iso_CSG_Inc_Temp = version;

#ifdef(View_POV_Include_Stack)
#   debug "including iso_csg.inc (MegaPOV version)\n"
#end

#declare IsoCSG_Version = 0.7;

#include "math.inc"
#include "transforms.inc"
#include "mp_functions.inc"

#version unofficial megapov 1.0;

//-------------------------------------------------------------
// ----   CSG macros   ----------------------------------------
//-------------------------------------------------------------

#macro IC_Merge2(_ICSG_fn_A, _ICSG_fn_B)
  function {                  // merge 2 objects
    min(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z))
  }
#end

#macro IC_Merge3(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C)
  function {                  // merge 3 objects
    min(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z),
        _ICSG_fn_C(x, y, z))
  }
#end

#macro IC_Merge4(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D)
  function {                  // merge 4 objects
    min(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z),
        _ICSG_fn_C(x, y, z),
        _ICSG_fn_D(x, y, z))
  }
#end

#macro IC_Merge5(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_fn_E)
  function {                  // merge 5 objects
    min(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z),
        _ICSG_fn_C(x, y, z),
        _ICSG_fn_D(x, y, z),
        _ICSG_fn_E(x, y, z))
  }
#end

#macro IC_Merge_Array(_ICSG_Array)        // merge an array of objects
  #local Size=dimension_size(_ICSG_Array,1);

  function {
    min(
      #local Counter=0;
      #while (Counter<Size)
        #if (Counter>0) , #end
          _ICSG_Array[Counter] (x,y,z)
        #local Counter=Counter+1;
      #end
    )
  }
#end


#macro IC_Intersection2(_ICSG_fn_A, _ICSG_fn_B)
  function {                  // intersection between 2 objects
    max(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z))
  }
#end

#macro IC_Intersection3(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C)
  function {                  // intersection between 3 objects
    max(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z),
        _ICSG_fn_C(x, y, z))
  }
#end

#macro IC_Intersection4(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D)
  function {                  // intersection between 4 objects
    max(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z),
        _ICSG_fn_C(x, y, z),
        _ICSG_fn_D(x, y, z))
  }
#end

#macro IC_Intersection5(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_fn_E)
  function {                  // intersection between 5 objects
    max(_ICSG_fn_A(x, y, z),
        _ICSG_fn_B(x, y, z),
        _ICSG_fn_C(x, y, z),
        _ICSG_fn_D(x, y, z),
        _ICSG_fn_E(x, y, z))
  }
#end

#macro IC_Intersection_Array(_ICSG_Array)     // Intersection of an array of objects
  #local Size=dimension_size(_ICSG_Array,1);

  function {
    max(
      #local Counter=0;
      #while (Counter<Size)
        #if (Counter>0) , #end
          _ICSG_Array[Counter] (x,y,z)
        #local Counter=Counter+1;
      #end
    )
  }
#end



#macro IC_Difference2(_ICSG_fn_A, _ICSG_fn_B)
  function {                  // difference between 2 objects
    max(_ICSG_fn_A(x, y, z),
      (-_ICSG_fn_B(x, y, z)))
  }
#end

#macro IC_Difference3(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C)
  function {                  // difference between 3 objects
    max(_ICSG_fn_A(x, y, z),
      (-_ICSG_fn_B(x, y, z)),
      (-_ICSG_fn_C(x, y, z)))
  }
#end

#macro IC_Difference4(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D)
  function {                  // difference between 4 objects
    max(_ICSG_fn_A(x, y, z),
      (-_ICSG_fn_B(x, y, z)),
      (-_ICSG_fn_C(x, y, z)),
      (-_ICSG_fn_D(x, y, z)))
  }
#end

#macro IC_Difference5(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_fn_E)
  function {                  // difference between 5 objects
    max(_ICSG_fn_A(x, y, z),
      (-_ICSG_fn_B(x, y, z)),
      (-_ICSG_fn_C(x, y, z)),
      (-_ICSG_fn_D(x, y, z)),
      (-_ICSG_fn_E(x, y, z)))
  }
#end

#macro IC_Difference_Array(_ICSG_Array)     // Difference of an array of objects
  #local Size=dimension_size(_ICSG_Array,1);

  function {
    max(
      #local Counter=0;
      #while (Counter<Size)
        #if (Counter>0)
          , -
        #end
          _ICSG_Array[Counter] (x,y,z)
        #local Counter=Counter+1;
      #end
    )
  }
#end

#macro IC_Inverse(_ICSG_Fn)
  function {
    -_ICSG_Fn(x,y,z)
  }
#end


//-------------------------------------------------------------
// ----   Shape macros   --------------------------------------
//-------------------------------------------------------------

#macro IC_Plane (_ICSG_Direction, _ICSG_Distance)
  #local Direction=_ICSG_Direction+<0,0,0>;

  #local Cx=Direction.x;
  #local Cy=Direction.y;
  #local Cz=Direction.z;

  function {
    ((x*Cx)+(y*Cy)+(z*Cz)-_ICSG_Distance)
  }
#end

#macro IC_Sphere (_ICSG_Center, _ICSG_Radius)
  #local Center=_ICSG_Center+<0,0,0>;

  #local Cx=Center.x;
  #local Cy=Center.y;
  #local Cz=Center.z;

  function {
    f_sphere(x-Cx, y-Cy, z-Cz, _ICSG_Radius)
    //(sqrt((x-Cx)^2 + (y-Cy)^2 + (z-Cz)^2) - _ICSG_Radius)
  }
#end

#macro IC_Box (_ICSG_Start, _ICSG_End)
  #local Start=_ICSG_Start+<0,0,0>;
  #local End=_ICSG_End+<0,0,0>;

  #local Cx=max(Start.x, End.x);
  #local Cy=max(Start.y, End.y);
  #local Cz=max(Start.z, End.z);
  #local Dx=min(Start.x, End.x);
  #local Dy=min(Start.y, End.y);
  #local Dz=min(Start.z, End.z);

  function {
    max(x-Cx, y-Cy, z-Cz, Dx-x, Dy-y, Dz-z)
  }
#end

#macro IC_Round_Box( _ICSG_Start , _ICSG_End , _ICSG_Radius )
  #local Start=_ICSG_Start+<0,0,0>;
  #local End=_ICSG_End+<0,0,0>;

  #local Cx=(Start.x + End.x)/2;
  #local Cy=(Start.y + End.y)/2;
  #local Cz=(Start.z + End.z)/2;
  #local Dx=abs(Start.x - End.x)/2;
  #local Dy=abs(Start.y - End.y)/2;
  #local Dz=abs(Start.z - End.z)/2;

  function {
    f_rounded_box(x-Cx, y-Cy, z-Cz, _ICSG_Radius, Dx, Dy, Dz)
  }
#end

#macro IC_Torus (_ICSG_MaR, _ICSG_MiR)
  function {
    f_torus(x, y, z, _ICSG_MaR, _ICSG_MiR)
  }
#end

#macro IC_Cylinder (_ICSG_Start, _ICSG_End, _ICSG_Radius)
  #local Start=_ICSG_Start+<0,0,0>;

  #local Cx=Start.x;
  #local Cy=Start.y;
  #local Cz=Start.z;

  #local Len=vlength(_ICSG_End-Start);

  #if (Len=0)
    #error "iso_csg.inc: Error: zero height cylinder"
  #end

  #local fn_T=function { Reorient_Trans(_ICSG_End-Start, x)  }

  #local fn_X=
  function(x, y, z){
    max(sqrt(pow(y, 2) + pow(z, 2)) - _ICSG_Radius, -x, x-Len)
  }
  #local fn_Y=
  function(x, y, z){
    fn_X(fn_T(x, y, z).x,
         fn_T(x, y, z).y,
         fn_T(x, y, z).z)
  }

  function {
    (fn_Y((x-Cx),(y-Cy),(z-Cz)))
  }
#end


#macro IC_Cylinder_Hole (_ICSG_Start, _ICSG_End, _ICSG_Radius, _ICSG_Hole)
  #local Start=_ICSG_Start+<0,0,0>;

  #local Cx=Start.x;
  #local Cy=Start.y;
  #local Cz=Start.z;

  #local Len=vlength(_ICSG_End-Start);

  #if (Len=0)
    #error "iso_csg.inc: Error: zero height cylinder"
  #end

  #local fn_T = function { Reorient_Trans( _ICSG_End-Start , x) }

  #local fn_X = IC_Box( <0,_ICSG_Hole,-2*max(Len,_ICSG_Radius,_ICSG_Hole)> ,
                        <Len,_ICSG_Radius,2*max(Len,_ICSG_Radius,_ICSG_Hole)> );

  #local fn_Y = function(x, y, z){
    fn_X( fn_T(x, y, z).x , f_r( 0 , fn_T(x, y, z).y , fn_T(x, y, z).z ) , 0 )
  }

  function {
    fn_Y( x - Cx , y - Cy , z - Cz )
  }

#end


#macro IC_Cone (_ICSG_Start, _ICSG_Radius1, _ICSG_End, _ICSG_Radius2)
  #local Start=_ICSG_Start+<0,0,0>;

  #local Cx=Start.x;
  #local Cy=Start.y;
  #local Cz=Start.z;

  #local Len=vlength(_ICSG_End-Start);

  #if (Len=0)
    #error "iso_csg.inc: Error: zero height cone"
  #end

  #local fn_T=function { Reorient_Trans(_ICSG_End-Start, x)  }

  #local fn_X=function(x, y, z){
    max(sqrt(pow(y, 2) + pow(z, 2)) - _ICSG_Radius1+x*((_ICSG_Radius1-_ICSG_Radius2)/Len), -x, x-Len)
  }
  #local fn_Y=
  function(x, y, z){
    fn_X(fn_T(x, y, z).x,
         fn_T(x, y, z).y,
         fn_T(x, y, z).z)
  }

  function {
    (fn_Y((x-Cx),(y-Cy),(z-Cz)))
  }
#end


#macro IC_Superellipsoid (_ICSG_EW, _ICSG_NS)
  function {
    -f_superellipsoid(x, y, z, _ICSG_EW, _ICSG_NS)
  }
#end


// ======== SOR shape (by ABX <abx@abx.art.pl>) ==============

#macro new_sor_spline(_ICSG_Array)
  #local n=dimension_size(_ICSG_Array,1);
  #local f_sor_spline=function{spline{
    sor_spline
    #while (n)
      #local n=n-1;
      (_ICSG_Array[n].v),(_ICSG_Array[n].u)
    #end
  }};
  function(h){f_sor_spline(h).x}
#end

#declare IC_Open=yes;
#declare IC_Close=no;

#macro IC_Sor(_ICSG_Array,_ICSG_Open)
  #local f_sor=new_sor_spline(_ICSG_Array);
  #if(_ICSG_Open=IC_Close)
    IC_Intersection3(
      function{f_sphere(x,0,z,f_sor(y))},
      IC_Plane(y,_ICSG_Array[dimension_size(_ICSG_Array,1)-2].v),
      IC_Plane(-y,-_ICSG_Array[1].v)
    )
  #else
    function{f_sphere(x,0,z,f_sor(y))}
  #end
#end



// ======== Triangle shape (by ABX <abx@abx.art.pl>) ==============

#macro IC_Triangle(V1,V2,V3,Thickness)

  #local P1=V1+<0,0,0>;
  #local P2=V2+<0,0,0>;
  #local P3=V3+<0,0,0>;
  function {
    f_triangle(
      x, y, z,
      P1.x, P1.y, P1.z,
      P2.x, P2.y, P2.z,
      P3.x, P3.y, P3.z,
      Thickness
    )
  }
#end

// ======== Heightfield shape (by Christoph Hormann <chris_hormann@gmx.de>) ==============

#macro IC_ImageFName_Function(_ICSG_Image_Name)

  #local Fnm_len=strlen(_ICSG_Image_Name);

  #local Cnt=Fnm_len;

  #while (Cnt>0)
    #if (strcmp(substr(_ICSG_Image_Name,Cnt,1), ".")=0)
      #local Fnm_ext3=substr(_ICSG_Image_Name,Cnt+1,3)
      #local Fnm_ext4=substr(_ICSG_Image_Name,Cnt+1,min(4, Fnm_len-Cnt))
      #if ((strcmp(Fnm_ext3, "jpg")=0) | (strcmp(Fnm_ext4, "jpeg")=0))
        #local File_type=1;           // jpg image
      #else
        #if ((strcmp(Fnm_ext3, "tif")=0) | (strcmp(Fnm_ext4, "tiff")=0))
          #local File_type=2;         // tif image
        #else
          #if (strcmp(Fnm_ext3, "tga")=0)
            #local File_type=3;       // tga image
          #else
            #if (strcmp(Fnm_ext3, "ppm")=0)
              #local File_type=4;     // ppm image
            #else
              #if (strcmp(Fnm_ext3, "pgm")=0)
                #local File_type=5;   // pgm image
              #else
                #if (strcmp(Fnm_ext3, "gif")=0)
                  #local File_type=6; // gif image
                #else
                  #local File_type=0; // png image (default)
                #end
              #end
            #end
          #end
        #end
      #end
      #local Cnt=0;
    #end
    #local Cnt=Cnt-1;
  #end

  function {
    pigment {
      image_map {
        #switch (File_type)
          #case (1)
            jpeg _ICSG_Image_Name
          #break
          #case (2)
            tiff _ICSG_Image_Name
          #break
          #case (3)
            tga _ICSG_Image_Name
          #break
          #case (4)
            ppm _ICSG_Image_Name
          #break
          #case (5)
            pgm _ICSG_Image_Name
          #break
          #case (6)
            gif _ICSG_Image_Name
          #break
        #else
          png _ICSG_Image_Name
        #end

        map_type 0
        interpolate 2
        once
      }
    }
  }

#end

#macro IC_Heightfield(_ICSG_Image_Name, _ICSG_Intensity)

  #local fn_Height=IC_ImageFName_Function(_ICSG_Image_Name)

  function {
    y - fn_Height(max(0.0001, min(1-0.0001, x)), max(0.0001, min(1-0.0001, z)), 0).gray*_ICSG_Intensity
  }
#end

#macro IC_Heightfield_Function(_ICSG_Fn_Height)
  function {
    y - _ICSG_Fn_Height(x, 1-z, 0)
  }
#end

#macro IC_HF_Sphere(_ICSG_Radius, _ICSG_Image_Name, _ICSG_Intensity)

  #local fn_Height=IC_ImageFName_Function(_ICSG_Image_Name)

  #local fn_Pattern=
    function {
      fn_Height(1-(f_th(x,z,y)+pi)/(2*pi), f_ph(x,-z,y)/pi, 0).gray
    }

  function {
    f_sphere(x, y, z, _ICSG_Radius) - fn_Pattern(x, y, z)*_ICSG_Intensity
  }
#end

#macro IC_HF_Sphere_Function(_ICSG_Radius, _ICSG_Fn_Height)

  #local fn_Pattern=
    function {
      _ICSG_Fn_Height(1-(f_th(x,z,y)+pi)/(2*pi), f_ph(x,-z,y)/pi, 0)
    }

  function {
    f_sphere(x, y, z, _ICSG_Radius) - fn_Pattern(x, y, z)
  }
#end

#macro IC_HF_Cylinder(_ICSG_Radius, _ICSG_Length, _ICSG_Image_Name, _ICSG_Intensity)

  #local fn_Height=IC_ImageFName_Function(_ICSG_Image_Name)

  #local fn_Pattern=
    function {
      fn_Height(1-(f_th(x,z,y)+pi)/(2*pi), max(0.0001, min(1-0.0001, z/_ICSG_Length)), 0).gray
    }

  function {
    f_sphere(x, y, 0, _ICSG_Radius) - fn_Pattern(x, y, z)*_ICSG_Intensity
  }
#end

#macro IC_HF_Cylinder_Function(_ICSG_Radius, _ICSG_Fn_Height)

  #local fn_Pattern=
    function {
      _ICSG_Fn_Height(1-(f_th(x,z,y)+pi)/(2*pi), z, 0)
    }

  function {
    f_sphere(x, y, 0, _ICSG_Radius) - fn_Pattern(x, y, z)
  }
#end


// ======== BLOB shape (by Christoph Hormann <chris_hormann@gmx.de>) ==============

#macro IC_BlobCylinder (_ICSG_Start, _ICSG_End, _ICSG_RadiusVal, _ICSG_StrengthVal)
  #local Start=_ICSG_Start+<0,0,0>;

  #local Cx=Start.x;
  #local Cy=Start.y;
  #local Cz=Start.z;

  #local Len=vlength(_ICSG_End-Start);

  #if (Len=0)
    #error "iso_csg.inc: Error: zero height cylinder"
  #end

  #local fn_T=function { Reorient_Trans(_ICSG_End-Start, x)  }

  #local fn_X=
  function(x, y, z){
    select(x,f_r(x, y, z),select(x-Len,f_r(0, y, z),f_r(x-Len, y, z)))
  }

  #local fn_Y=
  function(x, y, z){
    fn_X(fn_T(x, y, z).x,fn_T(x, y, z).y,fn_T(x, y, z).z)
  }

  #local fn_Z=
  function {
    (fn_Y((x-Cx),(y-Cy),(z-Cz)))
  }

  function {
    -select(
      fn_Z(x, y, z)-_ICSG_RadiusVal,
      _ICSG_StrengthVal*pow( 1- pow(fn_Z(x, y, z)/_ICSG_RadiusVal,2 ),2),
      0
    )
  }

#end

#macro IC_BlobSphere (_ICSG_Center, _ICSG_RadiusVal, _ICSG_StrengthVal)
  #local Center=_ICSG_Center+<0,0,0>;

  #local Cx=Center.x;
  #local Cy=Center.y;
  #local Cz=Center.z;

  #local fn_Z=
  function {
    (f_r((x-Cx),(y-Cy),(z-Cz)))
  }

  function {
    -select(
      fn_Z(x, y, z)-_ICSG_RadiusVal,
      _ICSG_StrengthVal*pow( 1- pow(fn_Z(x, y, z)/_ICSG_RadiusVal,2 ),2),
      0
    )
  }

#end

#macro IC_BlobShape (_ICSG_fn_Shape, _ICSG_RadiusVal, _ICSG_StrengthVal)

  #local fn_Z=
  function {
    (max(_ICSG_fn_Shape(x, y, z), 0))
  }

  function {
    -select(
      fn_Z(x, y, z)-_ICSG_RadiusVal,
      _ICSG_StrengthVal*pow( 1- pow(fn_Z(x, y, z)/_ICSG_RadiusVal,2 ),2),
      0
    )
  }

#end

#macro IC_Blob2(_ICSG_fn_A, _ICSG_fn_B, _ICSG_Threshold)
  function {                  // blob with 2 components
      _ICSG_fn_A(x, y, z)
    + _ICSG_fn_B(x, y, z)
    + _ICSG_Threshold
  }
#end

#macro IC_Blob3(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_Threshold)
  function {                  // blob with 3 components
      _ICSG_fn_A(x, y, z)
    + _ICSG_fn_B(x, y, z)
    + _ICSG_fn_C(x, y, z)
    + _ICSG_Threshold
  }
#end

#macro IC_Blob4(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_Threshold)
  function {                  // blob with 4 components
      _ICSG_fn_A(x, y, z)
    + _ICSG_fn_B(x, y, z)
    + _ICSG_fn_C(x, y, z)
    + _ICSG_fn_D(x, y, z)
    + _ICSG_Threshold
  }
#end

#macro IC_Blob5(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_fn_E, _ICSG_Threshold)
  function {                  // blob with 5 components
      _ICSG_fn_A(x, y, z)
    + _ICSG_fn_B(x, y, z)
    + _ICSG_fn_C(x, y, z)
    + _ICSG_fn_D(x, y, z)
    + _ICSG_fn_E(x, y, z)
    + _ICSG_Threshold
  }
#end

#macro IC_Blob_Array(_ICSG_Array, _ICSG_Threshold)     // blob an array of components
  #local Size=dimension_size(_ICSG_Array,1);

  function {
    (
    #local Counter=0;
    #while (Counter<Size)
      #if (Counter>0) + #end
        _ICSG_Array[Counter] (x,y,z)
      #local Counter=Counter+1;
    #end
    )
    + _ICSG_Threshold
  }
#end

#macro IC_Blob_Linear(_ICSG_fn_Blob, _ICSG_RadiusVal, _ICSG_StrengthVal, _ICSG_Threshold)
  function {                  // linearize the blob function
    sqrt(
      abs(
        -(sqrt(abs((_ICSG_fn_Blob(x, y, z)-_ICSG_Threshold)/_ICSG_StrengthVal))-1)
      )
    )*_ICSG_RadiusVal
  }
#end


// ===== Exponential BLOB shape (by Christoph Hormann <chris_hormann@gmx.de>) ===========

#macro IC_EBlob2(_ICSG_fn_A, _ICSG_fn_B, _ICSG_Threshold)
  function {                  // blob with 2 components
    (1+_ICSG_Threshold)
    -pow(_ICSG_Threshold, _ICSG_fn_A(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_B(x, y, z))
  }
#end

#macro IC_EBlob3(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_Threshold)
  function {                  // blob with 3 components
    (1+_ICSG_Threshold)
    -pow(_ICSG_Threshold, _ICSG_fn_A(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_B(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_C(x, y, z))
  }
#end

#macro IC_EBlob4(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_Threshold)
  function {                  // blob with 4 components
    (1+_ICSG_Threshold)
    -pow(_ICSG_Threshold, _ICSG_fn_A(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_B(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_C(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_D(x, y, z))
  }
#end

#macro IC_EBlob5(_ICSG_fn_A, _ICSG_fn_B, _ICSG_fn_C, _ICSG_fn_D, _ICSG_fn_E, _ICSG_Threshold)
  function {                  // blob with 5 components
    (1+_ICSG_Threshold)
    -pow(_ICSG_Threshold, _ICSG_fn_A(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_B(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_C(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_D(x, y, z))
    -pow(_ICSG_Threshold, _ICSG_fn_E(x, y, z))
  }
#end

#macro IC_EBlob_Array(_ICSG_Array, _ICSG_Threshold)     // blob an array of components
  #local Size=dimension_size(_ICSG_Array,1);

  function {
    (1+_ICSG_Threshold)
    #local Counter=0;
    #while (Counter<Size)
      -pow(_ICSG_Threshold, _ICSG_Array[Counter] (x, y, z) )
      #local Counter=Counter+1;
    #end
  }
#end

#macro IC_EBlob_ArrayS(_ICSG_Array, _ICSG_Sgn, _ICSG_Threshold)  // blob an array of components

  #local Size=dimension_size(_ICSG_Array,1);
  #local SizeS=dimension_size(_ICSG_Sgn,1);

  function {
    (1+_ICSG_Threshold)
    #local Counter=0;
    #while (Counter<Size)
      #if (Counter<SizeS)
        -_ICSG_Sgn[Counter]*pow(_ICSG_Threshold, _ICSG_Array[Counter] (x, y, z) )
      #else
        -pow(_ICSG_Threshold, _ICSG_Array[Counter] (x, y, z) )
      #end
      #local Counter=Counter+1;
    #end
  }
#end

#macro IC_EBlob_Linear(_ICSG_fn_Blob, _ICSG_Threshold)
  function {                  // linearize the blob function
    log(max(1e-7, abs((1+_ICSG_Threshold) - _ICSG_fn_Blob(x, y, z))))/
    log(_ICSG_Threshold)
  }
#end

// ======== Torus shapes (by ABX <abx@abx.art.pl>) ==============

#macro IC_Shaped_Torus(_ICSG_Fn,_ICSG_Radius)
  function{_ICSG_Fn(f_r(x,0,z)-_ICSG_Radius,y,0)}
#end

#macro IC_Fan(_ICSG_Major_Radius,_ICSG_Minor_Radius,_ICSG_Angle)
  #if(_ICSG_Angle>=360)
    #local _ICSG_Fan = IC_Torus(_ICSG_Major_Radius,_ICSG_Minor_Radius);
  #else
    #local A0=clip(radians(_ICSG_Angle)/2,0,pi);
    #local _ICSG_Fan = IC_Intersection2(
      IC_Torus(_ICSG_Major_Radius,_ICSG_Minor_Radius),
      function{_ICSG_Major_Radius*(abs(f_th(x,0,z))-A0)}
    );
  #end
  function{_ICSG_Fan(x,y,z)}
#end

#macro IC_Shaped_Fan(_ICSG_Fn,_ICSG_Radius,_ICSG_Angle)
  #if(_ICSG_Angle>=360)
    #local _ICSG_Fan = IC_Shaped_Torus(_ICSG_Fn,_ICSG_Radius);
  #else
    #local A0=clip(radians(_ICSG_Angle)/2,0,pi);
    #local _ICSG_Fan = IC_Intersection2(
      IC_Shaped_Torus(_ICSG_Fn,_ICSG_Radius),
      function{_ICSG_Radius*(abs(f_th(x,0,z))-A0)}
    );
  #end
  function{_ICSG_Fan(x,y,z)}
#end

#macro IC_Arc(_ICSG_Fn,_ICSG_Radius,_ICSG_Angle1,_ICSG_Angle2)
  #local A1=min(_ICSG_Angle1,_ICSG_Angle2);
  #local A2=max(_ICSG_Angle1,_ICSG_Angle2);
  #local A=A2-A1;
  #if(A>=360)
    #local _ICSG_Arc = IC_Torus(_ICSG_Fn,_ICSG_Radius);
  #else
    #local _ICSG_Arc = IC_Rotate(IC_Fan(_ICSG_Fn,_ICSG_Radius,A),y*(A1+A/2));
  #end
  function{_ICSG_Arc(x,y,z)}
#end

#macro IC_Shaped_Arc(_ICSG_Fn,_ICSG_Radius,_ICSG_Angle1,_ICSG_Angle2)
  #local A1=min(_ICSG_Angle1,_ICSG_Angle2);
  #local A2=max(_ICSG_Angle1,_ICSG_Angle2);
  #local A=A2-A1;
  #if(A>=360)
    #local _ICSG_Arc = IC_Shaped_Torus(_ICSG_Fn,_ICSG_Radius);
  #else
    #local _ICSG_Arc = IC_Rotate(IC_Shaped_Fan(_ICSG_Fn,_ICSG_Radius,A),y*(A1+A/2));
  #end
  function{_ICSG_Arc(x,y,z)}
#end

#macro Point(Current,Desired,Up)
  #local vZC=vnormalize(Current+<0,0,0>);
  #local vZD=vnormalize(Desired+<0,0,0>);
  #local vUp=vnormalize(Up+<0,0,0>);

  #local vXC=vnormalize(vcross(vUp,vZC));
  #local vXD=vnormalize(vcross(vUp,vZD));
  #local vYC=vnormalize(vcross(vZC,vXC));
  #local vYD=vnormalize(vcross(vZD,vXD));
  matrix < vXC.x,vYC.x,vZC.x, vXC.y,vYC.y,vZC.y, vXC.z,vYC.z,vZC.z, 0,0,0>
  matrix < vXD.x,vXD.y,vXD.z, vYD.x,vYD.y,vYD.z, vZD.x,vZD.y,vZD.z, 0,0,0>
#end

#macro Matrix(mv_X,mv_Y,mv_Z,mv_L)
  matrix <(mv_X).x,(mv_X).y,(mv_X).z,(mv_Y).x,(mv_Y).y,(mv_Y).z,(mv_Z).x,(mv_Z).y,(mv_Z).z,(mv_L).x,(mv_L).y,(mv_L).z >
#end

#macro IC_Torus_Spline( TorRadius, Points, StartVect )

  #local V=<0,0,0>+StartVect;
  #local Numpoints = dimension_size( Points, 1 );
  #local Cur = 0;
  #local Components = array[dimension_size( Points, 1 )-1];

  #while (Cur < Numpoints-1 )
    #local A=Points[Cur];
    #local B=Points[Cur+1];
    #if (V.x=0&V.y=0&V.z=0)
      #local C=Points[Cur+2];
      #if (vlength(vcross(C-A,B-A))=0)
        #local V=B-A;
        #local Cos=0;
        #local Axis=<0,0,0>;
      #else
        #local Axis=vnormalize(vcross((C-A),(B-A)));
        #local Base1=vnormalize(C-A);
        #local Base2=vnormalize(vcross(Axis,Base1));
        #local VB=<0.5*vlength(C-A),0,0>;
        #local VA=vcross(VB,z);
        #local VD=.5*<vdot(B-A,Base1),vdot(B-A,Base2),0>;
        #local VC=vcross(VD,z);
        #local Beta=((VD-VB).y*VA.x-(VD-VB).x*VA.y)/(VC.x*VA.y-VC.y*VA.x);
        #local Center=A+VD.x*Base1+VD.y*Base2+Beta*(VC.x*Base1+VC.y*Base2);
        #local Radius=vlength(Center-A);
        #local Cos=1;
        #local V=vcross( Axis,Center-A );
      #end
      #local B=C;
      #local Cur=Cur+1;
    #else
      #local Axis=vnormalize(vcross((B-A),V));
      #local Dir=vnormalize(vcross(V, Axis ));
      #local Cos=vdot(vnormalize(B-A), Dir);
      #local Radius=abs(.5*vlength(B-A)/Cos);
      #local Center=A+Radius*Dir;
    #end
    #if ( Cos & (Axis.x!=0|Axis.y!=0|Axis.z!=0))
      #local V1=vcross(B-Center, Axis);
      #local Angle = VAngleD(A-Center, B-Center);
      #if ( vdot(vcross(V,A-Center),vcross(V, V1))>0 )
        #local Angle=360-Angle;
      #end
      #declare Components[Cur]= IC_Transform(
        IC_Fan(Radius, TorRadius,Angle),
        transform{
          rotate y*Angle/2
          Matrix(
            vnormalize(vcross(-Axis,vnormalize(A-Center))),
            vnormalize(Axis),
            vnormalize(A-Center),Center
          )
        }
      );
    #else
      #declare Components[Cur]=IC_Cylinder(A, B, TorRadius);
    #end
    #declare Cur=Cur+1;
    #declare V=V1;
  #end
  IC_Merge_Array(Components)
#end

#macro IC_Shaped_Torus_Spline( _ICSG_Fn, TorRadius, Points, StartVect )

  #local V=<0,0,0>+StartVect;
  #local Numpoints = dimension_size( Points, 1 );
  #local Cur = 0;
  #local Components = array[dimension_size( Points, 1 )-1];
  #local Rotate=0;
  #local IsRotated=no;

  #while (Cur < Numpoints-1 )
    #local A=Points[Cur];
    #local B=Points[Cur+1];
    #if (V.x=0&V.y=0&V.z=0)
      #local C=Points[Cur+2];
      #if (vlength(vcross(C-A,B-A))=0)
        #local V=B-A;
        #local Cos=0;
        #local Axis=<0,0,0>;
      #else
        #local Axis=vnormalize(vcross((C-A),(B-A)));
        #local Base1=vnormalize(C-A);
        #local Base2=vnormalize(vcross(Axis,Base1));
        #local VB=<0.5*vlength(C-A),0,0>;
        #local VA=vcross(VB,z);
        #local VD=.5*<vdot(B-A,Base1),vdot(B-A,Base2),0>;
        #local VC=vcross(VD,z);
        #local Beta=((VD-VB).y*VA.x-(VD-VB).x*VA.y)/(VC.x*VA.y-VC.y*VA.x);
        #local Center=A+VD.x*Base1+VD.y*Base2+Beta*(VC.x*Base1+VC.y*Base2);
        #local Radius=vlength(Center-A);
        #local Cos=1;
        #local V=vcross( Axis,Center-A );
      #end
      #local B=C;
      #local Cur=Cur+1;
    #else
      #local Axis=vnormalize(vcross((B-A),V));
      #local Dir=vnormalize(vcross(V, Axis ));
      #local Cos=vdot(vnormalize(B-A), Dir);
      #local Radius=abs(.5*vlength(B-A)/Cos);
      #local Center=A+Radius*Dir;
    #end
    #ifdef(O)#declare O=union{object{O}#end
    #ifndef(O)#declare O=union{#end
      cylinder{A Center TorRadius/9 pigment{red 1}}
      cylinder{B Center TorRadius/9 pigment{red 1}}
    }
    #debug "\n"
    #if ( Cos & (Axis.x!=0|Axis.y!=0|Axis.z!=0))
      #local V1=vcross(B-Center, Axis);
      #local Angle = VAngleD(A-Center, B-Center);
      #local Axis1 = vcross(A-Center, B-Center);
      #local DAngle = 0;
      #if ( vdot(vcross(V,A-Center),vcross(V, V1))>0 )
        #debug "a"
        #local Angle=360-Angle;
        #local DAngle = 360;
        #local Switch = -1;
//        #if(IsRotated)#if(!Last)#local Switch = -1;#end#end
        #if(IsRotated)#if(!Last)#if(Cur>1)
          #debug "b"
          #local Switch = 1;
          #local DAngle = 0;
        #end#end#end
        #local Last = yes;
      #else
        #debug "c"
        #local Axis1=-Axis1;
        #local Switch = -1;
        #local DAngle = 360;
        #if(IsRotated)
//          #if(Last)
            #debug "d"
            #local Switch = 1;
            #local DAngle = 0;
//          #end
        #end
        #local Last = no;
      #end
      #debug "\n"
      #declare O=union{
        object{O}
        cone{Center TorRadius/4 Center+Axis1 0 pigment{green 1}}
      }
      #local Rotate = Rotate + (#if(IsRotated) Switch*VAngleD( Axis1, Axis2) + DAngle #else 0 #end) ;
      #declare Components[Cur]= IC_Transform(
        IC_Shaped_Fan(
          #if(Rotate!=0) IC_Rotate( #end
            _ICSG_Fn,
          #if(Rotate!=0) Rotate*z), #end
          Radius,
          Angle
        ),
        transform{
          rotate y*Angle/2
          Matrix(
            vnormalize(vcross(-Axis,vnormalize(A-Center))),
            vnormalize(Axis),
            vnormalize(A-Center),Center
          )
        }
      );
      #local Axis2=Axis1;
      #local IsRotated = yes;
    #else
      #declare Components[Cur]=IC_Cylinder(A, B, TorRadius);
    #end
    #declare Cur=Cur+1;
    #declare V=V1;
  #end
  IC_Merge_Array(Components)
#end

//-------------------------------------------------------------
// ----   Transform macros   ----------------------------------
//-------------------------------------------------------------

#macro IC_Transform (_ICSG_Fn, _ICSG_Trans)

  #local fn_T=function { transform { _ICSG_Trans inverse } }

  function {
    _ICSG_Fn(fn_T(x, y, z).x,
             fn_T(x, y, z).y,
             fn_T(x, y, z).z)
  }
#end

#macro IC_Translate (_ICSG_Fn, _ICSG_Vect)
  #local Vect=_ICSG_Vect+<0,0,0>;

  #local Cx=Vect.x;
  #local Cy=Vect.y;
  #local Cz=Vect.z;

  function {
    (_ICSG_Fn(x-Cx, y-Cy, z-Cz))
  }
#end

#macro IC_Scale (_ICSG_Fn, _ICSG_Vect)
  #local Vect=_ICSG_Vect+<0,0,0>;

  #local Cx=Vect.x;
  #local Cy=Vect.y;
  #local Cz=Vect.z;
  #if (Cx=0)
    #warning "iso_csg.inc: Scale 0 changed to Scale 1"
    Cx=1.0;
  #end
  #if (Cy=0)
    #warning "iso_csg.inc: Scale 0 changed to Scale 1"
    Cy=1.0;
  #end
  #if (Cz=0)
    #warning "iso_csg.inc: Scale 0 changed to Scale 1"
    Cz=1.0;
  #end

  function {
    (_ICSG_Fn(x/Cx, y/Cy, z/Cz))
  }
#end

#macro IC_ScaleC (_ICSG_Fn, _ICSG_Vect)       // Range corrected version
  #local Vect=_ICSG_Vect+<0,0,0>;

  #local Cx=Vect.x;
  #local Cy=Vect.y;
  #local Cz=Vect.z;
  #if (Cx=0)
    #warning "iso_csg.inc: Scale 0 changed to Scale 1"
    Cx=1.0;
  #end
  #if (Cy=0)
    #warning "iso_csg.inc: Scale 0 changed to Scale 1"
    Cy=1.0;
  #end
  #if (Cz=0)
    #warning "iso_csg.inc: Scale 0 changed to Scale 1"
    Cz=1.0;
  #end

  #local Scale=(Cx+Cy+Cz)/3;

  function {
    (_ICSG_Fn(x/Cx, y/Cy, z/Cz)*Scale)
  }
#end

#macro IC_Matrix (_ICSG_Fn, _ICSG_Mtrx)       // not equivalent to the matrix transform!

  function {
    _ICSG_Fn(x*_ICSG_Mtrx[0][0] + y*_ICSG_Mtrx[0][1] + z*_ICSG_Mtrx[0][2],
             x*_ICSG_Mtrx[1][0] + y*_ICSG_Mtrx[1][1] + z*_ICSG_Mtrx[1][2],
             x*_ICSG_Mtrx[2][0] + y*_ICSG_Mtrx[2][1] + z*_ICSG_Mtrx[2][2])
  }
#end

#macro IC_RotateR (_ICSG_Fn, _ICSG_Vect)      // Rotate Radians
  #local Vect=_ICSG_Vect+<0,0,0>;

  #local Cx=-Vect.x;
  #local Cy=-Vect.y;
  #local Cz=-Vect.z;

  #local MtrxA=array[3][3]
  #local MtrxB=array[3][3]
  #local MtrxC=array[3][3]

  #local MtrxA[0][0] = 1.0;
  #local MtrxA[0][1] = 0;
  #local MtrxA[0][2] = 0;
  #local MtrxA[1][0] = 0;
  #local MtrxA[1][1] = cos(Cx);
  #local MtrxA[1][2] = -sin(Cx);
  #local MtrxA[2][0] = 0;
  #local MtrxA[2][1] = sin(Cx);
  #local MtrxA[2][2] = cos(Cx);

  #local MtrxB[0][0] = cos(Cy);
  #local MtrxB[0][1] = 0;
  #local MtrxB[0][2] = sin(Cy);
  #local MtrxB[1][0] = 0;
  #local MtrxB[1][1] = 1;
  #local MtrxB[1][2] = 0;
  #local MtrxB[2][0] = -sin(Cy);
  #local MtrxB[2][1] = 0;
  #local MtrxB[2][2] = cos(Cy);

  #local MtrxC[0][0] = cos(Cz);
  #local MtrxC[0][1] = -sin(Cz);
  #local MtrxC[0][2] = 0;
  #local MtrxC[1][0] = sin(Cz);
  #local MtrxC[1][1] = cos(Cz);
  #local MtrxC[1][2] = 0;
  #local MtrxC[2][0] = 0;
  #local MtrxC[2][1] = 0;
  #local MtrxC[2][2] = 1;

  #local fn_X=IC_Matrix (function(x, y, z){ _ICSG_Fn(x, y, z) }, MtrxA)
  #local fn_Y=IC_Matrix (function(x, y, z){ fn_X(x, y, z) }, MtrxB)

  IC_Matrix (function(x, y, z){ fn_Y(x, y, z) }, MtrxC)

#end

#macro IC_Rotate (_ICSG_Fn, _ICSG_Vect)       // Rotate Degrees
  #local Vect=_ICSG_Vect+<0,0,0>;

  #local Cx=(Vect.x/180)*pi;
  #local Cy=(Vect.y/180)*pi;
  #local Cz=(Vect.z/180)*pi;
  IC_RotateR (function(x, y, z){ _ICSG_Fn(x, y, z) }, <Cx, Cy, Cz>)
#end

// Special transforms using macros from 'transforms.inc'
// by Tor Olav Kristensen

#macro IC_Reorient(_ICSG_Fn, _ICSG_vAxis1, _ICSG_vAxis2)

  IC_Transform(
    function(x, y, z){ _ICSG_Fn(x, y, z) },
    transform { Reorient_Trans(_ICSG_vAxis1, _ICSG_vAxis2) }
  )

#end // macro IC_Reorient


#macro IC_AxisRotate(_ICSG_Fn, _ICSG_vAxis, _ICSG_Angle)

  IC_Transform(
    function(x, y, z){ _ICSG_Fn(x, y, z) },
    transform { Axis_Rotate_Trans(_ICSG_vAxis, _ICSG_Angle) }
  )

#end // macro IC_AxisRotate


//-------------------------------------------------------------

//-------------------------------------------------------------
// ----   Helper macros   -------------------------------------
//-------------------------------------------------------------

#macro IC_Threshold(_ICSG_Fn, _ICSG_Threshold)       // change the threshold of a function
  function { _ICSG_Fn(x, y, z) - _ICSG_Threshold }
#end

#macro IC_Displace(_ICSG_Fn, _ICSG_Fn_Displace)      // displace a surface
  function { _ICSG_Fn(x, y, z) - _ICSG_Fn_Displace(x, y, z) }
#end


#version iso_CSG_Inc_Temp;
#end
