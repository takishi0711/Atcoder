#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1; a*a < n; a++) {
        for (int b = a; b < n; b++) {
            if (a*b >= n) break;
            ans++;
        }
    }
    ans *= 2;
    for (int i = 1; i*i < n; i++) {
        ans--;
    }
    cout << ans << endl;
    return 0;
}