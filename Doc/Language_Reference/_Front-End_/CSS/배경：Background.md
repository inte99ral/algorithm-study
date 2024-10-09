# 배경：Background

[참고 링크](https://blog.naver.com/iyakiggun/100174677035)
[공식 문서](https://developer.mozilla.org/en-US/docs/Web/CSS/background-repeat)

## 목차

- background-color
- background-image (CSS3부터 다중백그라운드 이미지도 지원)
- background-repeat
- background-position
- background-attachment
- background-origin (CSS3에서 추가됨)
- background-clip (CSS3에서 추가됨)
- background-size (CSS3에서 추가됨)

## 바탕 색상：background-color

- 해당 태그 오브젝트 전체 바탕색을 결정하는 속성입니다.

```css
:root {
  /* # background-color ============================== */
  --var-color: red; /* 관용색명 */
  --var-color: #ff0000; /* 색의 헥사코드 */
  --var-color: rgb(255, 0, 0); /* RGB 값 */
  --var-color: rgba(255, 0, 0, 0.5); /* RGB + 투명도A 값 */
}

.target {
  width: 1000px;
  height: 1000px;
  background-color: var(--var-color);
}
```

## 이미지 삽입：background-image

- 이미지를 배경에 삽입합니다.

```css
:root {
  /* # background-image ============================== */
  --var-image: url(0.png); /* url(이미지 경로) */
}

.target {
  width: 1000px;
  height: 1000px;
  background-image: var(--var-image);
}
```

## 배경 패턴 반복：background-repeat

[참고 링크](https://superkts.com/css/background-repeat)

- 배경으로 사용된 이미지나 패턴보다 배경크기가 더 큰 경우, 벽지보다 큰 벽을 채울 때 처럼 패턴을 계속 반복하면서 빈 공간을 채웁니다.

```css
:root {
  /* # background-color ============================== */
  --var-color: #fef9e9; /* 색의 헥사코드 */

  /* # background-image ============================== */
  --var-image: url(0.png); /* url(이미지 경로) */

  /* # background-repeat ============================= */
  /* ## 기본 속성 */
  /* ## { repeat | repeat-x | repeat-y | no-repeat | space | round } */
  --var-repeat: no-repeat; /* 반복하지 말기 */
  --var-repeat: repeat-x; /* x축 가로방향만 반복 */
  --var-repeat: repeat-y; /* y축 세로방향만 반복 */
  --var-repeat: repeat; /* 반복 */
  --var-repeat: space; /* 반복패턴이 잘리지 않도록 패턴 사이 여백을 만듬 */
  --var-repeat: round; /* 반복패턴이 잘리지 않도록 패턴의 크기를 조정함*/

  /* ## 다중 속성 : "x축속성 y축속성" 두 개의 기본 속성을 띄어쓰기로 구분해서 적용가능 */
  /* ## <horizion-repeat-style> <vertical-repeat-style> */
  --var-repeat: space repeat; /* X축은 여백반복, Y축은 기본반복 */

  /* ## 전역 속성 : 일반적으론 사용되지 않으며 CSS Cascade 우선순위 결정에 사용되는 명령어 입니다. */
  /* ## { inherit | initial | revert | revert-layer | unset } */
  --var-repeat: inherit; /* 부모 요소의 값을 상속 */
  --var-repeat: initial; /* 기본값으로 초기화 */
  --var-repeat: revert; /* 이전에 정의한 값으로 롤백 */
  --var-repeat: unset; /* 설정 해제 */
}

.target {
  width: 1000px;
  height: 1000px;
  background-color: var(--var-color);
  background-image: var(--var-image);
  background-repeat: var(--var-repeat);
}
```

## 배경 패턴 위치：background-position

- 전체배경 위에서 패턴의 위치를 결정합니다.

```css
:root {
  /* # background-image ============================== */
  --var-image: url(0.png); /* url(이미지 경로) */

  /* # background-position =========================== */
  /* ## 형식 : <왼쪽 끝과 사이의 거리> <위 천장과 사이의 거리> */
  /* ## 거리표현 종류 : { px(픽셀) | %(퍼센트) | 관용명(left, right, top, bottom) } */
  --var-position: 100px -100px;
  --var-position: 100% 50%;
  --var-position: right center;
}

.target {
  width: 1000px;
  height: 1000px;
  background-image: var(--var-image);
  background-position: var(--var-position);
}
```

## 배경 패턴 고정：background-attachment

```css
:root {
  /* # background-image ============================== */
  --var-image: url(0.png); /* url(이미지 경로) */

  /* # background-position =========================== */
  /* ## 속성 종류 : { "scroll" | fixed | local } */
  --var-attachment: scroll; /* 기본값, 외적으론 움직이나 내적으로는 배경이 고정됩니다. */
  --var-attachment: fixed; /* 배경이미지를 고정하고, 콘텐츠만 움직입니다. */
  --var-attachment: local; /* 배경이미지와 콘텐츠가 같이 움직입니다. */
}

.target {
  position: relative;
  width: 1000px;
  height: 2000px;
  background-image: var(--var-image);
  background-attachment: var(--var-attachment);
  overflow-y: scroll;

  &::after {
    content: '';
    position: absolute;
    top: 0px;
    left: 0px;
    width: 100px;
    height: 4000px;
  }
}
```

## 속성 축약：Shorthand Property

[설명링크](https://amango.tistory.com/84)

```css
background-image: url(../img.jpg);
background-repeat: no-repeat;
background-position: center top;
background-size: 100%;

background: url() no-repeat center top / 100%;
```

```css
.root {
  /* # background-color ============================== */
  /* 색상코드 */
  --var-color: #110000;
  /* # background-repeat ============================= */
  /* 기본 속성 : repeat | repeat-x | repeat-y | no-repeat | space | round  */
  /* 다중 속성 : "x축속성 y축속성" 두 개의 속성을 띄어쓰기로 구분해서 적용가능*/
  /* 전역 속성 */
}

.wrap1 {
  background-color: #ccc; /* 색상 */
  background-image: url('image/photo1.png');
  background-position: left center;
  background-size: 20%;
  background-repeat: no-repeat; /* 반복여부, 두 개를 쓸 경우 x축 y축,  */
  background-attachment: fixed;
}

.wrap2 {
  .wrap {
    background: #ccc url('image/photo1.jpg') left center/20% no-repeat fixed;
  }
}
```
