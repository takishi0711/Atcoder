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
    string s;
    cin >> s;
    int q;
    cin >> q;
    map<char, string> mp;
    mp['A'] = "BC";
    mp['B'] = "CA";
    mp['C'] = "AB";
    rep(qi,q) {
        ll t, k;
        cin >> t >> k;
        k--;
        vector<int> mov;
        int cnt = 0;
        rep(i,t) {
            cnt++;
            mov.push_back(k%2);
            k /= 2;
            if (k == 0) break;
        }
        reverse(mov.begin(), mov.end());
        char ans = s[k];
        ll ansn = s[k]-'A';
        if (t-cnt != 0) {
            ansn += t-cnt;
            ansn %= 3;
            ans = 'A' + ansn;
        }
        rep(i,mov.size()) {
            ans = mp[ans][mov[i]];
        }
        cout << ans << endl;
    }
    return 0;
}