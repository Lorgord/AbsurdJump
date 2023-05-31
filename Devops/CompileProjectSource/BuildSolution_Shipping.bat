@echo off

call "%~dp0..\Config.bat"



:begin
call "%RunBuildPath%" "%ProjectPureName%" "%Platform%" Shipping "%ProjectPath%" -waitmutex


pause


goto:EOF