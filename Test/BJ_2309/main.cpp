#include <bits/stdc++.h>
using namespace std;

bool isSolved = false;
int n = 6;
int r = 2;
vector<int> origin = { 1, 2, 3, 4, 5, 6 };

int main() {
    do {
        for (int i = 0; i < r; i++) {
            cout << origin[i] << ", ";
        }
        cout << "\b\b \n";
    } while (next_permutation(origin.begin(), origin.end()));

    return 0;
}