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
    ll a;
    cin >> a;
    ll n;
    cin >> n;
    vector<int> dist(1000005, INF);
    dist[1] = 0;
    queue<ll> q;
    q.push(1);
    while (!q.empty()) {
        ll i = q.front();
        q.pop();
        ll ni = i*a;
        if (ni < 1000000) {
            if (dist[ni] == INF) {
                dist[ni] = dist[i]+1;
                q.push(ni);
            }
        }
        if (i%10 == 0 || i < 10) continue;
        // string s;
        // s += to_string(i).back();
        // s += to_string(i).substr(1);
        string s = to_string(i);
        rotate(s.rbegin(), s.rbegin()+1, s.rend());
        ni = stol(s);
        if (dist[ni] == INF) {
            dist[ni] = dist[i]+1;
            q.push(ni);
        }
    }
    if (dist[n] == INF) dist[n] = -1;
    cout << dist[n] << endl;
    return 0;
}