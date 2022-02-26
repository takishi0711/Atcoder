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



int main() {
    int m = 8;
    int m2 = 4;

    int all_col = 30-(m2-1);
    vector<int> space_col;
    rep(i,m2) {
        int x = (all_col+m2-i-1)/(m2-i);
        all_col -= x;
        space_col.push_back(x);
    }

    vector<int> goal_col_m2(m2);
    int pos = space_col[0]-1;
    rep(i,m2) {
        goal_col_m2[i] = pos;
        if (i != m2-1) {
            pos++;
            pos += space_col[i+1];
        }
    }
    
    vector<int> distribution(m2);
    rep(i,m2) {
        distribution[i] = (m+i)/m2;
    }
    reverse(distribution.begin(), distribution.end());
    vector<int> goal_col;
    rep(i,m2) {
        rep(j,distribution[i]) goal_col.push_back(goal_col_m2[i]);
    }
    rep(i,m) cout << goal_col[i] << " ";
    cout << endl;
    return 0;
}