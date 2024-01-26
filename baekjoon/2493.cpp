// 도달 가능한 탑의 (높이, 인덱스) 목록을 이진 탐색 트리로 관리
// iteration할 때마다 현재 탑 높이 이상인 탑 중 가장 작은 것의 인덱스를 조회, 현재 탑 높이 이하의 기존 탑들을 트리에서 제거
// iteration마다 이진 탐색 트리에 삽입하므로 O(NlogN)
// ✨ 개선할 수 있는 부분: 스택을 사용하면 O(N)으로 줄일 수 있다. Monotonic Stack이라고 부르는 모양
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N, height;
    cin >> N;

    map<int, int> heights; // (height, index)
    vector<int> res;
    std::map<int, int>::iterator it;
    for (int i = 1; i <= N; i++) {
        cin >> height;
        it = heights.lower_bound(height);
        if (it != heights.end()) {
            res.push_back(it->second);
        } else {
            res.push_back(0);
        }
        
        if (!heights.empty()) {
            for (auto it = heights.begin(); it != heights.end(); ) {
                if (it->first <= height) {
                    it = heights.erase(it);
                } else {
                    break;
                }
            }
        }

        heights[height] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << ' ';
    }
    
    return 0;
}
