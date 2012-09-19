@echo off
rotate 300
mphase 0.833333
c:\povray3\povray +Ilattice.pov +oframe110.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000 +b500
c:\alchemy\alchemy frame110.tga -f palette.bmp -o -8 -w frame110.bmp
