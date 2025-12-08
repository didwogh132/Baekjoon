#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int cost[501];
    int happy[501];
    int dp[10001];

    for (int i = 1; i <= n; i++) cin >> cost[i] >> happy[i];

    fill(dp, dp + m + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = m; j >= cost[i]; j--) {
            if (dp[j - cost[i]] == INT_MAX) continue;

            if (dp[j] == INT_MAX) {
                dp[j] = dp[j - cost[i]] + happy[i];
            }
            else {
                dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (dp[i] != INT_MAX) {
            ans = (dp[i] > ans) ? dp[i] : ans;
        }
    }
    cout << ans;

    return 0;
}