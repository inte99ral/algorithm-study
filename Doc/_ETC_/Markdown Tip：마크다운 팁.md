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

## TeX and LaTeX 문법

[latex 문법](https://velog.io/@d2h10s/LaTex-Markdown-%EC%88%98%EC%8B%9D-%EC%9E%91%EC%84%B1%EB%B2%95)

[참고 링크](https://github.blog/news-insights/product-news/math-support-in-markdown/)

<table>
<tr>
  <th>대분류</th>
  <th>소분류</th>
  <th>문법</th>
  <th>예시</th>
</tr>
<!-- ## ROW-00-00 ========================================================= -->
<tr>
  <td rowspan="2">
    글씨 색상
  </td>
  <td>
    색상명
  </td>
  <td>
  
```text
${\color{red}빨간글씨}$
```

  </td>
  <td>

${\color{red}빨간글씨}$

  </td>
</tr>
<!-- ## ROW-00-01 ========================================================= -->
<tr>
  <td>
    색상코드
  </td>
  <td>

```text
$\color{#FF9922} \footnotesize \textnormal{경고문 🚨}$
```

  </td>
  <td>

$\color{#FF9922} \footnotesize \textnormal{경고문 🚨}$

  </td>
</tr>
<!-- ## ROW-01 ============================================================ -->
<tr>
  <td colspan="4">
</tr>
<!-- ## ROW-01-00 ========================================================= -->
<tr>
  <td rowspan="5">
    띄어쓰기
  </td>
  <td>
    강제개행
  </td>
  <td>

```txt
\\
```

  </td>
  <td>

$
x\\
x
$

  </td>
</tr>
<!-- ## ROW-01-01 ========================================================= -->
<tr>
  <td>
    작은 간격(1 칸)
  </td>
  <td>

```txt
\,
```

  </td>
  <td>

$x\,x$

  </td>
</tr>
<!-- ## ROW-01-02 ========================================================= -->
<tr>
  <td>
    중간 간격
  </td>
  <td>

```txt
\;
```

  </td>
  <td>

$x\;x$

  </td>
</tr>
<!-- ## ROW-01-03 ========================================================= -->
<tr>
  <td>
    큰 간격(4 칸)
  </td>
  <td>

```txt
\quad
```

  </td>
  <td>

$x\quad x$

  </td>
</tr>
<!-- ## ROW-01-04 ========================================================= -->
<tr>
  <td>
    더 큰 간격(8 칸)
  </td>
  <td>

```txt
\qquad
```

  </td>
  <td>

$x\qquad x$

  </td>
</tr>
<!-- ## ROW-02 ============================================================ -->
<tr>
  <td colspan="4">
</tr>
<!-- ## ROW-02-00 ========================================================= -->
<tr>
  <td rowspan="8">
    글씨 폰트
  </td>
  <td>
    Normal
  </td>
  <td>

```txt
\textnormal{Normal text}
```

  </td>
  <td>

$
\textnormal{Normal text}
$

  </td>
</tr>
<!-- ## ROW-02-01 ========================================================= -->
<tr>
  <td>
    Bold
  </td>
  <td>

```txt
\textbf{Bold text}
```

  </td>
  <td>

$
\textbf{Bold text}
$

  </td>
</tr>
<!-- ## ROW-02-02 ========================================================= -->
<tr>
  <td>
    Italic
  </td>
  <td>

```txt
\textit{Italic text}
```

  </td>
  <td>

$
\textit{Italic text}
$

  </td>
</tr>
<!-- ## ROW-02-03 ========================================================= -->
<tr>
  <td>
    Underlined
  </td>
  <td>

```txt
\underline{Underlined text}
```

  </td>
  <td>

$
\underline{Underlined text}
$

  </td>
</tr>
<!-- ## ROW-02-04 ========================================================= -->
<tr>
  <td>
    Typewriter
  </td>
  <td>

```txt
\texttt{Typewriter text}
```

  </td>
  <td>

$
\texttt{Typewriter text}
$

  </td>
</tr>
<!-- ## ROW-02-05 ========================================================= -->
<tr>
  <td>
    Roman
  </td>
  <td>

```txt
\textrm{Roman font text}
```

  </td>
  <td>

$
\textrm{Roman font text}
$

  </td>
</tr>
<!-- ## ROW-02-06 ========================================================= -->
<tr>
  <td>
    Sans-serif
  </td>
  <td>

```txt
\textsf{Sans-serif font text}
```

  </td>
  <td>

$
\textsf{Sans-serif font text}
$

  </td>
</tr>
<!-- ## ROW-02-07 ========================================================= -->
<tr>
  <td>
    Blackboard Bold
  </td>
  <td>

```txt
\mathbb
```

  </td>
  <td>

$
솟수∈\mathbb{P}\\
실수∈\mathbb{R}\\
정수∈\mathbb{Z}\\
유리수∈\mathbb{Q}\\
복소수∈\mathbb{C}
$

  </td>
</tr>
<!-- ## ROW-03 ============================================================ -->
<tr>
  <td colspan="4">
</tr>
<!-- ## ROW-03-00 ========================================================= -->
<tr>
  <td rowspan="10">
    글씨 크기
  </td>
  <td>
    가장 작은 크기
  </td>
  <td>

```txt
\tiny: 가장 작은 글씨 크기
```

  </td>
  <td>

$\tiny tiny$

  </td>
</tr>
<!-- ## ROW-03-01 ========================================================= -->
<tr>
  <td>
    매우 작은 크기
  </td>
  <td>

```txt
\scriptsize: 매우 작은 글씨 크기
```

  </td>
  <td>

$\scriptsize script \, size$

  </td>
</tr>
<!-- ## ROW-03-02 ========================================================= -->
<tr>
  <td>
    각주용 크기
  </td>
  <td>

```txt
\footnotesize
```

  </td>
  <td>

$\footnotesize footnote \, size$

  </td>
</tr>
<!-- ## ROW-03-03 ========================================================= -->
<tr>
  <td>
    작은 크기
  </td>
  <td>

```txt
\small
```

  </td>
  <td>

$\small small$

  </td>
</tr>
<!-- ## ROW-03-04 ========================================================= -->
<tr>
  <td>
    기본 크기
  </td>
  <td>

```txt
\normalsize
```

  </td>
  <td>

$\normalsize normal \, size$

  </td>
</tr>
<!-- ## ROW-03-05 ========================================================= -->
<tr>
  <td>
    약간 큰 크기
  </td>
  <td>

```txt
\large
```

  </td>
  <td>

$\large large$

  </td>
</tr>
<!-- ## ROW-03-06 ========================================================= -->
<tr>
  <td>
    큰 크기
  </td>
  <td>

```txt
\Large
```

  </td>
  <td>

$\Large Large$

  </td>
</tr>
<!-- ## ROW-03-07 ========================================================= -->
<tr>
  <td>
    더 큰 크기
  </td>
  <td>

```txt
\LARGE
```

  </td>
  <td>

$\LARGE LARGE$

  </td>
</tr>
<!-- ## ROW-03-08 ========================================================= -->
<tr>
  <td>
    매우 큰 크기
  </td>
  <td>

```txt
\huge
```

  </td>
  <td>

$\huge huge$

  </td>
</tr>
<!-- ## ROW-03-09 ========================================================= -->
<tr>
  <td>
    가장 큰 크기
  </td>
  <td>

```txt
\Huge
```

  </td>
  <td>

$\Huge Huge$

  </td>
</tr>
<!-- ## ROW-04 ============================================================ -->
<tr>
  <td colspan="4">
</tr>
<!-- ## ROW-04-00 ========================================================= -->
<tr>
  <td rowspan="40">
    수학 기호
  </td>
  <td>
    같지 않음
  </td>
  <td>

```txt
\ne
```

  </td>
  <td>

$
\ne
$

  </td>
<tr>
<!-- ## ROW-04-00 ========================================================= -->
<tr>
  <td>
    항상 같음
  </td>
  <td>

```txt
\equiv
```

  </td>
  <td>

$
\equiv
$

  </td>
<tr>
<!-- ## ROW-04-01 ========================================================= -->
<tr>
  <td>
    플러스마이너스
  </td>
  <td>

```txt
\pm
```

  </td>
  <td>

$
\pm
$

  </td>
<tr>
<!-- ## ROW-04-02 ========================================================= -->
<tr>
  <td>
    루트
  </td>
  <td>

```txt
\sqrt
```

  </td>
  <td>

$
\sqrt{2}
$

  </td>
<tr>
<!-- ## ROW-04-03 ========================================================= -->
<tr>
  <td>
    분수형
  </td>
  <td>

```txt
\over
\frac{b}{a}
```

  </td>
  <td>

$
{1 \over 2}
$

$
\frac{1}{2}
$

  </td>
<tr>
<!-- ## ROW-04-04 ========================================================= -->
<tr>
  <td>
    위첨자(superscript)
  </td>
  <td>

```txt
^
```

  </td>
  <td>

$
x^{sup}_{sub}
$

  </td>
<tr>
<!-- ## ROW-04-05 ========================================================= -->
<tr>
  <td>
    아래첨자(subscript)
  </td>
  <td>

```txt
_
```

  </td>
  <td>

$
x_{sub}^{sup}
$

  </td>
<tr>
<!-- ## ROW-04-06 ========================================================= -->
<tr>
  <td>
    조건
  </td>
  <td>

```txt
\begin{cases} ... \end{cases}
```

  </td>
  <td>

$
A = \begin{cases} p∈\mathbb{P} \\ a∈\mathbb{Z} \end{cases} ⟹ a^p≡a
$

  </td>
<tr>
<!-- ## ROW-04-07 ========================================================= -->
<tr>
  <td>
    괄호
  </td>
  <td>

```txt
\left ( \right )
\left | \right |
\left [ \right ]
\left \{ \right \}
\left \langle  \right \rangle
\left \|  \right \|
```

  </td>
  <td>

left, right 지정하지 않았을 경우, 괄호 크기가 전체를 덮지 못합니다.<br/>
$
a ( x^{2}+\frac{b}{a}x )
$

left, right 지정했을 경우, 괄호 크기가 전체를 덮습니다.<br/>
$
a \left ( x^{2}+\frac{b}{a}x \right )
$

  </td>
<tr>
<!-- ## ROW-04-07 ========================================================= -->
<tr>
  <td>
    논리적 동치
  </td>
  <td>

```txt
$a \Leftrightarrow b$
$a \iff b$
```

  </td>
  <td>

$a \Leftrightarrow b$

$a \iff b$

  </td>
<tr>
<!-- ## ROW-04-07 ========================================================= -->
<tr>
  <td>
    논리적 조건
  </td>
  <td>

```txt
$A \Rightarrow B$
```

  </td>
  <td>

$A \Rightarrow B$

  </td>
<tr>
<!-- ## ROW-04-07 ========================================================= -->
<tr>
  <td>
    나누어 떨어짐
  </td>
  <td>

```txt
$a \mid b$
```

  </td>
  <td>

$a \mid b$

  </td>
<tr>
<!-- ## ROW-04-07 ========================================================= -->
<tr>
  <td>
    서로소
  </td>
  <td>

```txt
$a \perp p$
```

  </td>
  <td>

$a \perp p$

  </td>
<tr>
<!-- ## ROW-04-xx ========================================================= -->
</table>

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
- css min-width 적용을 못하여 가로 폭이 축소되는 부분을 table을 사용하여 글씨나 공백을 이용하여 넓혀줍니다. 한 글씨가 14px ~ 16px 정도인게 일반적입니다.

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

&nbsp; github 기준으로 고정 넓이 수치는 852px 정도의 넓이가 적당합니다. 물론 `<img alt="00" src="00.svg" style="max-width: 100%; height: auto;" />` 처럼 max-width 의 넓이에 비례하는 가변수치로 처리할 수도 있습니다.

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
