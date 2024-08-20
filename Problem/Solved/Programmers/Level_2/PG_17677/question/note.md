# 정리

## 과거 나의 풀이

### 풀이 방법

- 앞 글자 뒷 글자가 문자에 속하는지 확인
- 문자 조합을 대문자로 바꿔서 vector에 입력
- algorithm 라이브러리의 합집합 교집합 함수를 사용하여 답을 찾음

### 문제점

- map 을 이 당시에 몰랐는지 왜 vector 로 구현했는지는 모르겠음

### 코드

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1;
    vector<string> s2;
    vector<string> su;
    vector<string> sn;

    for(int i=1; i<str1.length(); i++){
        if((((str1[i-1] >= 'A')&&(str1[i-1] <= 'Z'))||((str1[i-1] >= 'a')&&(str1[i-1] <= 'z')))&&(((str1[i] >= 'A')&&(str1[i] <= 'Z'))||((str1[i] >= 'a')&&(str1[i] <= 'z')))){
            int l = str1[i-1];
            int r = str1[i];
            if(l >= 91) l -= 32;
            if(r >= 91) r -= 32;
            string memory = "";
            memory += (char)l;
            memory += (char)r;
            s1.push_back(memory);
        }
    }

    for(int i=1; i<str2.length(); i++){
        if((((str2[i-1] >= 'A')&&(str2[i-1] <= 'Z'))||((str2[i-1] >= 'a')&&(str2[i-1] <= 'z')))&&(((str2[i] >= 'A')&&(str2[i] <= 'Z'))||((str2[i] >= 'a')&&(str2[i] <= 'z')))){
            int l = str2[i-1];
            int r = str2[i];
            if(l >= 91) l -= 32;
            if(r >= 91) r -= 32;
            string memory = "";
            memory += (char)l;
            memory += (char)r;
            s2.push_back(memory);
        }
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(su));
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(sn));

    float u = su.size();
    float n = sn.size();

    if(u == 0){
        answer = 65536;
    }
    else if(n == 0){
        answer = 0;
    }
    else{
        answer = (int)((n / u)*65536);
    }

    return answer;
}
```

## 타인의 풀이

```cpp
#include <bits/stdc++.h>
using namespace std;
short a, b, C[676], D[676];
int solution(string A, string B) {
    for(int i=1; i<A.size(); i++)
        if(isalpha(A[i-1]) && isalpha(A[i]))
            C[(A[i-1]&31)*26+(A[i]&31)]++;
    for(int i=1; i<B.size(); i++)
        if(isalpha(B[i-1]) && isalpha(B[i]))
            D[(B[i-1]&31)*26+(B[i]&31)]++;
    for(int i=0; i<676; i++) a+=min(C[i], D[i]), b+=max(C[i], D[i]);
    return b ? a*65536/b : 65536;
}
```
