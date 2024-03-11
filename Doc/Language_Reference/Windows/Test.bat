:: Hello, world! 출력 예제
:: Echo off 옵션 시, 내가 입력한 값은 보여주지 않고 출력값만 보여준다.
@Echo off

:: Echo 명령어는 뒷 줄의 문장을 출력한다.
Echo Hello,

:: 한 줄을 Echo. 입력으로 띄울 수 있다.
Echo.
Echo world!

:: 다른 입력이 있을 때까지 정지. >nul 명령어가 붙으면 "계속하려면 아무 키나 누르십시오..." 출력 조차 하지 않고 정지한다.
pause>nul