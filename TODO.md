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

## WARN

1. <b>패턴</b>：손 풀이로 수학적 처리과정을 뇌로 한번 거쳐보고 패턴 파악해보기
2. <b>변수</b>：값이 바뀐 걸 인지하기.
3. <b>포인터</b>：첫 입력시, 초기화를 0으로 했으면, null 값이 아니라 인덱스 0을 가르킨다.
4. <b>큐</b>：스택이나 우선순위 큐에서 pop 이나 push 행동을 취하면 당연히 순서가 바뀐다.
5. <b>조건</b>：if 문에서 배제한 케이스에 대하여 반례 체크를 해봐야 한다.
6. <b>범위</b>：int 의 범위는 4byte 2^32. long long 또한 8byte 2^64 가 한계이다. 아무리 long 이여도 int의 세제곱을 커버하진 못한다.

<br />

## DONE:

| 풀이 일자  |                                 문제 코드                                  |  문제명   |   난이도   | 해시태그    |
| :--------: | :------------------------------------------------------------------------: | :-------: | :--------: | :---------- |
| 2024-12-20 | [BJ 15649](<./Problem/Solved/Baekjoon/Silver/3/BJ_15649/__N과_M_(1)__.md>) | N과 M (1) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-23 | [BJ 15650](<./Problem/Solved/Baekjoon/Silver/3/BJ_15650/__N과_M_(2)__.md>) | N과 M (2) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-23 | [BJ 15651](<./Problem/Solved/Baekjoon/Silver/3/BJ_15651/__N과_M_(3)__.md>) | N과 M (3) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-23 | [BJ 15652](<./Problem/Solved/Baekjoon/Silver/3/BJ_15652/__N과_M_(4)__.md>) | N과 M (4) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-24 | [BJ 15654](<./Problem/Solved/Baekjoon/Silver/3/BJ_15654/__N과_M_(5)__.md>) | N과 M (5) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-24 | [BJ 15655](<./Problem/Solved/Baekjoon/Silver/3/BJ_15655/__N과_M_(6)__.md>) | N과 M (6) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-24 | [BJ 15656](<./Problem/Solved/Baekjoon/Silver/3/BJ_15656/__N과_M_(7)__.md>) | N과 M (7) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-25 | [BJ 15657](<./Problem/Solved/Baekjoon/Silver/3/BJ_15657/__N과_M_(8)__.md>) | N과 M (8) | `#SilverⅢ` | `#백트래킹` |
| 2024-12-26 | [BJ 15663](<./Problem/Solved/Baekjoon/Silver/2/BJ_15663/__N과_M_(9)__.md>) | N과 M (9) | `#SilverⅡ` | `#백트래킹` |

|2024-12-27
|[BJ 15664](<./Problem/Solved/Baekjoon/Silver/2/BJ_15664/__N과_M_(10)__.md>)
|N과 M (10)
|`#SilverⅡ`
|`#백트래킹`

|2024-12-27
|[BJ 15665](<./Problem/Solved/Baekjoon/Silver/2/BJ_15665/__N과_M_(11)__.md>)
|N과 M (11)
|`#SilverⅡ`
|`#백트래킹`

---

- [x] 2024.01.02 | [BJ 4963 섬의 개수 #Silver/2 #그래프이론 #그래프탐색 #너비우선탐색 #깊이우선탐색](Problem\Solved\Baekjoon\Silver\2\BJ_4963\question\info.md)
- [x] 2024.01.17 | [BJ 1992 쿼드트리 #Silver/1 #분할정복 #재귀](Problem\Solved\Baekjoon\Silver\1\BJ_1992\question\info.md)
- [x] 2024.03.22 | [BJ 15686 치킨 배달 #Gold/5 #그래프탐색](Problem\Failed\Baekjoon\Gold\5\BJ_15686\question\info.md)
- [x] 2024-03-22 | [BJ 7576](Problem\Failed\Baekjoon\Gold\5\BJ_7576\question\info.md) 토마토 `#GoldⅤ` `#그래프` `#그래프 탐색` `#너비 우선 탐색`
- [x] 2024-04-04 | [BJ 17135](Problem\Solved\Baekjoon\Gold\3\BJ_17135\question\info.md) 캐슬 디펜스 `#GoldⅢ` `#구현` `#그래프` `#브루트포스` `#너비우선탐색`
- [x] 2024-04-23 | [BJ 2252](Problem\Solved\Baekjoon\Gold\3\BJ_2252\question\info.md) 줄 세우기 `#GoldⅢ` `#그래프` `#위상 정렬` `#방향 비순환 그래프`
- [x] 2024-06-16 | [BJ 17472](Problem\Solved\Baekjoon\Gold\1\BJ_17472\question\info.md) 다리 만들기 2 `#GoldⅠ` `#구현` `#그래프` `#최소 스패닝 트리`
- [x] 2024-06-16 | [PG 42576](Problem\Solved\Programmers\Level_1\PG_42576\question\info.md) 완주하지 못한 선수 `#Level 1` `#해시`
- [x] 2024-07-04 | [PG 42579](Problem\Solved\Programmers\Level_3\PG_42579\question\info.md) 베스트앨범 `#Level 3` `#해시`
- [x] 2024-07-14 | [PG 42578](Problem\Solved\Programmers\Level_2\PG_42578\question\info.md) 의상 `#Level 2` `#해시`
- [x] 2024-07-22：[PG_17677](Problem\Solved\Programmers\Level_2\PG_17677\question\info.md) 뉴스 클러스터링 `#Level 2` `#2018_KAKAO_BLIND_RECRUITMENT 1차`
- [x] 2024-07-31：[PG_17679](Problem\Solved\Programmers\Level_2\PG_17679\question\info.md) 프렌즈4블록 `#Level 2` `#2018_KAKAO_BLIND_RECRUITMENT 1차`
- [x] 2024-07-24：[PG_17680](Problem\Solved\Programmers\Level_2\PG_17680\question\info.md) 캐시 `#Level 2` `#2018_KAKAO_BLIND_RECRUITMENT 1차`
- [x] 2024-08-19：[PG_17676](Problem\Solved\Programmers\Level_3\PG_17676\question\info.md) 추석 트래픽 `#Level 3` `#2018_KAKAO_BLIND_RECRUITMENT 1차`
- [x] 2024-10-31：[BJ_1000](Problem\Solved\Baekjoon\Bronze\5\BJ_1000/._A+B.md) A+B `#BronzeⅤ` `#수학` `#구현`
- [x] 2024-10-31：[BJ_1244](Problem\Solved\Baekjoon\Silver\4\BJ_1244/._스위치_켜고_끄기.md) 스위치 켜고 끄기 `#SilverⅣ` `#구현`
- [x] 2024-10-31：[BJ_1592](Problem\Solved\Baekjoon\Bronze\2\BJ_1592/._영식이와_친구들.md) 영식이와 친구들 `#BronzeⅡ` `#구현`
- [x] 2024-10-31：[BJ_2292](Problem\Solved\Baekjoon\Bronze\2\BJ_2292/._벌집.md) 벌집 `#BronzeⅡ` `#수학`
- [x] 2024-10-31：[BJ_2477](Problem\Solved\Baekjoon\Silver\2\BJ_2477/._참외밭.md) 참외밭 `#SilverⅡ` `#수학` `#구현` `#기하학`
- [x] 2024-11-07：[PG_1845](Problem\Solved\Programmers\Level_1\PG_1845/__폰켓몬.md) 폰켓몬 `#Level 1` `#해시`
- [x] 2024-11-07：[PG_181188](Problem\Solved\Programmers\Level_2\PG_181188/__요격_시스템.md) 요격 시스템 `#Level 2`
- [x] 2024-11-07：[BJ_2527](Problem\Solved\Baekjoon\Silver\1\BJ_2527/__직사각형.md) 직사각형 `#SilverⅠ` `#수학` `#기하학` `#많은조건분기`
- [x] 2024-11-22：[BJ_2941](Problem\Solved\Baekjoon\Silver\5\BJ_2941/__크로아티아_알파벳__.md) 크로아티아 알파벳 `#SilverⅤ` `#구현` `#문자열`
- [x] 2024-11-22：[BJ_2563](Problem\Solved\Baekjoon\Silver\4\BJ_2563/__색종이__.md) 색종이 `#SilverⅣ` `#구현`
- [x] 2024-11-22：[BJ_2567](Problem\Solved\Baekjoon\Silver\4\BJ_2567/__색종이_2__.md) 색종이 2 `#SilverⅣ` `#구현`
- [x] 2024-11-22：[BJ_2798](Problem\Solved\Baekjoon\Bronze\2\BJ_2798/__블랙잭__.md) 블랙잭 `#BronzeⅡ` `#브루트포스 알고리즘`
- [x] 2024-12-20：[BJ 2810](Problem\Solved\Baekjoon\Bronze\1\BJ_2810/__컵홀더__.md) 컵홀더 `#BronzeⅠ` `#구현` `#문자열` `#그리디`
- [x] 2024-12-20：[BJ 2851](Problem\Solved\Baekjoon\Bronze\1\BJ_2851/__슈퍼_마리오__.md) 슈퍼마리오 `#BronzeⅠ` `#구현` `#브루트포스` `#누적합`
- [x] 2024-12-20：[BJ 2164](Problem\Solved\Baekjoon\Silver\4\BJ_2164/__카드2__.md) 카드2 `#SilverⅣ` `#자료구조` `#큐`
- [x] 2024-12-20：[BJ 15649](<Problem\Solved\Baekjoon\Silver\3\BJ_15649/__N과_M_(1)__.md>) N과 M (1) `#SilverⅢ` `#백트래킹`

<br />

## FIXME:

- [x] 2024-10-18：[BJ 5397](Problem\Failed\Baekjoon\Silver\2\BJ_5397\question\info.md) 키로거 `#SilverⅡ` `#자료구조` `#스택` `#연결 리스트`
- [x] 2024-10-25 | [BJ 1629](Problem\Unsolved\Baekjoon\Silver\1\BJ_1629\question\info.md) 곱셈 `#SilverⅠ`
- [ ] 2024-06-16 | [BJ 11726](Problem\Solved\Baekjoon\Gold\1\BJ_17472\question\info.md) 2×n 타일링 `#SilverⅢ`
- [ ] 2024-xx-xx：[SWEA 20671](Problem\Unsolved\SWEA\D5\SWEA_20671\question\info.md) 숫자 카드 `#D5`

<br />

## TODO:

- [x] 2024-10-26：[BJ 3040](Problem\Failed\Baekjoon\Bronze\2\BJ_3040\info\question.md) 백설공주와일곱난쟁이 `#BronzeⅡ` `#브루트포스`
- [ ] BJ 2999 비밀이메일
- [ ] BJ 3985 롤케이크
- [ ] BJ 3052 나머지
- [ ] BJ 8320 직사각형을만드는방법
- [ ] PG 181186 아방가르드 타일링 `#Level_3#연습문제`
- [ ] PG 42627 디스크 컨트롤러
- [ ] BJ 8958_OX퀴즈
- [ ] BJ 10163\_색종이
- [ ] BJ 11399_ATM퀴즈
- [ ] BJ 13300\_방배정
- [ ] BJ 14696\_딱지놀이
- [ ] BJ 17413\_단어뒤집기2
- [ ] JO 1037 오류교정
- [ ] JO 1205 조커
- [ ] JO 1733 오목
- [ ] 1220.Magnetic
- [ ] 1493.수의 새로운 연산
- [ ] 1859.백만 장자 프로젝트
- [ ] 1940.가랏! RC카
- [ ] 1954.달팽이 숫자
- [ ] 1979 어디에 단어가 들어갈 수 있을까
- [ ] 1983.조교의 성적 매기기
- [ ] 1984 중간 평균값 구하기
- [ ] 2005 파스칼의 삼각형
- [ ] 2007 패턴 마디의 길이
- [ ] 3499.퍼펙트 셔플
- [ ] 4047.영준이의 카드 카운팅
- [ ] 4789.성공적인 공연기획
- [ ] 4698.테네스의 특별한 소수
- [ ] 5356.의석이세로로말해요
- [ ] 5432.쇠막대기 자르기
- [ ] 6485.삼성시의 버스 노선
- [ ] 7964.부먹왕국의 차원관문
- [ ] 7087.문제 제목 붙이기
- [ ] 7236.저수지의 물의 총 깊이 구하기
- [ ] 7272.안경이 없어

<br />
