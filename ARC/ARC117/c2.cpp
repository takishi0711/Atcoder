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

char f(char a, char b) {
    if (a == 'B' && b == 'W') return 'R';
    if (a == 'B' && b == 'R') return 'W';
    if (a == 'B' && b == 'B') return 'B';
    if (a == 'W' && b == 'W') return 'W';
    if (a == 'W' && b == 'R') return 'B';
    if (a == 'W' && b == 'B') return 'R';
    if (a == 'R' && b == 'W') return 'B';
    if (a == 'R' && b == 'R') return 'R';
    if (a == 'R' && b == 'B') return 'W';
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() < 4) {
        while (s.size() != 1) {
            string s2;
            int x = s.size();
            rep(i,x-1) {
                s2 += f(s[i], s[i+1]);
            }
            s = s2;
        }
        cout << s << endl;
    } else {
        while (1) {
            int x = s.size();
            int y = x;
            while (y%3 == 0) {
                y /= 3;
            }
            if (y == 1) break;
            string s2;
            rep(i,x-1) {
                s2 += f(s[i], s[i+1]);
            }
            s = s2;
        }
        char ans = f(s[0], s.back());
        cout << ans << endl;
    }
    return 0;
}