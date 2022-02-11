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
    int n, d;
    cin >> n >> d;
    vector<pair<int, P>> vec;
    rep(i,n) {
        int l, r;
        cin >> l >> r;
        vec.emplace_back(l,P(0,i));
        vec.emplace_back(r,P(1,i));
    }
    vector<bool> end(n);
    vector<int> sta;
    sort(vec.begin(), vec.end());
    int ans = 0;
    int now = 0;
    for (auto event : vec) {
        int col = event.first;
        int lr = event.second.first;
        int id = event.second.second;
        if (end[id]) continue;
        if (col <= now) {
            end[id] = true;
        } else if (lr == 1) {
            ans++;
            now = col + d - 1;
            end[id] = true;
            while (sta.size()) {
                end[sta.back()] = true;
                sta.pop_back();
            }
        } else {
            sta.push_back(id);
        }
    }
    cout << ans << endl;
    return 0;
}