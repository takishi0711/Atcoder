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
    P st, go;
    vector<set<P>> wp(26);
    rep(i,h)rep(j,w) {
        if (s[i][j] == 'S') {
            st.first = i;
            st.second = j;
        }
        if (s[i][j] == 'G') {
            go.first = i;
            go.second = j;
        }
        if ('a' <= s[i][j] && s[i][j] <= 'z') {
            wp[s[i][j]-'a'].insert(P(i,j));
        }
    }
    vector<vector<int>> dist(h, vector<int>(w,INF));
    queue<P> q;
    q.emplace(st.first,st.second);
    dist[st.first][st.second] = 0;
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        int d = dist[i][j];
        if ('a' <= s[i][j] && s[i][j] <= 'z') {
            int l = s[i][j]-'a';
            for (auto p : wp[l]) {
                int ni = p.first, nj = p.second;
                if (dist[ni][nj] != INF) {
                    wp[l].erase(P(ni,nj));
                    continue;
                }
                dist[ni][nj] = d+1;
                q.emplace(ni,nj);
                wp[l].erase(P(ni,nj));
            }
        }
        rep(dir,4) {
            int ni = i+di[dir], nj = j+dj[dir];
            if (ni<0||ni>=h||nj<0||nj>=w) continue;
            if (s[ni][nj] == '#') continue;
            if (dist[ni][nj] != INF) continue;
            dist[ni][nj] = d+1;
            q.emplace(ni,nj);
        }
    }
    int ans = dist[go.first][go.second];
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}