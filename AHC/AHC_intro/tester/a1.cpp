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

int Next_Score(int now, vector<int> c, vector<vector<int>> s, int t, vector<int> last) {
    int score = 0;
    score += s[now][t];
    last[t] = now+1;
    rep(i,26) {
        score -= c[i]*(now+1 - last[i]);
    }    
    return score;
}

int main() {
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i,26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i,d)rep(j,26) cin >> s[i][j];
    
    vector<int> last(26);
    rep(i,d) {
        int score_sub = -INF;
        int t;
        rep(j,26) {
            int now = Next_Score(i, c, s, j, last);
            if (now > score_sub) {
                score_sub = now;
                t = j;
            } 
        }
        last[t] = i+1;
        cout << t+1 << endl;
    }
    return 0;
}