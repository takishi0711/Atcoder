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



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    bool ok = false;
    stack<string> q;
    rep(i,n) {
        if (s[i] == 'f' && !ok) {
            ok = true;
            q = stack<string>();
            q.push("f");
        } 
        else if (ok && s[i] == 'f') {
            q.push("f");
        }
        else if (ok && s[i] == 'o') {

            string t;
            t = q.top(); q.pop();
            if (t == "f") q.push("fo");
            else ok = false;
        } 
        else if (ok && s[i] == 'x') {
            string t;
            t = q.top(); q.pop();
            if (t == "fo") {
                cnt++;
                if (q.size() == 0) ok = false;
            }
            else ok = false;
        }
        else ok = false;
    }
    int ans = n - cnt*3;
    cout << ans << endl;
    return 0;
}