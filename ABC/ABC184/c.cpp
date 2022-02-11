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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c && b == d) {
        cout << 0 << endl;
        return 0;
    }
    else if (abs(a-c) == abs(b-d)) {
        cout << 1 << endl;
        return 0;
    } 
    else if (abs(a-c)+abs(b-d) <= 3) {
        cout << 1 << endl;
        return 0;
    }
    else if ((a+b)%2 == (c+d)%2) {
        cout << 2 << endl;
        return 0;
    }
    else {
        for (int i = -3; i <= 3; i++) {
            for (int j = -3; j <= 3; j++) {
                if (abs(i)+abs(j) > 3) continue;
                if (abs(a-(c+i)) == abs(b-(d+j))) {
                    cout << 2 << endl;
                    return 0;
                }
            }
        }
        cout << 3 << endl;
        return 0;
    }
    return 0;
}