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

using mint = modint1000000007;
vector<string> s;
bool visited[2005][2005];
mint memo[2005][2005];

mint f(int i, int j) {
    if (i<0||j<0) return 0;
    if (s[i][j] == '#') return 0;
    if (visited[i][j]) return memo[i][j];
    visited[i][j] = true;
    return memo[i][j] = f(i-1,j) + f(i,j-1) + f(i-1, j-1);
}

int main() {
    int h, w;
    cin >> h >> w;
    s = vector<string>(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w) visited[i][j] = false;
    memo[0][0] = 1;
    visited[0][0] = true;
    cout << f(h-1,w-1).val() << endl;
    return 0;
}