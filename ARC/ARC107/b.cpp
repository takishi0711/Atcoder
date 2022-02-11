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
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = 2; i <= 2*n; i++) {
    if (i-k > (ll)n*2) continue; 
    if (i-k < 2) continue;
    ll nx = 0, ny = 0;
    if (i <= n) nx = i-1;
    else nx = n-(i-n)+1;
    if (i-k <= n) ny = i-k-1;
    else ny = n-(i-k-n)+1;
    ans += nx*ny;
  }
  cout << ans << endl;
  return 0;
}