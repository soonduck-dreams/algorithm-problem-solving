// LIS(Longest Increasing Subsequenece) 문제. dp로 해결
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  int cordCnt, a, b;
  vector<pair<int, int>> cords;

  cin >> cordCnt;
  for (int i = 0; i < cordCnt; i++) {
    cin >> a >> b;
    cords.push_back(make_pair(a, b));
  }
  sort(cords.begin(), cords.end());

  vector<int> seq;
  vector<int> dp(cordCnt, 1);
  for (const auto &elem : cords) {
    seq.push_back(elem.second);
  }

  for (int i = 1; i < cordCnt; i++) {
    for (int j = 0; j < i; j++) {
      if (seq[i] > seq[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  int result = cordCnt - *max_element(dp.begin(), dp.end());
  cout << result;

  return 0;
}
