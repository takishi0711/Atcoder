#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (l[i] == l[j]) continue;
                if (l[j] == l[k]) continue;
                if (l[k] == l[i]) continue;
                if (l[i]+l[j]>l[k] && l[i]+l[k]>l[j] && l[k]+l[j]>l[i]) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}