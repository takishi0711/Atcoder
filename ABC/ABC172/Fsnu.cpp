#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
 
const int K = 43;
 
ll dp[K][2][2];
 
int main() {
  int n;
  cin >> n;
  vector<ll> _a(n);
  rep(i,n) cin >> _a[i];
  ll x = 0;
  rep(i,n) x ^= _a[i];
  ll a = _a[0], b = _a[1];
  x ^= a^b;
  ll s = a+b;
 
  vector<int> xs, ss, as;
 
  rep(i,K)rep(j,2)rep(k,2) dp[i][j][k] = -1;
 
  dp[0][0][0] = 0;
  ll v = 1;
  rep(i,K-1) {
    int cx = x&1;
    int cs = s&1;
    int ca = a&1;
    xs.push_back(cx);
    ss.push_back(cs);
    as.push_back(ca);
    rep(j,2)rep(k,2) {
      if (dp[i][j][k] == -1) continue;
      // printf("%d %d %d: %lld\n", i,j,k,dp[i][j][k]);
      rep(na,2)rep(nb,2) {
        int ni = i+1;
        int nj = 0, nk = k;
        if ((na^nb) != cx) continue;
        int ns = na+nb+j;
        if (ns%2 != cs) continue;
        if (ns >= 2) nj = 1;
        if (ca < na) {
          nk = 1;
        } else if (ca == na) {
          nk = k;
        } else { // ca > na
          nk = 0;
        }
        chmax(dp[ni][nj][nk], dp[i][j][k]|(v*na));
      }
    }
    x >>= 1;
    s >>= 1;
    a >>= 1;
    v <<= 1;
  }
 
  a = dp[K-1][0][0];
  if (a == -1 || a == 0) {
    cout << -1 << endl;
    return 0;
  }
 
  ll ans = _a[0]-a;
  cout << ans << endl;
  return 0;
}