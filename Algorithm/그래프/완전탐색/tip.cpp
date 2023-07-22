//>> tip 0 : include 한 헤더파일 간의 간섭 막기
/*
예를 들어 name1.h 를 include 할 시에 가장 앞 줄에
#ifndef NAME1_H // 만일 NAME1_H 이라는 매크로가 정의되어 있지 않다면
#define NAME1_H  // NAME1_H 을 다음과 같이 정의하라
~코드 내용~
#endif // ifndef 종료
를 꼭 적도록 하자
// */

#ifndef TIP_CPP
#define TIP_CPP

//>> tip 1 : 여러개 선언하기 귀찮을 때
/*#include <bits/stdc++.h>
*/

#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
//>> tip 2 : /*에서 / 하나만 추가하면 해당 구간의 주석이 해제된다.
/*
int main() {
	return 0;
}
//*/

//>> tip 3 : 코드 구동 시간 체크
/*
class Timer {
//#include <iostream> #include <time.h> #include <vector> 선언 후 사용가능
private:
	vector<clock_t> start;
	vector<clock_t> end;
	vector<unsigned int> time;
public:
	Timer(int index) {
		cout << "[Timer Activate]" << endl;
		this->start = vector<clock_t>(index);
		this->end = vector<clock_t>(index);
		this->time = vector<unsigned int>(index);
	};
	~Timer() {
		cout << "[Timer Deactivate]" << endl;
	};
	void Start(int index) { 
		start[index] = clock(); 
		return;
	}
	void End(int index) { 
		end[index] = clock();
		time[index] = end[index] - start[index];
		return;
	}
	unsigned int Time(int index) {
		return time[index];
	}
	void Display(int index) {
		cout << "[TIME " << index << "] : " << time[index] << " ms" << endl;
	}

	void DisplayAll() {
		for (int i = 0; i < time.size(); i++) cout << "[TIME " << i << "] : " << time[i] << " ms" << endl;
	}
};

int main() {
	Timer* timer = new Timer(2);
	timer->Start(0);
	timer->Start(1);
	int sum = 0;  for (int i = 0; i < 10000; i++) for (int j = 0; j < 10000; j++) sum += i * j;
	timer->End(0);
	for (int i = 0; i < 10000; i++) for (int j = 0; j < 10000; j++) sum += i * j;
	timer->End(1);
	timer->Display(0);
	timer->DisplayAll();
	delete timer;
	return 0;
}
//*/

//>> tip 4 : sort 벡터 내림차순, 오름차순 소팅
/*
bool compare(int prev, int next) { return prev > next; }

int main() {
	vector<int> v = { 3,5,4,9,8,6,7,2,1 };
	cout << "[v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	sort(v.begin(), v.end());
	cout << "[오름차순 소팅 v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	sort(v.begin(), v.end(),compare);
	cout << "[내림차순 소팅 v] : "; for (auto& i : v) cout << i << ' '; cout << endl;
	
	return 0;
}
//*/

//>> tip 5 : transform 변환
/*
int main() {
	vector<int> v = { 3,5,4,9,8,6,7,2,1 };
	cout << "[v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	transform(v.begin(), v.end(), v.begin(), [](int n) {
		if (n > 5) return 0;
		else return n;
		}
	);
	cout << "[5 이하 0으로 변환 v] : "; for (auto& i : v) cout << i << ' '; cout << endl;
	
	cout << endl;

	string s = "I am the one, don't weigh a ton";
	cout << "[s] : " << s << endl;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << "[소문자 변환 s] : " << s << endl;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << "[대문자 변환 s] : " << s << endl;

	return 0;
}
//*/

//>> tip 6 : unique 중복제거
/*
int main() {
	//vector<int> v = { 3,5,8,4,9,8,2,6,7,2,1,1 };
	vector<int> v = { 9, 9, 9, 9, 9, 9 };
	cout << "[v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	sort(v.begin(), v.end());
	cout << "[소팅 v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	v.resize(unique(v.begin(), v.end()) - v.begin());
	cout << "[중복제거 v] : "; for (auto& i : v) cout << i << ' '; cout << endl;
	return 0;
}
//*/

#endif