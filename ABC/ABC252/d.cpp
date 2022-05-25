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

ll choose2(int n, int a) {
    ll res = 1;
    rep(i,a) {
        res *= n-i;
        res /= i+1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(200005);
    set<ll> st;
    rep(i,n) {
        cin >> a[i];
        st.insert(a[i]);
        cnt[a[i]]++;
    }
    ll ans = choose2(n, 3);
    for (int i = 1; i <= 200000; i++) {
        if (cnt[i] >= 2) {
            ans -= choose2(cnt[i], 2) * (n-cnt[i]);
            ans -= choose2(cnt[i], 3);
        }
    }
    cout << ans << endl;
    return 0;
}