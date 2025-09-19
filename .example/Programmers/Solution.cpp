#ifndef SOLUTION
#define SOLUTION

#include <bits/stdc++.h>

using namespace std;

// * Input 1: Number

int solution1(int input1) {
    int answer = 1000000007;

    cout << "[INPUT 1]: " << input1 << endl;

    return answer;
}


// * Input 2: Korean Words

int solution2(vector<string> input2) {
    int answer = 1000000007;

    cout << "[INPUT 2]: ";
    for (string s : input2) cout << s << ", ";
    cout << "\b\b " << endl;

    return answer;
}


// * Input 3: Between double quotation marks

int solution3(vector<string> input3) {
    int answer = 1000000007;

    cout << "[INPUT 3]: ";
    for (string s : input3) cout << s << ", ";
    cout << "\b\b " << endl;

    return answer;
}


// * Input 4: Multi-Dimensional Array

int solution4(vector<pair<int, int>> input4) {
    int answer = 1000000007;

    cout << "[INPUT 4]: [";
    for (const auto& p : input4) cout << "[" << p.first << ", " << p.second << "], ";
    cout << "\b\b]" << endl;

    return answer;
}

#endif