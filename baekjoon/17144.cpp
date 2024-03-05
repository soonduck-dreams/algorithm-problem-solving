// 구현 문제. 미세먼지 확산은 배열 하나 더 만들어서, 공기청정기 작동은 반복문을 충실히 사용.
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
vector<vector<int>> v, tmpv;
pair<int, int> p1, p2;

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void disperse() {
  int cnt;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (v[i][j] > 4) {
        cnt = 0;
        for (int k = 0; k < 4; k++) {
          if (i + dy[k] >= 0 && i + dy[k] < r && j + dx[k] >= 0 &&
              j + dx[k] < c && v[i + dy[k]][j + dx[k]] != -1) {
            tmpv[i + dy[k]][j + dx[k]] += v[i][j] / 5;
            cnt++;
          }
        }
        v[i][j] -= cnt * (v[i][j] / 5);
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      v[i][j] += tmpv[i][j];
      tmpv[i][j] = 0;
    }
  }
}

void purify() {
  for (int i = p1.first - 2; i >= 0; i--) {
    v[i + 1][0] = v[i][0];
  }
  for (int i = 1; i < c; i++) {
    v[0][i - 1] = v[0][i];
  }
  for (int i = 1; i <= p1.first; i++) {
    v[i - 1][c - 1] = v[i][c - 1];
  }
  for (int i = c - 1; i >= 2; i--) {
    v[p1.first][i] = v[p1.first][i - 1];
  }
  v[p1.first][1] = 0;

  for (int i = p2.first + 2; i < r; i++) {
    v[i - 1][0] = v[i][0];
  }
  for (int i = 1; i < c; i++) {
    v[r - 1][i - 1] = v[r - 1][i];
  }
  for (int i = r - 2; i >= p2.first; i--) {
    v[i + 1][c - 1] = v[i][c - 1];
  }
  for (int i = c - 1; i >= 2; i--) {
    v[p2.first][i] = v[p2.first][i - 1];
  }
  v[p2.first][1] = 0;
}

int main() {
  cin >> r >> c >> t;
  v.resize(r, vector<int>(c));
  tmpv.resize(r, vector<int>(c, 0));

  int pcnt = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
      if (v[i][j] == -1) {
        if (pcnt == 0) {
          p1 = {i, j};
        } else {
          p2 = {i, j};
        }
        pcnt++;
      }
    }
  }

  for (int i = 0; i < t; i++) {
    disperse();
    purify();
  }

  int result = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (v[i][j] != -1) {
        result += v[i][j];
      }
    }
  }

  cout << result;

  return 0;
}
