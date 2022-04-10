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

ll dp[2005][2005];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<P> p;
    rep(i,n) p.emplace_back(a[i],i);
    sort(p.rbegin(), p.rend());
    rep(i,n) {
        int pi = p[i].second;
        rep(l,i+1) {
            int r = i-l;
            chmax(dp[i+1][l+1], dp[i][l] + ll(pi-l)*a[pi]);
            chmax(dp[i+1][l], dp[i][l] + ll(n-r-1-pi)*a[pi]);
        }
    }
    ll ans = 0;
    rep(i,n+1) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}