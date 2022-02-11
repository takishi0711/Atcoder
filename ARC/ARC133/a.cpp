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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int x = 0;
    rep(i,n-1) {
        if (a[i] > a[i+1]) {
            x = a[i];
            break;
        }
    } 
    if (x == 0) x = a[n-1];
    vector<int> ans;
    rep(i,n) {
        if (a[i] != x) ans.push_back(a[i]);
    }
    if (ans.size() == 0) {
        return 0;
    } else {
        rep(i,ans.size()) {
            if (i == ans.size()-1) cout << ans[i] << endl;
            else cout << ans[i] << " ";
        }
    }
    return 0;
}