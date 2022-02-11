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



int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    ll man = 0;
    rep(i,n) {
        man += abs(x[i]);
    }
    double uk = 0;
    ll sum = 0;
    rep(i,n) {
        sum += abs(x[i])*abs(x[i]);
    }
    uk = sqrt(sum);
    ll tev = 0;
    rep(i,n) {
        ll now = abs(x[i]);
        tev = max(tev, now);
    }
    cout << man << endl;
    printf("%.12f\n", uk);
    cout << tev << endl;
    return 0;
}