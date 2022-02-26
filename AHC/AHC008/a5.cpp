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

int dist(int si, int sj, int gi, int gj) {
    return abs(si-gi) + abs(sj-gj);
}

char f1(int id, int si, int sj, int gi, int gj) {
    int dist_now = dist(si,sj,gi,gj);
    rep(dir,4) {
        int ni = si+di[dir], nj = sj+dj[dir];
        if (ni<0||ni>=30||nj<0||nj>=30) continue;
        int dist_next = dist(ni,nj,gi,gj);
        if (dist_next < dist_now) {
            G2[si][sj]--;
            G2[ni][nj]++;
            hx[id] = ni;
            hy[id] = nj;
            if (dir == 0) {
                return 'U';
            } else if (dir == 1) {
                return 'L';
            } else if (dir == 2) {
                return 'D';
            } else {
                return 'R';
            }            
        }
    }
    return '.';
}

bool petok(int i, int j) {
    if (G1[i][j] > 0) return false;
    rep(dir,4) {
        int ni = i+di[dir], nj = j+dj[dir];
        if (ni<0||ni>=30||nj<0||nj>=30) continue;
        if (G1[ni][nj] > 0) return false;
    }
    return true;
}

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
    
    bool prepar = true;
    set<int> prepar_done;

    rep(_,300) {
        string move_human;
        if (prepar) { // 全ての人間がまだ定位置に到着してない
            rep(man,m) {
                move_human += f1(man, hx[man], hy[man], 0, goal_col[man]);
                if (hx[man] == 0 && hy[man] == goal_col[man]) {
                    prepar_done.insert(man);
                }
            }
            if (prepar_done.size() == m) prepar = false;
        } else { // 準備オッケー
            rep(man,m) {
                if (hy[man] == 29) move_human += '.';
                else {
                    int i = hx[man], j = hy[man];
                    if (G1[i][j+1] == -1) {
                        if (i == 29) move_human += '.';
                        else {
                            move_human += 'D';
                            G2[i][j]--;
                            G2[i+1][j]++;
                            hx[man]++;
                        }
                    }
                    else {
                        if (petok(i, j+1)) {
                            move_human += 'r';
                            G1[i][j+1] = -1;
                            G2[i][j+1] = -1;
                        }
                        else move_human += '.';
                    }
                }
            }
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