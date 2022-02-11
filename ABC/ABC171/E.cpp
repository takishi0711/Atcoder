#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a.at(i); 
        sum ^= a.at(i);
    }
    
    for (int i = 0; i < N; i++) {
        int b = sum ^ a.at(i);
        cout << b << ' ';
    }
    cout << endl;
}