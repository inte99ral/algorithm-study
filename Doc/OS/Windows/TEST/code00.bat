@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

@REM dir C:\Users\dkdld\Desktop\test0 /a-d /s /b | findstr /e "\.txt"


@REM FOR /F "usebackq delims=" %%a IN (`dir C:\Users\dkdld\Desktop\test0 /a-d /s /b ^| findstr /e "\.txt"`) DO (
@REM   ECHO TEST = %%a
@REM )

FOR /F "usebackq" %%a IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO (
  ECHO TEST = %%a
)

PAUSE>NUL
EXIT