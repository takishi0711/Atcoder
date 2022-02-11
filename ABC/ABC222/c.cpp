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
    int n, m;
    cin >> n >> m;
    vector<string> a(2*n);
    rep(i,2*n) cin >> a[i];
    vector<P> ord(2*n);
    rep(i,2*n) {
        ord[i].first = 0;
        ord[i].second = -i;
    }
    rep(i,m) {
        rep(j,n) {
            int id1 = ord[j*2].second*(-1);
            int id2 = ord[j*2+1].second*(-1);
            char x1 = a[id1][i];
            char x2 = a[id2][i];
            if (x1 == x2) continue;
            if (x1 == 'G') {
                if (x2 == 'C') ord[j*2].first++;
                if (x2 == 'P') ord[j*2+1].first++;
            }
            if (x1 == 'C') {
                if (x2 == 'G') ord[j*2+1].first++;
                if (x2 == 'P') ord[j*2].first++;
            }
            if (x1 == 'P') {
                if (x2 == 'C') ord[j*2+1].first++;
                if (x2 == 'G') ord[j*2].first++;
            }
        }
        sort(ord.rbegin(), ord.rend());
    }
    rep(i,2*n) {
        cout << ord[i].second*(-1)+1 << endl;
    }
    return 0;
}