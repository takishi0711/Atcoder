#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    ll sum = 0;

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < N; i++) {
        if (i == 0) continue;
        else if (i == 1) sum += a[0];
        //else if (i == 2 || i == 3) sum += a[1];
        else {
            sum += a[i/2]; 
        }
    }

    cout << sum << endl;
}