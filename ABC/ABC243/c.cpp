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
    int n;
    cin >> n;
    vector<int> y(n), x(n);
    rep(i,n) cin >> x[i] >> y[i];
    string s;
    cin >> s;
    map<int, vector<P>> mp;
    rep(i,n) {
        mp[y[i]].emplace_back(x[i], i);
    }
    for (auto vec : mp) {
        sort(vec.second.begin(), vec.second.end());
        bool right = false;
        for (auto p : vec.second) {
            if (s[p.second] == 'R') {
                right = true;
            } else {
                if (right) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}