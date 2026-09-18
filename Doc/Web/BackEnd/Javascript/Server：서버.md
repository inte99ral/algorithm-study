# Server：서버

## 목차

-   [Server：서버](#server서버)
    -   [목차](#목차)
    -   [HTTP IP 주소로 연결](#http-ip-주소로-연결)
        -   [서버 적용](#서버-적용)
            -   [서버 적용 : 개요](#서버-적용--개요)
            -   [서버 적용 : 세부 설명](#서버-적용--세부-설명)
            -   [Express 구동](#express-구동)
                -   [Express 설치](#express-설치)
                -   [Express 배포할 HTML 준비](#express-배포할-html-준비)
                -   [Express 구동 로컬테스트](#express-구동-로컬테스트)
                -   [Express 외부망 연결 및 API 테스트](#express-외부망-연결-및-api-테스트)
            -   [NGINX 구동](#nginx-구동)
                -   [NGINX 설치](#nginx-설치)
                -   [NGINX 기본 명령어](#nginx-기본-명령어)
                -   [NGINX 구동 테스트](#nginx-구동-테스트)
                -   [NGINX 간단실행 환경 조성](#nginx-간단실행-환경-조성)
            -   [NGINX ⟶ Express 연결](#nginx--express-연결)
                -   [Express 코드 조정](#express-코드-조정)
                -   [NGINX 코드 조정](#nginx-코드-조정)
    -   [HTTP DNS 도메인으로 연결](#http-dns-도메인으로-연결)

## HTTP IP 주소로 연결

### 서버 적용

#### 서버 적용 : 개요

#### 서버 적용 : 세부 설명

#### Express 구동

##### Express 설치

##### Express 배포할 HTML 준비

##### Express 구동 로컬테스트

##### Express 외부망 연결 및 API 테스트

#### NGINX 구동

##### NGINX 설치

-   NGINX 설치 유무 확인

    &nbsp; NGINX 는 node.js 와는 별개의 서버 프로그램이므로 설치가 필요합니다. NGINX 의 설치가 되어 있다면 이 부분을 넘겨도 됩니다. 설치 유무를 모른다면 밑의 버전 확인 명령어를 터미널에 입력해보면 됩니다.

    ```bash
    # NGINX 버전 확인 명령어. 설치되어 있을 경우에 설치된 버전이 출력됨
    nginx -v
    ```

-   설치 파일 다운로드

    &nbsp; Windows OS 에서는 [nginx 공식 사이트](https://nginx.org/en/download.html) 에서 설치할 수 있습니다. (Ubuntu에서는 `sudo apt update && sudo apt install nginx` 명령어로 설치 가능합니다.)

    &nbsp; Nginx 의 여러 버전들 중에선 가장 앞선 버전의 stable version 을 설치하는 것을 추천합니다.

    &nbsp; 원하는 버전의 `nginx/Windows-...` 항목을 설치하면 됩니다. PGP(Pretty Good Privacy) Signature 전자서명 파일 .pgp 는 설치할 필요없으며 Linux/Unix용 소스 코드 패키지인 기본 모델 또한 불필요합니다.

-   설치 파일 압축해제 및 Windows 설정

    &nbsp; 원하는 위치에 `nginx/Windows-....zip` 파일의 압축을 풉니다. 이 폴더에서 `nginx.exe` 가 위치하는 경로를 `$NGINX_HOME` 라고 임시로 부르겠습니다. (예를 들어, `C:/example/nginx-1.28.0/nginx.exe` 라면 `$NGINX_HOME` 는 `C:/example/nginx-1.28.0` 입니다.)

    &nbsp; 윈도우 작업 표시줄 윈도우 로고를 우클릭하고 `시스템` 항목 클릭 -> `고급 시스템 설정` -> (시스템 속성 창)`고급` -> `환경 변수(N)...` 의 이동 흐름을 따라서 환경변수 설정 화면으로 가주세요.

    &nbsp; 그 후, 상단의 _사용자 변수_(본인 계정에만 적용) 또는 하단의 _시스템 변수_(모든 계정에 적용) 중 하나를 골라 변수 중에 `Path` 라는 이름의 변수를 선택하고 편집해주세요.

    &nbsp; `Path` 환경변수에 nginx 의 경로 `$NGINX_HOME` 를 추가해주세요.

    &nbsp; nginx 는 상대경로로 설정값과 에러 로그를 가져오므로 아무 곳에서 구동할 때는 우려되는 점이 많습니다. nginx 경로가 기억이 안나거나 일일히 찾아가기 귀찮을 때 이렇게 Path 가 경로를 알고있기 때문에

    -   `where nginx`(cmd)
    -   `where.exe nginx`(powershell)
    -   `Get-Command nginx`(powershell)

    등의 명령어로 nginx.exe 경로를 얻을 수 있습니다.

    &nbsp; 정상적으로 적용되었다면 `nginx.exe` 와 `/conf/` 폴더가 위치한 곳에서 powershell 터미널을 열고 `nginx -t` 명령어를 입력하면 터미널에 nginx 테스트 로그가 출력됩니다.

-   (참고) Windows 외부 설정파일 가져오기

    &nbsp; 만약 외부의 설정을 가져와야 할 때, Windows OS 에선 Linux 와 방법이 다릅니다.

    &nbsp; Windows 버전 nginx 에서는 Linux 에서처럼 별도의 sites-available나 conf.d 폴더를 기본적으로 제공하지 않습니다. 대신에, 설치된 경로를 `$NGINX_HOME` 라고 한다면 `$NGINX_HOME/conf/nginx.conf` 파일 내부에서 include 지시어를 사용하여 사용자 정의 설정 파일들을 포함시킬 수 있습니다.

##### NGINX 기본 명령어

&nbsp; 터미널에 입력하는 기본적인 명령어는 다음과 같습니다. 처음엔 대충 이런 느낌이라는 것만 확인 하고, 모를때만 다시 보면 됩니다.

-   <table>
    <tr>
    <th>기능</th>
    <th>Linux</th>
    <th>Windows</th>
    </tr>
    <tr>
    <td>NGINX <u><b>구동</u></b></td>
    <td colspan="2">

    `nginx`

    </td>
    </tr>
    <tr>
    <td>설정 파일 문법 <u><b>테스트</u></b></td>
    <td>

    `sudo nginx -t`

    </td>
    <td>

    `nginx -t`

    </td>
    </tr>
    <tr>
    <td>백그라운드에서 마스터 프로세스 <u><b>시작</u></b></td>
    <td>

    `sudo systemctl start nginx`

    </td>
    <td>

    `start nginx`

    </td>
    </tr>
    <tr>
    <td>모든 워커 프로세스 즉시 <u><b>종료</u></b></td>
    <td>

    `sudo systemctl stop nginx`

    </td>
    <td>

    `nginx -s stop`

    또는

    `taskkill /F /IM nginx.exe` (cmd 강제종료)

    또는

    `Stop-Process -Name nginx -Force` (powershell 강제종료)

    </td>
    </tr>
    <tr>
    <td>프로세스 완전 <u><b>종료 후 재구동</u></b></td>
    <td>

    `sudo systemctl restart nginx`

    </td>
    <td>

    `nginx -s stop` 후 `start nginx`

    </td>
    </tr>
    <tr>
    <td>프로세스를 종료하고 빠르게 <u><b>새 설정으로 시작</u></b></td>
    <td>

    `sudo systemctl reload nginx`

    </td>
    <td>

    `nginx -s reload`

    </td>
    </tr>
    <tr>
    <td>Nginx 프로세스 <u><b>상태 확인</u></b></td>
    <td>

    (상태 확인)

    </td>
    <td>

    `Get-Process nginx`

    또는

    작업 관리자에서 nginx.exe 프로세스 확인

    </td>
    </tr>

    </table>

##### NGINX 구동 테스트

&nbsp; 계속해서 설명의 편의를 위하여 

-   express 프로젝트 폴더의 경로를 `$PROJECT_ROOT` 라고 부르겠습니다.
-   nginx.exe 가 위치힌 경로를 `$NGINX_HOME` 라고 부르겠습니다.

&nbsp; 위에서 언급 했듯이 nginx 경로가 기억이 안난다면 `where nginx`(cmd 명령어), `where.exe nginx`(powershell 명령어) 를 통해 `$NGINX_HOME` 경로를 찾을 수 있습니다.

&nbsp; `$NGINX_HOME/conf/nginx.conf` 의 server { ... } 부분의 값을 수정하여 웹 서버의 동작 설정을 바꿀 수 있습니다. NGINX 는 기본적으로 C++ 친화적이며, 작업은 .conf 설정 파일 텍스트에 NGINX 지시어(directive) 를 적어서 기능을 조작합니다.

&nbsp; 처음 nginx.conf 파일을 열어보면 다음과 같은 형태입니다.

```conf
#user  nobody;
worker_processes  1;

#error_log  logs/error.log;
#error_log  logs/error.log  notice;
#error_log  logs/error.log  info;
#pid        logs/nginx.pid;


events {
    worker_connections  1024;
}


http {
    include       mime.types;
    default_type  application/octet-stream;

    #log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
    #                  '$status $body_bytes_sent "$http_referer" '
    #                  '"$http_user_agent" "$http_x_forwarded_for"';

    #access_log  logs/access.log  main;
    sendfile        on;
    #tcp_nopush     on;
    keepalive_timeout  65;
    #gzip  on;

    server {

    }
}
```

&nbsp; 이 nginx.conf 파일 텍스트 중에 `http{}` 안에 적혀있는 `server{}` 묶음 하나마다 서버 하나라고 생각하면 됩니다. 예를 들어서 다음과 같이 적었다면

```conf
http {
    
    server {
        listen 80 default_server;
        server_name _;
        return 444;
    }

    server {
        listen 80;
        server_name game.example.com;
        access_log logs/game_80_access.log;
        error_log  logs/game_80_error.log;
    }

    server {
        listen 8080;
        server_name web.example.com;
        access_log logs/web_8080_access.log;
        error_log  logs/web_8080_error.log;
    }

    server {
        listen 8080 default_server;
        server_name game.example.com;
        access_log logs/game_8080_access.log;
        error_log  logs/game_8080_error.log;
    }
}
```

NGINX 구동 시에 각 포트 별로, 접근한 도메인 별로 서버를 4개를 만드는 conf 설정파일이 됩니다.

&nbsp; 이런 설정으로 요청을 받을 준비를 하는 URL 과 서버 포트 번호(0 ~ 65535), 그리고 그 요청에 따른 응답을 정할 수 있습니다. 관습적으로 웹서버는 80번 포트를 사용합니다. 하지만 보통 ISP(인터넷 서비스 제공업체)는 일반 가정 서비스에서는 보안상의 이유로 80 포트를 막아 놓기 때문에, 이런 경우엔 8080 또는 8000 포트를 대체 번호로 사용합니다.

&nbsp; 다음과 같은 설정으로 Nginx 가 localhost(127.0.0.1) 주소의 8080포트 에 대하여 index.html 웹서버 역할을 하도록 할 수 있습니다. `... omitted(생략됨) ...` 이라고 요약 부분은 지금은 신경 쓸 필요 없습니다. `server { ... }` 에 집중해주세요.

```conf
... omitted ...

events {
    ... omitted ...
}

http {

    ... omitted ...

    server {
        # ## listen

        # * 뒤에 listen 8080 default_server 처럼 default_server 라고 적으면 해당 포트의 기본 서버로 취급합니다.

        listen 8080; # 모든 IPv4 주소 (0.0.0.0) 에서 8080 포트 허용
        listen [::]:8080; # 모든 IPv6 주소 (::) 에서 8080 포트 허용


        # ## server_name

        # * 복수개의 서버 중에서 이 서버명 URL 을 host 로 하는 요청이 있을 경우, 이 서버가 응답합니다.
        # * 일치하는 것이 없으면 해당 listen 포트의 기본 서버(default server) 가 응답합니다.
        # * IP 주소를 입력하거나 준비된 도메인이 있다면 도메인을 입력합니다.

        server_name localhost;


        # ## root

        # * 웹사이트 파일들이 위치한 루트 디렉토리를 지정합니다.
        # * 이 경로는 Nginx 서버가 실제 파일을 찾는 위치입니다.
        # * 이 경로를 실제 index.html 파일이 있는 경로로 변경해야 합니다.
        # * 상대경로가 아니라 절대경로여야 합니다.
        # * 띄어쓰기가 있는 경로 전체를 큰따옴표("") 또는 작은따옴표('')로 감쌉니다.
        # * Windows OS 환경에서 절대 경로를 사용할 때, 역슬래시(\) 대신에 슬래시(/) 또는 역슬래시를 연속으로(\\) 사용해야 합니다.

        root "$PROJECT_ROOT/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다


        # ## index

        # 루트 URL (/)로 요청이 들어왔을 때, 어떤 파일들을 index(기본화면) 로 취급해야 하는지에 대한 우선순위를 지정합니다.
        # Nginx는 나열된 순서대로 파일을 찾습니다.

        index index.html index.htm;


        # ## location

        # 모든 요청(location /)에 대한 처리 방식을 정의합니다.
        location / {
            # 'root'와 'index' 지시어를 사용하여 요청된 파일(예: index.html)을 찾아 서비스합니다.
            try_files $uri $uri/ =404;
        }
    }
}
```

이번에도 코드에 NGINX 의 설정 지시어들에 대하여 설명하는 주석이 많기 때문에 복잡해 보일 수 있습니다. 걱정마시고 결국 설명문만 다지우고 나면 아래 8줄이 전부입니다.

```conf
server {
    listen 8080;
    listen [::]:8080;
    server_name localhost;
    root "C:/html";
    index index.html index.htm;
    location / {
        try_files $uri $uri/ =404;
    }
}
```

&nbsp; root 지시어로 NGINX 가 바라보는 위치를 `C:/html` 로 지정했으므로 Express.js 때 처럼 C 드라이브에 html 폴더를 만들고 index.html 을 만들어서 넣어주세요.

```html
<!DOCTYPE html>
<html>
    <head>
        <title>My Page</title>
    </head>
    <body>
        <h1>Hello, world!</h1>
    </body>
</html>
```

&nbsp; 현재 터미널이 위치한 곳 따라서 밑의 두 명령어 중 하나를 입력하여 nginx 구동해주세요. (conf 폴더와, log 폴더를 찾아야하므로 -p 옵션으로 어디에서 찾으면 되는지 알려줘야 합니다.)

```bash
# * 1. nginx.exe 가 위치한 곳에서만 그냥 사용가능
nginx

# * 2. 아무 위치에서나 가능. -Prefix 옵션 적용하여 where.exe nginx 위치 기반으로 conf, log 탐색
nginx -p (Split-Path (where.exe nginx | Select-Object -First 1))
```

&nbsp; 기동 후에 터미널은 nginx 구동과 함께 더 이상 추가 메세지는 나오지 않습니다. 구동 이후에 웹 브라우저를 키고 `localhost:8080` 를 입력하여 페이지가 제대로 나오는지 확인해주세요.

&nbsp; 또한, 의도적으로 없는 url `http://localhost:8080/wasd/zxc` 를 입력하여 404 에러 페이지를 출력하는 지 확인해주세요.

&nbsp; 모든 IP `0.0.0.0`, `[::]` 에 대하여 열었으니 `http://『내 IP 주소』:8080/` 으로도 테스트 할 수 있습니다.

&nbsp; NGINX 를 종료하고 싶다면, 새로 터미널 창을 열고 터미널이 위치한 곳 따라서 밑의 두 명령어 중 하나를 입력하여 nginx 구동해주세요.

```bash
# * 1. nginx.exe 가 위치한 곳에서만 그냥 사용가능
nginx -s quit

# * 2. 아무 위치에서나 가능. -Prefix 옵션 적용하여 where.exe nginx 위치 기반으로 conf, log 탐색
nginx -p "$(Split-Path (where.exe nginx | Select-Object -First 1))" -s quit
```

##### NGINX 간단실행 환경 조성

&nbsp; NGINX 의 실행이 귀찮지 않으셨다면 이 부분을 넘어가도 좋습니다.

&nbsp; 구동 테스트를 해본 후에 느꼈을 지는 모르지만, NGINX 는 구동 후에 터미널에게 구동을 했다는 별도의 반환값도 없고 터미널 출력도 없이 독립적으로 돌아갑니다. 그래서 종료나 통제를 위해선 터미널을 닫고 새로 열어야 합니다. 에러나 접근에 대한 로그 데이터는 터미널로 출력 되지 않으며 nginx.exe 가 설치된 곳 위치에서 logs/ 폴더 안의 텍스트 파일로 출력합니다. 

&nbsp; 작동이 터미널과 무관하기 때문에 프로세스를 실행하라는 명령만하고 터미널은 신경쓰지 않겠다는 명령으로 `Start-Process nginx` 라고 명령어를 바꿔주면 편합니다. 문제는 터미널을 열은 곳이 nginx.exe 가 위치한 곳이 아닐 경우입니다.

&nbsp; NGINX 의 기동에는 로그 데이터를 적을 txt 파일과 conf 설정 파일이 필요하기 때문에 항상 nginx.exe 가 위치한 `$NGINX_HOME` 을 참고해야 합니다.

&nbsp; 파워쉘에서 `where.exe nginx` 로 `$NGINX_HOME` 값을 얻을 수 있지만, 매번 `cd` 로 이동하거나 탐색기 explorer 에서 주소를 검색해서 이동한 다음에 nginx 를 구동하는 것은 상당히 귀찮은 일 입니다.

&nbsp; 그렇다고 한들 매번 참고용 주소 `$NGINX_HOME`를 nginx 실행 명령어에 친다면 코드가 다음과 같이 길어집니다.

-   실행 시
    ```ps1
    Start-Process nginx -ArgumentList "-p `"$(Split-Path (where.exe nginx | Select-Object -First 1))`""
    ```

-   종료 시
    ```ps1
    nginx -p "$(Split-Path (where.exe nginx | Select-Object -First 1))" -s quit
    ```

-   에러 로그 확인
    ```ps1
    Get-Content -Path "$(Split-Path (where.exe nginx | Select-Object -First 1))\logs\error.log" -Wait -Tail 10
    ```

-   접속 로그 확인
    ```ps1
    Get-Content -Path "$(Split-Path (where.exe nginx | Select-Object -First 1))\logs\access.log" -Wait -Tail 10
    ```

&nbsp; 솔직히 말해서 너무 깁니다.

&nbsp; 다행히 파워쉘은 `$PROFILE` 에 .ps1 파일 코드에 적은 명령어는 실행시 자동으로 실행하는 default 설정으로 인식합니다. 파워쉘 `$PROFILE` 에 긴 명령어를 함수로 적어놓고 더 짧게 키워드로 호출하는 환경을 조성할 수 있습니다.

&nbsp; 파워쉘에서 `$profile` 를 입력하고 나오는 경로의 파일에 다음의 내용을 추가해주세요.

```ps1
# ## NGINX Config Setting

# ### NGINX 경로로 이동
function Nginx-Changedirectory {
    cd $(Split-Path (where.exe nginx | Select-Object -First 1))
}

# ### NGINX quick start 빠른 시작
function Nginx-Start {
    Start-Process nginx -ArgumentList "-p `"$(Split-Path (where.exe nginx | Select-Object -First 1))`""

    # * If subexpression is not used
    # $TempNginxDir = Split-Path (where.exe nginx | Select-Object -First 1); 
    # Start-Process nginx -ArgumentList "-p `"$TempNginxDir`""
}

# ### NGINX quick stop 빠른 종료
function Nginx-Stop {
    param(
        [int]$StopLevel = 0
    )

    switch ($StopLevel) {
        0 {
            Write-Host "Stop NGINX on level 0 (quit)"
            nginx -p "$(Split-Path (where.exe nginx | Select-Object -First 1))" -s quit
        }
        1 {
            Write-Host "Stop NGINX on level 1 (stop)"
            nginx -p "$(Split-Path (where.exe nginx | Select-Object -First 1))" -s stop
        }
        2 {
            Write-Host "Stop NGINX on level 2 (Forced)"
            Stop-Process -Name nginx -Force
        }
        default {
            Write-Warning "Invalid stop-level. (Support 0 to 2)"
        }
    }
}

# ### Nginx Get Process 동작 상태 체크
function Nginx-Check {
    Get-Process nginx
}

# ### Nginx Error Log 에러 로그 보기
function Nginx-Error {
    Get-Content -Path "$(Split-Path (where.exe nginx | Select-Object -First 1))\logs\error.log" -Wait -Tail 10

    # * If subexpression is not used
    # $TempErrPath = "$(Split-Path (where.exe nginx | Select-Object -First 1))\logs\error.log"
    # Get-Content -Path $TempErrPath -Wait -Tail 10
}

# ### Nginx Access Log 접근 로그 보기
function Nginx-Access {
    Get-Content -Path "$(Split-Path (where.exe nginx | Select-Object -First 1))\logs\access.log" -Wait -Tail 10

    # * If subexpression is not used
    # $TempAccPath = "$(Split-Path (where.exe nginx | Select-Object -First 1))\logs\access.log"
    # Get-Content -Path $TempAccPath -Wait -Tail 10
}

# ### More short alias keyword 더 짧게 키워드로 호출
Set-Alias cdng Nginx-Changedirectory
Set-Alias ngstart Nginx-Start
Set-Alias ngstop Nginx-Stop
Set-Alias ngcheck Nginx-Check
Set-Alias ngerr Nginx-Error
Set-Alias ngacc Nginx-Access
```

이후에는 새로 킨 파워쉘 창에서는 `ngstart` 같은 키워드만 입력해도 동작합니다.

#### NGINX ⟶ Express 연결

&nbsp; 자, 다시 한 번 정리해봅시다. 우리가 만드려고 하는 구조는 다음과 같습니다.

```txt
클라이언트(외부 인터넷 망 웹브라우저)
    │
    │ http://공인IP
    ↓
인터넷 공유기
    │
    │ 방화벽 개방 포트 :8080
    ↓
서버 PC
    ↓
NGINX :8080
    │
    ├────────────⟶ 정적 파일 (HTML / CSS / JS / 이미지)
    │
    └── /api/... ⟶ Express :3000
```

&nbsp; 외부에서 오는 접근에 대한 대문 역할을 NGINX 가 처리하며 요청의 성격에 따라 직접 처리할지, Express 에게 넘겨줄지를 결정합니다.

&nbsp; 만약 요청하는 데이터가 URL 과 매핑되어있어 외부에 전체공개되는(public) 정적 데이터일 경우엔 NGINX 가 즉시 넘겨주며, 처리과정에서 로직이 필요한 API 요청과 로그인 시도 또는 DB 조작처럼 복잡한 분석은 Express 에게 보내 처리 시킵니다.

&nbsp; 계속해서 설명의 편의를 위하여 

-   프로젝트 폴더(예시에서 example-server-project 로 만들었던 폴더)의 경로를 `$PROJECT_ROOT` 라고 부르겠습니다.

-   NGINX 를 설치했던 폴더 즉, nginx.exe 가 위치힌 경로를 `$NGINX_HOME` 라고 부르겠습니다.

##### Express 코드 조정

&nbsp; 먼저 할 일은, `$PROJECT_ROOT` 경로의 javascript 파일(예시에서 server.js 라고 이름붙임) 의 코드를 local 환경에서 api 에만 반응하도록 하는 것입니다. 다른 역할은 NGINX 에게 부여할 것 입니다.

```js
const express = require('express');
// * URL 를 통한 정적파일 제공은 NGINX 가 root 지시어로 담당하므로 제거
// const path = require('path');

const app = express();
const PORT = 3000;

// * Express 객체 app 설정 중 'trust proxy' 값의 기본값은 false 입니다. 요청 헤더에 프록시에 대한 정보가 있더라도 믿지 않고 직접 연결로만 취급하겠다는 소리입니다.
// * 밑의 NGINX 가 X-Forwarded-For 요청의 헤더로 실제로 요청을 보낸 클라이언트의 IP 주소를 전달해줘도 Express 는 그걸 req.ip 로 받아들이지 않고 '난 못 믿어, 이건 127.0.0.1 에서 왔잖아? 악의적인 클라이언트가 헤더 조작한거 같은데?' 라고 판단합니다. 이러면 req.get('X-Forwarded-For') 로 직접 헤더를 뜯어서 데이터를 얻어야 합니다. 이 보안처리에서 어떤 요청을 신뢰해도 되는지 지정해줄 필요가 있습니다.
// * 'tust proxy'라는 설정의 값을 'loopback'으로 지정함으로써, 연결해 온 프록시가 loopback 주소라면 그 프록시가 전달하는 프록시 정보는 신뢰해도 된다는 의미가 됩니다.
app.set('trust proxy', 'loopback');

// * Express 서버가 요청을 수신하여 움직일때 미들웨어 단계에서 터미널에 메세지를 출력합니다.
app.use((req, res, next) => {
    console.log('REQUEST');
    next();
});
// * URL 를 통한 정적파일 제공은 NGINX 가 root 지시어로 담당하므로 제거합니다.
// app.use(express.static(path.join(__dirname, 'public')));

// * API 요청 처리. 후에 DB 와 연결하는 코드로 변경할 수 있음
app.get('/api/test', (req, res) => {
    res.json({
        success: true,
        message: 'Express is working',
    });
});

// * 내 컴퓨터로 특정 포트의 모든 네트워크 인터페이스([::] 또는 0.0.0.0)에서 접근하는 대문은 NGINX 가 담당
// * 대문 NGINX 가 통과시킨 127.0.0.1:3000 인터페이스에만 응답
app.listen(PORT, '127.0.0.1', () => {
    console.log(`Express server running on port ${PORT}`);
});
```

`$PROJECT_ROOT` 위치에서 터미널에 `node server.js` 명령어를 입력하여 Express 서버를 구동합니다.

로컬 환경에서 웹브라우저에 `localhost:3000/api/test` 주소를 입력했을 때, 응답으로 json 데이터가 오는 지를 확인합니다. (index.html 은 NGINX 가 제공하므로 여기선 테스트가 불가합니다.)
또한, 요청 시에 터미널에 "REQUEST" 가 출력되는 지도 확인해주세요.

터미널과 서버를 닫지말고 유지해주세요.

##### NGINX 코드 조정

Express 서버가 열려있는 상태에서 NGINX 의 conf 설정 중 html{...} 괄호 안의 `server{...}` 설정을 다음과 같이 변경해주세요.

```conf
server {
    listen 8080; # * 정확히는 listen 0.0.0.0:8080 이지만 생략 허용
    listen [::]:8080;

    server_name _; # * 이 서버가 특정 도메인 전용이 아닐 경우 "_" 기입

    root "$PROJECT_ROOT/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다 !
    index index.html;

    location / {
        # * uri 위치에 매핑된 파일 반환하나 없으면 404 에러가 아니라 index.html 을 반환.
        # * SPA(Single Page Application) 를 고려한 설정
        try_files $uri $uri/ /index.html;
    }

    location /api/ {
        # * api 요청은 3000포트 Express 에게 전달
        proxy_pass http://127.0.0.1:3000;


        # * Express 에게 요청을 전달할 때 HTTP/1.1을 사용해라
        proxy_http_version 1.1;

        # * 원본 요청을 헤더 Host 에 담아 전달해라
        proxy_set_header Host $host;

        # * 원본 클라이언트 IP 주소를 X-Real-IP라는 헤더에 담아 전달해라
        proxy_set_header X-Real-IP $remote_addr; 

        # * 이제까지 거쳐온 IP 주소를 X-Forwarded-For 라는 헤더에 누적해서 전달해라
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;

        # * 요청 프로토콜을 X-Forwarded-Proto 라는 헤더에 담아 전달해라
        proxy_set_header X-Forwarded-Proto $scheme;
    }
}
```

`root "$PROJECT_ROOT/public"; # <==== ! 프로젝트 경로로 교체해서 적을 것 !` 에서 ` $PROJECT_ROOT ` 부분을 express 서버 프로젝트 폴더 내부 public/ 경로로 적어주셔야 한다는 점 잊지마세요.

-   터미널을 새로 열고 NGINX 기동 명령어를 입력하여 기동해주세요. 

    <u><b>NGINX 간단실행 환경 조성 문단</b></u>의 작업을 했다면 `ngstart` 라고만 입력하면 됩니다.

-   터미널에서 NGINX 로그 확인 명령어를 입력하면 접속 로그도 볼 수 있습니다.

    <u><b>NGINX 간단실행 환경 조성 문단</b></u>의 작업을 했다면 `ngacc` 라고만 입력하면 됩니다.

-   외부망의 웹 브라우저에서 `http://『내 IP 주소』:8080/` 으로 요청을 보내보세요.
    -   웹 브라우저에서 index.html 페이지가 응답받았는지 확인해주세요.
    -   NGINX 의 Access 로그 측 터미널에서 출력이 있는지 확인해주세요.
    -   Express 서버 측 터미널은 응답하지 않았을 것 입니다.

-   외부망의 웹 브라우저에서 `http://『내 IP 주소』:8080/api/test` 으로 요청을 보내보세요.
    -   웹 브라우저에서 json 데이터를 응답받았는지 확인해주세요.
    -   NGINX 의 Access 로그 측 터미널에서 출력이 있는지 확인해주세요.
    -   Express 서버 측 터미널에서 "REQUEST" 를 출력했는지 확인하세요.

이 과정이 성공했다면 축하드립니다.
당신은 통상적인 서버 구축, 정적 웹페이지 제공, API 제공에 성공하셨습니다.

종료하고 싶다면 

-   Express 서버 측 터미널에서 ctrl + c 를입력해주세요.
-   NGINX 의 Access 로그 측 터미널에서 ctrl + c 를입력해주세요.
-   터미널에서 NGINX 종료 명령어를 입력해주세요.

    <u><b>NGINX 간단실행 환경 조성 문단</b></u>의 작업을 했다면 `ngstop` 라고만 입력하면 됩니다.

이제 다음 단계는 DNS 를 통하여 IP 주소를 직접 입력하는 환경이 아니라 도메인 주소를 통한 웹 서비스를 구축하는 것 입니다.

## HTTP DNS 도메인으로 연결
