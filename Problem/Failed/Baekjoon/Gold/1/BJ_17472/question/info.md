# [다리 만들기 2](https://www.acmicpc.net/problem/17472)

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

<style>
  table * {text-align: center;} td {max-width: 20vw; border: solid 1px}
</style>
<table>
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

<style>
  table * {text-align: center;} td {max-width: 20vw; border: solid 1px}
</style>
<table>
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

&nbsp; 다음은 올바르지 않은 3가지 방법이다
&nbsp; 다음은 올바르지 않은 3가지 방법이다

<br />

## 입력

<br />

&nbsp; 첫째 줄에 N, M, L이 입력으로 들어온다. N은 3보다 크거나 같고, 50보다 작거나 같은 자연수이고, M은 50보다 작거나 같은 자연수이다. L은 N-1보다 작거나 같은 자연수이다.

<br />

## 출력

<br />

&nbsp; 첫째 줄에 공을 몇 번 던지는지 횟수를 출력한다.

<br />
<center>
<style>th {width: 30vw; text-align: center;} td {padding: 1em;}</>
<table><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td>

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

## 힌트

<br />

&nbsp; 예제 1의 경우 일단 1번이 공을 잡는다. 1번은 공을 한 번 잡았기 때문에, 공을 3번에게 던진다. 3번은 공을 한 번 잡았기 때문에, 공을 5번에게 던진다. 5번은 2번에게 던지고, 2번은 4번에게 던진다. 4번은 1번에게 던진다. 1번은 이제 공을 두 번 잡았기 때문에, 공을 4번에게 던진다. 4번은 2번에게 던지고, 2번은 5번에게 던지고, 5번은 3번에게 던지고, 마지막으로 3번은 1번에게 던진다. 1번은 이제 공을 세 번 잡았기 때문에, 게임은 끝난다.

<br />

## 출처

<br />

- 문제를 번역한 사람: baekjoon
- 문제의 오타를 찾은 사람: chatterboy, chsun0303, dtc03012, hello70825
- 어색한 표현을 찾은 사람: djm03178
- 문제를 다시 작성한 사람: jh05013

<br />

## 알고리즘 분류

<br />

- 구현
- 시뮬레이션
