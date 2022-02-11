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

ll ans = 0;
string s;

void dfs(string str, int nex) {
    if (str.size() == 4) {
        vector<bool> ok(10);
        rep(i,4) {
            ok[str[i]] = true;
        }
        bool ok2 = true;
        rep(i,10) {
            if (ok[i] == true && s[i] == 'x') ok2 = false;
            if (ok[i] == false && s[i] == 'o') ok2 = false; 
        }
        if (ok2) ans++; 
        return;
    }
    for (int i = nex; i <= 9; i++) {
        string str2 = str;
        str2 += ('0' + i);
        dfs(str2, i);
    }
}

int main() {
    cin >> s;
    dfs("",0);
    cout << ans << endl;
    return 0;
}