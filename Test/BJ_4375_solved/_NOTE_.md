# <img alt="『티어』" src="https://d2gd6pc034wcta.cloudfront.net/tier/『티어』.svg" width="16" /> [BJ 『문제코드』](https://www.acmicpc.net/problem/『문제코드』)：『문제제목』：오답노트

## 힌트

-   ~~항상 직접 손풀이를 먼저해보자. 나머지의 모듈로 등식은 익숙하지 않겠으나 직관적인 느낌은 알 수 있음~~
-   ~~십으로 나눈 나머지인 일의 자리 수만 생각해보기.~~ 
-   ~~주어진 수 n 의 배수 a 와 b 에 대하여 `an ≡ bn (mod 10)` 성립하는 조건파악. 이는 곧 `(a - b)n ≡ 0 (mod 10)` 라는 소리임~~
-   ~~다시말해, n 과 10의 공약수가 없다면 (a-b) 가 10의 배수의 차이가 나지 않는 다면 (mod 10) 즉 일의 자리 수는 전부 다름을 알 수 있음.~~
-   ~~10을 주기로 반복되기 때문에 1배 ~ 9배의 결과만 가지고 계산하면 됨~~

## 오답

### C++：2025-10-30：힘으로 해결 시도

-   | 메모리 |   시간   | 코드 길이 |
    | :----: | :------: | :-------: |
    |   -    | 시간초과 |   384 B   |

-   무지성 1 ... 1111 나눠보기 시도 -> 타임아웃

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    // --------------------------------

    freopen("_INPUT_.txt", "rt", stdin); // <-- LOCAL INPUT

    // --------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long temp;
    while(cin >> temp) {
        int cnt = 1;
        long long one = 1;
        while (one % temp != 0) {
            one = (one * 10) + 1;
            cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}
```

## 정답

### 『LANGUAGE_TYPE_02』：xxxx-xx-xx：『ANNOTATION_COMMENT』

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   843 B   |

-   과거 오답 풀이보니까 어이가 없음
-   수학적인 기본 지식이 필요, 왜 2 와 5 는 성립하지 않는가에 집중하면 대충 답이 나옴. 일의 자릿수가 무엇이든 10 의 약수가 아니라면, 0이 아닌 일의 자릿수에 10이 곱해지지 않는 한 0 이 나올 일은 없음. 10이 곱해져서 일의 자릿수가 0이 되는 10배... 그 이전의 1배 부터 9배까지의 일의 자릿수는 중복될 일이 없음. 그 후 10번째 0 -> 11번째부턴 다시 1번째와 일의 자릿수가 동일해짐. 이 일의 자리 숫자의 주기성이 존재한다는 것이 핵심 아이디어임.
-   모로가도 일의 자릿수가 1만 되면 되기 때문에 합계의 일의 자릿수와 주기성을 띄는 1배부터 9배수 하나를 골라 그 수의 일의 자릿수끼리의 합이 "11" 또는 "1" 이 되도록 계속 더해나가면 됨.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin); // <================

    int n;

    while (cin >> n) {
        int cnt = 1;
        int sum = n;
        int iArr[10] = {};
        for (int i = 0; i < 9; i++) {
            iArr[sum % 10] = sum;
            sum += n;
        }

        sum = iArr[1];

        while (sum != 1) {
            if(sum % 10 != 1) {
                sum += iArr[(11 - sum % 10) % 10];
            }

            sum /= 10;
            cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}
```
