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



int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    int ans = 0;
    map<P,bool> mp;
    rep(i,n)rep(j,i) { 
        int cnt = 2;
        int mi = j, ma = i;
        rep(k,n) {
            if (k == i || k == j) continue;
            if ((y[k]-y[i])*(x[j]-x[i]) == (y[j]-y[i])*(x[k]-x[i])) {
                cnt++;
                chmin(mi, k);
                chmax(ma, k);
            }
        }
        if (cnt >= k && !mp[P(mi,ma)]) ans++;
        mp[P(mi,ma)] = true;
    }
    cout << ans << endl;
    return 0;
}