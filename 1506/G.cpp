// 04/19/2021 1506 G

// https://codeforces.com/problemset/problem/1506/G

#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    int len = str.length();
    int cnt[26], vis[26];
    memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
    for (int i = 0; i < len; i++) {
      cnt[str[i] - 'a']++;
    }
    stack<char> s;
    for (int i = 0; i < len; i++) {
      cnt[str[i] - 'a']--;
      if (vis[str[i] - 'a'] == 1) continue;
      while (!s.empty() && str[i] > s.top() && cnt[s.top() - 'a'] > 0) {
        vis[s.top() - 'a'] = 0;
        s.pop();
      }
      s.push(str[i]);
      vis[str[i] - 'a'] = 1;
    }
    string ans = "";
    while (!s.empty()) {
      ans = s.top() + ans;
      s.pop();
    }
    cout << ans << endl;
  }
}