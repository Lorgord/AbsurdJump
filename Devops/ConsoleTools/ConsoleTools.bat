@echo off
call %*
goto :EOF


::.......................................................ProgressBar.....................................................................::

:InitProgressBar [FillChar] [DotChar]
    if defined pb.cr call :FinalizeProgressBar
    for /f %%a in ('copy "%~f0" nul /z') do set "pb.cr=%%a"
    if "%~1"=="" ( set "pb.FillChar=#" ) else ( set "pb.FillChar=%~1" )
    if "%~2"=="" ( set "pb.DotChar=." ) else ( set "pb.DotChar=%~2" )
    set "pb.console.columns="
    for /f "tokens=2 skip=4" %%f in ('mode con') do if not defined pb.console.columns set "pb.console.columns=%%f"
    set /a "pb.barArea=pb.console.columns/2-2", "pb.textArea=pb.barArea-9"
    set "pb.fill="
    setlocal EnableExtensions EnableDelayedExpansion
    for /l %%p in (1 1 %pb.barArea%) do set "pb.fill=!pb.fill!%pb.FillChar%"
    set "pb.fill=!pb.fill:~0,%pb.barArea%!"
    set "pb.dots=!pb.fill:%pb.FillChar%=%pb.DotChar%!"
    set "pb.back=!pb.fill:~0,%pb.textArea%!
    set "pb.back=!pb.back:%pb.FillChar%= !"
    endlocal & set "pb.fill=%pb.fill%" & set "pb.dots=%pb.dots%" & set "pb.back=%pb.back%"
    goto :eof

:DrawProgressBar Value [Text]
    if "%~1"=="" goto :eof
    if not defined pb.barArea call :InitProgressBar
    setlocal EnableExtensions EnableDelayedExpansion
    set /a "pb.Value=%~1 %% 101", "pb.filled=pb.Value*pb.barArea/100", "pb.dotted=pb.barArea-pb.filled", "pb.pct=1000+pb.Value"
    set "pb.pct=%pb.pct:~-3%"
    if "%~2"=="" ( set "pb.Text=" ) else ( 
        set "pb.Text=%~2%pb.back%" 
        set "pb.Text=!pb.Text:~0,%pb.textArea%!"
    )
    <nul set /p "pb.prompt=[!pb.fill:~0,%pb.filled%!!pb.dots:~0,%pb.dotted%!][ %pb.pct% ] %pb.Text%!pb.cr!"
    endlocal
    goto :eof

:FinalizeProgressBar [Erase]
    if defined pb.cr (
        if not "%~1"=="" (
            setlocal EnableDelayedExpansion
            set "pb.back="
            for /l %%p in (1 1 %pb.console.columns%) do set "pb.back=!pb.back! "
            <nul set /p "pb.prompt=!pb.cr!!pb.back:~1!!pb.cr!"
            endlocal
        )
    )
    for /f "tokens=1 delims==" %%v in ('set pb.') do set "%%v="
    goto :eof
	
::.......................................................................................................................................::



::..........................................................Files........................................................................::

:CountSubfolders
	set FolderPath=%~1
	
	set /A SubfoldersCount=0
	for /d %%i in ("%FolderPath%\*") do (
		set /A SubfoldersCount=SubfoldersCount+1
	)

::.......................................................................................................................................::



