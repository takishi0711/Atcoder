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
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    ll now = 0;
    vector<ll> two(42);
    two[0] = 1;
    rep(i,41) {
        two[i+1] = two[i]*2;
    }
    rep(i,n) {
        ll x = now;
        x -= two[t[i]];
        if (x <= 0) {
            now = two[t[i]];
        } else {
            now = two[t[i]] + two[t[i]+1] * ((x + two[t[i]+1]-1)/two[t[i]+1]);
        }
    }
    cout << now << endl;
    return 0;
}