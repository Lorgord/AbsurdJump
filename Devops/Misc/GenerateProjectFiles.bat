@echo off

call "%~dp0..\Config.bat"




:begin
start /WAIT /B "" "%VersionSelector%" -switchversionsilent "%ProjectPath%" "%EnginePath%"
start /WAIT /B "" "%UBTPath%" -projectfiles -progress -project="%ProjectPath%" 





goto:EOF