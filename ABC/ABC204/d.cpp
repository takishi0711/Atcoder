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

bool dp[105][100005];

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    int sum = 0;
    rep(i,n) {
        cin >> t[i];
        sum += t[i];
    }
    dp[0][0] = true;
    rep(i,n) {
        for (int j = 0; j <= sum; j++) {
            dp[i+1][j] = dp[i][j];
            if (j-t[i] >= 0) {
                dp[i+1][j] |= dp[i][j-t[i]];
            }
        }
    }
    int half = (sum+1)/2;
    for (int i = half; i <= sum; i++) {
        if (dp[n][i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}