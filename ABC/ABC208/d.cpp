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

vector<vector<P>> in(500), out(500);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    rep(i,n) dist[i][i] = 0;
    vector<vector<ll>> dist_first(n,vector<ll>(n,INF));
    rep(i,n) dist_first[i][i] = 0;
    vector<ll> c(m);
    rep(i,m) {
        int a, b;
        cin >> a >> b >> c[i];
        a--; b--;
        out[a].push_back(P(b,i));
        in[b].push_back(P(a,i));
        dist_first[a][b] = c[i];
    }
    dsu d(n);
    ll ans = 0;
    rep(k,n) {
        for (auto p : in[k]) {
            dist[p.first][k] = c[p.second];
            d.merge(k,p.first);
        }
        for (auto p : out[k]) {
            dist[k][p.first] = c[p.second];
            d.merge(k,p.first);
        }
        rep(i,n)rep(j,n) {
            bool ok = true;
            if (dist_first[i][j] != INF) {
                ans += dist_first[i][j];
                ok = false;
            }
            if (!d.same(i,j)) continue;
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            if (dist[i][j] != INF && ok) {
                cout << i << " " << j << " " << k << " " << dist[i][j] << endl;
                ans += dist[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}