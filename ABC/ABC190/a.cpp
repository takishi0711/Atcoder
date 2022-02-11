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
    int a, b, c;
    cin >> a >> b >> c;
    string ans;
    if (a > b) ans = "Takahashi";
    if (a < b) ans = "Aoki";
    if (a = b) {
        if (c == 0) ans = "Aoki"
        else ans = "Takahashi";
    }
    cout << ans << endl;
    return 0;
}