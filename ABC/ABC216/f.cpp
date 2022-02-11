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

using mint = modint998244353;

mint dp[5005][5005];

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<P> ap(n);
    rep(i,n) ap[i] = P(a[i],i);
    sort(ap.begin(), ap.end());
    vector<int> order;
    rep(i,n) order.push_back(ap[i].second);
    vector<fenwick_tree<mint>> dp(5005, fenwick_tree<mint>(5005));
    mint ans = 0;
    dp[0].add(0,1);
    rep(i,n) {
        if (a[order[i]] >= b[order[i]]) {
            ans += dp[i].sum(0, a[order[i]]-b[order[i]]+1);
        }
        for (int j = 0; j <= 5000; j++) {
            int next = min(j+b[order[i]], 5001);
            dp[i+1].add(j, dp[i].sum(j,j+1));
            dp[i+1].add(next, dp[i].sum(j,j+1));
        }
    }
    cout << ans.val() << endl;
    return 0;
}