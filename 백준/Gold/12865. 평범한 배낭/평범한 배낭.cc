#include <iostream>
#include <memory.h>

using namespace std;

int dp[101][100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int weight[101];
    int value[101];

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> weight[i] >> value[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
        }

        for (int j = weight[i]; j <= k; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout << dp[n][k];

    return 0;
}