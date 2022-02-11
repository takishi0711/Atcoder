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



int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<bool>> aka(h, vector<bool>(w,false)), block(h, vector<bool>(w,false));
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        aka[a][b] = true;
    }
    rep(i,m) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        block[c][d] = true;
    }
    vector<vector<bool>> ans(h, vector<bool>(w,false));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (block[i][j]) continue;
            if (!aka[i][j]) continue;
            while (j < w) {
                if (block[i][j]) break;
                ans[i][j] = true;
                j++;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = w-1; j >= 0; j--) {
            if (block[i][j]) continue;
            if (!aka[i][j]) continue;
            while (j >= 0) {
                if (block[i][j]) break;
                ans[i][j] = true;
                j--;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (block[i][j]) continue;
            if (!aka[i][j]) continue;
            while (i < h) {
                if (block[i][j]) break;
                ans[i][j] = true;
                i++;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = h-1; i >= 0; i--) {
            if (block[i][j]) continue;
            if (!aka[i][j]) continue;
            while (i >= 0) {
                if (block[i][j]) break;
                ans[i][j] = true;
                i--;
            }
        }
    }
    int cnt = 0;
    rep(i,h)rep(j,w) {
        if (ans[i][j]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}