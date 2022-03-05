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
    string s;
    cin >> s;
    string s2;
    rep(i,n) {
        if (s[i] == 'A') {
            s2 += 'B';
            s2 += 'B';
        } else if (s[i] == 'B') {
            s2 += 'B';
        } else {
            s2 += 'C';
        }
    }
    vector<pair<char, ll>> vec;
    ll cnt = 0;
    n = s2.size();
    rep(i,n) {
        cnt++;
        if (i == n-1 || s2[i] != s2[i+1]) {
            vec.push_back(make_pair(s2[i], cnt));
            cnt = 0;
        }
    } 
    string ans;
    for (auto [c, cnt] : vec) {
        if (c == 'B') {
            if (cnt%2 == 0) {
                rep(i,cnt/2) ans += 'A';
            } else {
                rep(i,cnt/2) ans += 'A';
                ans += 'B';
            }
        } else {
            rep(i,cnt) ans += 'C';
        }
    }
    cout << ans << endl;
    return 0;
}