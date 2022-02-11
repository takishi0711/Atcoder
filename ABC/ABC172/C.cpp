#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    ll sum = 0;
    int num = 0;
    int x = 0, y = 0;
    bool t = true;
    while (sum < k) {
        if (x < n && y < m) {
            if (a[x] < b[y]) {
                sum += a[x];
                x++;
                num++;
            }
            else {
                sum += b[y];
                y++;
                num++;
            }
        }
        else if (!(x < n) && y < m) {
            sum += b[y];
            y++;
            num++;
        }
        else if (x < n && !(y < m)) {
            sum += a[x];
            x++;
            num++;
        }
        else {
            t = false;
            break;
        }

        if (sum == k) {
            t = false;
            break;
        }
    }

    if (t) cout << --num << endl;
    else cout << num << endl; 
}