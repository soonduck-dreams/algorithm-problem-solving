// 다익스트라 구현해서 풀긴 했는데...
// 생각해보니 unweighted graph니까 단순 BFS로도 최단 거리를 구할 수 있었네... 다익스트라로 구현해도 어차피 의미가 없구만
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>
#define NONE -1

using namespace std;

struct Path {
  int weight;
  int src;
  int dst;
};

struct PathCompare {
  bool operator()(const Path &a, const Path &b) const {
    return a.weight > b.weight;
  }
};

int f(int x, int mode) {
  switch (mode) {
  case 0:
    return x - 1;
  case 1:
    return x + 1;
  case 2:
    return 2 * x;
  }
}

vector<bool> is_visited(100001, false);
vector<int> parent(100001, NONE);
priority_queue<Path, vector<Path>, PathCompare> pq;
int n, k;

vector<int> record;

int main() {
  FASTIO;

  cin >> n >> k;

  pq.push(Path{0, NONE, n});

  Path cur;
  int neighbor;
  while (!pq.empty()) {
    cur = pq.top();
    pq.pop();

    if (is_visited[cur.dst]) {
      continue;
    }

    is_visited[cur.dst] = true;
    parent[cur.dst] = cur.src;

    if (cur.dst == k) {
      break;
    }

    for (int i = 0; i < 3; i++) {
      neighbor = f(cur.dst, i);
      if (neighbor >= 0 && neighbor <= 1e5 && !is_visited[neighbor]) {
        pq.push(Path{cur.weight + 1, cur.dst, neighbor});
      }
    }
  }

  cout << cur.weight << '\n';

  int vertex = cur.dst;
  while (vertex != NONE) {
    record.push_back(vertex);
    vertex = parent[vertex];
  }
  for (int i = record.size() - 1; i >= 0; i--) {
    cout << record[i] << ' ';
  }

  return 0;
}
