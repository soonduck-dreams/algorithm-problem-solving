// 분할 정복 거듭제곱 문제
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

int n;
long long b; // 자료형 주의 (최대 1000억)
vector<vector<int>> v;
vector<vector<int>> result;

void matmul(const vector<vector<int>> a, const vector<vector<int>> b,
            vector<vector<int>> &result) {
  int size = a.size();
  int local;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      local = 0;
      for (int k = 0; k < size; k++) {
        local += a[i][k] * b[k][j];
      }
      local %= 1000;
      result[i][j] = local;
    }
  }
}

void matpow(const vector<vector<int>> &base, long long pow,
            vector<vector<int>> &result) {
  if (pow == 1) {
    result = base;
    return;
  }

  matpow(base, pow / 2, result);
  matmul(result, result, result);
  if (pow % 2) {
    matmul(result, base, result);
  }
}

int main() {
  FASTIO;

  cin >> n >> b;
  v.resize(n, vector<int>(n));
  result.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  matpow(v, b, result);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] % 1000 << ' ';
    }
    cout << '\n';
  }

  return 0;
}
