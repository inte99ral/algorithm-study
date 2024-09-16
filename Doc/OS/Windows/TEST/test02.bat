@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

@REM FOR /F "usebackq delims=" %%i IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO (
@REM   CALL SET var=%%var%% %%i
@REM )
@REM SET var=%var:~1%
@REM ECHO var02=%var%

for /f "usebackq delims=" %%i in ("list.txt") do set /p=%%i 

PAUSE>NUL
EXIT

@REM for /f "usebackqdelims=" %%i in ("infile.txt") do @<nul set /p"=%%i ">>"outfile.txt"
@REM >>"outfile.txt" echo.
