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



int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n), w(m);
  rep(i,n) cin >> h[i];
  rep(i,m) cin >> w[i];
  sort(h.begin(), h.end());
  vector<ll> gu(n), ki(n);
  for (int i = 1; i < n; i++) {
    if (i%2 != 0) ki[i] = h[i]-h[i-1];
    else gu[i] = h[i]-h[i-1];
  }
  rep(i,n-1) {
    gu[i+1] += gu[i];
    ki[i+1] += ki[i];
  }
  ll ans = LINF;
  rep(i,m) {
    int po = 0;
    int it = lower_bound(h.begin(), h.end(), w[i]) - h.begin();
    if (it == n) po = n-1;
    else if (it%2 == 0) po = it;
    else po = it-1;
    ll now = ki[max(0,po-1)] + gu[n-1] - gu[po] + abs(h[po]-w[i]);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}