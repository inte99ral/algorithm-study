# Server(Web, Platform)：웹 및 플랫폼 서버

## 목차

-   [Server(Web, Platform)：웹 및 플랫폼 서버](#serverweb-platform웹-및-플랫폼-서버)
    -   [목차](#목차)
    -   [개요](#개요)
    -   [Node.js 설치](#nodejs-설치)
        -   [Node.js 구동 테스트](#nodejs-구동-테스트)
    -   [IP 주소와 외부망 연결 테스트](#ip-주소와-외부망-연결-테스트)
        -   [IPv4](#ipv4)
            -   [IPv4 포트포워딩](#ipv4-포트포워딩)
        -   [IPv6](#ipv6)
            -   [IPv6 방화벽 설정](#ipv6-방화벽-설정)
    -   [HTTP IP 주소로 연결](#http-ip-주소로-연결)
        -   [NGINX 와 Express 로 분리하는 이유](#nginx-와-express-로-분리하는-이유)
        -   [Express](#express)
            -   [Express 패키지 설치](#express-패키지-설치)
            -   [Express 배포할 HTML 준비](#express-배포할-html-준비)
            -   [Express 로컬 테스트](#express-로컬-테스트)
            -   [Express 외부망 연결 및 API 테스트](#express-외부망-연결-및-api-테스트)
        -   [NGINX](#nginx)
            -   [NGINX 설치](#nginx-설치)
            -   [NGINX 기본 명령어](#nginx-기본-명령어)
            -   [NGINX 구동 테스트](#nginx-구동-테스트)
            -   [NGINX 간단실행 환경 조성](#nginx-간단실행-환경-조성)
        -   [NGINX ⟶ Express 연결](#nginx--express-연결)
            -   [Express 코드 조정](#express-코드-조정)
            -   [NGINX 코드 조정](#nginx-코드-조정)
    -   [HTTP DNS 도메인으로 연결](#http-dns-도메인으로-연결)
        -   [DNS 사이트에서 도메인 발급받기](#dns-사이트에서-도메인-발급받기)
        -   [NGINX 조정](#nginx-조정)
    -   [HTTPS 프로토콜 연결](#https-프로토콜-연결)
        -   [NGINX 80포트 개방](#nginx-80포트-개방)
        -   [win-acme 설치 및 인증서 발급](#win-acme-설치-및-인증서-발급)
        -   [NGINX 를 HTTPS 서버로 전환](#nginx-를-https-서버로-전환)
        -   [NGINX HTTP 서버 정리](#nginx-http-서버-정리)
    -   [DB 와 연결](#db-와-연결)
        -   [PostgreSQL](#postgresql)
            -   [PostgreSQL 설치](#postgresql-설치)
            -   [PostgreSQL 자동 실행 해제 및 종료](#postgresql-자동-실행-해제-및-종료)
            -   [pgAdmin 4 열기](#pgadmin-4-열기)
            -   [Query Tool 로 DB 조작](#query-tool-로-db-조작)
            -   [API 에 사용할 Table 만들기](#api-에-사용할-table-만들기)
        -   [Express → PostgreSQL](#express--postgresql)
            -   [Node.js PostgreSQL 드라이버 패키지 설치](#nodejs-postgresql-드라이버-패키지-설치)
                -   [경고 출력 시](#경고-출력-시)
            -   [DB 조작용 필요 파일 생성](#db-조작용-필요-파일-생성)
            -   [.env 환경변수 작성](#env-환경변수-작성)
            -   [DB 연결 모듈화](#db-연결-모듈화)
            -   [Express 측 DB 연결 코드](#express-측-db-연결-코드)
            -   [개념 정리 : HTTP Method 와 CRUD](#개념-정리--http-method-와-crud)
            -   [개념 정리 : 멱등성](#개념-정리--멱등성)
        -   [DB 서비스 예제 1 (유저 명단 관리)](#db-서비스-예제-1-유저-명단-관리)
            -   [DB 서비스 예제 1-1 : 서비스 설계](#db-서비스-예제-1-1--서비스-설계)
            -   [DB 서비스 예제 1-2 : DB 환경 조성](#db-서비스-예제-1-2--db-환경-조성)
            -   [DB 서비스 예제 1-3 : Express 코드 작성](#db-서비스-예제-1-3--express-코드-작성)
                -   [개념정리 : 파라미터화 쿼리(Parameterized Query)](#개념정리--파라미터화-쿼리parameterized-query)
            -   [DB 서비스 예제 1-4 : URL 요청 코드](#db-서비스-예제-1-4--url-요청-코드)
                -   [개념 정리 : Javascript 비동기 제어](#개념-정리--javascript-비동기-제어)
                -   [1-4 URL Request 코드](#1-4-url-request-코드)
        -   [DB 서비스 예제 2 (사진첩)](#db-서비스-예제-2-사진첩)
            -   [DB 서비스 예제 2-1 : 서비스 설계](#db-서비스-예제-2-1--서비스-설계)
            -   [DB 서비스 예제 2-2 : DB 환경 조성](#db-서비스-예제-2-2--db-환경-조성)
            -   [DB 서비스 예제 2-3 : Server Express 코드](#db-서비스-예제-2-3--server-express-코드)
                -   [개념 정리 : Express 와 미들웨어 중간처리](#개념-정리--express-와-미들웨어-중간처리)
                -   [개념 정리 : 바이너리 데이터 타입과 요청 스트림](#개념-정리--바이너리-데이터-타입과-요청-스트림)
                -   [개념 정리 : Express 미들웨어 에러 핸들링](#개념-정리--express-미들웨어-에러-핸들링)
                -   [2-3 Server Express 코드](#2-3-server-express-코드)
            -   [DB 서비스 예제 2-4 : URL Request 코드](#db-서비스-예제-2-4--url-request-코드)
                -   [개념 정리 : 바이너리 데이터 타입 Blob 과 Buffer](#개념-정리--바이너리-데이터-타입-blob-과-buffer)
                -   [개념 정리 : 바이너리 데이터 조작하기](#개념-정리--바이너리-데이터-조작하기)
                -   [2-4 URL Request 코드](#2-4-url-request-코드)
            -   [DB 서비스 예제 2-5 : CommonJS ⟶ ES Modules](#db-서비스-예제-2-5--commonjs--es-modules)
                -   [개념정리 : 모듈시스템 CommonJS 와 ES Modules](#개념정리--모듈시스템-commonjs-와-es-modules)
                -   [CommonJS ⟶ ES Modules 전환 작업](#commonjs--es-modules-전환-작업)
                -   [I/O 코드 모듈화](#io-코드-모듈화)
        -   [DB 서비스 예제 3 (파일 클라우드)](#db-서비스-예제-3-파일-클라우드)
    -   [추가 작업](#추가-작업)
        -   [CORS](#cors)
        -   [개념 정리 : JWT(JSON Web Token)의 서명(Signature)](#개념-정리--jwtjson-web-token의-서명signature)
        -   [검색 노출](#검색-노출)
        -   [구글 애드센스](#구글-애드센스)

## 개요

&nbsp; 웹과 플랫폼, API 라이브러리를 제공할 경우, 해당 서버는 클라이언트와 소통할 때, 

-   `TCP` 전송계층(Transport Layer)프로토콜
-   `HTTPS` 응용계층(Application Layer)프로토콜

으로 소통하는 것이 일반적입니다. 

&nbsp; 어떻게 정보를 주고 받을 지에 정한 약속이 전송계층 프로토콜, 어떤 정보 형태로 주고 받을 지 정한 약속이 응용계층 프로토콜 입니다.

&nbsp; TCP 는 느리지만 서로 3-Way Handshake 를 통해 높은 신뢰성으로 정보를 넘겨줍니다.

&nbsp; HTTPS 기반 데이터는 여러 암호화 조건을 헤더에 넣을 수 있으며 웹 기반 데이터에 최적화 되어 있습니다.

&nbsp; QUIC (HTTP/3) 라는 최신 체계도 생겼습니다. UDP 기반으로 동작하면서도 보안(TLS)과 신뢰성을 제공하여 기존 TCP/HTTPS를 대체하는 용도로 쓸 수 있습니다. 다만 여기선 다루지 않겠습니다.

## Node.js 설치

&nbsp; 웹 프로젝트는 javascript 라이브러리 생태계가 압도적으로 크고 보편적으로 활성화되어있기 때문에 javascript 언어가 필수적입니다. javaScript 런타임 환경인 Node.js 을 설치하여 환경을 조성해두어야 합니다.

&nbsp; Node.js 가 있다면 javaScript 코드를 브라우저 밖에서도 실행할 수 있게 되며, NPM 이라는 강력한 node.js 패키지 환경에서 편리한 라이브러리를 마음껏 사용할 수 있습니다.

&nbsp; node.js 와 npm 의 설치가 되어 있다면 이 부분을 넘겨도 됩니다. 설치 유무를 모른다면 밑의 버전 확인 명령어를 터미널에 입력해보면 됩니다.

-   terminal shell

    ```bash
    # npm 버전 확인 명령어. 설치되어 있을 경우에 설치된 버전이 출력됨
    npm -v
    ```

&nbsp; Windows OS 에서는 [node.js 공식 사이트](https://nodejs.org/ko/download) 에서 설치할 수 있습니다.

기본 설정되어 있는 체크박스 상태를 거의 그대로 따라가면 됩니다. npm 설치 관련 체크박스가 참인지 환경변수 추가관련 체크박스가 참인지만 확인해주세요.

### Node.js 구동 테스트

&nbsp; Node.js 는 -e 옵션 (eval, evaluation 의 약자) 으로 별도의 파일 없이 명령줄에서 직접 JavaScript 코드를 실행할 수 있습니다.

&nbsp; 터미널에서 다음의 명령어를 입력할 때, `Hello, world!` 가 출력되는 지 확인해주세요.

-   terminal shell

    ```ps1
    node -e "console.log('Hello, World!')"
    ```

## IP 주소와 외부망 연결 테스트

&nbsp; 먼저 본인의 IP 가 IPv4 로 할당되었는지 IPv6 로 할당되었는지 확인해야합니다. 일종의 지번주소, 도로명주소처럼 표현의 차이지만 구조상 연결방법이 완전히 달라지므로 주의해주세요.

-   IPv4 (`***.***.***.***` 의 형태, 한 필드당 10진법 0~255) 의 경우, 내부 로컬 주소가 인터넷망에 노출되지 않습니다. 따라서 인터넷과 연결된 공유기의 주소와 내 로컬주소 포트를 연결하는 포트포워딩(Port Forwarding) 작업이 필요합니다.

-   IPv6 (`****:****:****:****:****:****:****:****` 의 형태, 한 필드 16진법 0~65535)의 경우, 연결된 모든 기기에 각기 전세계에 유니크한 IPv6 주소가 할당되기 때문에 포트포워딩 작업이 필요 없습니다. 하지만 방화벽이 외부 연결을 차단하여 보안을 지키기 때문에 테스트가 필요합니다.

### IPv4

&nbsp; 터널링·릴레이 등의 우회 방법을 제외하고, 일반적인 IPv4 인바운드 서버를 운영하려면, 외부 인터넷에서 보이는 공인 IPv4 주소와 내가 포트포워딩을 설정할 수 있는 장비의 WAN IPv4 주소가 동일해야 합니다.

&nbsp; 터미널(powershell 또는 cmd) 에서 `ipconfig` 를 입력하면 공유기 관리자 페이지의 <u><b>기본 게이트 웨이</u></b> 주소(공유기의 내부 IP 주소)를 알 수 있습니다. 웹 브라우저에 <u><b>기본 게이트 웨이</u></b> 주소를 주소창에 입력하여 공유기 관리자 페이지로 갈 수 있습니다. 일반적으로 관리자 비밀번호는 공유기에 적혀있습니다. 관리자 페이지에서 상위 IP 주소를 타고 올라가다보면 외부에서 이 컴퓨터에 접근가능한 공인 IP 주소를 알 수 있습니다. 이 IPv4 주소에 대하여...

-   조건1. 그 IPv4 주소에 대하여 포트포워딩 설정, 보안 설정을 만질 수 있는 권한이 있어야합니다.

-   조건2. 브라우저에서 `https://ifconfig.me/` 를 입력해서 확인하는 등, 외부에서 보는 우리의 IPv4 주소와 동일해야 합니다.

두 조건을 만족하면 가능합니다.

#### IPv4 포트포워딩

&nbsp; 최상위 IPv4 에 해당하는 공유기 주소 또는 인터넷서비스 주소에 들어온 요청을 웹 서버가 실행 중인 컴퓨터의 내부 IP 주소로 전달하도록 설정해야 합니다.

&nbsp; 해당 IP 주소를 웹브라우저에 입력하여 관리자 페이지에 접근합니다. 관리자 페이지는 서비스와 공유기 종류 마다 차이가 있지만, 일반적으로 포트 포워딩 (Port Forwarding) 또는 가상 서버 (Virtual Server) 라고 적혀있을 설정 메뉴를 찾습니다.

&nbsp; 포트포워딩 규칙을 적절하게 추가해주세요.

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

### IPv6

&nbsp; 외부망과의 직접적인 상호접근을 방화벽이 막지는 않는지, 그리고 할당된 Global IP 주소가 정상인지부터 확인해야합니다.

-   Global IP 확인

    -   터미널에서 `ipconfig` 명령을 입력하여 출력되는 값 중에서 "Global IP" 관련 주소가 존재하는 지 확인하기 (예: Global IPv6)
    -   없을 경우엔, 클라우드 서버를 거치거나 Cloudflare Tunnel, playit.gg 같은 외부 인터넷망과 연결해주는 서비스가 필요합니다.

-   아웃바운드 테스트, 외부 주소로 요청 시 연결 상태 확인

    -   `ping` 은 상대방 네트워크 장비에 작은 데이터 패킷을 보낸 뒤, 응답이 돌아오는지와 그 걸리는 시간을 측정하는 네트워크 진단 도구입니다. 
    -   구글이 제공하는 공개 DNS 서비스(Google Public DNS)의 IPv6 주소 2001:4860:4860::8888 와 IPv4 주소 8.8.8.8 를 사용해서 테스트가 가능합니다.
    -   다음의 명령어를 터미널에 입력 후, 응답이 오는 지를 확인해주세요.
        -   `ping -6 2001:4860:4860::8888` (IPv6 통신 테스트)
        -   `ping -6 google.com`
        -   `ping -4 8.8.8.8` (IPv4 통신 테스트)
        -   `ping -4 google.com`

-   터미널에서 다음의 명령어로 테스트 서버 생성
    -   <u><b>Python 정적 파일 서버 구동</b></u> : 
        -   `python -m http.server 8080 --bind ::` 해당 코드를 터미널에 입력합니다.
            -   `python -m http.server` : 파이썬 내장 정적 웹 서버 모듈(http.server)을 실행합니다. 다음의 역할을 수행하는 코드가 내장되어 있습니다.
                -   ::에서 IPv6 연결 수신
                -   현재 디렉터리를 웹 루트로 사용
                -   파일 요청 시 해당 파일 반환
                -   / 접근 시 디렉터리 목록 표시
                -   MIME 타입 처리
                -   404 처리
            -   `8080` : 웹 서버가 사용할 포트(Port) 번호를 지정합니다. 기본값(8000) 대신 8080 포트로 요청을 대기합니다
            -   `--bind` : 제한없이 외부접속을 허용합니다. Dual-Stack 으로 IPv6 요청과 IPv4 요청까지 동시에 수신합니다.

    -   <u><b>Javascript 정적 파일 서버 구동</b></u> : 
        -   방법 1: `npx http-server -a :: -p 8081`
            -   npx(Node Package eXecuter)는 Node.js 패키지를 영구적으로 설치하지 않고도 임시 설치 후 실행할 수 있게 해주는 도구입니다. 이를 통해 파이썬 내장 모듈과 같이 간단하게 서버를 열 수 있습니다.
            -   꼭 8080 포트번호에 종속될 필요는 없다는 것을 보이기 위해 8081 포트로 여는 예시 입니다.
        
        -   방법 2: `node -e "require('http').createServer((req,res)=>{console.log('REQUEST');res.end('Hello, World!');}).listen(8081,'::',()=>console.log('Listening on [::]:8081'))"`
            -   단순하지만 외부 패키지 없이 직접 URL 요청에 응답으로 "Hello, World!" 를 보내고 요청처리 시에 터미널 콘솔에 "Listening on [::]:8081" 을 반환하는 서버를 엽니다. 

-   인바운드 테스트, 외부의 접근 수용 확인
    -   모바일 데이터를 킨 휴대폰 등, 외부 인터넷에서 `http://Global IP + 개방한 포트` 로 접근을 시도합니다.

        &nbsp; 예를 들어서, ipconfig 에서 나왔던 Global IP 가 `0000:0000:0000:aaa:0000:0000:0000:0000` 이고 개방한 포트번호가 `8080` 이라면 웹 브라우저에 `http://[0000:0000:0000:aaa:0000:0000:0000:0000]:8080/` 라고 주소창에 입력하면 됩니다.

&nbsp; 모든 테스트 진행이 성공적이라면 이제 컴퓨터를 서버 컴퓨터화 하는 것이 가능합니다.

#### IPv6 방화벽 설정

&nbsp; 접근이 정상적으로 이루어지지 않을 경우에 방화벽 설정을 조정해야합니다.

&nbsp; 접근 포트에 따라 차이가 있지만, 여기선 설명용 예시로 80번 포트라고 하겠습니다. 80번이 http 프로토콜 요청을 의미하는 디폴트 포트이므로 무난합니다.

&nbsp; Windows 방화벽이 외부의 80번 포트 접근을 막지 않도록 설정을 해야합니다.

-   Windows OS GUI 환경에서 제어판에서 조작

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

-   또는 파워쉘(관리자 모드)에서 다음의 명령어로 방화벽 규칙을 조정할 수도 있습니다.

    ```ps1
    # * 방화벽에 TCP 80포트를 개방하는 인바운드 룰 설정
    New-NetFirewallRule `
    -DisplayName "NGINX HTTP 80" `
    -Direction Inbound `
    -Protocol TCP `
    -LocalPort 80 `
    -Action Allow

    # * 방화벽에 적용된 룰 확인
    Get-NetFirewallRule -DisplayName "NGINX HTTP 80"
    ```

## HTTP IP 주소로 연결

이제 본격적으로 서버를 구축합니다.

서버는 다음과 같은 구조로 만들 것 입니다.

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

&nbsp; NGINX 가 네트워크 길목을 지키는 Gatekeeper 로써 앞에서 PC 에 개방한 포트로 <b>SSL 암호화 해제(HTTPS), 정적 이미지 제공, DDoS 방어, 로드 밸런싱 등</b> 들어오는 요청 처리를 맡으며

&nbsp; api 관련 처리를 Express 가 Worker 로써 <b>로그인 인증, DB 조회/수정, 결제 연동 등 복잡한 로직 처리 등</b> 작업을 맡기는 구조입니다.

&nbsp; 이 구조는 전형적으로 많이 쓰이는 서버 구조 입니다.

### NGINX 와 Express 로 분리하는 이유

&nbsp; NGINX 는 웹 서버 및 리버스 프록시(Reverse Proxy) 소프트웨어입니다. 다른 웹 서버 프로그램인 Apache HTTPd 에서 사용하는 요청당 스레드 혹은 프로세스 기반의 구조 대신, 비동기 이벤트 기반의 구조로 작동하는 것이 특징입니다. 이로 인해서 고성능을 자랑하며 서버 부하 시 성능 예측도 쉬워집니다. 사용자가 많은 만큼 여러 서드 파티 기능 모듈이 있기 때문에 기능 확장에도 용이합니다.

&nbsp; Express.js 는 쉽고 빠르게 웹 서버를 만들 수 있게 해주는 가장 인기 있는 웹 프레임워크입니다. 기존의 http 프로토콜 객체를 생성하고 일일히 설정하는 과정이 express 객체를 통해 훨씬 간단해 집니다. 코드는 지금 이해할 필요없고 그냥 express 덕분에 쉬워진다는 것만 보면 됩니다.

-   <table>
    <tr>
    <th>Node.js http</th>
    <th>Express.js</th>
    </tr>
    <td valign="top">

    ```js
    const http = require('node:http');
    const hostname = '127.0.0.1';
    const port = 3000;

    const server = http.createServer((req, res) => {
        res.statusCode = 200;
        res.setHeader('Content-Type', 'text/plain');
        res.end('Hello, World!\n');
    });

    server.listen(port, hostname, () => {
        console.log(`Server running at http://${hostname}:${port}/`);
    });
    ```

    </td>
    <td valign="top">

    ```js
    const express = require('express');
    const hostname = '127.0.0.1';
    const port = 3000;

    const app = express();

    app.get('/', (req, res) => res.send('Hello, World!\n'));
    app.listen(port, hostname, () => console.log(`Server running at http://${hostname}:${port}/`));
    ```

    </td>
    </table>

&nbsp; Nginx 와 Express 로 역할을 분할하는 이유는 Nginx 가 구현할 수 있는 복잡한 비즈니스 로직 및 DB 연동의 한계가 명확하기 때문입니다. 
Nginx 는 본래 서버 설정을 위한 설정 파일으로 JSON 응답이나 헤더 조작은 충분히 감당가능하지만, DB 트랜잭션과 외부 API 등의 처리를 구현하려고 하면 점점 복잡해집니다. 복잡한 작업, 라우터 분리, 미들웨어 패턴, 객체지향/함수형 프로그래밍 스타일 등을 자유롭게 적용할 수 있는 Express 에게 일을 맡기면 편해집니다.

&nbsp; 생태계와 개발 생산성을 위해서도 구분하는 것이 좋습니다. Express는 Node.js 기반의 거대한 npm 생태계를 그대로 활용할 수 있습니다. 인증(Passport.js), 데이터 검증(Joi, Zod), DB 연동(Prisma, Sequelize), 이메일 발송 등 수많은 라리브러리를 몇 줄의 코드로 불러와 바로 사용할 수 있습니다.

&nbsp; 또한 유지보수성과 코드 구조화에도 좋습니다. Nginx 는 읽기 어렵고 테스트나 버전 관리가 힘든 반면, Express는 코드가 커져도 구조화하기 쉽습니다. 웹 연결과 기능처리구현이 분리되어 있기 때문에 DB 연동이나 복잡한 로직을 수정, 추가하더라도 Express 쪽 코드만 신경쓰면 되며, Nginx 설정을 다듬을 필요도 없어집니다.

### Express

#### Express 패키지 설치

&nbsp; 다음의 명령어, 또는 직접 탐색기를 통해서 새 폴더를 만든 뒤에 그 폴더로 이동해주세요.

```bash
mkdir example-server-project
cd example-server-project
```

&nbsp; 예시에선 폴더 이름을 "example-server-project" 라고 만들었으나, 폴더의 이름은 어떻든 상관없습니다. 다만, 특수기호나 한글을 사용할 경우 문제가 생길 수 있습니다. 항상 개발 프로젝트 최상단 루트 폴더의 이름은 띄어쓰기 없이 소문자 영어와 하이픈으로만 만들어주세요.

&nbsp; 지금부터 이 프로젝트 폴더가 위치하는 경로를 `$PROJECT_ROOT` 라고 임시로 부르겠습니다.

&nbsp; node.js 의 npm 을 이용하여 `$PROJECT_ROOT` 에 express 를 설치해주세요. `$PROJECT_ROOT` 에서 터미널을 열고 밑의 npm 명령어를 입력합니다.

-   터미널 명령어

    ```bash
    # npm 패키지 메타데이터 초기화, 패키지 모듈들의 기준점 설정(node_modules 와 package.json)
    npm init -y

    # Express 설치
    npm install express
    ```

#### Express 배포할 HTML 준비

&nbsp; 그 후, 프로젝트 폴더 내에 public 폴더를 만들고, 그 안에 배포하고자 하는 index.html 파일을 넣습니다.

-   public/index.html

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

&nbsp; `$PROJECT_ROOT` 프로젝트 폴더는 <u><b>node 패키지 정보</b></u>와 정적파일들이 담길 <u><b>public 폴더</b></u> 그리고 그 안의 <u><b>index.html 파일</b></u>이 다음과 같은 구조로 위치해있어야 합니다.

```txt
example-server-project/ ($PROJECT_ROOT)
│
├─ node_modules/
├─ public/
│   └─ index.html (방금 만든 html 파일 위치)
│
├─ package.json
└─ package-lock.json
```

#### Express 로컬 테스트

&nbsp; 테스트용 Express 패키지를 사용하는 javascript 코드를 만들어, Express 패키지가 잘 설치됬는지 확인합니다. 

&nbsp; 프로젝트 루트에 `server.js` 파일을 생성하고, 정적 파일을 제공하도록 설정합니다.

-   server.js

    ```js
    // # Node.js + Express 서버 애플리케이션 예시

    // * Express 패키지 참조 오브젝트
    const express = require('express');
    const path = require('path');

    const app = express();
    // * Node.js 서버가 내부적으로 사용할 포트
    const PORT = 3000;

    // ## use

    // * use 는 서버에 요청이 수신된 직후의 동작을 정의하는 미들웨어 부분을 구성합니다. 예를 들어, `app.use((req, res, next) => { console.log('REQUEST'); next(); })` 같은 코드를 작성했을 경우, 클라이언트가 서버에 요청을 보낼 때마다 'REQUEST' 라는 문자열이 콘솔에 출력됩니다.
    // * 참고로 app.use 내부에서 next() 함수는 다음 미들웨어로 요청을 전달하는 역할을 하기 때문에 app.use 를 끝마칠 때는 함수의 return 처럼 필수적으로 작성해야합니다. 만약 next() 함수를 호출하지 않으면, 요청이 다음 미들웨어로 전달되지 않고 응답이 종료되지 않은 상태로 남게 되어 클라이언트는 응답을 받지 못하게 됩니다.

    // * `/public` 폴더를 정적 파일이 위치하는 곳으로 설정합니다. express.static() 함수 내부에 next(); 가 이미 있으므로 생략해도 됩니다.
    app.use(express.static(path.join(__dirname, 'public')));

    // ## get

    // * get 은 요청에 대한 서버의 응답을 정의합니다. express.static 미들웨어는 클라이언트가 기본 경로(/) 로 요청을 보냈을 때, 정적 파일 폴더(public) 내부에서 index.html 파일을 자동으로 찾아서 응답으로 제공하는 기능이 내장되어 있습니다. 따라서 public/index.html 을 응답하는 코드는 굳이 작성할 필요는 없습니다.)

    // app.get('/', (req, res) => {
    //     res.sendFile(path.join(__dirname, 'public', 'index.html'));
    // });

    // ## listen

    // * app.listen 은 서버 애플리케이션이 처음 실행될 때 호출됩니다. 포트 바인딩 (Port Binding, Node.js의 HTTP 모듈을 사용하여 OS에 특정 포트 번호에서 들어오는 네트워크 요청을 이 프로세스(Node.js 서버)가 처리하겠다고 등록)과 서버 시작 (Start Listening, 등록된 포트로 들어오는 모든 TCP/IP 연결 요청을 수신 대기 상태(Listening State)로 전환) 작업을 수행합니다.

    // ### 예시 1. IPv4 루프백(127.0.0.1) 바인딩
    // * 본인 PC(IPv4 Loopback interface, http://127.0.0.1:3000, 또는 http://localhost:3000)에서 내부 요청만 listen 수신을 허용합니다.
    app.listen(PORT, '127.0.0.1', () => console.log(`Server listening on http://127.0.0.1:${PORT}`));

    // ### 예시 2. IPv6 루프백(::1) 바인딩
    // * 본인 PC(IPv6 Loopback interface, http://[0000:0000:0000:0000:0000:0000:0000:0001]:3000 또는 생략문법 http://[::1]:3000, 또는 http://localhost:3000)에서 내부 요청만 listen 수신을 허용합니다.
    app.listen(PORT, '::1', () => console.log(`Server listening on http://[::1]:${PORT}`));
    ```

위 코드에는 express() 의 use, get, listen 에 대하여 설명하는 주석이 많기 때문에 복잡해 보일 수 있습니다. 걱정마시고 결국 설명문만 다지우고 나면 아래 7줄이 전부입니다.

-   server.js

    ```js
    const express = require('express');
    const path = require('path');
    const app = express();
    const PORT = 3000;
    app.use(express.static(path.join(__dirname, 'public')));
    app.listen(PORT, '127.0.0.1', () => console.log(`Server listening on http://127.0.0.1:${PORT}`));
    app.listen(PORT, '::1', () => console.log(`Server listening on http://[::1]:${PORT}`));
    ```

&nbsp; 터미널에 `node server.js` 명령어를 입력하여 서버 코드를 node.js 에서 구동시킵니다.

&nbsp; 이제 웹 브라우저에서 서버가 실행되는 컴퓨터의 내부 주소 `http://localhost:3000` 에 접속하여 페이지가 뜨는지 확인합니다.

&nbsp; <kbd>ctrl</kbd> + <kbd>c</kbd> 를 입력하면 서버를 종료할 수 있습니다.

#### Express 외부망 연결 및 API 테스트

&nbsp; `server.js` 파일을 본격적으로 로컬환경 뿐 아니라 모든 주소에서의 요청(임의의 IPv6 를 의미하는 `::` 와 임의의 IPv4를 의미하는 `0.0.0.0` 로 부터의 요청)을 전부 수신하도록 코드를 수정합니다. 아예 주소 값을 적지 않으면 자동적으로 무조건적으로 서버를 열게됩니다. 위 로컬테스트 코드의 경우처럼 IPv6 와 IPv4 수신을 나누어서 `::` 와 `0.0.0.0` 를 명시해도 똑같습니다.

설명이었던 주석은 정리하고 `/api/` 주소 요청 시의 API 응답 테스트 처리가 추가되었습니다.

&nbsp; 로컬테스트 코드와 마찬가지로 `/` 주소 요청 시에 `public/index.html` 를 반환한다는 내용의 코드 `app.get('/', (req, res) => {res.sendFile(path.join(__dirname, 'public', 'index.html'));});` 는 생략합니다. 별도로 언급하지 않아도 `/` 주소 요청 시에 정적파일 중에서 이름이 index 인 것을 반환하는 것이 관습적으로 기본값이기 때문입니다.

-   server.js

    ```js
    const express = require('express');
    const path = require('path');

    const app = express();
    const PORT = 3000;

    app.use(express.static(path.join(__dirname, 'public')));

    // * API 응답 테스트
    app.get('/api/test', (req, res) => {
        res.json({
            success: true,
            message: 'Express is working'
        });
    });

    app.listen(PORT, () => console.log(`Express server running on port ${PORT}`));
    ```

&nbsp; 내부 테스트와 똑같이 `node server.js` 명령어를 통해서 서버 코드를 node.js 에서 구동시킵니다.

&nbsp; 이제 외부 인터넷망(예를들어, 데이터를 킨 스마트폰에서 구글 웹브라우저에 URL 주소 입력)에서 외부망 인바운드 테스트 때와 같이 `http://Global IP + 개방한 포트` 로 접근을 시도합니다. 

-   인바운드 테스트 때와 같이, ipconfig 에서 나왔던 Global IP 가 `0000:0000:0000:aaa:0000:0000:0000:0000` 이고 이번엔 개방한 포트번호가 `3000` 이므로 웹 브라우저에 `http://[0000:0000:0000:aaa:0000:0000:0000:0000]:3000/` 이라고 주소창에 입력하면 됩니다.

&nbsp; 웹브라우저에 index.html 페이지가 나왔다면 이제 API 테스트를 진행합니다. `http://Global IP + 개방한 포트/api/test` 를 입력하여 요청을 보냅니다. 

-   웹 브라우저가 `{ success: true, message: 'Express is working' }` json 객체 데이터를 서버로 부터 받아왔다면 대성공입니다.

&nbsp; <kbd>ctrl</kbd> + <kbd>c</kbd> 를 입력하면 서버를 종료할 수 있습니다.

### NGINX

#### NGINX 설치

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

#### NGINX 기본 명령어

&nbsp; 터미널에 입력하는 기본적인 명령어는 다음과 같습니다. 처음엔 대충 이런 느낌이라는 것만 확인하고, 필요할 때만 다시 보면 됩니다.

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

#### NGINX 구동 테스트

&nbsp; 계속해서 설명의 편의를 위하여 

-   express 프로젝트 폴더의 경로를 `$PROJECT_ROOT` 라고 부르겠습니다.
-   nginx.exe 가 위치힌 경로를 `$NGINX_HOME` 라고 부르겠습니다.

&nbsp; 위에서 언급 했듯이 nginx 경로가 기억이 안난다면 `where nginx`(cmd 명령어), `where.exe nginx`(powershell 명령어) 를 통해 `$NGINX_HOME` 경로를 찾을 수 있습니다.

&nbsp; `$NGINX_HOME/conf/nginx.conf` 의 server { ... } 부분의 값을 수정하여 웹 서버의 동작 설정을 바꿀 수 있습니다. NGINX 는 기본적으로 C++ 친화적이며, 작업은 .conf 설정 파일 텍스트에 NGINX 지시어(directive) 를 적어서 기능을 조작합니다.

&nbsp; 처음 nginx.conf 파일을 열어보면 다음과 같은 형태입니다.

-   nginx.conf

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

-   nginx.conf

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

-   nginx.conf

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

-   nginx.conf

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

-   index.html

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

-   terminal shell

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

-   terminal shell

    ```bash
    # * 1. nginx.exe 가 위치한 곳에서만 그냥 사용가능
    nginx -s quit

    # * 2. 아무 위치에서나 가능. -Prefix 옵션 적용하여 where.exe nginx 위치 기반으로 conf, log 탐색
    nginx -p "$(Split-Path (where.exe nginx | Select-Object -First 1))" -s quit
    ```

#### NGINX 간단실행 환경 조성

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

&nbsp; 파워쉘에서 `$profile` 를 입력하고 나오는 경로의 파일(일반적으로 `...\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1`)에 다음의 내용을 추가해주세요.

-   Microsoft.PowerShell_profile.ps1

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

### NGINX ⟶ Express 연결

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

#### Express 코드 조정

&nbsp; 먼저 할 일은, `$PROJECT_ROOT` 경로의 javascript 파일(예시에서 server.js 라고 이름붙임) 의 코드를 local 환경에서 api 에만 반응하도록 하는 것입니다. 다른 역할은 NGINX 에게 부여할 것 입니다.

-   server.js

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

#### NGINX 코드 조정

Express 서버가 열려있는 상태에서 NGINX 의 conf 설정 중 html{...} 괄호 안의 `server{...}` 설정을 다음과 같이 변경해주세요.

-   nginx.conf

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

&nbsp; 이 단계는 앞에서 외부망에 본인 IP 주소를 통해 서버 배포에 성공했다는 걸 전제로 진행합니다.

&nbsp; 이번 단계의 목표는 외부 클라이언트에게 컴퓨터 직접적인 IP 주소를 노출하지 않고 DNS 서비스를 통하여 도메인을 경유하고 들어올 수 있도록 하는 것 입니다.

이는 악의적인 공격의 대상이 될 수 있다는 보안 상의 이유와 클라이언트 편의성 문제도 있지만, 상황에 따라 서버 컴퓨터가 바뀌는 등 IP 주소가 바뀌는 일도 있기 때문입니다. IP 주소로만 서비스를 제공한다면 컴퓨터를 새로 장만할 때마다 모든 사용자에게 새 컴퓨터의 IP 를 다시 알려줘야 합니다. 클라이언트는 "www.google.com" 처럼 서비스의 도메인 이름만 알고있으면 접근이 가능한 편이 여러모로 좋습니다.

```txt
클라이언트(외부 인터넷 망 웹브라우저)

DDNS
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

### DNS 사이트에서 도메인 발급받기

&nbsp; 외부에서 도메인 주소 namespace 에 우리들의 개인 IP 주소 매칭시키기 위해선 도메인 관리 기관에 유니크한 도메인 주소를 제시하고 그 도메인 주소의 유지 비용을 지불해야 합니다.

&nbsp; 다행히도 DNS(Domain Name System) 서비스를 무료로 제공하는 경우가 있습니다. 무료 계정에는 제약들이 있지만 본인들의 네임서버(name server)에서 본인들이 할당하고 있는 도메인 주소 공간 안에 있는 URL 에 사용자들의 개인 IP 주소를 연결할 수 있습니다. 여러 무료 사이트 중, 가장 제약이 적고 IPv6 친화적인 Duck DNS 를 사용하겠습니다. API 로 `https://www.duckdns.org/update?domains=『내도메인』&token=『내토큰』&ipv6=『내IPv6』` 같은 IP 주소 매크로 코딩도 편리하여 연습으로 최적화된 DNS 서비스 사이트 입니다.

&nbsp; [Duck DNS 링크](https://www.duckdns.org/) 에 접속하여 로그인을 해주세요.

&nbsp; 로그인을 진행하면 다음과 같은 입력창이 생깁니다.

http:// `sub domain` .duckdns.org <kbd>add domain</kbd>

&nbsp; 여기서 이제까지 없었던, 다른 도메인과 중복되지 않는 sub domain (예시: my-precious-domain, wonderful-service) 을 적고 <kbd>add domain</kbd> 버튼을 누르면 끝입니다. 해당 도메인은 이제 여러분 것 입니다. 1년 넘게 도메인 주소가 동작하지 않고 정지된 경우, 또는 약관 위반 및 범죄 행동과 엮여있을 경우에 개인정보처리방침 약관 차원에서 회원정보 말소와 도메인 주소 회수가 진행될 여지는 있다는 것은 주의해주세요.

&nbsp; 이제 <kbd>add domain</kbd> 버튼을 누르고 나면 해당 주소가 밑의 테이블 표에 추가됬을 것 입니다. 테이블 항목 중, IPv4 주소라면 `current ip` 항목에 IPv6 주소라면 `ipv6` 항목에 기입해주세요.

&nbsp; 앞으로 설명을 위해서 표기를 해야한다면 해당 도메인 주소를 `『MY_DOMAIN』.duckdns.org` 이라고 부르겠습니다.

### NGINX 조정

&nbsp; IPv6 주소만을 그대로 적었는데 그럼 NGINX 에서 포트는 어떻게 받아야 할까요? 사실 앞에 붙은 프로토콜이 이미 디폴트 포트를 가지고 있습니다. 별도로 포트 번호를 적용하지 않았다면 해당 기본 포트로 적용됩니다.

&nbsp; URL 스키마에 약속된 프로토콜에 대한 사항은 다음과 같습니다.

-   <table>
    <tr>
        <th>프로토콜</th>
        <th>기본포트</th>
        <th>포트 생략된 URL 예시</th>
    </tr>
    <tr>
        <td>HTTP</td>
        <td>80</td>
        <td>http://example.com</td>
    </tr>
    <tr>
        <td>HTTPS</td>
        <td>443</td>
        <td>https://example.com</td>
    </tr>
    <tr>
        <td>FTP</td>
        <td>21</td>
        <td>경우에 따라</td>
    </tr>
    <tr>
        <td>SSH</td>
        <td>22</td>
        <td>기본값이므로 클라이언트에 따라 생략</td>
    </tr>
    </table>

TSL 설정을 거치면 `listen [::]:443 ssl; ssl_certificate     ...; ssl_certificate_key ...;` 같은 코드로 NGINX 단계에서도 HTTPS(HTTP + TLS 암호화 계층) 프로토콜 서버로 열 수도 있지만 독자적으로 TLS 인증서와 SSL 보안키를 발급받아야 합니다. 이건 다음 단계에서 다루겠습니다.

&nbsp; 현재는 HTTP 프로토콜로만 서버를 열고 있습니다. 따라서 NGINX 의 conf 값에 다음의 수정이 필요합니다.

-   포트 번호 `80` 에 대하여 개방합니다. 
-   서버명을 `『MY_DOMAIN』.duckdns.org` 라고 명시합니다.

최종적으로 다음과 같은 형태의 코드로 구현됩니다.

```conf
server {
    # HTTP Default 포트넘버로 개방
    listen 80;
    listen [::]:80;

    server_name "『MY_DOMAIN』.duckdns.org"; # <==== ! 여러분의 도메인으로 교체해서 적어야 합니다

    root "$PROJECT_ROOT/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다
    index index.html;

    location / {
        try_files $uri $uri/ /index.html;
    }

    location /api/ {
        proxy_pass http://127.0.0.1:3000;

        proxy_http_version 1.1;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr; 
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }
}
```

Express 와 NGINX 를 기동해주고 웹 브라우저에 도메인 URL 을 입력하여 정상적으로 작동하는 지 확인해주세요.

우리의 목표는 서버가 각 URL 요청에 따라 다음의 응답을 하는 것 입니다.

-   <table>
    <tr class=r0>
    <th>프로토콜 종류</th>
    <th>요청</th>
    <th>응답</th>
    </tr>
    <tr class=r1>
    <th rowspan=2>HTTP</th>
    <td><code>http://『MY_DOMAIN』.duckdns.org</code></td>
    <td>NGINX 가 정적 파일 반환</td>
    </tr>
    <tr class=r2>
    <td><code>http://『MY_DOMAIN』.duckdns.org/api/test</code></td>
    <td>NGINX 가 Express 3000으로 프록시, Express 가 응답</td>
    </tr>
    </table>

## HTTPS 프로토콜 연결

HTTPS 프로토콜은 HTTP 에 TLS 암호화 계층을 넣은 보안처리된 통신 프로토콜입니다.

이를 위해선  TLS 인증서와 SSL 보안키가 필요합니다.

이 인증 발급도 여러 방법이 있으나 여기선 가장 쉬운 win-acme 프로그램을 사용해 HTTP-01 방식으로 Let's Encrypt 인증서를 발급하는 방법을 선택하겠습니다.

Let's Encrypt의 HTTP-01 검증은 반드시 HTTP 프로토콜 디폴트 포트인 TCP 80번 포트를 사용합니다.

HTTP-01 검증은 정적파일 폴더인 프로젝트 루트 폴더의 `public` 에 대하여 `public/.well-known/acme-challenge/특수문자열` 위치에 검사용 특수 파일을 생성하고, 그 뒤에 도메인에 대하여 80 포트 `/.well-known/acme-challenge/특수문자열` 주소로 검사용파일이 있는 지 검사함으로 이 도메인의 권한이 있다는 것을 인증받는 방식입니다.

목표로 하는 구조는 다음과 같습니다.

```txt
외부 클라이언트 PC
       │
       │ "https://『MY_DOMAIN』.duckdns.org"
       ↓
   DuckDNS
       │
       │ AAAA(IPv6) 레코드 매핑
       ↓
 PC Global IPv6
       │
       ├── :80  → nginx (HTTP 프로토콜) Let's Encrypt 인증서 파일
       │
       └── :443 → nginx (HTTPS 프로토콜)
                    │
                    ├───────⟶ index.html 및 정적 파일 ("$PROJECT_ROOT/public")
                    │
                    └─ :3000 → Express (API, JSON 및 계산 데이터)
```

### NGINX 80포트 개방

80 포트에 맞게 동작하도록 nginx.conf 를 맞춰주셔야 합니다.
이제까지 Express 와 NGINX 서버 개발 과정을 따라왔다면 이미 다음과 같은 코드일 것 입니다.

-   nginx.conf

    ```conf
        server {
            listen 80;
            listen [::]:80;

            server_name "『MY_DOMAIN』.duckdns.org"; # <==== ! 여러분의 도메인으로 교체해서 적어야 합니다

            root "$PROJECT_ROOT/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다
            index index.html;

            location / {
                try_files $uri $uri/ /index.html;
            }

            location /api/ {
                proxy_pass http://127.0.0.1:3000;

                proxy_http_version 1.1;
                proxy_set_header Host $host;
                proxy_set_header X-Real-IP $remote_addr; 
                proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
                proxy_set_header X-Forwarded-Proto $scheme;
            }
        }
    ```

위에서 해온 것과 같이 server.js 와 nginx 를 기동하여 서버를 열어주세요.

`『MY_DOMAIN』.duckdns.org` 에서 사이트가 출력되는지 확인해주세요.

### win-acme 설치 및 인증서 발급

[win-acme 공시 홈페이지](https://www.win-acme.com/)

&nbsp; win-acme는 Windows용 ACME(자동 인증서 관리 환경, Automated Certificate Management Environment) 클라이언트입니다. Let's Encrypt 인증서를 발급하고 자동 갱신할 수 있습니다. 현재 공식 문서에서 2.2.9.1을 권장 버전으로 안내하고 있습니다. 우측 상단의 <kbd>DOWNLOAD</kbd> 버튼을 눌러 설치해주세요.

-   설치한 zip 압축 파일을 적절한 곳 (예를 들면, `C:\Program Files\win-acme\v2.2.9.1701`) 에 압축을 해제해주세요.

-   압축해제된 파일 중 `wacs.exe` 를 우클릭하여 <u><b>관리자 권한</b></u>으로 실행해주세요.

    &nbsp; 우리의 목표는 인증서를 .pem 파일로 저장하고 nginx 에서 직접 사용하는 것 입니다.
    win-acme에는 nginx/Apache 등을 위해 『NAME』이름의 Let's Encrypt 인증서를 『name』-crt.pem, 『name』-key.pem, 『name』-chain.pem 같은 구조의 PEM 파일로 저장하는 기능이 있습니다.

    실행되고 나면 터미널 창이 뜨고 다음과 같은 메세지가 출력됩니다.

    ```txt
    ... omitted ...

    N: Create certificate (default settings)
    M: Create certificate (full options)
    R: Run renewals (0 currently due)
    A: Manage renewals (0 total)
    O: More options...
    Q: Quit

    Please choose from the menu:
    ```

-   <u><b>Please choose from the menu:</b></u>

    -   `M` (full options) 을 입력해주세요. 그 후 다음의 선택지가 출력됩니다.

-   <u><b>How shall we determine the domain(s) to include in the certificate?:</b></u>

    -   `2` 를 입력해주세요. 나머지 옵션은...

    -   1: Read bindings from IIS 은 win-acme가 IIS(Internet Information Services)에 등록되어 있는 웹사이트의 도메인을 자동으로 찾아서 인증서에 넣는 방식입니다. IIS 가 아니라 NGINX 에 적용하는 것이 목표이므로 대상이 아닙니다.

    -   3: CSR created by another program 은 CSR(Certificate Signing Request)을 다른 프로그램으로 직접 만들어 놓은 경우 그 CSR을 win-acme에 넘겨서 인증서를 발급받는 방식입니다. 새로 인증서를 만드는 과정이므로 대상이 아닙니다.

    그 후, 다음의 정보를 입력을 요구합니다. 작성해주세요.

-   <u><b>Host:</b></u>
    -   `『MY_DOMAIN』.duckdns.org`
    -   인증서의 대상은 Hostname 이므로 https 를 때고 호스트명만 입력해주세요.

-   <u><b>Friendly name '...'. Enter to accept or type desired name:</b></u>
    -   그냥 `Enter` 키를 입력해주세요.
    -   '...' 이름을 win-acme가 내부 관리용 이름으로 써도 되냐는 질문입니다. 

-   <u><b>Would you like to split this source into multiple certificates?:</b></u>
    -   `4` 번을 입력해주세요.
    -   domain 이나 host, IIS 에 따라서 인증서를 분리할 것인지 확인하는 질문입니다. 단일 인증서만 있으면 됩니다.

-   <u><b>How would you like prove ownership for the domain(s)?:</b></u>
    -   `1` 번을 입력해주세요.
    -   해당 도메인에 challenge 요청에 challenge 응답을 제공하는 HTTP-1 인증 방식 등 여러 방법을 기반으로 해당 도메인을 조작할 권한이 있다는 것을 인증받는 방법에 대한 선택지 입니다. 각 번호의 방법은 다음과 같습니다. 
        -   1번은 challenge 파일을 디스크에 설치하고 정적파일로 응답하는 지를 확인합니다
        -   2번은 디스크에 파일을 저장하는 대신 메모리 위에서 요청-응답만 확인합니다. 
        -   3번은 FTP(S) 원격서버에 Challenge 파일을 업로드합니다. 
        -   4번은 SSH-FTP 원격서버에 Challenge 파일을 업로드합니다. 
        -   5번은 WebDav 원격서버에 Challenge 파일을 업로드합니다.
        -   6번은 DNS-01 인증 방식으로 도메인 메뉴얼 기반으로 인증합니다.
        -   7번은 DNS-01 인증 방식으로 acme-dns 시스템 기반으로 인증합니다.
        -   8번은 DNS-01 인증 방식으로 본인 스크립트 기반으로 인증합니다.
        -   9번은 TLS-ALPN-01이라는 443 포트를 사용하는 인증 방식입니다.

        NGINX 에선 1번이 제일 편합니다.

-   <u><b>Path:</b></u>
    -   `$PROJECT_ROOT/public` 주소를 입력해주세요.
    -   1번 인증방식을 진행하기 위하여 정적파일 경로를 묻습니다. 정적 파일 경로를 지정해주면 ".well-known/acme-challenge/문자열" 에 검사용 파일을 생성하고, "『MY_DOMAIN』.duckdns.org/.well-known/acme-challenge/문자열" URL 에서 요청을 시도합니다. 

-   <u><b>Copy default web.config before validation? (y/n*)</b></u>
    -   `n` 또는 그냥 엔터(*디폴트 값 n)를 입력해주세요.
    -   이 옵션은 원래 IIS(Windows 웹서버) 환경에서 .well-known 디렉터리에 기본 web.config를 복사해서 검증 요청이 제대로 처리되도록 하는 용도입니다. 필요없습니다.

-   <u><b>What kind of private key should be used for the certificate?:</b></u>
    -   `2` (RSA key) 번 옵션을 선택해주세요.
    -   인증서 키 암호화 방식에 대한 선택지입니다. Elliptic Curve key (ECC) 는 인증서/키 처리 효율이 좋은 타원곡선 기반의 키로 최신 TLS 환경에서 사용되는 방식입니다. 다만 최신이라 아직 호환이 안되는 경우가 많습니다. 무난하게 RSA 방식을 채택해주세요.

-   <u><b>How would you like to store the certificate?:</b></u>
    -   `2` (.pem 방식, nginx 나 apache 를 위한 양식) 번 옵션을 선택해주세요.
    -   인증서의 저장 파일 형태에 대한 선택지입니다. nginx 에서 쓸 양식인 .pem 을 선택해야 합니다.

-   <u><b>File path:</b></u>
    -   프로젝트 폴더에 certs 폴더를 생성 후, `$PROJECT_ROOT/certs` 경로를 입력해주세요.
    -   인증서를 어디에 저장할 지에 대한 질문입니다. public 에 넣으시면 그대로 인증서 그대로 외부로 배포되기 때문에 큰일납니다. 인증서(certificate) 를 저장할 폴더 certs 를 별도로 만들어주는 것이 좋습니다.

-   <u><b>Choose from the menu:</b></u>

    -   `1` 번 옵션을 선택해주세요.
    -   개인키 .pem 파일에 비밀번호를 추가하는 옵션입니다. 비밀번호가 있을 경우엔 nginx 가 읽을 때마다 비밀번호를 별도 처리해야하는 문제가 생길 수 있기 때문에 설정하지 않습니다. 대신 개인키 파일이 외부로 공개되지 않도록 조심해 주세요. 

-   <u><b> Would you like to store it in another way too?: </b></u>
    -   `5` 번 옵션을 선택해주세요.
    -   .pem 방식 외에 또 다른 형태로도 저장하겠느냐는 질문입니다. 필요없습니다.

-   <u><b> Which installation step should run first?: </b></u>
    -   `3` 번 옵션을 선택해주세요.
    -   IIS 나 기타 작업의 스크립트 환경을 조성하느냐는 질문입니다. 필요없습니다.

&nbsp; 밑의 3가지 질문은 Let's Encrypt에 사용할 ACME 계정을 만드는 첫번째 시도에만 나옵니다.

-   <u><b> Open in default application? (y/n*) </b></u>
    -   `n` 을 입력해주세요.
    -   Let's Encrypt의 서비스 약관(Terms of Service) PDF를 기본 PDF 뷰어로 열어볼 것인지 묻는 것 입니다.

-   <u><b> Do you agree with the terms? (y*/n) </b></u>
    -   `y` 를 입력해주세요.
    -   Let's Encrypt의 서비스 약관에 동의할 것인지 묻는 단계입니다. 인증서 발급을 위해선 약관 동의가 필요합니다.

-   <u><b> Enter email(s) for notifications about problems and abuse (comma-separated): </b></u>
    -   본인 이메일 주소를 입력해주세요.
    -   인증서 갱신 문제, 중요알림, 인증서 악용 감지등에 대한 중요 알림을 어느 이메일로 보내야하는 지 묻는 질문입니다.

&nbsp; 모든 항목의 답이 끝나면 곧바로 이메일 주소 입력 이후 위에서 지정한 `『MY_DOMAIN』.duckdns.org/.well-known/acme-challenge/특수문자열` 에서 URL 요청을 시도합니다. 엔터 전에 `『MY_DOMAIN』.duckdns.org/` 서버 동작을 미리 한 번 확인해주세요.

### NGINX 를 HTTPS 서버로 전환

&nbsp; 인증서 발급 작업이 완료 되었다면 `『PROJECT_ROOT』/certs` 경로에 도메인 주소 이름이 적힌 4개의 인증서 관련 파일이 형성되어 있을 것 입니다. 각 파일은 다음과 같습니다.

-   `『MY_DOMAIN』.duckdns.org-key.pem` : 개인키
-   `『MY_DOMAIN』.duckdns.org-crt.pem` : 서버 인증서
-   `『MY_DOMAIN』.duckdns.org-chain.pem` : 서버 인증서 + 인증서 체인
-   `『MY_DOMAIN』.duckdns.org-chain-only.pem` : 인증서 자체를 제외한 체인

이 파일 중, 인증서 체인 파일과 개인키를 사용하게 됩니다.

인증서 발급까지는 끝났으니, 이제 nginx를 HTTPS 서버로 전환하겠습니다.

```txt
HTTPS 요청
https://.duckdns.org
        │
        ▼
DuckDNS → 내 PC의 IPv6
        │
        ▼
nginx :443 (TLS 종료)
        │
        ├── /              → 정적 파일
        │
        └── /api/...       → Express :3000
```

현재 NGINX 의 server 블록은 80번 포트에서 HTTP(80포트)만 처리하고 있으므로, HTTPS 요청을 수신할 새로운 `server{...}` 블록을 새로 추가해 주겠습니다.

무시해도 되는 부분은 ... omitted(생략함)... 표현으로 생략하겠습니다. 정말로 저렇게 적으라는 뜻이 아닙니다.

-   nginx.conf

    ```conf
    ... omitted ...

    events {
        ... omitted ...
    }

    http {

        ... omitted ...

        # ## HTTP Server block ================================
        server {
            listen 80;
            listen [::]:80;

            server_name "『MY_DOMAIN』.duckdns.org"; # <==== ! 여러분의 도메인으로 교체해서 적어야 합니다
            root "『PROJECT_ROOT』/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다

            location / {
                try_files $uri $uri/ /index.html;
            }

            location /api/ {
                proxy_pass http://127.0.0.1:3000;

                proxy_http_version 1.1;
                proxy_set_header Host $host;
                proxy_set_header X-Real-IP $remote_addr;
                proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
                proxy_set_header X-Forwarded-Proto $scheme;
            }
        }

        # ## HTTPS Server block ===============================
        server {
            listen 443 ssl;
            listen [::]:443 ssl;

            server_name "『MY_DOMAIN』.duckdns.org"; # <==== ! 여러분의 도메인으로 교체해서 적어야 합니다
            root "『PROJECT_ROOT』/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다

            ssl_certificate "『PROJECT_ROOT』/certs/『MY_DOMAIN』.duckdns.org-chain.pem" # <==== ! 프로젝트 경로와 도메인으로 교체해서 적어야 합니다
            
            ssl_certificate_key "『PROJECT_ROOT』/certs/『MY_DOMAIN』.duckdns.org-key.pem" # <==== ! 프로젝트 경로와 도메인으로 교체해서 적어야 합니다

            location / {
                try_files $uri $uri/ /index.html;
            }

            location /api/ {
                proxy_pass http://127.0.0.1:3000;

                proxy_http_version 1.1;
                proxy_set_header Host $host;
                proxy_set_header X-Real-IP $remote_addr;
                proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
                proxy_set_header X-Forwarded-Proto $scheme;
            }
        }
    }
    ```

&nbsp; nginx.exe 가 위치한 곳에서 `nginx -t` 로 문법 검사를 시행하고 `nginx -s reload` 로 빠른 재시작이 가능합니다.

이제 웹브라우저에서 `https://『MY_DOMAIN』.duckdns.org/` 접속을 확인해보세요. 웹페이지가 출력되었다면 성공입니다.

만약 잘 되지 않았을 경우, 다음을 확인해주세요.

-   1)  문법적으로 `server{...}` 블록을 추가하는 과정에서 실수가 있었을 수 있습니다.

    &nbsp; nginx.exe 가 위치한 곳에서 `nginx -t` 명령어를 입력하면 `nginx.conf` 설정파일이 정상적인지 검사합니다. 코드 오류를 수정했다면 `nginx -s reload` 로 빠른 재시작이 가능합니다.

-   2)  처음 시작할 때에 방화벽 서버 테스트 때와 비슷하게 방화벽이 443 포트 접근을 막고있을 수 있습니다. 인바운드 규칙을 추가해주면 해결됩니다.

    -   node 와 nginx 에 대한 규칙이 있는지 확인하는 파워쉘 명령어

        ```ps1
        Get-NetFirewallRule -PolicyStore ActiveStore `
            -Enabled True `
            -Direction Inbound `
            -Action Allow |
            Where-Object {
                $_.DisplayName -match "nginx|node"
            } |
            Format-List DisplayName, Name, Description, PolicyStoreSource, PolicyStoreSourceType
        ```

        또는

        ```ps1
        # * 1. 활성화된 인바운드 허용 규칙 조회
        $rules = Get-NetFirewallRule -PolicyStore ActiveStore `
            -Enabled True `
            -Direction Inbound `
            -Action Allow

        # * 2. nginx 또는 node 실행 파일에 연결된 규칙만 추출
        $result = foreach ($rule in $rules) {

            $app = $rule | Get-NetFirewallApplicationFilter

            if ($app.Program -match '(?i)nginx|node') {

                $port = $rule | Get-NetFirewallPortFilter

                [PSCustomObject]@{
                    Name       = $rule.DisplayName
                    Program    = $app.Program
                    Profile    = $rule.Profile -join ","
                    Protocol   = $port.Protocol -join ","
                    LocalPort  = $port.LocalPort -join ","
                    RemotePort = $port.RemotePort -join ","
                }
            }
        }

        # * 3. 결과 출력
        $result | Format-Table -AutoSize
        ```

    -   443 포트에 관한 규칙이 있는지 확인하는 파워쉘 명령어

        ```ps1
        Get-NetFirewallRule -Enabled True | Get-NetFirewallPortFilter | Where-Object {$_.Protocol -eq "TCP" -and $_.LocalPort -eq 443}
        ```

    -   443 포트에 관한 접근허용 규칙을 추가하는 파워쉘 명령어

        ```ps1
        New-NetFirewallRule `
            -DisplayName "NGINX HTTPS 443" `
            -Direction Inbound `
            -Protocol TCP `
            -LocalPort 443 `
            -Action Allow
        ```

### NGINX HTTP 서버 정리

이제 HTTPS 보안 프로토콜에 의한 요청만 받을 것이지만 HTTP 로 들어온 요청에 무응답하는 것은 "s" 한글자 생략한 클라이언트에게 불쾌감을 줄 수 있습니다. 따라서 HTTP 요청은 HTTPS 로 리다이렉트(다른 URL 주소로 넘겨주는 작업)하도록 바꿀 것 입니다.

또한, Let's Encrypt 인증서는 유효 기간이 지나가면 동작하지 않으므로 win-acme 프로그램이 자동으로 갱신 작업을 진행합니다. HTTP-01 방법으로 자동으로 재시도하기 때문에 80 포트는 열려있어야 합니다. 동시에 HTTP-01 검증 파일 인증 방식에 사용되는 `/.well-known/acme-challenge/` url 접근의 경우 HTTPS 로 리다이렉트 해선 안되기에 예외 상황을 작성해 주어야 합니다. 

우리의 목표는 서버가 각 URL 요청에 따라 다음의 응답을 하는 것 입니다.

-   <table>
    <tr class=r0>
    <th>프로토콜 종류</th>
    <th>요청</th>
    <th>응답</th>
    </tr>
    <tr class=r1>
    <th rowspan=2>HTTP</th>
    <td><code>http://『MY_DOMAIN』.duckdns.org/...</code></td>
    <td>HTTPS 주소로 301 이동</td>
    </tr>
    <tr class=r2>
    <td><code>http://『MY_DOMAIN』.duckdns.org/.well-known/acme-challenge/...</code></td>
    <td>HTTP 로 NGINX 가 검증 파일을 응답</td>
    </tr>
    <tr class=r3>
    <th rowspan=2>HTTPS</th>
    <td><code>https://『MY_DOMAIN』.duckdns.org/...</code></td>
    <td>NGINX 가 정적 파일 반환</td>
    </tr>
    <tr class=r4>
    <td><code>https://『MY_DOMAIN』.duckdns.org/api/...</code></td>
    <td>NGINX 가 Express 3000으로 프록시, Express 가 응답</td>
    </tr>
    </table>

따라서 HTTP 서버 블록만 다음과 같이 수정해주시면 됩니다.

```conf
# ## HTTP Server block ================================
server {
    listen 80;
    listen [::]:80;

    server_name "『MY_DOMAIN』.duckdns.org"; # <==== ! 여러분의 도메인으로 교체해서 적어야 합니다

    root "$PROJECT_ROOT/public"; # <==== ! 프로젝트 경로로 교체해서 적어야 합니다

    # * Let's Encrypt HTTP-01 검증 경로는 HTTP로 직접 응답
    # * ^~ 은 매칭 우선순위를 지정하는 NGINX 문법. 다른 location 정규식보다 먼저 실행됨
    location ^~ /.well-known/acme-challenge/ {
        try_files $uri =404;
    }

    # * 그 외 모든 HTTP 요청은 https:// 로 리다이렉트
    location / {
        return 301 https://$host$request_uri;
    }
}
```

## DB 와 연결

&nbsp; 이제 API url 이 실제로 DB 의 데이터를 조작할 수 있도록 만들어봅시다. 

```txt
외부 클라이언트 PC
       │
       │ "https://『MY_DOMAIN』.duckdns.org"
       ↓
   DuckDNS
       │
       │ AAAA(IPv6) 레코드 매핑
       ↓
 PC Global IPv6
       │
       ├── :80  → nginx (HTTP 프로토콜) Let's Encrypt 인증서 파일
       │
       └── :443 → nginx (HTTPS 프로토콜)
                    │
                    ├────────⟶ index.html 및 정적 파일 ("$PROJECT_ROOT/public")
                    │
                    └─ :3000 ⟶ Express (API, JSON 및 계산 데이터)
                                  │
                                  └─ :5432 ⟶ PostgreSQL (DB, 정보 저장소)
```

### PostgreSQL

&nbsp; 이 예제에선 PostgreSQL 을 선택합니다. 많이 사용되는 mySQL 도 좋지만 새로 배우는 입장이라면 1순위로 추천받는 DB 프로그램 입니다. 오픈 소스 ORDBMS(DataBase Management System)로 쓰기도 편합니다.

&nbsp; PostgreSQL은 단순한 CRUD 작업 뿐 아니라 상당히 복잡한 데이터 구조까지 다룰 수 있습니다.

&nbsp; Prisma에서도 PostgreSQL을 공식적으로 지원하고 있으며 Neon, Supabase 같은 PostgreSQL 계열 서비스도 지원합니다.

#### PostgreSQL 설치

[공식 다운로드 링크](https://www.postgresql.org/download/windows/) 에서 설치할 수 있습니다.

최신 정식 메이저 버전인 PostgreSQL 18 버전을 설치하면 됩니다.

어지간한 부분은 모두 기본설정 따라서 확인하고 넘어가도 됩니다.

-   설치 구성 요소로 다음의 항목들을 필수로 선택해야 합니다.

    -   PostgreSQL Server
    -   pgAdmin 4
    -   Command Line Tools

-   포트번호는 디폴트가 5432 입니다. 그대로 쓰면 됩니다. 
    -   참고로 포트는 열려있어 localhost:5432 요청을 보낼 순 있으나 응답하지 않습니다. PostgreSQL 은 HTTP 통신 프로토콜을 따르지 않으며 데이터베이스 전용 통신 규약(PostgreSQL Wire Protocol)을 사용합니다.

-   관리자 계정 비밀번호는 앞으로 DB 생성 관리 시에 꼭 필요하니 분실하시면 안됩니다.

설치 후, 추가 패키지 설치를 돕는 Stack Builder 가 켜지나 지금은 필요없으니 그냥 닫아 주세요.

설치가 끝났다면, 파워쉘(관리자)에서 다음의 명령어를 입력하여 postgresSQL 이 성공적으로 서비스 중인지 확인할 수 있습니다.

-   powershell

    ```ps1
    Get-Service *postgres*
    ```

#### PostgreSQL 자동 실행 해제 및 종료

&nbsp; DB 는 항상 데이터를 관리하는 것을 상정하기 때문에, Windows 서비스(Service)로 등록되어, 컴퓨터를 켤 때 자동으로 실행되도록 설정되는 경우가 많습니다.

&nbsp; 서버 컴퓨터라면 그것이 맞습니다만, 그것이 아니라면 DB 작업을 수행하지 않을 때에도 백그라운드에서 컴퓨터 자원을 소모하는 것이 불쾌할 수 있습니다.

밑의 방법으로 자동실행을 해제하고, 끄고 킬 수 있습니다.

우선 `관리자 모드` 로 파워쉘을 실행해주세요.

-   PostgreSQL 정확한 서비스 이름 확인하기

    ```ps1
    # 심플하게 이름만 보기
    Get-Service *postgres*
    
    # 자동실행타입까지 출력하기
    Get-Service *postgresql* | Select-Object Name, Status, StartType
    ```

    다음 명령어로 정확한 서비스 명이 출력됩니다. 이 서비스 명을 복사해서 사용하면 됩니다. 여기선 예시로 `postgresql-x64-18` 라고 하겠습니다.

-   PostgreSQL 자동실행 해제하기

    ```ps1
    # StartType 을 Automatic 에서 Manual 로 변경
    Set-Service -Name "postgresql-x64-18" -StartupType Manual
    ```

-   PostgreSQL 실행하기

    ```ps1
    Start-Service -Name "postgresql-x64-18"
    ```

-   PostgreSQL 종료하기

    ```ps1
    Stop-Service -Name "postgresql-x64-18"
    ```

#### pgAdmin 4 열기

&nbsp; pgAdmin 은 PostgreSQL 을 GUI 로 관리할 수 있는 프로그램입니다. MySQL 의 MySQL Workbench 같은 도구입니다.

&nbsp; 윈도우즈 시작에서 `pgAdmin 4` 을 검색해서 구동하거나, 또는 PostgreSQL 설치 폴더 디렉터리 기준으로 `.../PostgreSQL/『VERSION_NUMBER』/pgAdmin 4/runtime/pgAdmin4.exe` 을 직접 찾아서 구동할 수 있습니다. 구동해주세요.

&nbsp; 좌측 사이드바 Object Explorer 에서 "Servers" → "PostgreSQL 18" 를 선택해주세요. 이 과정에서 관리자 비밀번호를 요구할 것 입니다. 관리자 권한으로 잠금을 해제하면 밑과 같이 전개됩니다.

-   Object Explorer

    ```txt
    Servers
    └─ PostgreSQL 18
        │
        ├─ Databases
        ├─ Login/Group Roles
        └─ Tablespaces
    ```

&nbsp; 설치된 "PostgreSQL 18" 밑에 설치시에 자동으로 생성되는 기본 시스템 DB 인 `Databases → postgres`, 최고 관리자 계정 `Login/Group Roles → postgres` 가 확인됩니다. 이들은 삭제하거나 조작하지 않는 것을 권장합니다.

&nbsp; 우측 상단 탭에는 SQL 정보를 보여주는 "Dashboard", "Properties", "SQL", "Statistics", "Dependencies", "Processes" 등의 탭이 기본적으로 띄워져 있습니다. 지금은 불필요하니 무시해도 됩니다.

#### Query Tool 로 DB 조작

-   Query Tool 열기

    &nbsp; 좌측 사이드바 Object Explorer 에서 "Servers" → "PostgreSQL 18" → "Databases" → "postgres" 를 선택해주세요.

    &nbsp; "postgres" 를 마우스 우클릭 후, `Query Tool` 을 선택해주세요.

    &nbsp; SQL(Structured Query Language, 구조화된 질의 언어)을 입력할 수 있는 편집기가 열립니다. 쿼리를 입력하고 우측 상단 재생모양 삼각형을 누르면 명령을 실행합니다.

-   DB 테이블 용 계정 만들기

    &nbsp; DB 관리자 계정을 서버에 올려버리는 것 만큼 위험한 행동이 없습니다.

    &nbsp; 다음의 쿼리로 Express가 PostgreSQL에 접속할 때 사용할 계정을 따로 만들어주세요.

    ```sql
    CREATE ROLE myapp_user
    WITH LOGIN PASSWORD '****'; -- <==== ! 적당히 좋은 비밀번호로 교체해서 적어주세요.
    ```

    &nbsp; 이 비밀번호는 노출되지 않도록 server.js 코드에 직접 적지 않습니다. 다음 단계에서 환경변수로 관리하겠습니다. 기억해주세요.

    &nbsp; 생성된 역할(Role)은 GUI 로 Object Explorer 에서 "Servers" → "PostgreSQL 18" → "Login/Group Roles" 에서 확인할 수 있습니다. 보이지 않을 경우, 우클릭 후에 <kbd>Refresh</kbd> 를 클릭하면 새로고침을 하면 볼 수 있습니다.

    &nbsp; 물론 다음의 쿼리로도 계정을 검색하고 삭제할 수 있습니다. 알아만 두세요.

    ```sql
    -- * 계정 검색
    SELECT *
    FROM pg_roles
    WHERE rolname = 'myapp_user';

    -- * 계정 삭제
    DROP ROLE myapp_user;
    ```

-   DB 생성하기

    &nbsp; 다음의 쿼리로 DB를 만들어주고 방금 만든 계정에게 소유권을 줍니다.

    ```sql
    CREATE DATABASE myapp
    OWNER myapp_user;
    ```

    &nbsp; 생성된 DB 는 GUI 로 Object Explorer 에서 "Servers" → "PostgreSQL 18" → "Databases" 에서 확인할 수 있습니다. 보이지 않을 경우, 우클릭 후에 <kbd>Refresh</kbd> 를 클릭하면 새로고침을 하면 볼 수 있습니다.

#### API 에 사용할 Table 만들기

&nbsp; Role(정보창고의 책임자) 과 Database(정보 창고) 를 생성하였으니 이제 본격적으로 Express API 요청에 넘겨줄 데이터를 만들어보겠습니다. 목표는 사용자들의 username, e-mail, password, score 데이터를 저장하는 것입니다. 이를 통해 로그인 시도 요청이 오면 저장된 비밀번호와 대조하여 `로그인 성공 여부`를 알려줄 수 있습니다. 또한 페이지에서 사용자들의 점수를 비교하여 `순위표를 출력`할 수도 있습니다.

-   계정 변경하기

    &nbsp; 현재 계정은 PostgreSQL 전체 관리자 "postgres" 상태입니다. "myapp_user" 로 DB 를 다루어야합니다.
    
    &nbsp; 현재 DB는 "postgres" DB 의 Query tool 입니다. "myapp" DB 에서 Query 를 다루어야 합니다.

    &nbsp; 다음 쿼리로 확인해볼 수 있습니다.

    ```sql
    SELECT
        current_database(),
        current_user;
    ```

    &nbsp; PostgreSQL 은 테이블을 생성한 측이 접근 권한을 가지므로 "myapp_user" 계정으로 새로운 접속을 만들겠습니다.

    &nbsp; 가장 쉬운 방법은 Query Tool 상단 주소창처럼 생긴 current connection 창을 클릭하여 `< New Connection... >` 을 선택하고 필요한 값들을 입력해주면 됩니다. 이는 매번 Query Tool 을 닫고 열때마다 다시 이 작업을 해야하니 귀찮을 수 있습니다.

    &nbsp; 또 다른 방법은 PostgreSQL 과의 연결 자체를 새로 하나 더 만드는 것 입니다.

    &nbsp; pgAdmin 왼쪽 Object Explorer 에서 "Servers" 를 우클릭하고 "Register" → "Server..." 를 선택해주세요. 연결에 대한 설정값을 적은 "Register-Server" 창이 등장합니다.

    &nbsp; "Register-Server" 창의 General 탭에서 Name 항목에 `PostgreSQL 18 - myapp_user` 같이 지금 연결의 적당한 이름을 적어주세요.

    &nbsp; "Register-Server" 창의 Connection 탭에서 각 항목의 값을 입력해주세요.

    -   <table>
        <tr>
        <td>Host name/address</td>
        <td><code>localhost</code></td>
        </tr>

        <tr>
        <td>Post</td>
        <td><code>5432</code></td>
        </tr>

        <tr>
        <td>Maintenance database</td>
        <td><code>myapp</code></td>
        </tr>

        <tr>
        <td>Username</td>
        <td><code>myapp_user</code></td>
        </tr>

        <tr>
        <td>Password</td>
        <td><code>『PASSWORD』</code></td>
        </tr>

        <tr>
        <td>Save password?</td>
        <td><code>Save</code></td>
        </tr>
        </table>

    생성 후엔 좌측 사이드바 Object Explorer 에 새로운 연결 "PostgreSQL 18 - myapp_user" 를 볼 수 있습니다.

    -   Object Explorer

    ```txt
    Servers
    ├─ PostgreSQL 18
    └─ PostgreSQL 18 - myapp_user
        │
        └─ Databases
            └─ myapp
    ```

    &nbsp; 이제 여기서 "Servers" → "PostgreSQL 18 - myapp_user" → "Databases" → "myapp" 에서 우클릭하여 `Query Tool` 을 새로 열면 우리가 원하는 role 로 연결을 가진 Query Tool 창이 뜹니다. 

-   관리자 & 테이블 관련 쿼리 명령어 모음

    &nbsp; 다음의 명령어들을 응용으로 사용할 수도 있습니다. 알아만 두고 넘어갑시다.

    ```sql
    -- * 현재『DB_NAME』와 『DB_NAME』 소유주와 현재『ROLE_NAME』 을 확인
    SELECT
        current_database() AS database_name,
        pg_get_userbyid(datdba) AS database_owner,
        current_user
    FROM pg_database
    WHERE datname = current_database();

    -- * 유효한 모든 테이블의 『TABLE_NAME』 확인
    SELECT schemaname, tablename 
    FROM pg_tables 
    WHERE schemaname NOT IN ('pg_catalog', 'information_schema');

    -- * 『TABLE_NAME』과 『TABLE_NAME』 의 소유주를 확인
    SELECT schemaname, tablename, tableowner
    FROM pg_tables
    WHERE tablename = '『TABLE_NAME』';

    -- * 『DB_NAME』의 소유자를 『ROLE_NAME』 로 변경
    ALTER DATABASE 『DB_NAME』 OWNER TO 『ROLE_NAME』;

    -- * 『TABLE_NAME』의 소유자를 『ROLE_NAME』 로 변경
    ALTER TABLE public.『TABLE_NAME』 OWNER TO 『ROLE_NAME』;

    -- * 『TABLE_NAME』의 소유자 변경없이 『ROLE_NAME』 에게 조회권한 부여
    GRANT SELECT
    ON TABLE public.『TABLE_NAME』
    TO 『ROLE_NAME』;

    -- * 『DB_NAME』의 소유자 변경없이 『ROLE_NAME』 에게 접근권한 부여
    GRANT CONNECT, CREATE, TEMPORARY
    ON DATABASE 『DB_NAME』
    TO 『ROLE_NAME』;

    -- * 『DB_NAME』의 소유자 변경없이 『ROLE_NAME』 에게 접근권한 제거
    REVOKE CONNECT, CREATE, TEMPORARY
    ON DATABASE 『DB_NAME』
    FROM 『ROLE_NAME』;
    ```

-   Table 만들기
    
    &nbsp; "username | email(PK) | password | score" 형태의 테이블을 만들어줍시다. 
    
    &nbsp; 데이터 색적에 사용되는 대표값 기본키(primary key)는 email 로 잡아주는 것이 좋습니다.

    &nbsp; password 는 보안을 위하여 비밀번호 원문이 아닌 암호화된 해시값만을 기록하는 것이 좋습니다.

    &nbsp; 다음의 쿼리를 실행시켜 user 라는 테이블을 만들어 주세요.

    ```sql
    CREATE TABLE users (
        username      VARCHAR(50) NOT NULL,
        email         VARCHAR(255) PRIMARY KEY,
        password_hash TEXT NOT NULL,
        score         INTEGER NOT NULL DEFAULT 0
    );
    ```

    &nbsp; GUI 상에선 Object Explorer 에서 "Servers" → "PostgreSQL 18" → "Databases" → "myapp" → "Schemas" → "public" → "Tables" → `users` 에 표시 됩니다.

    &nbsp; 쿼리를 통한 테이블 확인은 위의 관리자 & 테이블 관련 쿼리 명령어 모음집을 확인해주세요.

-   Table 동작 확인

    &nbsp; SQL 기본 동작인 INSERT(입력), SELECT(출력), ORDER BY(정렬) 을 확인해봅니다.

    &nbsp; "users" 테이블에 테스트 데이터를 넣고 데이터를 검색하는 과정을 진행하겠습니다.

    &nbsp; 밑의 쿼리를 실행하여 테스트 데이터 3개를 테이블에 넣어주세요.

    ```sql
    INSERT INTO users
        (username, email, password_hash, score)
    VALUES
        ('Alice', 'alice@example.com', 'test_hash', 100),
        ('Bob', 'bob@example.com', 'test_hash', 250),
        ('Charlie', 'charlie@example.com', 'test_hash', 180);
    ```

    &nbsp; 밑의 쿼리를 실행하여 테이블의 모든 테이터를 출력받아 보세요.

    ```sql
    SELECT *
    FROM users;
    ```

    &nbsp; 밑의 쿼리를 실행하여 테이블의 유저를 score 내림차순으로 정렬한 표를 출력받아 보세요.

    ```sql
    SELECT username, score
    FROM users
    ORDER BY score DESC;
    ```

### Express → PostgreSQL

&nbsp; 이제 Express 측에서 5432 포트로 PostgreSQL 18 측으로 쿼리를 요청하고, 데이터를 응답받는 코드를 추가해주겠습니다. 전체 구조에서 윗 부분은 생략하고 server.js 파일의 Express 코드에 집중합시다. 

```txt
외부 클라이언트 PC
       │
       │ "https://『MY_DOMAIN』.duckdns.org"
       ┆

       ┆
    omitted(생략)
       ┆

       ┆
       └─ :3000 ⟶ Express (API, JSON 및 계산 데이터)
                      │
                      └─ :5432 ⟶ PostgreSQL (DB, 정보 저장소)
```

#### Node.js PostgreSQL 드라이버 패키지 설치

Node.js 에서 DB 를 조작하고, 개발자 계정 비밀번호를 프로젝트 빌드 외부 .env 파일로 격리시키고, 비밀번호 등 민감정보를 암호화하기 위해 다음의 패키지가 필수적으로 필요합니다.

-   `pg` : Node.js 에서 PostgreSQL 에 접근하여 SQL 를 실행시킴
-   `dotenv` : .env 파일 내부 환경변수를 읽음
-   `bcrypt` : 비밀번호를 해시 암호화하여 저장하고 검증함.

프로젝트 루트 폴더 `$PROJECT_ROOT` 에서 다음의 명령어로 node 패키지를 설치해주세요. 

-   terminal shell

    ```bash
    npm install pg dotenv bcrypt
    ```

##### 경고 출력 시

설치가 끝난 이후에 bcrypt 에 대하여 다음과 같은 경고가 출력될 수 있습니다.

-   terminal shell

    ```bash
    found 0 vulnerabilities
    npm warn install-scripts 1 package has install scripts not yet covered by allowScripts:
    npm warn install-scripts   bcrypt@6.0.0 (install: node-gyp-build)
    npm warn install-scripts
    npm warn install-scripts Run `npm install-scripts ls` to review, or `npm install-scripts approve <pkg>` to allow.
    ```

이는 bcrypt 가 네이티브 스크립트 구동을 하기 때문입니다. 이런 경우 악의적인 코드가 있을 수 있기 때문에 npm 측에서 검토 승인 없이는 동작을 허용하지 않습니다.

`npm install-scripts ls` 명령어를 입력하면 설치된 스크립트 구동 허용 상태를 확인할 수 있습니다.

`npm install-scripts approve 『패키지이름』` 명령어로 설치된 스크립트의 독자적인 실행을 허용할 수 있습니다. `deny` 로 불허할 수도 있습니다.

bcrypt 는 실행해도 안전하기 때문에 승인하셔도 괜찮습니다. 다음의 명령어로 동작을 허가해주세요.

-   terminal shell

    ```bash
    npm install-scripts approve bcrypt
    ```

bcrypt 가 정상적으로 동작하는지 확인하기 위해, bcrypt 구동 텍스트를 실행해볼 수 있습니다. 다음의 실행 텍스트에는 "test-string" 이라는 문자열을 해시함수에 넣어 암호화 하는 코드가 적혀있습니다.

```bash
node -e "const bcrypt = require('bcrypt'); console.log(bcrypt.hashSync('test-string', 10));"
```

#### DB 조작용 필요 파일 생성

&nbsp; 프로젝트 루트 폴더 `$PROJECT_ROOT` 에서 

-   <u><b>.env</b></u>
-   <u><b>db.js</b></u> 

&nbsp; 파일을 추가로 생성해주세요.

```txt
example-server-project/ ($PROJECT_ROOT)
│
├─ certs/
├─ node_modules/
├─ public/
│   └─ index.html (방금 만든 html 파일 위치)
│
├─ .env   <======== 새로 생성!
├─ db.js  <======== 새로 생성!
├─ package.json
├─ package-lock.json
└─ server.js
```

#### .env 환경변수 작성

&nbsp; .env 로 환경변수화 시킴으로 프로젝트 코드 내에서는 민감한 정보들이 직접적으로 기록되지 않게 만듭니다.

&nbsp; 만약에 git 프로젝트로 진행하고 있을 경우에는 <u><b>.gitignore</b></u> 파일을 생성하고 node_modules/ 과 .env 파일을 git 에서 제외할 것을 명시해야합니다.

&nbsp; .env 파일 내에 DB 관련 환경변수들을 적어주세요. 

-   .env

    ```env
    DB_HOST=127.0.0.1
    DB_PORT=5432
    DB_NAME=myapp
    DB_USER=myapp_user
    DB_PASSWORD=『PASSWORD』 # <==== ! DB 계정 비밀번호로 교체해서 적어야 합니다

    SERVER_PORT=3000
    ```

#### DB 연결 모듈화

&nbsp; .env 에 작성한 환경변수는 `require('dotenv').config();` 외부 모듈을 불러온 후에 process.env.『환경변수명』으로 사용할 수 있습니다.

&nbsp; db.js 에는 DB 와 연결을 재사용하기 위한 연결 풀(Connection Pool) 코드를 작성합니다.

&nbsp; API 요청이 들어올 때마다 매번 새로운 PostgreSQL 연결을 만들기보다는, 기존 연결을 효율적으로 재사용할 수 있습니다.

&nbsp; `module.exports = pool` 로 다른 JavaScript 파일에서 이 연결 풀을 사용할 수 있도록 모듈화하여 내보냅니다.

-   db.js

    ```js
    require('dotenv').config();

    const { Pool } = require('pg');

    const pool = new Pool({
        host: process.env.DB_HOST,
        port: Number(process.env.DB_PORT),
        database: process.env.DB_NAME,
        user: process.env.DB_USER,
        password: process.env.DB_PASSWORD,

        max: 10,
        idleTimeoutMillis: 30000,
        connectionTimeoutMillis: 5000,
    });

    module.exports = pool;
    ```

&nbsp; 이제 외부 javascript 코드는 `const pool = require('./db');` 같은 선언을 통해 db.js 모듈을 불러와서 사용할 수 있습니다. 예시와 같이 `pool` 이라 모듈이름을 선언하였다면, 매번 연결을 요청할 때마다 새로 작성할 필요 없이 `const result = await pool.query('SELECT NOW() AS server_time');` 비동기 요청으로 DB 에 연결하여 쿼리 명령을 보낼 수 있습니다.

#### Express 측 DB 연결 코드

&nbsp; NGINX 에서 `localhost:3000/api/test` 로 접근할 수 있던 API 테스트 코드를 이제 실제로 DB 연결이 정상적으로 이루어졌는지 확인하고 결과를 응답하는 코드로 수정하겠습니다.

&nbsp; API TEST 코드를 기반으로 javascript 의 비동기 제어 방식인 `async () { await }` 를 사용하는 방법과 우리가 직접 만든 모듈 pool 을 어떤 식으로 사용하는 지 확인해보세요. 

-   server.js

    ```js
    require('dotenv').config(); // * .env 파일에서 환경 변수 injection

    const express = require('express');
    const bcrypt = require('bcrypt'); // * 비밀번호 해싱을 위한 bcrypt 모듈
    const pool = require('./db'); // * PostgreSQL 연결 풀 모듈

    const app = express();
    const PORT = Number(process.env.SERVER_PORT) || 3000; // * 포트번호를 코드에 공개하지 않고 .env 에 은닉, 없을 시엔 기본값 3000 사용

    app.set('trust proxy', 'loopback');

    app.use(express.json({ limit: '10kb' })); // * JSON 요청을 파싱할 때, 최대 크기를 10kb로 제한

    app.use((req, res, next) => {
        console.log('REQUEST');
        next();
    });

    // * GET :: /api/test :: PostgreSQL 연결 테스트
    app.get('/api/test', async (req, res) => {
        try {
            const result = await pool.query('SELECT NOW() AS server_time');

            res.json({
                success: true,
                message: 'Express + PostgreSQL is working',
                databaseTime: result.rows[0].server_time,
            });
        } catch (err) {
            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Database connection failed',
            });
        }
    });

    app.listen(PORT, '127.0.0.1', () => {
        console.log(`Express server running on port ${PORT}`);
    });
    ```

이제 

-   5432 포트에 postgreSQL DB가 `start-service postgresql-x64-18` 터미널 명령어 등으로 구동하고 있을 때,
-   3000 포트에 Express 서버가 `node server.js` 명령어 등으로 구동하고 있을 때,

위의 조건이 만족하고 있다면 `localhost:3000/api/test` url 요청으로 API 데이터를 받아올 수 있습니다.

-   443(HTTPS 디폴트) 포트에 NGINX 게이트웨이 서버가 `start-nginx` 명령어 등으로 구동하고 있을 때,
-   『MY_DOMAIN』 도메인에 DDNS 서비스로부터 권한을 얻고 연결하였을 때, 

위의 조건이 만족하고 있다면 `https://『MY_DOMAIN』.duckdns.org/api/test` url 요청으로 API 데이터를 받아올 수 있습니다.

#### 개념 정리 : HTTP Method 와 CRUD

&nbsp; 지금은 DB 의 연결 상태만 확인했지만 이제 DB 에 데이터를 저장하고 읽고 수정하고 삭제하는 코드를 작성할 것 입니다. 이런 데이터 조작 작업을 흔히 CRUD 라고 줄여서 부릅니다. 

-   생성 (<u><b>C</b></u>reate)
-   읽기 (<u><b>R</b></u>ead)
-   수정 (<u><b>U</b></u>pdate)
-   삭제 (<u><b>D</b></u>elete)

의 각 작업들의 앞글자만 따온 것 입니다. 여기에 집중하여 데이터 조작 API 를 개발하면 직관적인 도구로 만들 수 있습니다.

&nbsp; 위 Express 의 DB 연결 확인 요청 코드에 app.get 을 사용하였습니다. GET 요청은 HTTP Method의 일종 입니다.

&nbsp; HTTP 메서드란 RESTful API 표준에서 요청 형식의 종류를 말합니다. GET 은 일반적으로 알고 계신 url 스트링 데이터에 모든 것이 담겨있는 형식이며 POST, PATCH, PUT 은 html 형식에서 body 에 데이터를 실어 전송하는 형식입니다. POST(생성 요청), PATCH(일부수정 요청), PUT(전체수정 요청) 은 기술상은 거의 같으나 이름을 달리하여 같은 URL 로 소통할 때에 멱등성 처리등 직관적으로 작업 라인을 구분하기 위해서 분리되었습니다. 안 지켜도 상관은 없지만 지켜주는 쪽이 더 잘 설계된 API 입니다. 이런 형식이니 알아만 두세요.

-   HTTP method 와 DB CRUD (Create Read Update Delete) 의 관계

    -   GET: 리소스 조회 (Read)

    -   POST: 새 리소스 생성 (Create), 멱등성 X 인 작업(비멱등 작업)

    -   PUT: 리소스 전체 수정 또는 교체 (Update/Replace)

    -   PATCH: 리소스 일부 어트리뷰트 수정 (Partial Update)

    -   DELETE: 리소스 삭제 (Delete)

#### 개념 정리 : 멱등성

&nbsp; 멱등성에 대한 설명을 잠깐만 하고 넘어가겠습니다.

&nbsp; 멱등성이란 중복 요청을 하더라도 한번 요청한 것과 결과가 같은 것을 보장하는 특성을 말합니다. 

-   DELETE 메서드 요청으로 2번 학생 데이터를 삭제하라고 5번을 입력하나 1번 입력하나 DB 의 최종 처리 결과는 같습니다.

-   GET 메서드 요청으로 3번 학생 데이터를 가져오라도 5번을 입력해도 앞의 4번의 결과는 새로고침되서 날아가고 마지막 결과만 보이므로 결국 최종 처리 결과가 같습니다. DB에도 영향은 없습니다.

&nbsp; 하지만 POST (새로운 리소스 생성과 복잡한 처리 작업) 에 할당된 작업은 대다수가 멱등하지 못합니다. 예를들어, 2만원을 결제하는 작업을 5번을 처리했다간 여러분의 통장에서 10만원이 인출될 수 있습니다.

&nbsp; 이런 이중결제같은 참사를 막기 위하여 Redis를 활용한 멱등성 키(Idempotency Key) 를 기반으로 검증 로직을 구현하여 중복 요청 실수가 있어도 복수의 처리가 일어나지 않도록 멱등성을 부여할 수 있습니다. 이는 나중에 다루겠습니다.

### DB 서비스 예제 1 (유저 명단 관리)

&nbsp; 이제 DB 와 연결되어 있기 때문에 저장소를 마음대로 사용할 수 있고, 이 정보의 기록 및 수정을 URL 로 조작할 수 있습니다. 이제 예시로 API 서비스를 만들어보겠습니다. 

&nbsp; 각 유저를 이메일과 비밀번호와 점수를 기록하고, 점수 순으로 순위표를 뽑는 예제를 만들어보겠습니다. 

#### DB 서비스 예제 1-1 : 서비스 설계

&nbsp; 구현할 API url 과 DB 작업은 다음과 같이 매핑됩니다.

-   DB 개발 명세서

    <table>
    <tr>
        <th colspan=4 align=left><b>users</b></th>
    </tr>
    <tr>
        <th>username</th>
        <th>email</th>
        <th>password_hash</th>
        <th>score</th>
    </tr>
    <tr>
        <td>VARCHAR(50) <kbd>NOT NULL</kbd></td>
        <td>VARCHAR(255) <kbd>PK</kbd></td>
        <td>TEXT <kbd>NOT NULL</kbd></td>
        <td>INTEGER <kbd>NOT NULL</kbd> <kbd>DEFAULT 0</kbd></td>
    </tr>
    </table>

-   API 개발 명세서

    <table>
    <tr>
        <th>URL</th>
        <th>HTTP method</th>
        <th>DB 작업</th>
    </tr>
    <tr>
        <td><code>/api/users</code></td>
        <td>POST</td>
        <td>
        <ul>
        <li>새로운 유저를 추가한다.</li>
        <li>username, email, password를 JSON으로 전달</li>
        </ul>
        </td>
    </tr>
    <tr>
        <td><code>/api/users/:email/score</code></td>
        <td>PATCH</td>
        <td>
        <ul>
        <li>특정 유저의 점수를 변경한다.</li>
        <li>이메일을 경로에 지정하고 변경할 점수를 전달</li>
        </ul>
        </td>
    </tr>
    <tr>
        <td><code>/api/leaderboard</code></td>
        <td>GET</td>
        <td>
        <ul>
        <li>점수 내림차순으로 상위 10명을 반환한다.</li>
        <li>요청 본문 없이 JSON으로 결과 반환</li>
        </ul>
        </td>
    </tr>
    </table>

#### DB 서비스 예제 1-2 : DB 환경 조성

&nbsp; 다음의 쿼리를 실행시켜 user 라는 테이블을 만들어 주세요. 앞의 [API 에 사용할 Table 만들기](#api-에-사용할-table-만들기) 항목에서 DB 연습할 때, 이미 생성한 테이블입니다. 이제까지 따라오셨다면 새로 만들지 않아도 괜찮습니다.

-   myapp/myapp_user@PostgreSQL 18 - myapp_user

    ```sql
    CREATE TABLE users (
        username      VARCHAR(50) NOT NULL,
        email         VARCHAR(255) PRIMARY KEY,
        password_hash TEXT NOT NULL,
        score         INTEGER NOT NULL DEFAULT 0
    );
    ```

&nbsp; 생성한 테이블의 확인은 [API 에 사용할 Table 만들기](#api-에-사용할-table-만들기) 항목의 `관리자 & 테이블 관련 쿼리 명령어 모음` 을 참고하세요.

#### DB 서비스 예제 1-3 : Express 코드 작성

&nbsp; server.js 에 이제 API url 을 요청 받았다면 DB에 요청을 보내고 그 답을 응답하는 코드를 작성해주면 됩니다.

-   server.js

    ```js
    require('dotenv').config();

    const express = require('express');
    const bcrypt = require('bcrypt');
    const pool = require('./db');

    const app = express();
    const PORT = Number(process.env.PORT) || 3000;

    app.set('trust proxy', 'loopback');
    app.use(express.json({ limit: '10kb' }));
    app.use((req, res, next) => {
        console.log('REQUEST', req.method, req.path);
        next();
    });

    // * GET | /api/test | PostgreSQL 연결 테스트
    app.get('/api/test', async (req, res) => {
        try {
            const result = await pool.query('SELECT NOW() AS server_time');

            res.json({
                success: true,
                message: 'Express + PostgreSQL is working',
                databaseTime: result.rows[0].server_time,
            });
        } catch (err) {
            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Database connection failed',
            });
        }
    });

    // * POST | /api/users | 새로운 유저 추가
    app.post('/api/users', async (req, res) => {
        const { username, email, password } = req.body;

        // * Validate input check
        // if (
        //     typeof username !== 'string' ||
        //     typeof email !== 'string' ||
        //     typeof password !== 'string' ||
        //     !username.trim() ||
        //     !email.trim() ||
        //     password.length < 8 ||
        //     password.length > 72
        // ) {
        //     return res.status(400).json({
        //         success: false,
        //         message: 'Invalid user data',
        //     });
        // }

        try {
            const passwordHash = await bcrypt.hash(password, 12);

            const result = await pool.query(
                `INSERT INTO users
                    (username, email, password_hash)
                VALUES ($1, $2, $3)
                RETURNING username, email, score`,
                [username.trim(), email.trim().toLowerCase(), passwordHash],
            );

            res.status(201).json({
                success: true,
                user: result.rows[0],
            });
        } catch (err) {
            if (err.code === '23505') {
                return res.status(409).json({
                    success: false,
                    message: 'Email already exists',
                });
            }

            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Failed to create user',
            });
        }
    });

    // * PATCH | /api/users/:email/score | 특정 유저의 점수 설정
    app.patch('/api/users/:email/score', async (req, res) => {
        const email = req.params.email;
        // const { score } = req.body;
        const { score: rawScore } = req.body;
        const score = Number(rawScore);

        console.log('PATCH /api/users/:email/score', { email, score });

        if (typeof email !== 'string' || !email.trim() || !Number.isSafeInteger(score) || score < 0) {
            return res.status(400).json({
                success: false,
                message: 'Invalid email or score',
            });
        }

        try {
            const result = await pool.query(
                `UPDATE users
                SET score = $1
                WHERE email = $2
                RETURNING username, email, score`,
                [score, email.trim().toLowerCase()],
            );

            if (result.rowCount === 0) {
                return res.status(404).json({
                    success: false,
                    message: 'User not found',
                });
            }

            res.json({
                success: true,
                user: result.rows[0],
            });
        } catch (err) {
            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Failed to update score',
            });
        }
    });

    //  * GET | /api/leaderboard | 점수 상위 10명 조회
    app.get('/api/leaderboard', async (req, res) => {
        try {
            const result = await pool.query(
                `SELECT username, email, score
                FROM users
                ORDER BY score DESC, email ASC
                LIMIT 10`,
            );

            res.json({
                success: true,
                count: result.rowCount,
                leaderboard: result.rows,
            });
        } catch (err) {
            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Failed to get leaderboard',
            });
        }
    });

    //  * GET | /api/leaderboard/images | 조회수 상위 10개 조회
    app.get('/api/leaderboard/images', async (req, res) => {
        try {
            const result = await pool.query(
                `SELECT image_id, views
                FROM users
                ORDER BY views DESC, image_id ASC
                LIMIT 10`,
            );

            res.json({
                success: true,
                count: result.rowCount,
                leaderboard: result.rows,
            });
        } catch (err) {
            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Failed to get leaderboard',
            });
        }
    });

    app.listen(PORT, '127.0.0.1', () => {
        console.log(`Express server running on port ${PORT}`);
    });
    ```

##### 개념정리 : 파라미터화 쿼리(Parameterized Query)

&nbsp; 코드 중간에 잘보면 특이하게 문자열에 변수 값을 이어붙일 때, pool.query(`$1, $2`, [var1, var2]) 같은 형식으로 값을 넣었습니다. 이런 방식을 파라미터화 쿼리(Parameterized Query) 라고 부릅니다.

&nbsp; Javascript 코드에서 흔히 쓰이는 `${var1}, ${var2}` 변수 문자열 치환 방식을 쓰지않은 이유는 악의를 가진 클라이언트가 DB 를 공격하는 SQL 을 URL 에 집어 넣었을 수 있기 때문입니다. 

&nbsp; 사용자 입력은 가능한 한 SQL 문자열에 직접 넣지 않는 것이 좋습니다.

```js
const result = await pool.query(
    `INSERT INTO users
        (username, email, password_hash)
     VALUES ($1, $2, $3)
     RETURNING username, email, score`,
    [
        username.trim(),
        email.trim().toLowerCase(),
        passwordHash,
    ]
);
```

#### DB 서비스 예제 1-4 : URL 요청 코드

이제 [Express 측 DB 연결 코드](#express-측-db-연결-코드) 항목에 나왔던 것과 같이

-   5432 포트에 postgreSQL DB 가 `start-service postgresql-x64-18` 같은 터미널 명령어로 서비스되고 있을 때,
-   3000 포트에 Express Server 가 `node server.js` 명령어 등으로 구동하고 있을 때,

위의 조건이 만족하고 있다면 `localhost:3000/api/test` 같은 url 요청으로 API 데이터를 받아올 수 있습니다.

-   443(HTTPS 디폴트) 포트에 NGINX 게이트웨이 서버가 `start-nginx` 명령어 등으로 구동하고 있을 때,
-   『MY_DOMAIN』 도메인에 DDNS 서비스로부터 권한을 얻고 연결하였을 때, 

위의 조건이 만족하고 있다면 `https://『MY_DOMAIN』.duckdns.org/api/test` url 요청으로 API 데이터를 받아올 수 있습니다.

&nbsp; API 가 정상적으로 요청에 응답하여 DB 데이터를 조작하고 반환해주는지 확인하기 위하여 URL 을 보내는 시도를 해보겠습니다.

&nbsp; Postman 같은 URL 요청 서비스도 있고 터미널 curl 도구로 URL 전송이 가능합니다. 

-   terminal shell

    ```bash
    curl -X PUT "https://api.example.com/data/1" \
        -H "Content-Type: application/json" \
        -d '{"foo": "푸", "bar": "바"}'
    ```

하지만 여기선 웹 개발 공부에 걸맞게 Javascript 의 `fetch` 도구를 통해 URL 요청을 해보겠습니다.

&nbsp; 개발 코드와 햇갈리지 않도록 `test/` 폴더를 생성하고 그 안에 URL Request 를 보낼 코드가 담길 `urlReq.js` 라는 이름의 파일을 생성해주세요.

&nbsp; 따라서 `$PROJECT_ROOT` 디렉터리의 구조는 다음과 같게 됩니다.

-   $PROJECT_ROOT

    ```txt
    example-server-project/ ($PROJECT_ROOT)
    │
    ├─ certs/
    ├─ node_modules/
    ├─ public/
    ├─ test/
    │   └─ urlReq.js <======== 새로 생성!
    │
    ├─ .env
    ├─ db.js
    ├─ package.json
    ├─ package-lock.json
    └─ server.js
    ```

&nbsp; `urlReq.js` 코드는 예시로 이런 형태를 취할 수 있습니다. 대충 형태만 보세요.

-   urlReq.js 예시 (안좋은 예시, 따라하지 마시오)

    ```js
    // # Node.js Fetch Request form
    // = ================================================================

    // * I/O Interface ==================================================

    const readline = require('readline');

    const reader = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
    });

    // * GET | /api/test | PostgreSQL 연결 테스트 ========================

    async function getApiTest() {
        return fetch('http://localhost:3000/api/test', {
            method: 'GET',
        })
            .then((response) => {
                if (!response.ok) throw new Error(`HTTP ${response.status}`);
                return response.json();
            })
            .then((data) => console.log('성공:', data))
            .catch((error) => console.error('에러:', error));
    }

    // * Input Number Recursive Function ================================

    function inputNumber() {
        reader.question(
            [
                '0: EXIT | 프로그램 종료',
                '1: GET | /api/test | PostgreSQL 연결 테스트',
                '\nInput Number: ',
            ].join('\n'),
            async (input) => {
                const num = Number(input);

                switch (num) {
                    case 0:
                        console.log('Exiting...\n');
                        reader.close();
                        return;
                    case 1:
                        await getApiTest();
                        break;
                    default:
                        console.log('Wrong input.');
                        break;
                }

                reader.question('\nContinue? (Y*/n): ', (input) => {
                    const isContinue = input.trim().toLowerCase() === 'y' || input.trim() === '';

                    if (!isContinue) {
                        console.log('Exiting...\n');
                        reader.close();
                        return;
                    }

                    inputNumber(); // recursive call to continue prompting for input
                });
            },
        );
    }

    // * Run

    inputNumber();
    ```

&nbsp; 콘솔의 표준 입출력 I/O 인터페이스와 연결한 reader 객체를 생성하고, `async (input) => { await ...}` 콜백 함수 안에 종료용 (Y*/n) 확인 콜백 함수를 담은 inputNumer 재귀함수를 이용해서 구현한 방법입니다. 

&nbsp; 사용자 입력을 더 받아야 할 때마다, `reader.question( ... , async (input) => { ... })` 콜백함수를 또 선언하여 `reader.question(  reader.question( ... ) )` 안으로 더 깊게 들어가지 않으면 입출력 순서를 보장하지 못합니다.

##### 개념 정리 : Javascript 비동기 제어

&nbsp; 다른 프로그래밍 언어에 익숙하다면 위와 같은 비동기 중심의 실행 방식이 어색할 수 있습니다. 
JavaScript의 태생은 다른 프로그래밍 언어들과는 다르게 웹 브라우저에서 페이지를 동적으로 제어하기 위해 만들어진 언어에서 시작되었습니다. 그로 인하여 `오류 관용성` 과 `비동기 중심 실행 방식` 이라는 독특한 특징을 가집니다. 

&nbsp; 위와 같은 상황은 비동기 중심 실행 방식으로 인하여 유발됩니다. 브라우저에서는 하나의 메인 스레드가 UI 처리와 스크립트 실행을 함께 담당합니다. 따라서 네트워크 요청 같은 느린 작업을 동기적으로 기다리면 화면 전체가 멈추게 되므로, 작업을 맡겨두고 완료 시점에 결과를 처리하는 이벤트 기반 비동기 방식이 기본이 되었습니다. Node.js 역시 이 모델을 이어받아 이벤트 루프와 논블로킹 I/O(libuv)를 중심으로 설계되었습니다.

&nbsp; 이런 방식은 서로 독립적인 작업을 동시에 진행할 때는 효율적이지만,
지금처럼 작업을 순서대로 실행해야 할 때는 콜백이 중첩되어 코드가 복잡해지기 쉽습니다.
Promise와 async/await는 이 문제를 완화하기 위한 문법입니다.

&nbsp; [Express 측 DB 연결 코드](#express-측-db-연결-코드) 항목에서 언급했듯이 `async () { await }` 을 이용하여 이 비동기 처리작업을 동기화 작업처럼 보이도록 제어할 수 있습니다. 실제로 작업 중인 쓰레드를 멈춰버리는 동기화 처리는 아니어도 async 코드 내의 진행을 제어하여 작업 순서를 보장할 수 있습니다. 

##### 1-4 URL Request 코드

&nbsp; 여기선 async + await 과 try/catch 를 이용하여 main 이라는 함수로 전체를 비동기 제어 처리를 해버리는 것으로 개발자에게 익숙한 방식으로 코드를 작성하겠습니다.

-   urlReq.js

    ```js
    // # Node.js Fetch Request form
    // = ================================================================
    // ## I/O Interface =================================================

    const readline = require('node:readline/promises');

    const reader = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
    });

    // ## Database Access API ===========================================

    //  * GET | /api/test | PostgreSQL 연결 테스트
    async function getApiTest() {
        try {
            const response = await fetch('http://localhost:3000/api/test', {
                method: 'GET',
            });

            if (!response.ok) throw new Error(`HTTP ${response.status}`);

            const data = await response.json();
            console.log('성공:', data);
        } catch (error) {
            console.error('에러:', error);
        }
    }

    //  * GET | /api/leaderboard | 점수 상위 10명 조회
    async function getApiLeaderboard() {
        try {
            const response = await fetch('http://localhost:3000/api/leaderboard', {
                method: 'GET',
            });

            if (!response.ok) throw new Error(`HTTP ${response.status}`);

            const data = await response.json();
            console.log('성공:', data);
        } catch (error) {
            console.error('에러:', error);
        }
    }

    //  * POST | /api/users | 새로운 유저 추가
    async function postApiUsers(username, email, password) {
        try {
            const response = await fetch('http://localhost:3000/api/users', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    username: username,
                    email: email,
                    password: password,
                }),
            });

            if (!response.ok) throw new Error(`HTTP ${response.status}`);

            const data = await response.json();
            console.log('성공:', data);
        } catch (error) {
            console.error('에러:', error);
        }
    }

    //  * PATCH | /api/users/:email/score | 특정 유저의 점수 설정
    async function patchApiUsersScore(email, score) {
        try {
            const response = await fetch(`http://localhost:3000/api/users/${email}/score`, {
                method: 'PATCH',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    score: score,
                }),
            });

            const data = await response.json().catch(() => ({}));

            if (!response.ok) {
                const err = new Error(data.message || `HTTP ${response.status}`);
                err.status = response.status;
                throw err;
            }

            console.log('성공:', data);
        } catch (error) {
            console.error('에러:', error);
        }
    }

    // ## Main ==========================================================
    async function main() {
        while (true) {
            const input = await reader.question(
                [
                    '',
                    '0: EXIT  | 프로그램 종료',
                    '1: GET   | /api/test               | 연결 테스트',
                    '2: GET   | /api/leaderboard        | 점수 상위 10명 조회',
                    '3: POST  | /api/users              | 새로운 유저 추가',
                    '4: PATCH | /api/users/:email/score | 특정 유저의 점수 설정',
                    '\nInput Number: ',
                ].join('\n'),
            );

            const num = Number(input);

            switch (num) {
                case 0:
                    console.log('Exiting...');
                    reader.close();
                    return;
                case 1:
                    await getApiTest();
                    break;
                case 2:
                    await getApiLeaderboard();
                    break;
                case 3: {
                    const username = await reader.question('Username: ');
                    const email = await reader.question('Email: ');
                    const password = await reader.question('Password: ');
                    await postApiUsers(username, email, password);
                    break;
                }
                case 4:
                    const email = await reader.question('Email: ');
                    const score = await reader.question('Score: ');
                    await patchApiUsersScore(email, score);
                    break;
                default:
                    console.log('Wrong input.');
                    break;
            }

            const answer = await reader.question('\nContinue? (Y*/n): ');
            console.log('\n');
            if (!['y', ''].includes(answer.trim().toLowerCase())) {
                console.log('Exiting...');
                reader.close();
                return;
            }
        }
    }

    // ## Run ===========================================================
    main();
    ```

다음 코드를 `node urlReq.js` 같은 명령어로 실행시키면 URL 요청을 보내는 테스트를 할 수 있습니다. 강제 종료는 다른 프로그램들과 마찬가지로 구동 중인 터미널에서 <kbd>ctrl</kbd> + <kbd>c</kbd> 입니다.

### DB 서비스 예제 2 (사진첩)

&nbsp; 이번 예제에서는 이미지 파일을 저장하고 꺼내는 서비스를 만들어보도록 하겠습니다. 

&nbsp; 이번 예제에서는 URL 이 특정 형태를 유지하고 HTTP Method 만 변합니다. URL 로 파라미터를 넘기고 HTTP Method 로 동작을 지시하는 RESTful 한 API 방식이 어떤 것인지 감을 잡는데에 도움이 될 것 입니다.

#### DB 서비스 예제 2-1 : 서비스 설계

-   DB 개발 명세서

    <table>
    <tr>
        <th colspan=3 align=left><b>images</b></th>
    </tr>
    <tr>
        <th>image_id</th>
        <th>image_file</th>
        <th>views</th>
    </tr>
    <tr>
        <td>INTEGER <kbd>PK</kbd></td>
        <td>BYTEA <kbd>NOT NULL</kbd></td>
        <td>INTEGER <kbd>NOT NULL</kbd> <kbd>DEFAULT 0</kbd></td>
    </tr>
    </table>

-   API 개발 명세서

    <table>
    <tr>
        <th>URL</th>
        <th>HTTP method</th>
        <th>DB 작업</th>
    </tr>
    <tr>
        <td><code>/api/leaderboard </code></td>
        <td>GET</td>
        <td>조회수 상위 10개 조회</td>
    </tr>
    <tr>
        <td><code>/api/:image-id</code></td>
        <td>GET</td>
        <td>image-id 이미지 조회</td>
    </tr>
    <tr>
        <td><code>/api/:image-id</code></td>
        <td>POST</td>
        <td>image-id 이미지 추가</td>
    </tr>
    <tr>
        <td><code>/api/:image-id</code></td>
        <td>PATCH</td>
        <td>image-id 이미지 변경</td>
    </tr>
    <tr>
        <td><code>/api/:image-id</code></td>
        <td>DELETE</td>
        <td>image-id 이미지 삭제</td>
    </tr>
    </table>

#### DB 서비스 예제 2-2 : DB 환경 조성

&nbsp; DB 기동과 계정 설정 등에 대한 내용은 상단의 [API 에 사용할 Table 만들기](#api-에-사용할-table-만들기) 항목을 참고하세요.

&nbsp; `myapp/myapp_user@PostgreSQL 18 - myapp_user` ( <u><b>Servers</b></u> > <u><b>PostgreSQL 18 - myapp_user</b></u> 연결에서 <u><b>Databases</b></u> > <u><b>myapp</b></u> 에 우클릭으로 열은 Query Tool ) 에서 다음의 쿼리 명령어를 입력하고 실행해주세요.

-   myapp/myapp_user@PostgreSQL 18 - myapp_user

    ```sql
    CREATE TABLE public.images (
        image_id   INTEGER PRIMARY KEY,
        image_file BYTEA   NOT NULL,
        views      INTEGER NOT NULL DEFAULT 0 CHECK (views >= 0)
    );
    ```

&nbsp; 생성한 테이블의 확인은 [API 에 사용할 Table 만들기](#api-에-사용할-table-만들기) 항목의 `관리자 & 테이블 관련 쿼리 명령어 모음` 을 참고하세요.

#### DB 서비스 예제 2-3 : Server Express 코드

코드 내부의 변수만을 다루는 것이 아니라 파일 데이터를 조작해야하다 보니 전체 코드를 이해하기 위해선 알아야 하는 개념들이 좀 있습니다.

##### 개념 정리 : Express 와 미들웨어 중간처리

Express.js 개발진은 프레임워크를 가볍고 유연하게 유지하기 위해 파일 업로드 처리 알고리즘을 Express 내부에 포함하지 않았습니다. 요청과 응답을 제어하는 틀만 제공하고 이 사이 중간처리 작업은 개발자들이 미들웨어(Middleware) 를 직접 만들어 삽입해야 합니다.

Express.js 의 get, post 등의 함수들은 인자 수의 제한이 없는 가변 인자(Variadic Arguments) 로 콜백 함수를 받습니다. 그리고나서 Express.js 프레임워크는 개발자에게 받은 콜백 함수들을 순서대로 호출하여 미들웨어 체인으로 연결하여 실행합니다.

예를 들어 `const mid1 = upload.single('file');`, `const mid2 = (req, res, next) => { console.log('REQUEST'); next(); };` 와 같이 코드를 만들었다고 합시다. 두 코드는 미들웨어 역할을 수행할 수 있도록, 파라미터로 요청(req) 를 받고 응답(res) 을 조작하고 이 응답을 다음 체인으로 넘겨주는(next) 형태의 함수로 제작되었습니다.

어? mid1 은 `(req, res, next) => {next();}` 미들웨어 동작을 수행하는 콜백함수 형태가 아니지 않느냐? 라는 궁금증이 생기실 수 있지만, upload.single('file') 은 밑에 설명할 multer 패키지의 미들웨어를 만들어내는 팩토리 패턴이라는 디자인 패턴을 가진 인스턴스입니다. upload.single('file') 이 return 하는 결과물이 `(req, res, next) => {next();}` 형태입니다.

Express.js 객체 app 에 대하여 `app.get('/api/test', async (req, res) => { ... });` GET 요청을 처리하는 함수에서 작업을 핸들링 하기 전에 요청(req) 이 위 mid1 (미디어 데이터 제어) 과 mid2 (콘솔 로그 출력) 과정을 거치고 오길 바란다면...

```js
app.get('/api/test', mid1, mid2, async (req, res) => { ... });
```

위와 같이 사이에 넣어주면 됩니다. 가변 인자 함수이므로 인자 수에 제한이 없기에...

```js
app.post('/api', 
  authMiddleware,      // 미들웨어 1 (인증)
  loggerMiddleware,    // 미들웨어 2 (로그)
  upload.single('file'),// 미들웨어 3 (파일 파싱)
  validationMiddleware,// 미들웨어 4 (유효성 검사)
  async (req, res) => { // 최종 핸들러 (컨트롤러)
    res.send('Done');
  }
);
```

이렇게 사전에 미들웨어 단계에서 보안처리를 할 수도 있습니다.

참고로 next(); 는 return; 이 아님을 명심합시다.

```js
console.log('A');
next();
console.log('B');
```

라면 A 가 출력되고 다른 미들웨어들이 순서대로 전부 동작한 후에 B 가 출력됩니다.

종료를 원한다면 `return next();` 나 `next(); return;` 처럼 동작 종료 및 반환를 명시해야합니다.

##### 개념 정리 : 바이너리 데이터 타입과 요청 스트림

이미지 파일을 DB 에 저장할 때는 BYTEA(Byte Array) 8비트 이진 데이터(Binary Data) 형식으로 저장하고 있습니다.

HTTP "Content-Type: multipart/form-data" 형식의 req 요청 스트림에는 Body(본문) 안에 0과 1로 되어있는 날 것의 이진(Binary) 데이터가 들어있습니다. 

이 바이너리 데이터를 읽어서 파일 조각을 분석하여 Javascript 가 다룰 수 있는 오브젝트 타입인 `buffer` 타입을 할당해줘야 합니다.

이 바이너리 데이터에 대한 오브젝트 타입은 buffer 뿐 아니라 arrayBuffer, blob 도 있지만 이는 나중에 다루겠습니다. 지금은 buffer 에 집중해주세요.

미들웨어(Middleware) 중간처리 단계를 삽입하여, 요청스트림을 분석하여 얻어낸 메타데이터와 버퍼를 req.file이라는 속성에 새로 할당(req.file = ...) 한 후 next()를 불러 넘겨주면 됩니다.

multer 는 조건을 넣어주면 그에 맞는 멀티데이터 제어용 미들웨어를 만들어주는 라이브러리입니다.

multer 를 이용하여 memoryStorage() 함수로 업로드된 요청파일을 Buffer 형태로 다루고, Buffer 형태로 변환한 값을 BYTEA 값으로 PostgreSQL에 넣을 수 있습니다.

프로젝트 루트 폴더 `$PROJECT_ROOT` 에서 터미널을 열고 다음의 명령어로 node 패키지를 설치해주세요. 

-   terminal shell

    ```bash
    npm install multer
    ```

이제 다음과 같은 형식으로 미들웨어를 만들고 적용할 수 있습니다.

```js
//  * multer 패키지 가져오기
const multer = require('multer');

//  * multipart/form-data의 image 필드를 메모리(Buffer)로 받는다.
const upload = multer({
    storage: multer.memoryStorage(),

    limits: {
        fileSize: 10 * 1024 * 1024, // 10 MB
    },

    fileFilter: (req, file, cb) => {
        if (!file.mimetype.startsWith('image/')) {
            return cb(new Error('Only image files are allowed'));
        }

        cb(null, true);
    },
});


//  * const upload = multer({ ... }) 은 설정된 필터에 따라 이미지를 버퍼로 바꿔주는 미들웨어를 반환
const imageMiddleware = upload.single('image')
```

##### 개념 정리 : Express 미들웨어 에러 핸들링

미들웨어 중에서 `(err, req, res, next) => { ... }` 파라미터에 err 가 있는 형태로 Express 프레임워크에 등록한 콜백함수는 자동으로 에러 핸들러로 취급됩니다.

Express 프레임워크가 동작하면서 만약 `next(err);` 로 미들웨어 체인이 넘어갈 경우에는, 이 후의 미들웨어 중에서 `(err, req, res, next) => { ... }` 형태의 함수를 찾아 다음 순서로 호출합니다.

Express 는 반드시 등록 순서대로만 진행하기 때문에 에러 발생 전에 등록된 에러 핸들러는 동작하지 않습니다. 에러가 발생하기도 전에 먼저 에러 핸들링을 할 순 없기 때문입니다. 

따라서 적용하고자하는 동작 다음 순서, 또는 범용적인 에러 처리라면 가장 마지막에 등록하는 것이 좋습니다.

넣은 파일의 용량이 한계를 넘었다던지, 요청 자체가 왜곡됬다던지 같이 URL 요청 핸들링으로 제어하기 어려운 경우를 에러 핸들링할 수 있습니다. 밑의 코드는 예시 입니다.

-   example

    ```js
    //  * Error-handling middleware | (err, req, res, next) 형태 미들웨어는 next(err); 시에 호출됨
    app.use((err, req, res, next) => {
        console.error(err);

        if (err instanceof multer.MulterError) {
            if (err.code === 'LIMIT_FILE_SIZE') {
                return res.status(413).json({
                    success: false,
                    message: 'Image file is too large',
                });
            }

            return res.status(400).json({
                success: false,
                message: err.message,
            });
        }

        if (err) {
            return res.status(400).json({
                success: false,
                message: err.message,
            });
        }

        next();
    });
    ```

기본적으론 코드에서 next(err); 의 선언 후에 에러 핸들러를 찾기 시작합니다. 하지만 별도 처리가 곤란하거나 귀찮은 경우도 존재합니다. Express 는 Express 5 이후로 rejected 인 Promise 가 반환되었다면 알아서 next(err); 와 마찬가지로 에러 핸들러를 찾아 다음 동작으로 넘깁니다. 

Promise 객체를 반환하는 비동기제어 콜백함수 `async (req, res) => { ... }` 가 catch 문으로도 제어하지 못한 동작으로 rejected 되었다면 알아서 Express 측이 에러핸들러로 넘겨준다는 것입니다.

##### 2-3 Server Express 코드

[개념 정리 : Express 와 미들웨어 중간처리](#개념-정리--express-와-미들웨어-중간처리) 항목에서 언급했듯, Express 는 등록 순서대로 일을 처리합니다.

`/api/leaderboard` 는 마치 imageId = "leaderboard" 인 `/api/:imageId` 의 URL 과 겹치기 때문에 요청이 가로채질 수 있습니다. 따라서 `/api/leaderboard` 를 먼저 등록해야 한다는 점만 명심해주세요.

각 get, post 등의 url 요청은 [DB 서비스 예제 2-1 : 서비스 설계](#db-서비스-예제-2-1--서비스-설계) 항목을 참고해주세요. 코드는 길지만 각 함수의 동작 목표에 집중하면서 읽으면 어려운 내용은 없습니다.

-   server.js

    ```js
    require('dotenv').config();

    const express = require('express');
    const multer = require('multer');
    const pool = require('./db');

    const app = express();
    const PORT = Number(process.env.PORT) || 3000;

    app.set('trust proxy', 'loopback');

    app.use(express.json({ limit: '10kb' }));
    app.use((req, res, next) => {
        console.log('Request: ', req.method, req.path);
        next();
    });

    //  * Middleware by multer factory instance | for multipart/form-data → memory buffer
    const upload = multer({
        storage: multer.memoryStorage(),

        limits: {
            fileSize: 10 * 1024 * 1024, // 10 MB
        },

        fileFilter: (req, file, cb) => {
            if (!file.mimetype.startsWith('image/')) {
                return cb(new Error('Only image files are allowed'));
            }

            cb(null, true);
        },
    });

    //  * Middleware for Image ID check | Only allow positive integers
    function parseImageId(value) {
        const imageId = Number(value);

        if (!Number.isInteger(imageId) || imageId < 1) {
            return null;
        }

        return imageId;
    }

    //  * Middleware for MIME type detection | Detect image MIME type from file signature
    function detectImageMimeType(buffer) {
        //  * PNG
        if (
            buffer.length >= 8 &&
            buffer.subarray(0, 8).equals(Buffer.from([0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a]))
        ) {
            return 'image/png';
        }

        //  * JPEG
        if (buffer.length >= 3 && buffer[0] === 0xff && buffer[1] === 0xd8 && buffer[2] === 0xff) {
            return 'image/jpeg';
        }

        //  * GIF
        if (
            buffer.length >= 6 &&
            ['GIF87a', 'GIF89a'].includes(buffer.subarray(0, 6).toString('ascii'))
        ) {
            return 'image/gif';
        }

        //  * WebP
        if (
            buffer.length >= 12 &&
            buffer.subarray(0, 4).toString('ascii') === 'RIFF' &&
            buffer.subarray(8, 12).toString('ascii') === 'WEBP'
        ) {
            return 'image/webp';
        }

        //  * BMP
        if (buffer.length >= 2 && buffer[0] === 0x42 && buffer[1] === 0x4d) {
            return 'image/bmp';
        }

        return null;
    }

    //  * GET | /api/test | PostgreSQL 연결 테스트
    app.get('/api/test', async (req, res) => {
        try {
            const result = await pool.query('SELECT NOW() AS server_time');

            res.json({
                success: true,
                message: 'Express + PostgreSQL is working',
                databaseTime: result.rows[0].server_time,
            });
        } catch (err) {
            console.error(err);
            res.status(500).json({
                success: false,
                message: 'Database connection failed',
            });
        }
    });

    //  * GET | /api/leaderboard | 조회수 상위 10명 조회
    app.get('/api/leaderboard', async (req, res) => {
        try {
            const result = await pool.query(
                `SELECT image_id, views
                FROM images
                ORDER BY views DESC, image_id ASC
                LIMIT 10`,
            );

            res.json({
                success: true,
                count: result.rowCount,
                leaderboard: result.rows,
            });
        } catch (err) {
            console.error(err);

            res.status(500).json({
                success: false,
                message: 'Failed to get leaderboard',
            });
        }
    });

    //  * GET | /api/:imageId | 이미지 조회 및 조회수 증가
    app.get('/api/:imageId', async (req, res) => {
        const imageId = parseImageId(req.params.imageId);

        if (imageId === null) {
            return res.status(400).json({
                success: false,
                message: 'Invalid image_id',
            });
        }

        try {
            const result = await pool.query(
                `UPDATE images
                SET views = views + 1
                WHERE image_id = $1
                RETURNING image_file`,
                [imageId],
            );

            if (result.rowCount === 0) {
                return res.status(404).json({
                    success: false,
                    message: 'Image not found',
                });
            }

            const imageBuffer = result.rows[0].image_file;
            const mimeType = detectImageMimeType(imageBuffer);

            if (mimeType === null) {
                return res.status(500).json({
                    success: false,
                    message: 'Unsupported image format',
                });
            }

            res.set('Content-Type', mimeType);
            res.set('Content-Length', String(imageBuffer.length));

            return res.send(imageBuffer);
        } catch (err) {
            console.error(err);

            return res.status(500).json({
                success: false,
                message: 'Failed to get image',
            });
        }
    });

    //  * POST | /api/:imageId | 신규 이미지 추가
    app.post('/api/:imageId', upload.single('image'), async (req, res) => {
        const imageId = parseImageId(req.params.imageId);

        if (imageId === null) {
            return res.status(400).json({
                success: false,
                message: 'Invalid image_id',
            });
        }

        if (!req.file) {
            return res.status(400).json({
                success: false,
                message: 'Image file is required',
            });
        }

        try {
            const result = await pool.query(
                `INSERT INTO images (image_id, image_file)
                VALUES ($1, $2)
                RETURNING image_id, views`,
                [imageId, req.file.buffer],
            );

            return res.status(201).json({
                success: true,
                image: result.rows[0],
            });
        } catch (err) {
            console.error(err);

            // PRIMARY KEY 중복
            if (err.code === '23505') {
                return res.status(409).json({
                    success: false,
                    message: 'image_id already exists',
                });
            }

            return res.status(500).json({
                success: false,
                message: 'Failed to add image',
            });
        }
    });

    //  * PATCH | /api/:imageId | 이미지 변경
    app.patch('/api/:imageId', upload.single('image'), async (req, res) => {
        const imageId = parseImageId(req.params.imageId);

        if (imageId === null) {
            return res.status(400).json({
                success: false,
                message: 'Invalid image_id',
            });
        }

        if (!req.file) {
            return res.status(400).json({
                success: false,
                message: 'Image file is required',
            });
        }

        try {
            const result = await pool.query(
                `UPDATE images
                SET image_file = $1
                WHERE image_id = $2
                RETURNING image_id, views`,
                [req.file.buffer, imageId],
            );

            if (result.rowCount === 0) {
                return res.status(404).json({
                    success: false,
                    message: 'Image not found',
                });
            }

            return res.json({
                success: true,
                image: result.rows[0],
            });
        } catch (err) {
            console.error(err);

            return res.status(500).json({
                success: false,
                message: 'Failed to update image',
            });
        }
    });

    //  * DELETE | /api/:imageId | 이미지 삭제
    app.delete('/api/:imageId', async (req, res) => {
        const imageId = parseImageId(req.params.imageId);

        if (imageId === null) {
            return res.status(400).json({
                success: false,
                message: 'Invalid image_id',
            });
        }

        try {
            const result = await pool.query(
                `DELETE FROM images
                WHERE image_id = $1
                RETURNING image_id`,
                [imageId],
            );

            if (result.rowCount === 0) {
                return res.status(404).json({
                    success: false,
                    message: 'Image not found',
                });
            }

            return res.json({
                success: true,
                image_id: result.rows[0].image_id,
            });
        } catch (err) {
            console.error(err);

            return res.status(500).json({
                success: false,
                message: 'Failed to delete image',
            });
        }
    });

    //  * Error-handling Middleware | Multer and other errors
    app.use((err, req, res, next) => {
        console.error(err);

        if (err instanceof multer.MulterError) {
            if (err.code === 'LIMIT_FILE_SIZE') {
                return res.status(413).json({
                    success: false,
                    message: 'Image file is too large',
                });
            }

            return res.status(400).json({
                success: false,
                message: err.message,
            });
        }

        if (err) {
            return res.status(400).json({
                success: false,
                message: err.message,
            });
        }

        next();
    });

    app.listen(PORT, '127.0.0.1', () => {
        console.log(`Express server running on port ${PORT}`);
    });
    ```

#### DB 서비스 예제 2-4 : URL Request 코드

이제 [Express 측 DB 연결 코드](#express-측-db-연결-코드) 항목에 나왔던 것과 같이

-   5432 포트에 postgreSQL DB 가 `start-service postgresql-x64-18` 같은 터미널 명령어로 서비스되고 있을 때,
-   3000 포트에 Express Server 가 `node server.js` 명령어 등으로 구동하고 있을 때,

위의 조건이 만족하고 있다면 `localhost:3000/api/test` 같은 url 요청으로 API 데이터를 받아올 수 있습니다.

-   443(HTTPS 디폴트) 포트에 NGINX 게이트웨이 서버가 `start-nginx` 명령어 등으로 구동하고 있을 때,
-   『MY_DOMAIN』 도메인에 DDNS 서비스로부터 권한을 얻고 연결하였을 때, 

위의 조건이 만족하고 있다면 `https://『MY_DOMAIN』.duckdns.org/api/test` url 요청으로 API 데이터를 받아올 수 있습니다.

터미널에서 curl 도구를 이용하면 쉽게 해당 요청을 보내볼 수 있습니다.

-   terminal shell

    ```bash
    curl -X POST \
    -F "image=@test.png" \
    http://localhost:3000/api/100
    ```

하지만 여기서도 [DB 서비스 예제 1-3 : URL 요청 코드](#db-서비스-예제-1-3--url-요청-코드) 항목처럼 웹 개발 공부에 걸맞게 Javascript 의 `fetch` 도구를 통해 URL 요청을 해보겠습니다. 이런 요청 코드 작성에 익숙해지면, 다른 프로젝트에서도 서버 데이터를 주고받는 코드를 작성할 수 있습니다.

코드 내부의 변수만을 다루는 것이 아니라 파일 데이터를 조작해야하다 보니 전체 코드를 이해하기 위해선 알아야 하는 개념들이 좀 있습니다.

##### 개념 정리 : 바이너리 데이터 타입 Blob 과 Buffer

[개념 정리 : 바이너리 데이터 타입과 요청 스트림](#개념-정리--바이너리-데이터-타입과-요청-스트림) 항목에서 이미 0,1 로 이루어진 바이너리 데이터를 다루는 타입 buffer 를 언급했습니다.

```txt
HTTP 요청
    │
    │ 이진값(Byte Sequence)
    ↓
Express(Server)
    │
    │ Javascript 이진값 타입(Buffer)
    ↓
PostgreSQL(DB)
```

이제 URL 요청에 파일을 담는 과정과 이 파일을 컴퓨터 메모리에 다운로드 받는 과정이 추가됩니다.

```txt
     클라이언트(urlReq.js)
       ↑ │
Buffer │ │ HTML 환경 이진값 타입(Blob)
       │ ↓
     HTTP 요청
        │
        │ Byte Sequence
        ↓
     Express(Server)
        │
        │ Buffer
        ↓
    PostgreSQL(DB)
```

컴퓨터에 있는 특정 파일을 읽어서 Javascript 의 변수에 집어넣거나 <u><b>(C:/example/a.png 파일을 DB 의 images 테이블에 넣기)</b></u> 반대로 Javascript 에서 파일을 컴퓨터에 저장하는 <u><b>(DB 에 특정 image ID 의 파일을 받아와서 다운로드하기)</b></u> 동작을 수행하려면 Blob, Buffer, ArrayBuffer 타입을 모두 사용해야 합니다.

파일이나 이미지의 바이너리 데이터를 다루는 데이터 형식 Blob, Buffer, ArrayBuffer는 서로 비슷해 보이지만 데이터를 어떤 목적으로 다루느냐에 따라 역할이 다릅니다.

-   <table>
    <tr>
        <th>타입명</th>
        <td>Blob</td>
        <td>Array Buffer</td>
        <td>Buffer</td>
    </tr>
    <tr>
        <th>개념</th>
        <td>MIME 타입이 붙은 불변 파일형 데이터</td>
        <td>고정 길이 원시 바이트 덩어리</td>
        <td>Uint8Array를 상속한 Node.js 전용 클래스</td>
    </tr>
    <tr>
        <th>주 실행환경</th>
        <td>웹 브라우저</td>
        <td>웹 브라우저, Node.js 모두 (JS 표준)</td>
        <td>Node.js</td>
    </tr>
    <tr>
        <th>읽기/쓰기</th>
        <td>불가 (비동기로 읽기만 가능)</td>
        <td>직접 수정은 불가능 (뷰가 필요)</td>
        <td>가능 (buf[0], readUInt32BE 등)</td>
    </tr>
    </table>

-   <u><b>Blob</b></u>

    &nbsp; Blob(Binary Large Object) 은 주로 웹 브라우저 및 프론트엔드 측에서 `업로드, 다운로드, 미리보기` 부분에서 사용됩니다. 

    &nbsp; 불변(immutable)의 파일 같은 데이터로, size와 type(MIME)을 가집니다. 웹 브라우저 입장에선 파일처럼 용량이 큰 Blob을 JS 메모리가 아니라 디스크에 둘 수도 있어서, `변하지 않는 큰 데이터를 다루기에 유리`합니다.

    &nbsp; 일부만 수정조작이 불가능하고 읽기작업에 항상 비동기제어 과정을 거쳐야하므로 `데이터 호출 및 수정 작업에 부적합`합니다.

-   <u><b>Array Buffer</b></u>

    &nbsp; Array Buffer 는 WebSocket, WebAssembly, Web Crypto, fetch 같은 `저수준 API가 주고받는 형태`입니다.

    &nbsp; 브라우저와 Node.js `모두에서 쓰는 표준`이고, `원시적인 이진 데이터`를 메모리 공간에서 다루는 타입들의 바탕이 되는 가장 낮은 층입니다. 후술할 Buffer 와도 직접적인 상속관계는 아니지만 Buffer 도 결국 직접 이진 데이터에 접근하는 것이 아니라 Buffer 클래스 내부의 ArrayBuffer 을 시작점 byteOffset 과 상대적 index 값으로 참조하여 물리적 메모리 공간을 다룹니다.

    &nbsp; Blob 처럼 불변한 형태에 묶여있지 않으므로 데이터 수정은 가능하나 "어떤 눈으로(어떤 타입과 크기로) 해석해서 읽고 쓸 것인가"를 결정하는 뷰(View)가 필요합니다. 뷰 없이는 Array Buffer `자체로는 아무것도 할 수 없고`, MIME 타입이나 파일 이름 같은 메타데이터가 없어 고수준의 데이터 전송에는 사용할 수 없습니다. 저수준의 바이너리 프로토콜 파싱이나 이미지·오디오 데이터 바이트 단위 전송에는 사용할 수 있습니다.

-   <u><b>Buffer</b></u>

    &nbsp; Buffer 는 Uint8Array의 하위 클래스라서 Uint8Array가 `node.js 환경에서 할 수 있는 건 모두 할 수 있고`, 거기에 Node.js용 편의 기능이 얹혀 있습니다.

    &nbsp; 긴 010011... 이진 데이터를 시작점 byteOffset 과 상대적 길이 기반 index 값으로 바이트 단위로 접근하는 타입 배열 Uint8Array 클래스를 상속받아 `접근한 바이트 데이터를 저장하고 조작하는 기능`이 추가된 클래스가 Buffer 입니다.

    &nbsp; 파일 시스템(fs), 네트워크(net, http), crypto, DB 드라이버(pg) 같은 `Node.js 생태계가 기본으로 쓰는 바이너리 타입`입니다.

    `브라우저 환경에선 Buffer 가 없습니다.` 가능하면 브라우저에서 구동되는 코드에서는 Uint8Array를 쓰는 편이 낫습니다.

##### 개념 정리 : 바이너리 데이터 조작하기

&nbsp; Blob, Array Buffer, Buffer 객체는 서로 오브젝트 타입 변환이 가능합니다. 도표로 전부 표시하면 다음과 같습니다.

-   Diagram

    ```txt
         ┌──────┐
         │ Blob │ ⟵─── new Blob([...], {type}) ──────┐
         └───┬──┘                                     │
    await blob.arrayBuffer()                          │
             ↓                                        │
      ┌─────────────┐                          ┌──────┴─────┐
      │ ArrayBuffer │ ── new Uint8Array(ab) ⟶ │ Uint8Array │
      └──────┬──────┘                          └──────┬─────┘
             │                                    subclass
             │                                        ⭣
             │                                    ┌────────┐
             └──────────── Buffer.from(ab) ───⟶  │ Buffer │
                                                  └────────┘
    
    * new Buffer(...) 생성자는 보안 취약점(Buffer(num) 형태의
    메모리 누수 문제 등)과 사용법 혼선 때문에 Node.js v6 이후부터
    공식적으로 deprecated(지원 중단) 되었습니다. 
    Buffer.from(<ArrayBuffer>) 
    Buffer.from(<Uint8Array>) 를 써주세요.
    ```

&nbsp; 데이터 형식 변환의 예시로 Javascript 에서 컴퓨터의 특정 경로의 파일을 Blob 으로 읽어들인 뒤, 다시 해당 파일을 ArrayBuffer 를 거쳐 Buffer 로 변환하여 다시 파일로 컴퓨터에 임의의 경로에 저장하는 코드를 만들어보겠습니다.

-   『파일_경로』에 위치한 이미지를 읽어 Blob 변수에 넣는 `read(『파일_경로』)`

-   Buffer 변수를 『파일_경로』에 이미지 파일로 설치하는 `write(『파일_경로』)`

이 두 가지 함수를 나중에 모듈화하기 편하도록 fileReader 라는 객체로 묶어서 구현하겠습니다.

&nbsp; 다음의 코드는 fileReader 라는 객체를 익명 class 생성자로 생성한 예제입니다. 맨 밑의 main 부터 읽으면 이해하기 더 쉽습니다.

-   예시 코드

    ```js
    //  * 'node:' = node 내장 모듈 명시, '/promises' = promise 반환 api 묶음
    const fs = require('node:fs/promises'); //  * FileSystem 파일 Input/Output
    const path = require('node:path'); //  * Path 경로 데이터 자동 변환 및 조합 정리

    // ## I/O Interface =================================================

    // ### File I/O Interface

    const fileReader = new (class {
        // #### Read
        
        /**
         * @example
         *     //  * Input
         *     const fileBlob = await fileReader.read('C:/images/example.jpg');
         */
        async read(filePath) {
            filePath = filePath.trim().replace(/^['"]+|['"]+$/g, '');
            const extension = path.extname(filePath).toLowerCase();

            //  * 파일 확장자 -> MIME 타입
            const mimetypes = {
                '.png': 'image/png',
                '.jpg': 'image/jpeg',
                '.jpeg': 'image/jpeg',
                '.gif': 'image/gif',
                '.webp': 'image/webp',
                '.bmp': 'image/bmp',
            };

            const buffer = await fs.readFile(filePath);
            const mimetype = mimetypes[extension] || 'application/octet-stream';

            //  * File 는 Blob(Binary Large Object) 의 자식클래스 (File extends Blob)
            return new Blob([buffer], { type: mimetype });
        }

        // #### Write

        /**
         * @example
         *     //  * Output
         *     await fileReader.write('C:/images', Buffer.from(await fileBlob.arrayBuffer()), fileBlob.type);
         * @param {string} filePath - 파일 저장 경로
         * @param {Buffer} fileBuffer
         * @param {string} mimetype - (예: 'image/png', 'image/jpeg')
         * @param {string|null} fileName - 파일명 (확장자 제외), null이면 자동생성
         * @returns {void}
         */
        async write(filePath, fileBuffer, mimetype, fileName = null) {
            //  * MIME 타입 -> 파일 확장자
            const extensions = {
                'image/png': '.png',
                'image/jpeg': '.jpg',
                'image/gif': '.gif',
                'image/webp': '.webp',
                'image/bmp': '.bmp',
            };

            const extension = extensions[mimetype];
            if (!extension) throw new Error(`Unsupported image type: ${mimetype}`);

            if (!fileName) {
                const now = new Date();

                //  * 0000 ~ 9999
                const year = now.getFullYear();
                //  * 01 ~ 12
                const month = String(now.getMonth() + 1).padStart(2, '0');
                //  * 01 ~ 31
                const day = String(now.getDate()).padStart(2, '0');
                //  * 00 ~ 23
                const hours = String(now.getHours()).padStart(2, '0');
                //  * 00 ~ 59
                const minutes = String(now.getMinutes()).padStart(2, '0');
                //  * 000 ~ 999
                const milliseconds = String(now.getMilliseconds()).padStart(3, '0');

                fileName = `${year}-${month}-${day}-${hours}-${minutes}${milliseconds}`;
            }

            const outputPath = path.join(filePath, `${fileName}${extension}`);

            console.log(`outputPath: ${outputPath}`);
            console.log(`filePath: ${filePath}`);
            console.log(`fileName: ${fileName}`);

            await fs.mkdir(filePath, { recursive: true });
            await fs.writeFile(outputPath, fileBuffer);
            return;
        }
    })();


    // ## Main ==========================================================

    async function main() {
        //  * 'C:/images/example.jpg' 파일 읽기
        const fileBlob = await fileReader.read('C:/images/example.jpg');
        
        //  * 'C:/images/' 경로에 파일로 저장하기
        await fileReader.write('C:/images', Buffer.from(await fileBlob.arrayBuffer()), fileBlob.type);
    }

    // ## Run ===========================================================

    main();
    ```

&nbsp; 실행되는 메인 함수를 봅시다. 'C:/images/example.jpg' 경로의 파일을 읽어서 fileBlob 변수에 저장한 뒤에 곧바로 'C:/images' 경로에 읽어들인 파일을 다시 저장합니다.

&nbsp; 'C:/images/' 경로에 'example.jpg' 파일을 넣고 해당 코드를 node 로 구동하면, 복사 후 붙여넣기 하듯 똑같은 파일이 하나 더 생성됩니다.

##### 2-4 URL Request 코드

&nbsp; 각 get, post 등의 url 요청은 [DB 서비스 예제 2-1 : 서비스 설계](#db-서비스-예제-2-1--서비스-설계) 항목을 참고해주세요. 코드는 길지만 각 함수의 동작 목표에 집중하면서 읽으면 어려운 내용은 없습니다.

-   urlReq.js

    ```js
    // # Node.js Fetch Request form
    // = ================================================================

    //  * 'node:' = node 내장 모듈 명시, '/promises' = promise 반환 api 묶음
    const fs = require('node:fs/promises'); //  * FileSystem 파일 Input/Output
    const path = require('node:path'); //  * Path 경로 데이터 자동 변환 및 조합 정리
    const readline = require('node:readline/promises'); //  * ReadLine 콘솔 입력 줄 처리

    // ## I/O Interface =================================================

    // ### Console I/O Interface

    const reader = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
    });

    // ### File I/O Interface

    const fileReader = new (class {
        // #### Read

        /**
         * @example
         *     //  * Input
         *     const fileBlob = await fileReader.read('C:/images/example.jpg');
         */
        async read(filePath) {
            filePath = filePath.trim().replace(/^['"]+|['"]+$/g, '');
            const extension = path.extname(filePath).toLowerCase();

            //  * 파일 확장자 -> MIME 타입
            const mimetypes = {
                '.png': 'image/png',
                '.jpg': 'image/jpeg',
                '.jpeg': 'image/jpeg',
                '.gif': 'image/gif',
                '.webp': 'image/webp',
                '.bmp': 'image/bmp',
            };

            const buffer = await fs.readFile(filePath);
            const mimetype = mimetypes[extension] || 'application/octet-stream';

            //  * File 는 Blob(Binary Large Object) 의 자식클래스 (File extends Blob)
            return new Blob([buffer], { type: mimetype });
        }

        // #### Write

        /**
         * @example
         *     //  * Output
         *     await fileReader.write('C:/images', Buffer.from(await fileBlob.arrayBuffer()), fileBlob.type);
         * @param {string} filePath - 파일 저장 경로
         * @param {Buffer} fileBuffer
         * @param {string} mimetype - (예: 'image/png', 'image/jpeg')
         * @param {string|null} fileName - 파일명 (확장자 제외), null이면 자동생성
         * @returns {void}
         */
        async write(filePath, fileBuffer, mimetype, fileName = null) {
            //  * MIME 타입 -> 파일 확장자
            const extensions = {
                'image/png': '.png',
                'image/jpeg': '.jpg',
                'image/gif': '.gif',
                'image/webp': '.webp',
                'image/bmp': '.bmp',
            };

            const extension = extensions[mimetype];
            if (!extension) throw new Error(`Unsupported image type: ${mimetype}`);

            if (!fileName) {
                const now = new Date();

                //  * 0000 ~ 9999
                const year = now.getFullYear();
                //  * 01 ~ 12
                const month = String(now.getMonth() + 1).padStart(2, '0');
                //  * 01 ~ 31
                const day = String(now.getDate()).padStart(2, '0');
                //  * 00 ~ 23
                const hours = String(now.getHours()).padStart(2, '0');
                //  * 00 ~ 59
                const minutes = String(now.getMinutes()).padStart(2, '0');
                //  * 000 ~ 999
                const milliseconds = String(now.getMilliseconds()).padStart(3, '0');

                fileName = `${year}-${month}-${day}-${hours}-${minutes}${milliseconds}`;
            }

            const outputPath = path.join(filePath, `${fileName}${extension}`);

            console.log(`outputPath: ${outputPath}`);
            console.log(`filePath: ${filePath}`);
            console.log(`fileName: ${fileName}`);

            await fs.mkdir(filePath, { recursive: true });
            await fs.writeFile(outputPath, fileBuffer);
            return;
        }
    })();

    // ## Database Access API ===========================================

    // ### GET | /api/test | PostgreSQL 연결 테스트
    
    async function getApiTest() {
        //  * 형태 1: fetch promise 객체를 반환하는 형태
        //  * fetch() 에 별도 HTTP method 지정이 없으면 기본값은 GET
        return fetch('http://localhost:3000/api/test')
            .then((response) => {
                if (!response.ok) throw new Error(`HTTP ${response.status}`);
                return response.json();
            })
            .then((data) => console.log('성공:', data))
            .catch((error) => console.error('에러:', error));
    }

    // ## GET | /api/leaderboard | 조회수 상위 10개 조회

    async function getApiLeaderboard() {
        //  * 형태 2: 안전하게 try 로 감싼 형태, 대신 에러를 먹어버림
        try {
            const response = await fetch(`http://localhost:3000/api/leaderboard`);

            //  * 대충 찍는 에러로그
            // if (!response.ok) throw new Error(`HTTP ${response.status}`);

            //  * 좀더 자세한 에러로그
            if (!response.ok) {
                const errorData = await response.json().catch(() => null);
                throw new Error(errorData?.message || `HTTP ${response.status}`);
            }

            const data = await response.json();

            console.log('성공:', data);
        } catch (error) {
            console.error('에러:', error);
        }
    }

    // ## POST | /api/:imageId | 새로운 이미지 추가

    /**
     * @example
     * -   HTML
     *     ```html
     *     <input type="file" id="image-file" accept="image/*">
     *     <button onclick="handleUpload()">업로드</button>
     *     ```
     *
     * -   JavaScript
     *     ```js
     *     const fileInput = document.querySelector('#image-file');
     *     async function handleUpload() {
     *         const file = fileInput.files[0];
     *         const data = await postApiImage(100, file);
     *     };
     *     ```
     */
    async function postApiImage(imageId, file) {
        //  * 형태 3: 가장 단순한 형태
        const formData = new FormData();
        formData.append('image', file); // multer.single('image')와 이름을 맞춘다.

        const response = await fetch(`http://localhost:3000/api/${imageId}`, {
            method: 'POST',
            body: formData, // Content-Type 헤더가 multipart/form-data로 자동 설정됨.
        });

        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const data = await response.json().catch(() => null);
        return data;
    }

    // * PATCH | /api/:imageId | 기존 이미지 업데이트

    async function patchApiImage(imageId, file) {
        const formData = new FormData();
        formData.append('image', file);

        const response = await fetch(`http://localhost:3000/api/${imageId}`, {
            method: 'PATCH',
            body: formData,
        });

        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const data = await response.json().catch(() => null);
        return data;
    }

    //  * DELETE | /api/:imageId | 이미지 삭제

    async function deleteApiImage(imageId) {
        const response = await fetch(`http://localhost:3000/api/${imageId}`, {
            method: 'DELETE',
        });

        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const data = await response.json().catch(() => null);
        console.log(data ? `성공: ${data}` : `실패`);
    }

    //  * GET | /api/:imageId | 이미지 조회 Blob (웹브라우저 용)

    /**
     * @example
     *
     * -   HTML
     *
     *     ```js
     *     const blob = await getApiImageBlob(100);
     *     const imageUrl = URL.createObjectURL(blob);
     *     document.querySelector('#preview').src = imageUrl;
     *     ```
     *
     * -   Node.js
     *
     *     ```js
     *     const getImageId = await reader.question('Image ID: ');
     *     const imagePath = await reader.question('Image Path: ');
     *     const imageBlob = await getApiImage(getImageId).catch(() => { process.exitCode = 1; });
     *
     *     await fileReader.write(
     *         imagePath,
     *         Buffer.from(await imageBlob.arrayBuffer()),
     *         imageBlob.type,
     *     );
     *     ```
     */
    async function getApiImage(imageId) {
        const response = await fetch(`http://localhost:3000/api/${imageId}`);

        if (!response.ok) throw new Error(`HTTP ${response.status}`);
        const blob = await response.blob().catch(() => null);
        return blob;
    }

    // ## Main ==========================================================

    async function main() {
        while (true) {
            const input = await reader.question(
                [
                    '',
                    '0: EXIT   | Program Exit',
                    '1: GET    | /api/test               | 연결 테스트',
                    '2: GET    | /api/leaderboard        | 조회수 상위 10개 조회',
                    '3: POST   | /api/:imageId           | 새로운 이미지 추가',
                    '4: PATCH  | /api/:imageId           | 기존 이미지 업데이트',
                    '5: DELETE | /api/:imageId           | 이미지 삭제',
                    '6: GET    | /api/:imageId           | 이미지 조회',
                    '\nInput Number: ',
                ].join('\n'),
            );

            const num = Number(input);

            switch (num) {
                case 0:
                    console.log('Exiting...');
                    reader.close();
                    return;
                case 1:
                    await getApiTest();
                    break;
                case 2:
                    await getApiLeaderboard();
                    break;
                case 3: {
                    const imageId = await reader.question('Image ID: ');
                    const imagePath = await reader.question('Image Path: ');
                    await postApiImage(imageId, await fileReader.read(imagePath));
                    break;
                }
                case 4: {
                    const imageId = await reader.question('Image ID: ');
                    const imagePath = await reader.question('Image Path: ');
                    await patchApiImage(imageId, await fileReader.read(imagePath));
                    break;
                }
                case 5: {
                    const delImageId = await reader.question('Image ID: ');
                    await deleteApiImage(delImageId);
                    break;
                }
                case 6: {
                    const getImageId = await reader.question('Image ID: ');
                    const imagePath = await reader.question('Image Path: ');
                    const imageBlob = await getApiImage(getImageId);

                    await fileReader.write(
                        imagePath,
                        Buffer.from(await imageBlob.arrayBuffer()),
                        imageBlob.type,
                    );

                    break;
                }
                default:
                    console.log('Wrong input.');
                    break;
            }

            const answer = await reader.question('\nContinue? (Y*/n): ');
            if (!['y', ''].includes(answer.trim().toLowerCase())) {
                console.log('Exiting...');
                reader.close();
                return;
            }
        }
    }

    // ## Run ===========================================================

    main();
    ```

&nbsp; 다음 코드를 `node urlReq.js` 같은 명령어로 실행시키면 URL 요청을 보내는 테스트를 할 수 있습니다. 강제 종료는 다른 프로그램들과 마찬가지로 구동 중인 터미널에서 <kbd>ctrl</kbd> + <kbd>c</kbd> 입니다.

&nbsp; 기능의 개발은 끝났습니다. 이제 여러분은 사진첩을 인터넷 상에서 운영할 능력을 갖추셨습니다.

#### DB 서비스 예제 2-5 : CommonJS ⟶ ES Modules

&nbsp; 사실상 코드 개발은 끝났지만, 코드를 정리하는 과정을 진행합니다.

&nbsp; ES6 이후에 시작된 Javascript 문법의 통일성을 갖추는 작업을 하겠습니다.

##### 개념정리 : 모듈시스템 CommonJS 와 ES Modules

JavaScript의 시작은 웹 브라우저에서 간단한 동작을 구현하기 위해 만들어진 언어입니다. 초창기에는 HTML 파일 안에 `<script> var foo = 1; ... </script>` 처럼 script 태그 안에 JavaScript를 직접 작성하는 방식으로 사용하였습니다.

하지만 Javascript 환경이 커지고 복잡한 기능 구현 및 프로그램 제작에 쓰이기 시작하면서 하나의 블록 안에 모두 적으려니 여러 애로사항이 발생하였습니다.

-   코드가 너무 길어져서 기능에 따라 분할하고 싶다.
-   다른 파일의 함수를 가져와서 사용하고 싶다.
-   각 기능의 함수, 변수가 충돌하지 않았으면 좋겠다.
-   어떤 파일이 어떤 기능에 의존하는지 명확하게 확인하고 싶다.

이런 문제점을 해결하고자 2009년에 node.js 에서 모듈화를 지원하는 모듈 시스템의 표준을 도입한 것이 CommonJS 입니다. node.js 환경과 Javscript 언어가 폭발적인 인기를 끌기 시작하자 require, module.exports 라는 도구에 기반한 방식이 아니라 타 프로그래밍 언어처럼 "언어 차원에서 공식적인 모듈 문법이 필요하다" 고 판단하면서 2015년에 javascript ES6 문법을 정의하면서 Javascript 에 import, export 가 언어 내에 정식으로 추가되었습니다.

2017년 이후에 브라우저에서 ES6 문법 기능들을 본격적으로 지원하면서 node.js 의 레거시 코드들도 최신 ES6 문법 기준으로 정리해나가는 추세입니다. Javascript 는 높은 자율성과 함께 발전 속도가 빠른 언어입니다. typescript 같이 javascript 의 안전성을 강화하는 아이디어들도 있지만 이는 나중에 다루도록 하겠습니다.

-   <u><b>CommonJS (require / module.exports)</b></u>

    &nbsp; Node.js 의 <u><b>CommonJS (require / module.exports)</b></u> 방식은 초창기 Javascript 스럽게 자유도 높은 모듈화를 구현하였습니다. 다음과 같은 코드로 내보내고 불러올 수 있습니다.

    -   내보내기 `module.exports = { ... };`

        ```js
        //  * math.js
        function add(a, b) { return a + b; }
        function substract(a, b) { return a - b; }
        
        module.exports = { add, substract };
        ```

    -   불러오기

        ```js
        //  * main.js
        const { add } = require('./math');

        console.log(add(10, 20));
        ```

    &nbsp; CommonJS (require / module.exports) 방식의 <u><b>장점</b></u>은 다음과 같습니다.

    -   `동적 로딩(Dynamic Loading)`을 지원하기 때문에 다른 언어의 모듈 참조(include, import) 처럼 코드 최상단에서 전역에 정적으로 로딩하지 않아도 됩니다. 코드 중간중간, 조건문이나 반복문 안에서도 require()를 자유롭게 호출할 수 있습니다. (if (condition) { const module = require('./foo'); } 처럼 if 문에 걸리지 않을 경우엔 foo.js 를 불러오지 않아도 됨. ) 또한, eval 처럼 require 함수는 문자열을 인자로 받고 판단하므로 require(`${package_name}`); 같은 테크닉을 구사할 수도 있습니다. 

    -   `직관적인 전역변수` 를 지원하여 코드파일 경로, 코드파일명도 별도의 설정 없이 __dirname이나__filename을 곧바로 쓸 수 있습니다.

    -   `호환성` 이 높습니다. Node.js 생태계의 오랜 기본값이었기 때문에 거의 모든 구형 패키지들과 완벽하게 호환됩니다.

-   <u><b>ES Modules (import / export)</b></u>
    
    &nbsp; ES Modules 방식은 CommonJS 가 가진 문법적인 약점을 해결합니다. require() 는 자유롭지만 그 자유를 위한 대가가 생각보다 큽니다. require() 는 파일 시스템에서 동기적으로 동작해야하므로 성능을 저하시킬 수 있습니다. 동적 호출한다는 것은 javascript 고질병인 동작 도중 발생하는 에러의 제어에 취약해지는 것을 의미하기도 합니다. 있는 줄 알았던 호출코드가 없었거나, 문자열 변환 오류로 require 에서 발생한 문제를 파악하지 못하여 고생하는 경우가 생길 수 있습니다. 
    
    문법 설계적으로도 좋지않으며
    
    ES6 표준 제정(2015) 이후로 시간이 꽤 흘렀기 때문에 표준 문법과의 괴리감도 문제가 됩니다.

    다음과 같은 코드로 코드를 공개하고, 공개된 코드를 가져올 수 있습니다.

    -   내보내기 `module.exports = { ... };`

        ```js
        //  * math.js
        function add(a, b) { return a + b; }
        function substract(a, b) { return a - b; }
        
        export { add, substract };
        // export default { add: (a, b) => a + b, subtract: (a, b) => a - b}; 이런 방식도 지원함
        ```

    -   불러오기

        ```js
        //  * main.js
        import { add } from './math.js';

        console.log(add(10, 20));
        ```

    &nbsp; ES Modules (import / export) 방식의 <u><b>장점</b></u>은 다음과 같습니다.

    -   `정적 분석 (Static Analysis)` 으로 동작하기 때문에 import와 export는 반드시 파일의 최상단(Top-level)에 위치해야 합니다. 이런 엄격한 규칙은 require() 에 비해서 답답할 수는 있지만 실행 전에 코드가 어떻게 연결되어 있는지 미리 파악할 수 있어, 번들러(Vite, Webpack 등)가 불필요한 코드를 깔끔하게 제거(Tree-shaking)할 수 있습니다.

    -   `Top-level await` 를 지원합니다. 비동기 작업(데이터베이스 연결, 설정 파일 로드 등)을 모듈 최상단에서 await 키워드를 사용해 처리할 수 있습니다. (CommonJS에서는 불가능하여 async 함수로 감싸야 했습니다.)

    -   `브라우저 호환성` 이 높습니다. ES Modules 은 이제 글로벌 표준으로 브라우저와 Node.js 모두가 공식 지원하는 자바스크립트 공식 표준 스펙입니다.

    &nbsp; 자율성이 줄어들고 규칙이 엄격해졌지만 그 이상으로 표준화된 체계는 이득이 많습니다.

##### CommonJS ⟶ ES Modules 전환 작업

-   1.  package.json 수정

    &nbsp; javascript node.js 프로젝트는 프로젝트 최상단 package.json 정보로 관리됩니다. 이제까지 `$PROJECT_ROOT` 라고 불러온 express 프로젝트 폴더 최상단의 package.json 파일을 열고 값 중에서 "type": "commonjs" 값을 수정해야 합니다.

    &nbsp; 필요없는 값들은 `... omitted(생략됨) ...` 표현으로 생략했습니다. type 항목에만 집중해주세요.

    ```json
    {
        "dependencies": { ... omitted(생략됨) ... },
        
        ... omitted(생략됨) ...

        "type": "module", // <====== "type": "commonjs", 에서 수정

        ... omitted(생략됨) ...
    }
    ```

-   2.  환경변수 만들어주기 (필요할 경우)

    &nbsp; 이 부분은 지금 예시 코드에는 적용되지 않습니다. 
    
    &nbsp; 하지만 학습 중에 예시 코드를 커스텀해서 기능을 추가하셨고 그 기능에 선언한 적 없는 `__dirname` 이나 `__filename` 같은 변수가 사용되었다면 별도로 만들어주셔야 합니다.

    &nbsp; CommonJS에서는 파일 경로를 잡을 때 __dirname을 전역으로 바로 쓸 수 있었지만, ESM 환경에서는 기본적으로 제공되지 않습니다. 특히 multer로 파일 업로드 경로를 지정할 때 이 부분이 문제가 될 수 있습니다. 따라서 필요하다면 다음과 같이 `__dirname` 이나 `__filename` 변수를 만들어 줄 수 있습니다. 

    ```js
    import path from 'path';
    import { fileURLToPath } from 'url';

    const __filename = fileURLToPath(import.meta.url);
    const __dirname = path.dirname(__filename);

    // 이후 기존처럼 사용 가능
    const uploadPath = path.join(__dirname, 'uploads');
    ```

-   3.  내보내기 불러오기 표현 수정하기

    &nbsp; (require / module.exports) 표현을 (import / export) 표현으로 수정합니다. 대표값 하나를 내보낼 경우엔 export 뒤에 default 를 붙여주세요.

    &nbsp; import 는 반드시 코드의 가장 최상단에 위치해야 합니다.

    &nbsp; this 는 사용할 수 없습니다.

    &nbsp; 엄격한 경로 규칙이 적용되어 로컬 파일을 불러올 때 반드시 확장자(.js)를 붙여야 하는 것도 잊지 마세요.

    &nbsp; 크게 수정할 부분은 많지 않습니다. `<=== Common JS` 라고 지정한 부분만 수정해주시면 됩니다.

    -   db.js

        ```js
        // require('dotenv').config(); // <=== CommonJS

        // import dotenv from 'dotenv'; // <=== ES module 명시적 선언 (커스텀 가능)
        // dotenv.config({ path: './custom_path/.env' });

        import 'dotenv/config'; // <=== ES module Side-Effect import (기본 설정을 따를 경우 생략가능)

        // const { Pool } = require('pg'); // <=== CommonJS
        import { Pool } from 'pg';

        const pool = new Pool({
            host: process.env.DB_HOST,
            port: Number(process.env.DB_PORT),
            database: process.env.DB_NAME,
            user: process.env.DB_USER,
            password: process.env.DB_PASSWORD,

            max: 10,
            idleTimeoutMillis: 30000,
            connectionTimeoutMillis: 5000,
        });

        // module.exports = pool; // <=== CommonJS
        export default pool;
        ```

    -   server.js

        ```js
        // require('dotenv').config(); // <=== CommonJS
        import 'dotenv/config';

        // const express = require('express'); // <=== CommonJS
        import express from 'express';

        // const multer = require('multer'); // <=== CommonJS
        import multer from 'multer';

        // const pool = require('./db'); // <=== CommonJS
        import pool from './db.js';

        // ... omitted(생략됨) ...

        ```

##### I/O 코드 모듈화

&nbsp; ES Modules 작업을 하는 겸, URL Request 코드와 파일, 콘솔 입출력 코드를 분할하겠습니다. 

&nbsp; io.js 콘솔 입출력 코드에는 다른 프로젝트에서 사용되는 Text Reader 코드가 포함되어 있습니다. 무시해도 됩니다.

-   io.js

    ```js
    // # I/O Interface
    // = ================================================================

    //  * 'node:' = node 내장 모듈 명시, '/promises' = promise 반환 api 묶음
    import fs from 'node:fs/promises'; //  * FileSystem 파일 Input/Output
    import { readFileSync } from 'node:fs';

    import path from 'node:path'; //  * Path 경로 데이터 자동 변환 및 조합 정리
    import readline from 'node:readline/promises'; //  * ReadLine 콘솔 입력 줄 처리

    // ## Console I/O Interface =========================================

    /**
     * @example
     *     //  * Import
     *     import { consoleReader as cr } from './io.js';
     *
     *     //  * Input
     *     const msg = await cr.question('Message: ');
     *     console.log(`${msg}`);
     *     cr.close();
     */
    const consoleReader = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
    });

    // ### File I/O Interface ===========================================

    /**
     * @example
     *     //  * Import (즉시 사용할 수 있게 생성된 오브젝트를 내보냅니다.)
     *     import { fileReader as fr } from './io.js';
     *
     *     //  * Input
     *     const fileBlob = await fileReader.read('C:/images/example.jpg');
     *
     *     //  * Output
     *     await fileReader.write('C:/images', Buffer.from(await fileBlob.arrayBuffer()), fileBlob.type);
     */
    const fileReader = new (class {
        /**
         * @param {string} filePath - 불러올 파일 경로
         * @returns {Blob}
         */
        async read(filePath) {
            filePath = filePath.trim().replace(/^['"]+|['"]+$/g, '');
            const extension = path.extname(filePath).toLowerCase();

            //  * 파일 확장자 -> MIME 타입
            const mimetypes = {
                '.png': 'image/png',
                '.jpg': 'image/jpeg',
                '.jpeg': 'image/jpeg',
                '.gif': 'image/gif',
                '.webp': 'image/webp',
                '.bmp': 'image/bmp',
            };

            const buffer = await fs.readFile(filePath);
            const mimetype = mimetypes[extension] || 'application/octet-stream';

            //  * File 는 Blob(Binary Large Object) 의 자식클래스 (File extends Blob)
            return new Blob([buffer], { type: mimetype });
        }

        /**
         * @param {string} filePath - 파일 저장할 경로
         * @param {Buffer} fileBuffer
         * @param {string} mimetype - (예: 'image/png', 'image/jpeg')
         * @param {string|null} fileName - 파일명 (확장자 제외), null이면 자동생성
         * @returns {void}
         */
        async write(filePath, fileBuffer, mimetype, fileName = null) {
            //  * MIME 타입 -> 파일 확장자
            const extensions = {
                'image/png': '.png',
                'image/jpeg': '.jpg',
                'image/gif': '.gif',
                'image/webp': '.webp',
                'image/bmp': '.bmp',
            };

            const extension = extensions[mimetype];
            if (!extension) throw new Error(`Unsupported image type: ${mimetype}`);

            if (!fileName) {
                const now = new Date();

                //  * 0000 ~ 9999
                const year = now.getFullYear();
                //  * 01 ~ 12
                const month = String(now.getMonth() + 1).padStart(2, '0');
                //  * 01 ~ 31
                const day = String(now.getDate()).padStart(2, '0');
                //  * 00 ~ 23
                const hours = String(now.getHours()).padStart(2, '0');
                //  * 00 ~ 59
                const minutes = String(now.getMinutes()).padStart(2, '0');
                //  * 000 ~ 999
                const milliseconds = String(now.getMilliseconds()).padStart(3, '0');

                fileName = `${year}-${month}-${day}-${hours}-${minutes}${milliseconds}`;
            }

            const outputPath = path.join(filePath, `${fileName}${extension}`);

            console.log(`outputPath: ${outputPath}`);
            console.log(`filePath: ${filePath}`);
            console.log(`fileName: ${fileName}`);

            await fs.mkdir(filePath, { recursive: true });
            await fs.writeFile(outputPath, fileBuffer);
            return;
        }
    })();

    // ### Text I/O Interface ===========================================

    /**
     * @example
     * -   Import
     *     ```js
     *     import { TextReader } from './io.js';
     *     const tr = new TextReader('C:/example.txt');
     *     ```
     *
     * -   String line
     *     ```js
     *     while (tr.hasMoreLines()) console.log(tr.readLine());
     *     ```
     *
     * -   Int Array
     *     ```js
     *     let input = [];
     *     let iter = tr.readLine().matchAll(/[0-9]+/g);
     *     for (let curr = iter.next(); !curr.done; curr = iter.next()) input.push(curr.value[0]);
     *     input.forEach((e) => console.log(e));
     *     ```
     *
     * -   Int Matrix
     *     ```js
     *     let input = [];
     *     let iter = tr.readLine().matchAll(/[0-9]+/g);
     *     for (let curr = iter.next(); !curr.done; curr = iter.next()) {
     *         input.push([curr.value[0], iter.next().value[0]]);
     *     }
     *     input.forEach((e) => {
     *         console.log(`[${e[0]}, ${e[1]}]`);
     *     });
     *     ```
     *
     * @implNote
     * -   another way with CommonJS
     *     ```js
     *     const reader = {
     *         fullLine: () => this.fullLine,
     *         hasMoreLines: () => !!this.fullLine[this.lineIndex],
     *         readLine: (() => {
     *             this.lineIndex = 0;
     *             this.fullLine = require('fs')
     *                 // .readFileSync('dev/stdin') // 백준 입력
     *                 .readFileSync('input.txt') // 로컬 input.txt 입력
     *                 .toString()
     *                 .split(/\r\n|\r|\n/gm);
     *
     *             return () => this.fullLine[this.lineIndex++];
     *         })(),
     *     };
     *     ```
     *
     * -   another way using Closure & Factory Function
     *     ```js
     *     const createTextReader = (path) => {
     *         const lines = fs.readFileSync(path, 'utf8').split(/\r\n|\r|\n/);
     *         let lineIndex = 0;
     *
     *         return {
     *             fullLine: () => lines,
     *             hasMoreLines: () => lineIndex < lines.length,
     *             readLine: () => lines[lineIndex++],
     *         };
     *     };
     *     const textReader = createTextReader('question/input.txt');
     *     ```
     */
    class TextReader {
        #lines;
        #lineIndex = 0;

        constructor(path) {
            this.#lines = readFileSync(path, 'utf8').split(/\r\n|\r|\n/);
        }

        fullLine() {
            return this.#lines;
        }

        hasMoreLines() {
            return this.#lineIndex < this.#lines.length;
        }

        readLine() {
            return this.#lines[this.#lineIndex++];
        }
    }

    export { consoleReader, fileReader, TextReader };
    ```

-   urlReq.js

    ```js
    // # Node.js Fetch Request form
    // = ================================================================

    import { consoleReader as reader, fileReader } from './io.js';
    
    // ## Database Access API ===========================================

    // ... omitted(생략됨) ...
    ```

### DB 서비스 예제 3 (파일 클라우드)

## 추가 작업

### CORS

Express라면 cors 패키지로 간단히 해결됩니다.

```js
const cors = require('cors');
app.use(cors()); // 라우터 등록보다 먼저
```

### 개념 정리 : JWT(JSON Web Token)의 서명(Signature)

### 검색 노출

### 구글 애드센스
