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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    {
        double l = 0, r = 1e9+1;
        rep(_,100) {
            double c = (l+r)/2;
            bool ok = false;
            double sum = 0;
            double cnt = 0;
            rep(i,n) {
                if (ok) {
                    sum += a[i];
                    cnt++;
                    ok = false;
                } else {
                    if (c <= a[i]) {
                        sum += a[i];
                        cnt++;
                        ok = false;
                    } else {
                        ok = true;
                    }
                }
            }
            sum /= cnt;
            if (c <= sum) l = c;
            else r = c;
        }
        printf("%.10f\n", l);
    }
    return 0;
}