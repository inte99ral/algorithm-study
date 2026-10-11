# 1

## 2

### Express → PostgreSQL DB 서비스 예제 2

### DB 서비스 예제 2 (사진첩)

&nbsp; 이번 예제에서는 이미지 파일을 저장하고 꺼내는 서비스를 만들어보도록 하겠습니다. 

&nbsp; 이번 예제에서는 URL 이 형식을 유지하고 Method 만 변합니다. URL 로 파라미터를 넘기고 Method 로 동작을 지시하는 RESTful 한 API 방식이 어떤 것인지 감을 잡는데에 도움이 될 것 입니다.

#### DB 서비스 예제 2-1 : 서비스 설계

-   DB 개발 명세서

    TABLE 명: <b>images</b>
    
    <table>
    <tr>
        <th>image_id</th>
        <th>image_file</th>
        <th>views</th>
    </tr>
    <tr>
        <td>INTEGER <kbd>PK</kbd></td>
        <td>BYTEA</td>
        <td>INTEGER <kbd>DEFAULT 0</kbd></td>
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

&nbsp; DB 기동과 계정 설정 등에 대한 내용은 상단의 <kbd>DB 와 연결</kbd> > <kbd>PostgreSQL</kbd> > <kbd>API 에 사용할 Table 만들기</kbd> 를 참고하세요.

&nbsp; `myapp/myapp_user@PostgreSQL 18 - myapp_user` ( <u><b>Servers</b></u> > <u><b>PostgreSQL 18 - myapp_user</b></u> 연결에서 <u><b>Databases</b></u> > <u><b>myapp</b></u> 에 우클릭으로 열은 Query Tool ) 에서 다음의 쿼리 명령어를 입력하고 실행해주세요.

-   myapp/myapp_user@PostgreSQL 18 - myapp_user

    ```sql
    CREATE TABLE public.images (
        image_id   INTEGER PRIMARY KEY,
        image_file BYTEA   NOT NULL,
        views      INTEGER NOT NULL DEFAULT 0 CHECK (views >= 0)
    );

    -- 또는 BIGINT 는 long long 자료형과 같은 8바이트 정수형 사용

    CREATE TABLE images (
        image_id   TEXT   PRIMARY KEY CHECK (char_length(image_id) BETWEEN 1 AND 100),
        image_file BYTEA  NOT NULL,
        views      BIGINT NOT NULL DEFAULT 0 CHECK (views >= 0)
    );
    ```

&nbsp; 생성한 테이블의 확인은 <kbd>DB 와 연결</kbd> > <kbd>PostgreSQL</kbd> > <kbd>API 에 사용할 Table 만들기</kbd> > <kbd>관리자 & 테이블 관련 쿼리 명령어 모음</kbd> 를 참고하세요.

#### 개념 정리 : Express 와 미들웨어 중간처리

Express.js 개발진은 프레임워크를 가볍고 유연하게 유지하기 위해 파일 업로드 처리 알고리즘을 Express 내부에 포함하지 않았습니다. 요청과 응답을 제어하는 틀만 제공하고 이 사이 중간처리 작업은 개발자들이 미들웨어(Middleware) 를 삽입하여야 직접해야 합니다.

Express.js 의 get, post 등의 함수들은 인자 수의 제한이 없는 가변 인자(Variadic Arguments) 로 콜백 함수를 받습니다. 그리고나서 Express.js 프레임워크는 개발자에게 받은 콜백 함수들을 순서대로 호출하여 미들웨어 체인으로 연결하여 실행합니다.

예를 들어 `const mid1 = upload.single('file');`, `const mid2 = (req, res, next) => { console.log('REQUEST'); next(); };` 와 같이 코드를 만들었다고 합시다. 두 코드는 미들웨어 역할을 수행할 수 있도록, 파라미터로 요청(req) 를 받고 응답(res) 을 조작하고 이 응답을 다음 체인으로 넘겨주는(next) 형태의 함수로 제작되었습니다.

어? mid1 은 `(req, res, next) => {next();}` 미들웨어 동작을 수행하는 콜백함수 형태가 아니지 않느냐? 라는 궁금증이 생기실 수 있지만, upload.single('file') 은 밑에 설명할 multer 패키지의 미들웨어를 만들어내는 팩토리 패턴이라는 디자인 패턴을 가진 인스턴스입니다. upload.single('file') 이 return 하는 결과물이 `(req, res, next) => {next();}` 입니다.

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

#### 개념 정리 : 에러 핸들링

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

#### DB 서비스 예제 2-3 : Server Express 코드

이미지 파일을 DB 에 저장할 때는 BYTEA(Byte Array) 8비트 이진 데이터(Binary Data) 형식으로 저장하고 있습니다.

이 형식에 맞춰 Express가 제공한 req 스트림을 읽어서 파일 조각을 분석하고, 메타데이터와 버퍼를 req.file이라는 속성에 새로 할당(req.file = ...)한 후 next()를 불러 넘겨주는 역할로 중간작업처리를 담당할 미들웨어(Middleware) 가 필요합니다.

이 Express 형식에 맞는 파일 제어 코드 패키지 multer 가 필요합니다.

이 형식에 맞춰 이미지 파일의 형식을 조작하려면 Express에서는 multer 패키지를 이용해야 합니다. 

multer 패키지를 이용하여 memoryStorage() 함수로 업로드된 요청파일을 Buffer 형태로 다루고, Buffer 형태로 변환한 값을 BYTEA 값으로 PostgreSQL에 넣을 수 있습니다.

프로젝트 루트 폴더 `$PROJECT_ROOT` 에서 터미널을 열고 다음의 명령어로 node 패키지를 설치해주세요. 

-   terminal shell

    ```bash
    npm install multer
    ```

이제 다음과 같은 형식으로 multer 라이브러리 코드를 호출할 수 있습니다.

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
... upload.single('image') ...
```

/api/leaderboard 를 먼저 정의하여 우선적으로 처리하도록 해야합니다.

이 라우트를 /api/:imageId 보다 먼저 정의해야 요청이 가로채지지 않습니다.

#### DB 서비스 예제 2-4 : URL Request 코드

```bash
curl -X POST \
  -F "image=@test.png" \
  http://localhost:3000/api/100
```

-   urlReq.js

```js

```

### DB 서비스 예제 3 (파일 클라우드)

이미지를 넘어서 데이터를 저장해보겠습니다.

#### 개념 정리 : JWT(JSON Web Token)의 서명(Signature)
