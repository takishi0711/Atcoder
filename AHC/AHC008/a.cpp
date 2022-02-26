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

// vector<vector<int>> G(30, vector<int>(30));
int G1[35][35]; // pet
int G2[35][35]; // human
int px[25], py[25], pt[25];
int hx[15], hy[15];
int n, m;

int main() {
    cin >> n;
    rep(i,n) {
        cin >> px[i] >> py[i] >> pt[i];
        px[i]--; py[i]--;
        G1[px[i]][py[i]]++;
    }
    cin >> m;
    rep(i,m) {
        cin >> hx[i] >> hy[i];
        hx[i]--; hy[i]--;
        G2[hx[i]][hy[i]]++;
    }

    rep(_,300) {
        string move_human;
        rep(man,m) {
            int i = hx[man], j = hy[man];
            bool ok = false;
            rep(dir,4) {
                int ni = i+di[dir], nj = j+dj[dir];
                if (ni<0||ni>=30||nj<0||nj>=30) continue;
                if (G1[ni][nj] == 0 && G2[ni][nj] == 0) {
                    bool okpet = true;
                    rep(dir2,4) {
                        int nni = ni+di[dir2], nnj = nj+dj[dir2];
                        if (nni<0||nni>=30||nnj<0||nnj>=30) continue;
                        if (G1[nni][nnj] > 0) okpet = false;
                    }
                    if (okpet) {
                        ok = true;
                        if (dir == 0) {
                            move_human += "u";
                        } else if (dir == 1) {
                            move_human += "l";
                        } else if (dir == 2) {
                            move_human += "d";
                        } else {
                            move_human += "r";
                        }
                        G1[ni][nj] = -1;
                        G2[ni][nj] = -1;
                        break;
                    }
                }
            }
            if (ok == false) move_human += ".";
        }
        cout << move_human << endl;

        rep(pet, n) {
            string move_pet;
            cin >> move_pet;
            G1[px[pet]][py[pet]]--;
            for (char c : move_pet) {
                if (c == 'U') {
                    px[pet]--;
                } else if (c == 'L') {
                    py[pet]--;
                } else if (c == 'D') {
                    px[pet]++;
                } else if (c == 'R') {
                    py[pet]++;
                } else {
                    // '.' のとき
                }
            }
            G1[px[pet]][py[pet]]++;
        }
    }
    return 0;
}