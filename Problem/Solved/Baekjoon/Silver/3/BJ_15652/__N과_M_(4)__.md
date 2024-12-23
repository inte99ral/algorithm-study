# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 15652：N과 M (4)](https://www.acmicpc.net/problem/15652)

<div align=center>

| 시간 제한 | 메모리 제한 |
| :-------: | :---------: |
|   1 초    |   512 MB    |

</div>

## 문제

&nbsp; 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
- 고른 수열은 비내림차순이어야 한다. 길이가 K 인 수열 A가 A<sub>1</sub>
  ≤ A<sub>2</sub>
  ≤ ... ≤ A<sub>k-1</sub> ≤ A<sub>k</sub>를 만족하면, 비내림차순이라고 한다.

## 입력

&nbsp; 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

## 출력

&nbsp; 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

&nbsp; 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

## 예제

<center>
<table>
<tr>
<th align="center">예제 입력 1</th>
<th align="center">예제 출력 1</th>
</tr>
<tr>
<td valign="top">

```txt
3 1
```

</td>
<td valign="top">

```txt
1
2
3
```

</td>
</tr>
<tr>
<th align="center">예제 입력 2</th>
<th align="center">예제 출력 2</th>
</tr>
<tr>
<td valign="top">

```txt
4 2
```

</td>
<td valign="top">

```txt
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4
```

</td>
</tr>
<tr>
<th align="center">예제 입력 3</th>
<th align="center">예제 출력 3</th>
</tr>
<tr>
<td valign="top">

```txt
3 3
```

</td>
<td valign="top">

```txt
1 1 1
1 1 2
1 1 3
1 2 2
1 2 3
1 3 3
2 2 2
2 2 3
2 3 3
3 3 3
```

</td>
</tr>
</table>
</center>

## 출처

- 문제를 만든 사람: baekjoon

## 알고리즘 분류

- 백트래킹
