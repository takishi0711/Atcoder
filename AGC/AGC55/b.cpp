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

vector<int> a(500005), b(500005);
int n;

bool dfs(int i, int x) {
    if (a[i] == x) {
        return true; 
    }
    if (i > n-3) return false;
    if (dfs(i+1, (a[i]+1)%3) && dfs(i+2, (a[i]+2)%3)) {
        a[i] = x; a[i+1] = (x+1)%3; a[i+2] = (x+2)%3;
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    rep(i,n) {
        if (s[i] == 'A') a[i] = 0;
        if (t[i] == 'A') b[i] = 0;
        if (s[i] == 'B') a[i] = 1;
        if (t[i] == 'B') b[i] = 1;
        if (s[i] == 'C') a[i] = 2;
        if (t[i] == 'C') b[i] = 2;
    }
    vector<int> cnta(3), cntb(3);
    vector<int> sub(n);
    rep(i,n) {
        cnta[a[i]]++;
        cntb[b[i]]++;
        sub[i] = (b[i]+3 - a[i])%3;
    }
    rep(i,3) {
        if (cnta[i] != cntb[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    rep(i,n-2) {
        if (i != n-3) {
            sub[i+1] = (sub[i+1]-sub[i]+3)%3;
            sub[i+2] = (sub[i+2]-sub[i]+3)%3;
        } else {
            if (sub[i] == sub[i+1] && sub[i+1] == sub[i+2]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    rep(i,n) {
        if (dfs(i, b[i]) == false) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}