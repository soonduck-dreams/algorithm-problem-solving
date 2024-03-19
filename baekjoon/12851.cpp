// BFS 문제인데, 발상의 전환이 필요했음
// 보통은 방문 체크를 큐에 넣는 시점에 한다 (중복 방문 방지)
// 그런데 방문 체크를 실제 방문 시점에 하면, BFS로 해당 노드에 도달하는 최단 경로의 개수를 셀 수 있다! (해당 레벨에서 중복 방문의 개수 카운트)
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k, cur_pos, cur_level, result_level, result_case_cnt, local;
queue<pair<int, int>> q; // (위치, 레벨)
bool is_visited[100001] = {false};

int f(int v, int mode) {
  switch (mode) {
  case 0:
    return v - 1;
  case 1:
    return v + 1;
  case 2:
    return 2 * v;
  }
}

int main() {
  FASTIO;
  cin >> n >> k;

  q.push({n, 0});
  result_case_cnt = 0;
  cur_pos = q.front().first;
  cur_level = q.front().second;
  is_visited[n] = true;
  while (!q.empty() && (result_case_cnt == 0 || cur_level == result_level)) {
    if (cur_pos == k) {
      result_case_cnt++;
      result_level = cur_level;
    } else if (result_case_cnt == 0) {
      for (int i = 0; i < 3; i++) {
        local = f(cur_pos, i);
        if (local >= 0 && local <= 1e5 && !is_visited[local]) {
          q.push({local, cur_level + 1});
        }
      }
    }

    q.pop();
    if (!q.empty()) {
      cur_pos = q.front().first;
      cur_level = q.front().second;
      is_visited[cur_pos] = true;
    }
  }

  cout << result_level << '\n' << result_case_cnt;

  return 0;
}
