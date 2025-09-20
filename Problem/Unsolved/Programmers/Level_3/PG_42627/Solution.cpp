// ================================================================
// ============================= Main =============================
// ================================================================

#include <iostream>
#include <regex>
#include <string>
#include <vector>
// #include "Solution.cpp"

int solution(std::vector<std::vector<int>> jobs);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin);

    std::vector<std::vector<int>> input;

    {   // * Input 4: Multi-Dimensional Array
        std::string rawInput4;
        std::regex regExp4("[0-9]+"); // Numbers
        std::sregex_token_iterator iter;
        std::sregex_token_iterator end;

        std::getline(std::cin, rawInput4);
        iter = std::sregex_token_iterator(rawInput4.begin(), rawInput4.end(), regExp4);

        while (iter != end) input.push_back({std::stoi(*iter++), std::stoi(*iter++)});

        // * Solution 4
        solution(input);
    }

    return 0;
}

// ================================================================
// =========================== Solution ===========================
// ================================================================

#ifndef SOLUTION
#define SOLUTION

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    {   // * TEST 01
        // for (auto &job : jobs) {
        //     for (int i : job) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
    }

    

    return answer;
}

#endif