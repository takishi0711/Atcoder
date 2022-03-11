#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

void Satisfaction_Score(int d, vector<int> c, vector<vector<int>> s, vector<int> t) {
    int ans = 0;
    vector<int> last(26);
    rep(i,d) {
        ans += s[i][t[i]];
        last[t[i]] = i+1;
        rep(j,26) {
            ans -= c[j]*(i+1 - last[j]);
        }
        cout << ans << endl;
    }
}

int main() {
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i,26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i,d)rep(j,26) cin >> s[i][j];
    vector<int> t(d);
    rep(i,d) {
        cin >> t[i];
        t[i]--;
    }
    Satisfaction_Score(d, c, s, t);
    return 0;
}