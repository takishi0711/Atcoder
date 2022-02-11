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
    ll n, m;
    cin >> n >> m;
    vector<int> id(10005,-1);
    vector<int> a;
    int len = 1;
    int x = (10/m)%m;
    int ama = 10%m;
    bool ok = false;
    ll ten = 10;
    while (id[x] == -1) {
        if (!ok) {
            if (ten > m) ok = true;
            ten *= 10;
        } else {
            id[x] = len;
        }
        a.push_back(x);
        len++;
        x = (x*10 + ama*10/m)%m;
        ama = (ama*10)%m;
    }
    int c = len - id[x];
    if (n < len) {
        cout << a[n] << endl;
        return 0;
    }
    n -= len;
    n %= c;
    int ans = a[id[x]+n];
    cout << ans << endl;
    return 0;
}