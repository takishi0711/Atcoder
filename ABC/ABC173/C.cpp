#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int ans = 0;

    for (int is = 0; is < 1<<h; is++) {
        for (int js = 0; js < 1<<w; js++) {
            int cnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (is>>i&1) continue;
                    if (js>>j&1) continue;
                    if (s[i][j] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}