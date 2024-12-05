# 비동기처리：Promise

[참조 링크](https://www.daleseo.com/js-async-promise/)

## Promise 객체와 async

&nbsp; 웹 서비스는 여러 병렬적인 계산이 요구됬습니다. 따라서 JavaScript는 비동기 처리 기능을 계속해서 발전해왔습니다. ES5 에서는 콜백함수를 이용하여 비동기 작업을 처리하였으나, ES6 에서 Promise 라는 비동기처리 객체를 추가하였습니다. 그리고 마침내 ES8(ECMAScript 2017) 에 와서 async/await 구문을 추가하여 동기코드와 똑같은 형식으로 높은 가독성과 유지보수성을 지키며 비동기작업을 다룰 수 있게 되었습니다.

&nbsp; async 로 선언된 함수는 비동기 처리를 통하여 프로세스 중에 호출된 시점부터 동작합니다. 위를 이용하면 async 함수의수는 다른 변수들과 마찬가지로 호이스팅은 일어납니다. 하지만 async 함수 표현식의 경우는 이야기가 다릅니다.인터프리터가 읽는 시점에서는 할당 동작 조차 취하지 않았기 때문에 async 함수 표현식은 호이스팅되지 않습니다.

ES8(ECMAScript 2017)에 추가되었습니다

JavaScript에서 비동기 프로그래밍 방식의 발전 과정은 다음과 같습니다:
ES5: 콜백 함수를 사용한 비동기 처리
ES6 (2015): Promise 객체 도입
ES8 (2017): async/await 구문 추가

ES5와 ES6의 비동기 처리
ES5에서는 주로 콜백 함수를 사용하여 비동기 작업을 처리했습니다2.
ES6에서는 Promise가 도입되어 비동기 작업을 더 체계적으로 관리할 수 있게 되었습니다2.
async/await의 장점
async/await는 Promise를 더욱 간결하고 직관적으로 사용할 수 있게 해줍니다. 이를 통해 비동기 코드를 마치 동기 코드처럼 작성할 수 있어, 가독성과 유지보수성이 크게 향상됩니다2.
따라서, async 키워드는 ES5나 ES6에 추가된 것이 아니라, ES8(ECMAScript 2017)에서 정식으로 도입되었습니다.

```javascript

```

async/await는 반드시 async 함수 내부에서 사용해야 합니다.
최상위 레벨 코드에서 await를 사용하려면 모듈 스코프에서 실행되어야 합니다.

## 원격 API 호출：fetch

[참조 링크](https://www.daleseo.com/js-window-fetch/)

&nbsp; fetch() 함수는 첫번째 인자로 URL, 두번째 인자로 옵션 객체를 받고, Promise 타입의 객체를 반환합니다.

&nbsp; 반환된 객체는, API 호출이 성공했을 경우에는 응답(response) 객체를 resolve하고, 실패했을 경우에는 예외(error) 객체를 reject합니다.

```typescript
const testLocal = async () => {
  return new Promise((resolve, reject) => {
    // fetch 옵션의 상세 설명 https://developer.mozilla.org/ko/docs/Web/API/Window/fetch
    fetch('server/data.json', {
      method: 'GET', // { GET | POST | PUT | DELETE }
      mode: 'cors', // { no-cors | cors | same-origin }
      cache: 'no-cache', // { default | no-cache | reload | force-cache | only-if-cached }
      credentials: 'same-origin', // { include | same-origin | omit }
      redirect: 'follow', // { manual | follow | error }
      referrerPolicy: 'no-referrer', // { no-referrer | no-referrer-when-downgrade | origin | origin-when-cross-origin | same-origin | strict-origin | strict-origin-when-cross-origin | unsafe-url }
      headers: {
        'Content-Type': 'application/json', // { application/json | application/x-www-form-urlencoded}
      },
    })
      .then((response) => {
        if (!response.ok) throw new Error(`HTTP error! status: ${response.status}`);
        return response.json();
      })
      .then((data) => {
        console.log('JSON 데이터 로드 완료:', data);
        resolve(data);
      })
      .catch((error) => {
        console.error('JSON 파일 로드 중 오류 발생:', error);
        reject(error);
      });
  });
};
```

## 동기적 컨텍스트

비동기 함수의 결과를 동기적 컨텍스트에서 const 변수로 받아 사용하는 것은 JavaScript의 비동기 특성 때문에 직접적으로는 불가능합니다.

비동기 함수의 결과를 완전히 동기적으로 처리하는 것은 불가능하며, 항상 비동기적 컨텍스트 내에서 처리해야 합니다.
다음 방법들을 사용하면 비동기 함수의 결과를 마치 동기적으로 처리하는 것처럼 코드를 작성할 수 있습니다.

### async/await 사용

```javascript
async function main() {
  const result = await asyncFunction();
  console.log(result);
}

main();
```

### 즉시 실행 async 함수:

```javascript
(async () => {
  const result = await asyncFunction();
  console.log(result);
})();
```

### Promise 체이닝:

```javascript
asyncFunction().then((result) => {
  console.log(result);
});
```
