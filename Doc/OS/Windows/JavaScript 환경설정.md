# JavaScript 환경설정：

## 2. 컴파일러：node.js

### 2 > 상세설명

V8 엔진은 자바스크립트를 실행 할 수 있는 엔진이며, 인터프리터 역할을 하는 이그니션과 컴 파일러 역할을 하는 터보팬을 사용해 컴파일합니다.

## 3. VScode 세팅

### 3 > tasks.json

#### 3 > tasks.json > 간단설명

```bash
node <FILE_NAME>.js
```

```json
// ...tasks.json 앞 부분...

// ### JavaScript：.js 파일 실행 ===================
{
  "label": "JavaScript：.js 파일 실행",
  "detail": "보고있는 .js 파일을 node.js 위에서 실행합니다.",
  "type": "process",
  "group": {
    "kind": "test",
    "isDefault": false
  },
  "command": "node",
  "args": ["${fileDirname}/${fileBasenameNoExtension}.js"]
}

// ...tasks.json 뒷 부분...
```

#### 3 > tasks.json > 상세설명

[공식 문서](https://code.visualstudio.com/docs/editor/tasks#vscode)

- tasks 안에 [ `{ ...1번째 작업 정보... }`, `{ ...2번째 작업 정보... }`, ... `{ ...n번째 작업 정보... }` ] 같은 형태로 작업 정보를 나열할 수 있습니다.

  ```json
  {
    // task.json 에 대한 공식문서 https://go.microsoft.com/fwlink/?LinkId=733558
    "version": "2.0.0",
    "tasks": [
      {
        // ...작업 1 에 대한 정보...
      },
      {
        // ...작업 2 에 대한 정보...
      },
      // ...
      {
        // ...작업 n 에 대한 정보...
      }
    ]
  }
  ```

<br />

- tasks 안에 [ `{ ...1번째 작업 정보... }`, `{ ...2번째 작업 정보... }`, ... `{ ...n번째 작업 정보... }` ] 같은 형태로 작업 정보를 나열할 수 있습니다.

  ```json
  // ...tasks.json 앞 부분...

  {
    // ...작업 1 에 대한 정보...
  },

  // ...tasks.json 뒷 부분...
  ```
