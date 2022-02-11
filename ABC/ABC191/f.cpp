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
    rep(i,n) {
        cin >> a[i];
    }
    int mn = INF;
    rep(i,n) chmin(mn, a[i]);
    set<int> s;
    rep(i,n) {
        for (int j = i+1; j < n; j++) {
            s.insert(__gcd(a[i],a[j]));
        }
    }
    int ans = 1;
    for (int x : s) {
        if (x < mn) ans++;
    }
    cout << ans << endl;
    return 0;
}