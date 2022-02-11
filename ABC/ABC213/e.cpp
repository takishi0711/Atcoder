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
    vector<vector<int>> dist(h, vector<int>(w, INF));
    deque<P> q;
    dist[0][0] = 0;
    q.emplace_back(0,0);
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop_front();
        int d = dist[i][j];
        rep(v,4) {
            int ni = i+di[v], nj = j+dj[v];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == '#') continue;
            if (dist[ni][nj] <= d) continue;
            dist[ni][nj] = d;
            q.emplace_front(ni,nj);
        }
        for (int ei = -2; ei <= 2; ei++) {
            for (int ej = -2; ej <= 2; ej++) {
                if (abs(ei) == 2 && abs(ej) == 2) continue;
                int ni = i+ei, nj = j+ej;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                //if (s[ni][nj] == '#') continue;
                if (dist[ni][nj] <= d+1) continue;
                dist[ni][nj] = d+1;
                q.emplace_back(ni,nj);
            }
        }
    }
    int ans = dist[h-1][w-1];
    cout << ans << endl;
    return 0;
}