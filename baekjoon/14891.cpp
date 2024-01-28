// 문제 내용대로 충실히 구현하면 됨
// top[i]: (i + 1)번째 톱니바퀴의 현재 12시 방향에 위치한 톱니 번호 (톱니 번호는 맨 처음 12시 방향에 있던 것을 시작으로 0 ~ 7 부여)
#include <iostream>
#include <vector>
using namespace std;
#define RIGHT(x) (((x) + 2) % 8)
#define LEFT(x) (((x) - 2 + 8) % 8)

bool wheels[4][8];
int top[4] = { 0 };
bool isVisited[4] = { false };

void spinWheel(int wheel, int spin) {
    isVisited[wheel] = true;
    if (wheel > 0 &&
        !isVisited[wheel - 1] &&
        (wheels[wheel][LEFT(top[wheel])] != wheels[wheel - 1][RIGHT(top[wheel - 1])])) {
        spinWheel(wheel - 1, -spin);
    }
    if (wheel < 3 &&
        !isVisited[wheel + 1] &&
        (wheels[wheel][RIGHT(top[wheel])] != wheels[wheel + 1][LEFT(top[wheel + 1])])) {
        spinWheel(wheel + 1, -spin);
    }

    top[wheel] = (top[wheel] - spin + 8) % 8;
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = s[j] - '0';
        }
    }

    int cmdCount, wheel, spin;
    cin >> cmdCount;
    for (int i = 0; i < cmdCount; i++) {
        cin >> wheel >> spin;
        spinWheel(wheel - 1, spin);
        for (int i = 0; i < 4; i++) {
            isVisited[i] = false;
        }
    }

    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += wheels[i][top[i]] << i;
    }
    cout << result;
    
    return 0;
}
