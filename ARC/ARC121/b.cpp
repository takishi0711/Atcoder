#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,char>;
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
    vector<pair<ll,char>> x(2*n);
    vector<ll> a(2*n);
    vector<char> c(2*n);
    int cntr = 0, cntg = 0, cntb = 0;
    rep(i,2*n) {
        cin >> x[i].first >> x[i].second;
        if (x[i].second == 'R') cntr++;
        if (x[i].second == 'G') cntg++;
        if (x[i].second == 'B') cntb++;
    }
    sort(x.begin(), x.end());
    cntr %= 2;
    cntg %= 2;
    cntb %= 2;
    if (cntr == 0 && cntg == 0 && cntb == 0) {
        cout << 0 << endl;
        return 0;
    }
    char color1, color2, color3;
    if (cntr == 0) {
        color1 = 'G';
        color2 = 'B';
        color3 = 'R';
    } else if (cntg == 0) {
        color1 = 'R';
        color2 = 'B';
        color3 = 'G';
    } else {
        color1 = 'R';
        color2 = 'G';
        color3 = 'B';
    }
    ll res1 = LINF, res2 = LINF, res3 = LINF;
    rep(i,2*n) {
        if (x[i].second == color1) {
            if (i > 0 && x[i-1].second == color2) {
                res3 = min(res3, abs(x[i].first-x[i-1].first));
            }
            if (i > 0 && x[i-1].second == color3) {
                res1 = min(res1, abs(x[i].first-x[i-1].first));
            }
            if (i < 2*n-1 && x[i+1].second == color2) {
                res3 = min(res3, abs(x[i].first-x[i+1].first));
            }
            if (i < 2*n-1 && x[i+1].second == color3) {
                res1 = min(res1, abs(x[i].first-x[i+1].first));
            }
        }
        if (x[i].second == color2) {
            if (i > 0 && x[i-1].second == color1) {
                res3 = min(res3, abs(x[i].first-x[i-1].first));
            }
            if (i > 0 && x[i-1].second == color3) {
                res2 = min(res2, abs(x[i].first-x[i-1].first));
            }
            if (i < 2*n-1 && x[i+1].second == color1) {
                res3 = min(res3, abs(x[i].first-x[i+1].first));
            }
            if (i < 2*n-1 && x[i+1].second == color3) {
                res2 = min(res2, abs(x[i].first-x[i+1].first));
            }
        }
    }
    ll ans = min(res3, res1+res2);
    cout << ans << endl;
    return 0;
}