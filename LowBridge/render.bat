@echo off
camera 180 30 -80 0 15 0
call pov2a main 800 600
copy main.tga main1.tga
camera 180 25 -10 -220 24 0
call pov2a main 800 600
copy main.tga main2.tga
camera 180 30 -80 0 15 0
call pov2a main 800 600
copy main.tga main3.tga
