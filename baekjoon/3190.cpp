// Queue로 뱀을 구현한다는 아이디어를 떠올린 다음엔 쉽게 풀린다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum TYPE { BLANK, ME, APPLE };

int n, k, l;
vector<vector<int>> board;
queue<pair<int, int>> snake; // front가 꼬리, back이 머리

int direction = 0;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

vector<pair<int, char>> control;
int cp = 0; // control pointer

int result;

int main(void) {
  FASTIO;
  int a, b;
  char c;

  cin >> n >> k;
  board.resize(n, vector<int>(n, BLANK));
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    board[a - 1][b - 1] = APPLE;
  }

  cin >> l;
  for (int i = 0; i < l; i++) {
    cin >> a >> c;
    control.push_back({a, c});
  }

  pair<int, int> head;
  board[0][0] = ME;
  snake.push({0, 0});
  for (result = 1;; result++) {
    head = {snake.back().first + dy[direction],
            snake.back().second + dx[direction]};

    if (head.first < 0 || head.first >= n || head.second < 0 ||
        head.second >= n || board[head.first][head.second] == ME) {
      break;
    }

    if (board[head.first][head.second] == BLANK) {
      board[snake.front().first][snake.front().second] = BLANK;
      snake.pop();
    }

    board[head.first][head.second] = ME;
    snake.push(head);

    if (cp < control.size() && control[cp].first == result) {
      direction = (direction + (control[cp].second == 'L' ? -1 : 1) + 4) % 4;
      cp++;
    }
  }

  cout << result;

  return 0;
}
