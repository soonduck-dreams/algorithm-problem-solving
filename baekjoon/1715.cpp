// 그리디하게 접근하면 쉽게 풀린다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, result;
priority_queue<int, vector<int>, greater<int>> pq; // min heap

int main() {
  FASTIO;

  cin >> n;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    pq.push(tmp);
  }

  int a, b;
  result = 0;
  while (pq.size() >= 2) {
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    result += a + b;
    pq.push(a + b);
  }

  cout << result;

  return 0;
}
