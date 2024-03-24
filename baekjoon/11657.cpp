// Bellman-Ford 이용. Bellman-Ford = single-source shortest path, can handle negative weights, can detect negative cycle
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>
#define INF 1e8

using namespace std;

int n, m, a, b, c;
vector<vector<pair<int, int>>>
    adj_list; // (weight, source) 나한테 오는 노드를 저장

vector<vector<int>> dist; // Bellman-Ford용 2xn 배열
int last = 0, now = 1 - last;

bool has_negative_cycle = false;

int main() {
  FASTIO;

  cin >> n >> m;
  adj_list.resize(n + 1);
  dist.resize(2, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj_list[b].push_back({c, a});
  }

  dist[last][1] = 0;
  for (int i = 2; i <= n; i++) {
    dist[last][i] = INF;
  }

  int min_dist;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      min_dist = dist[last][j];
      for (const auto &nb : adj_list[j]) {
        min_dist = dist[last][nb.second] < INF &&
                           (dist[last][nb.second] + nb.first < min_dist)
                       ? dist[last][nb.second] + nb.first
                       : min_dist;
      }
      dist[now][j] = min_dist;
    }
    last = 1 - last, now = 1 - last;
  }

  for (int i = 1; i <= n; i++) {
    if (dist[last][i] != dist[now][i]) {
      has_negative_cycle = true;
      break;
    }
  }

  if (has_negative_cycle) {
    cout << -1;
  } else {
    for (int i = 2; i <= n; i++) {
      cout << (dist[now][i] < INF ? dist[now][i] : -1) << '\n';
    }
  }

  return 0;
}
