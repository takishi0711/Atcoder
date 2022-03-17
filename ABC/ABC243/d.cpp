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
    ll x;
    cin >> n >> x;
    string s;
    cin >> s;
    bool big = false;
    int cnt = 0;
    rep(i,n) {
        if (x > 1e18) big = true;
        if (big) {
            if (s[i] == 'U') {
                if (cnt == 0) {
                    x /= 2;
                    big = false;
                } else {
                    cnt--;
                }
            } else {
                cnt++;
            }
        } else {
            if (s[i] == 'U') {
                x /= 2;
            } else if (s[i] == 'L') {
                x *= 2;
            } else {
                x *= 2;
                x++;
            }
        }
    }
    cout << x << endl;
    return 0;
}