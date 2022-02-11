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
    vector<ll> a(n+1), b(n+1);
    rep(i,n) cin >> a[i+1];
    rep(i,n) cin >> b[i+1];
    if (n%2 == 0) {
        ll ans = LINF;
        ll sum = 0;
        for (int i = 1; i <= n; i += 2) {
            int ni = i+1;
            if (ni > n) ni = 1;
            sum += min(a[ni], b[i]+b[ni]);
        } 
        ans = min(ans, sum);
        sum = 0;
        for (int i = 2; i <= n; i += 2) {
            int ni = i+1;
            if (ni > n) ni = 1;
            sum += min(a[ni], b[i]+b[ni]);
        } 
        ans = min(ans, sum);
        cout << ans << endl;
    } else {
        vector<ll> odd(n+1), even(n+1);
        for (int i = 1; i <= n; i++) {
            int ni = i+1;
            if (ni > n) ni = 1;
            if (i%2 == 1) odd[i] = min(a[ni], b[i]+b[ni]);
            else even[i] = min(a[ni], b[i]+b[ni]);
        }
        for (int i = 0; i < n; i++) {
            odd[i+1] += odd[i];
            even[i+1] += even[i];
        }
        ll ans = LINF;
        for (int i = 1; i <= n; i++) {
            ll sum = b[i];
            if (i%2 == 1) {
                sum += odd[max(0, i-2)];
                sum += even[n] - even[i-1];
            } else {
                sum += even[max(0, i-2)];
                sum += odd[n] - odd[i-1];
            }
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}