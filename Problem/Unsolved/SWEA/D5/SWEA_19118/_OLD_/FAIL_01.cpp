/**
 * @link https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=5&problemLevel=6&contestProbId=AYxCewMqiqwDFASu&categoryId=AYxCewMqiqwDFASu&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=6&pageSize=10&pageIndex=1
 * @name 19118. 언덕길
 * @version D5
 */

/*
실패 1

밑에서 부터 오름차순으로 올라가기 때문에 당연히 한칸씩 올라가며 탐욕법식 풀이가 가능할 것이라고 판단하였으나 변수가 과하게 많다

위 알고리즘의 가장 큰 반례는 

19
10 15 16 17 18 19 20 10 11 12 13 14 30 15 16 17 18 19 20 

으로, 처음에 20 -> 10 부분에서 오름차순 완결성이 깨진 것을 보고 

10 -> ... ->20 이 10 -> ... -> 14 보다 확연히 길기 때문에 후자를 삭제해버린다.

허나 14 이후에 30을 보면 15부터 20이 이어지기 때문에 미래를 봤다면 10-> ... ->20 인 전자를 삭제하는 것이 맞았다.
*/

#include<iostream>
#include<vector>

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
	int answer = 0;

	int secNum;

	int sec1st;
	int sec1ed;
	int sec1len;

	int sec2st;
	int sec2ed;
	int sec2len;

	// for (int i = 0; i < size; i++) {
	// 	cout << house[i] << ", ";
	// }
	// cout << "\b\b \n";

	for (int i = 1; i < size; i++) {
		if (house[i - 1] < house[i]) continue;

		sec2st = sec2ed = i;
		sec1st = sec1ed = i - 1;

		if (sec1ed != 0) {
			while ((sec1st != 0) && (house[sec1st - 1] >= house[sec2st])) {
				sec1st--;
			}
		}

		if (sec2st != size - 1) {
			while ((sec2ed + 1 != size - 1) && (house[sec1ed] >= house[sec2ed + 1]) && (house[sec2st] < house[sec2ed + 1])) {
				sec2ed++;
			}
		}

		sec1len = sec1ed - sec1st + 1;
		sec2len = sec2ed - sec2st + 1;

		if (sec1len == sec2len) {
			if (house[sec1ed] < house[sec2ed]) {
				secNum = 2;
			}
			else {
				secNum = 1;
			}
		}
		else if (sec1len > sec2len) {
			secNum = 2;
		}
		else {
			secNum = 1;
		}

		if (secNum == 2) {
			// * TEST_00
			{
				// cout << "delete2 : ";
				// for (int j = sec2st; j <= sec2ed; j++) {
				// 	cout << *(house.begin() + j) << ", ";
				// }
				// cout << "\b\b \n";
			}
			house.erase(house.begin() + sec2st, house.begin() + sec2ed + 1);
			size -= sec2len;
			i -= sec2len;
			answer += sec2len;
		}
		else {
			// * TEST_01
			{
				// cout << "delete1 : ";
				// for (int j = sec1st; j <= sec1ed; j++) {
				// 	cout << *(house.begin() + j) << ", ";
				// }
				// cout << "\b\b \n";
			}
			house.erase(house.begin() + sec1st, house.begin() + sec1ed + 1);
			size -= sec1len;
			i -= sec1len;
			answer += sec1len;
		}

		// * TEST_02
		{
			// cout << sec1st << "-" << sec1ed << "-" << sec2st << "-" << sec2ed << "\n";
		}

	}

	// * TEST_03
	{
		cout << "[";
		for (int i : house) {
			cout << i << ", ";
		}
		cout << "\b\b]\n";
	}
	return answer;
}