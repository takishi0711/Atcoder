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

// ABC 135 F - Strings of Eternity

// トポロジカルソートする O(n)
// 返り値が true の時のみ意味を持つ(false の場合は閉路)
struct TopologicalSort {
    vector<vector<int>> E; 
    TopologicalSort(int N) { E.resize(N); }
    void add_edge(int a, int b) { E[a].push_back(b); }
    bool visit(int v, vector<int>& order, vector<int>& color) { 
        color[v] = 1;
        for (int u : E[v]) { 
            if (color[u] == 2) continue; 
            if (color[u] == 1) return false;
            if (!visit(u, order, color)) return false; 
        } 
        order.push_back(v);
        color[v] = 2;
        return true;
    }
    bool sort(vector<int> &order) { 
        int n = E.size(); 
        vector<int> color(n);
        for (int u = 0; u < n; u++) {
            if (!color[u] && !visit(u, order, color)) return false;
        }
        reverse(order.begin(), order.end()); 
        return true; 
    } 
};

int main() {
    string s, t;
    cin >> s >> t;
    string copy = s;
    int ns = s.size(), nt = t.size();
    while (s.size() < t.size()) s += copy;
    string u = t + "#" + s + s;
    auto Z = z_algorithm(u);

    TopologicalSort ts(ns);

    for (int i = 0; i < ns; i++) {
        if (Z[i+nt+1] == nt) {
            ts.add_edge(i, (i+nt)%ns);
        }
    }

    vector<int> ord;
    bool res = ts.sort(ord);
    if (res == false) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> dp(500005);
    int ans = 0;
    for (int i : ord) {
        chmax(ans, dp[i]);
        for (int j : ts.E[i]) chmax(dp[j], dp[i]+1);
    }
    cout << ans << endl;
    return 0;
}