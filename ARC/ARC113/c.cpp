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
    int n = s.size();
    int cnt = 0;
    vector<int> al(26);
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (i >= n-2) {
            al[s[i]-'a']++;
        } else {
            if (s[i] == s[i+1] && s[i+1] != s[i+2]) {
                ans += n-(i+2)-al[s[i]-'a']+1;
                al = vector<int>(26);
                al[s[i]-'a'] += n-i;
            } else {
                al[s[i]-'a']++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}