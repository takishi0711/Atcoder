#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    ll max = 0;
    ll ans = 0;
    rep(i,n) {
        ll a;
        cin >> a;
        if (i == 0) {
            max = a;
        }
        if (a < max) {
            ans += max-a;
        }
        else if (a >= max) max = a;
    }
    cout << ans << endl;
    return 0;
}