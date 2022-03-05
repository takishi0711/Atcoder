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

using mint = modint998244353;

int main() {
    int t;
    cin >> t;
    vector<mint> vec(1000005);
    vec[0] = 1;
    rep(i,1000003) {
        vec[i+1] = vec[i]*26;
    }
    rep(ti,t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        mint ans = 0;
        rep(i,(n+1)/2) {
            int num = s[i]-'A';
            ans += vec[(n+1)/2 - (i+1)] * num;
        }
        string s2 = s;
        rep(i,(n+1)/2) {
            s2[n-1-i] = s2[i];
        }
        if (s2 <= s) ans += 1;
        cout << ans.val() << endl;
    }
    return 0;
}