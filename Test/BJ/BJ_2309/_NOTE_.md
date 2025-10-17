# <img alt="tier" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> [『문제코드』](https://www.naver.com/)：『문제제목』：오답노트

## 힌트

-   ~ ~제발 종료조건 설계를 잊지 말자~~

## 오답

### C++：2025-10-07：자괴감드는 실수

-   |  메모리  | 시간 | 코드 길이 |
    | :------: | :--: | :-------: |
    | 오답처리 |  -   |   540 B   |

-   진심으로 뭘 실수 했는지 한참 고민했습니다.

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "rt", stdin);
    int sum = 0;
    vector<int> v(9);
    for (int i = 0; i < 9; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sum -= 100;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (v[i] + v[j] == sum) {
                v[i] = v[j] = -1;
            }
        }
    }

    sort(v.begin(), v.end());

    for (int i = 2; i < 9; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}
```

## 정답

### C++：2025-10-07：제발 탈출조건

-   | 메모리  | 시간 | 코드 길이 |
    | :-----: | :--: | :-------: |
    | 2024 KB | 0 ms |   626 B   |

-   오답을 낸 것도 그렇고 이유를 못찾고 고민한 부분에서 자괴감이 들었다.
-   예를 들어, 25 25 25 25 10 10 10 10 10 같은 경우, 1,2,3,4 번 난쟁이 누구를 골라도 두 명의 합은 50 이다.
-   루프의 탈출 조건을 정확히 잡은 밑의 코드는 1,2번이 총합 150 - 100 = 50 에 해당하는 두 명임을 파악하지만, 오답인 코드의 경우 멈추지 않고 3번과 4번의 값도 -1 로 만들어버린다.

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "rt", stdin);
    int sum = 0;
    bool isFound = false;
    vector<int> v(9);
    for (int i = 0; i < 9; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sum -= 100;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (v[i] + v[j] == sum) {
                v[i] = v[j] = -1;
                isFound = true;
                break;
            }
        }
        if(isFound) break;
    }

    sort(v.begin(), v.end());

    for (int i = 2; i < 9; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}
```
