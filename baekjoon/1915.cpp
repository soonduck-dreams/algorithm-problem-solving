// DP 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, m, result;
vector<vector<int>> v, dp;

int main() {
  FASTIO;

  cin >> n >> m;
  v.resize(n, vector<int>(m));
  dp.resize(n, vector<int>(m));

  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      v[i][j] = s[j] - '0';
    }
  }

  result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 0) {
        dp[i][j] = 0;
      } else {
        if (i * j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
      }

      result = dp[i][j] > result ? dp[i][j] : result;
    }
  }

  cout << result * result;

  return 0;
}
