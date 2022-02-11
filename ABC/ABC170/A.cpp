#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;


int main() {
    vector<int> vec(5);
    for (int i = 0; i < 5; i++) {
        cin >> vec.at(i);
        if (vec.at(i) == 0) cout << i + 1 << endl;
    }

}