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

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> a(2*n, vector<ll>(2*n));
    rep(i,2*n) {
        for (int j = i+1; j < 2*n; j++) {
            cin >> a[i][j];
        }
    }
    rep(si,1<<2*n) {
        if (__builtin_popcount(si)%2 == 1) continue;
        rep(i,2*n) {
            for (int j = i+1; j < 2*n; j++) {
                if (si>>i&1 && si>>j&1) {
                    int bsi = si;
                    bsi ^= 1<<i;
                    bsi ^= 1<<j;
                    chmax(dp[si], dp[bsi]^a[i][j]);
                }
            }
        }
    }
    cout << dp[(1<<2*n)-1] << endl;
    return 0;
}