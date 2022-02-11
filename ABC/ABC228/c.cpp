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
    vector<vector<int>> p(n, vector<int>(3));
    rep(i,n)rep(j,3) cin >> p[i][j];
    vector<int> cnt(2000);
    rep(i,n) {
        int sum = 0;
        rep(j,3) sum += p[i][j];
        cnt[sum]++;
    }
    rep(i,1500) cnt[i+1] += cnt[i];
    rep(i,n) {
        int now = 300;
        rep(j,3) now += p[i][j];
        if (cnt[1300]-cnt[now]+1 <= k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}