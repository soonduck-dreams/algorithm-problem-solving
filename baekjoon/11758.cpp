// cross product의 성질을 이용해서 회전 방향을 구하는 ccw 알고리즘을 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  FASTIO;
  short p[3][2];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> p[i][j];
    }
  }

  int ccw = (p[1][0] - p[0][0]) * (p[2][1] - p[1][1]) -
            (p[1][1] - p[0][1]) * (p[2][0] - p[1][0]);

  if (ccw != 0)
    ccw /= abs(ccw);

  cout << ccw;

  return 0;
}
