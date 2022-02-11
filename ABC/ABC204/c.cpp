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

vector<int> to[2005];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    rep(i,n) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : to[v]) {
                if (dist[i][v] != INF) continue;
                dist[i][u] = dist[i][v]+1;
                q.push(u);
            }
        }
    }   
    int ans = 0;
    rep(i,n)rep(j,n) {
        if (dist[i][j] != INF) ans++;
    }
    cout << ans << endl;
    return 0;
}