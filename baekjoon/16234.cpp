// 국경선(edge)을 매번 설정하고, BFS로 인구 이동시키고, 국경선을 리셋하는 과정을 반복한다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, l, r;
int result;
vector<vector<int>> v;
vector<vector<vector<pair<int, int>>>> adj_list;
vector<vector<bool>> is_visited;

int dx[2] = {1, 0}, dy[2] = {0, 1};

queue<pair<int, int>> q;
vector<pair<int, int>> allies;
void movePopulation(pair<int, int> start) {
  int result = 0;
  allies.clear();

  q.push(start);
  is_visited[start.first][start.second] = true;

  while (!q.empty()) {
    allies.push_back(q.front());
    result += v[q.front().first][q.front().second];

    for (const auto &el : adj_list[q.front().first][q.front().second]) {
      if (!is_visited[el.first][el.second]) {
        q.push(el);
        is_visited[el.first][el.second] = true;
      }
    }

    q.pop();
  }

  result /= allies.size();
  for (const auto &el : allies) {
    v[el.first][el.second] = result;
  }
}

int main() {
  FASTIO;

  cin >> n >> l >> r;
  v.resize(n, vector<int>(n, 0));
  adj_list.resize(n,
                  vector<vector<pair<int, int>>>(n, vector<pair<int, int>>()));
  is_visited.resize(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  bool is_moveable;
  do {
    is_moveable = false;

    // 국경선(edge) 설정
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 2; k++) {
          if (i + dy[k] < n && j + dx[k] < n &&
              abs(v[i][j] - v[i + dy[k]][j + dx[k]]) >= l &&
              abs(v[i][j] - v[i + dy[k]][j + dx[k]]) <= r) {
            adj_list[i][j].push_back({i + dy[k], j + dx[k]});
            adj_list[i + dy[k]][j + dx[k]].push_back({i, j});
            is_moveable = true;
          }
        }
      }
    }

    if (is_moveable) {
      // 연합별 인구 이동 (BFS)
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (!is_visited[i][j]) {
            movePopulation({i, j});
          }
        }
      }

      // 국경선 전부 폐쇄
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          adj_list[i][j].clear();
          is_visited[i][j] = false;
        }
      }

      result++;
    }

  } while (is_moveable);

  cout << result;

  return 0;
}
