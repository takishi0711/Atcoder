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

vector<int> to[200005];
int cnt[200005][4];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // rep(i,n) {
    //     vector<int> dist(n,INF);
    //     queue<int> q;
    //     dist[i] = 0;
    //     cnt[i][0] = i+1;
    //     q.push(i);
    //     while (!q.empty()) {
    //         int v = q.front();
    //         q.pop();
    //         for (int u : to[v]) {
    //             if (dist[u] != INF) continue;
    //             dist[u] = dist[v] + 1;
    //             cnt[i][dist[u]] += u+1;
    //             if (dist[u] < 3) q.push(u);
    //         }
    //     }
    // }
    int q;
    cin >> q;
    rep(qi,q) {
        int x, k;
        cin >> x >> k;
        x--;
        int ans = 0;
        // vector<int> dist(n,INF);
        map<int,int> mp;
        queue<int> q;
        mp[x] = 0;
        q.push(x);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ans += v+1;
            if (mp[v] == k) continue;
            for (int u : to[v]) {
                if (mp.count(u)) continue;
                mp[u] = mp[v] + 1;
                q.push(u);
            }
        }
        cout << ans << endl;
    }
    return 0;
}