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
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    rep(i,k) cin >> c[i] >> d[i];
    int ans = 0;
    rep(si,1<<k) {
        vector<bool> tt(n+1, false);
        rep(i,k) {
            if (si>>i&1) tt[c[i]] = true;
            else tt[d[i]] = true;
        }
        int cnt = 0;
        rep(i,m) {
            if (tt[a[i]] && tt[b[i]]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}