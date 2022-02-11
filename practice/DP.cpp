#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<int> dp(n);
    rep(i,n) dp[i] = INF;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[0] = 0;
            continue;
        }
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if (i > 1) chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));

    }
    cout << dp[n-1] << endl;
    return 0;
}