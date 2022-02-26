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

int n;
vector<int> to[200005];
vector<int> ansL(200005), ansR(200005);
int num = 1;

void dfs(int v, int p=-1) {
    if (p != -1 && to[v].size() == 1) {
        ansL[v] = ansR[v] = num;
        num++;
    } else {
        int mi = INF, ma = 0;
        for (int u : to[v]) {
            if (u == p) continue;
            dfs(u,v);
            chmin(mi, ansL[u]);
            chmin(mi, ansR[u]);
            chmax(ma, ansL[u]);
            chmax(ma, ansR[u]);
        }       
        ansL[v] = mi;
        ansR[v] = ma; 
    }
}

// void dfs(int v, int p=-1) {
//     int mi = INF, ma = 0;
//     for (int u : to[v]) {
//         if (u == p) continue;
//         dfs(u,v);
//         chmin(mi, ansL[u]);
//         chmin(mi, ansR[u]);
//         chmax(ma, ansL[u]);
//         chmax(ma, ansR[u]);
//     }  
//     if (mi == INF && ma = 0) {
//         ansL[v] = ansR[v] = num;
//         num++;
//     } else {
//         ansL[v] = mi;
//         ansR[v] = ma; 
//     }     
        
// }

int main() {
    cin >> n;
    rep(i,n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(0);
    rep(i,n) {
        cout << ansL[i] << " " << ansR[i] << endl;
    }
    return 0;
}