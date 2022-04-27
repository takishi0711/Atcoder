#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n-1; i++) {
        string t1 = s.substr(0,i);
        string t2 = s.substr(i,n-i);
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        rep(j,t1.size())rep(k,t2.size()) {
            if (t1[j] == t2[k]) chmax(dp[j+1][k+1], dp[j][k]+1);
            chmax(dp[j+1][k+1], dp[j+1][k]);
            chmax(dp[j+1][k+1], dp[j][k+1]);
        }
        chmax(ans, dp[t1.size()][t2.size()]);
    }
    cout << n-ans*2 << endl;
    return 0;
}