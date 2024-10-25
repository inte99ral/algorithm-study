# Solution

## 모범답안

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long mod = 1000000007;
bool customCompare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first + b.first < b.first + a.first;
}
long long calculate(int l) {
    // 10^l 계산
    long long result = 1;
    long long base = 10;
    while(l > 0) {
        if(l % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        l /= 2;
    }
    return result;
}
long long stringToModInt(const string &s) {
    long long ret = 0;
    for (char digit : s) {
        ret = (ret * 10 + (digit - '0')) % mod;
    }
    return ret;
}

int main() {
    vector<long long> tenof(35);
    tenof[0] = 1;
    for(int i = 1;i < 35;i++) tenof[i] = (tenof[i-1] * 10) % mod;
    int T; cin >> T;
    for(int t = 1;t <= T;t++) {
        int N; cin >> N;
        vector<pair<string,int>> arr;
        arr.reserve(2*N);
        for(int i = 0;i < N;i++) {
            string a,b;
            cin >> a >> b;
            arr.push_back({a,i});
            arr.push_back({b,i});
        }
        sort(arr.begin(),arr.end(),customCompare);
        int _N = 2 * N;
        //long long answer = calculate1(N-2); //(10^(2^(N-2))) 계산
        long long answer = 0;
        vector<pair<int,int>> possib(N,{0,0});
        for(int i = _N-1;i >= 0;i--) {
            long long cur = 1;
            for(int j = 0;j < N;j++) {
                //자신 제외
                if(j != arr[i].second) {
                    //long long left = calculate(possib[j].first);
                    //long long right = calculate(possib[j].second);
                    long long left = tenof[possib[j].first];
                    long long right = tenof[possib[j].second];
                    long long inter = (left+right)%mod;
                    cur = (cur * inter) %mod;
                }
            }
            //answer에 누적
            answer = (answer + (stringToModInt(arr[i].first) * cur)%mod)%mod;
            //possib 업데이트 with arr[i]
            int target = arr[i].second;
            if(possib[target].first == 0) {
                possib[target] = {arr[i].first.size(),0};
            } else {
                possib[target] = {possib[target].first,arr[i].first.size()};
            }
        }
        cout << '#' << t << " " << answer << endl;
    }
    return 0;
}
```

## 내 풀이

```cpp
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

const long long MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("Problem\\Unsolved\\SWEA\\D5\\SWEA_20671\\question\\input.txt", "rt", stdin);  // * 로컬 input.txt 입력 코드


	int T;
	int N;

	// * 나눗셈 보조 tenof 생성 ==================================================
	vector<long long> tenof(35);
	tenof[0] = 1;

	for (int i = 1; i < 35; i++) {
		tenof[i] = (tenof[i - 1] * 10) % MOD; // 전 값에 10 곱하고 mod로 나누기
	}

	// * T 루프 진입 ==================================================
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;

		vector<pair<string, int>> arr;
		arr.reserve(2 * N);

		// * N 루프 진입 ==================================================
		for (int n = 0; n < N; n++) {

			string ai, bi;




			long long answer;
			cin >> answer;

			// # 10^30 자릿수까지 통일 후 크기 순서로 배열하고 그대로 출력, 힙정렬 바로 쓰기
			// priority_queue<long, vector<long>, function<bool(long, long)>> pq([](long o1, long o2) -> bool { return o1 < o2; });

			cout << "#" << n << " " << (answer) << "\n";

			cin >> answer;
			cout << "#" << n << " " << (answer) << "\n";
		}
	}

	return 0;
}
```
