// 투 포인터(left, right) 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>
#define INF 2e9

using namespace std;

int n;
vector<int> v;

int main(void) {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int min = INF;
  int result[2];
  int left = 0, right = n - 1;
  while (left < right) {
    if (abs(v[left] + v[right]) < min) {
      min = abs(v[left] + v[right]);
      result[0] = v[left], result[1] = v[right];
      if (min == 0) {
        break;
      }
    }

    (v[left] + v[right] < 0) ? left++ : right--;
  }

  cout << result[0] << ' ' << result[1];

  return 0;
}
