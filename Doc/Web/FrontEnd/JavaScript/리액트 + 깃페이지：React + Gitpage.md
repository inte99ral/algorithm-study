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

### Gitpage.io

#### Gitpage.io > 사전준비

- Github 에 계정이 있으셔야 합니다.
- 계정을 생성했거나 이미 계정이 있으시다면, 이제 여러분의 깃허브 계정명 `<GITHUB_ID>` 를 아셔야합니다.<br />
  프로필 화면에서 닉네임 밑에 씌여있으며, 프로필 페이지 주소를 봐도 https://github.com/`<GITHUB_ID>` 형식이므로 확인할 수 있습니다.

#### Gitpage.io > `<GITHUB_ID>`.github.io 배포용 프로젝트 생성

- 깃허브에 `<GITHUB_ID>`.github.io 라는 이름으로 프로젝트를 만듭니다.

  - 예를들어 `<GITHUB_ID>` 가 inte99ral 인 유저는 inte99ral.github.io 라는 이름의 프로젝트를 만들면됩니다. <b>(다른 이름이면 안됩니다!)</b>
  - 이 프로젝트에 올린 index.html 페이지가 그대로 여러분의 페이지가 됩니다.
  - 프로젝트 `<GITHUB_ID>`.github.io 에 index.html 파일을 생성한 뒤에 넣어봅시다.<br />
    Hello, world! 라는 글씨가 한가운데에 적혀있는 페이지 예시 입니다.

    ```html
    <!-- <GITHUB_ID>.github.io/index.html -->
    <!DOCTYPE html>
    <html>
      <head>
        <title>테스트용 HTML 페이지</title>
        <style>
          body {
            width: 100vw;
            height: 100vh;

            text-align: center;
            line-height: 100vh;
            overflow: hidden;
          }
        </style>
      </head>
      <body>
        <h1>Hello, World!</h1>
      </body>
    </html>
    ```

- 적용되기에 1~2 분의 정도 시간은 걸리지만 인터넷 브라우저를 키고 https://`<GITHUB_ID>`.github.io/ 라는 주소로 접속하시면 hello, world! 라는 문구가 띄어진 것을 볼 수 있습니다.

#### Gitpage.io > `<GITHUB_ID>`.github.io.dev 개발용 프로젝트 생성

- 깃허브에 `<GITHUB_ID>`.github.io.dev 라는 프로젝트를 만듭니다.
- 이 프로젝트는 개발용으로 쓰일 공간입니다.
- 여기서 개발을 한 뒤, 빌드한 완제품을 `<GITHUB_ID>`.github.io 배포용 프로젝트로 옮깁니다.
- 이렇게 분리를 하는 이유는 수많은 코드, 개발용 에셋들과 배포용 제품이 섞이지 않게 하기 위한 목적과 개발 진행 사항에 배포되어 있는 사이트가 영향을 받게하지 않기 위함입니다.

### npm (Node Package Manager) 환경 구현

#### npm 환경 구현 > node.js 설치

우선 JavaScript 생태계인 node.js 와 npm 이 설치되어 있어야 합니다.

- nvm(node version manager)을 [깃허브 링크](https://github.com/coreybutler/nvm-windows/) 에서 설치하여 node.js 설치 및 버전 관리를 하거나

  - `nvm list available` 명령어로 설치가능한 node.js 들을 볼 수 있습니다.

    ```bash
    nvm list available
    ```

  - `nvm install v<VERSION_NUMBER>` 명령어로 원하는 버전을 설치할 수 있습니다.

    ```bash
    # 예시용 옛날 버전
    nvm install v12.18.2

    # 가장 최신 LTS(장기간 관리 보장) 버전을 설치하기
    nvm install --lts
    ```

  - `nvm ls` 명령어로 설치되어있는 node.js 들을 볼 수 있습니다.

    ```bash
    nvm ls
    ```

  - `nvm use v<VERSION_NUMBER>` 명령어로 해당 버전을 쓸 수 있습니다.

    ```bash
    nvm use v12.18.2
    ```

- node.js 를 [공식 배포 사이트](https://nodejs.org/en) 에서 직접 원하는 버전을 설치하는 방법도 있습니다.

  - 설치 중에 "npm 설치" 체크박스를 꼭 확인해주세요.

- $\color{#FF9922} \footnotesize \textnormal{이 시스템에서 스크립트를 실행할 수 없으므로} \sim \textnormal{파일을 로드할 수 없습니다🚨}$

  - 윈도우즈 powershell 의 실행 정책 보안 때문에 발생한 것 입니다.
  - 파워쉘을 관리자 모드로 실행합니다. (작업표시줄 윈도우로고 우클릭 -> 터미널(관리자))
  - `Get-ExecutionPolicy` 명령어를 입력하여 현재 실행 정책을 확인합니다.
  - 출력값이 Restricted(파일 실행 금지) 이라면 RemoteSigned(인증기관 서명이 된 것 까지는 허용) 로 바꿔주셔야 합니다.
  - `Set-ExecutionPolicy <EXECUTION_POLICY>` 명령어로 바꿔줍시다.

    ```powershell
    Set-ExecutionPolicy RemoteSigned
    ```

### react & typescript

#### react & typescript > 설치

- `<GITHUB_ID>`.github.io.dev 개발용 프로젝트에서 react 를 설치할 것 입니다.
- 리액트 설치 명령 (타입스크립트 기반) 을 입력해주세요

  ```bash
  npx create-react-app <PROJECT_NAME> --template typescript
  ```

- 잘 설치가 되었는지 확인하기 위해서 `npm start` 명령어를 실행해봅시다.

  ```bash
  npm start
  ```

#### react & typescript > 구조정리

&nbsp; 개인적으로 선호하는 구조를 맞추기 위해서 구조를 변경합니다. atomic design 등 다른 구조를 쓰실 분들은 이 단락은 전부 무시하셔도 좋습니다.

&nbsp; 이 구조의 목표는 파일의 용량 효율을 포기하는 대신 정크 파일의 생성을 최소로 하는 것입니다.

##### 1단계. css 를 통합하지 않습니다.

&nbsp; 상위의 css style 양식을 받아오지 않습니다. 모든 컴포넌트 index.tsx 마다 본인 만의 style.tsx 를 가지고 있도록 구조를 유지합니다.

&nbsp; 이를 통해서 더미파일, 삭제되거나 변경된 컴포넌트의 style 정보가 남아있지 않도록 할 수 있습니다.

- src/component/ 빈 폴더를 생성합니다.
  - 앞으로 하위 컴포넌트를 만들 경우 이 곳에 정리합니다.
- theme.css 파일을 생성합니다.
- index.css 와 App.css 파일의 내용을 theme.css 에 복사합니다.

  ```css
  /* front-end\src\theme.scss */

  /* # index.css ================================================== */

  body {
    margin: 0;
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', 'Roboto', 'Oxygen', 'Ubuntu',
      'Cantarell', 'Fira Sans', 'Droid Sans', 'Helvetica Neue', sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }

  code {
    font-family: source-code-pro, Menlo, Monaco, Consolas, 'Courier New', monospace;
  }

  /* # App.css ==================================================== */

  .App {
    text-align: center;
  }

  .App-logo {
    height: 40vmin;
    pointer-events: none;
  }

  @media (prefers-reduced-motion: no-preference) {
    .App-logo {
      animation: App-logo-spin infinite 20s linear;
    }
  }

  .App-header {
    background-color: #282c34;
    min-height: 100vh;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    font-size: calc(10px + 2vmin);
    color: white;
  }

  .App-link {
    color: #61dafb;
  }

  @keyframes App-logo-spin {
    from {
      transform: rotate(0deg);
    }
    to {
      transform: rotate(360deg);
    }
  }
  ```

- index.css 파일에 theme.css 를 임포트합니다.

  ```typescript
  // # API & Library ==================================================
  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import reportWebVitals from './reportWebVitals';

  // # Style ==========================================================
  import './theme.css';

  // # Component ======================================================
  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
  root.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
  );

  reportWebVitals();
  ```

- index.css 와 App.css 파일을 삭제합니다.

##### 2단계. asset 를 따로 정리합니다.

&nbsp; 상위의 asset 을 가져오지 않습니다. 모든 컴포넌트에서 사용되는 에셋은 각각 자신 기준 옆에 있는 asset 폴더 내에서 가져옵니다.

&nbsp; 이를 통해서 더미파일, 삭제되거나 변경된 컴포넌트의 asset들이 남아있지 않도록 할 수 있습니다.

- asset 폴더를 생성합니다.
- logo.svg 를 asset 폴더로 옮겨줍니다.
- logo.svg 를 사용하고 있는 App.tsx 의 경로를 수정해줍시다.

  ```typescript
  // # API & Library ==================================================
  import React from 'react';

  // # Asset ==========================================================
  // import logo from "./logo.svg";
  import logo from './asset/logo.svg';

  function App() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <p>
            Edit <code>src/App.tsx</code> and save to reload.
          </p>
          <a
            className="App-link"
            href="https://reactjs.org"
            target="_blank"
            rel="noopener noreferrer"
          >
            Learn React
          </a>
        </header>
      </div>
    );
  }

  export default App;
  ```

##### 3단계. api 와 api 관련 함수는 폴더에 묶어서 정리합니다.

&nbsp; api 같이 외부 패키지 및 외부 함수를 참조하는 코드들은 최상단 src/api 폴더 내에서 관리하는 구조를 가능한 한 유지합니다.

&nbsp; 더 이상 사용되지 않는 외부 참조를 api 폴더에서만 제거하는 것으로 모든 영역에서 제거할 수 있습니다.

- src/api 폴더를 만들어주세요.
- 예시를 위하여 webVitals 진단기를 api 폴더 안에 정리하겠습니다.
- src/api/webVitals 폴더를 만들어주세요.
- src/api/webVitals 폴더 내부에 index.ts 를 생성합니다.

  ```typescript
  import { ReportHandler } from 'web-vitals';

  export const reportWebVitals = (onPerfEntry?: ReportHandler) => {
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

- src/index.tsx 의 경로를 수정해줍시다.

  ```typescript
  // # API & Library ==================================================

  import React from 'react';
  import ReactDOM from 'react-dom/client';
  // import reportWebVitals from "./reportWebVitals"; <--
  import { reportWebVitals } from './api/webVitals';

  // # Style ==========================================================

  import './theme.css';

  // # Component ======================================================

  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
  root.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
  );

  reportWebVitals();
  ```

- src/reportWebVitals.ts 파일을 삭제합니다.

##### 4단계. Jest와 Testing Library 는 사용빈도가 낮기에 제거합니다.

https://github.com/testing-library/jest-dom

&nbsp; 각 함수의 리턴값과 컴포넌트 렌더링을 시범용으로 구동해주는 패키지입니다. 다만, 사용자에 따라서 사용빈도가 극단적으로 적습니다. 저는 잘 안쓰기 때문에 제거하겠습니다.

- src/ 폴더 내에서 <b>setupTests.ts</b> 와 <b>App.test.tsx</b> 파일을 삭제합니다.
- npm search jest 명령어를 통해서 검색
- npm uninstall jest
- package.json 에서 ctrl + f 로 검색하여 jest 와 testing-library 를 제거합니다.
- package-lock.json 을 삭제하고 npm install 또는
- npm cache verify
  - 꼬인 부분을 체크 및 해결하는 명령어입니다. cache 폴더의 내용을 확인하고, 가비지 데이터들을 수집하여 삭제하고 무결성을 확인합니다.
- npm cache clean --force
  - npm의 cache를 모조리 삭제하는 명령어입니다.

##### 정리

위 단계를 거친 뒤엔 src 폴더의 구조가 다음과 같이 정리됩니다.

```txt
src/
├─ api/ (외부 라이브러리 및 외부 참조함수들)
├─ asset/ (이미지, 음악등 에셋들)
├─ component/ (하위 자식 컴포넌트들. 아직 설명안했습니다.)
├─ App.tsx (react SPA 구현의 최상단)
├─ index.tsx (react 컴포넌트 토대의 최상단)
├─ react-app-env.d.ts (환경변수 타입 파일. 아직 설명안했습니다.)
└─ theme.css (전체 테마로 적용되는 스타일)
```

#### react & typescript > 환경설정

- tsconfig.json의 compilerOptions 안에 baseUrl 을 src로 설정해주세요

  ```json
  // front-end\tsconfig.json
  {
    "compilerOptions": {
      "baseUrl": "src", // <-- 추가
      "target": "es5",
      "lib": ["dom", "dom.iterable", "esnext"],
      "allowJs": true,
      "skipLibCheck": true,
      "esModuleInterop": true,
      "allowSyntheticDefaultImports": true,
      "strict": true,
      "forceConsistentCasingInFileNames": true,
      "noFallthroughCasesInSwitch": true,
      "module": "esnext",
      "moduleResolution": "node",
      "resolveJsonModule": true,
      "isolatedModules": true,
      "noEmit": true,
      "jsx": "react-jsx"
    },
    "include": ["src"]
  }
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
        "project": ["tsconfig.json"],
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

  - 프로젝트 최상단(src 폴더 바로 외부)에 `.env` 생성 후, 환경변수를 등록합니다. <br />
    변수 이름이 `REACT_APP_` 으로 시작해야 인식되는 것을 주의하세요. <br />

  - 현 개발 빌드의 버젼을 string 타입 환경변수로 등록하여 사용하는 예시는 다음과 같습니다.

    - `.env` 파일에 환경변수 값 기입

      ```txt
      REACT_APP_VERSION = v0.0.1
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

      - npm start 또는 배포된 웹페이지에 접속하면 reportWebVitals 함수가 실행되면서 환경변수 .env 의 값 v0.0.1 를 콘솔창에 띄우도록 해봅시다.

        ```typescript
        // # front-end/src/api/webVitals/index.ts

        import { ReportHandler } from 'web-vitals';

        export const reportWebVitals = (onPerfEntry?: ReportHandler) => {
          (async () => console.log(`front-end ${process.env.REACT_APP_VERSION}`))(); // <-- 추가된 코드

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

      - F12 를 눌러 <b>콘솔</b> 창을 띄우시면 v0.0.1 버전이 출력되어 있을 것 입니다.

- $\color{#FF9922} \footnotesize \textnormal{주의사항 .env 의 값은 빌드 시점에 고정됩니다. 🚨}$

  - .env 환경변수 값은 npm start 이나 npm run build 를 한 시점에서 결정됩니다.
  - 이미 빌드를 한 이후에는 .env 값을 수정하고 새로고침을 하더라도 변하지 않습니다.
  - ctrl + c 로 테스트를 끄고 다시 키거나 새로 빌드해서 배포하기 전까지는 수정된 환경변수 값이 들어가지 못합니다.

<hr />

### React index.tsx 구조와 React.StrictMode 확인

- [공식문서](https://bit.ly/CRA-vitals)
- React StrictMode 는 리액트에서 제공하는 검사도구입니다. <br/>
  개발모드 시 디버그를 시행하면서 이상한 생명주기를 가진 컴포넌트나 권장하지 않는 부분을 점검해줍니다.

- `index.tsx` 파일 최상단 인덱스 파일은 다음과 같이 `<React.StrictMode>` 태그로 감싸져있습니다.

  ```typescript
  // # src/index.tsx

  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import { reportWebVitals } from './api/webVitals';

  import './theme.css';

  import App from './App';

  const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement);
  root.render(
    <React.StrictMode>
      <App />
    </React.StrictMode>,
  );

  reportWebVitals();
  ```

- react의 도구들은 구조상 도구가 감지할 <b>컴포넌트 영역</b>을 태그로 묶어주어야 합니다. 다음은 감시도구, 라우터, 리코일이라는 도구가 `<React.StrictMode>` `</BrowserRouter>` `<RecoilRoot>` 라는 태그를 통해 감지 영역을 지정해준 모습입니다.

  ```typescript
  // # src/index.tsx
  // ## API & Library
  import React from 'react';
  import ReactDOM from 'react-dom/client';
  import { BrowserRouter } from 'react-router-dom';
  import { RecoilRoot } from 'recoil';
  import { reportWebVitals } from 'api/webVitals';

  // ## Components
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

- $\color{#FF9922} \footnotesize \textnormal{Double Invoke! useEffect() 함수가 두 번 실행됩니다 🚨}$

  &nbsp; 아직 useEffect 함수 설명을 하진 않았지만 미리 짚고 가겠습니다.

  &nbsp; React StrictMode 검사도구가 전체 점검을 하면서 invoke 된 함수가 실행됩니다. 따라서 점검 때 한 번, 실행 시 한 번, 이렇게 useEffect 함수가 두 번 실행되며 로그도 두 번 씩 뜹니다.

  &nbsp; 불필요하다 생각되거나 double invoke 상황을 피하고 싶다면 `<React.StrictMode>` 태그를 제거해도 됩니다.

<hr />

### 백지화 및 홈페이지 디자인 시작

&nbsp; 지금까지는 react 가 제공하는 기본 페이지 디자인(파란색 리액트 로고가 가운데에 회전하는 페이지) 을 유지하면서 전체적인 구조를 조정하였습니다.

&nbsp; 이제 본격적인 응용과 실행예제를 위하여 필요없는 부분을 전부 삭제하고 빈 페이지로 만들겠습니다.

#### 1단계. App.tsx 정리

- 필요없는 로고와 내용물들은 삭제합니다.
- src/asset/logo.svg 삭제
- App.tsx 를 백지화 합니다. 이제 div 사이에 작성한 내용이 페이지가 됩니다. // 주석처리 된 부분은 코드가 길어졌을 때, 눈에 잘보이도록 정리하는 용도 입니다. 아무런 의미가 없습니다.

  ```typescript
  // # src/App.tsx
  // ## API & Library ==================================================

  import React from 'react';

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  const App = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return <div className="App"></div>;
  };

  export default App;
  ```

#### 2단계. theme.css 정리

- 모든 내용을 삭제합니다.
- 자주 쓰이는 설정을 추가해줍니다.

  ```css
  * {
    <!-- 포지션은 부모 상속을 원칙으로 합니다. -->
    position: relative;

    <!-- 테두리 선 두께가 객체 밖으로 나가지 않습니다. -->
    box-sizing: border-box;

    <!-- 객체 속에 여유 간격을 두지 마세요. ▣ -->
    padding: 0;

    <!-- 객체들 사이에 여유 간격을 두지 마세요. ■ ■ -->
    margin: 0;

    <!-- z축 기준값을 1000으로 하겠습니다. -->
    z-index: 1000;

    <!-- 글씨를 자동으로 꾸미지 말아주세요. -->
    text-decoration: none;
  }
  ```

#### 3단계. Hello, world!

- 여기까지 잘 따라오셨다면 처음에 HTML 로 만들었던 Hello, world! 를 다시 만들어봅시다.
- App.tsx 에 페이지를 작성합니다.

  ```typescript
  // # src/App.tsx
  // ## API & Library ==================================================

  import React from 'react';

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  const App = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <div className="app">
        <h1>Hello, world!</h1> // <--
        <h3>front-end : {process.env.REACT_APP_VERSION}</h3> // <--
      </div>
    );
  };

  export default App;
  ```

- theme.css 에서 글씨를 정가운데로 맞춰줍시다.

  ```css
  * {
    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
  }
  ```

- `npm start` 로 확인해보세요.

#### 4단계. Hello, world! + 자식 컴포넌트

- 자식 컴포넌트를 만들어서 react 구조에 익숙해져봅시다
- component/ 폴더 안에 HelloPage/ 폴더를 만듭니다.
- src/component/HelloPage/HelloPage.tsx
- HelloPage/ 폴더 내부에 index.tsx 파일을 만들고 다음과 같이 작성합니다.

  ```typescript
  // # src/component/HelloPage

  import React from 'react';

  export const HelloPage = () => {
    return (
      <center>
        <h1>Hello, world!</h1>
        <h3>front-end : {process.env.REACT_APP_VERSION}</h3>
      </center>
    );
  };
  ```

- App.tsx 를 다음과 같이 수정해주세요

  ```typescript
  // # src/App.tsx
  // ## API & Library ==================================================

  import React from 'react';

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  import { HelloPage } from 'component/HelloPage'; // <--

  const App = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <div className="app">
        <HelloPage></HelloPage> // <--

        // * <HelloPage /> 처럼 닫는 부분 없이 단일 태그로 써도 됩니다.
      </div>
    );
  };

  export default App;
  ```

- index 파일은 디폴트 값으로 취급됩니다. 덕분에 폴더 경로만 적어줘도 연결됩니다.
- 이제 페이지 전체에 해당하는 App.tsx 를 수정하지 않아도 작은 범위에서 내부의 자식 컴포넌트만 수정해주면 디자인과 글씨를 바꿀 수 있습니다.
- `<HelloPage></HelloPage>` 를 닫는 부분 없이 단일 태그로 `<HelloPage />` 처럼 쓸 수도 있습니다.
- `npm start` 를 통해서 결과물을 확인해보세요.

#### 5단계. Hello, world! + 테마와 폰트

- 페이지 전체에 사용될 글꼴이나 바탕색을 수정해봅시다.
- 예시용으로 저는 [윤디자인](https://www.yoondesign-m.com/719) 사이트에서 폰트 파일 `koverwatch.ttf` 을 다운로드 받겠습니다.
- src/asset/ 폴더 안에 font/ 폴더를 만든 뒤에 그 안에 폰트 파일을 넣어주세요.
- src/theme.css 파일에서 font 를 적용해주세요.

  ```css
  /* # src/theme.css */

  /* ## font */

  @font-face {
    font-family: Koverwatch; /* <-- */
    src: url(asset/font/koverwatch.ttf); /* <-- */
  }

  /* ## style */

  * {
    font-family: Koverwatch; /* <-- */
    font-size: 64px; /* <-- */

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
  }
  ```

- `npm start` 를 통해서 결과물을 확인해보세요.

<hr />

### SASS

&nbsp; sass 는 기존의 css 보다 향상된 스타일 문법 입니다.

&nbsp; 다음 두 명령어 중 하나를 골라 사용하시면 됩니다.

- node-sass 적용 `npm install node-sass` (비추천, 현재 지원 중단)
- dart sass 적용 `npm install sass`

#### SASS > $\color{#FF9922} \footnotesize \textbf{node-sass 에러 🚨}$

&nbsp; `node-sass` 는 더 이상 사용되지 않습니다. node 의 버전에 영향을 받기 때문에 개발을 하다보면 `node_modules\node-sass` 가 말썽을 일으킬 때가 있습니다.

&nbsp; 이는 sass 문법을 css 에 적용시켜주는 node-sass가 노드 버전에 의존적이어서 노드 버전이 바뀌면 오류를 일으키곤 합니다. 버전에 맞춰서 package.json 를 수정하는 방법도 있지만 dart sass 를 사용하는 쪽을 추천합니다.

#### SASS > 적용 예시

&nbsp; src/theme.css 파일의 확장자를 src/theme<b>.scss</b> 로 바꿔주세요

- 이제 SASS 문법으로 테마를 꾸밀 수 있습니다. // 주석처리 된 부분은 코드가 길어졌을 때, 눈에 잘보이도록 정리하는 용도 입니다. 아무런 의미가 없습니다.

  ```scss
  // # src/theme.scss
  // ## API & Library ==================================================
  // ## Asset ==========================================================
  // ### Font

  @font-face {
    font-family: Koverwatch;
    src: url(asset/font/koverwatch.ttf);
  }

  // ### Image

  // ## Default ========================================================
  // ### Variable
  // ### Animation

  // ## Styles =========================================================

  * {
    font-family: Koverwatch;
    font-size: 64px;

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;
  }

  .app {
    width: 100vw;
    height: 100vh;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
  }
  ```

- 가장 큰 차이 중 하나는 주석 처리가 // 로 편해졌다는 점 입니다.
- 또한 지금 당장은 큰 의미가 없지만 & 를 통해 자기 자신을 지정하여 캐스케이드하게 스타일 코드를 작성할 수 있습니다. 다음은 예시입니다.

  ```scss
  * {
    font-family: Koverwatch;
    font-size: 64px;

    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    z-index: 1000;
    text-decoration: none;

    // 나 (*) 바로 밑에 있는 .app 를 선택
    & > .app {
      background-color: red; // 확인용 빨간 배경

      width: 100vw;
      height: 100vh;
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
    }
  }
  ```

- `npm start` 를 통해서 결과물을 확인해보세요.
- 예시용이었으므로 `* { ... & > .app { ... }}` 구조는 원래 모습인 `* {...}` 과 `.app {...}` 으로 분리하여 원상복구 하셔도 됩니다.

<hr />

### react-icons

&nbsp; [react-icons 사이트](https://react-icons.github.io/react-icons/)

&nbsp; 페이지 디자인에는 여러 아이콘과 기호들이 사용됩니다.

&nbsp; 기호가 필요한 상황마다 쓸만한 아이콘을 찾고 또 페이지에 넣는 과정은 상당히 불편합니다. react-icons 은 자주 쓰이는 아이콘 디자인들을 전부 제공해줍니다.

#### react-icons > 설치

- `npm install react-icons` 명령어로 설치해주세요

  ```bash
  npm install react-icons
  ```

#### react-icons > 적용예시

- react-icons... 를 import 해준 이후면 태그로 사용할 수 있습니다.
- 사용 예시는 다음과 같습니다.

  ```javascript
  // # src/component/HelloPage/HelloPage.tsx
  // ## API & Library ==================================================

  import React from 'react';
  import { AiFillSetting } from 'react-icons/ai'; // <--

  // ## Asset ==========================================================
  // ## Style ==========================================================
  // ## Component ======================================================

  export const HelloPage = () => {
    // ## Hook ===========================================================
    // ## Method =========================================================
    // ## Return =========================================================

    return (
      <center>
        <AiFillSetting /> // <--
        <h1>Hello, world!</h1>
        <h3>front-end : {process.env.REACT_APP_VERSION}</h3>
      </center>
    );
  };
  ```

<hr />

### Styled Component

<hr />

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

- `npm run build` 명령어를 통해서 빌드한 후 /build 폴더 안의 내용물을 전부 배포용 프로젝트 `<GITHUB_ID>`.github.io에 올려준 뒤에 https://`<GITHUB_ID>`.github.io/ 에 접속해서 확인해봅시다.

  ```bash
  npm run build
  ```

#### react router > $\color{#FF9922} \footnotesize \textbf{404 에러 제어 🚨}$

&nbsp; 이번엔 잘 안될 것입니다. 404 에러 페이지가 뜹니다. 만약 잘 됬다면 주소창에 직접 https://`<GITHUB_ID>`.github.io<b>/blog</b> 를 입력해 보세요.

&nbsp; 404 에러가 뜨는 이유는 바로 웹 배포를 해주는 사실상의 백엔드 서버인 Gitpage.io 때문입니다. Gitpage.io 입장에서 보기엔 https://`<GITHUB_ID>`.github.io<b>/blog</b> 라는 주소는 없는 곳을 가리키는 이상한 주소입니다. React의 SPA 구조를 Gitpage.io 가 받아들이지 못해서 발생하는 문제입니다.

&nbsp; 다행히 편법을 사용하여 이 문제를 쉽게 해결할 수 있습니다. Gitpage.io는 이상한 주소로 인하여 404 에러를 응답할 때 <b>index.html</b> 옆에 <b>404.html</b> 파일이 존재한다면 그것을 대신 띄워줍니다. 이것을 응용하여 <b>404.html</b> 파일을 직접 생성해준 뒤, 입력받은 주소를 데이터로 바꾸어 https://`<GITHUB_ID>`.github.io<b>/ 기본주소로 넘겨주는 코드를 추가합니다. 또한 <b>index.html</b> 쪽에는 넘어온 주소 데이터가 있을 경우에 이를 해석해서 react router 에게 넘겨주는 코드를 추가합니다.

- 빌드된 front-end/build 폴더의 최상단 구조는 front-end/public 폴더에 들어있습니다.
- /public/404.html 파일 생성

  ```html
  <!-- front-end/public/404.html -->
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset="utf-8"
      <title>Integral Blog</title>
      <script type="text/javascript">
        window.location.replace(`/?url=${window.location.href}`);
      </script>
    </head>
    <body></body>
  </html>
  ```

- /public/index.html 파일 수정

  ```html
  <!-- front-end/public/index.html -->
  <!DOCTYPE html>
  <html lang="en">
    <head>
      <meta charset="utf-8" />
      <link rel="icon" href="%PUBLIC_URL%/favicon.ico" />
      <meta name="viewport" content="width=device-width, initial-scale=1" />
      <meta name="theme-color" content="#000000" />
      <meta name="description" content="Web site created using create-react-app" />
      <link rel="apple-touch-icon" href="%PUBLIC_URL%/logo192.png" />
      <link rel="manifest" href="%PUBLIC_URL%/manifest.json" />

      <title>Integral Blog</title>
    </head>
    <body style="margin: 0">
      <div id="root"></div>
      <script type="text/javascript">
        if (window.location.search.slice(1, 4) == 'url')
          window.history.replaceState(null, null, `${window.location.search.slice(5)}`);
      </script>
    </body>
  </html>
  ```

- Gitpage.io는 이상한 주소로 인하여 404 에러를 응답할 때 <b>index.html</b> 옆에 <b>404.html</b> 파일이 존재한다면 그것을 대신 띄워줍니다.
- <b>404.html</b> 파일을 직접 생성해준 뒤, 입력받은 주소를 데이터로 바꾸어 github.io/ 주소로 다시 넘겨주는 코드를 추가합니다. 데이터를 넘겨주는 방법은 여러 종류가 있지만 여기선 가장 쉽고 빠르게 전체주소를 쿼리스트링으로 넘겨주는 방법을 씁니다.

빌드 후, 깃 페이지 링크에서 잘 작동하는 지 확인해보자. 그 외에도 직접 분해해서 필요한 데이터만 가져오는 방법, localstorage 를 쓰는 방법 등 본인에게 적합한 방법을 사용하세요.
