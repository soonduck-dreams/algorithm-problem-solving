// 가능한 모든 조합마다 BFS하면 풀리는 문제. (브루트포스 BFS)
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum SPACE { BLANK, WALL, VIRUS };

int n, m;
int initial_safe_count = 0;
vector<vector<int>> v;
int result = 0;

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int BFS(vector<vector<int>> v, vector<pair<int, int>> &choose) {
  queue<pair<int, int>> q;
  int result = 3; // 3 walls

  for (auto const &p : choose) {
    v[p.first][p.second] = WALL;
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      if (v[i][j] == VIRUS) {
        q.push({i, j});
      }
    }
  }

  pair<int, int> *front;
  int nx, ny;
  while (!q.empty()) {
    front = &q.front();
    for (int i = 0; i < 4; i++) {
      ny = front->first + dy[i], nx = front->second + dx[i];
      if (ny >= 0 && ny < n && nx >= 0 && nx < m && v[ny][nx] == BLANK) {
        v[ny][nx] = VIRUS;
        q.push({ny, nx});
        result++;
      }
    }
    q.pop();
  }

  result = initial_safe_count - result;
  return result;
}

int main(void) {
  FASTIO;

  cin >> n >> m;
  v.resize(n, vector<int>(m, BLANK));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == BLANK) {
        initial_safe_count++;
      }
    }
  }

  vector<pair<int, int>> choose(3);
  int tmp;
  for (int i = 0; i < n * m - 2; i++) {
    if (v[i / m][i % m] != BLANK)
      continue;

    for (int j = i + 1; j < n * m - 1; j++) {
      if (v[j / m][j % m] != BLANK)
        continue;

      for (int k = j + 1; k < n * m; k++) {
        if (v[k / m][k % m] != BLANK)
          continue;

        choose[0] = {i / m, i % m};
        choose[1] = {j / m, j % m};
        choose[2] = {k / m, k % m};

        tmp = BFS(v, choose);
        result = tmp > result ? tmp : result;
      }
    }
  }

  cout << result;

  return 0;
}
