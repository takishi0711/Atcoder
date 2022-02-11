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
    int l;
    cin >> l;
    vector<int> y(12);
    ll ans = 1;
    l--;
    rep(i,11) {
        ans *= l;
        for (int j = 2; j <= 11; j++) {
            if (y[j] == 0) {
                if (ans % j == 0) {
                    ans /= j;
                    y[j] = 1;
                } 
            }
        }
        l--;
    }
    cout << ans << endl;
    return 0;
}