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
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int pos = 0;
    vector<int> x(2), y(2);
    rep(i,h)rep(j,w) {
        if (s[i][j] == 'o') {
            x[pos] = i;
            y[pos] = j;
            pos++;
        }
    }
    int ans = abs(x[0]-x[1]) + abs(y[0]-y[1]);
    cout << ans << endl;
    return 0;
}