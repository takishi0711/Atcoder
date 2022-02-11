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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    int mx = 0;
    for (int i = 2; i <= 1000; i++) {
        int cnt = 0;
        rep(j,n) {
            if (a[j]%i == 0) cnt++;
        }
        if (cnt > mx) {
            mx = cnt;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}