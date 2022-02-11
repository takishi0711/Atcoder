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
    string x;
    cin >> x;
    vector<int> alp(30);
    rep(i,26) {
        alp[x[i]-'a'] = i;
    }
    int n;
    cin >> n;
    vector<pair<string, int>> p(n);
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
        string s2;
        rep(j,s[i].size()) {
            s2 += 'a' + alp[s[i][j]-'a'];
        }
        p[i] = make_pair(s2,i);
    }
    sort(p.begin(), p.end());
    rep(i,n) {
        cout << s[p[i].second] << endl;
    }
    return 0;
}