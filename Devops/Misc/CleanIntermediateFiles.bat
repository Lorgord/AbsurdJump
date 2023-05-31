@echo off

call "%~dp0..\Config.bat"
Setlocal EnableDelayedExpansion




:begin
call :CountSubfolders "%PluginsPath%"
set /A TotalOperations=%TotalRemoveOperations%+%SubfoldersCount%
set /A Index=0


call :InitProgressBar "." " "
call :DrawProgressBar Index ""

rem Clean plugins intermediate
for /d %%i in ("%PluginsPath%\*") do (
	
	if exist "%%i\Intermediate" (
		rmdir /s /q "%%i\Intermediate"
	)
	
	set /A Index=!Index!+1
	call :DrawProgressBar !Index!*100/%TotalOperations% ""
)
rem Clean project intermediate folders
for %%f in (%DirsToRemove%) do (
	
	if exist "%ProjectRoot%\%%f" (
		rmdir /s /q "%ProjectRoot%\%%f"
	)
	
	set /A Index=!Index!+1
	call :DrawProgressBar !Index!*100/%TotalOperations% ""
)
rem Clean project intermediate files
pushd "%ProjectRoot%"
for %%f in (%FilesToRemove%) do (
	
	del /q "%%f"
	
	set /A Index=!Index!+1
	call :DrawProgressBar !Index!*100/%TotalOperations% ""
)
popd

call :DrawProgressBar 100 ""
call :FinalizeProgressBar
echo:




endlocal
goto :EOF

:DrawProgressBar Value [Text]
:InitProgressBar [FillChar] [DotChar]
:FinalizeProgressBar [Erase]

:CountSubfolders
%~dp0\..\ConsoleTools\ConsoleTools.bat %*



