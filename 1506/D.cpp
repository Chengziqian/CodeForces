// 04/08/2021

 // https://codeforces.com/problemset/problem/1506/D

 /* 
 D. Epic Transformation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array ๐ of length ๐ consisting of integers. You can apply the following operation, consisting of several steps, on the array ๐ zero or more times:

you select two different numbers in the array ๐๐ and ๐๐;
you remove ๐-th and ๐-th elements from the array.
For example, if ๐=6 and ๐=[1,6,1,1,4,4], then you can perform the following sequence of operations:

select ๐=1,๐=5. The array ๐ becomes equal to [6,1,1,4];
select ๐=1,๐=2. The array ๐ becomes equal to [1,4].
What can be the minimum size of the array after applying some sequence of operations to it?

Input
The first line contains a single integer ๐ก (1โค๐กโค104). Then ๐ก test cases follow.

The first line of each test case contains a single integer ๐ (1โค๐โค2โ105) is length of the array ๐.

The second line of each test case contains ๐ integers ๐1,๐2,โฆ,๐๐ (1โค๐๐โค109).

It is guaranteed that the sum of ๐ over all test cases does not exceed 2โ105.

Output
For each test case, output the minimum possible size of the array after applying some sequence of operations to it.

Example
input
5
6
1 6 1 1 4 4
2
1 2
2
1 1
5
4 5 4 5 4
6
2 3 2 1 3 1
output
0
0
2
1
0
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// int main() {
//   int T;
//   cin >> T;
//   while (T--) {
//     int n;
//     cin >> n;
//     map<int, int> record;
//     for (int i = 0; i < n; i++) {
//       int v;
//       cin >> v;
//       map<int, int>::iterator it;
//       it = record.find(v);
//       if (it == record.end()) {
//         record.insert(pair<int, int>(v, 1));
//       } else {
//         it->second += 1;
//       }
//     }
//     priority_queue<int, vector<int>, less<int> > counts;
//     int ans = 0;
//     for (map<int, int>::iterator it = record.begin(); it != record.end(); ++it) {
//       counts.push(it->second);
//     }
//     while (counts.size() > 1) {
//       int maxCount = counts.top();
//       counts.pop();
//       while (!counts.empty() && maxCount) {
//         int current = counts.top() - 1;
//         counts.pop();
//         if (current) counts.push(current);
//         maxCount--;
//       }
//       if (maxCount) counts.push(maxCount);
//     }
//     cout << (counts.empty() ? 0 : counts.top()) << endl;
//   }
//   return 0;
// }

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, mx = 0;
    cin >> n;
    map<int, int> record;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      map<int, int>::iterator it;
      it = record.find(v);
      if (it == record.end()) {
        record.insert(pair<int, int>(v, 1));
      } else {
        it->second += 1;
        mx = max(mx, it->second);
      }
    }
    cout << max(n % 2, 2 * mx - n) << endl;
  }
  return 0;
}