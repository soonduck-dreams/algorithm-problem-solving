// 2293번 문제와 동일한 발상을 이용하는 dp
#include <iostream>
#include <vector>
using namespace std;
#define INF 2e4

int n, k;
int candidate;

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> k;
    vector<int> v(n + 1, 0);
    vector<int> dp(k + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= k; j++) {
            candidate = dp[j - v[i]] != INF ? dp[j - v[i]] + 1 : INF;
            dp[j] = dp[j] < candidate ? dp[j] : candidate;
        }
    }

    cout << (dp[k] != INF ? dp[k] : -1);
    
    return 0;
}
