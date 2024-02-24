// monotonic stack 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> v, result;
stack<pair<int, int>> s; // (value, index in v)

int main() {
  FASTIO;

  cin >> n;
  v.resize(n);
  result.resize(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.top().first < v[i]) {
      result[s.top().second] = v[i];
      s.pop();
    }

    s.push({v[i], i});
  }

  for (int i = 0; i < n; i++) {
    cout << result[i] << ' ';
  }

  return 0;
}
