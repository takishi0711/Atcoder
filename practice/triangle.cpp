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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    // 三角形面積
    auto f = [&](int i, int j, int k) {
        i %= n;
        j %= n;
        k %= n;
        ll x1 = x[j]-x[i], y1 = y[j]-y[i];
        ll x2 = x[k]-x[i], y2 = y[k]-y[i];
        return abs(x1*y2-x2*y1)*4;
    };

    ll tot = 0;
    for (int j = 2; j < n; j++) {
        tot += f(0,j-1,j);
    }
    tot /= 4;

    ll s = 0, ans = 8e18;
    int j = 1;
    rep(i,n) {
        while (s < tot) {
            s += f(i,j,j+1);
            ans = min(ans, abs(tot-s));
            j++;
        }
        s -= f(i,i+1,j);
        ans = min(ans, abs(tot-s));
    }

    cout << ans << endl;
    return 0;
}