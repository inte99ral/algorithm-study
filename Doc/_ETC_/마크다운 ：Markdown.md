# 마크다운：Markdown

## 기본 문법

### 제목 및 단락：Header

`h1 ~ h6` 까지 # 로 표현 가능합니다.

```md
# h1

## h2

### h3

#### h4

##### h5

###### h6
```

### 인용

- 블록 인용：`>` 사용

  > 첫번째 블록
  >
  > > 두번째 블록
  > >
  > > > 세번째 블록

### 코드 블럭

- 인라인 코드： \` 사용

  - `[](int x, int y) -> int { return x + y; };`

- 펜스드 코드 블럭：\`\`\` 사용 (언어 지정 가능)

  ```cpp
  [](int x, int y) -> int { return x + y; };
  ```

- 들여쓰기 코드 블럭: 4개의 공백 또는 1개의 탭으로 들여쓰기 (markdownlint 나 prettier 설정에 따라 불가능 할 수 있습니다.)

  ```txt
  코드 블럭을 시작합니다

    들여쓰기 행이 끝날 때까지 코드 블럭입니다.

  코드 블럭을 끝냅니다.
  ```

### 정렬：Align

<div align=left>
『LEFT_TEXT』
</div>

<center>
『CENTER_TEXT_0』
</center>

<div align=center>
『CENTER_TEXT_1』
</div>

<div align=right>
『RIGHT_TEXT』
</div>

### 확장/축소：Accordion

<details>
  <summary>

```cpp
int main() {
  ... 클릭하여 확장/축소 ...
```

  </summary>
  
```cpp
  cout << "Hello, World!" << endl;
```
</details>

```cpp
  return 0;
}
```

### 수평선

- 다음의 방법으로 수평선을 그릴 수 있습니다.
  - `***`
  - `* * *`
  - `*****`
  - `- - -`
  - `-----`
  - `<hr />`

### 공백：No Breaking Space

- 다음의 방법으로 마크다운 문법 Lint 나 formatter에 무관하게 유동적인 공백 사용이 가능합니다.
  - `&nbsp` (HTML Entities 의 공백)

### 줄바꿈：Breaking Line

- 다음의 방법으로 강제개행이 가능합니다.
  - ENTER + ENTER
  - 공백 두 번 + ENTER
  - `<br />`

<center>

개행1  
개행1

개행2

개행2

개행3<br />개행3

</center>

### 표 만들기：Table

#### Table > Markdown Native

&nbsp; -(하이픈) 기호를 3개 이상 사용하여 헤더 셀을 구분할 수 있습니다.

&nbsp; :(콜론) 기호로 내용을 정렬할 수 있습니다.

| 첫번째(왼쪽정렬) | 두번째(가운데정렬) | 세번째(오른쪽정렬) |
| ---------------- | :----------------: | -----------------: |
| 왼쪽정렬         |     가운데정렬     |         오른쪽정렬 |

#### Table > HTML Tag

&nbsp; Table HTML 태그를 이용해서 섬세하게 테이블을 만드는 것 또한 가능합니다.

- <table>
  <tr>
    <th align=left>코드블럭</th>
  </tr>
  <tr>
    <td align=left>

  ```cpp
  #include <bits/stdc++.h>

  int main() {
    return 0;
  }
  ```

    </td>
  </tr>
  </table>

<br />

- <table>
  <tr>
    <th align=left>첫번째(왼쪽정렬)</th>
    <td align=left>왼쪽정렬&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <th align=center>두번째(가운데정렬)</th>
    <td align=center>가운데정렬</td>
  </tr>
  <tr>
    <th align=right>세번째(오른쪽정렬)</th>
    <td align=right>오른쪽정렬</td>
  </tr>
  </table>

<br />

- <table>
  <tr>
    <th valign=top>첫번째(상단정렬)</th>
    <th valign=middle>두번째(중단정렬)</th>
    <th valign=bottom>세번째(하단정렬)</th>
  </tr>
  <tr>
    <td valign=top>상단정렬<br /><br /><br /></td>
    <td valign=middle>중단정렬</td>
    <td valign=bottom>하단정렬</td>
  </tr>
  </table>

### 텍스트 서식

- 기울임
  - _이탤릭체_：`_이탤릭체_`
- 굵게
  - **볼드체**：`**볼드체**`
- 취소선
  - ~~취소선~~：`~~취소선~~`
  - <del>취소선</del>：`<del>취소선</del>`
- 밑줄
  - <u>밑줄</u>：`<u>밑줄</u>`
- 굵게 + 기울임
  - **_볼드+이탤릭_**：`**_볼드+이탤릭_**`
- 굵게 + 취소선
  - **~~볼드+취소선~~**：`**~~볼드+취소선~~**`
- 굵게 + 기울임 + 취소선
  - **_~~볼드+이탤릭+취소선~~_**：`**_~~볼드+이탤릭+취소선~~_**`

### 목록

- 순서 없는 목록：\*, -, + 을 앞에 적습니다.

  - 목록1
  - 목록2

- 순서 있는 목록：숫자와 점(.) 을 앞에 적습니다.
  1. 목록1
  2. 목록2
- 체크리스트：- [ ] 또는 - [x] 사용
  - [ ] 목록1
  - [ ] 목록2

### 참조

#### 참조 > Markdown Native

- 링크：`[『LINK_TEXT』](『URL』)`

<center>

[이미지 링크](./.asset/마크다운：Markdown/0.png)

</center>

- 이미지：`![『ALT_TEXT』](『URL』)`

<center>

![대체 텍스트](./.asset/마크다운：Markdown/0.png)

</center>

#### 참조 > HTML Tag

- 링크：`<a href="『URL』">『LINK_TEXT』</a>`

<center>

<a href="./.asset/마크다운：Markdown/0.png">이미지 링크</a>

</center>

- 이미지：`<img src="『URL』" alt="『ALT_TEXT』" width="『WIDTH_SIZE』" height="『HEIGHT_SIZE』" />`

<center>

<img src="./.asset/마크다운：Markdown/0.png" alt="0" width="200" height="200" />

</center>
