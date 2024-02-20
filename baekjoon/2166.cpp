// 기하학 문제. 각 점의 좌표가 주어졌을 때, 볼록다각형이나 오목다각형의 넓이를 구할 수 있는 신발끈 공식(shoelace formula)이란 걸 배웠다
#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<long long, long long>> v;
double result = 0;

int main(void) {
  FASTIO;

  cin >> n;
  v.resize(n);

  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v[i] = {a, b};
  }

  long long pre_result = 0;
  for (int i = 0; i < n - 1; i++) {
    pre_result += v[i].first * v[i + 1].second - v[i].second * v[i + 1].first;
  }
  pre_result += v[n - 1].first * v[0].second - v[n - 1].second * v[0].first;

  result = (double)abs(pre_result) / 2;
  cout << fixed << setprecision(1) << result;

  return 0;
}
