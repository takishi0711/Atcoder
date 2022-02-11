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



int main() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    int sti = 0, stj = 0;
    bool ok1 = false;
    rep(i,n) {
        rep(j,n){
            if (s[i][j] == '#') {
                sti = i; stj = j;
                ok1 = true;
                break;
            }    
        }
        if (ok1) break;
    }
    int cnts = 0, cntt = 0;
    rep(i,n)rep(j,n) {
        if (s[i][j] == '#') cnts++;
        if (t[i][j] == '#') cntt++;
    }
    if (cnts != cntt) {
        cout << "No" << endl;
        return 0;
    }
    rep(_,4) {
        vector<string> t2(n);
        bool ok = false;
        int stit = 0, stjt = 0;
        bool ok2 = false;
        rep(i,n) {
            rep(j,n){
                if (t[i][j] == '#') {
                    stit = i; stjt = j;
                    ok1 = true;
                    break;
                }    
            }
            if (ok2) break;
        }
        int subi = stit-sti, subj = stjt-stj;
        rep(i,n)rep(j,n) {
            if (ok == false) {
                t2[i][j] = '.';
                if (j == stj && i == sti) {
                    int ni = i+subi, nj = j+subj;
                    t2[i][j] = t[ni][nj];
                    ok = true;
                }
            } else {
                int ni = i+subi, nj = j+subj;
                if (ni<0||ni>=n||nj<0||nj>=n) {
                    t2[i][j] = '.';
                    continue;
                }
                t2[i][j] = t[ni][nj];
            }
        }
        if (s == t2) {
            cout << "Yes" << endl;
            return 0;
        }
        vector<string> t3(n);
        rep(i,n)rep(j,n) {
            t3[i][j] = t[n-j-1][i]; 
        }
        t = t3;
    }
    cout << "No" << endl;
    return 0;
}