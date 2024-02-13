// DFS 백트래킹 이용하기
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj_list;
vector<bool> is_visited;
bool is_result_true = false;

void DFS(int node, int depth) {
  if (depth == 4) {
    is_result_true = true;
    return;
  }

  for (const auto &neighbor : adj_list[node]) {
    if (!is_visited[neighbor]) {
      is_visited[neighbor] = true;
      DFS(neighbor, depth + 1);
      is_visited[neighbor] = false;
    }

    if (is_result_true) {
      return;
    }
  }
}

int main(void) {
  FASTIO;

  cin >> n >> m;
  adj_list.resize(n);
  is_visited.resize(n, false);

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    if (!is_visited[i]) {
      is_visited[i] = true;
      DFS(i, 0);
      is_visited[i] = false;
    }

    if (is_result_true) {
      break;
    }
  }

  cout << is_result_true;

  return 0;
}
