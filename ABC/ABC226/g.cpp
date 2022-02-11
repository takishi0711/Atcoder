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
    int t;
    cin >> t;
    rep(ti,t) {
        vector<ll> a(6), b(6);
        for (int i = 1; i <= 5; i++) cin >> a[i];
        for (int i = 1; i <= 5; i++) cin >> b[i];
        
        // 5に5
        ll x = min(a[5], b[5]);
        a[5] -= x;
        b[5] -= x;
        // 4に4
        x = min(a[4], b[4]);
        a[4] -= x;
        b[4] -= x;
        // 5に4
        x = min(a[4], b[5]);
        b[1] += x;
        a[4] -= x;
        b[5] -= x;
        // 3に3
        x = min(a[3], b[3]);
        a[3] -= x;
        b[3] -= x;
        // 5に3
        x = min(a[3], b[5]);
        b[2] += x;
        a[3] -= x;
        b[5] -= x;
        // 4に3
        x = min(a[3], b[5]);
        b[2] += x;
        a[3] -= x;
        b[5] -= x;
        // 5に2
        x = min(a[2], b[5]);
        b[3] += x;
        a[2] -= x;
        b[5] -= x;
        // 5に1
        x = min(a[1], b[5]);
        b[4] += x;
        a[1] -= x;
        b[5] -= x;
        // 4に3
        x = min(a[3], b[4]);
        b[1] += x;
        a[3] -= x;
        b[4] -= x;
        // 4に2
        x = min(a[2], b[4]);
        b[2] += x;
        a[2] -= x;
        b[4] -= x;
        // 4に1
        x = min(a[1], b[4]);
        b[3] += x;
        a[1] -= x;
        b[4] -= x;
        // 3に2
        x = min(a[2], b[3]);
        b[1] += x;
        a[2] -= x;
        b[3] -= x;
        // 3に1
        x = min(a[1], b[3]);
        b[2] += x;
        a[1] -= x;
        b[3] -= x;
        // 2に1
        x = min(a[1], b[2]);
        b[1] += x;
        a[1] -= x;
        b[2] -= x;
        // 1に1
        x = min(a[1], b[1]);
        a[1] -= x;
        b[1] -= x;

        bool ok = true;
        for (int i = 1; i <= 5; i++) {
            if (a[i] != 0) ok = false;
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}