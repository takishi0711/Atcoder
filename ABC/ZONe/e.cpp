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

ll dist[505][505];

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<ll>> a(r+1, vector<ll>(c+1)), b(r+1, vector<ll>(c+1));
    rep(i,r)rep(j,c-1) cin >> a[i][j];
    rep(i,r-1)rep(j,c) cin >> b[i][j];
    rep(i,r+1)rep(j,c+1) dist[i][j] = LINF;
    r--; c--;
    dist[0][0] = 0;
    priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> q;
    q.emplace(0,P(0,0));
    while (!q.empty()) {
        int d = q.top().first;
        int vi = q.top().second.first, vj = q.top().second.second;
        q.pop();
        if (dist[vi][vj] != d) continue;
        if (vj < c) {
            int ni = vi, nj = vj+1;
            if (dist[ni][nj] > d+a[vi][vj]) {
                dist[ni][nj] = d+a[vi][vj];
                q.emplace(dist[ni][nj], P(ni,nj));
            } 
        }
        if (vj > 0) {
            int ni = vi, nj = vj-1;
            if (dist[ni][nj] > d+a[vi][vj-1]) {
                dist[ni][nj] = d+a[vi][vj-1];
                q.emplace(dist[ni][nj], P(ni,nj));
            } 
        }
        if (vi < r) {
            int ni = vi+1, nj = vj;
            if (dist[ni][nj] > d+b[vi][vj]) {
                dist[ni][nj] = d+b[vi][vj];
                q.emplace(dist[ni][nj], P(ni,nj));
            } 
        }
        for (int i = 1; i <= vi; i++) {
            int ni = vi-i, nj = vj;
            if (dist[ni][nj] > d+1+i) {
                dist[ni][nj] = d+1+i;
                q.emplace(dist[ni][nj], P(ni,nj));
            }
        }
    }    
    cout << dist[r][c] << endl;
    return 0;
}