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
    ll a, b, c;
    cin >> a >> b >> c;
    vector<bool> used(10);
    vector<int> loop;
    int w = 0;
    loop.push_back(a%10);
    while (used[loop[w]] == false) {
        used[loop[w]] = true;
        loop.push_back((loop[w]*loop[w])%10);
        w++;
    }
    loop.pop_back();
    int n = loop.size();
    cout << n << endl;
    rep(i,n) cout << loop[i];
    cout << endl;
    return 0;
}