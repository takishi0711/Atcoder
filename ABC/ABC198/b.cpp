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
    if (s == "0") {
        cout << "Yes" << endl;
        return 0;
    }
    reverse(s.begin(), s.end());
    int x = 0;
    while (s[x] == '0') x++;
    s = s.substr(x);
    int n = s.size();
    int l = 0, r = n-1;
    while (l < r) {
        if (s[l] != s[r]) {
            cout << "No" << endl;
            return 0;
        }
        l++; r--;
    }
    cout << "Yes" << endl;
    return 0;
}