#include <iostream>
#include <memory.h>

using namespace std;

int dp[1001][10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int value[1001];
    int time[1001];
    memset(dp, 0, sizeof(dp));

    cin >> n >> k;

    for (int i = 1; i <= k; i++) cin >> value[i] >> time[i];

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
        }

        for (int j = time[i]; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - time[i]] + value[i]);
        }
    }

    cout << dp[k][n];

    return 0;
}