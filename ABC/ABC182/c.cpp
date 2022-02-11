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
    vector<int> cnt(3);
    int n = s.size();
    rep(i,s.size()) {
        cnt[(s[i]-'0')%3]++;
    }
    int x = cnt[1]+cnt[2]*2;
    x %= 3;
    if (x == 0) cout << 0 << endl;
    else if (x == 1) {
        if (cnt[1] && n > 1) cout << 1 << endl;
        else {
            if (cnt[2] >= 2 && n > 2) cout << 2 << endl;
            else cout << -1 << endl;
        }
    }
    else {
        if (cnt[2] && n > 1) cout << 1 << endl;
        else {
            if (cnt[1] >= 2 && n > 2) cout << 2 << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}