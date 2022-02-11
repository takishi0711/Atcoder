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
int in[200005];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        in[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i,n) {
        if (in[i] == 0) q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int v = q.top(); q.pop();
        ans.push_back(v);
        for (int u : to[v]) {
            in[u]--;
            if (in[u] == 0) q.push(u);
        }
    }
    if (ans.size() != n) cout << -1 << endl;
    else {
        rep(i,n) {
            if (i == n-1) cout << ans[i]+1 << endl;
            else cout << ans[i]+1 << " ";
        }
    }
    return 0;
}