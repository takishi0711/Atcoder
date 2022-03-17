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
    int n, m;
    cin >> n >> m; 
    vector<vector<ll>> dist(n, vector<ll>(n, LINF));
    vector<pair<ll, P>> edges(m);
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
        edges[i] = make_pair(c, P(a,b));
    }
    rep(k,n)rep(i,n)rep(j,n) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }

    int ans = 0;
    rep(i,edges.size()) {
        auto [c, p] = edges[i];
        auto [a, b] = p;
        if (c > dist[a][b]) ans++;
        else {
            bool ok = false;
            rep(j,n) {
                if (dist[a][j] + dist[j][b] == c) ok = true;
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}