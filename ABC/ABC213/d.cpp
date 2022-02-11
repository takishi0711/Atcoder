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
vector<int> ans;
vector<int> used[200005];

void dfs(int v, int p=-1) {
    ans.push_back(v+1);
    for (int u : to[v]) {
        if (u == p) continue;
        dfs(u,v);
        ans.push_back(v+1);
    }
}

int main() {
    int n;
    cin >> n;
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,n) sort(to[i].begin(), to[i].end());
    dfs(0);
    rep(i,ans.size()) {
        if (i == ans.size()-1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    return 0;
}