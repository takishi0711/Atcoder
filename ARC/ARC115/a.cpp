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
    int n, m;
    cin >> n >> m;
    int even = 0, odd = 0;
    ll ans = 0;
    rep(i,n) {
        string s;
        cin >> s;
        int cnt = 0;
        rep(j,m) {
            if (s[j] == '1') cnt++;
        }
        if (cnt%2 == 0) {
            ans += odd;
            even++;
        } else {
            ans += even;
            odd++;
        }
    }
    cout << ans << endl;
    return 0;
}