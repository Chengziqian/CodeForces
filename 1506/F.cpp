#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    vector<pair<int, int> > node;
    cin >> n;
    int c[200001], r[200001];
    for (int i = 0; i < n; i++) {
      cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
      node.push_back(pair<int, int>(r[i], c[i]));
    }
    node.push_back(pair<int, int>(1, 1));
    sort(node.begin(), node.end());
    int ans = 0;
    for (int i = 1; i < node.size(); i++) {
      int rightCount = node[i].second - node[i - 1].second;
      int leftCount = node[i].first - node[i - 1].first - rightCount;
      if (node[i - 1].first + node[i - 1].second & 1) {
        ans += (leftCount + 1) / 2;
      } else {
        ans += leftCount / 2 + (leftCount == 0 ? rightCount : 0);
      }
    }
    cout << ans << endl;
  }
}