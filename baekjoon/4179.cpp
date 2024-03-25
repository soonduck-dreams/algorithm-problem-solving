// BFS 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int r, c;
string s;
vector<vector<int>> v;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

enum TYPE { WALL, FIRE, EMPTY };

queue<pair<pair<int, int>, int>> jihun_q, fire_q; // (위치, 레벨)
vector<vector<bool>> jihun_visited, fire_visited;
int level;
int jihun_added_cnt;

int main() {
  FASTIO;

  cin >> r >> c;
  v.resize(r, vector<int>(c));
  jihun_visited.resize(r, vector<bool>(c, false));
  fire_visited.resize(r, vector<bool>(c, false));
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      switch (s[j]) {
      case '#':
        v[i][j] = WALL;
        break;
      case 'J':
        jihun_q.push({{i, j}, 0});
      case '.':
        v[i][j] = EMPTY;
        break;
      case 'F':
        fire_q.push({{i, j}, 0});
        v[i][j] = FIRE;
        break;
      }
    }
  }

  level = 0;
  pair<int, int> cur_position;
  while (true) {
    jihun_added_cnt = 0;
    while (!jihun_q.empty() && jihun_q.front().second == level) {
      cur_position = jihun_q.front().first;
      jihun_q.pop();
      if (v[cur_position.first][cur_position.second] == FIRE) {
        continue;
      }
      if (cur_position.first == 0 || cur_position.first == r - 1 ||
          cur_position.second == 0 ||
          cur_position.second == c - 1) { // 가장자리에 있으면 종료
        cout << level + 1;
        return 0;
      }
      for (int i = 0; i < 4; i++) {
        if (v[cur_position.first + dy[i]][cur_position.second + dx[i]] ==
                EMPTY &&
            !jihun_visited[cur_position.first + dy[i]]
                          [cur_position.second + dx[i]]) {
          jihun_q.push(
              {{cur_position.first + dy[i], cur_position.second + dx[i]},
               level + 1});
          jihun_added_cnt++;
          jihun_visited[cur_position.first + dy[i]]
                       [cur_position.second + dx[i]] = true;
        }
      }
    }
    if (jihun_added_cnt == 0) {
      cout << "IMPOSSIBLE";
      return 0;
    }

    while (!fire_q.empty() && fire_q.front().second == level) {
      cur_position = fire_q.front().first;
      fire_q.pop();
      for (int i = 0; i < 4; i++) {
        if (cur_position.first + dy[i] >= 0 && cur_position.first + dy[i] < r &&
            cur_position.second + dx[i] >= 0 &&
            cur_position.second + dx[i] < c &&
            v[cur_position.first + dy[i]][cur_position.second + dx[i]] ==
                EMPTY &&
            !fire_visited[cur_position.first + dy[i]]
                         [cur_position.second + dx[i]]) {
          fire_q.push(
              {{cur_position.first + dy[i], cur_position.second + dx[i]},
               level + 1});
          v[cur_position.first + dy[i]][cur_position.second + dx[i]] = FIRE;
          fire_visited[cur_position.first + dy[i]]
                      [cur_position.second + dx[i]] = true;
        }
      }
    }

    level++;
  }
}
