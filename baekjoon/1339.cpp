// 그리디하게 풀면 된다. 지분이 큰 애부터 9, 8, 7, 6, ... 이렇게 할당하기.
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int myPow(int base, int n) {
  int result = 1;
  for (int i = 0; i < n; i++)
    result *= base;
  return result;
}

int n, result;
string s;
int v[26] = {0};
priority_queue<int> pq;

int main() {
  FASTIO;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = s.size() - 1; j >= 0; j--) {
      v[s[j] - 'A'] += myPow(10, s.size() - j - 1);
    }
  }

  for (int i = 0; i < 26; i++) {
    if (v[i] > 0) {
      pq.push(v[i]);
    }
  }

  result = 0;
  int k = 9;
  while (!pq.empty()) {
    result += k * pq.top();
    pq.pop();
    k--;
  }

  cout << result;

  return 0;
}
