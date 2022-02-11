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
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> event;
    vector<pair<P, P>> bus(m);
    rep(i,m) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        a--; b--; s++; t++;
        event.push_back(make_tuple(s, 1, i));
        event.push_back(make_tuple(t, 1, i));
        bus[i] = pair<P, P>(P(s,a), P(t,b));
    }
    vector<int> takahashi(q);
    rep(i,q) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        event.push_back(make_tuple(x, 2, i));
        event.push_back(make_tuple(z, 3, i));
        takahashi[i] = y;
    }
    vector<P> ans(q);
    vector<P> where_takahashi(q);
    vector<vector<int>> bussz(m);
    vector<vector<int>> toshi(n);
    sort(event.begin(), event.end());
    rep(i,event.size()) {
        int time = get<0>(event[i]);
        int tt = get<1>(event[i]);
        int id = get<2>(event[i]);
        if (tt == 1) {
            if (bus[id].first.first == time) {
                int a = bus[id].first.second;
                for (int x : toshi[a]) {
                    where_takahashi[x] = P(1,id);
                    bussz[id].push_back(x);
                }
                toshi[a] = vector<int>();
            } else {
                int b = bus[id].second.second;
                for (int x : bussz[id]) {
                    where_takahashi[x] = P(2,b);
                    toshi[b].push_back(x);
                }
                bussz[id] = vector<int>();
            }
        } else if (tt == 2) {
            int y = takahashi[id];
            toshi[y].push_back(id);
            where_takahashi[id] = P(2,y);
        } else {
            int y = where_takahashi[id].second;
            if (where_takahashi[id].first == 1) {
                ans[id] = P(bus[y].first.second, bus[y].second.second);
            } else {
                ans[id] = P(INF, y);
            }
        }
    }
    rep(i,q) {
        if (ans[i].first == INF) {
            cout << ans[i].second+1 << endl;
        } else {
            cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
        }
    }
    return 0;
}