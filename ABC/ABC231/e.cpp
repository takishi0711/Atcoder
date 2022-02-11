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

int n;
ll x;
ll a[65];
map<ll,ll> memo[55];

ll dfs(int cur, ll lef) {
    if (cur == n-1) {
        return lef;
    }
    if (memo[cur].count(lef)) return memo[cur][lef];
    ll ret = LINF;

    ll step = a[cur+1]/a[cur];
    ll a = lef%step;

    if (a == 0) {
        ret = min(ret, dfs(cur+1, lef/step));
    } else {
        
    }
}

int main() {
    cin >> n >> x;
    rep(i,n) cin >> a[i];
    cout << dfs(0,x) << endl;
    return 0;
}