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

exit /b


