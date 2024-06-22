/**
 * @link https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=5&problemLevel=6&contestProbId=AYxCewMqiqwDFASu&categoryId=AYxCewMqiqwDFASu&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=6&pageSize=10&pageIndex=1
 * @name 19118. 언덕길
 * @version D5
 */

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

// # Prototype Declaration ====================
int solution(int size, vector<int> house);

// # Global Variable & Constant================
const int CODE_VERSION = 0;

// # Implements Definition ====================
int main(int argc, char** argv) {
	int T;

	freopen("Problem/Unsolved/SWEA/D5/SWEA_19118/input.txt", "rt", stdin);

	cin >> T;

	for(int t = 1; t <= T; t++) {
		/////////////////////////////////////////////////////////////////////////////////////////////
		cout << '#' << t << ' ';

		int N;
		cin >> N;

		vector<int> house(N);
		for (int i = 0; i < N; i++) cin >> house[i];

		cout << solution(N, house);

		cout << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;
}

int solution(int size, vector<int> house) {
	int answer = 1001;

	vector<bool> select(size, false);

	deque<pair<int, int>> stk; // cnt, idx

	stk.push_back({0, 0});

	while (!stk.empty()) {
		int cnt = stk.back().first;
		int idx = stk.back().second;
		stk.pop_back();

		if (stk.back().second == size) {
			for (bool b : select) {
				cout << (b ? 1 : 0) << " ";
			}
			cout << "\n";
			continue;
		}

		select[idx] = !select[idx];

		stk.push_back({cnt + 1, idx + 1});
		stk.push_back({cnt, idx + 1});
	}



	return answer;
}