// shortest path -> 다익스트라 이용.
// 반성: vector<vector<int>>로 2차원 배열 만들어서 쓰고 resize로 배열 크기를 변경하고 싶다면 clear를 먼저 해줄 것! resize의 2번째 파라미터는 새로 늘어난 크기만큼만 적용되니까
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;
vector<vector<bool>> is_visited;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
int path_cost, cnt;
pair<int, int> cur;

int main() {
  FASTIO;

  cnt = 1;
  while (true) {
    cin >> n;

    if (n == 0) {
      return 0;
    }

    v.clear();
    is_visited.clear();
    v.resize(n, vector<int>(n));
    is_visited.resize(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        is_visited[i][j] = false;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
      }
    }

    pq.push({v[0][0], {0, 0}});
    while (!pq.empty()) {
      path_cost = pq.top().first;
      cur = pq.top().second;
      pq.pop();

      if (is_visited[cur.first][cur.second]) {
        continue;
      }
      is_visited[cur.first][cur.second] = true;

      if (cur.first == n - 1 && cur.second == n - 1) {
        break;
      }

      for (int i = 0; i < 4; i++) {
        if (cur.first + dy[i] >= 0 && cur.first + dy[i] < n &&
            cur.second + dx[i] >= 0 && cur.second + dx[i] < n &&
            !is_visited[cur.first + dy[i]][cur.second + dx[i]]) {
          pq.push({path_cost + v[cur.first + dy[i]][cur.second + dx[i]],
                   {cur.first + dy[i], cur.second + dx[i]}});
        }
      }
    }

    cout << "Problem " << cnt << ": " << path_cost << '\n';
    cnt++;
    while (!pq.empty())
      pq.pop();
  }

  return 0;
}
