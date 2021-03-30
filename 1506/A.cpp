#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, m, x;
    cin >> n >> m >> x;
    long long j = (x - 1) / n;
    long long i = (x - 1) % n;
    cout << i * m + j + 1 << endl;
  }
  return 0;
}