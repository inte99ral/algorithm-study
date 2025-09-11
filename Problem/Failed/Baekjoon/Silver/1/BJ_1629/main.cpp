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

long long divideConquer(long long base, long long exp, long long mod) {
    if (exp == 1) return base % mod;

    long long dc = divideConquer(base, exp / 2, mod);
    long long answer = (dc * dc) % mod;

    if (exp % 2 == 1) answer = (answer * (base % mod)) % mod;

    return answer;
}

int main() {
    SET_IO("_INPUT_.txt");
    long long A, B, C;
    cin >> A >> B >> C;
    cout << divideConquer(A, B, C);
    UNSET_IO();
    return 0;
}