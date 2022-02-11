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
    ll b, c;
    cin >> b >> c;
    ll ans = 0;
    if (b < 0) {
        ll rx = b, lx = -b;
        ll mnlx = b - c/2, mnrx = -b - (c-1)/2;
        mnrx = max((ll)0,mnrx);
        ll mxlx = 0, mxrx = 0;
        if (c%2) {
            mxlx = -mnrx-1;
            mxrx = -mnlx;
        } else {
            mxlx = -mnrx;
            mxrx = -mnlx-1;
        }        
        
        ans += mxlx-mnlx+1 + mxrx-mnrx+1;
        if (mnrx == mxlx) {
            ans -= 1;
        }
        cout << ans << endl;    
        return 0;   
    }
    ll rx = b, lx = -b;
    ll mnlx = -b - (c-1)/2, mnrx = b - c/2;
    ll mxlx = 0, mxrx = 0;
    if (c%2) {
        mxlx = -mnrx;
        mxrx = -mnlx-1;
    } else {
        mxlx = -mnrx-1;
        mxrx = -mnlx;
    }
    mxlx = min((ll)0,mxlx);
    mnrx = max((ll)0,mnrx);
    ans += mxlx-mnlx+1 + mxrx-mnrx+1;
    if (b == 0) {
        mnrx = 0 - c/2;
        if (c%2) {
            mxrx = -mnrx;
        } else {
            mxrx = -mnrx-1;
        }
        cout << mxrx-mnrx+1 << endl;
        return 0;
    }
    if (mnrx == mxlx) {
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}