// dp로 접근: 양끝만 같은지 확인하고, 중간 부분은 이전에 구한 해를 사용
// + upper triangular matrix를 1차원 배열로 구현하여 메모리 절약
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, m, s, e;

class UpperTriangularMatrix {
private:
  vector<bool> data;
  int size;

public:
  void resize(int size) {
    data.resize(size * (size + 1) / 2);
    this->size = size;
  }
  void set(int r, int c, bool value) {
    data[size * r - (r - 1) * r / 2 + c - r] = value;
  };
  bool get(int r, int c) {
    if (r > c) {
      return true; // 유효하지 않은 좌표일 경우 true를 반환하기로 약속
    }
    return data[size * r - (r - 1) * r / 2 + c - r];
  }
};

UpperTriangularMatrix dp;

int main() {
  FASTIO;

  cin >> n;
  v.resize(n);
  dp.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // base case
  for (int i = 0; i < n; i++) {
    dp.set(i, i, true);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      dp.set(j, j + i, v[j] == v[j + i] && dp.get(j + 1, j + i - 1));
      // 양 끝이 같은지만 직접 확인하고, 중간 부분은 이전에 구한 해를 사용
    }
  }

  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> s >> e;
    s--, e--;
    cout << dp.get(s, e) << '\n';
  }

  return 0;
}
