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
    ll n;
    cin >> n;
    vector<ll> num3, num5;
    ll now = 1;
    while (now <= n) {
        if (now == 1) {
            num3.push_back(1);
            now *= 3;
            continue;
        }
        num3.push_back(now);
        now *= 3;
    }
    now = 1;
    while (now <= n) {
        if (now == 1) {
            num5.push_back(1);
            now *= 5;
            continue;
        }
        num5.push_back(now);
        now *= 5;
    }
    for (int a = 1; a < num3.size(); a++) {
        for (int b = 1; b < num5.size(); b++) {
            if (num3[a] + num5[b] == n) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}