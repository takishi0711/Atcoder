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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    dsu d(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (d.same(a,b)) {
            cout << "No" << endl;
            return 0;
        }
        if (to[a].size() >= 2 || to[b].size() >= 2) {
            cout << "No" << endl;
            return 0;
        }
        to[a].push_back(b);
        to[b].push_back(a);
        d.merge(a, b);
    }
    cout << "Yes" << endl;
    return 0;
}