# [다리 만들기 2](https://www.acmicpc.net/problem/17472)

<style>
  .example * {text-align: center;}
  .example td {width: 30vw; border: solid 1px lightgray}
  .output td {width: 30vw; padding: 1em}
</style>

<br />
<center>

| 시간 제한 | 메모리 제한 |
| :-------: | :---------: |
|   1 초    |   512 MB    |

</center>
<br />

## 문제

<br />

&nbsp; 섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 한다. 이 나라의 지도는 N×M 크기의 이차원 격자로 나타낼 수 있고, 격자의 각 칸은 땅이거나 바다이다.

&nbsp; 섬은 연결된 땅이 상하좌우로 붙어있는 덩어리를 말하고, 아래 그림은 네 개의 섬으로 이루어진 나라이다. 색칠되어있는 칸은 땅이다.

<br />
<center>

<img src="./asset/1.avif" style="width:20vw; aspect-ratio: 1 / 1"/>

</center>
<br />

&nbsp; 다리는 바다에만 건설할 수 있고, 다리의 길이는 다리가 격자에서 차지하는 칸의 수이다. 다리를 연결해서 모든 섬을 연결하려고 한다. 섬 A에서 다리를 통해 섬 B로 갈 수 있을 때, 섬 A와 B를 연결되었다고 한다. 다리의 양 끝은 섬과 인접한 바다 위에 있어야 하고, 한 다리의 방향이 중간에 바뀌면 안된다. 또, 다리의 길이는 2 이상이어야 한다.

&nbsp; 다리의 방향이 중간에 바뀌면 안되기 때문에, 다리의 방향은 가로 또는 세로가 될 수 밖에 없다. 방향이 가로인 다리는 다리의 양 끝이 가로 방향으로 섬과 인접해야 하고, 방향이 세로인 다리는 다리의 양 끝이 세로 방향으로 섬과 인접해야 한다.

&nbsp; 섬 A와 B를 연결하는 다리가 중간에 섬 C와 인접한 바다를 지나가는 경우에 섬 C는 A, B와 연결되어있는 것이 아니다.

&nbsp; 아래 그림은 섬을 모두 연결하는 올바른 2가지 방법이고, 다리는 회색으로 색칠되어 있다. 섬은 정수, 다리는 알파벳 대문자로 구분했다.

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

&nbsp; 다음은 올바르지 않은 3가지 방법이다

<br />
<center>

<table class="example">
  <tr>
    <td><img src="./asset/4.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
    <td><img src="./asset/5.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
    <td><img src="./asset/6.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
  </tr>
  <tr>
    <td>C의 방향이 중간에 바뀌었다</td>
    <td>D의 길이가 1이다.</td>
    <td>가로 다리인 A가 1과 가로로 연결되어 있지 않다.</td>
  </tr>
</table>

</center>
<br />

&nbsp; 다리가 교차하는 경우가 있을 수도 있다. 교차하는 다리의 길이를 계산할 때는 각 칸이 각 다리의 길이에 모두 포함되어야 한다. 아래는 다리가 교차하는 경우와 기타 다른 경우에 대한 2가지 예시이다.

<br />
<center>

<table class="example">
  <tr>
    <td><img src="./asset/7.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
    <td><img src="./asset/8.avif" style="width:20vw; aspect-ratio: 1 / 1"/></td>
  </tr>
  <tr>
    <td>A의 길이는 4이고, B의 길이도 4이다.</td>
    <td>
      다리 A: 2와 3을 연결 (길이 2)<br />
      다리 B: 3과 4를 연결 (길이 3)<br />
      다리 C: 2와 5를 연결 (길이 5)<br />
      다리 D: 1과 2를 연결 (길이 2)
    </td>
  </tr>
  <tr>
    <td>총 다리의 총 길이: 4 + 4 + 2 = 10</td>
    <td>총 길이: 12</td>
  </tr>
</table>

</center>
<br />

&nbsp; 나라의 정보가 주어졌을 때, 모든 섬을 연결하는 다리 길이의 최솟값을 구해보자.

<br />

## 입력

<br />

&nbsp; 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. 둘째 줄부터 N개의 줄에 지도의 정보가 주어진다. 각 줄은 M개의 수로 이루어져 있으며, 수는 0 또는 1이다. 0은 바다, 1은 땅을 의미한다.

<br />

## 출력

<br />

&nbsp; 모든 섬을 연결하는 다리 길이의 최솟값을 출력한다. 모든 섬을 연결하는 것이 불가능하면 -1을 출력한다.

<br />

## 제한

<br />

- 1 ≤ N, M ≤ 10
- 3 ≤ N × M ≤ 100
- 2 ≤ 섬의 개수 ≤ 6

<br />
<center>
<table class="output"><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td>

```
7 8
0 0 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 0 0
1 1 0 0 0 1 1 0
0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
```

</td><td>

```
9







```

</td></tr></table>
<table class="output"><tr><th>예제 입력 2</th><th>예제 출력 2</th></tr><tr><td>

```
7 8
0 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
```

</td><td>

```
10







```

</td></tr></table>
<table class="output"><tr><th>예제 입력 3</th><th>예제 출력 3</th></tr><tr><td>

```
7 8
1 0 0 1 1 1 0 0
0 0 1 0 0 0 1 1
0 0 1 0 0 0 1 1
0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0
```

</td><td>

```
9







```

</td></tr></table>
<table class="output"><tr><th>예제 입력 4</th><th>예제 출력 4</th></tr><tr><td>

```
7 7
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
0 0 0 0 0 0 0
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
```

</td><td>

```
-1







```

</td></tr></table>
</center>
<br />

## 출처

<br />

- 문제를 만든 사람: baekjoon
- 데이터를 추가한 사람: djm03178

<br />

## 알고리즘 분류

<br />

- 구현
- 그래프 이론
- 브루트포스 알고리즘
- 그래프 탐색
- 너비 우선 탐색
- 깊이 우선 탐색
- 최소 스패닝 트리
