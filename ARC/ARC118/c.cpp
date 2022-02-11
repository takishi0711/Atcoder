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
    int n;
    cin >> n;
    vector<int> a(n,1);
    rep(i,n) {
        if (i != 0) a[i] *= 2;
        if (i%2 == 0) a[i] *= 3;
        if (i == 0 || i == 1) a[i] *= 2500;
        else {
            a[i] *= i/2;
        }
    }
    rep(i,n) {
        if (i != n-1) cout << a[i] << " ";
        cout << a[i] << endl;
    }
    return 0;
}