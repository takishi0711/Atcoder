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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    for (int i = x+1; i < h; i++) {
        if (s[i][y] == '#') break;
        else ans++;
    }
    for (int i = x-1; i >= 0; i--) {
        if (s[i][y] == '#') break;
        else ans++;
    }
    for (int i = y+1; i < w; i++) {
        if (s[x][i] == '#') break;
        else ans++;
    }
    for (int i = y-1; i >= 0; i--) {
        if (s[x][i] == '#') break;
        else ans++;
    }
    ans++;
    cout << ans << endl;
    return 0;
}