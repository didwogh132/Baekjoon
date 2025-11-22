#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, n;
    int height[351];
    int speed[351];
    int dp[100010];
    memset(dp, 0, sizeof(dp));
    dp[0] = 100001;
    cin >> h >> n;

    for (int i = 1; i <= n; i++) cin >> height[i] >> speed[i];

    for (int i = 1; i <= n; i++) {
        for (int j = h; j >= height[i]; j--) {
            if (dp[j - height[i]] == 0) continue;

            int cand = (dp[j - height[i]] > speed[i]) ? speed[i] : dp[j - height[i]];
            if (dp[j] < cand) dp[j] = cand;
        }
    }

    cout << dp[h];

    return 0;
}