// DFS 브루트포스로 해결
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, k, result;
string s;

vector<set<char>> words;
map<char, bool> is_choosing;
int candidate_size, choice_limit;

bool is_antic(const char &c) {
  return c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c';
}

void DFS(int level, char c) {
  bool is_success;
  int local_result = 0;
  is_choosing[c] = true;
  if (level >= choice_limit) {
    if (level > choice_limit) { // edge case: K = 5일 때 a, n, t, i, c 이외의
                                // 글자가 포함된 단어가 존재할 경우
      is_choosing[c] = false;
    }
    for (const auto &w : words) {
      is_success = true;
      for (const auto &c : w) {
        if (!is_choosing[c]) {
          is_success = false;
          break;
        }
      }
      if (is_success) {
        local_result++;
      }
    }
    result = local_result > result ? local_result : result;
    is_choosing[c] = false;
    return;
  }

  for (auto it = ++is_choosing.find(c); it != is_choosing.end(); ++it) {
    DFS(level + 1, it->first);
  }

  is_choosing[c] = false;
}

int main() {
  FASTIO;

  cin >> n >> k;
  words.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> s;
    for (const auto &c : s) {
      if (!is_antic(c)) {
        words[i].insert(c);
        is_choosing[c] = false;
      }
    }
  }

  if (k < 5) {
    cout << 0;
    return 0;
  }

  candidate_size = is_choosing.size();
  choice_limit = k - 5;
  if (choice_limit >= candidate_size) {
    cout << n;
    return 0;
  }

  result = 0;
  for (auto it = is_choosing.begin(); it != is_choosing.end(); ++it) {
    DFS(1, it->first);
  }

  cout << result;

  return 0;
}
