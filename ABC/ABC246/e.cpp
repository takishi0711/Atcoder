#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {1, 1, -1, -1};
const int dj[] = {1, -1, 1, -1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

int dist[1505][1505][4];

int main() {
    int n;
    cin >> n;
    int ai, aj, bi, bj;
    cin >> ai >> aj;
    cin >> bi >> bj;
    ai--; aj--; bi--; bj--;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    
    rep(i,n)rep(j,n)rep(k,4) dist[i][j][k] = INF;
    deque<tuple<int,int,int>> que;
    rep(i,4) {
        dist[ai][aj][i] = 1;
        que.push_front(make_tuple(ai,aj,i));
    }
    
    while (!que.empty()) {
        int i, j, dir;
        tie(i,j,dir) = que.front();
        que.pop_front();
        int ni = i+di[dir], nj = j+dj[dir];
        if (ni>=0&&ni<n&&nj>=0&&nj<n) {
            if (s[ni][nj] != '#') {
                if (dist[ni][nj][dir] > dist[i][j][dir]) {
                    dist[ni][nj][dir] = dist[i][j][dir];
                    que.push_front(make_tuple(ni,nj,dir));
                }
            }
        }
        for (int x = 1; x <= 3; x++) {
            int ndir = (dir+x)%4;
            if (dist[i][j][ndir] > dist[i][j][dir]+1) {
                dist[i][j][ndir] = dist[i][j][dir]+1;
                que.push_back(make_tuple(i,j,ndir));
            }
        }
    }
    
    int ans = INF;
    rep(i,4) {
        ans = min(ans, dist[bi][bj][i]);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}