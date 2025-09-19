#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "./Solution.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin);

    int input1; // Number

    {   // * Input 1: Number
        std::cin >> input1;
        cout << solution(input1);
    }
    
    return 0;
}