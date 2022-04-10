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

int f(char c) {
    if ('1' <= c && c <= '9') {
        return c-'0';
    } else {
        return (c-'a') + 10;
    }
}

string f2(int n) {
    if (1 <= n && n <= 9) {
        return to_string(n);
    } else {
        string res;
        res += 'a' + (n-10);
        return res;
    }
}

string dfs(int n) {
    if (n == 1) return "1";
    else {
        string s = dfs(n-1);
        return s + f2(n) + s;
    }
}

int main() {
    int n;
    cin >> n;
    string ans = dfs(n);
    rep(i,ans.size()) {
        if (i == ans.size()-1) cout << f(ans[i]) << endl;
        else cout << f(ans[i]) << " "; 
    }
    return 0;
}