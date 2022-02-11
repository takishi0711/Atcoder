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
    string s;
    cin >> s;
    deque<char> deq;
    int rev = 0;
    int n = s.size();
    rep(i,n) {
        if (s[i] == 'R') rev ^= 1;
        else {
            if (rev) deq.push_front(s[i]);
            else deq.push_back(s[i]);
        }
    }
    string ans = "";
    n = deq.size();
    if (rev) reverse(deq.begin(), deq.end());
    rep(i,n) {
        ans += deq[i];
        if (ans.size() >= 2) {
            int m = ans.size();
            if (ans[m-1] == ans[m-2]) {
                ans.erase(ans.begin()+int(ans.size())-2, ans.end());
            }
        }
    }
    //ans = ans.substr(0,(int)ans.size()-1);
    cout << ans << endl;
    return 0;
}