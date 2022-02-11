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


char g(char a, char b) {
    if (a == 'R') {
        if (b == 'R') return 'R';
        if (b == 'P') return 'P';
        if (b == 'S') return 'R';
    }
    if (a == 'P') {
        if (b == 'R') return 'P';
        if (b == 'P') return 'P';
        if (b == 'S') return 'S';
    }
    if (a == 'S') {
        if (b == 'R') return 'R';
        if (b == 'P') return 'S';
        if (b == 'S') return 'S';
    }
}


int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<char>> dp(105, vector<char>(105));
    rep(i,n) dp[0][i] = s[i];
    int w = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i+1][j] = g(dp[i][j], dp[i][(j+w)%n]);
        }
        w *= 2;
        w %= n;
    }
    cout << dp[k][0] << endl;
    return 0;
}