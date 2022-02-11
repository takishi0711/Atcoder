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

double ougon = (double)(sqrt(5)+1)/2;

int main() {
    ll n;
    cin >> n;
    if (n <= 130) {
        cout << n << endl;
        rep(i,n) cout << 1 << endl;
        return 0;
    }
    vector<ll> num;
    //num.push_back(n);
    ll now = n;
    while (now > 10) {
        double a = (double)now/ougon;
        now = a;
        num.push_back(now);
    }
    reverse(num.begin(), num.end());
    int sz = num.size();
    ll x, y;
    if ((sz-2+1)%2 == 0) {
        x = num[1];
        y = num[0];
        vector<int> ans;
        rep(i,x) ans.push_back(1);
        rep(i,y) ans.push_back(2);
        rep(i,sz-2+1) {
            if (i%2 == 0) {
                ans.push_back(4);
                y = x+y;
            }
            else {
                ans.push_back(3);
                x = x+y;
            }
        }
        int k = x+y+sz-2+1;
        k += n-x;
        rep(i,n-x) {
            ans.push_back(1);
        }
        cout << k << endl;
        rep(i,ans.size()) cout << ans[i] << endl;
    } else {
        x = num[0];
        y = num[1];
        vector<int> ans;
        rep(i,x) ans.push_back(1);
        rep(i,y) ans.push_back(2);
        rep(i,sz-2+1) {
            if (i%2 == 1) {
                ans.push_back(4);
                y = x+y;
            }
            else {
                ans.push_back(3);
                x = x+y;
            }
        }
        int k = x+y+sz-2+1;
        k += n-x;
        rep(i,n-x) {
            ans.push_back(1);
        }
        cout << k << endl;
        rep(i,ans.size()) cout << ans[i] << endl;
    }
    return 0;
}