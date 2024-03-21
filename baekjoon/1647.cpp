// MST를 만들고, 그 상태에서 비용이 가장 큰 간선 하나만 제거해주면 두 개의 component로 쪼개진다.
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, result;
vector<vector<pair<int, int>>> adj_list; // (비용, 노드)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
vector<bool> is_visited;

int main() {
  FASTIO;

  cin >> n >> m;
  adj_list.resize(n + 1);
  is_visited.resize(n + 1);

  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj_list[a].push_back({c, b});
    adj_list[b].push_back({c, a});
  }

  result = 0;

  int cur, max_cost = -1;
  pq.push({0, 1});
  while (!pq.empty()) {
    cur = pq.top().second;
    if (is_visited[cur]) {
      pq.pop();
      continue;
    }

    result += pq.top().first;
    is_visited[cur] = true;
    max_cost = pq.top().first > max_cost ? pq.top().first : max_cost;
    pq.pop();

    for (const auto &nb : adj_list[cur]) {
      if (!is_visited[nb.second]) {
        pq.push({nb.first, nb.second});
      }
    }
  }

  result -= max_cost;
  cout << result;

  return 0;
}
