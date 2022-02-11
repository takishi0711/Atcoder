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
    ll n;
    cin >> n;
    ll sum = 0;
    set<ll> st;
    for (ll i = 2; i*i <= n; i++) {
        ll now = i*i;
        while (now <= n) {
            if (!st.count(now)) sum++;
            st.insert(now);
            now *= i;
        }
    }
    ll ans = n-sum;
    cout << ans << endl;
    return 0;
}