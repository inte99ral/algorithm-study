@REM @ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

@REM (FOR /F "usebackq" %%i IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO CALL SET var=%%var%% %%i) && CALL g++ data=%%var%%


@REM (FOR /F "usebackq" %%i IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO CALL SET var=%%var%% %%i) && CALL g++ -v

(FOR /F "usebackq" %%i IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.cpp"`) DO CALL SET var=%%var%% %%i) && CALL g++ %%var%% -o %~dp0/Main.exe


PAUSE>NUL
EXIT

:: 테스트 1 : 
dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b | findstr /e "\.cpp"




SET var=1 && ECHO %var%

FOR /L %i IN (1, 1, 5) DO ECHO %i 

CALL ECHO DANCE

FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @CALL ECHO %i


(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO CALL SET list=%list% %i)


E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST


@REM FOR /F "usebackq delims=" %%i IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO (
@REM   CALL SET var=%%var%% %%i
@REM )
@REM SET var=%var:~1%
@REM ECHO var02=%var%

@REM for /f "usebackq delims=" %%i in ("list.txt") do set /p=%%i 


@REM for /f "usebackqdelims=" %%i in ("infile.txt") do @<nul set /p"=%%i ">>"outfile.txt"
@REM >>"outfile.txt" echo.
