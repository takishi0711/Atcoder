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
#define No { cout << "No" << endl; return 0;}

int d[205][2];
int x[205][2];

int main() {
    int n;
    cin >> n;
    rep(i,205)rep(j,2) d[i][j] = -1;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        if (a != -1) d[a][0] = i;
        if (b != -1) d[b][1] = i;
        x[i][0] = a;
        x[i][1] = b;
    }
    for (int i = 1; i <= 2*n; i++) {
        if (d[i][0] != -1 && d[i][1] != -1) No;
    }
    rep(i,n) {
        if (x[i][0] != -1 && x[i][0] != -1) {
            if (x[i][0] >= x[i][1]) No;
            int c = x[i][1] - x[i][0];
            if (c == 1) continue;
            int up = x[i][0], down = x[i][1];
            for (int j = up+1; j <= down-1; j++) {
                if (d[j][0] != -1) {
                    if (d[j+down-up][1] > 2*n || (d[j+down-up][1] != -1)&&(d[j][0] != d[j+down-up][1])) {
                        No;
                    }
                    else d[j+down-up][1] = d[j][0];
                }
                if (d[j][1] != -1) {
                    if (d[j-down+up][0] < 1 || (d[j-down+up][0] != -1)&&(d[j][1] != d[j-down+up][0])) {
                        No;
                    }
                    else d[j-down+up][0] = d[j][1];
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}