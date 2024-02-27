// 스도쿠 문제~ 백트래킹~
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> targets;
bool is_done = false;

bool row[9][10]{}, col[9][10]{},
    sqr[9][10]{}; // n번째 row, col, square에 숫자 m이 들어가 있나요?

bool is_okay(int target, int input) {
  return !row[targets[target].first][input] &&
         !col[targets[target].second][input] &&
         !sqr[(targets[target].first / 3) * 3 + (targets[target].second / 3)]
             [input];
}

void memo(int y, int x, int input) {
  row[y][input] = true;
  col[x][input] = true;
  sqr[(y / 3) * 3 + (x / 3)][input] = true;
}

void unmemo(int y, int x, int input) {
  row[y][input] = false;
  col[x][input] = false;
  sqr[(y / 3) * 3 + (x / 3)][input] = false;
}

void DFS(int target, int input) {
  if (target == targets.size() - 1) {
    is_done = true;
    return;
  }

  for (int i = 1; i <= 9; i++) {
    if (is_okay(target + 1, i)) {
      board[targets[target + 1].first][targets[target + 1].second] = i;
      memo(targets[target + 1].first, targets[target + 1].second, i);
      DFS(target + 1, i);

      if (is_done) {
        return;
      }

      board[targets[target + 1].first][targets[target + 1].second] = 0;
      unmemo(targets[target + 1].first, targets[target + 1].second, i);
    }
  }
}

int main() {
  FASTIO;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) {
        targets.push_back({i, j});
      } else {
        memo(i, j, board[i][j]);
      }
    }
  }

  for (int i = 1; i <= 9; i++) {
    if (is_okay(0, i)) {
      board[targets[0].first][targets[0].second] = i;
      memo(targets[0].first, targets[0].second, i);
      DFS(0, i);

      if (is_done) {
        break;
      }

      board[targets[0].first][targets[0].second] = 0;
      unmemo(targets[0].first, targets[0].second, i);
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
