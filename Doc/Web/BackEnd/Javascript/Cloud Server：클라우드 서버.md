# Cloud Server：클라우드 서버

## 목차

-   [Cloud Server：클라우드 서버](#cloud-server클라우드-서버)
    -   [목차](#목차)
    -   [개요](#개요)
    -   [0. 로컬호스트 내부테스트](#0-로컬호스트-내부테스트)
        -   [0-1. 웹 페이지 파일 생성](#0-1-웹-페이지-파일-생성)
        -   [0-2. 브라우저에서 체크하기](#0-2-브라우저에서-체크하기)
        -   [0-3. 로컬호스트 배포 테스트](#0-3-로컬호스트-배포-테스트)
            -   [Vscode extension](#vscode-extension)
            -   [Nginx](#nginx)
    -   [1. 오라클 API 웹 배포](#1-오라클-api-웹-배포)
        -   [1-1. 네이밍 컨벤션 정리](#1-1-네이밍-컨벤션-정리)
        -   [1-2. OCI 계정생성](#1-2-oci-계정생성)
            -   [계정 만들기](#계정-만들기)
            -   [로그인 확인](#로그인-확인)
            -   [계정 도메인 정책 확인](#계정-도메인-정책-확인)
        -   [1-3. Compartment(컴파트먼트) 생성하기](#1-3-compartment컴파트먼트-생성하기)
            -   [컴파트먼트란?](#컴파트먼트란)
            -   [하위 컴파트먼트 생성하기](#하위-컴파트먼트-생성하기)
            -   [컴파트먼트 삭제하기](#컴파트먼트-삭제하기)
        -   [1-4. 버킷 생성](#1-4-버킷-생성)
            -   [블록 \& 버킷 개념정리](#블록--버킷-개념정리)
            -   [버킷 생성하기](#버킷-생성하기)
            -   [index.html 오브젝트 업로드](#indexhtml-오브젝트-업로드)
        -   [1-5. 오브젝트 URL 확인](#1-5-오브젝트-url-확인)
    -   [2. 최소 단위 정적 웹 배포](#2-최소-단위-정적-웹-배포)
        -   [2-1. VCN(가상 네트워크) 생성](#2-1-vcn가상-네트워크-생성)
            -   [VCN 개념정리](#vcn-개념정리)
            -   [VCN 생성방법](#vcn-생성방법)
            -   [VCN 과 서브넷의 이름을 바꾸고 싶다면?](#vcn-과-서브넷의-이름을-바꾸고-싶다면)
        -   [2-2. Compute VM(인스턴스) 생성 및 공용 IP 확보](#2-2-compute-vm인스턴스-생성-및-공용-ip-확보)
            -   [Compute VM 개념정리](#compute-vm-개념정리)
            -   [Compute VM 생성하기](#compute-vm-생성하기)
            -   [Error: 500 Out of capacity](#error-500-out-of-capacity)
            -   [Error: 400 Parameter 'applyJobPlanResolution' is not valid.](#error-400-parameter-applyjobplanresolution-is-not-valid)
            -   [Error: 429 Too many requests](#error-429-too-many-requests)
        -   [2단계: OCI 클라우드 방화벽(Security List) 개방](#2단계-oci-클라우드-방화벽security-list-개방)
        -   [3단계: VM 내부 OS 방화벽 개방 및 Nginx 설치](#3단계-vm-내부-os-방화벽-개방-및-nginx-설치)
        -   [4단계: index.html 배치 및 외부 접속 테스트](#4단계-indexhtml-배치-및-외부-접속-테스트)
    -   [3. 웹 도메인 연결](#3-웹-도메인-연결)
    -   [프로젝트 살 붙이기](#프로젝트-살-붙이기)
        -   [단계 1.5 (도메인 연결): "숫자 IP는 치기 귀찮네?" ➔ DuckDNS를 가져와서 VM IP 매핑하기](#단계-15-도메인-연결-숫자-ip는-치기-귀찮네--duckdns를-가져와서-vm-ip-매핑하기)
        -   [단계 2.0 (보안 적용): "주의 요함(HTTP) 경고창이 뜨네?" ➔ Certbot을 이용해 Nginx에 무료 SSL(HTTPS) 인증서 적용하기](#단계-20-보안-적용-주의-요함http-경고창이-뜨네--certbot을-이용해-nginx에-무료-sslhttps-인증서-적용하기)
        -   [단계 3.0 (아키텍처 고도화): "웹사이트에 이미지랑 동영상이 많아지니 서버 용량이 부족하고 느려지네? 서버 컴퓨터를 더 가볍게 유지하고 싶다." ➔ index.html과 정적 자원들을 Object Storage로 이사 보내고, VM은 백엔드 API 서버용으로만 쓰기](#단계-30-아키텍처-고도화-웹사이트에-이미지랑-동영상이-많아지니-서버-용량이-부족하고-느려지네-서버-컴퓨터를-더-가볍게-유지하고-싶다--indexhtml과-정적-자원들을-object-storage로-이사-보내고-vm은-백엔드-api-서버용으로만-쓰기)
    -   [OCI 시작하기](#oci-시작하기)
        -   [버킷 생성](#버킷-생성)
        -   [웹 도메인 생성하기](#웹-도메인-생성하기)
            -   [도메인 개념정리](#도메인-개념정리)
            -   [도메인 무료 생성](#도메인-무료-생성)
        -   [DNS 형성하기](#dns-형성하기)
            -   [DNS 개념정리](#dns-개념정리)
            -   [DNS 생성](#dns-생성)
        -   [가상 네트워크(VCN) 생성](#가상-네트워크vcn-생성)
        -   [가상 서버 컴퓨터(Virtual Machine, Compute Instance) 생성](#가상-서버-컴퓨터virtual-machine-compute-instance-생성)
            -   [VM 개념정리](#vm-개념정리)
            -   [① VM 생성하기](#-vm-생성하기)
            -   [② API Gateway 연동(유료)](#-api-gateway-연동유료)
        -   [커스텀 도메인(SSL 인증서 포함)을 연결하는 작업이 필요합니다.](#커스텀-도메인ssl-인증서-포함을-연결하는-작업이-필요합니다)
    -   [OCI 응용하기](#oci-응용하기)
        -   [주소 설정](#주소-설정)

## 개요

&nbsp; 클라우드로 서버 컴퓨터 환경을 제공하는 서비스들이 존재합니다. 설명 예시로 OCI(Oracle Cloud Infrastructure) 를 사용하겠습니다.

&nbsp; OCI은 다른 클라우드에 비해 **넉넉한 사양의 VM**을 영구 무료로 제공합니다. 게임 서버를 호스팅하기에 충분할 수 있습니다.

&nbsp; 또한, 무료계정 정책이 사용자 친화적이므로 AWS 에선 무료 계정임에도 특정 한도를 초과하면 자동으로 유료 서비스로 전환되어 요금이 부과되는 것과는 다르게 OCI 의 Always Free 리소스는 Always Free 아웃바운드 데이터 전송량을 초과하면 해당 리소스에 대한 추가 전송이 차단됩니다.

## 0. 로컬호스트 내부테스트

&nbsp; 이 단계에서 목표로 하는 아키텍처 구조는 다음과 같습니다.

```txt
[사용자 (웹브라우저에 파일디렉터리입력: "file:///C:/ ... /index.html")]
```

&nbsp; 내부의 html 파일을 외부 네트워크에서 접근하게 만드려면 웹과 연결하고, 보안 규칙을 설정하고, 연결한 망 위에 파일을 올리는 등 복잡한 과정을 거칩니다. 그 전에 로컬 환경에서 파일이 배포 시에 어떻게 보여질 지 정적으로 체크하겠습니다.

### 0-1. 웹 페이지 파일 생성

&nbsp; 대충 입력과 구동상태를 확인하기 위한 단순한 사이트 뭉치를 만들어줍니다.

&nbsp; 위치가 어디든 상관은 없으나 이 예시에서는 찾기 쉽도록 C:/ 드라이브 최상단에 바로 `firstLocalWeb` 이라는 이름이 폴더를 만들고 그 안에 다음의 파일 3개를 만들어주세요. IDE 개발환경이 없더라도 텍스트 파일을 만들어서 메모장에다 밑의 내용을 복사 붙여넣기한 후에 txt 확장자를 각 파일에 맞게 바꿔줘도 생성이 가능합니다. 

&nbsp; 다음 파일 3개는 각각 웹페이지의 실제몸통(html), 모양새(css), 움직임(js) 을 컴퓨터 언어로 명시한 문서입니다. 기능은 그저 웹페이지 가운데에 글씨를 띄우고, 그 글씨를 클릭하고 있는 동안에, 그리고 클릭을 멈추는 순간에 페이지 색을 바꾸는 것이 전부인 단순한 기능 테스트용 페이지 입니다.

-   index.html

    ```html
    <!doctype html>
    <html>
        <head>
            <meta charset="utf-8" />
            <meta name="viewport" content="width=device-width, initial-scale=1" />
            <title>기본 형태 BasicForm</title>
            <link href="./style.css" rel="stylesheet" />
            <script src="./script.js" defer></script>
            
            <!-- SNS 공유카드용 -->
            <meta property="og:type" content="website" />
            <!--     ● SNS 캐시용 깔끔한 대표 홈페이지 주소-->
            <meta
                property="og:url"
                content="『대충 대표페이지』예시: https://objectstorage.../index.html"
            />
            <meta property="og:title" content="『대충 공유 카드 제목』" />
            <meta property="og:description" content="『대충 공유카드 상세 설명』" />
            <!--     ● SNS 공유카드 썸네일 이미지 -->
            <meta
                property="og:image"
                content="『대충 썸네일 URL』예시: https://images.unsplash.com/photo-1618005182384-a83a8bd57fbe?auto=format&fit=crop&w=1200&q=80"
            />
            <meta name="twitter:card" content="summary_large_image" />
        </head>
        <body id="body">
            <h1 id="btn">이 글씨를 클릭하면 색상이 바뀝니다</h1>
        </body>
    </html>
    ```

-   script.js

    ```js
    const objBtn = document.getElementById('btn');
    const objBody = document.getElementById('body');
    
    const eventBodyOrange = (e) => {
        objBody.style.backgroundColor = '#FF9922';
    };
    const eventBodyGreen = (e) => {
        objBody.style.backgroundColor = '#92FF29';
    };
    
    // pointer event = mouse event + touch event 
    objBtn.addEventListener('pointerdown', eventBodyGreen);
    objBtn.addEventListener('pointerup', eventBodyOrange);
    objBtn.addEventListener('pointercancel', eventBodyOrange);
    objBtn.addEventListener('pointerleave', eventBodyOrange);
    ```

-   style.css

    ```css
    /* Default setting */
    * {
        box-sizing: border-box;
        padding: 0;
        margin: 0;
        border: 0;
    }

    body {
        width: 100vw;
        height: 100vh;
        
        display: flex;
        justify-content: center;
        align-items: center;

        color: white;
        background-color: #2f99f2;
    }
    ```

### 0-2. 브라우저에서 체크하기

&nbsp; 웹브라우저를 키고 주소창에 파일의 디렉터리 주소를 다음과 같이 입력합니다. `file:/// ... /index.html`

&nbsp; 예시와 똑같이 C드라이브 최상단의 "firstlocalweb" 폴더 안에서 만들었다면 `file:///C:/firstlocalweb/index.html` 일 것 입니다.

### 0-3. 로컬호스트 배포 테스트

&nbsp; 외부 망 연결없이 내부에서 자기 자신을 의미하는 주소 `127.0.0.1` 으로 소통하는 것도 가능하지만 웹 배포할 때 같은 것을 다시하므로 지금 하거나 익힐 필요가 없습니다. 방법은 서술하겠지만 다음단계로 가세요. 

#### Vscode extension

vscode 개발환경에선 손쉽게 테스트 해볼 수 있습니다. 

#### Nginx

nginx 을 설치해야합니다.

## 1. 오라클 API 웹 배포

&nbsp; 이전 단계에서는 외부 네트워크에는 연결되지 못하고 내선 localhost 안에서만 웹페이지가 존재하였습니다. 이번 단계에서는 <u><b>OCI(오라클 클라우드) 서비스의 무료 자원과 API를 이용</b></u>하여 외부망에 웹사이트를 노출시켜 보겠습니다.

&nbsp; 이 단계에서 목표로 하는 아키텍처 구조는 다음과 같습니다.

```txt
[사용자] ➔ [OCI API] ➔ [OCI Object Storage (Public Bucket)] ➔ [index.html(Object)]
```

### 1-1. 네이밍 컨벤션 정리

&nbsp; 앞으로 이름을 만들 일이 많기 때문에 어느 정도의 원칙을 정해두는 것이 좋습니다.

&nbsp; 특정 값들은 전세계 기준으로 유일해야하는 경우도 있기 때문에 이름짓기를 잘해야합니다.

&nbsp; 지금부터 이 예시의 프로젝트 명칭은 로컬에서 외부 망에 서비스하는 것으로 목표가 변했으므로 "fristLocalWeb" 에서 "`firstStaticWeb`" 으로 변경하겠습니다. 이 예시는 이름 짓는 규칙이 어떤 식으로 생성되는 지 그 예시로만 이해하시고 다른 이름을 사용하셔야합니다. 프로젝트명 시점에서 중복이 없을만한 것이 좋습니다.

&nbsp; 인터넷 표준 규격이 알파벳 대소문자, 숫자, 하이픈만 지원하기 때문에 모든 이름은 어지간해선 마찬가지로 알파벳 대소문자, 숫자, 하이픈만 사용하는 것이 좋습니다.

&nbsp; 분리되는 데이터는 하이픈(케밥케이스)으로 구분하며 분리되지 않은 데이터의 띄어쓰기는 대소문자(카멜케이스)로 구분합니다. 이는 인터넷 표준 규격이 알파벳, 숫자, 하이픈만 지원하기 때문입니다. 예시로 프로젝트명 "first static web" 과 개발단계 "dev(develop)" 를 붙여서 이름을 짓는다면 `firstStaticWeb-dev` 로 이름이 만들어질 것 입니다.

&nbsp; 순번 번호를 붙일 경우에는 01 부터 세는 것으로 정렬순서 문제를 조정하며 00 을 배제하여 가독성 문제를 해결합니다.

&nbsp; 앞으로도 계속해서 새로운 요소들이 추가되고 그 요소들의 이름을 작성하는 법이 나올 예정이므로 미리 이 곳에 정리해두겠습니다. 『...』는 필수적으로 적는 것이며 「...」 는 필요시에 추가합니다. 다음은 만약 프로젝트의 이름이 `first static web` 이며 development 단계일 경우의 네이밍 예시입니다.

-   <table>
    <tr class="1 ==============================================================">
    <th>요소 종류</th>
    <th>작명예시</th>
    <th>작명법</th>
    </tr>
    
    <tr>
    <td>Compartment<br />(컴파트먼트)</td>
    <td>
    
    ```txt
    root (내 계정 - 추가 생성 불가능)
    ├── production (운영 환경 권한격리 구역)
    │    ├── firstStaticWeb-prod (프로젝트 단위)
    │    ├── webResources
    │    └── dbResources
    └── development (개발 환경 접근허가 구역)
        ├── firstStaticWeb-dev (프로젝트 단위)
        ├── testServers
        └── testStorage
    ```
    
    </td>
    <td><b>『논리적 그룹에 따른 분리』-「환경(dev|stg|prod)」</b></td>
    </tr>

    <tr class="2 ==============================================================">
    <td>VCN<br />(가상네트워크)</td>
    <td>
    
    `vcn-firstStaticWeb-dev`
    
    </td>
    <td><b>vcn-『그룹』-「환경(dev|stg|prod)」「번호」</b></td>
    </tr>

    <tr class="3 ==============================================================">
    <td>Subnet<br />(VCN 서브넷)</td>
    <td>
    <ul>
    <li>
    
    `Public Subnet-vcn-firstStaticWeb-dev`
    
    </li>
    <li>
    
    `sub-firstStaticWeb-dev-pubi01`
    
    </li>
    </ul>
    
    </td>
    <td>
    <ul>
    <li>OCI 생성마법사에서 "Public Subnet-[VCN이름]" 으로 자동생성</li>
    <li>또는, <b>sub-『프로젝트』-『환경』-「보안형태(pubi|priv)」「번호」</b></li>
    </ul>
    </td>
    </tr>

    <tr class="4 ==============================================================">
    <td>VM<br />(가상 머신)</td>
    <td>
    
    `vm-firstStaticWeb-dev-web`
    
    </td>
    <td><b>vm-『프로젝트』-『환경』-「역할」「번호」</b></td>
    </tr>

    <tr class="5 ==============================================================">
    <td>Block Volume<br />(블록)</td>
    <td>
    
    `bv-firstStaticWeb-dev-web-db`
    
    </td>
    <td><b>vcn-『연결된VM이름』-「OS|사용목적」「번호」</b></td>
    </tr>

    <tr class="6 ==============================================================">
    <td>Storage Bucket<br />(버킷)</td>
    <td>
    
    `bkt-firstStaticWeb-dev-web-assetsUNIQUE01`
    
    </td>
    <td>
    <ul>
    <li><b>bkt-『연결된VM이름』-「용도(asset, media, backup 등...)」「고유번호」</b></li>
    <li>이미 고유하다면 고유번호는 필요 없습니다.</li>
    <li>버킷 이름은 전체에서 대소문자를 무시하고 중복없이 고유해야하므로 이를 주의합시다.</li>
    </ul>
    </td>
    </tr>
    </table>

### 1-2. OCI 계정생성

#### 계정 만들기

&nbsp; [oracle cloud 홈페이지](https://www.oracle.com/kr/cloud/)

&nbsp; OCI 서비스에 계정을 생성해야합니다.

&nbsp; 로그인 시 `클라우드 계정 이름`, `사용자 이름 또는 전자메일`, `비밀번호`를 요구하므로 잊으시면 안됩니다.

&nbsp; 계정 생성시에, 홈지역은 본인 국가나 그 주변 국가를 선택해야 최저 지연 시간을 보장하므로 유리하지만, 사용자들의 수와 해당 국가 서비스의 자원 보유량에 따라서 무료계정으로 자원을 확보하는 난이도가 달라지기 때문에 이 부분도 고려해야합니다. 대한민국 기준에선 다음과 같습니다.

-   <table>
    <tr><th>리전명</th><th>한국 기준 평균 지연시간</th><th>Free Tier VM 확보 난이도</th><th>추천도</th></tr>
    <tr><td>Japan East (Tokyo, ap-tokyo-1)</td><td>약 30~50ms</td><td>중간</td><th>★★★★★</th></tr>
    <tr><td>Japan Central (Osaka, ap-osaka-1)</td><td>약 35~60ms</td><td>중간~높음</td><th>★★★★☆</th></tr>
    <tr><td>South Korea Central (Seoul, ap-seoul-1)</td><td>약 5~15ms</td><td>매우 높음(경쟁 심함)</td><th>★★★☆☆</th></tr>
    <tr><td>Singapore (ap-singapore-1)</td><td>약 70~100ms</td><td>매우 높음(경쟁 심함)</td><th>★★☆☆☆</th></tr>
    <tr><td>Australia East (Sydney)</td><td>약 120ms</td><td>비교적 여유</td><th>★★☆☆☆</th></tr>
    </table>

&nbsp; 주소지는 대한민국 기준

-   동과 호수
-   건물명
-   구를 제외한 도로명주소
-   구 이름
-   도시 이름
-   우편번호

순으로 작성하면 대강 맞습니다.

&nbsp; 결제 상황을 위하여 카드를 등록해야 합니다. 가상카드나 임시생성된 카드로는 등록이 되지 않습니다. 명심해주세요.

&nbsp; 하루 이틀 뒤에 계정 생성이 완료되었다는 이메일이 옵니다.

#### 로그인 확인

&nbsp; [oracle cloud 홈페이지](cloud.oracle.com) 에 로그인 정보(클라우드 계정 이름, 사용자 이름 또는 전자메일, 비밀번호) 를 입력해서 로그인해주세요.

&nbsp; Oracle Mobile Authenticator 앱을 설치하여 로그인 시에 보안처리를 더 철저하게 할 수 있습니다.

#### 계정 도메인 정책 확인

&nbsp; OCI 는 보안을 위하여 로그인을 한 이후에 <u><b>일정 시간이 지나면 로그아웃</b></u> 시키고 세션을 만료합니다. OCI 테넌시를 처음 생성했다면 세션 만료 시간이 기본값인 1시간(60분)으로 고정되어 있습니다. 매 순간 이런 재로그인 시도가 불편하다면 다음과 같이 설정을 수정할 수 있습니다.

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Identity & Security` 
-> (Indentity 항목) `Domains` 
-> (별도 수정이 없었다면 Default 라는 이름인 도메인) `Current domain 표시인 도메인` 
-> `Settings` 
-> `Session settings` 항목에서 `Session duration` 값 변경 (최대 32767분 = 22.7일)

&nbsp; 이 작업은 작업 중 주기적인 로그아웃을 막는 것이며, 이렇게 늘려놔도 세션에 작업없이 1~2시간 정도 놔둘 경우 보안을 위해 자동 로그아웃되는 것은 막을 수 없습니다. 그 밑의 `My Apps idle timeout` 은 외부 앱에서 API 로 오라클에 접근과 연동을 한 경우의 세션 만료 시간입니다. 지금은 필요없지만 알아만 두세요.

&nbsp; 또한, OCI 는 보안을 위하여 계정 도메인의 <u><b>비밀번호에 유효기간</b></u>을 두어 일정 주기로 바꾸는 것을 요구합니다. 이를 따르는 것이 좋으나 너무 귀찮다면 다음의 방법으로 계정 도메인의 보안 정책을 조정할 수 있습니다.

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Identity & Security` 
-> (Indentity 항목) `Domains` 
-> (별도 수정이 없었다면 Default 라는 이름인 도메인) `Current domain 표시인 도메인` 
-> `Domain Policies` 
-> `Password policy` 항목 
-> `defaultPasswordPolicy` 
-> `Actions` 
-> `Edit password rules` 
-> `Expires after (days)` 항목의 값을 0 으로 

### 1-3. Compartment(컴파트먼트) 생성하기

&nbsp; 안정적인 서비스 구역과 연습용 테스트 구역을 구분하기 위하여 최상위(Root)의 하위 컴파트먼트(Compartment)를 만들어 분리하려고 합니다.

#### 컴파트먼트란?

&nbsp; 컴파트먼트는 클라우드 리소스를 논리적으로 격리하는 계층형 디렉터리(폴더) 개념입니다. 프로젝트별, 부서별, 또는 개발/스테이징/운영 환경별로 리소스(인스턴스, 네트워크, 스토리지 등)를 묶어서 관리하고 권한을 제어(IAM)하기 위해 사용합니다.

&nbsp; OCI 보안정책상, 최상위(Root) 컴파트먼트에선 static 한 html 파일을 서비스하는 정적 웹 호스팅(Static Website Hosting) 기능을 활성화 할 수 없습니다. 이는 최상위 컴파트먼트가 해당 테넌시(계정)의 모든 리소스와 마스터 권한, 결제정보가 모이는 민감한 영역이므로, 이 컴파트먼트를 호스팅해버린다면 해당 컴파트먼트의 모든 자원에 전세계 사람에 접근하도록 Public 으로 접근권한을 허용하는 행위가 되기 때문입니다. 공격자의 공격으로부터 중요 데이터의 격리가 불가능한 이런 형태를 OCI 는 원천적으로 제공하지 않으려고 합니다.

&nbsp; 컴퓨터에 최상위 구조가 `C:\` 이듯 OCI 서비스에서 최상위 컴파트먼트는 본인의 테넌시(계정, Tenancy) 가 됩니다. 그 밑으로 최대 6단계 깊이 까지 하위 컴파트먼트를 생성할 수 있으며, 보통 프로젝트와 부서 틀에 따라 다음과 같이 구조를 설계합니다.

```txt
root (내 계정 - 추가 생성 불가능)
├── production (운영 환경 권한격리 구역)
│    ├── firstStaticWeb-prod (프로젝트 단위)
│    ├── webResources
│    └── dbResources
└── development (개발 환경 접근허가 구역)
    ├── firstStaticWeb-dev (프로젝트 단위)
    ├── testServers
    └── testStorage
```

#### 하위 컴파트먼트 생성하기

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Identity & Security` 
-> (Indentity 항목) `Compartments` 
-> <kbd>Create compartment</kbd> 를 클릭합니다.

&nbsp; 생성할 때 `이름`과 `설명`과 누구를 부모로 하는 `하위 컴파트먼트` 인지 설정하면 됩니다. 설명(Description)은 그리 중요하지 않으니 지금은 그냥 `for 『컴파트먼트_이름』` 으로 적겠습니다.

&nbsp; 컴파트먼트의 이름을 작명할 때는 [1-1. 네이밍 컨벤션 정리](#1-1-네이밍-컨벤션-정리) 항목을 참고해주세요. 예시로 이 프로젝트 이름은 "first static web" 이고 "개발"중인 사항이므로, root 밑에 `development` 컴파트먼트를 생성하고, 그 밑에 하위로 `firstStaticWeb-dev` 라는 이름으로 컴파트먼트를 생성하겠습니다.

#### 컴파트먼트 삭제하기

&nbsp; 컴파트먼트는 가장 거대한 논리적 자원 구분이기 때문에 삭제할 때 상당히 귀찮습니다. 서버 담당 신입이 서버 모든 데이터를 증발시키는 대참사를 막기 위하여 컴파트먼트 삭제 시도시에 컴파트먼트 위에 데이터가 하나라도 있다면 삭제가 실패하며 취소됩니다.

&nbsp; 하지만 잘못만들었거나 정리해야하는 상황에 거대한 컴파트먼트를 일일히 삭제하는 것 또한 고통입니다. OCI 는 일일히 확인 삭제하는 것을 정책상 추천하나 OCI 공식 자원 삭제 도구인 ociextirpater를 쓰면 삭제 자동화가 가능합니다.

&nbsp; OCI 는 OCI 서비스를 제어가능한 터미널 Cloud Shell 과 사용자당 터미널용 5GB의 암호화된 영구 스토리지(Persistent Storage)를 제공합니다. 다음의 방법을 따라 Cloud Shell 쉘을 키고 ociextirpater 사용해주세요.

&nbsp; OCI 메인 화면 우측상단 컴퓨터모양 <kbd>🖳</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Cloud Shell` 를 클릭하여 터미널을 엽니다.

```bash
# 1. 오라클 공식 OCI Extirpater 도구 다운로드
git clone https://github.com/therealcmj/ociextirpater.git

# 2. 다운로드된 폴더로 이동
cd ociextirpater

# 3-1. 혹시모르니 내부에 얽힌 자원들만 먼저 싹 강제 삭제 (-dt 옵션) 후 별도로 컴파트먼트 제거
python3 ociextirpate.py -c "본인의_컴파트먼트_OCID" -dt
oci iam compartment delete --compartment-id "본인의_컴파트먼트_OCID" --force

# 3-2. 내부 자원을 싹 지운 후, 컴파트먼트 자체까지 최종 삭제하는 명령어
python3 ociextirpate.py -c "본인의_컴파트먼트_OCID" -F

# 4. ociextirpater 도 제거하기
rm -rf ~/ociextirpater
```

### 1-4. 버킷 생성

&nbsp; 정적 웹사이트 파일을 저장할 공간을 만듭니다.

&nbsp; 지금은 단순하게 index.html 을 올려서 url 로 제공하는 테스트를 하는 것이 목표이므로 "버킷" 을 생성해야 합니다.

#### 블록 & 버킷 개념정리

&nbsp; OCI 에서 파일을 저장하는 구조는 크게 두 가지 입니다. 각 데이터를 블록화 시켜서 로컬디스크처럼 사용되는 동적인 저장용량 Block volumes 과 정적으로 한 파일을 오브젝트화 시키는 Bucket 이 있습니다.

-   블록 스토리지 방식은 내부 데이터 접근 성능과 트랜잭션에 유리합니다.

    Oracle DB, MySQL 등 데이터베이스 저장소, 부팅 디스크, 고성능 애플리케이션 구동 공간을 구현한다면 서버 내부의 파일들을 1초에도 수만 번씩 데이터를 읽고 써야 합니다. 이 경우 매번 url 를 타고 네트워크를 거쳐 파일을 가져오는 방식으론 감당이 안 됩니다.
    Compute 인스턴스(서버)에 마운트하여 로컬 디스크처럼 사용하는 하드디스크 방식의 블록 스토리지가 적합합니다.

-   버킷은 대규모 확장성과 비용 절감에 유리합니다.

    이미지/동영상 업로드 파일 저장소, 정적 웹사이트 호스팅(index.html 등), 데이터 백업 및 로그 수집을 하는 경우에는 매 순간 디스크에 마운트를 시도하는 것 보다, 각 데이터에 접근할 데이터를 오브젝트로 묶어 고유한 주소(URL)를 부여하는 것이 훨씬 편리합니다.

-   짧게 요약하면 

    -   <b>애플리케이션이나 DB가 직접 엑세스해서 고성능으로 굴려야 하는 데이터 ➔ 블록</b>
    -   <b>웹 브라우저나 외부에서 API로 접근해야 하거나, 용량이 크고 자주 바뀌지 않는 데이터 ➔ 버킷</b>
    -   보통 OCI로 서비스를 구축할 때는 Compute 인스턴스 내부는 블록 볼륨으로 돌리고, 사용자들이 업로드하는 미디어 파일이나 백업은 버킷에 저장하는 방식으로 상호보완적으로 사용합니다.

#### 버킷 생성하기

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Storage` 
-> (Object Storage & Archive Storage 항목) `Buckets`
-> <kbd>Create bucket</kbd> 버튼을 클릭하여 만들 수 있습니다.

-   우선 버튼 클릭 전에, Compartment 가 Root 가 아니라 하위에 만들어뒀던 컴파트먼트인지 확인해주세요. 예시에서는 root 밑의 development 밑의 `firstStaticWeb-dev` 였습니다. 

-   다음 값만 주의하고 나머진 기본설정을 따라 버킷 생성을 완료합니다.
    -   <u><b>Bucket name :</b></u>
        &nbsp; 이름을 지을 땐 [1-1. 네이밍 컨벤션 정리](#1-1-네이밍-컨벤션-정리) 항목을 참고해주세요. (예시: `bkt-firstStaticWeb-dev-web-assets`)
        
        &nbsp; 일반적으로 버킷명은 <b>bkt-『프로젝트』-『환경』-「역할」「번호」-「용도(asset, media, backup 등...)」「고유번호」</b> 또는 VM 이 있었다면 <b>bkt-『연결된VM이름』-「용도(asset, media, backup 등...)」「고유번호」</b> 규칙을 따릅니다. 복잡해지는 이유는 버킷명은 전체에서 고유해야만 하기 때문입니다. 이미 고유하다면 고유번호를 붙일 이유는 없습니다.
    
    -   <u><b>Bucket scope :</b></u>
        &nbsp; 기본 값은 (글로벌 범위) `Namespace` 입니다. 바꿀 필요 없습니다.
    
    -   <u><b>Default storage tier :</b></u>
        &nbsp; 기본 값은 `Standard` 입니다. 바꿀 필요 없습니다.
    
    -   <u><b>Enable auto-tiering :</b></u>
        &nbsp; 기본값 `OFF` 로 놔두면 됩니다.
        
        &nbsp; Enable auto-tiering (자동 계층화 활성화) 옵션은 OCI 측에서 버킷 사용패턴을 자동감시하여, 자주 접근안하는 파일의 경우 자동으로 낮은 Tier(계층) 수준으로 내려버립니다. 파일이 수만 개가 되고 사람이 관리하기 어려워졌을 때에 OCI 측에 맡기는 옵션입니다.
    
    -   <u><b>Enable object versioning :</b></u>
        &nbsp; 기본값 `OFF` 로 놔두면 됩니다.

        &nbsp; Enable object versioning (오브젝트 버전 관리 활성화) 옵션은 git 처럼 버킷 파일의 변경이력 히스토리 로그를 관리하는 기능입니다. 파일을 잘못 수정하는 실수가 발생해도 복구할 수 있지만 로그 기록으로 인하여 저장비용이 늘어납니다.

    -   <u><b>Emit object events :</b></u>
        &nbsp; 기본값 `OFF` 로 놔두면 됩니다.

        &nbsp; Emit object events (오브젝트 이벤트 방출) 옵션은 버킷 내에 변화가 발생했을 경우에 신호를 쏴주는 기능입니다. 버킷 내에 자동화 파이프라인을 구축할 경우에 필요합니다. 
    
    -   <u><b>Uncommitted multipart uploads cleanup :</b></u>
        &nbsp; 기본값 `OFF` 로 놔두면 됩니다.

        &nbsp; Uncommitted multipart uploads cleanup (미커밋 멀티파트 업로드 정리) 옵션은 업로드 실패시에 발생한 찌꺼기 파일조각을 일정 기간 동안 감시 후 자동 삭제하는 기능입니다. 대용량 파일을 업로드하기 위하여 여러 multipart 로 분할하여 업로드를 하던 도중에 에러로 인하여 취소되는 경우 committed 은 되지 않았으나 파일 조각들이 유령처럼 남게 됩니다. API 나 CLI 를 통하여 대용량 미디어 파일과 로그를 다루는 경우에 필요한 옵션입니다. 

-   버킷 생성 후, 버킷을 클릭하여 `Details`->`Actions`->`Edit visibility`를 Public으로 설정하여 인터넷에서 파일에 접근할 수 있도록 합니다.

#### index.html 오브젝트 업로드

-   생성된 버킷을 클릭하고 <kbd>Upload objects</kbd> 버튼을 누릅니다.
-   Select files 창에서 필요한 값들을 입력하여 줍니다.

    -   **Object name prefix :**
        -   폴더 경로를 구현해야 할 때, `new_folder/` 라고 적어두면 index.html 이 저장될 때, `new_folder/` + index.html 이 되는 구조입니다. 
        -   OCI 같은 오브젝트 스토리지는 일반적인 '폴더(디렉터리)' 구조가 없습니다. 실제로는 모든 파일이 한 공간에 일렬로 늘어서는 평평한 구조(Flat Structure)이기 때문에 Prefix(접두어)를 이용해 파일 이름 앞에 `폴더명/` 을 붙여서 가상의 계층 구조를 만듭니다.
        -   역슬래시는 사용하면 안되며, 띄어쓰기 또한 되기는 하나 지저분하고 깨지기 쉬워 오작동 위험이 높습니다. 쓰지마세요.

    -   **Storage tier**
        -   그냥 standard 로 두면 됩니다.
        -   OCI의 오브젝트 스토리지는 하나의 버킷 안에 서로 다른 스토리지 티어를 가진 파일들을 섞어서 보관하는 것을 허용합니다. (단, 버킷의 기본 티어가 Standard일 때만 가능합니다.) Standard (표준)	상태와 용량당 가격이 저렴하나 꺼내는 데 제한이 있고 몇 년 동안 보관만 해두어야 하는 상태인 Archive (아카이브) 를 선택할 수 있습니다.

    -   **Additional Checksum**
        -   None 으로 비워두셔도 됩니다.
        -   Additional Checksum(추가 체크섬)은 "올린 파일이 클라우드에 올라가는 과정에서 1비트의 변형도 없이 100% 똑같이 완벽하게 도착했나?" 를 확인하는 무결성 체크입니다. 컴퓨터에서 아주아주 용량이 큰 파일(수십 GB짜리 게임 데이터나 백업 압축 파일)을 인터넷을 통해 클라우드로 업로드하다 보면, 간혹 인터넷 연결이 순간적으로 불안정해져서 파일 데이터 중 아주 미세한 일부(1비트)가 깨지거나 누락되는 일이 발생할 수 있습니다. 추가 체크섬은 다음의 과정을 거쳐 파일의 결점 여부를 파악합니다. 우선 파일의 내용을 수학적 알고리즘(MD5, SHA-256 등)을 거쳐 지문으로 만듭니다. 파일과 함께 클라우드에 보내면 클라우드에서 다시 그 파일을 알고리즘으로 지문화한 뒤에, 파일과 함께 도착한 지문과 같은 지 비교합니다. 두 지문이 같다면 무결성이 입증된 것 입니다. 일반적인 몇 GB 조차 아닌 파일들은 불필요한 과정입니다.

    -   **Choose Files from your Compute**
        -   [0-1. 웹 페이지 파일 생성](#0-1-웹-페이지-파일-생성) 단계에서 생성한 파일을 올립니다.
        -   이 항목을 통하여 파일을 오브젝트로써 버킷에 추가합니다. 창을 열어서 선택하거나, 직접 드래그를 하여 복수개의 파일이나 폴더 전체를 넣을 수도 있습니다.

    -   **Optional response headers and metadata :**
        -   특수한 목적(웹 캐싱 제어, 강제 다운로드 설정 등)이 없다면 굳이 건드릴 필요 없이 비워두셔도 됩니다.
        -   Response Header 는 이 파일을 요청한 웹 브라우저에게 "이 파일은 이렇게 처리해줘!"라고 지시하는 규칙을 넣는 곳입니다.
            -   Content-Type: OCI가 파일 확장자(.html)를 보고 자동으로 text/html로 지정해 주므로 보통은 따로 안 건드려도 브라우저가 웹페이지로 잘 인식합니다.
            -   Cache-Control: "이 파일은 자주 바뀌니까 브라우저 너는 캐시(임시 저장)하지 말고 매번 새로 읽어와!" 같은 명령을 내릴 때 사용합니다.
        -   Metadata 는 웹 브라우저와는 상관없이, 클라우드 관리자인 나를 위한 '메모지'나 '태그' 입니다. 예를 들어 Type: User-defined, Name: project-name, Value: my-homepage 같은 식으로 적어두면, 나중에 클라우드에서 수많은 파일 중 특정 프로젝트의 파일만 검색하거나 분류할 때 유용합니다.

-   배포하려는 index.html 파일을 비롯한 웹사이트의 모든 정적 파일(CSS, JS, 이미지 등)을 업로드합니다.

### 1-5. 오브젝트 URL 확인

-   index.html 을 업로드한 Bucket 의 Objects 항목으로 가면 업로드 된 파일들을 볼 수 있습니다.
-   index.html 파일 옆의 <kbd>…</kbd> 버튼을 누르고, view object details 항목을 클릭하면 나오는 팝업에서 `URL path (URI)` 를 확인할 수 있습니다.

## 2. 최소 단위 정적 웹 배포

&nbsp; 이전 단계에서는 오라클에서 오라클 서비스의 자원에 접근가능하도록 사용자들에게 제공한 API 를 통해서 index.html 에 접근하게 했습니다. 하지만 개인 포트폴리오나 실제 서비스용에 합당한 프로덕션 수준으로 발전시키기 위해선 오라클 API 에 의존하지 않고 <u><b>내가 통제하는 서버 위에서 해당 페이지를 배포</b></u>해야합니다. 이번엔 이것을 Minimum Viable Product(최소 기능 제품, MVP)으로 구현하는 것을 목표로 할 것입니다.

&nbsp; 이 단계에서 목표로 하는 아키텍처 구조는 다음과 같습니다.

```txt
[사용자 (브라우저: http://공용IP)] ➔ [OCI Compute VM (Nginx)] ➔ [OCI Object Storage (Public Bucket)] ➔ [index.html(Object)]
```

이 구조는 우리가 만든 index.html 페이지를 외부의 웹 브라우저에서 접근할 수 있게만 하는 최소한의 구조입니다. 따라서 다음의

-   문자화된 도메인 주소가 없음
-   https:// SSL 보안인증 없음
-   서버와 리소스DB가 분리되지 않고 붙어있음
-   서비스 유연성 낮음

같은 기능이 부족합니다. 이 부족한 부분들은 뒤에서 추가하도록 하겠습니다.

### 2-1. VCN(가상 네트워크) 생성

#### VCN 개념정리

OCI Compute VM (Nginx + SSL) 부분을 만드는 것이 지금 단계의 목표입니다. 우리는 VM 가상컴퓨터가 외부 인터넷망와 우리의 index.html 과 이어주는 서버 컴퓨터 역할을 수행하게 만들어야 합니다.

그걸 위해선 다음의 과정을 거처야합니다.

-   1 가상 네트워크(VCN, Virtual Cloud Network) 생성: OCI 서비스의 오라클 데이터 센서의 수만대의 거대한 물리적 서버에서 어느 정도의 구역을 나의 것으로 선언하여 소프트웨어 적으로 선을 긋고 분리하여 개념상 나만의 독립적인 가상의 네트워크망을 생성해야합니다. 본인이 통제권을 가진 네크워크가 있어야 그 위에 서버를 올릴 수 있습니다.

-   2 서브넷(Subnet) 쪼개기: VCN이라는 거대한 땅을 공개 공간(Public)과 비공개 공간(Private)으로 구역을 나눕니다.

-   3 인터넷 게이트웨이(IGW): 외부에 웹 서비스를 공개하기 위해 외부 인터넷과 연결되는 정문을 달아줍니다.

-   4 보안 목록(Security List) / 보안 그룹(NSG)지정: "80번 포트(HTTP)와 443번 포트(HTTPS)를 통해서 들어오는 사람만 허용하겠다"처럼 방화벽 규칙을 세웁니다.

-   5 그 후에 내가 통제하는 VCN 안에서 가상 웹서버 컴퓨터(VM, Virtual Machine) 인스턴스를 올립니다. 

#### VCN 생성방법

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Networking` 
-> `Virtual Cloud Networks` 화면으로 이동합니다.

&nbsp; 직접 만들 수도 있지만 Start VCN Wizard 를 통해 VCN 생성에 도움을 받을 수 있습니다.

&nbsp; <kbd>Actions</kbd> 버튼을 클릭하여 나오는 드롭다운 메뉴에서 <kbd>Start VCN Wizard</kbd> -> <kbd>VCN with Internet Connectivity</kbd> 를 선택하면 외부 통신이 가능한 Public Subnet이 자동으로 만들어집니다. 기본값들을 그대로 대입하면 됩니다. 각 값의 의미는 다음과 같습니다.

-   Basic information

    -   <u><b>VCN name :</b></u> 
        
        &nbsp; 예시로는 `vcn-firstStaticWeb-dev` 입니다. [1-1. 네이밍 컨벤션 정리](#1-1-네이밍-컨벤션-정리) 항목의 VCN 부분을 참고해주세요. 
        &nbsp; VCN의 이름입니다. 

    -   <u><b>Compartment :</b></u> VCN을 위치시킬 컴파트먼트를 지정합니다. 버킷과 같은 위치의 컴파트먼트를 지정해주세요.

-   Configure VCN
    -   <u><b>VCN IPv4 CIDR block :</b></u>
        
        &nbsp; 기본값은 `10.0.0.0/16` 입니다.
        
        &nbsp; CIDR(Classless Inter-Domain Routing) 블록은 이 VCN 가상 데이터 센터 안에서 사용할 사설 IP 주소의 범위를 지정합니다.

        &nbsp; `10.0.0.0/16` 이라고 적힌 값은 `10.0. ...` 으로 시작하는 사설 IP 대역을 사용하겠으며, `/16` 은 서브넷 마스크를 의미하여 앞의 16비트(`10.0`)를 고정하고 나머지 공간을 IP로 쓰겠다는 계약입니다. 따라서 그 의미는 `10.0.0.0` 부터 `10.0.255.255` 까지 총 65,536개의 내부 IP 주소를 확보하겠다는 의미입니다. 이것이 사설 네트워크를 구축할 때 가장 흔하게 쓰이는 표준 크기 입니다. `10.0.x.x` 의 값은 네트워크 표준 규약(RFC 1918)에 의해 `127.0.0.1` 루프백 IP 와 비슷하게 사설 네트워크 내부 통신 IP 주소를 의미합니다.

-   <u><b>Use DNS hostnames in this VCN :</b></u>
    &nbsp; 토글 스위치의 값은 `ON` 입니다.
    &nbsp; 이 옵션을 켜면 OCI가 VCN 내부용 사설 DNS 서버를 자동으로 활성화합니다. 이에 따라 VCN 안에 생성되는 모든 인스턴스(VM)는 `[인스턴스_호스트이름].[서브넷_DNS_레이블].oraclevcn.com` 규칙을 따라 고유한 내부 DNS 도메인 이름(hostname)을 가지게 됩니다. ON 일 경우 복잡하게 10.0.1.4 같은 복잡한 IP 주소 대신, web-server.sub01.myvcn.oraclevcn.com 같은 이름으로 통신할 수 있습니다. 또한 IP 가 변하는 상황에도 이 hostname 은 유지되므로 코드 수정없이 계속 사용가능합니다. 

-   <u><b>Configure public subnet :</b></u>
    
    &nbsp; 기본값은 `10.0.0.0/24` 입니다.
    
    &nbsp; 이는 거대한 방(10.0.0.0/16)의 맨 앞부분을 떼어내어 `10.0.0.0` 부터 `10.0.0.255`까지 256개의 IP를 이 구역에 할당하겠다는 소리입니다.

    &nbsp; 거대한 데이터 센터(VCN)를 통째로 쓰면 보안상 위험하므로 이렇게 외부 통신용 방과 내부 격리용 방을 격리합니다. 이 방들을 서브넷(Subnet)이라고 합니다.

    &nbsp; public subnet은 인터넷망과 직접 통신이 가능한 공공 구역입니다. 이 서브넷에 배치되는 리소스는 공인 IP(Public IP)를 할당받아 외부와 데이터를 주고받을 수 있습니다. 외부에 서비스를 노출해야 하는 API Gateway, 로드 밸런서(LB), 혹은 배포용 웹 서버가 주로 여기에 위치합니다.

-   <u><b>Configure private subnet :</b></u>
    
    &nbsp; 기본값은 `10.0.1.0/24` 입니다.
    
    &nbsp; 이는 거대한 방(10.0.1.0/16)의 맨 앞부분을 떼어내어 `10.0.1.0` 부터 `10.0.1.255`까지 256개의 IP를 이 구역에 할당하겠다는 소리입니다.

    &nbsp; private subnet은 인터넷에서 직접 접근할 수 없는 비밀 구역입니다. 철저히 격리되어 있어 내부 네트워크를 통해서만 접근이 가능하므로 보안이 강력합니다. 외부 유출이 안 되거나 백엔드 로직을 처리하는 실제 WAS 서버, 데이터베이스(DB) 등이 여기에 위치합니다.

-   <u><b>Tag :</b></u>

    &nbsp; 큰 의미는 없고 분류 및 검색용입니다.

#### VCN 과 서브넷의 이름을 바꾸고 싶다면?

&nbsp; OCI 웹 콘솔(브라우저 화면)에서는 VCN의 이름을 수정하는 버튼을 마땅히 제공하지 않습니다. 하지만 OCI CLI(명령줄 인터페이스)나 클라우드 셸(Cloud Shell)을 이용하면 명령어 한 줄로 아주 쉽게 이름을 바꿀 수 있습니다. 

&nbsp; 우선 VCN 의 고유 ID 를 확인하셔야 합니다.

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Networking` 
-> `Virtual Cloud Networks` 화면으로 이동합니다.

&nbsp; 이름을 변경하려는 VCN 을 선택하여 들어가면 해당 VCN의 Details 탭 항목으로 넘어가게 됩니다. 거기서 OCID 항목의 값을 확인해주세요.

&nbsp; OCI 메인 화면 우측상단 컴퓨터모양 <kbd>🖳</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Cloud Shell` 를 클릭하여 터미널을 엽니다.

&nbsp; 터미널에 다음의 명령어를 입력하면 VCN 의 이름을 바꿀 수 있습니다.

```bash
oci network vcn update --vcn-id "『내_VCN의_OCID』" --display-name "『새로운_VCN_이름』"
```

&nbsp; 마찬가지로 서브넷의 이름을 `sub-firstStaticWeb-dev-pubi` 같이 바꾸고 싶다면 다음과 같은 명령어로 바꿀 수 있습니다.

```bash
oci network subnet update \
    --subnet-id "『서브넷의_OCID』" \
    --display-name "『새로운_서브넷_이름』"
```

### 2-2. Compute VM(인스턴스) 생성 및 공용 IP 확보

#### Compute VM 개념정리

오라클 클라우드 위에 24시간 돌아갈 가상화 서버컴퓨터 인스턴스 Compute VM 

-   공부할 개념: 클라우드 가상 서버(VM)의 개념, OS(Ubuntu 또는 Oracle Linux) 선택.

-   할 일: OCI에서 Always Free 사양의 컴퓨터를 한 대 개설합니다. 

&nbsp; 우리가 사용할 컴퓨터(가상 서버)를 오라클 클라우드 컴퓨터에 한 대 개설하는 단계입니다. 생성이 완료되면 고정된 공용 IP(Public IP) 주소가 발급됩니다.

&nbsp; 가상의 공간에서 서버 컴퓨터를 하나 발급받는 과정이기 때문에 설정해야 하는 것이 많습니다. 집중해주세요.

#### Compute VM 생성하기

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Compute` 
-> (Compute 항목) `Instances`
-> <kbd>Create instance</kbd> 버튼을 클릭하여 만들 수 있습니다.

Applied filters 옆에 Compartment 가 대상인 컴파트먼트인지 확인해주세요 

-   Image and shape: Always Free 대상인 VM.Standard.E2.1.Micro(AMD) 또는 VM.Standard.A1.Flex(ARM, 추천) 중 하나를 선택합니다.

-   Networking: 방금 생성한 VCN의 Public Subnet을 선택하고, Assign a public IPv4 address를 체크합니다.

-   SSH Keys: SSH 접속을 위한 키 쌍을 다운로드(Save private key)합니다.

-   인스턴스 생성 완료 후 할당된 [공용 IP 주소(Public IP)]를 메모합니다.

만약 OCI 무료 티어의 자원 제한(Ampere A1 Compute 2 Core, 12GB RAM 등) 안에서 구성해야 하더라도, VM을 2개(웹용 1Core/6GB, DB용 1Core/6GB)로 쪼개어 구성하는 것이 향후 유지보수와 안정성 측면에서 훨씬 유리합니다.

Create instance 창에 적절한 값들을 넣어주세요. 각 값의 의미는 다음과 같습니다.

-   ① 단계: Basic information

    -   <u><b>name :</b></u> 
        
        &nbsp; 예시로는 `vm-firstStaticWeb-dev-web` 입니다. [1-1. 네이밍 컨벤션 정리](#1-1-네이밍-컨벤션-정리) 항목의 VM 부분을 참고해주세요. 
        &nbsp; VM instance 의 이름입니다. 
    
    -   <u><b>Compartment :</b></u> VCN을 위치시킬 컴파트먼트를 지정합니다. 별다른 이유가 없다면 VCN과 같은 위치의 컴파트먼트를 지정해주세요.

    -   Placement
        -   <u><b>Availability domain :</b></u>
            &nbsp; 기본값은 `기본으로 주는 도메인 AD1` 입니다.
            &nbsp; Availability Domain(가용성 도메인, AD)은 지금 생성하는 인스턴스(VM)가 물리적으로 어느 데이터 센터의 어느 구역에 위치할지를 말합니다. 무료계정용 도메인은 한 곳만 주어지는 경우가 대다수 입니다. 네트워크 지연(Latency) 를 최소화 하려면 같은 프로젝트의 VM 들은 같은 곳에 있는 게 좋습니다. 고가용성(HA) 나 재해복구 상황등을 고려해서 리스크 대비 차원 분리하는 경우도 있지만 이 단계 수준에서 고려하는 문제가 아닙니다.
    
    -   Image and shape
        -   <u><b>Image :</b></u>
            &nbsp; 추천값은 `Canonical Ubuntu 22.04` 입니다.
            
            &nbsp; 기본값은 최신 기준 Oracle Linux 이지만 <kbd>Change image</kbd> 를 누르고 OS 종류 Ubuntu 와 하단 밑의 버전 22.04 를 선택하여 추천값으로 수정할 수 있습니다. 오라클 리눅스는 Red Hat Enterprise Linux(RHEL) 기반이라 안정적이지만, 국내 개발 생태계나 오픈소스 레퍼런스는 Ubuntu LTS 환경이 더 풍부한 편입니다. 개발 환경의 편의성이나 사용하려는 백엔드 스택(Node.js, Docker 등)과의 호환성을 고려하여 바꾸는 것이 더 좋습니다.

            &nbsp; Ubuntu 22 LTS 버전이 웰메이드 OS로 오랜 시간 사용되면서 패키지 생태계가 최신 24 버전보다 성숙되었기 때문에 입문자들에게 선호됩니다. 에러 해결 레퍼런스도 구글링하기 쉽고 패키지 호환성도 높으며 Ampere 아키텍처와 호환성이 검증되었기 때문에 오류로 인한 스트레스를 덜 받습니다. 

            &nbsp; Canonical Ubuntu 22.04 의 "Minimal" 버전을 선택할 수도 있습니다. 이는 apt(패키지 매니저)가 작동하기 위한 최소한의 패키지만을 포함합니다. 기본 OS 보다 3GB 정도 더 가벼워 OS 용량이 수백MB 밖에 하지 않으며 RAM 사용량도 적고 패키지 보안 취약점(CVE)이 더 적습니다. 다만 curl, wget 이나 vim 같은 편의성 패키지마저 없기 때문에 따로 별도로 설치해주셔야 합니다. ARM 기반의 Ampere 칩셋을 사용할 예정이기 때문에 aarch64, 즉 x86_64이 아니라 ARM 기반에 적합한 버전을 선택해야 합니다.
            
            &nbsp; Image는 스마트폰의 공장초기화 상태나 PC의 OS 설치 파일처럼, VM이 생성될 때 기반이 되는 운영체제(OS)와 소프트웨어 환경을 선택하는 항목입니다.
        
        -   <u><b>Shape :</b></u>
            &nbsp; 추천값은 Ampere 칩셋 `VM.Standard.A1.Flex`(1core 6GB) 입니다.
            
            &nbsp; 기본값은 AMD Micro(1GB RAM) 칩셋의 VM.Standard.E2.1.Micro 이지만 <kbd>Change shape</kbd> 를 누르고 칩셋 브랜드 Ampere 와 칩셋 종류 A1 를 선택하여 추천값으로 수정할 수 있습니다. AMD Micro 사양(1GB RAM)은 메모리가 너무 적어 웹 서버나 DB를 원활하게 구동하기 어렵습니다. OCI 무료계정에서 최대 합계 2core/12GB 이므로 1core/6GB 로 분할하여 2개의 VM 을 운용하는 것이 최대한으로 무료 자원을 사용하는 전략입니다.
            
            &nbsp; Shape는 생성할 VM 인스턴스의 물리적인 하드웨어 스펙(CPU 종류, 코어 수, 메모리 크기, 네트워크 대역폭)을 결정하는 템플릿입니다. 이 가상 컴퓨터의 ROM 스토리지 메모리 용량은 후에 결정하므로 Next 를 누르고 넘어가주세요. (다만 남은 칩셋이 없다면 기본값 VM.Standard.E2.1.Micro 를 선택해주세요)

-   ② 단계: Security
    -   <u><b>Security :</b></u>
        &nbsp; 추천값은 `ON` 입니다.
        &nbsp; 무료 기능이라 쓰는 것이 좋습니다.
        &nbsp; Shielded Instances(보호된 인스턴스)는 가상 머신(VM)이 부팅될 때부터 실행되는 동안까지 펌웨어 및 OS 커널 레벨에서 악성코드나 위변조 공격이 일어나지 않도록 하드웨어 기반으로 방어해 주는 강력한 보안 기능입니다.
        
        오라클과 정식 OS 제조사(Ubuntu 등)가 디지털 서명(Signature)을 한 신뢰할 수 있는 순정 커널 코드만 부팅되도록 강제하여 가짜 운영체제나 악성 부트킷(Bootkit)를 막는 <b>Secure Boot (안전 부팅)</b>, 부팅 과정의 모든 단계(펌웨어, 부트로더, OS 커널 등)를 측정하는 <b>Measured Boot (측정된 부팅)</b>, 이런 데이터를 암호화 칩셋인 가상 <b>TPM(Trusted Platform Module)</b>에 안전하게 기록합니다.
        
        Shielded Instances와 Confidential Computing(기밀 컴퓨팅) 기능은 동시에 둘 다 켤 수 없으며, 둘 중 하나만 선택해야 합니다. 하지만 Confidential Computing 은 데이터가 메모리(RAM)에 올라가 연산되는 순간까지 전부 암호화하는 초고도의 기업용 보안 기능으로 무료계정은 지원하지 않는 기능이므로 신경쓰지 않아도 됩니다.

-   ③ 단계: Networking
    -   Primary VNIC
        -   <u><b>VNIC name :</b></u>
            &nbsp; 추천값은 vm 이름을 따라 `vnic-firstStaticWeb-dev-web` 입니다. (다음 숫자부턴 01 ... 99 넘버링을 뒤에 붙입니다.)
            &nbsp; VNIC(가상 랜카드, Virtual Network Interface Card) 는 가상 컴퓨터 본체인 VM 안의 랜카드 장치의 이름입니다. 클라우드 환경에서는 VM 본체 하나에 랜카드를 여러개 꽂아 고도화된 아키텍처를 구현하기 때문에 이 가상 랜카드들을 다루기 위해 이름으로 구분이 필요합니다.
        
        -   <u><b>Primary network :</b></u>
            &nbsp; 기본값은 `● Select existing virtual cloud network` 옵션입니다.
            &nbsp; 랜카드를 어떤 가상 네트워크망에 연결할지 결정하는 것으로, Select existing virtual cloud network은 이미 만들어 둔 가상 네트워크망(VCN)을 쓰겠다는 뜻입니다.
            
            -   <u><b>Virtual cloud network compartment :</b></u>
                &nbsp; 기본값은 `VCN이 있는 컴파트먼트`(이 예시에선 firstStaticWeb-dev) 입니다.
                &nbsp; VCN 를 어느 컴파트먼트에서 연결하는지 결정합니다.
            
            -   <u><b>Virtual cloud network :</b></u>
                &nbsp; 기본값은 `위에서 만든 VCN` 입니다(이 예시에선 vcn-firstStaticWeb-dev) 입니다.
                &nbsp; 연결할 VCN 이 뭔지를 결정합니다.
        
        -   <u><b>Subnet :</b></u>
            &nbsp; 기본값은 `● Select existing subnet` 옵션입니다.
            &nbsp; 가상 랜카드에 어떤 서브 네트워크의 랜선을 꼽을지 결정하는 것으로, Select existing subnet은 이미 만들어 둔 서브넷을 쓰겠다는 뜻입니다.
            
            -   <u><b>Subnet compartment :</b></u>
                &nbsp; 기본값은 `VCN이 있는 컴파트먼트`(이 예시에선 firstStaticWeb-dev) 입니다.
                &nbsp; Subnet 를 어느 컴파트먼트에서 연결하는지 결정합니다.
            
            -   <u><b>Virtual cloud network :</b></u>
                &nbsp; 기본값은 `위에서 만든 VCN의 Subnet(public)` 입니다(이 예시에선 sub-firstStaticWeb-dev-pubi) 입니다.
                &nbsp; 이름을 굳이 수정하지 않았다면, 디폴트 이름인 Public subnet-... 같은 이름일 것 입니다. 연결할 Subnet 이 뭔지를 결정합니다. 공개된 퍼블릭 서브넷을 골라야 외부로 서비스를 제공할 수 있습니다.
        
        -   Private IPv4 address assignment
            -   <u><b>Subnet IPv4 prefixes :</b></u>
                &nbsp; 기본값은 `10.0.0.0/24`, VCN 만든 당시에 지정한 내부 서브넷 IP 주소 입니다.
                &nbsp; 이름을 굳이 수정하지 않았다면, 디폴트 이름인 Public subnet-... 같은 이름일 것 입니다. 연결할 Subnet 이 뭔지를 결정합니다. 공개된 퍼블릭 서브넷을 골라야 외부로 서비스를 제공할 수 있습니다.

            -   <u><b>Private IPv4 address :</b></u>
                &nbsp; 기본값은 `Automatically assign private IPv4 address` 입니다.
                &nbsp; 10.0.0.0/24 대역폭에서 사용하고 있지 않은 가장 빠른 유효 IP 주소를 OCI 측에서 자동으로 찾아 할당하는 옵션입니다. 클라우드 인프라의 DHCP(Dynamic Host Configuration Protocol) 서비스와 유사하게 작동하며, 개발자가 주소를 직접 고민할 필요가 없습니다. 웹 서버는 사설 IP 자체가 고정될 필요가 없거나, 도메인 연결 및 외부 통신 시 '공용 IP(Public IP)' 또는 로드 밸런서 인터페이스를 주로 바라보기 때문에 자동 할당으로 비워두는 것이 표준 관행입니다.

                &nbsp; Manually assign private IPv4 address 옵션은 개발자가 직접 10.0.0.50 같이 직접 IP 주소를 지정합니다. 해당 주소가 비어있지 않다면 오류가 발생합니다. 이 경우는 웹서버처럼 어떤 IP 이던 DNS 로 제공만되면 상관없는 경우와 다르게 DB 서버용 VM 처럼 서버 교체시에도 IP 주소가 변하면 안될 때 고려해볼 옵션입니다.
                
                &nbsp; Provide existing private IPv4 OCID 옵션은 OCI 가 전체 서비스 시스템적으로 관리하는 고유식별자 OCID 로 맵핑하는 옵션입니다. OCI 가 관리하는 이 ID 는 VM 오류이나 서브넷 충돌과 무관하므로 마이그레이션/재해복구 상황에서 사용됩니다.
        
        -   Public IPv4 address assignment
            -   <u><b>Automatically assign public IPv4 address :</b></u>
                &nbsp; 기본값은 `ON` 입니다.

                &nbsp; 외부 VCN 을 거쳐 VM 서버에 접속할 수 있도록 VM 에 대한 공인 IP를 발급할지 말지를 결정합니다.

                &nbsp; ON 인 상태가 웹 서버에선 필수입니다. 외부 인터넷 망에서 VM 에서 호스트하는 웹서버로 접근할 수단(IP)이 없기 때문입니다.
                
                &nbsp; OFF 인 상태가 DB 서버에선 필수입니다. DB 는 외부에 직접 노출되선 안되며 내부에서만 관리되어야 합니다.
            
            -   <u><b>IPv6 address assignment :</b></u>
                &nbsp; 비활성화 옵션입니다. 지금 연결된 VCN 을 만들 때 굳이 IPv6 를 지원하게 만드는 귀찮은 작업을 하지 않았기 때문에 IPv6 주소는 지원하지 않습니다.
        
        -   <u><b>Add SSH keys :</b></u>
            &nbsp; 추천값은 `● Upload public key file (.pub)` 옵션을 선택하고 <kbd>Download Private Key</kbd>버튼을 눌러 보안키를 설치합니다.

            &nbsp; 이는 원격접속 보안키 설정입니다. 보안키 자물쇠-열쇠 쌍을 직접 컴퓨터에서 생성하는 옵션과 OCI 에게 부탁하는 방법이 있습니다. 직접 만드는 쪽을 추천합니다.

            -   ● Upload public key file (.pub)(직접 생성)
                
                &nbsp; windows OS 에서 파워쉘을 열고 다음의 명령어를 입력하여 RSA 알고리즘으로 보안키 자물쇠-열쇠 쌍을 직접 컴퓨터에서 생성합니다.
                
                ```bash
                # ssh-keygen : SSH 쌍 생성 명령어입니다.
                # -t rsa : 암호화 알고리즘 type 을 RSA 로 합니다.
                # -b 4096 : 암호화 비트 용량(보안수준)을 기본 2048의 두배 4096으로 합니다.
                # -f 『파일위치』 : 만들 파일이름입니다.
                ssh-keygen -t rsa -b 4096 -f oci_vm.key

                # 입력 이후, passphrase(추가보안비밀번호) 여부를 묻습니다. 공백으로 엔터를 입력하면 사용하지 않는 것 입니다.
                # 생성 이후, fingerprint 파일 지문이 출력됩니다. 이는 전문적인 개발 시에 해당 키에 왜곡이 없는지 교차 대조용으로만 사용됩니다. 기억해두실 필요 없습니다.
                ```

                &nbsp; 생성이 완료되었다면 다음의 방법으로 정상적인 자물쇠-열쇠 쌍인지 체크할 수 있습니다.

                ```bash
                # 키 파일의 지문을 체크합니다
                # private와 public 의 지문이 똑같아야 정상입니다.
                ssh-keygen -l -f 『파일이름』

                # priavte key 에서 public 텍스트를 추출해냅니다.
                # 비밀번호 passphrase 가 있다면 입력해야합니다.
                # 이 텍스트와 기존 public key 의 텍스트 내용이 똑같아야합니다.
                ssh-keygen -y -f 『Private 파일이름』
                ```

            -   ● Generate a key pair for me(OCI 위탁 생성)
                &nbsp; 기본값은 ● Generate a key pair for me 옵션 입니다. 이 옵션을 선택한다면 <kbd>Download Private Key</kbd>버튼을 눌러 보안키를 설치합니다.
                &nbsp; 이 다운로드 받은 보안키는 절대로 분실해선 안됩니다.
            
            -   사용예시

                &nbsp; 리눅스 서버의 보안키 인증서를 생성하는 방법에 대한 옵션입니다. 리눅스 서버는 보안상 일반적인 ID/비밀번호 로그인을 허용하지 않으며 암호화 키 파일쌍(비공개열쇠 .key 와 공개자물쇠 .key.pub)을 통해서만 원격접속(SSH) 를 허용합니다. 따라서 Private key 인증용 파일을 분실할 경우 이 VM 은 OCI 관리자도 접근 못합니다. VM 을 포기하고 통으로 삭제하거나 블록 볼륨만이라도 어떻게든 분리하여 데이터만이라도 살리는 것 말고는 할 수 있는 것이 없으므로 주의하세요.
                
                &nbsp; 지금은 못하지만 후에 다음과 같은 명령어로 VM에 원격접속이 가능합니다.
                ```bash
                ssh -i "D:/.../ssh-key.key ubuntu@서버_공용_IP"
                ```
                &nbsp; Unix 기반 OS 에선 가끔 권한이 가볍다고 판단 되면 "Permissions are too open" 에러를 유발할 때가 있습니다. 이땐 다음의 명령어로 소유자만 읽을 수 있도록 보한 권한을 잠궈주시면 됩니다.
                
                ```bash
                # 4: 파일 소유자(IUser)는 읽기(Read=4) 권한을 가진다.
                # 0: 나와 같은 그룹에 속한 다른 사용자들에겐 아무 권한도 주지 않는다(0).
                # 0: 이 컴퓨터에 로그인할 수 있는 제3의 외부인에겐 아무 권한도 주지 않는다(0).
                chmod 400 vm-key.key
                ```

-   ④ 단계: Storage
    -   Boot volume
        -   <u><b>Specify a custom boot volume size and performance setting :</b></u>
            &nbsp; 추천값은 `Off` 입니다.
            
            &nbsp; Specify a custom boot volume size and performance setting (사용자 정의 부트 볼륨 크기 및 성능 설정) 옵션은 기본 제공되는 OS의 최소 부팅용 볼륨 50GB 과 부팅 성능을 수동으로 지정하는 옵션입니다.
            
            &nbsp; Nginx 서버 구성엔 50GB 로 충분합니다. OCI 무료계정은 총합 200GB 까지만 무료로 제공받기 때문에 최소한만 사용하는 것이 좋습니다.
        
        -   <u><b>Use in-transit encryption :</b></u>
            &nbsp; 추천값은 `On` 입니다.
            
            &nbsp; Use in-transit encryption (전송 중 암호화) 옵션은 인스턴스(Compute)와 호스트 하드웨어에 연결된 부트 볼륨/블록 볼륨 간에 이동하는 모든 데이터를 암호화할지를 묻습니다.
            
            &nbsp; OCI 보안 모범 사례(Security Best Practices)에 따라 전송 중 암호화는 기본적으로 활성화하는 것이 권장되며, 인스턴스 성능에 미치는 영향이 미미하면서도 데이터 보안성을 높여줍니다.
        
        -   <u><b>Encrypt this volume with a key that you manage :</b></u>
            &nbsp; 추천값은 `Off` 입니다.
            
            &nbsp; Encrypt this volume with a key that you manage (사용자 관리 키로 이 볼륨 암호화) 옵션은 오라클이 기본적으로 관리하는 암호화 키 대신, 사용자가 OCI Vault(볼트) 서비스에서 직접 생성한 마스터 암호화 키(CMK)를 사용하여 디스크를 암호화하는 옵션입니다. OCI에서 기본적으로 제공하는 Oracle-managed key로도 데이터는 완벽히 암호화되어 보호됩니다. 컴플라이언스나 기업 보안 정책상 키의 라이프사이클을 직접 제어해야 하는 상황이 아니라면, Nginx 프록시 서버 목적상 별도의 Vault 구성 없이 기본값으로 두는 것이 단순하고 효율적입니다.
    
    -   Block volumes
        &nbsp; `그대로 놔두면 됩니다.`
        
        &nbsp; 추가적으로 블록 볼륨(가상 하드디스크)을 생성한 것이 있다면 이를 더 연결할 것인지를 묻는 옵션입니다. 우리가 설계 중인 아키텍처 구조에서 핵심 웹 리소스인 index.html과 정적 자원들은 서버 내부 디스크가 아닌 OCI Object Storage(오브젝트 스토리지)에 저장됩니다. VM의 Nginx는 오직 들어오는 HTTP 요청을 받아 Object Storage의 Public URL로 토스(Reverse Proxy)해주는 역할만 수행하므로, VM 내부에 대용량 정적 파일을 저장할 필요가 전혀 없습니다. 따라서 추가적인 비용 발생이나 스토리지 낭비를 막기 위해 블록 볼륨은 추가하지 않고 그대로 인스턴스 생성을 완료하시면 됩니다.

-   Review
    &nbsp; 전체 옵션 선택지 사항들을 다시 한번 검토합니다.

#### Error: 500 Out of capacity

-   :rotating_light: $\color{#FF9922} \footnotesize \textnormal{500 Error}$ 란?
    
    &nbsp; 생성을 시도할 때, `API Error` 라며 "Out of capacity for shape VM.Standard.A1.Flex in availability domain AD-1. Create the instance in a different availability domain or try again later.If you specified a fault domain, try creating the instance without specifying a fault domain. If that doesn’t work, please try again later.Learn more about host capacity." 라는 내용으로 에러가 발생할 수 있습니다. 이는 OCI 에서 여러분들에게 가상 컴퓨터로 제공할 자원 재고가 떨어졌기 때문에 발생합니다. 누군가 본인 자원을 OCI 로 환원하던지, OCI 가 자원을 더 확충하기 전까진 이를 원천적으로는 해결할 방법이 없습니다. 이런 상황에서 차선책으로 밑의 방법을 취할 수 있습니다.

1)  자원 수준 다운그레이드
    &nbsp; Ampere 칩셋 `VM.Standard.A1.Flex`(1core 6GB)이 워낙 인기가 좋다보니 재고가 금방 동날 수 밖에 없습니다. 열화된 칩셋 AMD Micro(1GB RAM) 칩셋의 VM.Standard.E2.1.Micro 로 낮춰서 다시 시도해봅시다.

2)  될 때까지, OCI 명령을 Stack화하여 재적용하기
    
    &nbsp; 될때까지 반복실행을 하고자 한다면 이제까지의 생성 단계를 매번 다시 지정하는 것은 효율이 너무 떨어집니다.

    &nbsp; 위의 VM 생성 단계에서 Review 단계까지 갔을 경우에 <kbd>Save as stack</kbd> 을 누르면 현 요청이 테라폼(Terraform) 코드로 OCI 내부에 저장하는 창으로 넘어갑니다. Custom provider(외부 도구나 커스텀 플러그인이 사용되는지 체크) 같이 신경 쓸 필요없는 값들 입니다. <kbd>Next</kbd>와 <kbd>Create</kbd> 눌러 다음으로 넘어가면 됩니다. 이름 또한 대강 `stk-firstStaticWeb-dev-web` 등 어떻게 지어도 상관없습니다. 이렇게 생성한 Stack 들은 밑의 경로를 따라 접근할 수 있습니다.

    &nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
    -> `Developer Services` 
    -> (Resource Manager 항목) `Stacks`
    -> List scope 에서 compartment 를 선택할 수 있습니다.
    -> Stack을 클릭하면 나오는 Stacks details 에서 <kbd>Apply</kbd> 를 누르면 작업이 실행됩니다. 

3)  될 때까지, OCI CLI 스크립트 반복 매크로 돌리기

    &nbsp; 계속 Apply 를 누르는 동작도 상당히 피곤합니다. 자리를 줄 때까지 while 루프를 돌도록 하여 무한히 요청하는 방법도 있습니다. 이를 위해서 반복작업할 Stack 의 OCID 값과 터미널에서 OCI 작업을 통제가능하도록 OCI CLI 를 설치하여야 합니다. Stack 의 OCID 값은 Stack 의 Stack details 항목에서 `ocid1.ormstack.oc1...` 값을 확인할 수 있습니다. OCI CLI 는 다음의 명령어로 파워쉘에 설치할 수 있습니다. 문제가 발생했다면 [공식 문서](https://docs.oracle.com/en-us/iaas/Content/API/SDKDocs/cliinstall.htm)를 참고해주세요.

    ```ps1
    Set-ExecutionPolicy RemoteSigned -Scope Process; iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/oracle/oci-cli/master/scripts/install/install.ps1'))
    ```

    &nbsp; 명령어를 해석하면 `Set-ExecutionPolicy...;` 로 엄격한 실행정책을 일시적으로 RemoteSigned 단계로 완화하여 뒤의 줄의 스크립트를 보안상 차단하지 않도록 합니다.
    &nbsp; 이어서 `iex ...` Invoke-Expression 축약 별명 alias 인 iex 명령을 통해 OCI 가 공식적으로 제공하는 메뉴얼 가이드라인을 URL 에서 받아와 이를 구동합니다. 패키지 관리자를 통하지 않고 굳이 이런 방법을 OCI 에서 공식적으로 선호하는 이유는 OCI CLI가 파이썬(Python) 기반으로 작동하기 때문입니다. 사용자의 PC에 파이썬이 없는 경우, 저 URL 의 스크립트는 내부에 가상 파이썬 환경(Virtual Environment)을 스스로 구축하고 그 안에 CLI를 격리하여 설치해 줍니다. 윈도우 환경마다 다른 설정을 스크립트 하나로 유연하게 제어하기 위해 이 방식을 선호합니다. 최신화 업데이트 같은 패키지 제어는 `oci cli update` 같이 oci cli 패키지 내부에서 전부 제공합니다.

    &nbsp; 유닉스 스타일의 도구(OCI CLI)가 윈도우용 파이썬 환경 위에서 돌아가므로 윈도우 패키징 관례를 따릅니다. 루트폴더명은 케밥케이스, 내부파일명은 파스칼케이스를 원칙으로 하겠습니다.
    
    해당 명령 이후에 나오는 선택지는 다음과 같이 선택하는 것을 추천합니다.
    
    -   <u><b>실행 규칙 변경</b></u>
        &nbsp; `Y` 입력 후 엔터
    
    -   <u><b>In what directory would you like to place the install?</b></u>
        &nbsp; `『설치할 경로』\oracle-cli` (예시: D:\Program Files\oracle-cli)입력 후 엔터
        
        &nbsp; lib 를 설치할 경로를 묻는 질문입니다. 그냥 기본 위치에 설치하겠다면 바로 엔터만 입력해도 됩니다.
    
    -   <u><b>In what directory would you like to place the 'oci.exe' executable?</b></u>
        &nbsp; `『설치할 경로』\oracle-cli\Bin` (예시: D:\Program Files\oracle-cli\Bin)입력 후 엔터
        
        &nbsp; bin 을 설치할 경로를 묻는 질문입니다. 그냥 기본 위치에 설치하겠다면 바로 엔터만 입력해도 됩니다. 취향에 따라 다르지만 windows 는 패키지 관리가 어려운 편이라 패키지명 폴더에 /lib 과 /bin 이 같이 있는 것이 좋긴합니다.
    
    -   <u><b>In what directory would you like to place the 'oci.exe' executable?</b></u>
        &nbsp; `『설치할 경로』\oracle-cli\Libexec` (예시: D:\Program Files\oracle-cli\Libexec)입력 후 엔터
        
        &nbsp; /libexec 또는 /share 같이 실행 보조 스크립트들을 설치할 경로를 묻는 질문입니다. 그냥 기본 위치에 설치하겠다면 바로 엔터만 입력해도 됩니다. 리눅스/유닉스 스타일 개발자들이 /lib, /bin, /libexec 등을 다른 경로에 흩어놓고 관리하는 경우가 있어서 설치 시에 이렇게 물어보는 것 입니다. 다만 이번 설치파일은 /share(설명서나 아이콘같이 아키텍처에 독립적인 정적 데이터) 도 아니고 /libexec (시스템 내부적으로만 호출하는 바이너리) 도 아니지만 그나마 /libexec 에 가깝습니다.
    
    -   <u><b>What optional CLI packages would you like to be installed (comma separated names; press enter if you don't need any optional packages)?</b></u>
        &nbsp; 바로 `엔터` 치고 넘어가시면 됩니다.
        
        &nbsp; 별도의 패키지를 추가 설치하고 싶은 지 확인합니다. 별도로 필요한 것이 없으며 후에 필요하면 pip 명령으로 설치할 수 있습니다. 이후에 설치가 시작됩니다.

    -   <u><b>Modify PATH to include the CLI and enable tab completion in PowerShell now?</b></u>
        설치가 끝나고 나오는 질문입니다. 윈도우즈 환경변수 PATH 에 경로 값을 자동으로 등록해주고, PowerShell에서 탭(Tab) 자동 완성을 사용할지 묻습니다. 안할 이유 전혀없는 편리한 기능이므로 Y를 입력하는 것을 추천합니다.

    &nbsp; 위 과정을 거쳤다면 이제 windows 터미널에서 oci cli 를 사용할 수 있습니다. 파워쉘에서 `oci -h` 명령어로 도움말 목록이 뜨는 지 확인해볼 수 있습니다. 
    
    &nbsp; 이제 로그인 정보를 oci cli 에게 입력해야 합니다. 다음의 명령어를 입력해주세요.

    ```ps1
    oci setup config
    ```

    해당 명령 이후에 나오는 질문들에 다음과 같이 답해주세요.
    
    -   <u><b>Enter a location for your config:</b></u>
        &nbsp; 추천값은 `『oci cli 경로』\oracle-cli\.oci\config` 입니다. 기본값대로 입력없이 바로 엔터해도 됩니다.
        &nbsp; 유저 설정값 파일 "\config" 을 어느 경로에 저장해둘지 묻는 질문입니다. 
    
    -   <u><b>Enter a user OCID:</b></u>
        &nbsp; User OCID 입력 후 엔터. 해당 값은 OCI 접속 후 우측상단에 사람 그림을 클릭 -> 이메일 주소를 클릭하면 OCID 가 나옵니다.

    -   <u><b>Enter a tenancy OCID:</b></u>
        &nbsp; Tenancy OCID 입력 후 엔터. 해당 값은 OCI 접속 후 우측상단에 사람 그림을 클릭 -> Tenancy... 를 클릭하면 OCID 가 나옵니다.

    -   <u><b>Enter a region by index or name:</b></u>
        &nbsp; 지역코드를 적어주어야 합니다. 우측 상단~중단 쯤에 지역명이 적힌 탭이 있습니다. 클릭하여 나오는 드롭다운 창에서 <kbd>Manage regions</kbd> 을 클릭하면 현 지역코드가 "Region identifier" 에 적혀있습니다.

    -   <u><b>Do you want to generate a new API Signing RSA key pair:</b></u>
        &nbsp; `Y` 또는 바로 엔터하여, OCI용 PEM 규격 (PKCS#8 기본 권장) 키 쌍을 생성합니다.

    -   <u><b>Enter a directory for your keys to be created:</b></u>
        &nbsp; 추천값은 `『oci cli 경로』\oracle-cli\.oci` 입니다. 기본값대로 입력없이 바로 엔터해도 됩니다.

    -   <u><b>Enter a name for your key:</b></u>
        &nbsp; 기본값 `oci_api_key` 그대로 따라도 됩니다.

    -   <u><b>Enter a passphrase for your private key :</b></u>
        &nbsp; `N/A` 라고 입력 엔터 후에 재확인 체크까지 하고나면 비밀번호를 생성하지 않습니다. 추가 비밀번호 여부를 묻습니다. 개인기호입니다. 안하면 보안이 약하고 비밀번호를 추가하면 환경 시스템변수에 "OCI_CLI_PASSPHRASE" 값으로 비밀번호를 넣어줘야 하는 등 많이 귀찮습니다.

    -   <u><b>Do you want to write your passphrase to the config file? </b></u>
        &nbsp; 비밀번호를 config 파일에 저장할 지 묻습니다. `N`, 저장 안하는게 맞습니다.
    
    -   If you haven't already uploaded your API Signing public key through the
    console, follow the instructions on the page linked below in the section
    'How to upload the public key':
        &nbsp; 이 창에서 할 일은 끝났고, OCI 웹사이트에 `oci_api_key_public.pem` 을 올리러가면됩니다. 웹사이트의 우측 상단의 사람 그림을 클릭하고 User setting 을 클릭합니다. 그렇게 나온 창에서 가로 탭 중에서 <kbd>Tokens and keys</kbd> 를 클릭하면 API keys 항목이 보일 것 입니다. <kbd>Add API key</kbd> 를 눌러 public key file 을 올려주세요.
    
    -   시스템 변수 정리
        &nbsp; 마지막 작업입니다. 이 변수값 정리는 아까 config 파일을 디폴트 위치로 나뒀다면 하지 않아도 됩니다. 

        &nbsp; 작업표시줄 윈도우로고 우클릭 -> 시스템 -> 고급 시스템 설정 -> 환경 변수 로 가서 `OCI_CLI_CONFIG_FILE` 값을 `『oci cli 경로』\oracle-cli\.oci\config` 로 저장하면 끝입니다. 

    성공적으로 연결이 되었다면 다음의 명령어로 OCI 에게 통신 데이터를 받아올 수 있습니다.

    ```ps1
    # oci: 오라클 클라우드 CLI 프로그램을 실행해라.
    # os: Object Storage 서비스에 접근해라.
    # ns: Namespace 정보를
    # get: 조회해라
    oci os ns get
    ```

    성공시엔 `{ "data": "...", }` 라는 정보를 담은 json 배열이 오며, 실패시엔 `ServiceError { ... }` 에러데이터 json 배열이 반환됩니다.

    성공적이라면 이제 다음의 명령어로 무한루프를 돌 수 있습니다. 텍스트 파일에 다음 코드를 복사 붙여넣기 한 뒤, 확장자 명을 ".txt" 에서 ".ps1" 으로 바꿔준 다음에, 해당 디렉터리에 파워쉘을 열고 `./『텍스트_파일_이름』.ps1` 을 입력하여 해당 명령을 내릴 수 있습니다. 『YOUR_STACK_OCID』부분은 작업할 stack 의 ocid 를 넣어주세요.

    ```ps1
    # ===========================================================
    # OCI Resource Manager Auto Apply
    # Version 2.0.4
    # ===========================================================

    Write-Host "# OCI Resource Manager Auto Apply"

    # Loop counter
    $LoopCount = 0

    # Stack OCID
    $StackId = "『YOUR_STACK_OCID』"

    # Retry interval
    $RetrySeconds = 120

    # OCI wait option
    $WaitInterval = 60
    $MaxWait = 86400


    function Invoke-Oci
    {
        param(
            [string[]]$Command
        )

        # $err = Join-Path $env:TEMP "oci_err.txt"
        $err = Join-Path $PSScriptRoot "oci_err.txt"

        if(Test-Path $err)
        {
            Remove-Item $err -Force
        }

        Write-Host "[COMMAND]:"
        $Command | ForEach-Object { Write-Host "  $_" }

        $out = & oci @Command 2>$err

        $stderr = ""

        if(Test-Path $err)
        {
            $stderr = Get-Content $err -Raw
            Remove-Item $err -Force
        }

        $stdout = ($out | Out-String).Trim()

        return @{
            ExitCode = $LASTEXITCODE
            StdOut   = $stdout
            StdErr   = $stderr
        }
    }

    while($true)
    {
        $LoopCount++
        Write-Host ""
        Write-Host "================================================================"
        Write-Host "## LOOP START"
        Write-Host ""
        Write-Host "[COUNT]: $LoopCount"
        Write-Host "[DATE] : $(Get-Date)"

        Write-Host ""
        Write-Host "### CREATE PLAN"
        Write-Host ""

        $plan = Invoke-Oci -Command @(
            "resource-manager"
            "job"
            "create-plan-job"
            "--stack-id"
            $StackId
            "--wait-for-state"
            "SUCCEEDED"
            "--wait-for-state"
            "FAILED"
            "--wait-for-state"
            "CANCELED"
            "--wait-interval-seconds"
            $WaitInterval
            "--max-wait-seconds"
            $MaxWait
        )

        if($plan.ExitCode -ne 0)
        {
            Write-Host ""
            Write-Host "#### PLAN CREATE ERROR"
            Write-Host $plan.StdErr

            Start-Sleep $RetrySeconds
            continue
        }

        try
        {
            $planJson = $plan.StdOut | ConvertFrom-Json
        }
        catch
        {
            Write-Host "#### Invalid PLAN JSON"
            Write-Host $plan.StdOut

            Start-Sleep $RetrySeconds
            continue
        }

        $PlanJobId = $planJson.data.id
        $PlanState = $planJson.data."lifecycle-state"

        Write-Host ""
        Write-Host "[PLAN JOB]: $PlanJobId"
        Write-Host "[STATE]   : $PlanState"

        if($PlanState -ne "SUCCEEDED")
        {
            Write-Host ""
            Write-Host "#### PLAN FAILED"

            Start-Sleep $RetrySeconds
            continue
        }

        Write-Host ""
        Write-Host "### CREATE APPLY"
        Write-Host ""

        $apply = Invoke-Oci -Command @(
            "resource-manager"
            "job"
            "create-apply-job"
            "--stack-id"
            $StackId
            "--execution-plan-strategy"
            "FROM_PLAN_JOB_ID"
            "--execution-plan-job-id"
            $PlanJobId
            "--wait-for-state"
            "SUCCEEDED"
            "--wait-for-state"
            "FAILED"
            "--wait-for-state"
            "CANCELED"
            "--wait-interval-seconds"
            $WaitInterval
            "--max-wait-seconds"
            $MaxWait
        )

        if($apply.ExitCode -ne 0)
        {
            Write-Host ""
            Write-Host "#### APPLY CREATE ERROR"
            Write-Host $apply.StdErr

            Start-Sleep $RetrySeconds
            continue
        }

        try
        {
            $applyJson = $apply.StdOut | ConvertFrom-Json
        }
        catch
        {
            Write-Host "#### Invalid APPLY JSON"
            Write-Host $apply.StdOut

            Start-Sleep $RetrySeconds
            continue
        }

        # Write-Host ($applyJson.data | ConvertTo-Json -Depth 100)
        # exit 0

        $ApplyState = $applyJson.data."lifecycle-state"

        Write-Host ""
        Write-Host "[APPLY STATE]: $ApplyState"

        if($ApplyState -eq "SUCCEEDED")
        {
            Write-Host ""
            Write-Host "#### STACK APPLY SUCCEEDED"
            exit 0
        }

        $FailureCode = $applyJson.data."failure-details".code
        $FailureMsg  = $applyJson.data."failure-details".message

        Write-Host ""
        Write-Host "#### APPLY FAILED"
        Write-Host "[CODE]   : $FailureCode"
        Write-Host "[MESSAGE]: $FailureMsg"
        Write-Host "Retry from PLAN..."

        Start-Sleep $RetrySeconds
    }
    ```

    직접 OCID 를 적어넣은 뒤에 전체 줄을 복사/붙여넣기하던지 또는 텍스트 파일로 적고나서 .ps1 파일로 확장자를 바꾸고 파워쉘 구동시키는 방법도 있습니다.

    혹시 windows 파워쉘이 아니라 리눅스 bash 쉘이라면 명령어는 다음과 같습니다.

    ```bash
    # 본인의 Stack OCID를 아래 따옴표 안에 입력하세요
    STACK_ID="ocid1.ormstack.oc1.ap-singapore-1.xxxxxxxxxxxxxx"

    while true; do
    echo "--- [$(date)] VM 생성 시도 시작 ---"
    
    # Apply 실행 후 상태가 완료될 때까지 대기
    JOB_STATUS=$(oci resource-manager job create --stack-id "$STACK_ID" --operation APPLY --wait-for-state SUCCEEDED --wait-for-state FAILED --query "data.\"lifecycle-state\"" --raw-output 2>/dev/null)
    
    if [ "$JOB_STATUS" = "SUCCEEDED" ]; then
        echo -e "\a" # 컴퓨터에서 '삑' 소리 알림 (지원하는 환경인 경우)
        echo "========================================="
        echo "🎉 축하합니다! VM 인스턴스 생성에 성공했습니다!"
        echo "========================================="
        break # 루프 종료
    else
        echo "--- 재고 부족(또는 에러)으로 실패했습니다. ---"
        echo "60초 후 다시 시도합니다..."
        sleep 60
    fi
    done
    ```

#### Error: 400 Parameter 'applyJobPlanResolution' is not valid.

400 에러는 스택에 정의된 인프라 계획을 적용할 때 안전장치(Resolution) 옵션이 빠져서 HTTP 400 (잘못된 요청) 에러를 뱉은 것입니다.

예전에는 스택(Stack)을 실행할 때 그냥 --operation APPLY (stack 실행옵션) 를 적용하면 됬지만 OCI 정책이 강화되었습니다. 이젠 APPLY 작업을 하려면, 사전에 짜놓은 실행 계획(Plan)을 어떻게 반영할 것인지(Resolution)에 대한 옵션을 무조건 명시해라"라며 필수 매개변수를 요구하고 있습니다.

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Developer Services` 
-> (Resource Manager 항목) `Stacks`
-> List scope 에서 compartment 를 선택할 수 있습니다.
-> 만든 Stack을 선택하면 나오는 Stacks details 에서 <kbd>Plan</kbd> 를 누르면 Plan 이 실행됩니다. 

```ps1
# 400 Error Code
$RawResult = oci resource-manager job create --stack-id $StackId --operation APPLY 2>$null

# Correct Code
$RawResult = oci resource-manager job create --stack-id $StackId --operation APPLY --apply-job-plan-resolution EXECUTE_PLAN 2>$null
```

이 에러를 해결하려면 oci resource-manager job create 명령을 내릴 때 --apply-job-plan-resolution 이라는 옵션을 뒤에 하나 덧붙여 주어야 합니다.

보통 자동 매크로에서는 이전에 빌드해 둔 가장 최근의 성공적인 계획을 기반으로 인스턴스를 올리도록 지정하는 EXECUTE_PLAN 값을 부여합니다.

#### Error: 429 Too many requests

```ps1
Stop-Process -Name "oci" -Force -ErrorAction SilentlyContinue
```

명령어로 터미널 종료 후에도 혹시모를 백그라운드 oci cli 작업을 강제종료시켜주시고 5분 뒤에 다시 실행해주세요.

### 2단계: OCI 클라우드 방화벽(Security List) 개방

-   공부할 개념: 네트워크 보안, 포트(Port), 인바운드 규칙(Ingress Rule).

-   할 일: 외부 사용자가 내 VM으로 들어올 수 있도록 통로를 열어줘야 합니다. OCI 콘솔의 가상 네트워크(VCN) 설정에서 80번 포트(HTTP 기본 포트)를 전체 개방(0.0.0.0/0)해 줍니다.

-   💡 많은 초보자가 VM 내부에 Nginx를 잘 켜두고도 이 클라우드 방화벽을 안 열어서 접속 실패를 겪습니다. 가장 중요한 단계입니다.

### 3단계: VM 내부 OS 방화벽 개방 및 Nginx 설치

-   공부할 개념: Linux 명령어, SSH 원격 접속, 패키지 관리자(apt 또는 dnf), Linux 자체 방화벽(iptables 또는 firewalld).

-   할 일: 
    -   내 컴퓨터에서 SSH를 통해 OCI VM으로 원격 접속합니다. (VS Code의 Remote-SSH 확장 기능을 쓰시면 편리합니다.)
    -   Linux 자체 방화벽에서도 80번 포트를 열어줍니다.
    -   nginx를 설치하고 실행합니다.

### 4단계: index.html 배치 및 외부 접속 테스트

-   공부할 개념: 웹 서버의 루트 디렉토리(Document Root), 웹 호스팅의 원리.

-   할 일: Nginx의 기본 경로(보통 /var/www/html 또는 /usr/share/nginx/html)에 질문자님의 index.html 파일을 덮어씌웁니다.

## 3. 웹 도메인 연결

&nbsp; 이 목표의 아키텍처 구조는 다음과 같이 변화할 예정입니다.

```txt
[사용자] ➔ [DNS (가비아, 후이즈, Cloudflare 등 도메인대행사)] ➔ [Compute VM (Nginx + SSL)] ➔ [OCI Object Storage (Public Bucket)] ➔ [index.html(Object)]
```

DNS (Domain Name System) 은 
비유: '전화번호부'

역할: 사람들이 기억하기 쉬운 '도메인 이름'을 컴퓨터가 이해하는 'IP 주소(예: 192.0.2.1)'로 연결(매핑)해 주는 시스템입니다.

주요 업무: * "이 도메인으로 들어오는 사람을 어디(어떤 서버)로 보내야 하지?"에 대한 정보를 가지고 있습니다.

웹사이트 접속, 이메일 전송 등을 위해 필수적인 네트워크 서비스입니다.

보통 도메인 판매 업체에서 무료 DNS 기능을 제공하기도 하고, 클라우드플레어(Cloudflare) 같은 전문 DNS 관리 서비스를 사용하기도 합니다.

## 프로젝트 살 붙이기

### 단계 1.5 (도메인 연결): "숫자 IP는 치기 귀찮네?" ➔ DuckDNS를 가져와서 VM IP 매핑하기

### 단계 2.0 (보안 적용): "주의 요함(HTTP) 경고창이 뜨네?" ➔ Certbot을 이용해 Nginx에 무료 SSL(HTTPS) 인증서 적용하기

### 단계 3.0 (아키텍처 고도화): "웹사이트에 이미지랑 동영상이 많아지니 서버 용량이 부족하고 느려지네? 서버 컴퓨터를 더 가볍게 유지하고 싶다." ➔ index.html과 정적 자원들을 Object Storage로 이사 보내고, VM은 백엔드 API 서버용으로만 쓰기

## OCI 시작하기

### 버킷 생성

### 웹 도메인 생성하기

#### 도메인 개념정리

&nbsp; 도메인은 인터넷 주소의 별명입니다. 현실에서도 건물 주소와 가게 간판의 이름이 각각 있듯이, 인터넷에서도 IP 주소와 그 주소에 거는 간판 이름을 붙여줍니다. 만약 가게를 가게 이름으로 안부르고 건물 주소로만 부른다면 가게가 건물을 다른 곳으로 이동하는 경우나 다른 건물에 2호점 확장이 일어날 때마다 이름을 바꿔야하나 고민해야 합니다. WWW 에서도 그런 이유로 도메인과 IP주소를 준비해야 본격적인 서비스가 가능합니다.

&nbsp; 인터넷의 IP 주소가 향하는 곳의 소유자는 명확합니다. 그 컴퓨터와 메모리의 주인입니다. 하지만 이를 인터넷에 연결하여 이곳으로 사람들을 오게하려면 이 주소 별명의 소유권이 나에게 있고 그 별명이 향하는 곳으로 가는 길이 신뢰할 수 있는 경로라는 것을 증명해야 합니다.

&nbsp; 현실의 부동산이나 등기소처럼 인터넷에도 여러 도메인의 권한을 소유하고 판매 관리하는 업체들이 있습니다. 대표적인 업체로는 가비아, 후이즈, 고대디(GoDaddy), 아이네임즈 등이 있습니다.

&nbsp; 도메인은 인증서를 발급받기 위해서도 필요합니다. 흔히 사용되는 무료 SSL 인증서 발급 기관인 'Let's Encrypt'는 도메인 이름이 있어야만 인증서를 발급해 줍니다.

#### 도메인 무료 생성

&nbsp; 직접 도메인 판매 및 등록 업체에서 유료 도메인(.com, .me, .net, .xyz 등)을 구매할 수도 있지만 여기선 완전 무료로 프로젝트를 올리는 것이 목표이므로 무료 다이내믹 DNS(DDNS) 서브도메인을 받아 사용하는 것이 가장 안전하고 확실한 방법입니다. DDNS 의 도메인은 브랜드신뢰성(Professionalism)이나, 메일서비스(Email Hosting), 와일드카드 서브도메인 보안인증서(SSL/TLS Wildcard), 서비스유연성(Portability), 검색엔진최적화(SEO) 에서 조금씩 손해를 보는 부분이 있으니 나중에는 도메인 구매를 고려해봐도 좋습니다.

&nbsp; 가장 신뢰도가 높고 오랜 기간 서비스 중인 DuckDNS 또는 No-IP 서비스를 이용해 `내이름.duckdns.org` 형태의 도메인을 무료로 확보할 수 있습니다. 여기서는 별도의 광고나 갱신 주기 제약이 적어 편리한 DuckDNS를 기준으로 설명합니다.

-   [DuckDNS](https://www.duckdns.org/) 공식 홈페이지에 접속하여 Google 이나 GitHub 계정으로 로그인합니다.
-   subdomains 입력창에 본인이 원하는 본인만의 도메인 이름(예시: `myfirststaticweb`)을 입력하고 <kbd>add domain</kbd>을 클릭합니다.
-   성공하면 `『본인이 정한 도메인 이름』.duckdns.org` 라는 무료 도메인이 생성됩니다.

### DNS 형성하기

#### DNS 개념정리

#### DNS 생성

OCI는 'OCI DNS Management'라는 강력한 서비스를 제공하며, 무료 티어(Always Free)에서도 일정 부분 사용할 수 있습니다. 하지만, 기업용 클라우드 환경에 맞춰져 있어 설정 인터페이스가 다소 복잡하고 전문적입니다. 설정 후 전파 속도나 변경사항 적용이 초보자에게는 다소 딱딱하게 느껴질 수 있습니다.

여기서는 Cloudflare 서비스의 무료 서비스를 이용하겠습니다.

### 가상 네트워크(VCN) 생성

### 가상 서버 컴퓨터(Virtual Machine, Compute Instance) 생성

&nbsp; VCN(외부 넷과 연결되는 도로망)가 생성되었다면 이제 이 네트워크에 VM(외부인이 접근할 수 있는 집)을 올려 외부와 소통하는 서버의 역할을 하게 만들 수 있습니다.

#### VM 개념정리

&nbsp; 개발자나 기업이 서비스를 구축할 때 VM은 가장 기본적이면서도 핵심적인 인프라(IaaS) 역할을 합니다.

&nbsp; OCI 서비스에선 이를 인스턴스(Compute Instance) 라는 이름으로 다룹니다. 인스턴스 VM은 24시간 켜져 있는 나만의 '리눅스/윈도우 가상 컴퓨터'이며, 여기에 웹 서버를 올리든 DB를 올리든 내 입맛대로 자유롭게 원격 제어하여 서비스를 배포할 수 있는 핵심 기지입니다.

&nbsp; 인스턴스를 넣어 VN 에 nginx 를 올리는 과정을 수행하면 됩니다. 유료계정일 경우 이 또한 OCI 측에서 API Gateway 라는 이름으로 자동처리 해주긴합니다. 둘 다 방법을 작성해두겠습니다.

-   ① 인스턴스(VM) 생성하기(무료)
-   ② API Gateway 연동 (유료 계정만 가능)

#### ① VM 생성하기

#### ② API Gateway 연동(유료)

&nbsp; "유료 계정"이라면 오라클의 API 로 오라클의 지원을 받아 자동화된 방법으로 서비스의 대문 게이트웨이를 만들 수 있습니다.

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 콘솔 메뉴 버튼을 눌러 네비게이션 메뉴를 열고
-> `Developer Services` 
-> (API Management 항목)`Gateways` 로 이동합니다.

Applied filters 옆에 Compartment 선택 창에서 <b>"Web-Resources"</b> 같이 현재 버킷이 있는 컴파트먼트를 선택합니다.

<kbd>Create gateway</kbd> 버튼을 누르고 값들을 입력합니다.

-   <u><b>Name :</b></u> 
    &nbsp; 예시로 `Web-Gateway` 라 하겠습니다.
    &nbsp; Gateway 의 이름입니다. 적절하게 이름 붙이면 됩니다.

-   <u><b>Compartment :</b></u> 
    &nbsp; 예시로는 `Web-Resources` 컴파트먼트를 고르겠습니다.
    &nbsp; Gateway 를 놓을 컴파트먼트를 지정합니다. 웹페이지 버킷이 위치하는 컴파트먼트와 맞춰줍시다.
-   Certificate
    &nbsp; 이 항목은 API Gateway를 구축할 때 '외부 사용자가 우리 서버에 접속할 때 사용할 인터넷 주소(도메인)와 HTTPS 보안 인증서(SSL/TLS)를 어떻게 처리할 것인가?' 를 결정하는 단계입니다.
    -   <u><b>Certificate compartment :</b></u>
        &nbsp; 기본값은 `Gateway 가 위치한 컴파트먼트(Web-Resources)` 입니다.
        
        &nbsp; Gateway 로 외부사용자가 접근가능한 컴파트먼트를 지정합니다.
    -   <u><b>Certificate :</b></u>
        &nbsp; 기본값은 `Default (*.oci.customer-oci.com)` 입니다.
        
        &nbsp; Gateway에  외부 사용자가 접속할 수 있는 인터넷 주소(호스트네임)를 지정합니다.
        
        &nbsp; 별도로 OCI의 현재 컴파트먼트의 인증서 관리 서비스(Certificates Service)에 등록해 둔 '커스텀 인증서'가 없다면 기본값(`Default (*.oci.customer-oci.com)`)만이 활성화됩니다. Default 옵션은 사용자가 직접 도메인 주소를 사거나 HTTPS 인증서를 발급받는 번거로운 과정 없이 OCI 측에서 빠르게 HTTPS 주소를 만들어줍니다.

        &nbsp; 기본값으로 자동 생성되는 주소는 `[랜덤문자열].apigateway.[리전이름].oci.customer-oci.com` 구조로 만들어집니다. 주소 뒤에 붙은 `*.oci.customer-oci.com` 대역은 오라클이 소유한 도메인이기 때문에, 오라클이 공식 기관으로부터 발급받은 와일드카드 인증서를 적용해 줍니다. 따라서 사용자가 별도 세팅을 하지 않아도 기본적으로 HTTPS 통신이 즉시 작동합니다. 만료 전에 오라클이 알아서 인증서를 갱신해 주기 때문에 관리할 필요도 없습니다.

-   <u><b>Network :</b></u> 
    &nbsp; `Public` 를 고릅니다.
    
    &nbsp; VCN 가상 네트워크 외부의 웹 사용자들의 응답을 받을 지 여부를 결정합니다. "Private" 선택 시 VCN 내부에서만 접근가능해집니다.

-   Choose a VCN and subnet
    -   <u><b>Virtual cloud network compartment :</b></u>
        &nbsp; 기본값은 `연결할 VCN이 위치한 컴파트먼트(Web-Resources)` 입니다.
        &nbsp; Gateway와 연결할 VCN이 위치한 컴파트먼트를 지정합니다.
    
    -   <u><b>Virtual cloud network :</b></u>
        &nbsp; 기본값은 `연결할 VCN(위의 단계에서 생성한 VCN)` 입니다.
        &nbsp; Gateway와 연결할 VCN를 지정합니다.
    
    -   <u><b>Subnet compartment :</b></u>
        &nbsp; 기본값은 `연결할 서브넷이 위치한 컴파트먼트(Web-Resources)` 입니다.
        &nbsp; Gateway와 연결할 서브넷이 위치한 컴파트먼트를 지정합니다.
    
    -   <u><b>Subnet :</b></u>
        &nbsp; 기본값은 `연결할 서브넷(위의 단계에서 생성한 VCN의 서브넷)` 입니다.
        &nbsp; Gateway와 연결할 서브넷을 지정합니다.

-   <u><b>Enable network security groups :</b></u> 
    &nbsp; 일단 기본값 그대로 `OFF` 로 둡니다.
    &nbsp; 이 옵션을 ON으로 켜면, 미리 만들어 둔 NSG(방화벽 규칙 그룹)를 이 게이트웨이에 맵핑할 수 있게 됩니다.

-   <u><b>Advanced options :</b></u>
    &nbsp; 일단 기본값 그대로 `OFF` 로 둡니다.
    &nbsp; Response Caching(응답 캐싱)은 인터넷 서핑을 할 때 브라우저가 이미지나 페이지를 캐싱해서 빠르게 띄워주는 것처럼, API Gateway 수준에서 이 작업을 대신 해주는 것입니다. 자주 요청되는 데이터를 API Gateway가 메모리에 임시로 기억(저장)해 두었다가, 똑같은 요청이 오면 백엔드 서버까지 가지 않고 그 자리에서 바로 답을 내어줍니다.
    &nbsp; 백엔드 서버와 DB의 부담이 급감하고, 응답속도가 빨라지고, 비용이 절감되지만 지금 신경 쓸 부분이 아닙니다.

-   <u><b>Certificate authority :</b></u>
    &nbsp; 일단 기본값 그대로 `No items to display` 로 둡니다.
    &nbsp; 이 기능은 중간자 공격을 방지하는 고급기능입니다. 위의 Certificate 항목이 일반 사용자가 이 Gateway에 접속할 때 사용자 브라우저에게 안전한 사이트임을 보여주는 HTTPS 보안 인증서였다면, Certificate authority 항목은 이 Gateway가 사용자의 요청을 받아서 내부 백엔드 서버로 넘겨줄 때 이 백엔드 서버가 우리 서버가 맞는지 확인하는 신원검증기준(CA 도장)입니다.
    &nbsp; 공격자들이 해킹을 시도했다면 Gateway 의 주소를 탈취하여 사용자에게 요청을 훔치고 이상한 응답을 보낼 수도 있습니다. 하지만 지금 단계에서 신경 쓸 부분이 아닙니다.
-   <u><b>Tags :</b></u>
    &nbsp; 관리하기 위한 태그를 붙일 수 있습니다. 지금 신경 쓸 부분이 아닙니다.

Create를 누르면 수 분 내에 Active 상태로 바뀝니다.

### 커스텀 도메인(SSL 인증서 포함)을 연결하는 작업이 필요합니다.

sdsd

## OCI 응용하기

OCI 를 이용하여 SNS 서비스 기틀을 개발할 수 있습니다.

개발 스택은 다음과 같이 정리될 것 입니다.

### 주소 설정

만약 웹페이지를 Object Storage 버킷으로만 운영하고 싶다면, 기본 주소는 `https://objectstorage.[리전].oraclecloud.com/...` 형태가 됩니다. 이 주소는 커스텀 도메인(`web.example.com`)을 바로 붙이기가 까다롭기 때문에, 보통 앞단에 Cloudflare 같은 무료 CDN을 붙여서 주소를 깔끔하게 매핑합니다.
