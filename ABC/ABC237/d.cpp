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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<vector<int>> b(w, vector<int>(h));
    rep(i,w)rep(j,h) {
        b[i][j] = a[j][i];
    }
    rep(i,w) {
        rep(j,h) cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}