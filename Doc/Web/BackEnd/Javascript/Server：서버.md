# Server：서버

## 목차

-   [Server：서버](#server서버)
    -   [목차](#목차)
    -   [HTTP IP 주소로 연결](#http-ip-주소로-연결)
        -   [Node.js 설치](#nodejs-설치)
        -   [서버 테스트](#서버-테스트)
            -   [IPv4](#ipv4)
                -   [IPv4 포트포워딩](#ipv4-포트포워딩)
            -   [IPv6](#ipv6)
                -   [IPv6 방화벽 설정](#ipv6-방화벽-설정)
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

### Node.js 설치

### 서버 테스트

먼저 본인의 IP 가 IPv4 로 할당되었는지 IPv6 로 할당되었는지 확인해야합니다. 일종의 지번주소, 도로명주소처럼 표현의 차이지만 구조상 연결방법이 완전히 달라지므로 주의해주세요.

-   IPv4 의 경우, 내부 로컬 주소가 인터넷망에 노출되지 않습니다. 따라서 인터넷과 연결된 공유기의 주소와 내 로컬주소 포트를 연결하는 포트포워딩(Port Forwarding) 작업이 필요합니다.

-   IPv6 의 경우, 연결된 모든 기기에 각기 전세계에 유니크한 IPv6 주소가 할당되기 때문에 포트포워딩 작업이 필요 없습니다. 하지만 방화벽이 외부 연결을 차단하여 보안을 지키기 때문에 테스트가 필요합니다.

#### IPv4

터널링·릴레이 등의 우회 방법을 제외하고, 일반적인 IPv4 인바운드 서버를 운영하려면, 외부 인터넷에서 보이는 공인 IPv4 주소와 내가 포트포워딩을 설정할 수 있는 장비의 WAN IPv4 주소가 동일해야 합니다.

&nbsp; 터미널(powershell 또는 cmd) 에서 `ipconfig` 를 입력하면 공유기 관리자 페이지의 <u><b>기본 게이트 웨이</u></b> 주소(공유기의 내부 IP 주소)를 알 수 있습니다. 웹 브라우저에 <u><b>기본 게이트 웨이</u></b> 주소를 주소창에 입력하여 공유기 관리자 페이지로 갈 수 있습니다. 일반적으로 관리자 비밀번호는 공유기에 적혀있습니다. 관리자 페이지에서 상위 IP 주소를 타고 올라가다보면 외부에서 이 컴퓨터에 접근가능한 공인 IP 주소를 알 수 있습니다. 이 IPv4 주소에 대하여...

-   조건1. 그 IPv4 주소에 대하여 포트포워딩 설정, 보안 설정을 만질 수 있는 권한이 있어야합니다.

-   조건2. 브라우저에서 `https://ifconfig.me/` 를 입력해서 확인하는 등, 외부에서 보는 우리의 IPv4 주소와 동일해야 합니다.

두 조건을 만족하면 가능합니다.

##### IPv4 포트포워딩

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

#### IPv6

외부망과의 직접적인 상호접근을 방화벽이 막지는 않는지, 그리고 할당된 Global IP 주소가 정상인지부터 확인해야합니다.

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

##### IPv6 방화벽 설정

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

### 서버 적용

#### 서버 적용 : 개요

본격적으로 서버를 구축합니다.

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

#### 서버 적용 : 세부 설명

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

#### Express 구동

##### Express 설치

&nbsp; 다음의 명령어, 또는 직접 탐색기를 통해서 새 폴더를 만든 뒤에 그 폴더로 이동해주세요.

```bash
mkdir example-server-project
cd example-server-project
```

&nbsp; 폴더의 이름은 어떻든 상관없습니다. 다만, 특수기호나 한글을 사용할 경우 문제가 생길 수 있습니다. 항상 개발 프로젝트 최상단 루트 폴더의 이름은 띄어쓰기 없이 소문자 영어와 하이픈으로만 만들어주세요.

&nbsp; 지금부터 이 프로젝트 폴더가 위치하는 경로를 `$PROJECT_ROOT` 라고 임시로 부르겠습니다.

&nbsp; node.js 의 npm 을 이용하여 `$PROJECT_ROOT` 에 express 를 설치해주세요. `$PROJECT_ROOT` 에서 터미널을 열고 밑의 npm 명령어를 입력합니다.

```bash
# npm 패키지 메타데이터 초기화, 패키지 모듈들의 기준점 설정(node_modules 와 package.json)
npm init -y

# Express 설치
npm install express
```

##### Express 배포할 HTML 준비

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

##### Express 구동 로컬테스트

&nbsp; 테스트용 Express 패키지를 사용하는 javascript 코드를 만들어, Express 패키지가 잘 설치됬는지 확인합니다. 

&nbsp; 프로젝트 루트에 `server.js` 파일을 생성하고, 정적 파일을 제공하도록 설정합니다.

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

```js
const express = require('express');
const path = require('path');
const app = express();
const PORT = 3000;
app.use(express.static(path.join(__dirname, 'public')));
app.listen(PORT, '127.0.0.1', () => console.log(`Server listening on http://127.0.0.1:${PORT}`));
app.listen(PORT, '::1', () => console.log(`Server listening on http://[::1]:${PORT}`));
```

&nbsp; 다음 명령어를 통해서 서버 코드를 node.js 에서 구동시킵니다.

```bash
node server.js
```

&nbsp; 이제 웹 브라우저에서 서버가 실행되는 컴퓨터의 내부 주소 `http://localhost:3000` 에 접속하여 페이지가 뜨는지 확인합니다.

&nbsp; <kbd>ctrl</kbd> + <kbd>c</kbd> 를 입력하면 서버를 종료할 수 있습니다.

##### Express 외부망 연결 및 API 테스트

&nbsp; `server.js` 파일을 본격적으로 로컬환경 뿐 아니라 모든 주소에서의 요청(임의의 IPv6 를 의미하는 `::` 와 임의의 IPv4를 의미하는 `0.0.0.0` 로 부터의 요청)을 전부 수신하도록 코드를 수정합니다. 아예 주소 값을 적지 않으면 자동적으로 무조건적으로 서버를 열게됩니다. 위 로컬테스트 코드의 경우처럼 IPv6 와 IPv4 수신을 나누어서 `::` 와 `0.0.0.0` 를 명시해도 똑같습니다.

설명이었던 주석은 정리하고 `/api/` 주소 요청 시의 API 응답 테스트 처리가 추가되었습니다.

&nbsp; 로컬테스트 코드와 마찬가지로 `/` 주소 요청 시에 `public/index.html` 를 반환한다는 내용의 코드 `app.get('/', (req, res) => {res.sendFile(path.join(__dirname, 'public', 'index.html'));});` 는 생략합니다. 별도로 언급하지 않아도 `/` 주소 요청 시에 정적파일 중에서 이름이 index 인 것을 반환하는 것이 관습적으로 기본값이기 때문입니다.

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

&nbsp; 내부 테스트와 똑같이 다음 명령어를 통해서 서버 코드를 node.js 에서 구동시킵니다.

```bash
node server.js
```

&nbsp; 이제 외부 인터넷망(예를들어, 데이터를 킨 스마트폰에서 구글 웹브라우저에 URL 주소 입력)에서 외부망 인바운드 테스트 때와 같이 `http://Global IP + 개방한 포트` 로 접근을 시도합니다. 

-   인바운드 테스트 때와 같이, ipconfig 에서 나왔던 Global IP 가 `0000:0000:0000:aaa:0000:0000:0000:0000` 이고 이번엔 개방한 포트번호가 `3000` 이므로 웹 브라우저에 `http://[0000:0000:0000:aaa:0000:0000:0000:0000]:3000/` 이라고 주소창에 입력하면 됩니다.

&nbsp; 웹브라우저에 index.html 페이지가 나왔다면 이제 API 테스트를 진행합니다. `http://Global IP + 개방한 포트/api/test` 를 입력하여 요청을 보냅니다. 

-   웹 브라우저가 `{ success: true, message: 'Express is working' }` json 객체 데이터를 서버로 부터 받아왔다면 대성공입니다.

&nbsp; <kbd>ctrl</kbd> + <kbd>c</kbd> 를 입력하면 서버를 종료할 수 있습니다.

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
