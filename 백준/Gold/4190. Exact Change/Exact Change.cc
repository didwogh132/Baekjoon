#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, m;
		cin >> n >> m;
		int cost[101];
		int dp[20001];
		for (int i = 1; i <= m; i++) cin >> cost[i];
		memset(dp, 0x7f, sizeof(dp));

		dp[0] = 0;
		for (int i = 1; i <= m; i++) {

			for (int j = 20000; j >= cost[i]; j--) {
				if (dp[j - cost[i]] == 0x7f7f7f7f) continue;
				dp[j] = (dp[j] > dp[j - cost[i]] + 1) ? dp[j - cost[i]] + 1 : dp[j];
			}
		}
		int ans = 0x7f7f7f7f;
		int ans_pay= 0;
		for (int i = n; i <= 20000; i++) {
			if (dp[i] != 0x7f7f7f7f) {
				ans = dp[i];
				ans_pay = i;
				break;
			}
		}

		cout << ans_pay << " " << ans << "\n";
	}
	return 0;
}