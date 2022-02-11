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

const int MAX_A = 300005;
int op(int a, int b) { return max(a,b);}
int e() { return 0;}

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vector<int> idx(n+1);
    rep(i,n) {
        idx[q[i]] = i;
    }
    vector<vector<int>> pq(n);
    rep(i,n) {
        for (int j = p[i]; j <= n; j += p[i]) {
            pq[i].push_back(idx[j]);
        }
    }
    segtree<int,op,e> dp(MAX_A);
    // rep(i,pq[0].size()) {
    //     dp.set(pq[0][i], 1);
    // }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> num;
        rep(j,pq[i].size()) {
            int x = dp.prod(0,pq[i][j])+1;
            chmax(ans, x);
            num.push_back(x);
        }
        rep(j,pq[i].size()) {
            dp.set(pq[i][j], num[j]);
        }
    }
    cout << ans << endl;
    return 0;
}