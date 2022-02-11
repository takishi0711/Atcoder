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
vector<int> u(200005), d(200005);
int dep;
vector<vector<int>> sikomi(200005);
vector<vector<int>> sikomu(200005);
vector<int> ans(200005);
vector<int> cntdep(200005);

void dfs(int v, int p=-1) {
    for (int q : sikomu[v]) {
        sikomi[d[q]].push_back(q);
    }
    /*
    for (int q : sikomi[dep]) {
        ans[q]++;
    } */   
    cntdep[dep]++;
    for (int u : to[v]) {
        if (u == p) continue;
        dep++;
        dfs(u,v);
        dep--;
    }
    for (int q : sikomu[v]) {
        sikomi[d[q]].pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int p;
        cin >> p;
        p--;
        to[i].push_back(p);
        to[p].push_back(i);
    }
    int q;
    cin >> q;
    rep(i,q) {
        cin >> u[i] >> d[i];
        u[i]--;
        sikomu[u[i]].push_back(i);
    }
    dep = 0;
    dfs(0);
    rep(i,q) cout << ans[i] << endl;
    return 0;
}