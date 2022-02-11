#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);
    rep(i,n) {
        int point;
        cin >> point;
        point--;
        p[i] = point;
    }
    rep(i,n) cin >> c[i];
    vector<ll> issyu(n);
    vector<bool> issyu_ok(n, false);
    vector<int> loop(n);
    ll ans = 0;
    rep(i,n) {
        if (issyu_ok[i]) {
            issyu[i] = issyu[issyu[i]];
            loop[i] = loop[loop[i]];
        }
        else {
            int ip = i;
            ll sum = 0;
            ip = p[ip];
            int l = 0;
            while (!(issyu_ok[ip])) {
                sum += c[ip];
                issyu_ok[ip] = true;
                issyu[ip] = i;
                loop[ip] = i;
                ip = p[ip];
                l++;
            }
            issyu[i] = sum;
            loop[i] = l;
        }
        if (issyu[i] <= 0) {
            ll sum = 0;
            int ip = i;
            ip = p[ip];
            rep(j,5000) {
                sum += c[ip];
                ans = max(ans, sum);
                ip = p[ip];
            }
        }
        if (issyu[i] > 0) {
            ll sum = (ll)(k/loop[i]) * issyu[i];
            int ip = i;
            ip = p[ip];
            ans = max(ans, sum);
            rep(j,k%loop[i]) {
                sum += c[ip];
                ans = max(ans, sum);
                ip = p[ip];
            }
        }
    }
    cout << ans << endl;
    return 0;
}