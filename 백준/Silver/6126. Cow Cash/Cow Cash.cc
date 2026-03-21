#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, n;
    cin >> v >> n;

    int coin[26];
    long long dp[10010];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= v; i++) cin >> coin[i];

    dp[0] = 1;

    for (int i = 1; i <= v; i++) {
        for (int j = coin[i]; j <= n; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[n];

    return 0;
}