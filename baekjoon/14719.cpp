// 바닥에서부터 올라가면서 체크하면 된다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <iostream>
#include <vector>

using namespace std;

int h, w;
vector<int> v;

int main(void) {
  FASTIO;

  cin >> h >> w;
  v.resize(w);

  for (int i = 0; i < w; i++) {
    cin >> v[i];
  }

  int result = 0;
  int last;
  for (int i = 1; i <= h; i++) {
    last = -1; // -1 means invalid
    for (int j = 0; j < w; j++) {
      if (v[j] >= i) {
        result += (last >= 0) ? j - last - 1 : 0;
        last = j;
      }
    }
  }

  cout << result;

  return 0;
}
