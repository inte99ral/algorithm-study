# TODO

## Coding Convention

```txt
『PROBLEM_CODE』
	├─ __『PROBLEM_NAME』__.md (문제내용)
	├─ _NOTES_.md (오답노트)
	├─ _INPUT_.txt (입력내용)
	│
	└─ Main.{cpp | java | js ...} (문제 풀이 코드)
```

<br />

## WARN

1. <b>패턴</b>：손 풀이로 수학적 처리과정을 뇌로 한번 거쳐보고 패턴 파악해보기
2. <b>변수</b>：값이 바뀐 걸 인지하기.
3. <b>포인터</b>：첫 입력시, 초기화를 0으로 했으면, null 값이 아니라 인덱스 0을 가르킨다.
4. <b>큐</b>：스택이나 우선순위 큐에서 pop 이나 push 행동을 취하면 당연히 순서가 바뀐다.
5. <b>조건</b>：if 문에서 배제한 케이스에 대하여 반례 체크를 해봐야 한다.
6. <b>범위</b>：int 의 범위는 4byte 2^32. long long 또한 8byte 2^64 가 한계이다. 아무리 long 이여도 int의 세제곱을 커버하진 못한다.
7. <b>컨테이너</b>：변화가 잦은 알고리즘에는 리스트를, 또는 변화가 없는 알고리즘 등에는 벡터를 적용하는 경우처럼, 상황에 적합한 컨테이너를 사용하기.

<br />

## DONE:

| 풀이 일자  | 문제 코드                                                                            | 문제명                  | 난이도     | 해시태그                          |
| :--------- | :----------------------------------------------------------------------------------- | :---------------------- | :--------- | :-------------------------------- |
| 2024-12-20 | [BJ 15649](<./Problem/Solved/Baekjoon/Silver/3/BJ_15649/__N과_M_(1)__.md>)           | N과 M (1)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-23 | [BJ 15650](<./Problem/Solved/Baekjoon/Silver/3/BJ_15650/__N과_M_(2)__.md>)           | N과 M (2)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-23 | [BJ 15651](<./Problem/Solved/Baekjoon/Silver/3/BJ_15651/__N과_M_(3)__.md>)           | N과 M (3)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-23 | [BJ 15652](<./Problem/Solved/Baekjoon/Silver/3/BJ_15652/__N과_M_(4)__.md>)           | N과 M (4)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-24 | [BJ 15654](<./Problem/Solved/Baekjoon/Silver/3/BJ_15654/__N과_M_(5)__.md>)           | N과 M (5)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-24 | [BJ 15655](<./Problem/Solved/Baekjoon/Silver/3/BJ_15655/__N과_M_(6)__.md>)           | N과 M (6)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-24 | [BJ 15656](<./Problem/Solved/Baekjoon/Silver/3/BJ_15656/__N과_M_(7)__.md>)           | N과 M (7)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-25 | [BJ 15657](<./Problem/Solved/Baekjoon/Silver/3/BJ_15657/__N과_M_(8)__.md>)           | N과 M (8)               | `#SilverⅢ` | `#백트래킹`                       |
| 2024-12-26 | [BJ 15663](<./Problem/Solved/Baekjoon/Silver/2/BJ_15663/__N과_M_(9)__.md>)           | N과 M (9)               | `#SilverⅡ` | `#백트래킹`                       |
| 2024-12-27 | [BJ 15664](<./Problem/Solved/Baekjoon/Silver/2/BJ_15664/__N과_M_(10)__.md>)          | N과 M (10)              | `#SilverⅡ` | `#백트래킹`                       |
| 2024-12-27 | [BJ 15665](<./Problem/Solved/Baekjoon/Silver/2/BJ_15665/__N과_M_(11)__.md>)          | N과 M (11)              | `#SilverⅡ` | `#백트래킹`                       |
| 2024-12-29 | [BJ 15666](<./Problem/Solved/Baekjoon/Silver/2/BJ_15666/__M과_N_(12)__.md>)          | N과 M (12)              | `#SilverⅡ` | `#백트래킹`                       |
| 2025-01-09 | [BJ 4963](./Problem/Solved/Baekjoon/Silver/2/BJ_4963/__섬의_개수__.md)               | 섬의 개수               | `#SilverⅡ` | `#그래프이론` `#그래프탐색`       |
| 2025-01-09 | [BJ 1992](./Problem/Solved/Baekjoon/Silver/1/BJ_1992/__쿼드트리__.md)                | 쿼드트리                | `#SilverⅠ` | `#분할 정복` `#재귀`              |
| 2025-01-13 | [BJ 15686](./Problem/Solved/Baekjoon/Gold/5/BJ_15686/__치킨_배달__.md)               | 치킨 배달               | `#GoldⅤ`   | `#그래프탐색`                     |
| 2025-03-07 | [BJ 3040](./Problem/Solved/Baekjoon/Bronze/2/BJ_3040/__백설_공주와_일곱_난쟁이__.md) | 백설 공주와 일곱 난쟁이 | `#BronzeⅡ` | `#브루트포스`                     |
| 2024-05-04 | [BJ 2999](./Problem/Solved/Baekjoon/Bronze/1/BJ_2999/__비밀_이메일__.md)             | 비밀이메일              | `#D5`      | `#구현` `#문자열`                 |
| 2025-09-08 | [BJ 3985](./Problem/Solved/Baekjoon/Bronze/1/BJ_3985/__롤_케이크__.md)               | 롤 케이크               | `#BronzeⅠ` | `#구현` `#시뮬레이션`             |
| 2025-09-09 | [BJ 5397](./Problem/Solved/Baekjoon/Silver/2/BJ_5397/__키로거__.md)                  | 키로거                  | `#SilverⅡ` | `#자료구조` `#스택` `#연결리스트` |

<br />

## FIXME:

| 풀이 일자 | 문제 코드 | 문제명 | 난이도 | 해시태그 |
| :-------- | :-------- | :----- | :----- | :------- |

- 대기
  | 2025-03-16
  | [BJ 1629](./Problem/Failed/Baekjoon/Silver/1/BJ_1629/__곱셈__.md)
  | 곱셈
  | `#SilverⅠ`
  | `#?`
