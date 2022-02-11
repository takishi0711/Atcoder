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
    vector<vector<int>> x(10);
    for (int i = 1; i <= 9; i++) {
        if (i == 1) {
            x[i].push_back(1);
        }
        if (i == 2) {
            x[i].push_back(2);
            x[i].push_back(4);
            x[i].push_back(8);
            x[i].push_back(6);
        }
        if (i == 3) {
            x[i].push_back(3);
            x[i].push_back(9);
            x[i].push_back(7);
            x[i].push_back(1);
        }
        if (i == 4) {
            x[i].push_back(4);
            x[i].push_back(6);
        }
        if (i == 5) {
            x[i].push_back(5);
        }
        if (i == 6) {
            x[i].push_back(6);
        }
        if (i == 7) {
            x[i].push_back(7);
            x[i].push_back(9);
            x[i].push_back(3);
            x[i].push_back(1);
        }
        if (i == 8) {
            x[i].push_back(8);
            x[i].push_back(4);
            x[i].push_back(2);
            x[i].push_back(6);
        }
        if (i == 9) {
            x[i].push_back(9);
            x[i].push_back(1);
        }
    }
    int n = a%10;
    int y1 = x[n].size();
    int z1 = b%y1;
    if (z1 == 0) {
        cout << x[n].back() << endl;
        return 0;
    }
    vector<int> loop2;
    loop2.push_back(z1);
    vector<bool> used(10);
    int w = 0;
    while (used[loop2[w]] == false) {
        used[loop2[w]] = true;
        loop2.push_back((loop2[w]*loop2[w])%y1);
        w++;
    }
    loop2.pop_back();
    int m = loop2.size();
    int z = (c%m + m-1)%m;
    int v = loop2[z];
    int ans = x[n][v-1];
    cout << ans << endl;
    return 0;
}