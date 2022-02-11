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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<P> b;
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') {
            b.emplace_back(i,j);
        }
    }
    int ans = 0;
    for (auto p : b) {
        int i = p.first, j = p.second;
        if (s[i][j-1] != '#' && s[i-1][j] != '#') ans++;
        if (s[i-1][j] != '#' && s[i][j+1] != '#') ans++;
        if (s[i][j+1] != '#' && s[i+1][j] != '#') ans++;
        if (s[i+1][j] != '#' && s[i][j-1] != '#') ans++;
        if (s[i][j-1] == '#' && s[i-1][j] == '#' && s[i-1][j-1] != '#') ans++;
        if (s[i-1][j] == '#' && s[i][j+1] == '#' && s[i-1][j+1] != '#') ans++;
        if (s[i][j+1] == '#' && s[i+1][j] == '#' && s[i+1][j+1] != '#') ans++;
        if (s[i+1][j] == '#' && s[i][j-1] == '#' && s[i+1][j-1] != '#') ans++;
    }
    cout << ans << endl;
    return 0;
}