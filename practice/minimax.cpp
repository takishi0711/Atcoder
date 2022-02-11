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

//ABC025 C ミニマックス法

char A[3][3];
int b[2][3];
int c[3][2];

int calc() {
    int score = 0;
    rep(i,2)rep(j,3) if (A[i][j] == A[i+1][j]) score += b[i][j]; 
    rep(i,3)rep(j,2) if (A[i][j] == A[i][j+1]) score += c[i][j];
    return score; 
}

int dfs(int turn) {
    if (turn == 9) return calc();

    if (turn%2 == 0) {
        int mx = -1;
        rep(i,3)rep(j,3) {
            if (A[i][j] != '*') continue;
            A[i][j] = 'o';
            mx = max(mx, dfs(turn+1));
            A[i][j] = '*';
        }
        return mx;
    } else {
        int mn = INF;
        rep(i,3)rep(j,3) {
            if (A[i][j] != '*') continue;
            A[i][j] = 'x';
            mn = min(mn, dfs(turn+1));
            A[i][j] = '*';
        }
        return mn;
    }
}

int main() {
    int sum = 0;
    rep(i,2)rep(j,3) {
        cin >> b[i][j];
        sum += b[i][j];
    } 
    rep(i,3)rep(j,2) {
        cin >> c[i][j];
        sum += c[i][j];
    }

    fill(A[0], A[3], '*');

    int chokudai = dfs(0);
    cout << chokudai << endl;
    cout << sum-chokudai << endl;
    return 0;
}