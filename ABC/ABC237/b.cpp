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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    deque<int> d;
    d.push_back(n);
    rep(i,n) {
        int x = n-1 - i;
        if (s[i] == 'L') d.push_back(x);
        else d.push_front(x);
    }
    rep(i,d.size()) {
        if (i == d.size()-1) cout << d[i] << endl;
        else cout << d[i] << " ";
    }
    return 0;
}