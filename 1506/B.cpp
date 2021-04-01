#include <iostream>
#include <string>

using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k, ans = 0;
    string s;
    cin >> n >> k >> s;
    int len = s.size();
    int left = 0, right = len - 1;
    while (left < len && s[left] != '*') left++; 
    while (right >= 0 && s[right] != '*') right--;
    if (left == right) {
      cout << 1 << endl;
      continue;
    } else {
      ans += 2;
      int index = left + k;
      while (index < right) {
        if (s[index] == '.') {
          while (index > left && s[index] == '.') index--;
          if (index == left) return 0;
        }
        ans++;
        index += k;
      }
    }
    cout << ans << endl;
  }
  return 0;
}