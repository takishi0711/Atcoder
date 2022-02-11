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
    string s, t;
    cin >> s >> t;
    int cnts = 0, cntt = 0;
    rep(i,n) {
        if (s[i] == '0') cnts++;
        if (t[i] == '0') cntt++;
    }
    if (cnts != cntt) {
        cout << -1 << endl;
        return 0;
    }
    int ans = cnts;
    int nows = 0, nowt = 0;
    rep(i,n) {
        if (s[i] == '0') nows++;
        if (t[i] == '0') nowt++;
        if (s[i] == '0' && t[i] == '0') {
            if (nows == nowt) ans--;
        }
    }
    cout << ans << endl;
    return 0;
}