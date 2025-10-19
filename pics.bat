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

exit /b


