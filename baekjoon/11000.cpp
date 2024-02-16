// 그리디한 생각: 가장 먼저 시작하는 수업부터 확인해서, 기존 강의실에 집어넣거나 새로운 강의실을 만들자
// 기존 강의실을 전부 확인하지 말고, 가장 빨리 끝나는 강의실만 확인하면 된다. 시간이 겹친다면, 나머지 강의실들도 무조건 겹치기 때문에 바로 새로운 강의실을 만들면 된다
// 우선순위 큐가 heap 기반으로 만들어진다는 사실을 되새겨보는 시간이 되었다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
priority_queue<int, vector<int>, greater<int>> v;
int result;

int main(void) {
  FASTIO;
  int a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    pq.push({a, b});
  }

  int c, d;
  while (!pq.empty()) {
    c = pq.top().first, d = pq.top().second;

    if (!v.empty() && c >= v.top()) {
      v.pop();
      v.push(d);
    } else {
      v.push(d);
    }
    pq.pop();
  }

  result = v.size();
  cout << result;
  return 0;
}
