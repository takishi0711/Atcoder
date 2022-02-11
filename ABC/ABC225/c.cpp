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
    vector<vector<int>> b(n, vector<int>(m));
    rep(i,n)rep(j,m) {
        cin >> b[i][j];
        b[i][j]--;
    }
    bool ok = true;
    rep(i,n) {
        rep(j,m-1) {
            if (b[i][j+1] - b[i][j] != 1) ok = false;
        }
        int x = b[i][0]/7;
        rep(j,m) {
            if (b[i][j]/7 != x) ok = false;
        }
    }
    rep(i,m) {
        rep(j,n-1) {
            if (b[j+1][i] - b[j][i] != 7) ok = false;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}