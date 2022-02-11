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



int main() {
    vector<ll> ten(6);
    ten[0] = 1;
    rep(i,5) ten[i+1] = ten[i]*10;
    double k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    vector<int> tk(10), ao(10);
    rep(i,4) {
        tk[s[i]-'0']++;
        ao[t[i]-'0']++;
    }
    vector<int> cnt(10);
    rep(i,10) {
        cnt[i] += tk[i]+ao[i];
    }
    double ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ll tkscore = 0, aoscore = 0;
            vector<int> tk2, ao2;
            tk2 = tk; ao2 = ao;
            tk2[i]++; ao2[j]++;
            for (int x = 1; x <= 9; x++) {
                tkscore += x*ten[tk2[x]];
                aoscore += x*ten[ao2[x]];
            }
            if (tkscore <= aoscore) continue;

            vector<int> cnt2 = cnt;
            double now = 1;
            now *= (double)(k-cnt2[i])/(k*9-8);
            cnt2[i]++;
            now *= (double)(k-cnt2[j])/(k*9-9);
            ans += now;
        }
    }
    printf("%.10f\n", ans);
    return 0;
}