#include <iostream>
#include <memory.h>

using namespace std;

int dp[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    int day[1010];
    int pay[1010];

    cin >> n >> t;
    int pay_max = 0;
    for (int i = 1; i <= n; i++) {
        cin >> day[i] >> pay[i];
        pay_max += pay[i];
    }

    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + t + 1, pay_max);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
        }

        for (int j = day[i]; j <= t; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - day[i]] - pay[i]);
        }
    }
    int ans = pay_max;
    for (int i = 0; i <= t; i++) {
        if (dp[n][i] < ans) ans = dp[n][i];
    }

    cout << ans;

    return 0;
}