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
    ll left = 0, right = INF;
    while (left+1 < right) {
        ll c = (left+right)/2;
        if (r*c*r*c < R) {
            left = c;
        } else if (r*c*r*c == R) {
            right = c;
        } else {
            if (r*(c-1)*r*(c-1) < R) {
                left = c;
            } else {
                right = c;
            }
        }
    }
    cout << right << endl;
    return 0;
}