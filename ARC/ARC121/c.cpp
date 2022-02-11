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
    int t;
    cin >> t;
    rep(ti,t) {
        int n;
        cin >> n;
        vector<int> p(n+1);
        vector<int> num(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            num[p[i]] = i;
        }
        int now = 1;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (num[i] == i) continue;
            if ((num[i]-1)%2 == now%2) {
                for (int j = num[i]-1; j >= i; j--) {
                    ans.push_back(j);
                    swap(p[j], p[j+1]);
                    swap(num[p[j]], num[p[j+1]]);
                    now++;
                }
            } else {
                bool ok = false;
                for (int j = i; j < n; j++) {
                    if (j != num[i] && j%2 == now%2) {
                        ans.push_back(j);
                        swap(p[j], p[j+1]);
                        swap(num[p[j]], num[p[j+1]]);
                        now++;                 
                        ok = true;
                        break;       
                    }
                }
                if (ok) {
                    for (int j = num[i]-1; j >= i; j--) {
                        ans.push_back(j);
                        swap(p[j], p[j+1]);
                        swap(num[p[j]], num[p[j+1]]);
                        now++;
                    }                    
                } else {
                    if (num[i] == n) {
                        ans.push_back(n-2);
                        swap(p[n-2], p[n-1]);
                        swap(num[p[n-2]], num[p[n-1]]);
                        now++;
                        ans.push_back(n-1);
                        swap(p[n-1], p[n]);
                        swap(num[p[n-1]], num[p[n]]);
                        now++;
                        ans.push_back(n-2);
                        swap(p[n-2], p[n-1]);
                        swap(num[p[n-2]], num[p[n-1]]);
                        now++;
                        ans.push_back(n-1);
                        swap(p[n-1], p[n]);
                        swap(num[p[n-1]], num[p[n]]);
                        now++;
                        ans.push_back(n-2);
                        swap(p[n-2], p[n-1]);
                        swap(num[p[n-2]], num[p[n-1]]);
                        now++;
                    } else {
                        int x = num[i];
                        ans.push_back(x);
                        swap(p[x], p[x+1]);
                        swap(num[p[x]], num[p[x+1]]);
                        now++;
                        ans.push_back(x-1);
                        swap(p[x-1], p[x]);
                        swap(num[p[x-1]], num[p[x]]);
                        now++;
                        ans.push_back(x);
                        swap(p[x], p[x+1]);
                        swap(num[p[x]], num[p[x+1]]);
                        now++;
                        for (int j = num[i]-1; j >= i; j--) {
                            ans.push_back(j);
                            swap(p[j], p[j+1]);
                            swap(num[p[j]], num[p[j+1]]);
                            now++;
                        }                            
                    }
                }
            }
        }
        cout << ans.size() << endl;
        rep(i,ans.size()) {
            if (i == ans.size()-1) cout << ans[i] << endl;
            else cout << ans[i] << " ";
        }
    }
    return 0;
}