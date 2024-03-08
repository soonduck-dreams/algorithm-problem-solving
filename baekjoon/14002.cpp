// 대표적인 DP 알고리즘인 LIS(Longest Increasing Subsequence)를 복습.
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  FASTIO;

  int n;
  vector<int> v, dp, parent;

  cin >> n;
  v.resize(n);
  dp.resize(n);
  parent.resize(n);

  dp[0] = 1;
  parent[0] = -1;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    parent[i] = -1;
    for (int j = 0; j < i; j++) {
      if (v[i] > v[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        parent[i] = j;
      }
    }
  }

  int result = dp[0], idx = 0;
  stack<int> s;

  for (int i = 1; i < n; i++) {
    if (dp[i] > result) {
      result = dp[i];
      idx = i;
    }
  }

  s.push(v[idx]);
  while (parent[idx] != -1) {
    s.push(v[parent[idx]]);
    idx = parent[idx];
  }

  cout << result << '\n';
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }

  return 0;
}
