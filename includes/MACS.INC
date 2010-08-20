#macro Matrix(mv_X,mv_Y,mv_Z,mv_L)
matrix <(mv_X).x,(mv_X).y,(mv_X).z,(mv_Y).x,(mv_Y).y,(mv_Y).z,(mv_Z).x,(mv_Z).y,(mv_Z).z,(mv_L).x,(mv_L).y,(mv_L).z >
#end

#macro Connect(Start,SR,End,ER)
  #local SP=Start+<0,0,0>;
  #local EP=End+<0,0,0>;
  #local D=vlength(EP-SP);
  #local Rd=SR-ER;
  #local D2=sqrt(D*D-Rd*Rd);
  cone { SP+(EP-SP)/D*Rd*(SR)/D,(SR)*D2/D,EP+(EP-SP)/D*Rd*(ER)/D,(ER)*D2/D }
#end

#macro RoundedBar(v_SP,v_EP,R)
  #local vSP=(v_SP)*<1,1,1>;
  #local vEP=(v_EP)*<1,1,1>;
  #local vS=<min(vSP.x,vEP.x),min(vSP.y,vEP.y),min(vSP.z,vEP.z)>;
  #local vE=<max(vSP.x,vEP.x),max(vSP.y,vEP.y),max(vSP.z,vEP.z)>;

  prism { vS.y,vE.y,9,
    <vE.x-R,vE.z>,<vE.x,vE.z-R>,<vE.x,vS.z+R>,
    <vE.x-R,vS.z>,<vS.x+R,vS.z>,<vS.x,vS.z+R>,
    <vS.x,vE.z-R>,<vS.x+R,vE.z>,<vE.x-R,vE.z> }
  cylinder { <vS.x+R,vS.y,vS.z+R>,<vS.x+R,vE.y,vS.z+R>,R }
  cylinder { <vE.x-R,vS.y,vS.z+R>,<vE.x-R,vE.y,vS.z+R>,R }
  cylinder { <vS.x+R,vS.y,vE.z-R>,<vS.x+R,vE.y,vE.z-R>,R }
  cylinder { <vE.x-R,vS.y,vE.z-R>,<vE.x-R,vE.y,vE.z-R>,R }
#end

#macro RoundedBox(v_SP,v_EP,R)
  #local vSP=(v_SP)*<1,1,1>;
  #local vEP=(v_EP)*<1,1,1>;
  #local vS=<min(vSP.x,vEP.x),min(vSP.y,vEP.y),min(vSP.z,vEP.z)>;
  #local vE=<max(vSP.x,vEP.x),max(vSP.y,vEP.y),max(vSP.z,vEP.z)>;

  box {<vS.x,vS.y+R,vS.z+R>,<vE.x,vE.y-R,vE.z-R>}
  box {<vS.x+R,vS.y,vS.z+R>,<vE.x-R,vE.y,vE.z-R>}
  box {<vS.x+R,vS.y+R,vS.z>,<vE.x-R,vE.y-R,vE.z>}

  #local vS=vS+R;
  #local vE=vE-R;

  sphere { <vS.x,vS.y,vS.z>,R}
  sphere { <vE.x,vS.y,vS.z>,R}
  sphere { <vS.x,vE.y,vS.z>,R}
  sphere { <vE.x,vE.y,vS.z>,R}
  sphere { <vS.x,vS.y,vE.z>,R}
  sphere { <vE.x,vS.y,vE.z>,R}
  sphere { <vS.x,vE.y,vE.z>,R}
  sphere { <vE.x,vE.y,vE.z>,R}

  cylinder { <vS.x,vS.y,vS.z>,<vE.x,vS.y,vS.z>,R }
  cylinder { <vS.x,vE.y,vS.z>,<vE.x,vE.y,vS.z>,R }
  cylinder { <vS.x,vS.y,vE.z>,<vE.x,vS.y,vE.z>,R }
  cylinder { <vS.x,vE.y,vE.z>,<vE.x,vE.y,vE.z>,R }
  cylinder { <vS.x,vS.y,vS.z>,<vS.x,vE.y,vS.z>,R }
  cylinder { <vE.x,vS.y,vS.z>,<vE.x,vE.y,vS.z>,R }
  cylinder { <vS.x,vS.y,vE.z>,<vS.x,vE.y,vE.z>,R }
  cylinder { <vE.x,vS.y,vE.z>,<vE.x,vE.y,vE.z>,R }
  cylinder { <vS.x,vS.y,vS.z>,<vS.x,vS.y,vE.z>,R }
  cylinder { <vE.x,vS.y,vS.z>,<vE.x,vS.y,vE.z>,R }
  cylinder { <vS.x,vE.y,vS.z>,<vS.x,vE.y,vE.z>,R }
  cylinder { <vE.x,vE.y,vS.z>,<vE.x,vE.y,vE.z>,R }
#end

#macro BevelBox(S,E,BW)
  #local vC=(S+E)/2;
  #local vD=<abs(S.x-E.x),abs(S.y-E.y),abs(S.z-E.z)>/2;
  #local xE=(vD.y+vD.z)/2-BW/sqrt(8);
  #local yE=(vD.x+vD.z)/2-BW/sqrt(8);
  #local zE=(vD.x+vD.y)/2-BW/sqrt(8);

  intersection {
    box { -1,1 matrix <vD.x,0,0, 0,xE,xE, 0,-xE,xE, vC.x,vC.y,vC.z> }
    box { -1,1 matrix <yE,0,-yE, 0,vD.y,0, yE,0,yE, vC.x,vC.y,vC.z> }
    box { -1,1 matrix <zE,zE,0, -zE,zE,0, 0,0,vD.z, vC.x,vC.y,vC.z> }
    bounded_by { box { vC-vD,vC+vD } }
  }
#end

#macro BiRoundedBox(Start,End,MajorRadius,MinorRadius)
  #if ((MajorRadius)=(MinorRadius))
    RoundedBox(Start,End,MajorRadius)
  #end
  #if ((MajorRadius)>(MinorRadius))
    #if ((MinorRadius)=0)
      RoundedBar(Start,End,MajorRadius)
    #else
//
#local pSP=Start;
#local pEP=End;

#local vS=<min(vSP.x,vEP.x),min(vSP.y,vEP.y),min(vSP.z,vEP.z)>;
#local vE=<max(vSP.x,vEP.x),max(vSP.y,vEP.y),max(vSP.z,vEP.z)>;

#local rY=abs(MajorRadius);
#local rXZ=abs(MinorRadius);

RoundedBar(pS+<0,rXZ,0>   pE-<0,rXZ,0>,  rY)
RoundedBar(pS+<rXZ,0,rXZ>,pE-<rXZ,0,rXZ>,rY-rXZ)

torus { rY-rXZ,rXZ translate <pS.x+rY,pS.y+rXZ,pS.z+rY> }
torus { rY-rXZ,rXZ translate <pE.x-rY,pS.y+rXZ,pS.z+rY> }
torus { rY-rXZ,rXZ translate <pS.x+rY,pE.y-rXZ,pS.z+rY> }
torus { rY-rXZ,rXZ translate <pE.x-rY,pE.y-rXZ,pS.z+rY> }
torus { rY-rXZ,rXZ translate <pS.x+rY,pS.y+rXZ,pE.z-rY> }
torus { rY-rXZ,rXZ translate <pE.x-rY,pS.y+rXZ,pE.z-rY> }
torus { rY-rXZ,rXZ translate <pS.x+rY,pE.y-rXZ,pE.z-rY> }
torus { rY-rXZ,rXZ translate <pE.x-rY,pE.y-rXZ,pE.z-rY> }

cylinder { <pS.x+rY,pS.y+rXZ,pS.z+rXZ>,<pE.x-rY,pS.y+rXZ,pS.z+rXZ>,rXZ }
cylinder { <pS.x+rY,pE.y-rXZ,pS.z+rXZ>,<pE.x-rY,pE.y-rXZ,pS.z+rXZ>,rXZ }
cylinder { <pS.x+rY,pS.y+rXZ,pE.z-rXZ>,<pE.x-rY,pS.y+rXZ,pE.z-rXZ>,rXZ }
cylinder { <pS.x+rY,pE.y-rXZ,pE.z-rXZ>,<pE.x-rY,pE.y-rXZ,pE.z-rXZ>,rXZ }

cylinder { <pS.x+rXZ,pS.y+rXZ,pS.z+rY>,<pS.x+rXZ,pS.y+rXZ,pE.z-rY>,rXZ }
cylinder { <pE.x-rXZ,pS.y+rXZ,pS.z+rY>,<pE.x-rXZ,pS.y+rXZ,pE.z-rY>,rXZ }
cylinder { <pS.x+rXZ,pE.y-rXZ,pS.z+rY>,<pS.x+rXZ,pE.y-rXZ,pE.z-rY>,rXZ }
cylinder { <pE.x-rXZ,pE.y-rXZ,pS.z+rY>,<pE.x-rXZ,pE.y-rXZ,pE.z-rY>,rXZ }

//    
    #end
  #end
#end

#macro CutSphere(pC,rS,rI,vC)
  #local pS=pC-<rS,rS,rS>;
  #local pE=pC+<rS,rS,rS>;
  #if(vC.x>0) #local pS=<pC.x,pS.y,pS.z>; #end
  #if(vC.y>0) #local pS=<pS.x,pC.y,pS.z>; #end
  #if(vC.z>0) #local pS=<pS.x,pS.y,pC.z>; #end
  #if(vC.x<0) #local pE=<pC.x,pE.y,pE.z>; #end
  #if(vC.y<0) #local pE=<pE.x,pC.y,pE.z>; #end
  #if(vC.z<0) #local pE=<pE.x,pE.y,pC.z>; #end

  intersection { sphere { pC,rS } box { pS,pE }
  #if(rI>0) sphere{ pC,rI inverse } #end
  }
#end

#macro CutCylinder(Start,End,rC,rI,vC)
  #local vA=vnormalize(End-Start);
  #local sX=sqrt(1-vA.x*vA.x)*rC;
  #local sY=sqrt(1-vA.x*vA.x)*rC;
  #local sZ=sqrt(1-vA.x*vA.x)*rC;

  #local pS=<min(End.x-sX,Start.x-sX),min(End.y-sY,Start.y-sY),min(End.z-sZ,Start.z-sZ)>;
  #local pE=<max(End.x+sX,Start.x+sX),max(End.y+sY,Start.y+sY),max(End.z+sZ,Start.z+sZ)>;

  #local pC=(pS+pE)/2;
  #if(vC.x>0) #local pS=<pC.x,pS.y,pS.z>; #end
  #if(vC.y>0) #local pS=<pS.x,pC.y,pS.z>; #end
  #if(vC.z>0) #local pS=<pS.x,pS.y,pC.z>; #end
  #if(vC.x<0) #local pE=<pC.x,pE.y,pE.z>; #end
  #if(vC.y<0) #local pE=<pE.x,pC.y,pE.z>; #end
  #if(vC.z<0) #local pE=<pE.x,pE.y,pC.z>; #end
  intersection {
    cylinder { Start,End,rC }
    box { pS,pE }
    #if(rI>0) cylinder { Start-vA*rC*.1,End+vA*rC*.1,rI inverse } #end
  }
#end

#macro CutTorus(rA,rB,vC,rI)
  #local pS=<-rA-rB,-rB,-rA-rB>;
  #local pE=< rA+rB, rB, rA+rB>;
  #if(vC.x>0) #local pS=<   0,pS.y,pS.z>; #end
  #if(vC.y>0) #local pS=<pS.x,   0,pS.z>; #end
  #if(vC.z>0) #local pS=<pS.x,pS.y,   0>; #end
  #if(vC.x<0) #local pE=<   0,pE.y,pE.z>; #end
  #if(vC.y<0) #local pE=<pE.x,   0,pE.z>; #end
  #if(vC.z<0) #local pE=<pE.x,pE.y,   0>; #end
  intersection {
    torus { rA,rB }
    box { pS,pE }
    #if(rI>0) torus { rA,rI inverse } #end
    bounded_by { box { pS,pE } }
  }

#end

#macro RoundedCylinder(Start,End,MajorRadius,MinorRadius)
  #local pS=<0,0,0>+Start;
  #local pE=<0,0,0>+End;
  #local sJ=MajorRadius;
  #local sN=MinorRadius;
  #local vY=vnormalize(pE-pS);
  #local vX=vnormalize(vcross(<vY.y,vY.z,-vY.x>,vY));
  #local vZ=vnormalize(vcross(vX,vY));
  
  cylinder { pS,pE,sJ-sN }
  cylinder { pS+vY*sN,pE-vY*sN,sJ }
  torus { sJ-sN,sN translate  y*sN Matrix(vX,vY,vZ,pS) }
  torus { sJ-sN,sN translate -y*sN Matrix(vX,vY,vZ,pE) }
#end

#macro CylinderSpan(Start1,End1,Start2,End2,Radius)
  #local vX=vnormalize(Start2-Start1);
  #local vZ=vnormalize(End1-Start1);
  #local vY=vnormalize(vcross(vZ,vX))*Radius;
  #local vZ=vnormalize(vcross(vX,vY));
  prism { -1,1,5,
    <0,0>,
    <vlength(Start2-Start1),0>,
    <vdot(End2-Start1,vX),vdot(End2-Start1,vZ)>,
    <vdot(End1-Start1,vX),vdot(End1-Start1,vZ)>,
    <0,0>
    Matrix(vX,vY,vZ,Start1)
  }
#end

#declare FlipXY=transform { matrix <0,1,0, 1,0,0, 0,0,1, 0,0,0> }
#declare FlipXZ=transform { matrix <0,0,1, 0,1,0, 1,0,0, 0,0,0> }
#declare FlipYZ=transform { matrix <1,0,0, 0,0,1, 0,1,0, 0,0,0> }

#macro AxisRotate(Axis,Angle)
  #local vX=vnormalize(Axis);
  #local vY=vnormalize(vcross(vX,<vX.y,vX.z,-vX.x>));
  #local vZ=vnormalize(vcross(vX,vY));
  matrix < vX.x,vY.x,vZ.x, vX.y,vY.y,vZ.y, vX.z,vY.z,vZ.z, 0,0,0 >
  rotate x*(Angle)
  matrix < vX.x,vX.y,vX.z, vY.x,vY.y,vY.z, vZ.x,vZ.y,vZ.z, 0,0,0 >
#end

#macro Reorient(Axis1,Axis2)
  #local vX1=vnormalize(Axis1);
  #local vX2=vnormalize(Axis2);
  #local vY=vnormalize(vcross(vX1,vX2));
#if (vlength(vY)>0)
  #local vZ1=vnormalize(vcross(vX1,vY));
  #local vZ2=vnormalize(vcross(vX2,vY));
  matrix < vX1.x, vY.x,vZ1.x, vX1.y,vY.y,vZ1.y, vX1.z,vY.z, vZ1.z, 0,0,0 >
  matrix < vX2.x,vX2.y,vX2.z, vY.x,vY.y, vY.z, vZ2.x,vZ2.y,vZ2.z, 0,0,0 >
#end
#end

#macro Point(Current,Desired,Up)
  #local vZC=vnormalize(Current+<0,0,0>);
  #local vZD=vnormalize(Desired+<0,0,0>);
  #local vUp=vnormalize(Up+<0,0,0>);

  #local vXC=vnormalize(vcross(vUp,vZC));
  #local vXD=vnormalize(vcross(vUp,vZD));
  #local vYC=vnormalize(vcross(vZC,vXC));
  #local vYD=vnormalize(vcross(vZD,vXD));
// remove C
  matrix < vXC.x,vYC.x,vZC.x, vXC.y,vYC.y,vZC.y, vXC.z,vYC.z,vZC.z, 0,0,0>
  matrix < vXD.x,vXD.y,vXD.z, vYD.x,vYD.y,vYD.z, vZD.x,vZD.y,vZD.z, 0,0,0>
#end  

#macro Transition(Start,End,Swerve,Phase)
  #local tP=min(1,max(0,Phase))*pi;
  #local aL=(1-cos(tP))/2;
  #local aS=(1-cos(tP*2))/2;
  ( (Start)+(End-Start)*aL + (Swerve)*aS )
#end

#macro Linear(Start,End,Phase)
  ((End-Start)*min(max(0,Phase),1)+Start)
#end  

#macro SmoothSeed(Array,Freq)
  #declare Array[0]= Freq;
  #declare Array[1]= seed(floor(clock*(Freq)));
  #declare Array[2]= seed(floor(clock*(Freq)+1));
  #declare Array[3]= seed(floor(clock*(Freq)+2));
#end

#macro SmoothRand(Array)
  #local t_T=clock*Array[0]-floor(clock*Array[0]);
  ( rand(Array[1])*(t_T-1)*(t_T-1)*.5
  + rand(Array[2])*(.5+t_T-t_T*t_T)
  + rand(Array[3])*t_T*t_T*.5 )
#end

#macro SmoothVec(Array)
  <SmoothRand(Array),SmoothRand(Array),SmoothRand(Array)>
#end  

#macro vmatrix(op,vx,vy,vz,vl)
  (op.x*vx+op.y*vy+op.z*vz+vl)
#end

#macro Stretch(Vector,amount)
  #local v_X=vnormalize(Vector);
  #local s_A=(amount)-1;
  matrix <
    s_A*v_X.x*v_X.x+1,s_A*v_X.x*v_X.y,  s_A*v_X.x*v_X.z,
    s_A*v_X.y*v_X.x,  s_A*v_X.y*v_X.y+1,s_A*v_X.y*v_X.z,
    s_A*v_X.z*v_X.x,  s_A*v_X.z*v_X.y,  s_A*v_X.z*v_X.z+1,
    0,0,0>
#end

#macro FindKnee(pA,pH,lT,lS,vD)
  #local lB=vlength(pA-(pH));
#if( (lB>lT+lS) | (lT>lB+lS) | (lS>lT+lB) )
#error "Invalid span lengths.\n"
#end
  #local tX=(lT*lT-lS*lS+lB*lB)/2/lB;
  #local tY=sqrt(lT*lT-tX*tX);
  #local vO=vnormalize(pA-(pH));
  #local vF=vnormalize(vcross(vD,vO));
  #local vU=vnormalize(vcross(vO,vF));
  (pH+vO*tX+vU*tY)
#end

#macro sgn(ARG)
  ( (ARG) = 0 ? 0 : ( (ARG) < 0 ? -1 : 1) ) 
#end

#macro GentleLoc(dTotal,tTotal,tHack)
#local dT=abs(dTotal);
#local tT=abs(tTotal);
#local aM=-dT*840;
#local tP=min(max(tHack/tT,0),1);
#local tP2=tP*tP;
#local tP4=tP2*tP2;
// dT = total distance
// tT = total time
// aM = maximum acceleration
// tP = time hack
  (((tP/42 - 1/12)*tP2 + tP/10 - 1/24)*tP4*aM)
#end

#macro GentleVel(dTotal,tTotal,tHack)
#local dT=abs(dTotal);
#local tT=abs(tTotal);
#local aM=-dT*840;
#local tP=min(max(tHack/tT,0),1);
// dT = total distance
// tT = total time
// aM = maximum acceleration
// tP = time hack
#local tPD=tP*tP-tP;
  (tPD*tPD*tPD*aM/6/tT)
#end

#macro GentleAcc(dTotal,tTotal,tHack)
#local dT=abs(dTotal);
#local tT=abs(tTotal);
#local aM=-dT*840;
#local tP=min(max(tHack/tT,0),1);
// dT = total distance
// tT = total time
// aM = maximum acceleration
// tP = time hack
  (tP*tP*(tP-1/2)*(tP-1)*(tP-1)*aM/tT/tT)
#end

#macro SeeBit(Field,Bit)
  #local tF=floor(Field/Bit);
  (tF-2*floor(tF/2))
#end
  