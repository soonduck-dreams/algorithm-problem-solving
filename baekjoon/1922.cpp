// MST 구현 문제. Prim 이용함
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, result = 0;
vector<vector<pair<int, int>>> adj_list; // (이웃 노드, 비용)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq; // (비용, 이웃 노드)
vector<bool> is_visited;

int main() {
  FASTIO;

  cin >> n >> m;
  adj_list.resize(n + 1);
  is_visited.resize(n + 1, false);

  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj_list[a].push_back({b, c});
    adj_list[b].push_back({a, c});
  }

  int cur_node, visited_node_cnt = 0;
  pq.push({0, 1});
  while (!pq.empty() && visited_node_cnt < n) {
    cur_node = pq.top().second;

    if (is_visited[cur_node]) {
      pq.pop();
      continue;
    }

    is_visited[cur_node] = true;
    result += pq.top().first;
    visited_node_cnt++;

    pq.pop();
    for (const auto &nb : adj_list[cur_node]) {
      if (!is_visited[nb.first]) {
        pq.push({nb.second, nb.first});
      }
    }
  }

  cout << result;

  return 0;
}
