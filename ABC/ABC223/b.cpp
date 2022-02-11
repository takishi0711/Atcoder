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
    int n = s.size();
    vector<string> vec;
    rep(i,n+1) {
        vec.push_back(s);
        s = s.substr(1) + s[0];
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] << endl;
    cout << vec.back() << endl;
    return 0;
}