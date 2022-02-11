#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;
using ll = long long;



int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N), b(N);

    vector<multiset<int>> s(200005);
    multiset<int> maxs;

    auto getMax = [&](int i) {
        if (s[i].size() == 0) return -1;
        return *(s[i].rbegin());
    };
    auto addYochien = [&](int i) {
        int x = getMax(i);
        if (x == -1) return;
        maxs.insert(x);
    };
    auto delYochien = [&](int i) {
        int x = getMax(i);
        if (x == -1) return;
        maxs.erase(maxs.find(x));
    };
    auto addEnji = [&](int i, int x) {
        delYochien(i);
        s[i].insert(x);
        addYochien(i);
    };
    auto delEnji = [&](int i, int x) {
        delYochien(i);
        s[i].erase(s[i].find(x));
        addYochien(i);
    };

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        addEnji(b[i], a[i]);
    }

    for (int i = 0; i < Q; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        delEnji(b[c], a[c]);
        b[c] = d;
        addEnji(b[c], a[c]);
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }
    return 0;
}