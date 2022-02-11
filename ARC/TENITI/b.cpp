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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(1005);
    rep(i,n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    rep(i,m) {
        int b;
        cin >> b;
        cnt[b]++;
    }
    rep(i,1002) {
        if (cnt[i] == 1) cout << i << endl;
    }
    return 0;
}