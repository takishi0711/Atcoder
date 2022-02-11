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
  string s;
  cin >> s;
  vector<int> cnt(10);
  int n = s.size();
  rep(i,n) {
    cnt[s[i]-'0']++; 
  }
  if (n == 1) {
    if ((s[0]-'0')%8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  else if (n == 2) {
    int x = (s[0]-'0')*10 + (s[1]-'0');
    int y = (s[1]-'0')*10 + (s[0]-'0');
    if (x%8==0 || y%8 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  else {
  for (int i = 100; i <= 999; i++) {
    if (i%8 != 0) continue;
    string now = to_string(i);
    vector<int> t(10);
    rep(j,3) {
      t[now[j]-'0']++;
    }
    if (t[0] > 0) continue;
    bool ok = true;
    rep(j,10) {
      if (j == 0) continue;
      if (t[j] > 0) {
        if (cnt[j] < t[j]) ok = false;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  }
  cout << "No" << endl;
  return 0;
}