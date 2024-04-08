// 스도쿠 문제. 백트래킹으로 해결하면 된다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>
using namespace std;

#define BLOCK(i, j) (3 * ((i) / 3) + ((j) / 3))

int sudoku[9][9];
bool is_in_row[9][10] = {}, is_in_col[9][10] = {}, is_in_blk[9][10] = {};
string s;
bool is_done;

void setTarget(const pair<int, int> target, int v, bool b) {
  is_in_row[target.first][v] = b;
  is_in_col[target.second][v] = b;
  is_in_blk[BLOCK(target.first, target.second)][v] = b;
}

void DFS(const pair<int, int> &target, int v) {
  if (is_in_row[target.first][v] || is_in_col[target.second][v] ||
      is_in_blk[BLOCK(target.first, target.second)][v]) {
    return;
  }

  sudoku[target.first][target.second] = v;
  setTarget(target, v, true);

  pair<int, int> next_target = {-1, -1};
  for (int i = target.first; i < 9; i++) {
    for (int j = (i == target.first ? target.second + 1 : 0); j < 9; j++) {
      if (sudoku[i][j] == 0) {
        next_target = {i, j};
        break;
      }
    }
    if (next_target.first >= 0) {
      break;
    }
  }

  if (next_target.first < 0) {
    is_done = true;
    return;
  } // 스도쿠 풀이를 완료하여 모든 재귀 함수를 종료

  for (int i = 1; !is_done && i <= 9; i++) {
    DFS(next_target, i);
  }

  if (!is_done) {
    setTarget(target, sudoku[target.first][target.second], false);
    sudoku[target.first][target.second] = 0;
  }
}

int main() {
  FASTIO;

  for (int i = 0; i < 9; i++) {
    cin >> s;
    for (int j = 0; j < 9; j++) {
      sudoku[i][j] = s[j] - '0';
      if (sudoku[i][j] > 0) {
        setTarget({i, j}, sudoku[i][j], true);
      }
    }
  }

  pair<int, int> target = {-1, -1};
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (sudoku[i][j] == 0) {
        target = {i, j};
        break;
      }
    }
    if (target.first >= 0) {
      break;
    }
  }

  if (target.first < 0) {
    is_done = true;
  } // 입력으로 이미 완성된 스도쿠가 들어온 경우

  for (int i = 1; !is_done && i <= 9; i++) {
    DFS(target, i);
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << sudoku[i][j];
    }
    cout << '\n';
  }

  return 0;
}
