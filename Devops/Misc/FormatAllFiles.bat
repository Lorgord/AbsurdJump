@echo off

call "%~dp0..\Config.bat"


rem Format all files in this project. It will not format plugins because it could be ThirdParty or premade with fixed style and code.

:begin
for /R "%SourceCodePath%" %%f in (*.cpp, *.h, *.cs) do (
    start /WAIT /B "" "%ClangFormatDir%\clang-format.exe" -i "%%f"
    echo %%f
)

pause





goto:EOF