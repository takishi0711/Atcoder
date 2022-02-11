#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
    int h, w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--; cw--; dh--; dw--;
    vector<vector<char>> s(h, vector<char>(w));
    rep(si,h)rep(sj,w) cin >> s[si][sj];
    vector<vector<int>> mark(h, vector<int>(w, -1));
    int k = 0;
    rep(si,h)rep(sj,w) {
        if (s[si][sj] == '#') continue;
        if (mark[si][sj] != -1) continue;
        queue<P> q;
        auto update = [&](int i, int j, int x) {
            if (mark[i][j] != -1) return;
            mark[i][j] = x;
            q.push(P(i,j));
        };
        update(si,sj,k);
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second; q.pop();
            rep(dir,4) {
                int ni = i+di[dir], nj = j+dj[dir];
                if (ni<0||ni>=h||nj<0||nj>=w) continue;
                if (s[ni][nj] == '#') continue;
                update(ni, nj, k);
            }
        }
        k++;
    }
    queue<P> q;
    auto update = [&](int i, int j) {
        if (mark[i][j] != -1) return;
        //mark[i][j] = x;
        q.push(P(i,j));
    };
    update(ch, cw);
    int woop = 0;
    int dmark = mark[dh][dw];
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second; q.pop();
        if (mark[i][j] == dmark) {
            
        }
        for (int is = -2; is <= 2; is++) {
            for (int js = -2; js <= 2; js++) {
                int ni = i+is, nj = j+js;
                if (ni<0||ni>=h||nj<0||nj>=w) continue;
                if (s[ni][nj] == '#') continue;
                if (mark[ni][nj] != mark[i][j]) {
                    update(ni, nj);
                    woop++;
                }
            }
        }
    }
    return 0;
}