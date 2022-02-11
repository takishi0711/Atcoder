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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    sort(a.begin(), a.end());
    int now = 0;
    int mn = INF;
    rep(i,m) {
        int x = a[i]-now-1;
        if (x > 0) mn = min(mn, x);
        now = a[i];
    }
    if (n-now > 0) mn = min(mn, n-now);
    int ans = 0;
    now = 0;
    rep(i,m) {
        int x = a[i]-now-1;
        ans += (x+mn-1)/mn;
        now = a[i];
    }
    ans += (n-now+mn-1)/mn;
    cout << ans << endl;
    return 0;
}