// Try #1: DFS로 풀었다가 시간 초과. DP였구나~
// Try #2: 나름 생각한 2xk 배열 DP로 통과
// Try #3: 알고 보니 1d 배열로 훨씬 단순하고 효율적으로 푸는 방법이 있었다 🤯

#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> k;

    vector<int> dp(k + 1, 0);
    vector<int> v(n, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[k];
    
    return 0;
}
