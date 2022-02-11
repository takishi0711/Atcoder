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
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<vector<int>> dist(h, vector<int>(w,INF));
    dist[0][0] = 0;
    queue<P> q;
    q.push(P(0,0));
    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        {
            int ni = i+1, nj = j;
            if (!(ni<0||ni>=h||nj<0||nj>=w)) {
                if (c[ni][nj] == '.') {
                    if (dist[ni][nj] == INF) {
                        dist[ni][nj] = dist[i][j]+1;
                        q.emplace(ni,nj);
                    }
                }
            }
        }
        {
            int ni = i, nj = j+1;
            if (!(ni<0||ni>=h||nj<0||nj>=w)) {
                if (c[ni][nj] == '.') {
                    if (dist[ni][nj] == INF) {
                        dist[ni][nj] = dist[i][j]+1;
                        q.emplace(ni,nj);
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w) {
        if (dist[i][j] == INF) continue;
        ans = max(ans, dist[i][j]+1);
    }
    cout << ans << endl;
    return 0;
}