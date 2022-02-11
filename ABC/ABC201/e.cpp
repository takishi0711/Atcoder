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

template<typename T>
struct lca {
    int n, root, l;
    vector<vector<int>> to;
    vector<vector<T>> co;
    vector<int> dep;
    vector<T> costs;
    vector<vector<int>> par; 
    lca(int n) : n(n),to(n),co(n),dep(n),costs(n) {
        l = 0;
        while ((1<<l) < n) l++;
        par = vector<vector<int>>(n+1,vector<int>(l,n));
    }
    void addEdge(int a, int b, T c=0) {
        to[a].push_back(b); co[a].push_back(c);
        to[b].push_back(a); co[b].push_back(c);
    }
    void dfs(int v, int d=0, T c=0, int p=-1) {
        if (p != -1) par[v][0] = p;
        dep[v] = d;
        costs[v] = c;
        for (int i = 0; i < to[v].size(); i++) {
            int u = to[v][i];
            if (u == p) continue;
            dfs(u, d+1, c^co[v][i], v);
        }
    }
    void init(int _root=0) {
        root = _root;
        dfs(root);
        for (int i = 0; i < l-1; i++) {
            for (int v = 0; v < n; v++) {
                par[v][i+1] = par[par[v][i]][i];
            }
        }
    }
    // LCA
    int operator()(int a, int b) {
        if (dep[a] > dep[b]) swap(a,b);
        int gap = dep[b]-dep[a];
        for (int i = l-1; i >= 0; i--) {
            int len = 1<<i;
            if (gap >= len) {
                gap -= len;
                b = par[b][i];
            }
        }
        if (a == b) return a;
        for (int i = l-1; i >= 0; i--) {
            int na = par[a][i];
            int nb = par[b][i];
            if (na != nb) {
                a = na; b = nb;
            }
        }
        return par[a][0];
    }
    int length(int a, int b) {
        int c = lca(a, b);
        return dep[a]+dep[b]-dep[c]*2;
    }
    T dist(int a, int b) {
        int c = lca(a, b);
        return costs[a]^costs[b];
    }
};

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    lca<ll> g(n);
    rep(i,n-1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g.addEdge(u,v,w);
    }
    g.init();
    vector<int> cnttwo(61);
    rep(i,n) {
        rep(j,61) {
            if (g.costs[i]>>j&1) cnttwo[j]++;
        }
    } 
    mint ans = 0;
    rep(i,n) {
        mint two = 1;
        rep(j,61) {
            if (g.costs[i]>>j&1) {
                int cnta = n-cnttwo[j];
                ans += two*cnta;
            } else {
                int cnta = cnttwo[j];
                ans += two*cnta;
            }
            two *= 2;
        }
    }
    ans /= 2;
    cout << ans.val() << endl;
    return 0;
}