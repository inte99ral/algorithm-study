# 기본 형태：Basic Form

```html
<!-- HTML 기본 형태 -->
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>기본 형태 BasicForm</title>
        <!-- (external style) -->
        <link href="./main.css" rel="stylesheet" />
        <script src="./main.js" defer></script>
        <!-- <style></style> (internal style) -->
    </head>
    <body>
        <div>
            <!-- (inline style) -->
            <div style="color:red">테스트</div>
        </div>
        <!-- <script></script> (internal style) -->
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
