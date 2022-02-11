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
    ll n;
    cin >> n;
    vector<ll> ten(16);
    ten[1] = 1;
    for (int i = 2; i <= 16; i++) {
        ten[i] = ten[i-1]*10;
    }
    vector<ll> sum_keta(20), sum_sum_keta(20);
    sum_keta[1] = 1;
    sum_sum_keta[1] = 1;
    for (int i = 2; i <= 15; i++) {
        sum_keta[i] = ten[i] + sum_keta[i-1];
        sum_sum_keta[i] = sum_sum_keta[i-1] + sum_keta[i];
    }  
    string s = to_string(n);
    ll len = s.size();
    ll ans = sum_sum_keta[len-1];
    bool ok = true;
    rep(i,s.size()) {
      //cout << ans << endl;
        int num = s[i]-'0';
        if (num >= 2) {
            ans += sum_keta[len];
            break;
        } 
        if (num == 1) {
            if (i == s.size()-1) {
                ans++;
            } else {
                ll x = stol(s.substr(i+1));
                ans += x+1;
            }
        }
        if (num == 0) break;
      len--;
    } 
    cout << ans << endl;
    return 0;
}