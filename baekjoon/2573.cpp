// 구현 + BFS
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
int bfs_cnt;
int result;

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

vector<vector<int>> tmpv;
void melt() {
  int cnt;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt = 0;
      if (v[i][j] > 0) {
        for (int k = 0; k < 4; k++) {
          if (i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 &&
              j + dx[k] < m && v[i + dy[k]][j + dx[k]] == 0) {
            cnt++;
          }
        }
      }
      tmpv[i][j] = cnt;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v[i][j] = (v[i][j] - tmpv[i][j] >= 0) ? (v[i][j] - tmpv[i][j]) : 0;
    }
  }
}

queue<pair<int, int>> q;
vector<vector<bool>> is_visited;
void BFS(pair<int, int> p) {
  q.push(p);
  is_visited[p.first][p.second] = true;
  pair<int, int> cur;
  while (!q.empty()) {
    cur = q.front();
    for (int i = 0; i < 4; i++) {
      if (cur.first + dy[i] >= 0 && cur.first + dy[i] < n &&
          cur.second + dx[i] >= 0 && cur.second + dx[i] < m &&
          !is_visited[cur.first + dy[i]][cur.second + dx[i]] &&
          v[cur.first + dy[i]][cur.second + dx[i]] > 0) {
        q.push({cur.first + dy[i], cur.second + dx[i]});
        is_visited[cur.first + dy[i]][cur.second + dx[i]] = true;
      }
    }
    q.pop();
  }
}

int main() {
  FASTIO;

  cin >> n >> m;
  v.resize(n, vector<int>(m));
  tmpv.resize(n, vector<int>(m, 0));
  is_visited.resize(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  result = 0;
  do {
    result++;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        is_visited[i][j] = false;
      }
    }

    melt();
    bfs_cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] > 0 && !is_visited[i][j]) {
          if (bfs_cnt == 0) {
            bfs_cnt++;
            BFS({i, j});
          } else {
            cout << result;
            return 0;
          }
        }
      }
    }

  } while (bfs_cnt == 1);

  cout << 0;
  return 0;
}
