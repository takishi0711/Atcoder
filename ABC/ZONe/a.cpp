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
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    rep(i,n-3) {
        if (s[i] == 'Z' && s[i+1] == 'O' && s[i+2] == 'N' && s[i+3] == 'e') ans++;
    }
    cout << ans << endl;
    return 0;
}