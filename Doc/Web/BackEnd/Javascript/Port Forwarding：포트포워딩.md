# Port Forwarding：포트포워딩

## 목차

-   [Port Forwarding：포트포워딩](#port-forwarding포트포워딩)
    -   [목차](#목차)
    -   [개념 설명](#개념-설명)
    -   [웹 서비스 포트포워딩 예시](#웹-서비스-포트포워딩-예시)
        -   [사용되는 기술 스택 설명](#사용되는-기술-스택-설명)
        -   [1. node.js 서버 설정：Static File Serving](#1-nodejs-서버-설정static-file-serving)
            -   [1-1. Express 설치](#1-1-express-설치)
            -   [1-2. 배포할 HTML 준비](#1-2-배포할-html-준비)
            -   [1-3. 서버 파일 server.js 생성](#1-3-서버-파일-serverjs-생성)
            -   [1-4. 서버 실행](#1-4-서버-실행)
        -   [2. Nginx 리버스 프록시 설정](#2-nginx-리버스-프록시-설정)
            -   [2-1. Nginx 설치](#2-1-nginx-설치)
                -   [□ Nginx 윈도우 설정](#-nginx-윈도우-설정)
                -   [□ Nginx 기본 명령어](#-nginx-기본-명령어)
                -   [□ Nginx 설정](#-nginx-설정)
        -   [3. Windows 방화벽 및 공유기 포트 포워딩](#3-windows-방화벽-및-공유기-포트-포워딩)
            -   [3-1. Windows 방화벽 설정](#3-1-windows-방화벽-설정)
            -   [3-2. 공유기 포트 포워딩 설정](#3-2-공유기-포트-포워딩-설정)
                -   [공유기 관리자 페이지 접속](#공유기-관리자-페이지-접속)
                -   [포트 포워딩 메뉴 찾기](#포트-포워딩-메뉴-찾기)
                -   [포트 포워딩 규칙 추가](#포트-포워딩-규칙-추가)

## 개념 설명

&nbsp; IP 에 대해서 기본적인 설명만 하겠습니다. 인터넷에서 주소지에 해당하는 IP 주소는 내부망과 외부망 각각 따로 값을 가집니다.

-   터미널에서 `ipconfig` 를 입력하면 본인의 내부 네트워크 안에서 사용하는 내부 IP 주소를 확인할 수 있습니다.
-   브라우저에서 `https://ifconfig.me/` 를 입력하면 외부 인터넷과 연결하는 공유기(Router)의 외부 IP 주소를 확인할 수 있습니다.

각각 위의 방법으로 주소값을 확인할 수 있습니다.

&nbsp; IPv4 주소 형식을 따르며 각 옥텟은 0에서 255 사이의 숫자여야 합니다. 또한 `127.0.0.0/8` (127.0.0.0 ~ 127.255.255.255까지의 약 1600만 개 주소)가 특별히 테스트 용으로 외부 네크워크와의 연결없이 자기 자신을 가르키는 루프백 기능을 위해 예약되었습니다. 이 중에서 자신을 의미하는 localhost 의 대표로 가장 많이 쓰이는 주소는 `127.0.0.1` 입니다.

&nbsp; 많은 개발 예제에서 `127.0.0.1` 주소에 `:8800` 등의 포트로 특정 서비스를 올리는 것을 보았을 것 입니다. 중요한 점은 로컬호스트에 올려놓은 것 만으로는 외부에선 접근할 수 없다는 것 입니다.

&nbsp; 예시로 외부 IP `12.34.56.78` 의 컴퓨터가 `127.0.0.1:3000` (localhost:3000) 에 index.html 을 올려놨다고 해도, 외부의 유저가 `12.34.56.78:3000` 으로 index.html 화면을 볼 수는 없습니다. 이는 다음의 두가지 이유 때문입니다.

-   공유기가 보안상의 이유로 외부에서 내부 네트워크로의 요청을 차단합니다.
-   공유기는 포트 3000 으로 들어온 요청을 내부 IP 주소:3000 으로 전달해야 한다는 것을 알지 못합니다.

외부에서 내부 네트워크에 있는 특정 컴퓨터의 특정 포트에 접속하려면, 공유기에 해당 요청을 전달하라는 명령을 설정해야 합니다. 이 명령이 바로 **_포트 포워딩_** 입니다.

## 웹 서비스 포트포워딩 예시

### 사용되는 기술 스택 설명

&nbsp; node.js 기반으로

`(외부인터넷) - 공유기 - Nginx - Express - (컴퓨터 내부 index.html)`

를 구현하는 방법이 가장 무난합니다.

-   Nginx

    -   Nginx는 외부로 부터 들어오는 요청들의 관문 역할을 합니다.
    -   리버스 프록시(Reverse Proxy) 기능
        -   외부에서 오는 직접적인 요청으로부터 내부 서버를 보호하고 <u><b>우회하여 Nginx가 먼저 요청을 받고 내부 서버로 요청을 전달</b></u>
    -   로드 밸런싱(Load Balancing) 기능
        -   여러 개의 Express 서버가 있을 때, 요청을 분산시켜 한 쪽으로 쏠리는 서버 과부하를 막고 서비스의 안정성을 높입니다.
    -   정적 파일 제공
        -   HTML, CSS, JavaScript, 이미지 파일 등 변하지 않는 정적 파일을 Express 보다 훨씬 빠르고 효율적으로 클라이언트에게 직접 제공합니다.
    -   SSL/TLS 처리
        -   HTTPS를 위한 암호화/복호화 작업을 Nginx가 대신 처리하여, Express는 순수하게 애플리케이션 로직만 처리하도록 부하를 줄여줍니다.

-   Express

    -   Express 는 웹 애플리케이션 프레임워크입니다. Node.js 환경에서 웹 서버를 구성하고 관리하는 데 필요한 핵심 기능을 제공합니다.
    -   라우팅(Routing) 및 설정 기능
        -   <u><b>HTTP 요청을 수신하고 응답을 처리합니다.</b></u>
        -   접속 포트나 템플릿 엔진 위치 같은 설정을 도와줍니다.
    -   미들웨어(Middleware) 관리
        -   인증(Authentication), 로깅(Logging), 데이터 압축, 세션 관리 등 다양한 기능을 요청과 응답의 중간 단계에 쉽게 추가할 수 있게 해줍니다.

### 1. node.js 서버 설정：Static File Serving

#### 1-1. Express 설치

&nbsp; 다음의 명령어, 또는 직접 탐색기를 통해서 프로젝트 폴더를 만든 뒤에 그 폴더로 이동해주세요.

```bash
mkdir example-project
cd example-project
```

&nbsp; node.js 의 npm 을 이용하여 express 를 설치해주세요.

```bash
# Express 설치
npm install express
```

#### 1-2. 배포할 HTML 준비

&nbsp; 그 후, 프로젝트 폴더 내에 public 폴더를 만들고, 그 안에 배포하고자 하는 index.html 파일을 넣습니다.

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

#### 1-3. 서버 파일 server.js 생성

&nbsp; 프로젝트 루트에 server.js 파일을 생성하고, 정적 파일을 제공하도록 설정합니다.

```js
const express = require('express');
const path = require('path');
const app = express();
// * Node.js 서버가 내부적으로 사용할 포트
const PORT = 3000;

// * `/public` 폴더를 정적 파일이 위치하는 곳으로 설정합니다.
app.use(express.static(path.join(__dirname, 'public')));

// * get 은 요청에 대한 응답을 제공합니다. (express.static 미들웨어는 클라이언트가 기본 경로(/) 로 요청을 보냈을 때, 정적 파일 폴더(public) 내부에서 index.html 파일을 자동으로 찾아서 응답으로 제공하는 기능이 내장되어 있습니다. 따라서 기본경로 / 에 index.html 을 응답하는 코드는 굳이 작성할 필요는 없습니다.)
// app.get('/', (req, res) => {
//     res.sendFile(path.join(__dirname, 'public', 'index.html'));
// });

// * listen 은 서버 애플리케이션이 처음 실행될 때 호출됩니다. 포트 바인딩 (Port Binding, Node.js의 HTTP 모듈을 사용하여 OS에 특정 포트 번호에서 들어오는 네트워크 요청을 이 프로세스(Node.js 서버)가 처리하겠다고 등록)과 서버 시작 (Start Listening, 등록된 포트로 들어오는 모든 TCP/IP 연결 요청을 수신 대기 상태(Listening State)로 전환) 작업을 수행합니다.
app.listen(PORT, () => {
    console.log(`Node.js server running on http://localhost:${PORT}`);
});
```

#### 1-4. 서버 실행

&nbsp; 다음 명령어를 통해서 서버 코드를 node.js 에서 구동시킵니다.

```bash
node server.js
```

&nbsp; 이제 웹 브라우저에서 서버가 실행되는 컴퓨터의 **내부 주소(http://localhost:3000)** 접속하여 페이지가 뜨는지 확인합니다.

### 2. Nginx 리버스 프록시 설정

#### 2-1. Nginx 설치

&nbsp; Windows OS 에서는 [nginx 공식 사이트](https://nginx.org/en/download.html) 에서 설치할 수 있습니다. (Ubuntu에서는 `sudo apt update && sudo apt install nginx` 명령어로 설치 가능합니다.)

&nbsp; Nginx 의 여러 버전들 중에선 가장 앞선 버전의 stable version 을 설치하는 것을 추천합니다.

&nbsp; 원하는 버전의 `nginx/Windows-...` 항목을 설치하면 됩니다. PGP(Pretty Good Privacy) Signature 전자서명 파일 .pgp 는 설치할 필요없으며 Linux/Unix용 소스 코드 패키지인 기본 모델 또한 불필요합니다.

##### □ Nginx 윈도우 설정

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

##### □ Nginx 기본 명령어

&nbsp; 기본적인 명령어는 다음과 같습니다.

-   <table>
    <tr>
    <th>기능</th>
    <th>Linux</th>
    <th>Windows</th>
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

##### □ Nginx 설정

&nbsp; Windows 버전 nginx 에서는 Linux 에서처럼 별도의 sites-available나 conf.d 폴더를 기본적으로 제공하지 않습니다. 대신에, 설치된 경로를 `$NGINX_HOME` 라고 한다면 `$NGINX_HOME/conf/nginx.conf` 파일 내부에서 include 지시어를 사용하여 사용자 정의 설정 파일들을 포함시킬 수 있습니다.

&nbsp; `$NGINX_HOME/conf/nginx.conf` 의 server { ... } 부분의 값을 수정하여 기본 설정을 바꿀 수 있습니다.

&nbsp; 이 설정으로 요청을 받을 준비를 하는 URL 과 서버 포트 번호(0 ~ 65535), 그리고 그 요청에 따른 응답을 정할 수 있습니다. 관습적으로 웹서버는 80번 포트를 사용합니다. 하지만 보통 ISP(인터넷 서비스 제공업체)는 일반 가정 서비스에서는 보안상의 이유로 80 포트를 막아 놓기 때문에, 이런 경우엔 8080 또는 8000 포트를 대체 번호로 사용합니다.

&nbsp; 다음과 같은 설정으로 Nginx 가 localhost(127.0.0.1) 주소의 8080포트 에 대하여 index.html 웹서버 역할을 하도록 할 수 있습니다.

```conf
...

events {
    ...
}

http {

    ...

    server {
        listen 8080; # 모든 IPv4 주소 (0.0.0.0) 에서 8080 포트 허용
        listen [::]:8080; # 모든 IPv6 주소 (::) 에서 8080 포트 허용

        server_name localhost; # IP 주소를 입력하거나 도메인이 있다면 도메인을 입력합니다.

        # * 웹사이트 파일들이 위치한 루트 디렉토리를 지정합니다.
        # * 이 경로는 Nginx 서버가 실제 파일을 찾는 위치입니다.
        # * 이 경로를 실제 index.html 파일이 있는 경로로 변경해야 합니다.
        # * 상대경로가 아니라 절대경로여야 합니다.
        # * 띄어쓰기가 있는 경로 전체를 큰따옴표("") 또는 작은따옴표('')로 감쌉니다.
        # * Windows OS 환경에서 절대 경로를 사용할 때, 역슬래시(\) 대신에 슬래시(/) 또는 역슬래시를 연속으로(\\) 사용해야 합니다.
        root "D:/html";

        # 루트 URL (/)로 요청이 들어왔을 때, 어떤 파일들을 우선순위로 찾을지 지정합니다.
        # Nginx는 나열된 순서대로 파일을 찾습니다.
        index index.html index.htm;

        # 모든 요청(location /)에 대한 처리 방식을 정의합니다.
        location / {
            # 'root'와 'index' 지시어를 사용하여 요청된 파일(예: index.html)을 찾아 서비스합니다.
            try_files $uri $uri/ =404;
        }
    }
}
```

&nbsp; 위의 설정대로 nginx 를 구동하면 브라우저에서 로컬호스트 127.0.0.1:80 주소를 요청하면 `D:/html/index.html` 경로에 있는 html 페이지가 응답하는 것을 볼 수 있습니다.

&nbsp; 이번 예제에선 Nginx 를 배포 서버가 아니라 리버스 프록시 중간 경유 역할을 맡길 것 이기 때문에 직접 index.html 을 응답하는 것이 아니라, express 에게 응답 요청을 보내도록 설정을 다음과 같이 수정해야 합니다.

```conf
server {
    listen 80; # 모든 IPv4 주소 (0.0.0.0) 에서 80 포트 허용
    listen [::]:80; # 모든 IPv6 주소 (::) 에서 80 포트 허용

    server_name 12.34.56.78; # IP 주소를 입력하거나 도메인이 있다면 도메인을 입력합니다.

    location / {
        # 요청을 Node.js 서버의 내부 주소와 포트(3000)로 전달(프록시)합니다.
        proxy_pass http://localhost:3000;

        # 클라이언트의 실제 IP와 호스트 정보를 Node.js 서버로 전달하기 위한 설정
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }
}
```

이제 `Node.js` (3000) <- `Nginx` (80) <- `브라우저 요청` 흐름이 만들어졌습니다.

### 3. Windows 방화벽 및 공유기 포트 포워딩

&nbsp; 컴퓨터 내부적으로는 설정이 완료되었지만, 외부 인터넷에서 사용자의 컴퓨터로 접근하려면 2가지 추가 설정이 필요합니다.

#### 3-1. Windows 방화벽 설정

&nbsp; Windows 방화벽이 외부의 80번 포트 접근을 막지 않도록 설정을 해야합니다.

&nbsp; `제어판`(보기 기준: 큰 아이콘) -> `Windows Defender 방화벽` -> 좌측 탭의 `고급 설정` 으로 이동합니다.

&nbsp; `고급 보안이 포합된 Windows Defender 방화벽` 창이 뜰 것 입니다.

&nbsp; 좌측 탭의 `인바운드 규칙` 항목으로 이동합니다. 우측 탭의 `새 규칙` 을 클릭하여 새 규칙을 추가하는 `새 인바운드 규칙 마법사` 창을 띄웁니다.

&nbsp; <u><b>규칙 종류</u></b> 단계에서 `포트(O)` 를 선택합니다. 다음을 눌러 넘어갑니다.

&nbsp; <u><b>프로토콜 및 포트</u></b> 단계에서 다음 항목을 선택해주세요.

-   적용하는 프로토콜은 `TCP(T)` 를 선택합니다. 이는 웹 통신(HTTP)에 사용되는 표준 프로토콜 중 UDP 보다는 느리지만 상호체크를 통해 안정적이므로 웹사이트 배포에 사용되는 형태입니다.
-   적용하는 포트는 `80` 를 적습니다. 이 예제에서는 모든 포트 요청에서 작업을 받지는 않을 것 입니다.

다음을 눌러 넘어갑니다.

&nbsp; <u><b>작업</u></b> 단계에서 `연결 허용`(Allow the connection) 을 선택하여 80번 포트로 들어오는 모든 연결을 허용합니다. 다음을 눌러 넘어갑니다.

&nbsp; <u><b>프로필</u></b> 단계에서 모두 접근할 수 있도록 `도메인`, `개인`, `공용` 모두 체크합니다. 다음을 눌러 넘어갑니다.

&nbsp; <u><b>이름</u></b> 단계에서 `WEB_NGINX_HTTP_80` 같은 느낌으로 규칙의 용도를 쉽게 알 수 있도록 이름을 정합니다. 마침을 눌러 규칙을 저장합니다.

인바운드 규칙에서 새 규칙을 추가합니다.

포트 유형을 선택하고, TCP 프로토콜의 특정 로컬 포트에 80을 입력합니다.

연결 허용을 선택하고 규칙을 저장합니다.

현재 컴퓨터 연결 상황이 IPv4 인지 IPv6 인지에 따라

#### 3-2. 공유기 포트 포워딩 설정

&nbsp; 사용자의 공인 IP 주소 (예를 들어, 12.34.56.89)으로 들어온 요청을 웹 서버가 실행 중인 컴퓨터의 내부 IP 주소로 전달하도록 설정해야 합니다.

##### 공유기 관리자 페이지 접속

&nbsp; 터미널(powershell 또는 cmd) 에서 `ipconfig` 를 입력하면 공유기 관리자 페이지의 <u><b>기본 게이트 웨이</u></b> 주소(공유기의 내부 IP 주소)를 알 수 있습니다.

&nbsp; 브라우저에 <u><b>기본 게이트 웨이</u></b> 주소를 주소창에 입력하여 공유기 관리자 페이지로 갈 수 있습니다. 일반적으로 관리자 비밀번호는 공유기에 적혀있습니다.

##### 포트 포워딩 메뉴 찾기

&nbsp; 공유기 종류 마다 차이가 있습니다. 일반적으로 포트 포워딩 (Port Forwarding) 또는 가상 서버 (Virtual Server) 라고 적혀있을 설정 메뉴를 찾습니다.

##### 포트 포워딩 규칙 추가

-   <table>
    <tr class="0">
    <th class="0-0">설정 항목</th>
    <th class="0-1">값</th>
    <th class="0-2">설명</th>
    </tr>
    <tr class="1">
    <td class="1-0">외부 포트 (External Port)</td>
    <td class="1-1">80</td>
    <td class="1-2">외부 인터넷에서 들어오는 포트, 0~99 나 0-99 처럼 물결이나 하이픈이 있으면 범위로 지정가능. DMZ 서버의 경우 포트 제한 없이 모든 포트를 열고 외부 접근 허용</td>
    </tr>
    <tr class="2">
    <td class="2-0">내부 포트 (Internal Port)</td>
    <td class="2-1">80</td>
    <td class="2-2">내부 컴퓨터에서 받을 포트 (Nginx 포트)</td>
    </tr>
    <tr class="3">
    <td class="3-0">프로토콜 (Protocol)</td>
    <td class="3-1">TCP</td>
    <td class="3-2">웹페이지에 사용되는 프로토콜</td>
    </tr>
    <tr class="4">
    <td class="4-0">내부 IP 주소 (Internal IP Address)</td>
    <td class="4-1">사용자 Windows 컴퓨터의 내부 IP</td>
    <td class="4-2">웹페이지에 사용되는 프로토콜</td>
    </tr>
    </table>

&nbsp; 내부 IP 주소 값은 터미널(powershell 또는 cmd) 에서 `ipconfig` 를 입력하면 <u><b>IPv4 주소(IPv4 Address)</u></b> (컴퓨터에 할당된 내부 IP 주소) 항목을 보면 알 수 있습니다.
