#include <iostream>
#include <memory.h>

using namespace std;

int dp[101][10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;

    int time[101];
    int score[101];
    
    memset(dp, 0, sizeof(dp));

    cin >> n >> t;

    for (int i = 1; i <= n; i++) cin >> time[i] >> score[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
        }

        for (int j = time[i]; j <= t; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - time[i]] + score[i]);
        }
    }

    cout << dp[n][t];

    return 0;
}