#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        int coin[21];
        int dp[21][10010];
        memset(dp, 0, sizeof(dp));
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> coin[i];

        cin >> m;

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
            }

            for (int j = coin[i]; j <= m; j++) {
                dp[i][j] += dp[i][j - coin[i]];
            }
        }

        cout << dp[n][m] << "\n";
    }
    return 0;
}