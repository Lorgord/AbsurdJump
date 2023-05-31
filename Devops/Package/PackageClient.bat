@echo off

call "%~dp0..\Config.bat"




:begin
call "%RunUATPath%" BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-clientconfig="%Configuration%" ^
-archivedirectory="%ArchivePath%" ^
-build -cook -CookMapsOnly -package -stage -archive -pak -allmaps -client





goto:EOF