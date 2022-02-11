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
    int n, q;
    cin >> n >> q;
    vector<int> c(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<map<int,int>> ans(n+1);
    rep(i,q) {
        int m;
        cin >> m;
        if (m == 1) {
            int a, b;
            cin >> a >> b;
            ans[a][ans[b][]]
        }
    }
    return 0;
}