#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;



int main() {
    ll x, y, z;
    cin >> x >> y >> z;
    ll ans = 0;
    for (ll i = 0; i < 10000000; i++) {
        if (y*z > x*i) continue;
        else {
            ans = i-1;
            break;
        }
    }
    if (ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}