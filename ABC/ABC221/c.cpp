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
    int n;
    cin >> n;
    string s = to_string(n);
    /*
    vector<int> num(s.size());
    rep(i,s.size()) {
        num[i] = s[i]-'0';
    }
    sort(num.begin(), num.end());
    */

    int m = s.size();
    ll ans = 0;
    sort(s.begin(), s.end());
    do {
        for (int i = 1; i < m; i++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            ll a = stol(s1), b = stol(s2);
            string ds1 = to_string(a), ds2 = to_string(b);
            if (s1.size() != ds1.size() || s2.size() != ds2.size()) continue;
            if (a == 0 || b == 0) continue;
            ans = max(ans, a*b);
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}