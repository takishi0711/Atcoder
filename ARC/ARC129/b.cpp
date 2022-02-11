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
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];
    int mnr = INF, mxl = 0;
    rep(i,n) {
        mnr = min(mnr, r[i]);
        mxl = max(mxl, l[i]);
        if (mnr >= mxl) cout << 0 << endl;
        else {
            cout << (mxl-mnr+1)/2 << endl;
        }
    }
    return 0;
}