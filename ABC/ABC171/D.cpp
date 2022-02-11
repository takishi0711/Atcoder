#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  vector<int> num(100000);
  int64_t sum = 0;
  for (int i = 0; i < N; i++) {
      cin >> vec.at(i);
      num.at(vec.at(i) - 1)++;
      sum += vec.at(i);
  }
  
  int Q;
  cin >> Q;
  vector<int> b(Q);
  vector<int> c(Q);
  for (int i = 0; i < Q; i++) cin >> b.at(i) >> c.at(i);
  
  for (int i = 0; i < Q; i++) {
      sum += (c.at(i) - b.at(i)) * num.at(b.at(i) - 1);
      cout << sum << endl;
      num.at(c.at(i) - 1) += num.at(b.at(i) - 1);
      num.at(b.at(i) - 1) = 0;
  }
}
