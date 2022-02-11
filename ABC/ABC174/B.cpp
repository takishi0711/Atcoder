#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  ll d;
  cin >> n >> d;
  int ans = 0;
  for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      if (x*x + y*y <= d*d) ans++;
  }
  cout << ans << endl;
  return 0;
}