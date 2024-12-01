# 스프레드 & 레스트 연산자：Spread & Rest Operator

## 스프레드 연산자：Spread Operator

## 개념정리

&nbsp; JavaScript에서 ...와 같은 방식으로 배열의 여러 값을 지칭하는 문법은 "스프레드 연산자(Spread Operator)"라고 불립니다.

&nbsp; 스프레드 연산자가 배열/객체 앞에 붙게 되면 해당 배열/객체를 여러 요소로 `분해하여 펼칩니다`.

스프레드 연산자는 ES6(ECMAScript 2015)에서 도입되었으며, 코드를 더 간결하고 가독성 있게 만드는 데 도움을 줍니다.

## 예시

```js
const numbers = [1, 2, 3];
const moreNumbers = [...numbers, 4, 5, 6];
console.log(moreNumbers); // [1, 2, 3, 4, 5, 6]
```

## 레스트 연산자：Rest Operator

### 레스트 연산자 > 개념정리

&nbsp; JavaScript에서도 ...를 이용하여 함수에 인자의 수가 유동적인 가변인자를 적용할 수 있습니다. 이때 ...을 "레스트 연산자(Rest Operator)"라고 부릅니다.

&nbsp; 레스트 연산자가 인자 앞에 붙게 되면 앞으로 들어올 인자들을 해당 인자명의 `배열/객체로 묶습니다`.

&nbsp; 주로 들어올 인자의 수가 유동적인 함수의 매개변수에 사용되거나, ES6 구조 분해 할당에서 객체의 인자에 넣은 값 중에서 나머지 뒷 부분들을 끼워넣을 경우에 사용됩니다.

### 레스트 연산자 > 예시

```js
function sum(...numbers) {
  return numbers.reduce((total, num) => total + num, 0);
}
sum(1, 2, 3, 4); // 10
```
