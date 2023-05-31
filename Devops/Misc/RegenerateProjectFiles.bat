@echo off

call Devops\Config.bat



:begin
echo Deleting intermediate files.
call Devops\Misc\CleanIntermediateFiles.bat
echo All intermediate files have been deleted.
echo:

echo Generating project files.
call Devops\Misc\GenerateProjectFiles.bat
echo All project files have been generated.
echo:

pause

goto:EOF