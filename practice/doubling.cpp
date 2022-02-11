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

int dub[50][100005];

int main() {
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<int> a(m);
    rep(i,m) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,n) dub[0][i] = i;
    rep(i,m) {
        swap(dub[0][a[i]],dub[0][a[i]+1]);
    }
    for (int i = 0; i <= 35; i++) {
        rep(j,n) {
            dub[i+1][j] = dub[i][dub[i][j]];
        }
    }
    vector<int> res(n);
    rep(i,n) res[i] = i;
    int keta = 0;
    while (d > 0) {
        vector<int> res2(n);
        if (d%2 == 1) {
            rep(i,n) res2[i] = res[dub[keta][i]];
            swap(res,res2);
        } 
        d /= 2;
        keta++;
    }
    vector<int> ans(n);
    rep(i,n) {
        ans[res[i]] = i+1;
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}