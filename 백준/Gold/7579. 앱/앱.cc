#include <iostream>
#include <memory.h>

using namespace std;

int dp[10105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int memory[101];
    int cost[101];
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    int max_memory = 0;
    int max_cost = 0;
    for (int i = 1; i <= n; i++) {
        cin >> memory[i];
        max_memory += memory[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        max_cost += cost[i];
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = max_cost; j >= cost[i]; j--) {
            if (dp[j] < dp[j - cost[i]] + memory[i]) {
                dp[j] = dp[j - cost[i]] + memory[i];
            }
        }
    }

    int ans = max_cost;

    for (int i = 0; i <= max_cost; i++) {
        if (dp[i] >= m) {
            ans = i;
            break;
        }
    }
    cout << ans;

    return 0;
}