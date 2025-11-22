#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, n;
    int dp[1110][21];
    int customer[21];
    int cost[21];
    memset(dp, 0x7f, sizeof(dp));
    cin >> c >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i] >> customer[i];
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c + 100; j++) {
            dp[j][i] = dp[j][i - 1];
        }

        for (int j = customer[i]; j <= c + 100; j++) {
            if (dp[j - customer[i]][i] + cost[i] < dp[j][i]) {
                dp[j][i] = dp[j - customer[i]][i] + cost[i];
            }
        }
    }

    int ans = 0x7f7f7f7f;

    for (int j = c; j <= c + 100; j++) {
        if (dp[j][n] < ans) {
            ans = dp[j][n];
        }
    }

    cout << ans;

    return 0;
}