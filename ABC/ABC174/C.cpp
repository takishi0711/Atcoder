#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int k;
  cin >> k;
  ll ans = 0;
  vector<bool> t(k, false);
  int x = 7;
  while (true) {
      ans++;
      x %= k;
      if (x == 0) break;
      if (t[x]) {
          cout << -1 << endl;
          return 0;
      }
      t[x] = true;
      x = x*10 + 7;
  } 
  cout << ans << endl;
  return 0;
}