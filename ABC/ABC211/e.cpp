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

int n, k;
int ans = 0;
vector<string> s(10);
map<vector<string>, int> mp;

void dfs(vector<string> vec, int cnt) {
    if (cnt == k && mp[vec] == 0) {
        ans++;
        mp[vec]++;
        /*
        rep(i,n) {
            rep(j,n) cout << vec[i][j];
            cout << endl;
        }
        cout << endl;
        */
        return;
    }
    if (mp[vec] == 1) return;
    mp[vec]++;
    rep(i,n)rep(j,n) {
        if (vec[i][j] == '#' || vec[i][j] == '.') continue;
        rep(dir,4) {
            int ni = i+di[dir], nj = j+dj[dir];
            if (ni<0||ni>=n||nj<0||nj>=n) continue;
            if (vec[ni][nj] == '#' || vec[ni][nj] == 'x') continue;
            vector<string> vec2 = vec;
            vec2[ni][nj] = 'x';
            dfs(vec2, cnt+1);
        }
    }
}

int main() {
    cin >> n >> k;
    if (n*n < k) {
        cout << 0 << endl;
        return 0;
    }
    rep(i,n) cin >> s[i];
    rep(i,n)rep(j,n) {
        if (s[i][j] == '#') continue;
        auto s2 = s;
        s2[i][j] = 'x';
        dfs(s2, 1);
    }
    cout << ans << endl;
    return 0;
}