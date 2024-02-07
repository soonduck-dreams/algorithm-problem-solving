// 스택 이용하기
#include <iostream>
#include <vector>
using namespace std;

#define ROUND -1
#define SQUARE -2

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  string s;
  vector<int> v;
  cin >> s;

  int tmp, top, result;
  bool isValid = true;

  for (const auto &c : s) {
    switch (c) {
    case '(':
      v.push_back(ROUND);
      break;

    case '[':
      v.push_back(SQUARE);
      break;

    case ')':
      tmp = 0;
      while (!v.empty()) {
        top = v.back();
        if (top == ROUND) {
          tmp = tmp ? tmp : 1;
          v.pop_back();
          v.push_back(2 * tmp);
          break;
        } else if (top != SQUARE) {
          tmp += top;
          v.pop_back();
        } else {
          isValid = false;
          break;
        }
      }
      isValid = (int)!v.empty();
      break;

    case ']':
      tmp = 0;
      while (!v.empty()) {
        top = v.back();
        if (top == SQUARE) {
          tmp = tmp ? tmp : 1;
          v.pop_back();
          v.push_back(3 * tmp);
          break;
        } else if (top != ROUND) {
          tmp += top;
          v.pop_back();
        } else {
          isValid = false;
          break;
        }
      }
      isValid = (int)!v.empty();
      break;
    }

    if (!isValid) {
      break;
    }
  }

  if (isValid) {
    result = 0;
    for (const auto &elem : v) {
      if (elem != ROUND && elem != SQUARE) {
        result += elem;
      } else {
        result = 0;
        break;
      }
    }
  } else {
    result = 0;
  }

  cout << result;

  return 0;
}
