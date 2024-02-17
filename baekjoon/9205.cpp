// BFS를 이용한다는 발상에 이르면 그 이후는 쉽게 풀린다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool canReach(vector<pair<int, int>> &convs, pair<int, int> &src,
              pair<int, int> &dst) {
  int convs_size = convs.size();
  vector<bool> is_visited(convs_size, false);
  queue<pair<int, int>> q;

  q.push(src);

  while (!q.empty()) {
    if (abs(q.front().first - dst.first) + abs(q.front().second - dst.second) <=
        1000) {
      return true;
    }

    for (int i = 0; i < convs_size; i++) {
      if (!is_visited[i] && abs(q.front().first - convs[i].first) +
                                    abs(q.front().second - convs[i].second) <=
                                1000) {
        is_visited[i] = true;
        q.push(convs[i]);
      }
    }

    q.pop();
  }

  return false;
}

int main(void) {
  FASTIO;
  int t, n;
  int a, b;
  pair<int, int> src, dst;
  vector<pair<int, int>> convs;

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    convs.resize(n);

    cin >> a >> b;
    src = {a, b};
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      convs[i] = {a, b};
    }
    cin >> a >> b;
    dst = {a, b};

    cout << (canReach(convs, src, dst) ? "happy" : "sad") << '\n';
  }

  return 0;
}
