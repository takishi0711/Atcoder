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


vector<int> to[2505];
vector<int> ot[2505];
bool reachableFrom1[2505];
bool reachableToN[2505];
bool ok[2505];

void dfs(int v) {
    if (reachableFrom1[v]) return;
    reachableFrom1[v] = true;
    for (int u : to[v]) {
        dfs(u);
    }
}

void rdfs(int v) {
    if (reachableToN[v]) return;
    reachableToN[v] = true;
    for (int u : ot[v]) {
        rdfs(u);
    }
}


int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<tuple<int,int,int>> edges;
    rep(i,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        c -= p;
        c = -c;
        edges.emplace_back(a,b,c);
        to[a].push_back(b);
        ot[b].push_back(a);
    }
    dfs(0);
    rdfs(n-1);
    rep(i,n) ok[i] = reachableFrom1[i]&reachableToN[i];
    { // bellman-ford
        vector<int> d(n,INF);
        d[0] = 0;
        bool upd = true;
        int step = 0;
        while (upd) {
            upd = false;
            rep(i,m) {
                int a, b, c;
                tie(a,b,c) = edges[i];
                if (!ok[a]) continue;
                if (!ok[b]) continue;
                int newD = d[a]+c;
                if (newD < d[b]) {
                    upd = true;
                    d[b] = newD;
                }
            }
            step++;
            if (step > n) {
                puts("-1");
                return 0;
            }
        }
        int ans = -d[n-1];
        ans = max(ans,0);
        cout << ans << endl;
    }
    return 0;
}