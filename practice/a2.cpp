#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

int n;
int cf, cb;
int dp[1<<7][1<<7];
vector<int> ans;
int mi = INF;

void dfs(int si, int sj, int p, int cost, vector<int> v) {
    if (cost >= dp[si][sj]) return;
    if (si == ((1<<(n-1)) - 1) || si == ((1<<n) - 1)) {
        if (~sj>>(n-1)&1 && p != n-1) {
            if (cost < mi) {
                ans = v;
                mi = cost;
            }
        }
    }
    dp[si][sj] = cost;
    rep(i,n) {
        if (i == p) continue;
        if (sj>>i&1) continue;
        v.push_back(i);
        int nsj = sj ^ ((1<<n) - 1);
        nsj ^= ((1<<(i+1)) - 1);
        int ncost = cost;
        if (p < i) ncost += cf;
        else ncost += cb;
        dfs(si|(1<<i), nsj, i, ncost, v);
        v.pop_back();
    }
}


int main() {
    cin >> n;
    cin >> cf >> cb;
    string a;
    cin >> a;
    int x = 0;
    rep(i,a.size()) {
        if (a[i] == 'd') x |= (1<<i);
    }
    rep(i,1<<7)rep(j,1<<7) dp[i][j] = INF;
    vector<int> v;
    dfs(0, x, n-1, 0, v);
    cout << n << " ";
    rep(i,ans.size()) cout << ans[i]+1 << " ";
    cout << n << endl;
    return 0;
}