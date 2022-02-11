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



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    sort(w.rbegin(), w.rend());
    vector<P> a(m);
    rep(i,m) {
        cin >> a[i].second >> a[i].first;
    }
    
    return 0;
}