// # BJ 11726：2×n 타일링

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define SET_IO(INPUT_DATA) \
        std::ios::sync_with_stdio(false); \
        std::cin.tie(nullptr); \
        std::cout.tie(nullptr); \
        std::istream* IO_STREAM = (std::filesystem::exists(INPUT_DATA)) \
            ? (std::istream*) new std::ifstream(INPUT_DATA) \
            : (std::istream*) new std::stringstream(INPUT_DATA); \
        std::streambuf* IO_BACKUP = std::cin.rdbuf(IO_STREAM->rdbuf())

    #define UNSET_IO() \
        std::cin.rdbuf(IO_BACKUP); \
        delete IO_STREAM
    
#else
    #define SET_IO(INPUT_DATA) \
        std::ios::sync_with_stdio(false); \
        std::cin.tie(nullptr); \
        std::cout.tie(nullptr)

    #define UNSET_IO() ((void) 0)
#endif

using namespace std;

long long factorialMemory[1000] = {1, 1,};
long long powMemory[1000] = {};

long long factorial(int num) {
    if (factorialMemory[num] != 0) return factorialMemory[num];
    return (factorial(num - 1) * num) % 10007;
}

long long powWithModRecur(int exp, int dividend, int divisor) {
    if (exp == 1) return dividend % divisor;
    return (powWithModRecur(exp - 1, dividend, divisor) * dividend) % divisor;
}

long long powWithMod(int index) {
    if (powMemory[index] == 0) powMemory[index] = powWithModRecur(10005, factorial(index), 10007);
    return powMemory[index];
}

int main() {
    SET_IO("_INPUT_.txt");
    int N;
    int answer = 0;
    
    cin >> N;

    for (int n1 = N / 2; n1 >= 0; n1--) {
        int n2 = N - (n1 * 2);
        answer += (((factorial(n1 + n2) * powWithMod(n1)) % 10007) * powWithMod(n2)) % 10007;
        answer %= 10007; 
    }

    cout << answer << "\n";
    UNSET_IO();
    return 0;
}