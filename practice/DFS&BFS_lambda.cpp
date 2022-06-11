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



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);     
        to[b].push_back(a);     
    }

    {
        vector<bool> visited(n);
        auto dfs = [&](auto dfs, int v) -> void {
            visited[v] = true;
            for (int u : to[v]) {
                if (visited[u]) continue;
                dfs(dfs,u);
                printf("%d %d\n", u+1, v+1);
            }
        };
        dfs(dfs,0);
    }

    {
        vector<int> dist(n, INF);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int u : to[v]) {
                if (dist[u] != INF) continue;
                dist[u] = dist[v]+1;
                q.push(u);
                printf("%d %d\n", u+1, v+1);
            }
        }
    }
    return 0;
}