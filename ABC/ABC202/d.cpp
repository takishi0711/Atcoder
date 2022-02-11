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

ll choose2(ll n, ll a) {
    ll res = 1;
    if (a == 0) return 1;
    rep(i,a) {
        res *= n-i;
        res /= i+1;
    }
    return res;
}

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    string ans;
    int nowa = a, nowb = b;
    rep(i,a+b) {
        if (nowa == 0) {
            ans += "b";
            nowb--;
            continue;
        }
        if (nowb == 0) {
            ans += "a";
            nowa--;
            continue;
        }
        ll res = choose2(a+b-i-1, nowa-1);
        if (k > res) {
            ans += "b";
            nowb--;
            k -= res;
        } else {
            ans += "a";
            nowa--;
        }
    }
    cout << ans << endl;
    return 0;
}