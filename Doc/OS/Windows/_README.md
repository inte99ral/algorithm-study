# 윈도우

## 윈도우 터미널 단축키 설정

- 시작에서 powershell or cmd 중 선호하는 터미널 검색
- 우클릭 "파일 위치 열기"
- 해당 파일에 우클릭->추가옵션표시->바로가기 파일을 두 개를 만들어줍니다.
- 첫번째 바로가기 파일에<br/>`-⇀`우클릭 속성 `-⇀` 바로가기 키를 클릭하고 단축키 Crtl + Alt + T 를 입력합니다.
- 두번째 바로가기 파일에<br/>`-⇀`우클릭 속성 `-⇀` 바로가기 키를 클릭하고 단축키 Crtl + Alt + Shift + T 를 입력합니다.<br/>`-⇀`우클릭 속성 `-⇀` 고급에 관리자 권한으로 실행 체크합니다.
- 파워쉘이 켜지면 우클릭 `-⇀` 속성의 편집옵션 항목에서 Ctrl+Shift+C/V 복사 붙여넣기 항목에 체크해주면 복사 붙여넣기를 쉽게 할 수 있습니다.

## 윈도우 무결성 확인

- 관리자 권한으로 터미널창을 띄워 SFC(System File Checker)의 도움을 받으면 됩니다.
- ```bash
  sfc /scannow
  ```

## 기본 형식

```bat
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
```

## COLOR

[참고링크](https://velog.io/@joonpark/Makefile-%EA%BE%B8%EB%AF%B8%EA%B8%B0)

```bat
echo "Default!!"
@echo "\033[31m"
echo "\033[31mRed!!"
@echo "\033[32m"
echo "\033[32mGreen!!"
```

- 배우는 중 https://skdjjdje.tistory.com/3

- bat -> exe 변환 코드 https://sysdocu.tistory.com/1502

- 쉘 스크립트 [참고링크](https://codingdog.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%89%98-%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EC%99%80-%EC%97%90-%EB%8C%80%ED%95%B4-%EC%95%8C%EC%95%84%EB%B4%85%EC%8B%9C%EB%8B%A4)
- find -> dir /b | findstr /i "^[0-9][0-9]\*\.pdf$" [참고링크](https://stackoverflow.com/questions/1183659/windows-advanced-file-matching)
