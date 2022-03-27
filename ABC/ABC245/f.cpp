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

// 座標圧縮
vector<int> compress1(vector<int>& v, int n) {
    vector<int> dic;
    rep(i,n) dic.push_back(v[i]);
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    rep(i,n) v[i] = lower_bound(dic.begin(), dic.end(), v[i]) - dic.begin();
    return dic;
}

int main() {
    int n, m;
    cin >> n >> m;
    dsu d1(n);
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        d1.merge(u,v);
    }
    auto gr = d1.groups();
    int ans = 0;
    for (auto vec : gr) {
        scc_graph graph(vec.size());
        sort(vec.begin(), vec.end());
        map<int,int> mp;
        map<int,int> mp2;
        rep(i,vec.size()) {
            mp[vec[i]] = i;
            mp2[i] = vec[i];
        }

        for (int u : vec) {
            for (int v : to[u]) {
                graph.add_edge(mp[u],mp[v]);
            }
        }
        auto scgr = graph.scc();
        vector<int> id(vec.size());
        rep(i,scgr.size()) {
            for (int u : scgr[i]) id[u] = i;
        }
        vector<set<int>> too(scgr.size());
        rep(i,vec.size()) {
            for (int j : to[mp2[i]]) {
                too[id[i]].insert(id[mp[j]]);
            }
        }
        vector<bool> ok(scgr.size());
        rep(i,scgr.size()) {
            if (scgr[i].size() > 1) ok[i] = true;
        }
        for (int i = scgr.size()-1; i >= 0; i--) {
            for (int j : too[i]) {
                if (ok[j]) ok[i] = true;
            }
        }
        rep(i,scgr.size()) {
            if (ok[i]) ans += scgr[i].size();
        }
    }
    cout << ans << endl;
    return 0;
}