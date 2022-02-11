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
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s.size() == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    rep(i,s.size()-1) {
        int a1 = s[i]-'a';
        int a2 = s[i+1]-'a';
        int b1 = t[i]-'a';
        int b2 = t[i+1]-'a';
        if ((a2-a1+26)%26 != (b2-b1+26)%26) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}