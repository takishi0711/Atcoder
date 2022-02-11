#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    ll n;
    cin >> n;
    ll x = 1;
    ll ans = 0;
    while (1) {
        ll y = n/x;
        if (y == 1) {
            ans += n-x+1;
            break;
        }
        ll l = x, r = n;
        while (l+1 < r) {
            ll c = (l+r)/2;
            if (n/c == y) l = c;
            else r = c;
        }
        ans += y*(r-x);
        x = r;
    }
    cout << ans << endl;
    return 0;
}