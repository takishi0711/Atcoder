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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    int ans = 0;
    int cnt = 0;
    map<int,int> mp;
    rep(i,k) {
        if (mp[c[i]] == 0) {
            cnt++;
        } 
        mp[c[i]]++;
    }
    ans = cnt;
    for (int i = k; i < n; i++) {
        if (mp[c[i]] == 0) {
            cnt++;
        }
        mp[c[i]]++;
        if (mp[c[i-k]] == 1) {
            cnt--;
        }
        mp[c[i-k]]--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}