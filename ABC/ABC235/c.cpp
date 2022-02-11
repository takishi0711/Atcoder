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
    int q;
    cin >> q;
    map<int, vector<int>> mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[a].push_back(i+1);
    }
    rep(qi,q) {
        int x, k;
        cin >> x >> k;
        if (mp[x].size() < k) cout << -1 << endl;
        else cout << mp[x][k-1] << endl;
    }
    return 0;
}