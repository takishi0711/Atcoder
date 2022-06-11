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

vector<int> to[200005];
ll cnt[200005][4];

void dfs(int num, int v, int p, int depth) {
    cnt[num][depth] += v+1;
    for (int u : to[v]) {
        if (u == p) continue;
        if (depth+1 <= 3) dfs(num, u, v, depth+1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,n) {
        dfs(i, i, -1, 0);
    }
    int q;
    cin >> q;
    rep(qi,q) {
        int x, k;
        cin >> x >> k;
        x--;
        int ans = 0;
        for (int i = 0; i <= k; i++) ans += cnt[x][i];
        cout << ans << endl;
    }
    return 0;
}