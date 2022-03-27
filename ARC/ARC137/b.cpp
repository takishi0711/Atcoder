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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cntnum(2);

    vector<pair<int, int>> vec;
    ll cnt = 0;
    rep(i,n) {
        cnt++;
        if (i == n-1 || a[i] != a[i+1]) {
            vec.push_back(make_pair(a[i], cnt));
            cnt = 0;
        }
    } 

    for (auto [i,j] : vec) {
        cntnum[i] = max(cntnum[i], j);
    }

    int ans = cntnum[0]+cntnum[1]+1;
    cout << ans << endl;
    return 0;
}