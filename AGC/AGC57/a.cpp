#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int t;
    cin >> t;
    rep(ti,t) {
        ll a, b;
        cin >> a >> b;
        ll l = 0, r = 1e9+1;
        while (l+1 < r) {
            ll c = (l+r)/2;
            ll c1 = stol("1"+to_string(c));
            ll c2 = c*10;
            if (c < a) l = c;
            else if (c1 <= b || c2 <= b) l = c;
            else r = c;
        }
        cout << b-l << endl;
    }
    return 0;
}