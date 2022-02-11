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
const double PI = acos(-1);

ll f(ll k, ll x) {
    ll res = 0;
    ll num = 1;
    while (x > 0) {
        res += num*(x%10);
        num *= k;
        x /= 10;
    }
    return res;
}

int main() {
    ll k;
    cin >> k;
    ll a, b;
    cin >> a >> b;
    ll ans = f(k, a)*f(k, b);
    cout << ans << endl;
    return 0;
}