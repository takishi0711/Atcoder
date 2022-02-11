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

vector<int> to[100005];
vector<int> used(100005);
vector<int> c(100005);
vector<int> ans;

void dfs(int v, int p=-1) {
    if (used[c[v]] == 0) {
        ans.push_back(v+1);
    }
    used[c[v]]++;
    for (int u : to[v]) {
        if (u == p) continue;
        dfs(u, v);
        used[c[u]]--;
    }
}
 
int main() {
    int n;
    cin >> n;
    rep(i,n) cin >> c[i];
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    //used[c[0]] = true;
    dfs(0);
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << endl;
    return 0;
}