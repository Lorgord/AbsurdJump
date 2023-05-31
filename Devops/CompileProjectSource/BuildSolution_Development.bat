@echo off

call "%~dp0..\Config.bat"



:begin
call "%RunBuildPath%" "%ProjectPureName%"Editor "%Platform%" Development "%ProjectPath%" -waitmutex


pause


goto:EOF