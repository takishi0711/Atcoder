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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    rep(i,n) cin >> a[i];
    rep(i,k) {
        cin >> b[i];
        b[i]--;
    }
    int mx = 0;
    rep(i,n) {
        if (mx < a[i]) mx = a[i];
    }
    vector<int> num;
    rep(i,n) {
        if (a[i] == mx) num.push_back(i);
    }
    for (int x : num) {
        rep(i,k) {
            if (b[i] == x) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}