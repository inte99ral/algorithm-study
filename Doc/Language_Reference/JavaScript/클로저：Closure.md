# 클로저：Closure

&nbsp; 클로저(Closure)는 함수와 그 함수가 선언된 렉시컬 환경(Lexical Scope)의 조합입니다. 클로저는 함수가 자신이 선언된 스코프의 변수에 접근할 수 있게 해주는 메커니즘입니다.

&nbsp; 예를들어 다음의 코드는 10 이 아니라 1를 두 번 출력합니다.

```js
var x = 1; // global

function first() {
  var x = 10;
  second();
}

function second() {
  console.log(x);
}

first(); // ?
second(); // ?
```

&nbsp; 그 이유는 변수 x 가 스코프 범위에 따라 global 범위의 x, first() 의 x, second() 안의 x로 구분되었으며 두 x 가 global x의 1 값을 레퍼런스로 삼고있기 때문입니다. 이를 스코프 체인(Scope chain) 이라고 하며, 이렇게 어디서 호출하였는 지와 무관하게 코드 상 선언된 위치에서 정적으로 스코프 범위가 결정되는 것을 렉시컬 스코프(Lexical Scope) 라고 부릅니다.

&nbsp; 그렇다면 스코프 체인과 무관하게 second() 안에 x 값을 적용하려면 어떻게 해야할까요? 그 방법이 바로 closure 입니다.

```js
function outerFunction(x) {
  return function innerFunction(y) {
    return x + y;
  };
}

const closure = outerFunction(5);
console.log(closure(3)); // 출력: 8
```

&nbsp; 클로저는 다음의 특징을 가집니다.

- 외부 함수의 변수에 접근 가능
- 함수가 선언된 환경을 기억
- 데이터 은닉과 캡슐화를 가능하게 함
