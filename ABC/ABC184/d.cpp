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

double d[100][100][100];

double f(int a, int b, int c) {
    if (a >= 100 || b >= 100 || c >= 100) return 0;
    if (d[a][b][c] != -1) return d[a][b][c];
    double res = 0;
    if (a > 0) {
        if (d[a+1][b][c] == -1) d[a+1][b][c] = f(a+1,b,c);
        res += double(a)/(a+b+c)*(d[a+1][b][c]+1);
    }
    if (b > 0) {
        if (d[a][b+1][c] == -1) d[a][b+1][c] = f(a,b+1,c);
        res += double(b)/(a+b+c)*(d[a][b+1][c]+1);
    }
    if (c > 0) {
        if (d[a][b][c+1] == -1) d[a][b][c+1] = f(a,b,c+1);
        res += double(c)/(a+b+c)*(d[a][b][c+1]+1);
    }
    return d[a][b][c] = res;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    rep(i,100)rep(j,100)rep(k,100) d[i][j][k] = -1;
    double ans = f(a, b, c);
    printf("%.10f\n", ans);
    return 0;
}