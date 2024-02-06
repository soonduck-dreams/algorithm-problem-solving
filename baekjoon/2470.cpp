// two-pointer technique 사용. left와 right가 양끝에서 시작해 좁혀가는 방식
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  int cnt;
  vector<int> v;

  cin >> cnt;
  v.resize(cnt);

  for (int i = 0; i < cnt; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  int start = 0, end = cnt - 1;
  int result[2] = {0};
  int min;
  bool isInitial = true;
  while (start < end) {
    if (isInitial) {
      result[0] = v[start];
      result[1] = v[end];
      min = abs(result[1] + result[0]);
      isInitial = false;
    } else {
      if (min > abs(v[end] + v[start])) {
        result[0] = v[start];
        result[1] = v[end];
        min = abs(result[1] + result[0]);
      }
    }

    if (min == 0)
      break;

    if (v[start] + v[end] < 0) {
      start++;
    } else {
      end--;
    }
  }

  cout << result[0] << ' ' << result[1];

  return 0;
}
