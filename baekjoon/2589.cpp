// BFS 이용하기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define WATER 0
#define LAND 1
#define UNVISITED -1

int m, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int BFS(vector<vector<bool>> &v, pair<int, int> src) {
  vector<vector<int>> level(m, vector<int>(n, UNVISITED));
  queue<pair<int, int>> q;
  pair<int, int> now;
  int result = 0;

  q.push(src), level[src.first][src.second] = 0;

  while (!q.empty()) {
    for (int i = 0; i < 4; i++) {
      now = make_pair(q.front().first + dy[i], q.front().second + dx[i]);
      if (now.first >= 0 && now.first < m && now.second >= 0 &&
          now.second < n && level[now.first][now.second] == UNVISITED &&
          v[now.first][now.second] == LAND) {
        level[now.first][now.second] =
            level[q.front().first][q.front().second] + 1;
        q.push(make_pair(now.first, now.second));
      }
    }
    result = level[q.front().first][q.front().second];
    q.pop();
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  string s;
  cin >> m >> n;
  vector<vector<bool>> v(m, vector<bool>(n, WATER));

  for (int i = 0; i < m; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      v[i][j] = s[j] == 'W' ? WATER : LAND;
    }
  }

  int result = 0, local;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] == LAND) {
        local = BFS(v, make_pair(i, j));
        result = local > result ? local : result;
      }
    }
  }

  cout << result;

  return 0;
}
