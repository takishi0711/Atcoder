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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s_cp = s;
    int n_cp = n;
    vector<int> ans(3*n);
    rep(_,6) {
        bool flag1 = false;
        bool flag2 = false;
        if (s[0] == 'B') {
            rep(i,3*n) {
                if (s[i] == 'B') s[i] = 'A';
                else if (s[i] == 'A') s[i] = 'B';
            }
            flag1 = true;
        } else if (s[0] == 'C') {
            rep(i,3*n) {
                if (s[i] == 'C') s[i] = 'A';
                else if (s[i] == 'A') s[i] = 'C';
            }
            flag2 = true;
        }
        vector<int> a(3*n), b(3*n), c(3*n);
        rep(i,3*n) {
            if (s[i] == 'A') a[i]++;
            if (s[i] == 'B') b[i]++;
            if (s[i] == 'C') c[i]++;
            if (i != 3*n-1) {
                a[i+1] += a[i];
                b[i+1] += b[i];
                c[i+1] += c[i];
            }
        }
        int cnt = 0;
        char fi = s[0];
        char se, th;
        for (int i = 1; i <= n; i++) {
            bool ok1 = false;
            bool ok2 = false;
            int idx3_1, idx3_2;
            {
                // se = 'B';
                // th = 'C';
                int idx1 = lower_bound(a.begin(), a.end(), i)-a.begin();
                int idx2 = lower_bound(b.begin(), b.end(), i+b[idx1])-b.begin();
                if (idx2 < 3*n) {
                    idx3_1 = lower_bound(c.begin(), c.end(), i+c[idx2])-c.begin();
                    if (idx3_1 < 3*n) ok1 = true;
                }                
            }
            {
                // se = 'C';
                // th = 'B';
                int idx1 = lower_bound(a.begin(), a.end(), i)-a.begin();
                int idx2 = lower_bound(c.begin(), c.end(), i+c[idx1])-c.begin();
                if (idx2 < 3*n) {
                    idx3_2 = lower_bound(b.begin(), b.end(), i+b[idx2])-b.begin();
                    if (idx3_2 < 3*n) ok2 = true;
                }     
            }
            if (ok1 || ok2) {
                if (ok1 && ok2) {
                    if (idx3_1 > idx3_2) {
                        se = 'B';
                        th = 'C';
                    }  else {
                        se = 'C';
                        th = 'B';
                    }
                } else if (ok1) {
                    se = 'B';
                    th = 'C';
                } else {
                    se = 'C';
                    th = 'B';
                }
                cnt = i;
            } else {
                break;
            }
        }
        string s1(cnt, 'A');
        string s2(cnt, se);
        string s3(cnt, th);
        if (flag1) {
            if (se == 'B') swap(s1,s2);
            else swap(s1,s3);
        }
        if (flag2) {
            if (se == 'C') swap(s1,s2);
            else swap(s1,s3);
        }
        string t = s1+s2+s3;
        int pos = 0;
        string nex = "";
        rep(i,3*n_cp) {
            if (ans[i]) continue;
            if (pos == 3*cnt) {
                nex.push_back(s_cp[i]);
            } else {
                if (s_cp[i] == t[pos]) {
                    pos++;
                    ans[i] = _+1;
                }
                else nex.push_back(s_cp[i]);
            }
        }
        s = nex;
        n -= cnt;
        if (s.size() == 0) break;
    }
    rep(i,3*n_cp) {
        if (i == 3*n_cp-1) cout << ans[i] << endl;
        else cout << ans[i];
    }
    return 0;
}