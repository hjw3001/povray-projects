@echo off
REM   This batch file is used to generate all the necessary include files. This
REM   will save space when distributing the files.
genwin window1.inc Main_Windows 88 830
genwin window2.inc Main_Windows_2 50 830
genwin window3.inc Top_Window_1 100 160
genwin window4.inc Top_Window_2 60 150
genwin window5.inc Bot_Window_1 70 300
genwin window6.inc Bot_Window_2 50 320
genwin window7.inc Bot_Window_3 120 320
genwin window8.inc Bot_Window_4 70 320
genwin window9.inc Mid_Window_1 80 100
genwin window10.inc Top_Window_3 50 70
genwin window11.inc Bot_Window_5 70 210
genwin window12.inc Bot_Window_6 120 300
genwin window13.inc Bot_Window_7 55 120
genwin window14.inc Bot_Window_8 72 240
genwin window15.inc Main_Window_1 60 180
detail detail1.inc Bot_Detail_1 100 299 100
detail detail2.inc Main_Detail_1 30 225 120
detail detail3.inc Main_Detail_2 10 55 70
glgtower 9
genstays
