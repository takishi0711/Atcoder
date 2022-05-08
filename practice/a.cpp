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
    vector<vector<int>> to(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(0);
    vector<int> ans;
    vector<int> used(n);
    while (!q.empty()) {
        int v = q.top();
        q.pop();
        ans.push_back(v);
        used[v] = true;
        for (int u : to[v]) {
            if (used[u]) continue;
            q.push(u);
        }
    }
    rep(i,n) {
        if (i == n-1) cout << ans[i]+1 << endl;
        else cout << ans[i]+1 << " ";
    }
    return 0;
}