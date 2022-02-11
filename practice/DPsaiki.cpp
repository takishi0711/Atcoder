#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int INF = 1001001001;
int n;
vector<int> h(100010);
vector<int> dp(100010);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }

    return false;
}


int rec(int i) {
    if (dp[i] < INF) return dp[i];
    if (i == 0) return 0;
    int res = INF;
    chmin(res, rec(i-1) + abs(h[i]-h[i-1]));
    if (i > 1) chmin(res, rec(i-2) + abs(h[i]-h[i-2]));

    return dp[i] = res; 
}

int main() {
    int n;
    cin >> n;
    rep(i,n) cin >> h[i];

    rep(i,n) dp[i] = INF;

    cout << rec(n) << endl;
    return 0;
}