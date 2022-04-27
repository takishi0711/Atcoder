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



int main() {
    string s;
    cin >> s;
    bool ok1 = false, ok2 = false;
    map<char, bool> mp;
    rep(i,s.size()) {
        if (isupper(s[i])) {
            ok1 = true;
        } else {
            ok2 = true;
        }
        if (mp[s[i]]) {
            cout << "No" << endl;
            return 0;
        }
        mp[s[i]] = true;
    }
    if (ok1 && ok2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}