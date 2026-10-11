# Server(Web, Platform)：웹 및 플랫폼 서버

## 목차

-   [Server(Web, Platform)：웹 및 플랫폼 서버](#serverweb-platform웹-및-플랫폼-서버)
    -   [목차](#목차)
    -   [개요](#개요)
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
            -   [DB 서비스 예제 1 : 서비스 설계](#db-서비스-예제-1--서비스-설계)
            -   [DB 서비스 예제 1 : Express 코드 작성](#db-서비스-예제-1--express-코드-작성)
                -   [개념정리 : 파라미터화 쿼리(Parameterized Query)](#개념정리--파라미터화-쿼리parameterized-query)
            -   [DB 서비스 예제 1 : URL 요청 코드](#db-서비스-예제-1--url-요청-코드)
    -   [CORS](#cors)
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

이제 외부 javascript 코드는 `const pool = require('./db');` 같은 선언을 통해 db.js 모듈을 불러와서 사용할 수 있습니다. 예시와 같이 `pool` 이라 모듈이름을 선언하였다면, 매번 연결을 요청할 때마다 새로 작성할 필요 없이 `const result = await pool.query('SELECT NOW() AS server_time');` 비동기 요청으로 DB 연결을 시도할 수 있습니다.

#### Express 측 DB 연결 코드

&nbsp; NGINX 에서 `localhost:3000/api/test` 로 접근할 수 있던 API 테스트 코드를 이제 실제로 DB 연결이 정상적으로 이루어졌는지 확인하고 결과를 응답하는 코드로 수정하겠습니다.

&nbsp; API TEST 코드를 기반으로 javascript 의 비동기처리 방식인 `async () { await }` 를 사용하는 방법과 우리가 직접 만든 모듈 pool 을 어떤 식으로 사용하는 지 확인해보세요. 

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

#### DB 서비스 예제 1 : 서비스 설계

&nbsp; 구현할 API url 과 DB 작업은 다음과 같이 매핑됩니다.

-   <table>
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

#### DB 서비스 예제 1 : Express 코드 작성

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

#### DB 서비스 예제 1 : URL 요청 코드

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

-   urlReq.js 예시 (따라하지 마시오)

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

콘솔의 표준 입출력 I/O 인터페이스와 연결한 reader 객체를 생성하고, `async (input) => { await ...}` 콜백 함수 안에 종료용 (Y*/n) 확인 콜백 함수를 담은 inputNumer 재귀함수를 이용해서 구현한 방법입니다. 

다른 프로그래밍 언어가 익숙한 경우 매우 어색한 형태일 수 있습니다. Javascript 의 언어 지향점도 그렇고 Node.js 런타임 설계 또한 비동기 I/O 를 중심으로 설계되어 있습니다. 비절차적인 프로그램 개발시엔 막힘없이 코드가 실행되는 것이 좋지만, 지금처럼 순차적인 입출력을 구현할 때면 역으로 코드가 복잡해지는 단점이 있습니다.

사용자 입력을 더 받아야 할 때마다, `reader.question( ... , async (input) => { ... })` 콜백함수를 또 선언하여 `reader.question(  reader.question( ... ) )` 안으로 더 깊게 들어가야 하는 것은 끔찍합니다.

사용자 콘솔 입력을 순차적으로 받아야하는 상황에선 javascript 스럽지 않은 디자인으로 코드를 작성하는 것이 더 좋습니다.

여기선 async + await 과 try/catch 를 이용하여 main 이라는 함수로 전체를 동기화 제어 처리를 해버리는 것으로 개발자에게 익숙한 방식으로 코드를 작성하겠습니다.

-   urlReq.js

    ```js
    // # Node.js Fetch Request form
    // = ================================================================
    // * I/O Interface ==================================================

    const readline = require('node:readline/promises');

    const reader = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
    });

    // * GET | /api/test | PostgreSQL 연결 테스트 ========================

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

    // * GET | /api/leaderboard | 점수 상위 10명 조회 ====================

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

    // * POST | /api/users | 새로운 유저 추가 ============================

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

    // * PATCH | /api/users/:email/score | 특정 유저의 점수 설정 =========

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

    // * Main ===========================================================

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

    // * Run

    main();
    ```

## CORS

Express라면 cors 패키지로 간단히 해결됩니다.

```js
const cors = require('cors');
app.use(cors()); // 라우터 등록보다 먼저
```

## 검색 노출

## 구글 애드센스
