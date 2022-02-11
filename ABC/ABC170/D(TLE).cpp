#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;
using ll = long long;


int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec.at(i);

    int num = 0;
    sort(vec.begin(), vec.end());
    bool t = true;
    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            for (int j = 0; j < i; j++) {
                if (vec.at(i) % vec.at(j) == 0) t = false;
            }
            if (t == true) num++;
            t = true;
        }
        else {
            if (vec.at(i) == vec.at(i+1)) continue;
            else {
                for (int j = 0; j < i; j++) {
                    if (vec.at(i) % vec.at(j) == 0) t = false;
                }
                if (t == true) num++;
                t = true;
            }
        }
    }
    cout << num << endl;
}