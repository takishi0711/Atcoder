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

bool taka[10][10], ao[10][10];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        taka[a][b] = true;
        taka[b][a] = true;
    }
    rep(i,m) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        ao[c][d] = true;
        ao[d][c] = true;
    }
    vector<int> vec;
    rep(i,n) vec.push_back(i);
    do {
        bool ok = true;
        rep(i,n)rep(j,i) {
            if (taka[i][j] != ao[vec[i]][vec[j]]) {
                ok = false;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(vec.begin(), vec.end()));
    cout << "No" << endl;
    return 0;
}