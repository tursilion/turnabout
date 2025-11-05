cd pics9918
call :runpics
cd ..\picsf18a
call :runpics
cd ..
goto :EOF

@rem process each pic
:runpics

..\PCPort\Debug\chopbmp.exe 0 bottom
..\PCPort\Debug\chopbmp.exe 1 bottom
..\PCPort\Debug\chopbmp.exe 2 top
..\PCPort\Debug\chopbmp.exe 3 top
..\PCPort\Debug\chopbmp.exe 4 top
..\PCPort\Debug\chopbmp.exe 5 top
..\PCPort\Debug\chopbmp.exe 6 top
..\PCPort\Debug\chopbmp.exe 7 top
..\PCPort\Debug\chopbmp.exe 8 top
..\PCPort\Debug\chopbmp.exe 9 top
..\PCPort\Debug\chopbmp.exe 10 top
..\PCPort\Debug\chopbmp.exe 11 top
..\PCPort\Debug\chopbmp.exe 12 top
..\PCPort\Debug\chopbmp.exe 13 top
..\PCPort\Debug\chopbmp.exe 14 top
..\PCPort\Debug\chopbmp.exe 15 top
..\PCPort\Debug\chopbmp.exe 16 top

..\PCPort\Debug\chopbmp.exe 17 top
..\PCPort\Debug\chopbmp.exe 18 top
..\PCPort\Debug\chopbmp.exe 19 top
..\PCPort\Debug\chopbmp.exe 20 top
..\PCPort\Debug\chopbmp.exe 21 top
..\PCPort\Debug\chopbmp.exe 22 top
..\PCPort\Debug\chopbmp.exe 23 top
..\PCPort\Debug\chopbmp.exe 24 top
..\PCPort\Debug\chopbmp.exe 25 top
..\PCPort\Debug\chopbmp.exe 26 top
..\PCPort\Debug\chopbmp.exe 27 top
..\PCPort\Debug\chopbmp.exe 28 top
..\PCPort\Debug\chopbmp.exe 29 top
..\PCPort\Debug\chopbmp.exe 30 top
..\PCPort\Debug\chopbmp.exe 31 top
..\PCPort\Debug\chopbmp.exe 32 top
..\PCPort\Debug\chopbmp.exe 33 top

exit /b


