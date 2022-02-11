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
    vector<vector<int>> a(26);
    rep(i,n) {
        a[s[i]-'a'].push_back(i);
    }
    int pos = n;
    rep(i,n) {
        int c = s[i]-'a';
        int idx = -1;
        for (int j = 0; j < c; j++) {
            int x = lower_bound(a[j].begin(), a[j].end(), pos) - a[j].begin();
            x--;
            if (x < 0) continue;
            if (a[j][x] <= i) continue;
            pos = a[j][x];
            swap(s[i], s[a[j][x]]);
            break;
        }
    }
    cout << s << endl;
    return 0;
}