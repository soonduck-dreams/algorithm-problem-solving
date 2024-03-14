// BFS 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n, result;
vector<vector<int>> v;
bool is_not_done;

queue<pair<int, int>> q;
vector<vector<bool>> is_visited, can_break;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
int cur_y, cur_x;

int main() {
  FASTIO;

  string s;

  cin >> m >> n;
  v.resize(n, vector<int>(m));
  can_break.resize(n, vector<bool>(m));
  is_visited.resize(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      v[i][j] = s[j] - '0';
    }
  }

  is_not_done = true;
  result = 0;
  while (is_not_done) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        is_visited[i][j] = false;
        can_break[i][j] = false;
      }
    }
    q.push({0, 0});
    is_visited[0][0] = true;

    while (!q.empty()) {
      cur_y = q.front().first, cur_x = q.front().second;

      if (cur_y == n - 1 && cur_x == m - 1) {
        is_not_done = false;
      }

      for (int i = 0; i < 4; i++) {
        if (cur_y + dy[i] >= 0 && cur_y + dy[i] < n && cur_x + dx[i] >= 0 &&
            cur_x + dx[i] < m && !is_visited[cur_y + dy[i]][cur_x + dx[i]]) {
          if (v[cur_y + dy[i]][cur_x + dx[i]] == 0) {
            q.push({cur_y + dy[i], cur_x + dx[i]});
            is_visited[cur_y + dy[i]][cur_x + dx[i]] = true;
          } else {
            can_break[cur_y + dy[i]][cur_x + dx[i]] = true;
            is_visited[cur_y + dy[i]][cur_x + dx[i]] = true;
          }
        }
      }
      q.pop();
    }

    if (is_not_done) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (can_break[i][j]) {
            v[i][j] = 0;
          }
        }
      }
      result++;
    }
  }

  cout << result;

  return 0;
}
