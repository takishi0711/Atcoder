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
    int t;
    cin >> t;
    rep(qi,t) {
        ll l, r;
        cin >> l >> r;
        if (l*2 > r) {
            cout << 0 << endl;
        } else {
            cout << (r-2*l+1)*(r-2*l+2)/2 << endl;
        }
    }
    return 0;
}