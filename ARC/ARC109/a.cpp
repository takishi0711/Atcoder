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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0,a);
    vector<int> dist(205,INF);
    dist[a] = 0;
    auto push = [&](int i, int x) {
        if (dist[i] <= x) return;
        dist[i] = x;
        q.emplace(x,i);
    };
    while (!q.empty()) {
        int d = q.top().first;
        int i = q.top().second;
        q.pop();
        if (dist[i] != d) continue;
        if (i == 1) {
            push(1+100,d+x);
            push(1+1,d+y);
        }
        if (1 < i && i <= 99) {
            push(i-1,d+y);
            push(i+1,d+y);
            push(i+100,d+x);
            push(i+100-1,d+x);
        }
        if (i == 100) {
            push(100-1,d+y);
            push(100+100,d+x);
            push(100+100-1,d+x);
        }
        if (i == 101) {
            push(101-100,d+x);
            push(101-100+1,d+x);
            push(101+1,d+y);
        }
        if (100 < i && i <= 199) {
            push(i-1,d+y);
            push(i+1,d+y);
            push(i-100,d+x);
            push(i-100+1,d+x);
        }
        if (i == 200) {
            push(200-1,d+y);
            push(200-100,d+x);
        }
    }
    int ans = dist[b+100];
    cout << ans << endl;
    return 0;
}