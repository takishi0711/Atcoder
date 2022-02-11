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

vector<int> to[10];
vector<int> goal = {0,1,2,3,4,5,6,7,8,0};
map<vector<int>, bool> mp;
vector<int> now(10);
int ans = INF;

void dfs(int pos, int dep, int bef=-1) {
    if (now == goal) {
        ans = min(ans,dep);
        return;
    }
    if (mp[now]) return;
    mp[now] = true;
    for (int nex : to[pos]) {
        if (nex == bef) continue;
        swap(now[pos], now[nex]);
        dfs(nex, dep+1, pos);
        swap(now[pos], now[nex]);
    }
    return;
}

int main() {
    int m;
    cin >> m;
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= 8; i++) {
        int p;
        cin >> p;
        now[p] = i;
    }
    int pos;
    for (int i = 1; i <= 9; i++) {
        if (now[i] == 0) pos = i;
    }
    dfs(pos, 0);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}