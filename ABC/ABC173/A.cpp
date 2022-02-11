#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    int N;
    cin >> N;
    int num = 0;
    for (int i = 0; i <= 10; i++) {
        if (1000*i >= N) {
            num = i;
            break;
        }
    }
    cout << num*1000 - N << endl;
}