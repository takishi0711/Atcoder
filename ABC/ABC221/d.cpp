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

vector<int> compress1(vector<int>& v, int n) {
    vector<int> dic;
    rep(i,n) dic.push_back(v[i]);
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    rep(i,n) v[i] = lower_bound(dic.begin(), dic.end(), v[i]) - dic.begin();
    return dic;
}

int main() {
    int n;
    cin >> n;
    vector<int> num;
    vector<ll> a(n), b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
        num.push_back(a[i]);
        num.push_back(a[i]+b[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int m = num.size();
    auto Z = compress1(num,m);
    map<int,int> mp;
    rep(i,m) {
        mp[Z[i]] = num[i];
    }
    vector<ll> dp(m+1);
    rep(i,n) {
        dp[mp[a[i]]]++;
        dp[mp[a[i]+b[i]]]--;
    }
    rep(i,m) {
        dp[i+1] += dp[i];
    }
    vector<ll> ans(n+1);
    rep(i,m) {
        ans[dp[i]] += Z[i+1]-Z[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == n) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    return 0;
}