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
    int idx = 0;
    rep(i,s.size()) {
        if (s[i] == '.') idx = i;
    }
    int x = stoi(s.substr(0,idx));
    int y = stoi(s.substr(idx+1));
    if (0 <= y && y <= 2) cout << x << '-' << endl;
    if (3 <= y && y <= 6) cout << x << endl;
    if (7 <= y && y <= 9) cout << x << '+' << endl;
    return 0;
}