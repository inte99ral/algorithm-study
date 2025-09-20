// ================================================================
// ============================= Main =============================
// ================================================================

#include <iostream>
#include <regex>
#include <string>
#include <vector>
// #include "Solution.cpp"

int solution1(int input1);
int solution2(std::vector<std::string> input2);
int solution3(std::vector<std::string> input3);
int solution4(std::vector<std::pair<int, int>> input4);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin);

    int input1; // Number
    std::vector<std::string> input2; // Korean Words
    std::vector<std::string> input3; // Between double quotation marks
    std::vector<std::pair<int, int>> input4; // Multi-Dimensional Array

    {   // * Input 1: Number
        std::cin >> input1;
        std::cin.ignore(); // input buffer "\n" release for getline()

        // * Solution 1
        solution1(input1);
    }
    
    {   // * Input 2: Korean Words
        std::string rawInput2;
        std::regex regExp2("[0-9A-Za-z가-힣\\s]+"); // Korean Words
        std::sregex_token_iterator iter;
        std::sregex_token_iterator end;

        std::getline(std::cin, rawInput2);
        iter = std::sregex_token_iterator(rawInput2.begin(), rawInput2.end(), regExp2);

        while (iter != end) input2.push_back(*iter++);

        // * Solution 2
        solution2(input2);
    }

    {   // * Input 3: Between double quotation marks
        std::string rawInput3;
        std::regex regExp3("\\\"[^\\[\\\"\\,\\]]+"); // Between double quotation marks
        std::sregex_token_iterator iter;
        std::sregex_token_iterator end;

        std::getline(std::cin, rawInput3);
        iter = std::sregex_token_iterator(rawInput3.begin(), rawInput3.end(), regExp3);

        while (iter != end) input3.push_back(((std::string) *iter++).substr(1));

        // * Solution 3
        solution3(input3);
    }

    {   // * Input 4: Multi-Dimensional Array
        std::string rawInput4;
        std::regex regExp4("[0-9]+"); // Numbers
        std::sregex_token_iterator iter;
        std::sregex_token_iterator end;

        std::getline(std::cin, rawInput4);
        iter = std::sregex_token_iterator(rawInput4.begin(), rawInput4.end(), regExp4);

        while (iter != end) input4.push_back({std::stoi(*iter++), std::stoi(*iter++)});

        // * Solution 4
        solution4(input4);
    }

    return 0;
}

// ================================================================
// =========================== Solution ===========================
// ================================================================

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