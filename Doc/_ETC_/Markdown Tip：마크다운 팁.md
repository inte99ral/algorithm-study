# Markdown Tip：마크다운 팁

## 스타일리쉬 블록

- Note 블록

  > [!NOTE]
  > DON'T DELETE THE `package.json` file!

- Warning 블록

  > [!WARNING]
  > DON'T DELETE THE `package.json` file!

- Important 블록

  > [!IMPORTANT]
  > Read the contribution guideline before adding a pull request.

## TeX and LaTeX style syntax

[latex 문법](https://velog.io/@d2h10s/LaTex-Markdown-%EC%88%98%EC%8B%9D-%EC%9E%91%EC%84%B1%EB%B2%95)

[참고 링크](https://github.blog/news-insights/product-news/math-support-in-markdown/)

$${\color{red}Red}$$

${\color{lightgreen}Light \space Green}$

$\scriptsize{\color{#FF9922}Light \space Green}$

$\color{#FF9922} \footnotesize \textnormal{package.json \space 확인 🚨}$

When $a \ne 0$, there are two solutions to $(ax^2 + bx + c = 0)$ and they are
$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a} $$

SASS > $\color{#FF9922} \footnotesize \textbf{node-sass 에러 🚨}$

## 반응형 이미지

```markdown
<a href="#">
  <picture>
    <source media="(min-width: 720px)" srcset="00.svg" />
    <img src="01.svg" width="800" height="400" alt="Click to see the source" />
  </picture>
</a>
```

## 코드 확장/축소

<details>
  <summary>

```cpp
int main() {
  ... 클릭하여 확장 ...
```

  </summary>
  
```cpp
  ... 클릭하여 축소 ...
  return 0;
}
```
</details>

## 가로 폭이 더 큰 CSS

- 코드블럭이나 table은 overflow 시에 스크롤 취급을 해줍니다.
- css min-width 적용을 못하여 가로 폭이 축소되는 부분을 table을 사용하여 글씨나 공백을 이용하여 넓혀줍니다. 한 글씨가 14px 정도인게 일반적입니다.

<details>
  <summary>테스트 00</summary>

  <div style="overflow-x: scroll">
    <table>
      <tr>
        <td>　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　</td>
      </tr>
      <tr>
        <td>
          <a href="#"><img src="./.asset/마크다운：Markdown/3.jpg" width="1400px" height="400" alt="css-in-readme"></a>
        </td>
      </tr>
    </table>
  </div>
</details>

## 클릭 안되게 하기

<a href="#">
  <img src="./.asset/마크다운：Markdown/2.svg" width="400" height="400" alt="css-in-readme">
</a>

## 마크다운 CSS：Markdown CSS

### 개요

&nbsp; 마크다운 문법은 html 태그들을 지원하나 마크다운 문서를 읽는 체계에 따라 지원하는 정도가 다릅니다. vscode 미리보기에서는 html 문법을 거의 다 지원하는 반면, Github는 악용할 여지를 없애기 위하여 일반적인 Markdown 문법을 그대로 사용하지 않습니다. 웹 사이트의 보안과 일관성을 위해 Markdown을 HTML로 변환 후 추가 사후 처리 및 정리 작업을 수행합니다. 자세한 Github 마크다운 사양은 [Github Flavored Markdown Spec 문서](https://github.github.com/gfm/)에서 확인 하실 수 있습니다.

&nbsp; Github 가 HTML으로 변환하는 부분에서 많은 부분을 지원하지 않게되며, 특히 CSS와 js가 적용되지 않는 부분이 치명적입니다. 그럼에도 불구하고 애니메이션이나 커스텀 디자인을 넣는 편법이 존재합니다.

&nbsp; 이 편법의 구현에는 두 가지 포인트가 있습니다.

- 첫번째 포인트는 SVG 파일을 이미지 취급하여 `<img src="./file.svg" alt="" /> ` 처럼 마크다운 문서에서 띄울 수 있다는 점 입니다.
- 두번째 포인트는 SVG에서 `<foreignObject>` 태그를 통하여 텍스트 문서나 HTML 오브젝트를 지원한다는 부분입니다.

결과적으로 SVG 구현을 경유하여 HTML 오브젝트를 Markdown 문서에 간접적으로 구현이 가능합니다. 이 경우엔 결론적으론 그저 SVG 이미지를 띄운 것이기에 Github의 README.md 마크다운 문서에서도 구현이 됩니다.

&nbsp; github 기준으로 852px 정도의 넓이가 적당합니다.

&nbsp; 예를 들어 다음과 같은 html 페이지라면

```html
<!DOCTYPE html>
<html>
  <style>
    @font-face {
      font-family: NanumSquareNeoEb;
      src: url(../font/NanumSquareNeo/NanumSquareNeo-dEb.ttf);
    }

    :root {
      --size-width: 852px; /* width value */
      --size-height: 284px; /* height value */
    }

    * {
      font-family: NanumSquareNeoEb;
      box-sizing: border-box;
      background-color: inherit;
      padding: 0;
      margin: 0;
      border: 0;
    }

    body {
      /* border: 1px solid black; <===== Test line */
      width: var(--size-width);
      height: var(--size-height);
      display: flex;
      justify-content: center;
      align-items: center;
    }

    .header {
      width: calc(100% - 12px);
      height: calc(100% - 12px);
      border-radius: 24px;

      /* background: linear-gradient(150deg, #6aa5e3, #6866e9); */

      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
      gap: 24px;

      /* color: white; */
      font-size: 24px;
      overflow: hidden;
    }

    .outer {
      box-shadow: 4px 4px 10px -1px rgba(0, 0, 0, 0.25), -4px -4px 10px -1px rgba(255, 255, 255, 0.25);
    }

    .inner {
      box-shadow: inset 4px 4px 10px -1px rgba(0, 0, 0, 0.25), inset -4px -4px 10px -1px rgba(255, 255, 255, 0.25);
    }
  </style>
  <body>
    <div class="header outer">
      <div>Hello, world!</div>
      <div>안녕, 세계!</div>
    </div>
  </body>
</html>
```

&nbsp; 다음과 같이 svg 파일 이미지로 바꿀 수 있습니다.

```html
<svg fill="none" viewBox="0 0 852 284" width="852" height="284" xmlns="http://www.w3.org/2000/svg">
  <foreignObject width="100%" height="100%">
    <div id="html" xmlns="http://www.w3.org/1999/xhtml">
      <style>
        <!-- ... 생략 ... -->
      </style>
      <body>
        <!-- ... 생략 ... -->
      </body>
    </div>
  </foreignObject>
</svg>
```

&nbsp; 이것을 마크다운 문서에 적용해주시면 됩니다.

```md
<center>
<a href="#"><img alt="alt-message" src="./asset/svg/00.svg" width="852"></a>
</center>
```

### 외부 리소스 관련 문제

&nbsp; 외부 리소스 로딩 제한, 경로 참조 시 보안 정책 또는 렌더링 환경 차이로 인해 외부 에셋을 가져오지 못합니다.

&nbsp; Base64 임베딩 인코딩하여 대체해주세요.

### 예시

[예시](https://github.com/sindresorhus/css-in-readme-like-wat?tab=readme-ov-file)
Doc\Language_Reference\Front-End\CSS\asset\마크다운 CSS：Markdown CSS\0.svg

<a href="#"><img src="./.asset/마크다운：Markdown/0.svg" width="800px" height="400" alt="css-in-readme"></a>

<a href="#"><img src="./.asset/마크다운：Markdown/2.svg" width="800px" height="400" alt="css-in-readme"></a>

<center>
<a href="#"><img src="./asset/svg/00.svg" width="852" height="284" alt="css-in-readme"></a>
</center>
