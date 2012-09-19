@echo off
rotate 0.0
mphase 0.000000
c:\povray3\povray +Ilattice.pov +oframe100.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 7.5
mphase 0.083333
c:\povray3\povray +Ilattice.pov +oframe101.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 15.0
mphase 0.166667
c:\povray3\povray +Ilattice.pov +oframe102.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 22.5
mphase 0.250000
c:\povray3\povray +Ilattice.pov +oframe103.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 30.0
mphase 0.333333
c:\povray3\povray +Ilattice.pov +oframe104.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 37.5
mphase 0.416667
c:\povray3\povray +Ilattice.pov +oframe105.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 45.0
mphase 0.500000
c:\povray3\povray +Ilattice.pov +oframe106.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 52.5
mphase 0.583333
c:\povray3\povray +Ilattice.pov +oframe107.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 60.0
mphase 0.666667
c:\povray3\povray +Ilattice.pov +oframe108.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 67.5
mphase 0.750000
c:\povray3\povray +Ilattice.pov +oframe109.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 75.0
mphase 0.833333
c:\povray3\povray +Ilattice.pov +oframe110.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
rotate 82.5
mphase 0.916667
c:\povray3\povray +Ilattice.pov +oframe111.tga +FT +v -p +W240 +H180 +q11 +r9 +a0.300 +j1.000
c:\alchemy\alchemy frame105.tga -o -8 -w palette.bmp
c:\alchemy\alchemy frame100.tga -f palette.bmp -o -8 -w frame100.bmp
c:\alchemy\alchemy frame101.tga -f palette.bmp -o -8 -w frame101.bmp
c:\alchemy\alchemy frame102.tga -f palette.bmp -o -8 -w frame102.bmp
c:\alchemy\alchemy frame103.tga -f palette.bmp -o -8 -w frame103.bmp
c:\alchemy\alchemy frame104.tga -f palette.bmp -o -8 -w frame104.bmp
c:\alchemy\alchemy frame105.tga -f palette.bmp -o -8 -w frame105.bmp
c:\alchemy\alchemy frame106.tga -f palette.bmp -o -8 -w frame106.bmp
c:\alchemy\alchemy frame107.tga -f palette.bmp -o -8 -w frame107.bmp
c:\alchemy\alchemy frame108.tga -f palette.bmp -o -8 -w frame108.bmp
c:\alchemy\alchemy frame109.tga -f palette.bmp -o -8 -w frame109.bmp
c:\alchemy\alchemy frame110.tga -f palette.bmp -o -8 -w frame110.bmp
c:\alchemy\alchemy frame111.tga -f palette.bmp -o -8 -w frame111.bmp
