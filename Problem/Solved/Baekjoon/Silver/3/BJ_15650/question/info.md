# [N과 M (2)](https://www.acmicpc.net/problem/15650)

<center>

| 시간 제한 | 메모리 제한 |
| :-------: | :---------: |
|   1 초    |   512 MB    |

</center>
<br />

## 문제

<br />

&nbsp; 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

&nbsp; &nbsp; ● 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

&nbsp; &nbsp; ● 고른 수열은 오름차순이어야 한다.

<br />

## 입력

<br />

&nbsp; 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

<br />

## 출력

<br />

&nbsp; 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

&nbsp; 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

<br />
<center>
<style>th {width: 30vw; text-align: center;} td {padding: 1em;}</style>
<table><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td>

```
3 1
```

</td><td>

```
1
2
3
```

</td></tr></table>
<table><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td>

```
4 2
```

</td><td>

```
1 2
1 3
1 4
2 3
2 4
3 4
```

</td></tr></table>
<table><tr><th>예제 입력 1</th><th>예제 출력 1</th></tr><tr><td>

```
4 4
```

</td><td>

```
1 2 3 4
```

</td></tr></table>
</center>
<br />

## 출처

<br />

- 문제를 만든 사람: baekjoon

<br />

## 알고리즘 분류

<br />

- 백트래킹
