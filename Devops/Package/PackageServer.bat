@echo off

call "%~dp0..\Config.bat"




:begin
call "%RunUATPath%" BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-serverconfig="%Configuration%" ^
-archivedirectory="%ArchivePath%" ^
-build -cook -CookMapsOnly -package -stage -archive -pak -allmaps -server -noclient





goto:EOF