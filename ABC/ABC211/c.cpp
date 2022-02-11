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

using mint = modint1000000007;

int main() {
    string s;
    cin >> s;
    map<char, mint> mp;
    rep(z,int(s.size())) {
        if (s[z] == 'c') {
            mp['c']++;
        } else if (s[z] == 'h') {
            mp['h'] += mp['c'];
        } else if (s[z] == 'o') {
            mp['o'] += mp['h'];
        } else if (s[z] == 'k') {
            mp['k'] += mp['o'];
        } else if (s[z] == 'u') {
            mp['u'] += mp['k'];
        } else if (s[z] == 'd') {
            mp['d'] += mp['u'];
        } else if (s[z] == 'a') {
            mp['a'] += mp['d'];
        } else if (s[z] == 'i') {
            mp['i'] += mp['a'];
        } 
    }
    cout << mp['i'].val() << endl;
    return 0;
}