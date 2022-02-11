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
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    map<string, bool> mp;
    rep(i,m) {
        mp[t[i]] = true;
    }
    rep(i,n) {
        if (mp[s[i]]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}