# 비동기처리：Promise

[참조 링크](https://www.daleseo.com/js-async-promise/)

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
