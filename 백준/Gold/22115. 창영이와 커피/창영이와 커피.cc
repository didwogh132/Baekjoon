#include <iostream>
#include <memory.h>

using namespace std;

int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int caffeine[101];

    cin >> n >> k;
    memset(dp, 0x7f, sizeof(dp));

    for (int i = 1; i <= n; i++) cin >> caffeine[i];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= caffeine[i]; j--) {
            if (dp[j - caffeine[i]] == 0x7f7f7f7f) continue;

            dp[j] = min(dp[j], dp[j - caffeine[i]] + 1);
        }
    }

    if (dp[k] == 0x7f7f7f7f) {
        cout << -1;
    }
    else {
        cout << dp[k];
    }

    return 0;
}