#include <bits/stdc++.h>
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
    while (true) {
      string s;
      cin >> s;
      if (s == "#") break;
      int n = s.size();
      int ans = 0;
      rep(qs,2) {
        int cnt = 0;
        rep(i,n) {
          if (s[i] == '(') {
            if (i != 0 && s[i-1] == ')') {
              if (cnt == 1 || cnt == -1) cnt = 2;
              else cnt += 1;
            }
            else cnt += 2;
          }
          else {
            cnt--;
            if (cnt == -1) ans++;
            else if (cnt < -1) cnt = 0;
          }
        }
        reverse(s.begin(), s.end());
        rep(i,n) {
          if (s[i] == '(') s[i] = ')';
          else s[i] = '(';
        }
        /*
        rep(i,ans) s.push_back(')');
        n += ans;
        */
      }
      cout << ans << endl;
    }
    return 0;
}