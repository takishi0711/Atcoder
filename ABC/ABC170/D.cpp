#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;
using ll = long long;

const int M = 1000005;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec.at(i);

    vector<int> cnt(M);
    for (int x : vec) {
        if (cnt.at(x) != 0) {
            cnt.at(x) = 2;
            continue;
        }
        for (int i = x; i < M; i += x) cnt.at(i)++;
    }

    int num = 0;
    for (int x : vec) {
        if (cnt.at(x) == 1) num++;
    }
    cout << num << endl;
}