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
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, P, int>> edges;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back(make_tuple(c,P(a,b),0));
    }
    rep(qi,q) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back(make_tuple(w,P(u,v),qi+1));
    }
    sort(edges.begin(), edges.end());
    dsu d(n);
    vector<string> ans(q+5);
    rep(i,edges.size()) {
        int c;
        P p;
        int id;
        tie(c,p,id) = edges[i];
        int a = p.first, b = p.second;
        if (id == 0) {
            if (d.same(a,b)) continue;
            d.merge(a, b);
        } else {
            if (d.same(a,b)) ans[id] = "No";
            else ans[id] = "Yes";
        }
    }
    rep(i,q) cout << ans[i+1] << endl;
    return 0;
}