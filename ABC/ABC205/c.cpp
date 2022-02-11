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
    ll a, b, c;
    cin >> a >> b >> c;
    if (c%2 == 0) {
        if (abs(a) < abs(b)) {
            cout << "<" << endl;
        } else if (abs(a) > abs(b)) {
            cout << ">" << endl;
        } else {
            cout << "=" << endl;
        }
    } else {
        if (a <= 0) {
            if (b <= 0) {
                if (abs(a) < abs(b)) {
                    cout << ">" << endl;
                } else if (abs(a) > abs(b)) {
                    cout << "<" << endl;
                } else {
                    cout << "=" << endl;
                }
            } else {
                cout << "<" << endl;
            }
        } else {
            if (b <= 0) {
                cout << ">" << endl;
            } else {
                if (abs(a) < abs(b)) {
                    cout << "<" << endl;
                } else if (abs(a) > abs(b)) {
                    cout << ">" << endl;
                } else {
                    cout << "=" << endl;
                }
            }
        } 
    }
    return 0;
}