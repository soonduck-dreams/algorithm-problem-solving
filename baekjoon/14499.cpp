// 연결 리스트로 주사위 전개도를 구현하고, 굴러가는 방향에 따라 전개도가 어떻게 변화하는지에 유의하자
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n, m, x, y, k;
vector<vector<int>> v;
vector<int> cmd;

list<int> four, three;

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

void moveDice(const int &dir) {
  switch (dir) {
  case 1:
    three.push_front(four.back());
    four.pop_back();
    four.push_back(three.back());
    three.pop_back();
    break;
  case 2:
    three.push_back(four.back());
    four.pop_back();
    four.push_back(three.front());
    three.pop_front();
    break;
  case 3:
    four.push_back(four.front());
    four.pop_front();
    break;
  case 4:
    four.push_front(four.back());
    four.pop_back();
    break;
  }

  list<int>::iterator it1 = (dir <= 2) ? ++three.begin() : ++four.begin();
  list<int>::iterator it2 = (dir <= 2) ? ++four.begin() : ++three.begin();
  *it2 = *it1;
}

int main() {
  FASTIO;
  cin >> n >> m >> x >> y >> k;
  v.resize(n, vector<int>(m));
  cmd.resize(k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> cmd[i];
  }

  for (int i = 0; i < 4; i++) {
    four.push_back(0);
  }
  for (int i = 0; i < 3; i++) {
    three.push_back(0);
  }

  for (int i = 0; i < k; i++) {
    if (x + dx[cmd[i] - 1] >= 0 && x + dx[cmd[i] - 1] < n &&
        y + dy[cmd[i] - 1] >= 0 && y + dy[cmd[i] - 1] < m) {
      x += dx[cmd[i] - 1];
      y += dy[cmd[i] - 1];
      moveDice(cmd[i]);

      if (v[x][y] == 0) {
        v[x][y] = four.back();
      } else {
        *(--four.end()) = v[x][y];
        v[x][y] = 0;
      }

      cout << *(++four.begin()) << '\n';
    }
  }

  return 0;
}
