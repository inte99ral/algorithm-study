# [디스크 컨트롤러](https://school.programmers.co.kr/learn/courses/30/lessons/181188)

<style>
  .example * {text-align: center;}
  .example td {width: 20vw; border: solid 1px lightgray}
  .output td {width: 30vw; padding: 1em}
</style>

<br />

## 문제 설명

<br />

&nbsp; A 나라가 B 나라를 침공하였습니다. B 나라의 대부분의 전략 자원은 아이기스 군사 기지에 집중되어 있기 때문에 A 나라는 B 나라의 아이기스 군사 기지에 융단폭격을 가했습니다.

&nbsp; A 나라의 공격에 대항하여 아이기스 군사 기지에서는 무수히 쏟아지는 폭격 미사일들을 요격하려고 합니다. 이곳에는 백발백중을 자랑하는 요격 시스템이 있지만 운용 비용이 상당하기 때문에 미사일을 최소로 사용해서 모든 폭격 미사일을 요격하려 합니다.

&nbsp; A 나라와 B 나라가 싸우고 있는 이 세계는 2 차원 공간으로 이루어져 있습니다. A 나라가 발사한 폭격 미사일은 x 축에 평행한 직선 형태의 모양이며 개구간을 나타내는 정수 쌍 (s, e) 형태로 표현됩니다. B 나라는 특정 x 좌표에서 y 축에 수평이 되도록 미사일을 발사하며, 발사된 미사일은 해당 x 좌표에 걸쳐있는 모든 폭격 미사일을 관통하여 한 번에 요격할 수 있습니다. 단, 개구간 (s, e)로 표현되는 폭격 미사일은 s와 e에서 발사하는 요격 미사일로는 요격할 수 없습니다. 요격 미사일은 실수인 x 좌표에서도 발사할 수 있습니다.
각 폭격 미사일의 x 좌표 범위 목록 targets이 매개변수로 주어질 때, 모든 폭격 미사일을 요격하기 위해 필요한 요격 미사일 수의 최솟값을 return 하도록 solution 함수를 완성해 주세요.

&nbsp; 문제의 그림예시 `<그림 1>`

<br />
<center>

```
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
```

0은 빈 칸, 1은 집, 2는 치킨집이다.

</center>
<br />

<br />
<center>

<table class="example">
  <tr>
    <td><img src="./asset/2.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
    <td><img src="./asset/3.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
  </tr>
  <tr>
    <td>다리의 총 길이: 13</td>
    <td>다리의 총 길이: 9</td>
  </tr>
  <tr>
    <td>D는 2와 4를 연결하는 다리이고, 3과는 연결되어 있지 않다.</td>
    <td>&nbsp;</td>
  </tr>
</table>

</center>
<br />

<br />

## 제한 사항

<br />

- 1 ≤ targets의 길이 ≤ 500,000
- targets의 각 행은 [s,e] 형태입니다.
  - 이는 한 폭격 미사일의 x 좌표 범위를 나타내며, 개구간 (s, e)에서 요격해야 합니다.
  - 0 ≤ s < e ≤ 100,000,000

<br/>

## 입출력 예

<br />

<center>
<table class="output"><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td>

```
5 3 2
```

</td><td>

```
10
```

</td></tr></table>
</center>
<br />

## 입출력 예 설명

<br />
<center>
<img src="./asset/1.png" style="width:50vw; aspect-ratio: 3 / 1"/>
</center>

위 그림과 같이 최소 세 번의 요격 미사일 발사로 전부 방어할 수 있습니다.
