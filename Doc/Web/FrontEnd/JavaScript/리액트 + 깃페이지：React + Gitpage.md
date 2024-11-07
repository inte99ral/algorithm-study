# 리액트 + 깃페이지：React + Gitpage

## VS code Extension

- Auto Rename Tag
- ES7+ React/Redux/React-Native snippets
- ESLint
- Prettier
- vscode-styled-components
- TODO Highlight

<br />

## Convention

### Directory Structure

```text

```

## 기본 환경 조성

### npm (Node Package Manager) 환경 구현

```bash
npm install
```

### react & typescript

#### react & typescript > 설치

- 리액트 설치 명령 (타입스크립트 기반) 을 입력해주세요

  ```bash
  npx create-react-app <PROJECT_NAME> --template typescript
  ```

#### react & typescript > 환경설정

- tsconfig, compilerOptions 안에 baseUrl 을 src로 설정해주세요

  ```json
  "baseUrl": "src",
  ```

  - 베이스 주소가 src로 설정되었기 때문에 앞으로 import 할 때, 뒤에 /../../../ 없이 주소를 적을 경우 src 부터 시작합니다.

- $\color{#FF9922} \footnotesize \textnormal{package.json \space 확인 🚨}$

  - warning 이 뜨고 npm audit (npm 에서 코드 취약점을 파악하는 명령어) 를 쳤을 시에 nth-check 가 나온다면 걱정하지 말자.
  - 경고하자면 `npm audit fix --force` 로는 해결할 수 없다. 오히려 다른 패키지들이 깨질 수 있으니 주의
  - npm 으로 패키지를 다운로드 받고 있다면 원래 나와야 하는 게 맞다.
  - 문제의 원인은 package.json 안에 있는 `"react-scripts"` 이다.
  - npm은 해당 코드로 Node.js 앱을 돌릴 때 생기는 취약점을 경고한다.
    하지만 CRA(create-react-app)는 정적 빌드 툴이고, Node.js와 같은 방식으로 작동하지 않으며.
    npm audit은 CRA의 몇몇 부분을 취약점으로 오탐지한다.
  - 따라서 문제되는 의존성이 npm에 탐지되지 않게하기 위하여 다음의 방법을 사용한다.
  - package.json 안의 "dependencies" 안에 있는 "react-scripts" 을 "devDependencies" 로 이동시킨다.
  - 그 후, npm audit 대신 `npm audit --production` 을 사용하면된다.
  - npm이 node_modules 트리나 package-lock.json 의 수정시엔 의존성 라이브러리 버전을 상세하게 고정한 정보인 package-lock.json 이 자동생성되나 가끔 수정이 안될때가 있습니다. package-lock.json이 우선시 되므로 이 경우 package-lock.json을 삭제하거나 직접 수정해주세요

- $\color{#FF9922} \footnotesize \textnormal{node-sass \space 에러 \space 🚨}$

  - 개발을 하다보면 `node_modules\node-sass` 가 말썽을 일으킬 때가 있을 수 있다. <br/> 이는 sass 문법을 css 에 적용시켜주는 node-sass가 노드 버전에 의존적이어서 노드 버전이 바뀌면 오류를 일으키곤 한다. 버전에 맞춰서 package.json 를 수정해주던가 dart sass 를 사용하면된다.
  - 이 개발에선 dart sass 를 사용하겠다 node-sass 문항을 삭제하고 `"sass": "^1.32.12"` 로 대체한다.

### eslint & prettier

#### eslint & prettier > 패키지 설치

- 앞서서 eslint & prettier 란?

  - eslint 는 현재 개발자들에게 매우 인기있는 JavaScript linter이다, lint 란 소스 코드를 사전 검사하여 버그, 스타일 오류, 의심스러운 구조체들을 파악하여 로직 에러를 사전에 막아주는 도구이다.
  - prettier는 대다수가 쓰는 code formatter로 띄어쓰기, 개행 줄, 따옴표 등의 코드 생김새를 체크하고 강제로 지키도록 만들어 팀 간에 약속한 코드 컨벤션을 유지시켜준다 . eslint 의 스타일 체크보다 훨씬 기능이 다양하며, 자동으로 code format 를 맞춰 변화시켜주기 때문에 매우 편리하다. 한 명이 개발한 것 처럼 이쁜 코드를 만들어주는 도구이다.

- 빌드 시가 아니라 IDE 에서 개발 시 실시간 체크하기 위해서 vscode 의 extension `eslint` 와 `prettier` 를 설치해야 합니다.
- 프로젝트에 필요한 패키지들을 내려받는다. 필요한 것은 다음과 같다.

  - eslint
  - prettier
  - eslint-config-prettier
    - eslint에서 prettier와 충돌할 수 있는 rule을 꺼버린다.
    - 코드 오류만로 eslint, 코드 포맷팅만 prettier로 잡을 수 있다.
  - eslint-plugin-prettier
    - prettier를 eslint의 rules로써 동작하게 한다.
    - 코드 포맷팅 문제가 사전에 오류 메세지로 출력되서 파악하기 쉬워진다.
    - 단, 오류 메시지가 지나치게 많아져서 느려진다.

- 위에서 언급한 패키지들을 내려 받는 명령어

  ```bash
  npm install eslint prettier eslint-config-prettier eslint-plugin-prettier --save-dev
  ```

#### eslint & prettier > 환경 설정

- prettier 세팅

  - vscode 설정에서 default editor 를 prettier 로 바꿔줄 것
  - 편하게 쓰기 위해서 editor: format on save 를 true 값으로 해주면 저장 시에 자동으로 코드를 알맞게 바꿔준다.
  - 특수 법칙을 적용할 디렉토리에 `.prettierrc.json` 파일을 생성하고 내부에 법칙을 작성한다.

    ```json
    {
      "singleQuote": true,
      "semi": true,
      "useTabs": false,
      "tabWidth": 2,
      "trailingComma": "all",
      "printWidth": 100,
      "arrowParens": "always",
      "endOfLine": "auto"
    }
    ```

  <br />

- eslint 세팅

  - npx eslint --init 명령어를 통해 빠른 초기 설정이 가능하다.
  - 예시 프로젝트에서는 react 와 typescript 를 사용한다.
  - javascript module 과 commonjs 중 무엇을 쓰는 지 질문하는데 module 이 더 최신 방식이다. 뭐가 뭔지 모르겠다면 본인이 타 파일의 코드를 불러오는 방법을 보면 안다.

    - commonjs : 가져올 때는 `require` 로, 내보낼때는 `module.exports` 를 쓰는 구 방법

    - javascript module : `import` 와 `export` 을 사용하여 EMCA Script modules(또는 ES modules)를 가져오고 내보내는 방법. JS 코드 패키징의 공식 표준 형식이며 대부분의 최신 웹 브라우저는 기본적으로 모듈을 지원한다.

  - 설정하고 나면, 추가적으로 내려받아야할 설정들까지 자동으로 받아준다. 그 후, .eslintrc 파일이 생성되었을 것이다. 참고로 이 설정파일의 형식을 먼저 묻는데 js 로 선택할 경우, 최상위 디렉토리가 아니면 인식이 안될 수 있다. json 이 무난하다.

  - .eslintrc.json 에 프리티어 설정을 적용한다.

    ```json
    {
      // 상위 폴더에 적용 유뮤.
      "root": false,

      // env 환경변수 적용
      "env": {
        "browser": true,
        "es2021": true
      },

      // 추가한 plugin에서 사용할 규칙을 설정.
      "extends": [
        "eslint:recommended",
        "plugin:react/recommended",
        "plugin:@typescript-eslint/recommended",
        "plugin:prettier/recommended"
      ],

      "overrides": [],

      // 구문 분석을 위해 사용하는 parser 설정
      "parser": "@typescript-eslint/parser",

      // 구문 분석할 언어 옵션 설정
      "parserOptions": {
        // 프로젝트 tsconfig 주소를 못잡을때 명시
        "project": ["front-end/tsconfig.json"],
        "ecmaVersion": "latest",
        "sourceType": "module"
      },

      "plugins": ["react"],

      // 프로젝트에 사용할 규칙을 설정.
      // 규칙에 추가 옵션이 있는 경우 배열로 설정 가능.
      // 참고 : https://eslint.org/docs/latest/rules/
      // off 또는 0 사용시 규칙을 사용하지 않음.
      // warn 또는 1 사용시 규칙을 경고로 사용.
      // error 또는 2 사용시 규칙을 오류로 사용.
      "rules": {},

      // .로 시작하는 설정파일이나 node_modules, 외의 무시할 파일 영역
      "ignorePatterns": ["build", "dist", "public"],

      // 리액트 버전 자동탐지
      "settings": {
        "react": {
          "version": "detect"
        }
      }
    }
    ```

### env 환경 변수 설정

- typescript 에서 환경변수의 타입을 미리 명시하여 귀찮은 타입 처리를 피할 수 있다

  - 프로젝트 최상단에 `.env` 생성 후, 환경변수 등록합니다. <br />
    변수 이름이 `REACT_APP_` 으로 시작해야 인식되는 것을 주의하세요. <br />

  - 현 개발 빌드의 버젼을 string 타입 환경변수로 등록하여 사용하는 예시는 다음과 같습니다.

    - `.env` 파일에 환경변수 값 기입

      ```txt
      REACT_APP_VERSION = 0.003v
      ```

    <br />

    - `react-app-env.d.ts` 에 환경변수의 타입 명시

      ```typescript
      /// <reference types="react-scripts" />

      declare namespace NodeJS {
        interface ProcessEnv {
          NODE_ENV: 'development' | 'production';
          REACT_APP_VERSION: string;
        }
      }
      ```

    <br />

    - process.env.REACT_APP_VERSION 라는 이름으로 환경변수 사용이 가능합니다.

      ```typescript
      // front-end/src/api/webVitals/index.ts

      import { ReportHandler } from 'web-vitals';
      import { server } from 'api/rest';

      export const reportWebVitals = (onPerfEntry?: ReportHandler) => {
        // IIFF 로 감싸서 process.env.REACT_APP_VERSION 값과 서버의 version 값을 가져옴
        (async () =>
          console.log(
            `front-end ${
              process.env.REACT_APP_VERSION
            }v \n back-end ${await server.getServerVersion()}v`,
          ))();
        if (onPerfEntry && onPerfEntry instanceof Function) {
          import('web-vitals').then(({ getCLS, getFID, getFCP, getLCP, getTTFB }) => {
            getCLS(onPerfEntry);
            getFID(onPerfEntry);
            getFCP(onPerfEntry);
            getLCP(onPerfEntry);
            getTTFB(onPerfEntry);
          });
        }
      };
      ```

  <br />

### React.StrictMode 확인

- React StrictMode 는 리액트에서 제공하는 검사도구입니다. <br/>
  개발모드 시 디버그를 시행하면서 이상한 생명주기를 가진 컴포넌트나 권장하지 않는 부분을 점검해줍니다.

- `index.tsx` 파일 최상단 인덱스 파일은 다음과 같이 `<React.StrictMode>` 태그로 감싸져있습니다.

  ```typescript
  // -- API & Library
  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import { BrowserRouter } from 'react-router-dom';
  import { RecoilRoot } from 'recoil';
  import { reportWebVitals } from 'api/webVitals';

  // -- Components
  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);

  root.render(
    <React.StrictMode>
      <BrowserRouter>
        <RecoilRoot>
          <App />
        </RecoilRoot>
      </BrowserRouter>
    </React.StrictMode>,
  );

  reportWebVitals(console.log);
  ```

  이런 구조에서 리액트의 검사도구가 `<App/>` 내의 컴포넌트들을 검사할 수 있습니다.

- $\color{#FF9922} \footnotesize \textnormal{Double Invoke! useEffect 함수가 두 번 실행됩니다 🚨}$
  - React StrictMode 검사도구가 전체 점검을 하면서 invoke 된 함수가 실행됩니다. <br />
    따라서 useEffect 함수가 두 번 실행되며 로그도 두 번 씩 뜹니다. <br />
    불필요하다 생각되거나 double invoke 상황을 피하고 싶다면 `<React.StrictMode>` 태그를 제거해도 됩니다.

<br />

### react router

#### react router > 설치

- 패키지 설치 명령어

  ```bash
  npm install react-router-dom @types/react-router-dom
  ```

#### react router > 환경설정

- 테스트용 페이지 파일들을 생성

  1. 홈페이지 HomePage.tsx

     ```typescript
     // src/components/HomePage/index.tsx
     // API & Library
     import React from 'react';

     export const HomePage = () => {
       // Return
       return (
         <>
           <div>홈페이지</div>
         </>
       );
     };
     ```

  <br />

  2. 블로그 페이지 BlogPage.tsx

     ```typescript
     // src/components/BlogPage/index.tsx
     // API & Library
     import React from 'react';

     export const BlogPage = () => {
       // Return
       return (
         <>
           <div>블로그 페이지</div>
         </>
       );
     };
     ```

  <br />

  3. 에러 핸들링 페이지 ErrorPage.tsx

     ```typescript
     // src/components/ErrorPage/index.tsx
     // API & Library
     import React from 'react';

     export const ErrorPage = () => {
       // Return
       return (
         <>
           <div>에러 페이지</div>
         </>
       );
     };
     ```

  <br />

- react의 최상단 index.tsx 에 Router가 감지할 수 있도록<br />
  react-router-dom 에서 BrowserRouter 를 임포트하고 `<BrowserRouter>` 태그를 넣어줍니다.

  ```typescript
  // -- API & Library
  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import { BrowserRouter } from 'react-router-dom';
  import { RecoilRoot } from 'recoil';
  import { reportWebVitals } from 'api/webVitals';

  // -- Components
  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);

  root.render(
    <BrowserRouter>
      <RecoilRoot>
        <App />
      </RecoilRoot>
    </BrowserRouter>,
  );

  reportWebVitals(console.log);
  ```

- App.tsx 에 페이지들을 각 주소에 맞게 연결해줍시다.

  ```typescript
  // src/App.tsx
  // API & Library
  import React, { useEffect } from 'react';
  import { Route, Routes, Navigate } from 'react-router-dom';

  // Components
  import { HomePage } from 'components/HomePage';
  import { BlogPage } from 'components/BlogPage';
  import { ErrorPage } from 'components/pages/ErrorPage';

  const App = () => {
    // LifeCycle
    useEffect(() => {
      console.log('[VERSION]: ', process.env.REACT_APP_VERSION);
    }, []);

    // Return
    return (
      <div className={`App`}>
        <Routes>
          <Route path="/" element={<Navigate replace to="/home" />} /> // 처음 도착하게 될 주소
          <Route path="/home/*" element={<HomePage />} />
          <Route path="/blog/*" element={<BlogPage />} />
          <Route path="/error/*" element={<ErrorPage />} />
          <Route path="/*" element={<Navigate replace to="/error" />} /> // 이상한 값이면 이 곳으로
        </Routes>
      </div>
    );
  };

  export default App;
  ```

- 사이트를 로컬 주소에 올려 테스트하는 `npm start` 명령어를 통해서 작동을 확인해봅시다.

  ```bash
  npm start
  ```

### Gitpage.io 에 올리기
