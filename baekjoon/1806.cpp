// two-pointer technique. 두 포인터가 똑같은 지점에서 시작해서 오른쪽으로 이동하는 식
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

#define INF 2e6

using namespace std;

int v, e;
int a, b, c;
int reached_count, result;

vector<vector<pair<int, int>>> adj_list; // {vertex, weight}
vector<bool> is_reached;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq; // {weight, vertex}

int main(void) {
  FASTIO;

  cin >> v >> e;
  adj_list.resize(v + 1);
  is_reached.resize(v + 1, false);

  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    adj_list[a].push_back({b, c});
    adj_list[b].push_back({a, c});
  }

  result = 0;
  reached_count = 0;
  pq.push({0, 1});
  int now_vertex;
  while (reached_count < v) {
    if (!is_reached[pq.top().second]) {
      now_vertex = pq.top().second;
      result += pq.top().first;
      is_reached[now_vertex] = true;
      reached_count++;
      pq.pop();

      for (auto const &neighbor : adj_list[now_vertex]) {
        pq.push({neighbor.second, neighbor.first});
      }
    } else {
      pq.pop();
    }
  }

  cout << result;

  return 0;
}
