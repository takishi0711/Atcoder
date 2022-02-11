#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double PI = acos(-1);

const int MAX_N = 200005;
using mint = modint1000000007;

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    //assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} comb(1000005);

// Rerooting
// https://youtu.be/zG1L4vYuGrg?t=7092
// TODO: vertex info, edge info
struct Rerooting {
  struct DP {
    mint dp;
    int t;
    DP(mint dp=1, int t=0):dp(dp),t(t) {}
    DP operator+(const DP& a) const {
      // edit here
      return DP(dp*a.dp*comb(t+a.t, t), t+a.t);
    }
    DP addRoot() const {
      // edit here
      return DP(dp, t+1);
    }
  };
  
  int n;
  vector<vector<int>> to;
  vector<vector<DP>> dp;
  vector<DP> ans;
  Rerooting(int n=0):n(n),to(n),dp(n),ans(n) {}
  void addEdge(int a, int b) {
    to[a].push_back(b);
    to[b].push_back(a);
  }
  void init() {
    dfs(0);
    bfs(0);
  }

  DP dfs(int v, int p=-1) {
    DP dpSum;
    dp[v] = vector<DP>(to[v].size());
    rep(i,to[v].size()) {
      int u = to[v][i];
      if (u == p) continue;
      dp[v][i] = dfs(u,v);
      dpSum = dpSum + dp[v][i];
    }
    return dpSum.addRoot();
  }
  void bfs(int v, const DP& dpP=DP(), int p=-1) {
    int deg = to[v].size();
    rep(i,deg) if (to[v][i] == p) dp[v][i] = dpP;

    vector<DP> dpSumL(deg+1);
    rep(i,deg) dpSumL[i+1] = dpSumL[i] + dp[v][i];
    vector<DP> dpSumR(deg+1);
    for (int i = deg-1; i >= 0; --i)
      dpSumR[i] = dpSumR[i+1] + dp[v][i];
    ans[v] = dpSumL[deg].addRoot();

    rep(i,deg) {
      int u = to[v][i];
      if (u == p) continue;
      DP d = dpSumL[i] + dpSumR[i+1];
      bfs(u, d.addRoot(), v);
    }
  }
};


int main() {
    int n;
    cin >> n;
    Rerooting g(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.addEdge(a,b);
    }    
    g.init();
    rep(i,n) {
        cout << g.ans[i].dp.val() << endl;
    }
    return 0;
}