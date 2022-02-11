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
    string s;
    cin >> s;
    vector<int> a(n+1);
    rep(i,n+1) cin >> a[i];
    int k = INF;
    rep(i,n) k = min(k, abs(a[i]-a[i+1]));
    vector<vector<int>> ans(k, vector<int>(n+1));
    rep(i,n+1) {
        if (a[i] <= k) {
            int x = a[i];
            rep(j,k) {
                if (x) {
                    ans[k-j-1][i] = 1;
                    x--;
                }
            }
        } else {
            rep(j,k) ans[j][i] = (a[i]+j)/k;
        }
        
    }
    cout << k << endl;
    rep(i,k) {
        rep(j,n+1) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}