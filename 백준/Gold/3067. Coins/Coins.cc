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
		int arr[21];
		int dp[10001];

		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		cin >> m;

		for (int i = 1; i <= n; i++) {
			dp[arr[i]] = dp[arr[i]] + 1;
			for (int j = arr[i]; j <= m; j++) {
				dp[j] += dp[j - arr[i]];
			}
		}

		cout << dp[m] << "\n";
	}
	return 0;
}