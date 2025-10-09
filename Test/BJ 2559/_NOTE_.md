# <img alt="s3" src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="16" /> [BJ 2559](https://www.acmicpc.net/problem/2559)：수열：오답노트

## 힌트

-   ~ ~제발 종료조건 설계를 잊지 말자~~

## 오답

### C++：2025-10-09：아차차 이슈

-   |  메모리  | 시간 | 코드 길이 |
    | :------: | :--: | :-------: |
    | 오답처리 |  -   |   430 B   |

-   maxSum 의 초기값은 음수보다도 작아야 하는데 INT_MIN 이 아니라 0 이라고 선언함.
-   K 개 만큼 모이기 전부터 대소 비교를 시도함

```c++
#include <bits/stdc++.h>
using namespace std;
int N, K, sum = 0, maxSum = 0;
deque<int> dq;
int main() {
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        int temp;
        cin >> temp;
        sum += temp;
        dq.push_back(temp);
        if (int(dq.size()) > K) {
            sum -= dq.front();
            dq.pop_front();
        }
        if (sum > maxSum) maxSum = sum;
    }
    cout << maxSum;
    return 0;
}
```

## 정답

### C++：2025-10-09：덱으로 구현

-   | 메모리  | 시간  | 코드 길이 |
    | :-----: | :---: | :-------: |
    | 2152 KB | 40 ms |   478 B   |

-   prefix 합을 deque 컨테이너를 이용하여 직접 구현했다.
-   사실상 상당한 연산 오버헤드이기 때문에 아쉬운 부분

```c++
#include <bits/stdc++.h>
using namespace std;
int N, K, sum = 0, maxSum = INT_MIN;
deque<int> dq;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        int temp;
        cin >> temp;
        sum += temp;
        dq.push_back(temp);
        if (int(dq.size()) < K) continue;
        if (int(dq.size()) > K) {
            sum -= dq.front();
            dq.pop_front();
        }
        if (sum > maxSum) maxSum = sum;
    }
    cout << maxSum;
    return 0;
}
```

### C++：2025-10-09：prefix sum DP

-   | 메모리  | 시간  | 코드 길이 |
    | :-----: | :---: | :-------: |
    | 2412 KB | 24 ms |   347 B   |

-   누적합 DP
-   `n - k` 부터 `n` 까지의 합은, `1 ~ n` 까지 합에서 `1 ~ (k - 1)` 까지 합을 뺀 값과 같다. 따라서 누적합 배열을 만들어 준 후, 그 차이만 구해주면 된다. 일일히 k 구간의 합을 계산할 필요가 없다.

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, K, temp, psum[100001], maxSum = INT_MIN;
int main() {

    freopen("input.txt", "rt", stdin); // <- local input

    cin >> N >> K;
    for (int n = 1; n <= N; n++) cin >> temp; psum[n] = psum[n - 1] + temp;
    for (int i = K; i <= N; i++) maxSum = max(maxSum, psum[i] - psum[i - K]);
    cout << maxSum;
    return 0;
}
```
