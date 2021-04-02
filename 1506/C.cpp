#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    string a, b;
    cin >> a >> b;
    int dp[21][21];
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        if (i == 0 || j == 0) dp[i][j] = a[i] == b[j] ? 1 : 0;
        else dp[i][j] = a[i] == b[j] ? dp[i - 1][j - 1] + 1 : 0;
      }
    }
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        maxLen = max(maxLen, dp[i][j]);
      }
    }
    cout << a.size() + b.size() - maxLen * 2 << endl;
  }
  return 0;
}