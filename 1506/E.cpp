// 04/13/2021

// https://codeforces.com/problemset/problem/1506/E

/*
E. Restoring the Permutation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation is a sequence of ๐ integers from 1 to ๐, in which all numbers occur exactly once. For example, [1], [3,5,2,1,4], [1,3,2] are permutations, and [2,3,2], [4,3,1], [0] are not.

Polycarp was presented with a permutation ๐ of numbers from 1 to ๐. However, when Polycarp came home, he noticed that in his pocket, the permutation ๐ had turned into an array ๐ according to the following rule:

๐๐=max(๐1,๐2,โฆ,๐๐).
Now Polycarp wondered what lexicographically minimal and lexicographically maximal permutations could be presented to him.

An array ๐ of length ๐ is lexicographically smaller than an array ๐ of length ๐ if there is an index ๐ (1โค๐โค๐) such that the first ๐โ1 elements of arrays ๐ and ๐ are the same, and the ๐-th element of the array ๐ is less than the ๐-th element of the array ๐. For example, the array ๐=[1,3,2,3] is lexicographically smaller than the array ๐=[1,3,4,2].

For example, if ๐=7 and ๐=[3,2,4,1,7,5,6], then ๐=[3,3,4,4,7,7,7] and the following permutations could have been as ๐ initially:

[3,1,4,2,7,5,6] (lexicographically minimal permutation);
[3,1,4,2,7,6,5];
[3,2,4,1,7,5,6];
[3,2,4,1,7,6,5] (lexicographically maximum permutation).
For a given array ๐, find the lexicographically minimal and lexicographically maximal permutations that could have been originally presented to Polycarp.

Input
The first line contains one integer ๐ก (1โค๐กโค104). Then ๐ก test cases follow.

The first line of each test case contains one integer ๐ (1โค๐โค2โ105).

The second line of each test case contains ๐ integers ๐1,๐2,โฆ,๐๐ (1โค๐๐โค๐).

It is guaranteed that the array ๐ was obtained by applying the rule from the statement to some permutation ๐.

It is guaranteed that the sum of ๐ over all test cases does not exceed 2โ105.

Output
For each test case, output two lines:

on the first line output ๐ integers โ lexicographically minimal permutation that could have been originally presented to Polycarp;
on the second line print ๐ integers โ lexicographically maximal permutation that could have been originally presented to Polycarp;
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