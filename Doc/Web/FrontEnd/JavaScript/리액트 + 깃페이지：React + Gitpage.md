# 리액트 + 깃페이지：React + Gitpage

## VS code Extension

- Auto Rename Tag
- ES7+ React/Redux/React-Native snippets
- ESLint
- Prettier
- vscode-styled-components
- TODO Highlight

<br />

## npm install

```bash
npm install
```

## react & typescript 세팅

- npx create-react-app `<PROJECT_NAME>` --template typescript

- tsconfig, compilerOptions 안에 baseUrl 설정

  ```json
  "baseUrl": "src",
  ```

  - 베이스 주소가 src로 설정되었기 때문에 앞으로 import 할 때, 뒤에 /../../../ 없이 주소를 적을 경우 src 부터 시작한다.

- <div style="color:orange">package.json 확인 🚨</div>

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

- <div style="color:orange">node-sass 에러 🚨</div>

  - 개발을 하다보면 `node_modules\node-sass` 가 말썽을 일으킬 때가 있을 수 있다. <br/> 이는 sass 문법을 css 에 적용시켜주는 node-sass가 노드 버전에 의존적이어서 노드 버전이 바뀌면 오류를 일으키곤 한다. 버전에 맞춰서 package.json 를 수정해주던가 dart sass 를 사용하면된다.
  - 이 개발에선 dart sass 를 사용하겠다 node-sass 문항을 삭제하고 `"sass": "^1.32.12"` 로 대체한다.

<br/>
