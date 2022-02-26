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
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rep(dir1,8)rep(dir2,8) {
        int nx1 = x1+dx[dir1];
        int ny1 = y1+dy[dir1];
        int nx2 = x2+dx[dir2];
        int ny2 = y2+dy[dir2];
        if (nx1 == nx2 && ny1 == ny2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}