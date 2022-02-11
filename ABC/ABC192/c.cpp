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

vector<ll> ten(11);


ll g1(ll x) {
    vector<int> vec;
    while (x > 0) {
        vec.push_back(x%10);
        x /= 10;
    }
    sort(vec.begin(), vec.end());
    ll res = 0;
    int n = vec.size();
    rep(i,n) {
        res += vec[i]*ten[n-1-i];
    }
    return res;
}

ll g2(ll x) {
    vector<int> vec;
    while (x > 0) {
        vec.push_back(x%10);
        x /= 10;
    }
    sort(vec.rbegin(), vec.rend());
    ll res = 0;
    int n = vec.size();
    rep(i,n) {
        res += vec[i]*ten[n-1-i];
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    ten[0] = 1;
    rep(i,10) ten[i+1] = ten[i]*10;
    rep(i,k) {
        n = g2(n)-g1(n);
    }
    cout << n << endl;
    return 0;
}