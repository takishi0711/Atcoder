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
    int n, q;
    cin >> n >> q;
    vector<int> num(n+1);
    vector<int> idx(n+1);
    for (int i = 1; i <= n; i++) {
         num[i] = i;
         idx[i] = i;
    }
    rep(qi,q) {
        int x;
        cin >> x;
        if (idx[x] == n) {
            int y = num[idx[x]-1];
            swap(idx[x], idx[y]);
            swap(num[idx[x]], num[idx[y]]);
        } else {
            int y = num[idx[x]+1];
            swap(idx[x], idx[y]);
            swap(num[idx[x]], num[idx[y]]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == n) cout << num[i] << endl;
        else cout << num[i] << " ";
    }
    return 0;
}