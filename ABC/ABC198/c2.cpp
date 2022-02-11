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
    ll r, x, y;
    cin >> r >> x >> y;
    ll R = x*x + y*y;
    if (r*r == R) {
        cout << 1 << endl;
        return 0;
    }
    ll left = 0, right = INF;
    while (left+1 < right) {
        ll c = (left+right)/2;
        if (double(r*c) < sqrt(R)) {
            left = c;
        } else {
            right = c;
        }
    }
    if (right == 1) {
        right = 2;
    }
    cout << right << endl;
    return 0;
}