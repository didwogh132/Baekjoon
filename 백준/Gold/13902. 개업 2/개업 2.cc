#include <iostream>
#include <memory.h>

using namespace std;

int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int size[1001];
    bool cook[10001];

    memset(dp, 0x7f, sizeof(dp));
    memset(cook, false, sizeof(cook));

    cin >> n >> m;

    for (int i = 1; i <= m; i++) cin >> size[i];

    for (int i = 1; i <= m; i++) {
        if (size[i] <= n) cook[size[i]] = true;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int x = size[i] + size[j];
            if (x <= n) cook[x] = true;
        }
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (!cook[i]) continue;
        for (int j = i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i] + 1);
        }
    }

    if (dp[n] == 0x7f7f7f7f) {
        cout << -1;
    }
    else {
        cout << dp[n];
    }

    return 0;
}