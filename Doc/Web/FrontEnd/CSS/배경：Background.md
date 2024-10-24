# 배경：Background

[참고 링크](https://blog.naver.com/iyakiggun/100174677035)
[공식 문서](https://developer.mozilla.org/en-US/docs/Web/CSS/background-repeat)

## 목차

- background-color
- background-image (CSS3부터 다중백그라운드 이미지도 지원)
- background-repeat
- background-attachment
- background-position
- background-size (CSS3에서 추가됨)
- background-origin (CSS3에서 추가됨)
- background-clip (CSS3에서 추가됨)

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

## 배경패턴 반복：background-repeat

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

## 배경패턴 고정：background-attachment

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

## 배경패턴 위치：background-position

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

## 배경패턴의 크기：background-size

```css
:root {
  /* # background-image ============================== */
  --image: url(0.png); /* url(이미지 경로) */

  /* # background-size ============================== */
  --size: auto; /* 원래 배경 이미지 크기만큼 표시(기본 값) */
  --size: contain; /* 지정한 요소 안에 배경 이미지가 다 들어오도록 이미지를 확대/축소 */
  --size: cover; /* 지정한 요소를 다 덮도록 배경이미지를 확대/축소 */
  --size: 50%; /* 공간에 대한 배경의 크기 백분율 */
  --size: 50% 100%; /* [<너비_백분율> <높이_백분율>] 비율 지정 */
  --size: 10px 10px; /* [<너비_값> <높이_값>] 고정값 지정 */
}

.target {
  width: 1000px;
  height: 1000px;
  border: 10px dashed yellowgreen;

  background-image: var(--image);
  background-size: var(--size);
}
```

## 배경패턴 시작점：background-origin

- 요소 박스의 배경 이미지를 어느 영역을 시작점으로 잡을 지를 설정합니다.

```css
:root {
  /* # background-color ============================== */
  --color: #fef9e9; /* 색의 헥사코드 */

  /* # background-image ============================== */
  --image: url(0.png); /* url(이미지 경로) */

  /* # background-repeat ============================= */
  --repeat: no-repeat; /* 반복하지 말기 */

  /* # background-origin ============================== */
  /* ## { "padding-box" | border-box | content-box } */
  --origin: padding-box; /* "기본값", 패딩이 시작되는 부분이 시작 기준 */
  --origin: border-box; /* 보더가 시작되는 부분이 시작 기준 */
  --origin: content-box; /* 패딩 내부 컨텐츠가 시작되는 부분이 시작 기준 */
}

.target {
  width: 1000px;
  height: 1000px;
  padding: 100px;
  border: 10px dashed yellowgreen;

  background-color: var(--color);
  background-image: var(--image);
  background-repeat: var(--repeat);
  background-origin: var(--origin);
}
```

## 배경패턴이 차지하는 범위：background-clip

- 배경이 요소의 어디까지 채울 것인지를 결정합니다.

```css
:root {
  /* # background-color ============================== */
  --color: #fef9e9; /* 색의 헥사코드 */

  /* # background-image ============================== */
  --image: url(0.png); /* url(이미지 경로) */

  /* # background-repeat ============================= */
  --repeat: no-repeat; /* 반복하지 말기 */

  /* # background-clip ============================== */
  /* ## { padding-box | "border-box" | content-box } */
  --clip: padding-box; /* 패딩이 시작되는 부분이 시작 기준 */
  --clip: border-box; /* "기본값", 보더가 시작되는 부분이 시작 기준 */
  --clip: content-box; /* 패딩 내부 컨텐츠가 시작되는 부분이 시작 기준 */
}

.target {
  width: 1000px;
  height: 1000px;
  padding: 100px;
  border: 10px dashed yellowgreen;

  background-color: var(--color);
  background-image: var(--image);
  background-clip: var(--clip);
}
```

## 속성 축약：Shorthand Property

```css
:root {
  /* # background-color ============================== */
  --color: #fef9e9;

  /* # background-image ============================== */
  --image: url(0.png); /* url(이미지 경로) */

  /* # background-repeat ============================= */
  --repeat: no-repeat; /* 반복하지 말기 */

  /* # background-attachment ========================= */
  --attachment: local;

  /* # background-position =========================== */
  --position: left top;

  /* # background-size =============================== */
  --size: 100px 100px;

  /* # background-origin ============================= */
  --origin: content-box; /* 패딩 내부 컨텐츠가 시작되는 부분이 시작 기준 */

  /* # background-clip =============================== */
  --clip: content-box; /* 패딩 내부 컨텐츠가 시작되는 부분이 시작 기준 */
}

.target {
  position: relative;
  overflow-y: scroll;
  width: 1000px;
  height: 1000px;
  padding: 100px;
  border: 10px dashed yellowgreen;

  /* # background shorthand ========================== */
  /* ## 각 background-... 값들을 생략하거나 한 번 언급할 수 있습니다.
  /* ## 요소들이 어떤 것을 의미하는 지 명확하다면, 요소들의 순서는 상관 없습니다. */
  /* ## position 과 size, 두 값의 혼동을 막기 위해 [<position> / <size>] 형태로 명시해야합니다. */
  /* ## origin 과 clip 이 한 번 언급된 경우, 해당 값을 origin과 clip에 전부 적용합니다. */
  /* ## origin 과 clip 이 두 번 언급될 경우, 처음 값을 <origin>으로 두번째 값을 <clip>으로 받아들입니다. */
  background: var(--color) var(--image) var(--repeat) var(--attachment) var(--position) / var(
      --size
    ) var(--origin) var(--clip);

  &::after {
    content: '';
    position: absolute;
    top: 0px;
    left: 0px;
    width: 10px;
    height: 1400px;
  }
}
```
