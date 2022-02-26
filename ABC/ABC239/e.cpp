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

vector<int> x(100005);
vector<int> to[100005];

vector<multiset<int>> stvec(100005);

void dfs(int v, int p=-1) {
    stvec[v].insert(x[v]);
    for (int u : to[v]) {
        if (u == p) continue;
        dfs(u,v);
        auto it = stvec[u].rbegin();
        rep(i,20) {
            if (stvec[v].size() == 20) {
                if (*stvec[v].begin() < *it) {
                    stvec[v].insert(*it);
                } else {
                    break;
                }
            } else {
                stvec[v].insert(*it);
            }
            it++;
            if (it == stvec[u].rend()) break;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    rep(i,n) cin >> x[i];
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0);
    rep(qi,q) {
        int v, k;
        cin >> v >> k;
        v--; k--;
        auto it = stvec[v].rbegin();
        rep(i,k) it++;
        cout << *it << endl;
    }
    return 0;
}