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

vector<ll> yakusu(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(200005);
    rep(i,n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll ans = 0;
    rep(i,n) {
        // ll sum = 0;
        for (int j = 1; j*j <= a[i]; j++) {
            if (a[i]%j == 0) {
                ll x = j, y = a[i]/j;
                if (x == y) {
                    ll z = cnt[x];
                    // if (a[i] == x) z--;
                    ans += z*z; 
                    // sum += z*z; 
                } else {
                    ll z1 = cnt[x], z2 = cnt[y];
                    // if (a[i] == x) z1--;
                    // if (a[i] == y) z2--;
                    ans += z1*z2*2;
                    // sum += z1*z2*2;
                }
            }
        }
        // cout << a[i] << " " << sum << endl;
    }
    cout << ans << endl;
    return 0;
}