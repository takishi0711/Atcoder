#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    vector<pair<ll, pair<pair<ll,ll>, ll>>> vec;
    rep(i,m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        vec.push_back(make_pair(c[i], make_pair(P(a[i], b[i]), i)));
    }
    sort(vec.begin(), vec.end());
    dsu d(n);
    vector<int> ans;
    rep(i,m) {
        int v = vec[i].second.first.first;
        int u = vec[i].second.first.second;
        int id = vec[i].second.second;
        if (d.same(u,v)) continue;
        ans.push_back(id);
        d.merge(u,v);
    }
    rep(i,n-1) {
        if (i == n-1-1) cout << ans[i]+1 << endl;
        else cout << ans[i]+1 << " ";
    }
    return 0;
}