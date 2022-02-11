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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    fenwick_tree<ll> fen(n+1);
    rep(i,n) {
        fen.add(i,a[i]);
    }
    ll l = 0, r = 1e9;
    double ans = INF;
    rep(i,100000) {
        ll cl = (l*2+r)/3;
        ll cr = (l+r*2)/3;
        ll num1 = cl*n + fen.sum(0,n);
        ll num2 = cr*n + fen.sum(0,n);
        int idx1 = upper_bound(a.begin(), a.end(), cl*2) - a.begin();
        int idx2 = upper_bound(a.begin(), a.end(), cr*2) - a.begin();
        num1 -= fen.sum(0,idx1) + cl*2*(n-idx1);
        num2 -= fen.sum(0,idx2) + cr*2*(n-idx2);
        double ans1 = (double)num1/n;
        double ans2 = (double)num2/n;
        ans = min({ans, ans1, ans2});
        if (num1 < num2) r = cr;
        else l = cl;
    }
    printf("%.10f\n", ans);
    return 0;
}