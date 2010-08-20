// PYROTECH INCLUDE FILE for POV-Ray 3.1
// 
// Copyright January 2000 Rune S. Johansen
// 
// This include file requires MegaPov 0.7:
// http://nathan.kopp.com/patched.htm
   
   #version unofficial megapov 1.1;
   
   #macro Pyrotech1 (_Location,_Size,_Clock,_Type,_Glows,_Brightness,_Color1,_Color2,_Seed,_Illuminate)
      #if (_Clock>0&_Clock<1)
         
         #declare _Light = 2.5*(1-_Clock)*sqrt(_Clock);
         
         #declare _S = seed(_Seed);
         
         #declare _X = 0;
         #while (_X<_Glows)
            glow {
               type 0
               
               #declare _V = <1,1,1>;
               #while (vlength(_V)>1)
                  #declare _V = (<rand(_S),rand(_S),rand(_S)>-0.5)*2;
               #end
               #if (_Type=2) #declare _V = vnormalize(_V); #end
               location _V*_Size*sqrt(_Clock)+_Location
               
               color vnormalize(<
                  _Color1.x+(_Color2-_Color1).x*rand(_S),
                  _Color1.y+(_Color2-_Color1).y*rand(_S),
                  _Color1.z+(_Color2-_Color1).z*rand(_S),
               >) * _Brightness*_Light
            }
            #declare _X = _X+1;
         #end
         
         #if (_Illuminate>0) light_source {_Location, _Light*_Illuminate} #end
         
      #end
   #end
   