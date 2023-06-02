@echo off




rem ------------------------------------General params-------------------------------------- rem

set EngineVersion=5.1
set ProjectPureName=AbsurdJump
set Platform=Win64

rem ---------------------------------------------------------------------------------------- rem





rem ------------------------------------System params--------------------------------------- rem

set ClangFormatDir=%~dp0ThirdParty\ClangFormat
set CppCheckDir=%~dp0ThirdParty\CppCheck
set VersionSelector=%~dp0ThirdParty\UEVersionSelector\UnrealVersionSelector.exe

rem ---------------------------------------------------------------------------------------- rem



rem ------------------------------------Engine params--------------------------------------- rem

set SemanticEngineName=UE_%EngineVersion%


rem find EnginePath
powershell -command "& { (Get-ItemProperty 'Registry::HKEY_LOCAL_MACHINE\SOFTWARE\EpicGames\Unreal Engine\%EngineVersion%' -Name 'InstalledDirectory' ).'InstalledDirectory' }" > gen_temp.txt
set /p EnginePath=<gen_temp.txt
del /q gen_temp.txt

rem determine UBTRelativePath
if %EngineVersion% GEQ 5.1 (
	set UBTRelativePath=Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe
)
if %EngineVersion% LSS 5.1 if %EngineVersion% GEQ 4.0 (
	set UBTRelativePath=Engine\Binaries\DotNET\UnrealBuildTool.exe
)
set UBTPath=%EnginePath%\%UBTRelativePath%


set RunUATPath=%EnginePath%\Engine\Build\BatchFiles\RunUAT.bat
set RunBuildPath=%EnginePath%\Engine\Build\BatchFiles\Build.bat

rem ---------------------------------------------------------------------------------------- rem



rem --------------------------------Project params------------------------------------------ rem

set ProjectRoot=%~dp0..
set ProjectName=%ProjectPureName%.uproject
set VSProjectName=%ProjectPureName%.sln

set ProjectPath=%ProjectRoot%\%ProjectName%
set VSProjectPath=%ProjectRoot%\%VSProjectName%

set SourceCodePath=%ProjectRoot%\Source
set CppCodePath=%SourceCodePath%\%ProjectPureName%\Private
set HCodePath=%SourceCodePath%\%ProjectPureName%\Public
set ShadersSourceCodePath=%SourceCodePath%\Shaders
set PluginsPath=%ProjectRoot%\Plugins


set DirsToRemove=Intermediate DerivedDataCache Saved Binaries .vs Build Script
set FilesToRemove=*.sln
set /A TotalRemoveOperations=8

rem ---------------------------------------------------------------------------------------- rem



rem --------------------------------Build params-------------------------------------------- rem

set Configuration=Shipping
set ArchivePath=%ProjectRoot%\Build

set ServerExePath=%ArchivePath%\WindowsServer\%ProjectPureName%Server.exe
set ClientExePath=%ArchivePath%\WindowsClient\%ProjectPureName%Client.exe
set GameExePath=%ArchivePath%\WindowsNoEditor\%ProjectPureName%.exe

rem ---------------------------------------------------------------------------------------- rem


