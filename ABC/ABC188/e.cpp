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

vector<int> to[200005];
vector<int> to2[200005];

vector<int> mx(200005);
vector<int> a(200005);
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : to[v]) {
        if (visited[u] && mx[u] == mx[v]) continue;
        mx[u] = max(mx[v], a[u]);
        dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,n) cin >> a[i];
    vector<bool> st(n, true);
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        to[y].push_back(x);
        to2[x].push_back(y);
        st[x] = false;
    }
    rep(i,n) {
        if (st[i]) {
            visited = vector<bool>(n, false);
            mx[i] = a[i];
            //visited[i] = true;
            dfs(i);
        }
    }
    int ans = -INF;
    rep(i,n) {
        if (to2[i].size() == 0) continue;
        for (int u : to2[i]) {
            int now = mx[u] - a[i];
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}