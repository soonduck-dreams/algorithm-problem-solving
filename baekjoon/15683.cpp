// DFS 브루트포스. cctv 종류별 동작을 구현하기 위해 배열(dt, dti) 이용
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>
#define INF 100

using namespace std;

enum TYPE { UNCOVERED, ONE, TWO180, TWO90, THREE, FOUR, WALL, COVERED };

int n, m;
vector<vector<int>> v;

int uncovered_cnt;
vector<pair<int, int>> cctvs;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0}; // 우하좌상
int dt[5] = {1, 2, 2, 3, 4}, dti[5] = {1, 2, 1, 1, 1};

int result = INF;

void DFS(int c, int d) {
  if (c == cctvs.size()) {
    result = uncovered_cnt < result ? uncovered_cnt : result;
    return;
  }

  vector<pair<int, int>> covered_here;
  pair<int, int> cur;
  int local_direction;
  int cctv_type = v[cctvs[c].first][cctvs[c].second] - 1;

  for (int i = 0; i < dt[cctv_type]; i++) {
    local_direction = (d + i * dti[cctv_type]) % 4;
    cur = {cctvs[c].first + dy[local_direction],
           cctvs[c].second + dx[local_direction]};
    while (cur.first >= 0 && cur.first < n && cur.second >= 0 &&
           cur.second < m && v[cur.first][cur.second] != WALL) {
      if (v[cur.first][cur.second] == UNCOVERED) {
        v[cur.first][cur.second] = COVERED;
        covered_here.push_back(cur);
        uncovered_cnt--;
      }
      cur.first += dy[local_direction];
      cur.second += dx[local_direction];
    }
  }

  for (int i = 0; i < 4; i++) {
    DFS(c + 1, i);
  }

  for (const auto &el : covered_here) {
    v[el.first][el.second] = UNCOVERED;
    uncovered_cnt++;
  }
}

int main() {
  FASTIO;

  cin >> n >> m;
  v.resize(n, vector<int>(m));

  uncovered_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == UNCOVERED) {
        uncovered_cnt++;
      } else if (v[i][j] < WALL) {
        cctvs.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    DFS(0, i);
  }

  cout << result;

  return 0;
}
