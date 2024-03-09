// 고슴도치와 물의 동시 이동을 BFS로 구현한다. 물이 여러 군데에서 시작하거나, 아예 없는 경우도 있음에 주의
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum TYPE { EMPTY, WATER, WALL, GOAL };

int r, c;
pair<int, int> me_src;
vector<pair<int, int>> water_srcs;
vector<vector<int>> v;
string s;

int main() {
  FASTIO;

  cin >> r >> c;
  v.resize(r, vector<int>(c));

  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      switch (s[j]) {
      case '.':
        v[i][j] = EMPTY;
        break;
      case 'S':
        v[i][j] = EMPTY;
        me_src = {i, j};
        break;
      case '*':
        v[i][j] = WATER;
        water_srcs.push_back({i, j});
        break;
      case 'X':
        v[i][j] = WALL;
        break;
      case 'D':
        v[i][j] = GOAL;
        break;
      }
    }
  }

  queue<pair<pair<int, int>, int>> me_q, water_q; // (위치, 레벨)
  vector<vector<bool>> me_visited(r, vector<bool>(c, false)),
      water_visited(r, vector<bool>(c, false));

  me_q.push({me_src, 0});
  me_visited[me_src.first][me_src.second] = true;
  for (const auto &el : water_srcs) {
    water_q.push({el, 0});
    water_visited[el.first][el.second] = true;
  }

  int cur_level = 0;
  bool is_safe = true;
  int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
  pair<int, int> cur_node;

  while (is_safe) {
    is_safe = false;
    while (me_q.front().second == cur_level) {
      cur_node = me_q.front().first;

      if (v[cur_node.first][cur_node.second] == WATER) {
        me_q.pop();
        continue;
      }
      is_safe = true;

      if (v[cur_node.first][cur_node.second] == GOAL) {
        cout << cur_level;
        return 0;
      }

      for (int i = 0; i < 4; i++) {
        if (cur_node.first + dy[i] >= 0 && cur_node.first + dy[i] < r &&
            cur_node.second + dx[i] >= 0 && cur_node.second + dx[i] < c &&
            !me_visited[cur_node.first + dy[i]][cur_node.second + dx[i]] &&
            v[cur_node.first + dy[i]][cur_node.second + dx[i]] != WALL &&
            v[cur_node.first + dy[i]][cur_node.second + dx[i]] != WATER) {
          me_q.push({{cur_node.first + dy[i], cur_node.second + dx[i]},
                     me_q.front().second + 1});
          me_visited[cur_node.first + dy[i]][cur_node.second + dx[i]] = true;
        }
      }

      me_q.pop();
    }

    while (!water_q.empty() && water_q.front().second == cur_level) {
      cur_node = water_q.front().first;

      for (int i = 0; i < 4; i++) {
        if (cur_node.first + dy[i] >= 0 && cur_node.first + dy[i] < r &&
            cur_node.second + dx[i] >= 0 && cur_node.second + dx[i] < c &&
            !water_visited[cur_node.first + dy[i]][cur_node.second + dx[i]] &&
            v[cur_node.first + dy[i]][cur_node.second + dx[i]] != WALL &&
            v[cur_node.first + dy[i]][cur_node.second + dx[i]] != GOAL) {
          water_q.push({{cur_node.first + dy[i], cur_node.second + dx[i]},
                        water_q.front().second + 1});
          water_visited[cur_node.first + dy[i]][cur_node.second + dx[i]] = true;
          v[cur_node.first + dy[i]][cur_node.second + dx[i]] = WATER;
        }
      }

      water_q.pop();
    }

    cur_level++;
  }

  cout << "KAKTUS";
  return 0;
}
