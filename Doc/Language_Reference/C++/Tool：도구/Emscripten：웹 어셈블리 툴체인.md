# Emscripten：웹 어셈블리 툴체인

## Emscripten > 개념 설명

Emscripten은 C++ 코드를 WebAssembly로 컴파일하는 데 사용되는 툴체인입니다. 이를 통해 C++로 만든 게임을 HTML 페이지 위에 띄울 수 있습니다.

## Emscripten > 설치

```bash
# 설치
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk

# 최신 버전 설치 및 활성화
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

## Emscripten > 사용 예시

&nbsp; 예를 들어, a 와 b 를 더하여 화면에 a+b 를 띄우는 게임파일 game.cpp 가 있다고 합시다.

```cpp
// # game.cpp
#include <iostream>
extern "C" {
    int add(int a, int b) {
        return a + b;
    }
}
```

&nbsp; 다음의 Emscripten 명령어와 옵션들로 컴파일 할 수 있습니다.

```bash
emcc game.cpp -o game.js -s EXPORTED_FUNCTIONS="['_add']" -s MODULARIZE=1 -s EXPORTED_RUNTIME_METHODS="ccall,cwrap"
```

&nbsp; 옵션들의 세부 설명은 다음과 같습니다.

- **-o game.js**: JavaScript와 WebAssembly 파일이 생성됩니다.

- **-s EXPORTED_FUNCTIONS**: WebAssembly에서 사용할 함수를 지정합니다.

- **-s MODULARIZE=1**: 모듈화된 JavaScript 파일을 생성합니다.

- **-s EXPORTED_RUNTIME_METHODS**: JavaScript에서 Wasm 함수를 호출할 수 있도록 설정합니다.

&nbsp; 위 파일을 HTML 에서 다음과 같이 호출할 수 있습니다.

```html
<!DOCTYPE html>
<html>
  <head>
    <title>WebAssembly Game</title>
    <script src="game.js"></script>
  </head>
  <body>
    <h1>WebAssembly Game Example</h1>
    <script>
      // WebAssembly 모듈 초기화
      Module.onRuntimeInitialized = function () {
        const add = Module.cwrap('add', 'number', ['number', 'number']);
        console.log('3 + 5 =', add(3, 5)); // 결과 출력
      };
    </script>
  </body>
</html>
```
