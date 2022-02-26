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

int row[1005][1005];
int col[1005][1005];
int naname[1005][1005];
int naname2[1005][1005];

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    auto s2 = s;
    rep(i,n) reverse(s2[i].begin(), s2[i].end());
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> a2(n, vector<int>(n));
    rep(i,n)rep(j,n) {
        if (s[i][j] == '#') a[i][j] = 1;
    }
    rep(i,n)rep(j,n) {
        if (s2[i][j] == '#') a2[i][j] = 1;
    }
    rep(i,n)rep(j,n) {
        row[i+1][j+1] = row[i+1][j] + a[i][j];
    }
    rep(j,n)rep(i,n) {
        col[i+1][j+1] = col[i][j+1] + a[i][j];
    }
    rep(i,n)rep(j,n) {
        naname[i+1][j+1] = naname[i][j] + a[i][j];
    }
    rep(i,n)rep(j,n) {
        naname2[i+1][j+1] = naname2[i][j] + a2[i][j];
    }
    
    rep(i,n+1)rep(j,n+1) {
        if (j-6 >= 0) {
            if (row[i][j]-row[i][j-6] >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    rep(j,n+1)rep(i,n+1) {
        if (i-6 >= 0) {
            if (col[i][j]-col[i-6][j] >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    rep(i,n+1)rep(j,n+1) {
        if (i-6 >= 0 && j-6 >= 0) {
            if (naname[i][j]-naname[i-6][j-6] >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    rep(i,n+1)rep(j,n+1) {
        if (i-6 >= 0 && j-6 >= 0) {
            if (naname2[i][j]-naname2[i-6][j-6] >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}