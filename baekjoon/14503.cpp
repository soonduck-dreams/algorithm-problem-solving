// 주어진 문제 설명을 그대로 구현하면 된다. 알고리즘 분류가 "시뮬레이션"...?

#include <iostream>
#include <vector>
using namespace std;

// TO GET POSITION IN FRONT OF ME (MULTIPLY -1 FOR THE ONE BEHIND ME)
int dfr[4] = {-1, 0, 1, 0}, dfc[4] = {0, 1, 0, -1};

enum Area {
    DIRTY,
    WALL,
    CLEAN
};

int N, M, r, c, d;
int res = 0;
bool isRunning = true;

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
bool isCleanAround(const vector<vector<int>>& S, const int& r, const int& c) {
    for (int i = 0; i < 4; i++) {
        if (S[r + dr[i]][c + dc[i]] == Area::DIRTY) {
            return false;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> M >> r >> c >> d;

    vector<vector<int>> S(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> S[i][j];
        }
    }

    
    while (isRunning) {
        if (S[r][c] == Area::DIRTY) {
            S[r][c] = Area::CLEAN;
            res++;
        }

        if (isCleanAround(S, r, c)) {
            if (S[r - dfr[d]][c - dfc[d]] != Area::WALL) {
                r -= dfr[d];
                c -= dfc[d];
            } else {
                isRunning = false;
            }
        } else {
            d = (d - 1 + 4) % 4;
            if (S[r + dfr[d]][c + dfc[d]] == Area::DIRTY) {
                r += dfr[d];
                c += dfc[d];
            }
        }
    }

    cout << res;
    
    return 0;
}
