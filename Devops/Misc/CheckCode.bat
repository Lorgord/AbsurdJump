@echo off

call "%~dp0..\Config.bat"




:begin
start /WAIT /B "" "%CppCheckDir%\cppcheck.exe" --enable=all --suppress=*:*.gen.cpp "%SourceCodePath%" 2> cppcheck.log
start /WAIT /B "" "%CppCheckDir%\cppcheck.exe" --enable=all --suppress=*:*.gen.cpp "%PluginsPath%" 2>> cppcheck.log
pause



goto:EOF