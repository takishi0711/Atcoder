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
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i] >> t[i];
    rep(i,n) {
        bool ok1 = true, ok2 = true;
        rep(j,n) {
            if (j == i) continue;
            if (s[i] == s[j]) ok1 = false;
            if (s[i] == t[j]) ok1 = false;
        }
        rep(j,n) {
            if (j == i) continue;
            if (t[i] == s[j]) ok2 = false;
            if (t[i] == t[j]) ok2 = false;
        }
        if (ok1 == false && ok2 == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}