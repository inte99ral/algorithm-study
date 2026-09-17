# Server(Web, Platform)：웹 및 플랫폼 서버

## 목차

-   [Server(Web, Platform)：웹 및 플랫폼 서버](#serverweb-platform웹-및-플랫폼-서버)
    -   [목차](#목차)
    -   [개요](#개요)
    -   [HTTP IP 주소로 연결](#http-ip-주소로-연결)
        -   [Node.js 설치](#nodejs-설치)
    -   [HTTP DNS 도메인으로 연결](#http-dns-도메인으로-연결)
        -   [DNS 사이트에서 도메인 발급받기](#dns-사이트에서-도메인-발급받기)
        -   [NGINX 조정](#nginx-조정)
    -   [HTTPS 프로토콜 연결](#https-프로토콜-연결)
        -   [NGINX 80포트 개방](#nginx-80포트-개방)
        -   [win-acme 설치 및 인증서 발급](#win-acme-설치-및-인증서-발급)
        -   [NGINX 를 HTTPS 서버로 전환](#nginx-를-https-서버로-전환)
        -   [NGINX HTTP 서버 정리](#nginx-http-서버-정리)
    -   [DB 와 연결](#db-와-연결)
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

## HTTP IP 주소로 연결

### Node.js 설치

&nbsp; javascript 언어 위주로 프로젝트를 구성하기 때문에 javaScript 코드를 브라우저 밖에서 실행할 수 있게 해주는 런타임 환경인 Node.js 가 필수적으로 필요합니다.

&nbsp; Node.js 가 있다면 javaScript 코드를 브라우저 밖에서도 실행할 수 있게 되며, NPM 이라는 강력한 node.js 패키지 환경에서 편리한 라이브러리를 마음껏 사용할 수 있습니다.

&nbsp; node.js 와 npm 의 설치가 되어 있다면 이 부분을 넘겨도 됩니다. 설치 유무를 모른다면 밑의 버전 확인 명령어를 터미널에 입력해보면 됩니다.

```bash
# npm 버전 확인 명령어. 설치되어 있을 경우에 설치된 버전이 출력됨
npm -v
```

&nbsp; Windows OS 에서는 [node.js 공식 사이트](https://nodejs.org/ko/download) 에서 설치할 수 있습니다.

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
       ├── :80  → Let's Encrypt 인증용
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

이 예제에선 PostgreSQL 을 선택합니다. 많이 사용되는 mySQL 도 좋지만 새로 배우는 입장이라면 1순위로 추천받는 DB 프로그램 입니다.

PostgreSQL은 단순한 CRUD 작업 뿐 아니라 상당히 복잡한 데이터 구조까지 다룰 수 있습니다.

Prisma에서도 PostgreSQL을 공식적으로 지원하고 있으며 Neon, Supabase 같은 PostgreSQL 계열 서비스도 지원합니다.

## 검색 노출

## 구글 애드센스
