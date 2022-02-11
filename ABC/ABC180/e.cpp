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


int n;
int za[18][3];
int d[18][18];
int dp[1<<18][18];

int rec(int S, int v) {
    if(dp[S][v] >= 0) return dp[S][v];
    if(S == (1<<n)-1 && v == 0) return dp[S][v] = 0;
    int tmp = INF;
    rep(u,n) if(!(S>>u & 1)) tmp = min(tmp, rec(S|1<<u,u)+d[v][u]);
    return dp[S][v] = tmp;
}

int main() {
    cin >> n;
    rep(i,n)rep(j,n) d[i][j] = d[j][i] = INF;
    rep(i,n) {
        cin >> za[i][0] >> za[i][1] >> za[i][2];
    }
    rep(i,n)rep(j,n) {
        if (i == j) continue;
        d[i][j] = abs(za[j][0]-za[i][0]) + abs(za[j][1]-za[i][1]) + max(0,za[j][2]-za[i][2]);
    }
    fill((int *)dp, (int *)(dp+(1<<17)), -1);
    cout << rec(0,0) << endl;
    return 0;
}