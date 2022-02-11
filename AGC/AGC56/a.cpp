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



int main() {
    int n;
    cin >> n;
    vector<vector<char>> ans(n, vector<char>(n, '.'));
    int col = 0;
    vector<int> ku;
    rep(i,n) {
        rep(j,3) {
            ans[i][col] = '#';
            col++;
            if (col == n) {
                if (j != 2) ku.push_back(i);
                col = 0;
            }
        }
    }
    int pos = 0;
    rep(i,ku.size()) {
        swap(ans[pos], ans[ku[i]]);
        pos = ku[i]+1;
    }
    rep(i,n) {
        rep(j,n) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}