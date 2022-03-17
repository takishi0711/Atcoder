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
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    map<int, int> amp, bmp;
    int ans1 = 0;
    rep(i,n) {
        amp[a[i]]++;
        bmp[b[i]]++;
        if (a[i] == b[i]) ans1++;
    }
    int ans2 = 0;
    for (auto [x,y] : amp) {
        ans2 += y*bmp[x];
    }
    ans2 -= ans1;
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}