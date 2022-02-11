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
    ll k;
    cin >> k;
    ll ans = 0;
    for (ll a = 1; a <= k; a++) {
        ll res = 0;
        ll c = 0;
        for (ll b = 1; b*b < (k/a)*(k/a); c=b++) {
            ll x = (k/a)/b;
            if (x == b) res +=
            res += (k/a)/b;
        }
        res *= 2;
        if (c*c == (k/a)*(k/a)) res++;
        ans += res;
    }
    cout << ans << endl;
    return 0;
}