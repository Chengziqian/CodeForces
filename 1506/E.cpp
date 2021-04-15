// 04/13/2021

// https://codeforces.com/problemset/problem/1506/E

/*
E. Restoring the Permutation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation is a sequence of 𝑛 integers from 1 to 𝑛, in which all numbers occur exactly once. For example, [1], [3,5,2,1,4], [1,3,2] are permutations, and [2,3,2], [4,3,1], [0] are not.

Polycarp was presented with a permutation 𝑝 of numbers from 1 to 𝑛. However, when Polycarp came home, he noticed that in his pocket, the permutation 𝑝 had turned into an array 𝑞 according to the following rule:

𝑞𝑖=max(𝑝1,𝑝2,…,𝑝𝑖).
Now Polycarp wondered what lexicographically minimal and lexicographically maximal permutations could be presented to him.

An array 𝑎 of length 𝑛 is lexicographically smaller than an array 𝑏 of length 𝑛 if there is an index 𝑖 (1≤𝑖≤𝑛) such that the first 𝑖−1 elements of arrays 𝑎 and 𝑏 are the same, and the 𝑖-th element of the array 𝑎 is less than the 𝑖-th element of the array 𝑏. For example, the array 𝑎=[1,3,2,3] is lexicographically smaller than the array 𝑏=[1,3,4,2].

For example, if 𝑛=7 and 𝑝=[3,2,4,1,7,5,6], then 𝑞=[3,3,4,4,7,7,7] and the following permutations could have been as 𝑝 initially:

[3,1,4,2,7,5,6] (lexicographically minimal permutation);
[3,1,4,2,7,6,5];
[3,2,4,1,7,5,6];
[3,2,4,1,7,6,5] (lexicographically maximum permutation).
For a given array 𝑞, find the lexicographically minimal and lexicographically maximal permutations that could have been originally presented to Polycarp.

Input
The first line contains one integer 𝑡 (1≤𝑡≤104). Then 𝑡 test cases follow.

The first line of each test case contains one integer 𝑛 (1≤𝑛≤2⋅105).

The second line of each test case contains 𝑛 integers 𝑞1,𝑞2,…,𝑞𝑛 (1≤𝑞𝑖≤𝑛).

It is guaranteed that the array 𝑞 was obtained by applying the rule from the statement to some permutation 𝑝.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output two lines:

on the first line output 𝑛 integers — lexicographically minimal permutation that could have been originally presented to Polycarp;
on the second line print 𝑛 integers — lexicographically maximal permutation that could have been originally presented to Polycarp;
Example
inputCopy
4
7
3 3 4 4 7 7 7
4
1 2 3 4
7
3 4 5 5 5 7 7
1
1
outputCopy
3 1 4 2 7 5 6 
3 2 4 1 7 6 5 
1 2 3 4 
1 2 3 4 
3 4 5 1 2 7 6 
3 4 5 2 1 7 6 
1 
1 
*/

#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
int main() {
  int T;
  int N = 2e5 + 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    unordered_set<int> used;
    int q[N], ansForMax[N], ansForMin[N];
    stack<int> s;
    int minNum = 1;
    for (int k = 0; k < n; ++k) cin >> q[k];
    for (int k = 0; k < n; ++k) {
      if (k == 0 || q[k - 1] != q[k]) {
        ansForMin[k] = q[k];
        ansForMax[k] = q[k];
        used.insert(q[k]);
        for (int n = (k == 0 ? 1 : q[k - 1]); n < q[k]; ++n) {
          if (used.find(n) == used.end()) s.push(n);
        }
      } else {
        while (used.find(minNum) != used.end()) ++minNum;
        ansForMin[k] = minNum;
        used.insert(minNum);
        ansForMax[k] = s.top();
        s.pop();
      }
    }
    for (int k = 0; k < n; ++k) {
      cout<<ansForMin[k]<<" ";
    }
    cout<<endl;
    for (int k = 0; k < n; ++k) {
      cout<<ansForMax[k]<<" ";
    }
    cout<<endl;
  }
}