#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<int> ans(n);
    rep(sv,n) {
        vector<int> dist(n, INF);
        queue<int> q;
        auto push = [&](int v, int d) {
            if (dist[v] != INF) return;
            dist[v] = d;
            q.push(v);
        };
        push(sv,0);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int d = dist[v];
            if (v-1 >= 0) push(v-1, d+1);
            if (v+1 < n) push(v+1, d+1);
            if (v == x) push(y, d+1);
            if (v == y) push(x, d+1);
        }
        rep(i,n) ans[dist[i]]++;
    }
    rep(i,n) ans[i] /= 2;
    for (int i = 1; i < n; i++) cout << ans[i] << endl;
    return 0;
}