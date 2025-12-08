#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, n;
    cin >> h >> n;
    int kg[505];
    int dp[45010];
    fill(dp, dp + h + 1, INT_MAX);

    for (int i = 1; i <= n; i++) cin >> kg[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = h; j >= kg[i]; j--) {
            if (dp[j - kg[i]] == INT_MAX) continue;

            if (dp[j] == INT_MAX) {
                dp[j] = dp[j - kg[i]] + 1;
            }
            else {
                dp[j] = max(dp[j], dp[j - kg[i]] + 1);
            }
        }
    }

    for (int i = h; i >= 0; i--) {
        if (dp[i] != INT_MAX) {
            cout << i;
            break;
        }
    }

    return 0;
}