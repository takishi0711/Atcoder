#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0, j = n-1;
  int ans = 0;
  while (i < j) {
      if (s[i] == 'W' && s[j] == 'R') {
          s[i] = 'R';
          s[j] = 'W';
          ans++;
          i++;
          j--;
      }
      else if (s[i] == 'W' && s[j] == 'W') j--;
      else if (s[i] == 'R' && s[j] == 'R') i++;
      else if (s[i] == 'R' && s[j] == 'W') {
          i++;
          j--;
      }
  }
  cout << ans << endl;
  return 0;
}