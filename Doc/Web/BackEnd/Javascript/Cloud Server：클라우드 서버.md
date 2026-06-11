# Cloud Server：클라우드 서버

## 목차

-   [Cloud Server：클라우드 서버](#cloud-server클라우드-서버)
    -   [목차](#목차)
    -   [개요](#개요)
    -   [OCI 시작하기](#oci-시작하기)
        -   [계정(도메인) 생성](#계정도메인-생성)
            -   [계정 만들기](#계정-만들기)
            -   [로그인 확인](#로그인-확인)
            -   [도메인 정책 확인](#도메인-정책-확인)
        -   [컴파트먼트 생성하기](#컴파트먼트-생성하기)
            -   [컴파트먼트란?](#컴파트먼트란)
            -   [하위 컴파트먼트 생성하기](#하위-컴파트먼트-생성하기)
        -   [버킷 생성](#버킷-생성)
            -   [블록 \& 버킷 개념정리](#블록--버킷-개념정리)
            -   [버킷에 넣을 파일 만들기](#버킷에-넣을-파일-만들기)
            -   [버킷 생성하기](#버킷-생성하기)
            -   [index.html 오브젝트 업로드](#indexhtml-오브젝트-업로드)
            -   [오브젝트 URL 확인](#오브젝트-url-확인)
        -   [웹서비스 배포를 위한 가상 네트워크 생성](#웹서비스-배포를-위한-가상-네트워크-생성)
        -   [URL 정리 및 웹서버화](#url-정리-및-웹서버화)
            -   [②① OCI 무료 인스턴스(VM) 빌드](#-oci-무료-인스턴스vm-빌드)
            -   [① API Gateway 연동(유료)](#-api-gateway-연동유료)
            -   [② OCI 무료 인스턴스(VM) 빌드](#-oci-무료-인스턴스vm-빌드-1)
    -   [OCI 응용하기](#oci-응용하기)
        -   [주소 설정](#주소-설정)

## 개요

&nbsp; 클라우드로 서버 컴퓨터 환경을 제공하는 서비스들이 존재합니다. 설명 예시로 OCI(Oracle Cloud Infrastructure) 를 사용하겠습니다.

&nbsp; OCI은 다른 클라우드에 비해 **넉넉한 사양의 VM**을 영구 무료로 제공합니다. 게임 서버를 호스팅하기에 충분할 수 있습니다.

&nbsp; 또한, 무료계정 정책이 사용자 친화적이므로 AWS 에선 무료 계정임에도 특정 한도를 초과하면 자동으로 유료 서비스로 전환되어 요금이 부과되는 것과는 다르게 OCI 의 Always Free 리소스는 Always Free 아웃바운드 데이터 전송량을 초과하면 해당 리소스에 대한 추가 전송이 차단됩니다.

## OCI 시작하기

### 계정(도메인) 생성

#### 계정 만들기

&nbsp; [oracle cloud 홈페이지](https://www.oracle.com/kr/cloud/)

&nbsp; OCI 서비스에 계정을 생성해야합니다.

&nbsp; 로그인 시 `클라우드 계정 이름`, `사용자 이름 또는 전자메일`, `비밀번호`를 요구하므로 잊으시면 안됩니다.

&nbsp; 계정 생성시에, 홈지역은 본인 국가나 그 주변 국가를 선택해야 최저 지연 시간을 보장하므로 유리하며, 아시아권에선 항상 무난한 곳이 싱가포르입니다.

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

#### 도메인 정책 확인

&nbsp; OCI 는 보안을 위하여 계정 도메인의 비밀번호에 유효기간을 두어 일정 주기로 바꾸는 것을 요구합니다. 이를 따르는 것이 좋으나 너무 귀찮다면 다음의 방법으로 계정 도메인의 보안 정책을 조정할 수 있습니다.

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

### 컴파트먼트 생성하기

&nbsp; 정적 웹사이트 호스팅(Static Website Hosting)을 위해선 버킷을 만들기 전에 먼저 최상위(Root)의 하위 컴파트먼트(Compartment)를 새로 만들어야합니다. 

#### 컴파트먼트란?

&nbsp; 컴파트먼트는 클라우드 리소스를 논리적으로 격리하는 계층형 디렉터리(폴더) 개념입니다. 프로젝트별, 부서별, 또는 개발/스테이징/운영 환경별로 리소스(인스턴스, 네트워크, 스토리지 등)를 묶어서 관리하고 권한을 제어(IAM)하기 위해 사용합니다.

&nbsp; OCI 보안정책상, 최상위(Root) 컴파트먼트에선 static 한 html 파일을 서비스하는 정적 웹 호스팅(Static Website Hosting) 기능을 활성화 할 수 없습니다. 이는 최상위 컴파트먼트가 해당 테넌시(계정)의 모든 리소스와 마스터 권한, 결제정보가 모이는 민감한 영역이므로, 이 컴파트먼트를 호스팅해버린다면 해당 컴파트먼트의 모든 자원에 전세계 사람에 접근하도록 Public 으로 접근권한을 허용하는 행위가 되기 때문입니다. 공격자의 공격으로부터 중요 데이터의 격리가 불가능한 이런 형태를 OCI 는 원천적으로 제공하지 않으려고 합니다.

&nbsp; 컴퓨터에 최상위 구조가 `C:\` 이듯 OCI 서비스에서 최상위 컴파트먼트는 본인의 테넌시(계정, Tenancy) 가 됩니다. 그 밑으로 최대 6단계 깊이 까지 하위 컴파트먼트를 생성할 수 있으며, 보통 프로젝트와 부서 틀에 따라 다음과 같이 구조를 설계합니다.

```txt
Root (내 계정 - 추가 생성 불가능)
 ├── Production (운영 환경 컴파트먼트)
 │    ├── Web-Resources (웹 서버용 버킷 등)
 │    └── DB-Resources
 └── Development (개발 환경 컴파트먼트)
      ├── Test-Servers
      └── Test-Storage
```

#### 하위 컴파트먼트 생성하기

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Identity & Security` 
-> (Indentity 항목) `Compartments` 
-> <kbd>Create compartment</kbd> 를 클릭합니다.

### 버킷 생성

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

#### 버킷에 넣을 파일 만들기

&nbsp; 대충 입력과 구동상태를 확인하기 위한 단순한 사이트 뭉치를 만들어줍니다.

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
        </head>
        <body id="body">
            <h1 id="btn">테스트</h1>
        </body>
    </html>
    ```

-   script.js

    ```js
    const objBtn = document.getElementById('btn');
    const objBody = document.getElementById('body');

    const eventBodyGreen = (e) => {
        objBody.style.backgroundColor = 'green';
    };
    const eventBodyRed = (e) => {
        objBody.style.backgroundColor = 'red';
    };

    objBtn.addEventListener('mousedown', eventBodyGreen);
    objBtn.addEventListener('mouseup', eventBodyRed);
    ```

-   style.css

    ```css
    body {
        width: 100vw;
        height: 100vh;

        display: flex;
        justify-content: center;
        align-items: center;

        color: white;
        background-color: #992244;
    }
    ```

#### 버킷 생성하기

&nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
-> `Storage` 
-> (Object Storage & Archive Storage 항목) `Buckets`
-> <kbd>Create bucket</kbd> 버튼을 클릭하여 만들 수 있습니다.

================================================================

_BOOKMARK

================================================================

-   우선 버튼 클릭 전에, Compartment 가 Root 가 아니라 하위에 만들어뒀던 Web-Resources 컴파트먼트인지 확인해주세요.

-   다음 값만 주의하고 나머진 기본설정을 따라 버킷 생성을 완료합니다.
    -   <u><b>Bucket name :</b></u>
        &nbsp; 일반적으로 버킷명은 <b>"프로젝트명-환경-용도-리전(선택)"</b> (예시: `firststaticweb-dev-web-singapore`)처럼 케밥케이스(kebab-case)로 작성합니다. 주소(URL)창이나 CLI에서 타이핑하기 가장 편한 것이 소문자와 하이픈(-) 조합이기 때문입니다.

        &nbsp; VCN의 이름입니다.
    
    -   <u><b>Bucket scope :</b></u>
        &nbsp; 기본 값은 (글로벌 범위) `Namespace` 입니다. 바꿀 필요 없습니다.
    -   <u><b>Default storage tier :</b></u>
        &nbsp; 기본 값은 `Standard` 입니다. 바꿀 필요 없습니다.

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
        -   파일을 추가합니다. 창을 열어서 선택하거나, 직접 드래그를 하여 복수개의 파일이나 폴더 전체를 넣을 수도 있습니다.

    -   **Optional response headers and metadata :**
        -   특수한 목적(웹 캐싱 제어, 강제 다운로드 설정 등)이 없다면 굳이 건드릴 필요 없이 비워두셔도 됩니다.
        -   Response Header 는 이 파일을 요청한 웹 브라우저에게 "이 파일은 이렇게 처리해줘!"라고 지시하는 규칙을 넣는 곳입니다.
            -   Content-Type: OCI가 파일 확장자(.html)를 보고 자동으로 text/html로 지정해 주므로 보통은 따로 안 건드려도 브라우저가 웹페이지로 잘 인식합니다.
            -   Cache-Control: "이 파일은 자주 바뀌니까 브라우저 너는 캐시(임시 저장)하지 말고 매번 새로 읽어와!" 같은 명령을 내릴 때 사용합니다.
        -   Metadata 는 웹 브라우저와는 상관없이, 클라우드 관리자인 나를 위한 '메모지'나 '태그' 입니다. 예를 들어 Type: User-defined, Name: project-name, Value: my-homepage 같은 식으로 적어두면, 나중에 클라우드에서 수많은 파일 중 특정 프로젝트의 파일만 검색하거나 분류할 때 유용합니다.

-   배포하려는 index.html 파일을 비롯한 웹사이트의 모든 정적 파일(CSS, JS, 이미지 등)을 업로드합니다.

#### 오브젝트 URL 확인

-   index.html 을 업로드한 Bucket 의 Objects 항목으로 가면 업로드 된 파일들을 볼 수 있습니다.
-   index.html 파일 옆의 <kbd>…</kbd> 버튼을 누르고, view object details 항목을 클릭하면 나오는 팝업에서 `URL path (URI)` 를 확인할 수 있습니다.

### 웹서비스 배포를 위한 가상 네트워크 생성

&nbsp; 이제 index.html 웹페이지 정보가 담긴 문서를 URL 로 접근할 수 있게 됬으니 웹서버화를 시켜 특정 주소로 해당 페이지를 제공하는 것이 다음의 목표 입니다.

URL 정리 및 웹서버화
가상 네트워크(Virtual Cloud Network, VCN)

### URL 정리 및 웹서버화

이제 index.html 웹페이지 정보가 담긴 문서를 URL 로 접근할 수 있게 됬으니 웹서버화를 시켜 특정 주소로 해당 페이지를 제공하는 방법을 보겠습니다. 크게 다음 두 방법으로 정리됩니다.

API Gateway 와 내가 직접 VN 에 nginx 를 올리는 것의 차이가 있습니다.

-   ① OCI 무료 인스턴스(VM)로 빌드
-   ② API Gateway 연동 (유료 계정만 가능)

#### ②① OCI 무료 인스턴스(VM) 빌드

================================================================

_BOOKMARK

================================================================

#### ① API Gateway 연동(유료)

&nbsp; "유료 계정"이라면 오라클의 API 로 오라클의 지원을 받아 자동화된 방법으로 게이트웨이를 만들 수 있습니다.

-   <u><b>1단계: API Gateway 생성을 위한 네트워크(VCN) 확인</b></u>

    &nbsp; API Gateway 를 만드려면 최소한의 가상 네트워크(Virtual Cloud Network, VCN)와 퍼블릭 서브넷이 필요합니다.

    VCN은 오라클 클라우드 내에 나만을 위해 생성되는 독립된 거대한 가상 데이터 센터입니다.

    &nbsp; OCI 메인 화면 좌측상단 <kbd>☰</kbd> 버튼을 눌러 네비게이션 메뉴를 열고
    -> `Networking` 
    -> `Virtual Cloud Networks` 화면으로 이동합니다.

    &nbsp; 직접 만들 수도 있지만 Start VCN Wizard 를 통해 VCN 생성에 도움을 받을 수 있습니다.

    &nbsp; <kbd>Actions</kbd> 버튼을 클릭하여 나오는 드롭다운 메뉴에서 <kbd>Start VCN Wizard</kbd> -> <kbd>VCN with Internet Connectivity</kbd> 를 선택하면 외부 통신이 가능한 Public Subnet이 자동으로 만들어집니다. 기본값들을 그대로 대입하면 됩니다. 각 값의 의미는 다음과 같습니다.

    -   Basic information

        -   <u><b>VCN name :</b></u> VCN의 이름입니다.

        -   <u><b>Compartment :</b></u> VCN을 위치시킬 컴파트먼트를 지정합니다.

    -   Configure VCN
        -   <u><b>VCN IPv4 CIDR block :</b></u>
            
            &nbsp; 기본값은 `10.0.0.0/16` 입니다.
            
            &nbsp; CIDR(Classless Inter-Domain Routing) 블록은 이 VCN 가상 데이터 센터 안에서 사용할 사설 IP 주소의 범위를 지정합니다.

            &nbsp; `10.0.0.0/16` 이라고 적힌 값은 `10.0. ...` 으로 시작하는 사설 IP 대역을 사용하겠으며, `/16` 은 서브넷 마스크를 의미하여 앞의 16비트(`10.0`)를 고정하고 나머지 공간을 IP로 쓰겠다는 계약입니다. 따라서 그 의미는 `10.0.0.0` 부터 `10.0.255.255` 까지 총 65,536개의 내부 IP 주소를 확보하겠다는 의미입니다. 이것이 사설 네트워크를 구축할 때 가장 흔하게 쓰이는 표준 크기 입니다. `10.0.x.x` 의 값은 네트워크 표준 규약(RFC 1918)에 의해 `127.0.0.1` 루프백 IP 와 비슷하게 사설 네트워크 내부 통신 IP 주소를 의미합니다.

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

-   <u><b>2단계: API Gateway 생성하기</b></u>

    &nbsp; 버킷 앞단에서 대문 역할을 해 줄 Gateway 장치를 만듭니다.
    
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
인터넷 서핑을 할 때 브라우저가 이미지나 페이지를 캐싱해서 빠르게 띄워주는 것처럼, API Gateway 수준에서 이 작업을 대신 해주는 것입니다.

Create를 누르면 수 분 내에 Active 상태로 바뀝니다.

#### ② OCI 무료 인스턴스(VM) 빌드

① OCI 무료 인스턴스(VM)로 제대로 빌드하기 (추천)
OCI의 강력한 장점인 "평생 무료 VM(Compute Instance)"을 하나 생성한 뒤, 거기에 Nginx나 Apache 같은 실제 웹서버 프로그램을 아주 가볍게 설치하고 파일을 올려 배포하는 방식입니다. 이것이 리눅스 환경에서 플랫폼 독립적으로 웹서비스를 테스트하기 가장 깔끔하고 정석적인 방법입니다.

## OCI 응용하기

OCI 를 이용하여 SNS 서비스 기틀을 개발할 수 있습니다.

개발 스택은 다음과 같이 정리될 것 입니다.

### 주소 설정

만약 웹페이지를 Object Storage 버킷으로만 운영하고 싶다면, 기본 주소는 `https://objectstorage.[리전].oraclecloud.com/`... 형태가 됩니다. 이 주소는 커스텀 도메인(`web.example.com`)을 바로 붙이기가 까다롭기 때문에, 보통 앞단에 Cloudflare 같은 무료 CDN을 붙여서 주소를 깔끔하게 매핑합니다.
