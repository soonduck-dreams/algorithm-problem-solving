// BFS 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> v;

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
vector<vector<bool>> is_visited, is_melting;

int cheese_cnt, prev_cheese_cnt;
int days_elapsed;

int main() {
  FASTIO;

  cin >> m >> n;
  v.resize(m, vector<int>(n));
  is_melting.resize(m, vector<bool>(n));
  is_visited.resize(m, vector<bool>(n));

  cheese_cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
      if (v[i][j]) {
        cheese_cnt++;
      }
    }
  }

  days_elapsed = 0;
  int cur_y, cur_x;
  while (cheese_cnt > 0) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        is_visited[i][j] = false;
        is_melting[i][j] = false;
      }
    }

    q.push({0, 0});
    is_visited[0][0] = true;

    while (!q.empty()) {
      cur_y = q.front().first, cur_x = q.front().second;
      for (int i = 0; i < 4; i++) {
        if (cur_y + dy[i] >= 0 && cur_y + dy[i] < m && cur_x + dx[i] >= 0 &&
            cur_x + dx[i] < n && !is_visited[cur_y + dy[i]][cur_x + dx[i]]) {
          if (v[cur_y + dy[i]][cur_x + dx[i]]) {
            is_melting[cur_y + dy[i]][cur_x + dx[i]] = true;
            is_visited[cur_y + dy[i]][cur_x + dx[i]] = true;
          } else {
            q.push({cur_y + dy[i], cur_x + dx[i]});
            is_visited[cur_y + dy[i]][cur_x + dx[i]] = true;
          }
        }
      }
      q.pop();
    }

    prev_cheese_cnt = cheese_cnt;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (is_melting[i][j]) {
          v[i][j] = 0;
          cheese_cnt--;
        }
      }
    }

    days_elapsed++;
  }

  cout << days_elapsed << '\n' << prev_cheese_cnt;

  return 0;
}
