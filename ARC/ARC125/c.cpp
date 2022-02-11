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
    vector<int> a(k);
    vector<bool> num(n+1, true);
    rep(i,k) {
        cin >> a[i];
        num[a[i]] = false;
    }
    if (k == 1) {
        for (int i = n; i >= 1; i--) {
            if (i == 1) cout << i << endl;
            else cout << i << " ";
        }
        return 0;
    }
    vector<vector<int>> vec1(k); 
    vector<vector<int>> vec2(k);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!num[i]) continue;
        int idx = lower_bound(a.begin(), a.end(), i) - a.begin();
        cnt = max(cnt, idx);
        if (cnt < k-1) {
            vec1[cnt].push_back(i);
            cnt++;
        } else if (cnt == k-1) {
            vec2[cnt].push_back(i);
            cnt++;
        } else {
            if (i < a[k-1]) {
                vec2[k-1].push_back(i);
            } else {
                vec2[k-2].push_back(i);
            }
        }
    }
    rep(i,k) reverse(vec2[i].begin(), vec2[i].end());
    vector<int> ans;
    rep(i,k) {
        ans.push_back(a[i]);
        rep(j,vec1[i].size()) ans.push_back(vec1[i][j]);
        rep(j,vec2[i].size()) ans.push_back(vec2[i][j]);
    }
    rep(i,n) {
        if (i == n-1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    return 0;
}