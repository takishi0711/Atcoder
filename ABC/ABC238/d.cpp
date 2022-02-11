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
        ll a, s;
        cin >> a >> s;
        bool kuri = false;
        bool ok = true;
        rep(i,61) {
            if (a>>i&1) {
                if (s>>i&1) {
                    if (!kuri) {
                        ok = false;
                        break;
                    }
                } else {
                    if (kuri) {
                        ok = false;
                        break;
                    }
                }
                kuri = true;
            } else {
                if (s>>i&1) {
                    kuri = false;
                } else {
                    if (kuri) {
                        kuri = true;
                    } else {
                        
                    }
                }
            }
        }
        if (kuri) ok = false;
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}