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

ll dp[200005][2];

int main() {
    int n;
    cin >> n;
    set<int> st;
    //vector<int> cnt(200005);
    vector<ll> mx(200005, -LINF);
    vector<ll> mn(200005, LINF);
    rep(i,n) {
        ll x;
        int c;
        cin >> x >> c;
        st.insert(c);
        mx[c] = max(mx[c],x);
        mn[c] = min(mn[c],x);
    }
    vector<int> num;
    num.push_back(0);
    mx[0] = 0;
    mn[0] = 0;
    for (int c : st) {
        num.push_back(c);
    }
    num.push_back(0);
    int m = num.size();
    rep(i,200005)rep(j,2) dp[i][j] = LINF;
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i < m; i++) {
        ll x = mx[num[i]] - mn[num[i]];
        {
            chmin(dp[i][0], dp[i-1][0] + abs(mn[num[i]]-mx[num[i-1]])+x);
            chmin(dp[i][0], dp[i-1][1] + abs(mn[num[i]]-mn[num[i-1]])+x);
        }
        {
            chmin(dp[i][1], dp[i-1][0] + abs(mx[num[i]]-mx[num[i-1]])+x);
            chmin(dp[i][1], dp[i-1][1] + abs(mx[num[i]]-mn[num[i-1]])+x);
        }
    }
    cout << min(dp[m-1][0], dp[m-1][1]) << endl;
    return 0;
}