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
    int n;
    cin >> n;
    vector<P> edges_A;
    int a;
    cin >> a;
    rep(i,a) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges_A.emplace_back(x,y);
    }
    vector<P> edges_B;
    int b;
    cin >> b;
    rep(i,b) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges_B.emplace_back(u,v);
    }
    int ans = 0;
    rep(si,1<<b) {
        vector<vector<int>> to(n);
        vector<int> in(n);
        set<int> st;
        for (auto p : edges_A) {
            auto [x,y] = p;
            to[y].push_back(x);
            in[x]++;
        }
        rep(i,b) {
            auto [u,v] = edges_B[i];
            if (si>>i&1) {
                st.insert(u);
            } else {
                to[u].push_back(v);
                in[v]++;
            }
        }
        queue<int> q;
        rep(i,n) {
            if (st.count(i)) continue;
            if (in[i] == 0) q.push(i);
        }
        int now = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            now++;
            for (int j : to[i]) {
                if (st.count(j)) continue;
                in[j]--;
                if (in[j] == 0) q.push(j);
            }
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}