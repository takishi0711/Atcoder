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
    int t;
    cin >> t;
    rep(qi,t) {
        ll n;
        cin >> n;
        int cnt = 0;
        while (n%2 == 0) {
            n /= 2;
            cnt++;
        }
        string ans;
        if (cnt == 0) ans = "Odd";
        else if (cnt == 1) ans = "Same";
        else ans = "Even";
        cout << ans << endl;
    }
    return 0;
}