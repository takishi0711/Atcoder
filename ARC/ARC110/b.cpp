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
    int n;
    cin >> n;
    string t;
    cin >> t;
    if (t == "1") {
        ll ans = 1e10;
        ans *= 2;
        cout << ans << endl;
        return 0;
    }
    if (t == "11") {
        ll ans = 1e10;
        cout << ans << endl;
        return 0;
    }
    if (t == "111") {
        cout << 0 << endl;
        return 0;
    }
    if (t[0] == '0') {
        rep(i,n) {
            if (i%3 == 0 && t[i] == '1') {
                cout << 0 << endl;
                return 0;
            } 
            if (i%3 != 0 && t[i] == '0') {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (n > 1 && t[1] == '0') {
        rep(i,n) {
            if ((i+2)%3 == 0 && t[i] == '1') {
                cout << 0 << endl;
                return 0;
            } 
            if ((i+2)%3 != 0 && t[i] == '0') {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (n > 2 && t[2] == '0') {
        rep(i,n) {
            if ((i+1)%3 == 0 && t[i] == '1') {
                cout << 0 << endl;
                return 0;
            } 
            if ((i+1)%3 != 0 && t[i] == '0') {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    bool ok = true;
    if (n >= 3) {
        rep(i,3) {
            if (t[i] == '0') ok = false;
        }
        if (ok) {
            cout << 0 << endl;
            return 0;
        }
    }
    int cnt = 0;
    rep(i,n) {
        if (t[i] == '0') cnt++;
    }
    ll ans = 1e10;
    if (t[n-1] == '0') ans = ans-cnt+1;
    else ans = ans-cnt;
    cout << ans << endl;
    return 0;
}