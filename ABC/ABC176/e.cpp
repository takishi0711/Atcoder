#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int H, W, m;
    cin >> H >> W >> m;
    map<int, int> hmp, wmp;
    map<P, int> x;
    int hmax = 0, wmax = 0;
    int indh = 0, indw = 0;
    rep(i,m) {
        int h, w;
        cin >> h >> w;
        h--; w--;
        x[P(h,w)]++;
        hmp[h]++;
        if (hmp[h] > hmax) {
            //indh = h;
            hmax = hmp[h];
        }
        wmp[w]++;
        if (wmp[w] > wmax) {
            //indw = w;
            wmax = wmp[w];
        }
    } 
    vector<int> hm, wm;
    rep(i,H) {
        if (hmp[i] == hmax) hm.push_back(i);
    }
    rep(i,W) {
        if (wmp[i] == wmax) wm.push_back(i);
    }
    int ans = hmax + wmax;
    rep(i,hm.size())rep(j,wm.size()) {
        if (x[P(hm[i],wm[j])] != 1) {
            cout << ans << endl;
            return 0; 
        }
    }
    cout << ans-1 << endl;
    return 0;
}