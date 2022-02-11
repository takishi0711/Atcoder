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

using mint = modint998244353;

// 典型90 57日目

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m,0));
    rep(i,n) {
        int t, x;
        cin >> t;
        rep(j,t) {
            cin >> x;
            x--;
            d[i][x] = 1;
        }
    }
    vector<int> s(m);
    rep(i,m) cin >> s[i];
    int pos = 0;
    rep(i,m) {
        bool found = false;
        for (int j = pos; j < n; j++) {
            if (d[j][i] == 1) {
                if (j != pos) {
                    swap(d[j], d[pos]);
                }
                found = true;
                break;
            }
        }
        if (found) {
            rep(j,n) {
                if (j != pos && d[j][i] == 1) {
                    for (int k = i; k < m; k++) {
                        d[j][k] ^= d[pos][k];
                    }
                }
            }
            if (s[i] == 1) {
                for (int j = i; j < m; j++) {
                    s[j] ^= d[pos][j];
                }
            }
            pos++;
        }
    }
    if (s == vector<int>(m,0)) {
        mint ans = 1;
        for (int i = pos; i < n; i++) ans *= 2;
        cout << ans.val() << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}