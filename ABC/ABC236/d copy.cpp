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

ll dp[1<<16];
int n;
ll ans = 0;
ll a[20][20];

void dfs(string s, ll x, int dep) {
    if (dep == 2*n) {
        chmax(ans, x);
        return;
    }
    if (s[dep] == '1') {
        dfs(s, x, dep+1);
        return;
    }
    s[dep] = '1';
    for (int i = dep+1; i < 2*n; i++) {
        if (s[i] != '1') {
            x ^= a[dep][i];
            s[i] = '1';
            dfs(s, x, dep+1);
            s[i] = '0';
            x ^= a[dep][i];
        }
    }
}



int main() {
    cin >> n;
    rep(i,2*n) {
        for (int j = i+1; j < 2*n; j++) {
            cin >> a[i][j];
        }
    }
    string s;
    rep(i,2*n) s += "0";
    dfs(s, 0, 0);
    cout << ans << endl;
    return 0;
}