# _ETC_：윈도우 기타 항목

## OneDrive 연결 해제

### OneDrive 단순 백업 해제

-   시작 메뉴에서 검색창에 OneDrive 검색 후 선택
-   탐색기 창으로 팝업되는 OneDrive 폴더에 상단 경로 쪽에 OneDrive 클릭
-   OneDrive 메뉴 설정(톱니바퀴 모양) 클릭
-   `우측 탭 동기화 및 백업 > 백업 관리` 에서 모든 파일 해제
-   `우측 탭 계정 > 폴더 선택` 에서 백업할 폴더만 선택

### OneDrive 경로 레지스트리 편집

&nbsp; 바탕화면, 유저, 사진 폴더가 OneDrive 폴더로 연결되는 경로를 수정합니다.

-   `Win + R` 을 눌러 실행 창을 열고, regedit를 입력하여 레지스트리 편집기를 실행합니다.
-   `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders` 로 이동합니다.
-   `Desktop`, `Personal`, `My Pictures` 항목을 찾아 값 데이터를 각각

    -   `%USERPROFILE%\Desktop`
    -   `%USERPROFILE%\Documents`
    -   `%USERPROFILE%\Pictures`

    로 수정합니다.

### OneDrive 자동 실행 방지

&nbsp; OneDrive가 자동으로 실행되지 않도록 설정하여 불필요한 동기화를 방지할 수 있습니다.

-   `Ctrl + Shift + del` 를 눌러 작업 관리자를 엽니다.
-   상단의 `시작 프로그램` 탭을 클릭합니다.
-   목록에서 **'Microsoft OneDrive'**를 찾아 우클릭한 후, **'사용 안 함'**을 선택합니다.

## 속도 및 보안성 개선

-   `설정 > 네트워크 및 인터넷 > 프록시` 에서 `자동으로 설정 검색` 끄기
-   `설정 > 개인 설정 > 시작` 에서 `팁, 바로가기, 새 앱 등에 대한 권장 사항 표시` 끄기
-   `설정 > 개인 정보 및 보안 > 일반` 에서
    -   `내 광고 ID를 사용하여 앱에서 개인 설정된 광고를 표시하도록 허용` 끄기
    -   `Windows에서 앱 시작을 추적해서 시작 및 검색 결과를 개선할 수 있게 해 주세요.` 끄기 (대신 명령어 목록 같은 것이 남지 않게되서 불편할 수는 있습니다)
    -   `앱 설정 시 제안되는 내용 표시` 끄기

## 윈도우 터미널 단축키 설정

-   시작에서 powershell or cmd 중 선호하는 터미널 검색
-   우클릭 "파일 위치 열기"
-   해당 파일에 우클릭->추가옵션표시->바로가기 파일을 두 개를 만들어줍니다.
-   첫번째 바로가기 파일에<br/>`-⇀`우클릭 속성 `-⇀` 바로가기 키를 클릭하고 단축키 Crtl + Alt + T 를 입력합니다.
-   두번째 바로가기 파일에<br/>`-⇀`우클릭 속성 `-⇀` 바로가기 키를 클릭하고 단축키 Crtl + Alt + Shift + T 를 입력합니다.<br/>`-⇀`우클릭 속성 `-⇀` 고급에 관리자 권한으로 실행 체크합니다.
-   파워쉘이 켜지면 우클릭 `-⇀` 속성의 편집옵션 항목에서 Ctrl+Shift+C/V 복사 붙여넣기 항목에 체크해주면 복사 붙여넣기를 쉽게 할 수 있습니다.

## 윈도우 무결성 확인

-   관리자 권한으로 터미널창을 띄워 SFC(System File Checker)의 도움을 받으면 됩니다.
-   ```bash
    sfc /scannow
    ```

## 임시 데이터 정리

-   `Win + R` 입력으로 실행창 키고
    -   `temp` 입력, 임시폴더 정리
    -   `%temp%` 입력, 임시폴더 정리
    -   `wsreset.exe` 입력 마이크로소프트 캐시 정리

## 프린터 대기열 걸림 문제 해결

-   [printspool 재구성](https://support.hp.com/kr-ko/document/c04746618)
