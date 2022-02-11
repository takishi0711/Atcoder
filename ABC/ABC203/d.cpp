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
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    int nanban = 0;
    if (k%2 == 0) {
        nanban = (k*k)/2;
    } else {
        nanban = (k*k)/2+1;
    }
    vector<ll> b;
    multiset<ll> st;
    rep(i,k)rep(j,k) {
        b.push_back(a[i][j]);
        st.insert()
    }
    return 0;
}