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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    rep(si,1<<n) {
        vector<int> cnt(26);
        rep(i,n) {
            if (si>>i&1) {
                rep(j,s[i].size()) {
                    cnt[s[i][j]-'a']++;
                }
            }
        }
        int sum = 0;
        rep(i,26) {
            if (cnt[i] == k) sum++;
        }
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}