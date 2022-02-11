#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;
using ll = long long;


int main() {
    int X, N;
    cin >> X >> N;
    vector<int> vec(105);
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        vec.at(a.at(i)) = 1;
    }

    int p = 0;
    for (int i = 100; i >= 1; i--) {
        if (abs(X-p) > abs(X-i) && vec.at(i) == 0) p = i;
    }
    cout << p << endl;
}