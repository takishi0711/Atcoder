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
    int a, b;
    cin >> a >> b;
    vector<int> sei, hu;
    for (int i = 1; i <= a; i++) sei.push_back(i);
    for (int i = 1; i <= b; i++) hu.push_back(-i);
    int suma = 0, sumb = 0;
    rep(i,a) suma += sei[i];
    rep(i,b) sumb -= hu[i];
    if (a < b) {
        sei.back() += sumb-suma;
    } else if (a > b) {
        hu.back() -= suma-sumb;
    } 
    rep(i,a) cout << sei[i] << " ";
    rep(i,b) cout << hu[i] << " ";
    cout << endl;
    return 0;
}