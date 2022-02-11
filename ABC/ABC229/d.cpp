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
    int k;
    cin >> s >> k;
    int n = s.size();
    int ans = 0;
    rep(_, 2) {
        vector<pair<char, ll>> vec;
        ll cnt = 0;
        rep(i,n) {
            cnt++;
            if (i == n-1 || s[i] != s[i+1]) {
                vec.push_back(make_pair(s[i], cnt));
                cnt = 0;
            }
        } 
        int sum = 0;
        int nowcnt = 0;
        int r = 0;
        int m = vec.size();
        rep(l,m) {
            while (r < m && (vec[r].first == 'X' || (vec[r].first == '.' && nowcnt+vec[r].second <= k))) {
                sum += vec[r].second;
                if (vec[r].first == '.') nowcnt += vec[r].second;
                r++;
            }
            if (r < m && vec[r].first == '.') {
                ans = max(ans, sum + min(k-nowcnt, (int)vec[r].second));
            } else {
                ans = max(ans, sum);
            }
            sum -= vec[l].second;
            if (vec[l].first == '.') nowcnt -= vec[l].second;
        }
        reverse(s.begin(), s.end());
    }
    cout << ans << endl;
    return 0;
}