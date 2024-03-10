// BFS로 해결함. union-find로도 풀 수 있다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj_mtx;
vector<int> cities;
vector<bool> is_visited;
queue<int> q;

int main() {
  FASTIO;

  cin >> n >> m;
  adj_mtx.resize(n, vector<int>(n));
  is_visited.resize(n, false);
  cities.resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> adj_mtx[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> cities[i];
    cities[i]--;
  }

  q.push(cities[0]);
  is_visited[cities[0]] = true;

  while (!q.empty()) {
    for (int i = 0; i < n; i++) {
      if (!is_visited[i] && adj_mtx[q.front()][i]) {
        q.push(i);
        is_visited[i] = true;
      }
    }
    q.pop();
  }

  for (const auto &el : cities) {
    if (!is_visited[el]) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}
