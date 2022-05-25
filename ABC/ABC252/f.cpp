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
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    if (sum < l) {
        ans += l;
    }
    vector<ll> vec = a;
    while (vec.size() > 1) {
        vector<ll> next_vec;
        for (int i = 0; i < vec.size(); i += 2) {
            if (i == vec.size()-1) {
                next_vec.push_back(vec[i]);
            } else {
                next_vec.push_back(vec[i]+vec[i+1]);
                ans += vec[i]+vec[i+1];
            }
        }        
        vec = next_vec;
    }
    ans += sum;
    cout << ans << endl;
    return 0;
}