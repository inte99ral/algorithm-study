@REM @ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

PAUSE>NUL
EXIT

:: ==============================

:: 테스트 1 : 
dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b | findstr /e "\.cpp"

:: 걍 재기동 생각안함, 선언 되어있지 않았다면 delay 같은 일이 벌어짐
(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @CALL SET cpps=%cpps% %i) & ECHO %cpps:~7% 

:: 파일에 넣고 저장
(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @<NUL SET /P="%i ">>Main.txt)

:: 왠지 안됨
(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @<NUL SET /P="%i ">>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt) & ECHO. & SET /P var=<E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt & @CALL ECHO %var% & DEL /Q E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt 

:: 잘됨 단순히 출력
(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @<NUL SET /P="%i ">>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt) & SET /P var=<E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt & @CALL ECHO %var% & DEL /Q E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt 

:: gcc 빌드 시도
(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @<NUL SET /P="%i ">>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt) & SET /P var=<E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt & CALL g++ %var%-o E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.exe & DEL /Q E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt 

:: 대 성 공
(FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @<NUL SET /P="%i ">>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt) & SET /P var=<E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt & CALL g++ %var%-o E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.exe & DEL /Q E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt 

CALL gcc %var%-o E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.exe 

ECHO [TESTCODE]>>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt

@<NUL SET /P="TEST_CODE ">>E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt

SET /P var=<E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt
ECHO %var%
:: 삭제
DEL /Q E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST\Main.txt

:: 되는것 확인

SET af=-v & call gcc %af%



SET var=1 && ECHO %var%


CALL ECHO DANCE

FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @CALL ECHO %i

SET a=1 && ECHO %a%
SET a=1 && CALL ECHO %a%


* 딜레이 문제
* setlocal은 배치파일에서만 기동
SET cpps="❤️" && (FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @CALL SET cpps=%cpps% %i) & ECHO %cpps:~7% 



SET cpps="-"
SET cpps="❤️" && (FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @SET /P"=%%i" >> Main.txt)
ECHO %cpps%

SET cpps="❤️" && (FOR /F "usebackq" %i IN (`dir "E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST" /a-d /s /b ^| findstr /e "\.cpp"`) DO @CALL SET cpps=%cpps% %i) && @CALL ECHO TT=%cpps:~1%


E:\StudySpace\Coding\Algorithm_Study\Doc\OS\Windows\TEST


@REM FOR /F "usebackq delims=" %%i IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO (
@REM   CALL SET var=%%var%% %%i
@REM )
@REM SET var=%var:~1%
@REM ECHO var02=%var%

@REM for /f "usebackq delims=" %%i in ("list.txt") do set /p=%%i 


@REM for /f "usebackqdelims=" %%i in ("infile.txt") do @<nul set /p"=%%i ">>"outfile.txt"
@REM >>"outfile.txt" echo.
