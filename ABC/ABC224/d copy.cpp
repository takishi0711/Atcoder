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

vector<int> to[10];
string goal = "0123456780";
map<string, int> dist;
string now = "0000000000";

int main() {
    int m;
    cin >> m;
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= 8; i++) {
        int p;
        cin >> p;
        now[p] = '0' + i;
    }
    queue<string> q;
    q.push(now);
    dist[now] = 0;
    while (!q.empty()) {
        string s = q.front(); q.pop();
        int pos;
        for (int i = 1; i <= 9; i++) {
            if (s[i] == '0') pos = i;
        }

        for (int u : to[pos]) {
            string t = s;
            swap(t[u], t[pos]);
            if (dist.count(t)) continue;
            dist[t] = dist[s]+1;
            q.push(t);
        }
    }
    if (!dist.count(goal)) cout << -1 << endl;
    else cout << dist[goal] << endl;
    return 0;
}