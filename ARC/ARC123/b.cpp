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
    vector<ll> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int idxa = 0, idxc = 0;
    int ans = 0;
    rep(i,n) {
        bool ok = true;
        if (!(a[idxa] < b[i])) continue;
        while (!(b[i] < c[idxc])) {
            idxc++;
            if (idxc == n) {
                ok = false;
                break;
            }
        }
        if (ok == false) {
            break;
        }
        ans++;
        idxa++;
        idxc++;
        if (idxa == n || idxc == n) break;
    }
    cout << ans << endl;
    return 0;
}