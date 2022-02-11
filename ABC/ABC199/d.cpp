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

vector<int> to[25];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    ll ans = pow(3,n);
    rep(i,m) {
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);     
        ll res = 3;   
        rep(j,n) {
            if (j == a[i] || j == b[i]) continue;
            if (to[j].size() == 0) res *= 3;
            else res *= 2;
        }
        ans -= res;
    }
    ans = max(ans,ll(0));
    cout << ans << endl;
    return 0;
}