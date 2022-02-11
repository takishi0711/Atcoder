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
    int n = s.size();
    int fa = 0, ba = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') fa++;
        else break;
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'a') ba++;
        else break;
    }
    if (fa > ba) {
        cout << "No" << endl;
        return 0;
    }
    int sub = ba-fa;
    string sb(sub, 'a');
    sb += s;
    string s2 = sb;
    reverse(sb.begin(), sb.end());
    if (sb == s2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}