# 기본 형태：Basic Form

## HTML 가장 기본 양식

```html
<!DOCTYPE html>
<html>
    <head>
        <title>My Page</title>
    </head>
    <body>
        <h1>Hello, world!</h1>
    </body>
</html>
```

## HTML-CSS-JS 양식

```html
<!-- HTML 기본 형태 -->
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <!-- <meta name='viewport' content='width=device-width, initial-scale=1'> -->
        <title>기본 형태 BasicForm</title>
        <!-- CSS (external style) -->
        <link href="./style.css" rel="stylesheet" />
        <!-- JS (external style) -->
        <script src="./script.js" defer></script>
        <!-- CSS (internal style) -->
        <!-- <style></style> -->
    </head>
    <body>
        <div>
            <!-- CSS (inline style) -->
            <div style="color:red">테스트</div>
        </div>
        <!-- JS (external style) -->
        <!-- <script></script> -->
    </body>
</html>
```

```css
/* css 디폴트 설정 */
* {
    position: relative;
    box-sizing: border-box;
    padding: 0;
    margin: 0;
    border: 0;
}
```

```js
// js 디폴트 스크립트
console.log('TEST LOG');
```

Semantic HTML 레이아웃
[Semantic HTML 레이아웃](https://velog.io/@lobinb797/Day95-NodeJS-)

## 외부 raw file 을 렌더링하는 양식

&nbsp; 무거운 파일이 존재할 때 사용되는 전략이 있습니다.

&nbsp; 페이지를 직접 브라우저에서 띄우는 것이 아니라 우회하여 빌드 결과를 별도 CDN에 업로드하고 iframe으로 불러오면 서버 부하를 최소화하고, 로딩 속도를 개선할 수 있습니다.

&nbsp; 예를 들어 Unity 게임 빌드 처럼 에셋파일들이 무겁다면 `<iframe src="https://cdn.example.com/unitygame/index.html" style={{ width: "100%", height: "600px", border: "none" }}/>` 이런 형태로 다른 주소로 배포하는 html 를 렌더링만 하도록 만들 수 있습니다.

&nbsp; 페이지 전체를 렌더링하는 양식은 다음과 같습니다.

```html
<iframe id="viewer" style="width:100%;height:100vh;"></iframe>
<script>
    fetch('https://raw.githubusercontent.com/USER/REPO/BRANCH/index.html')
        .then((res) => res.text())
        .then((html) => {
            const iframe = document.getElementById('viewer');
            iframe.srcdoc = html;
        });
</script>
```
