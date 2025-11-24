#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int arr[1001];
	int dp[1001];
	int ans = 0;
	memset(dp, 0, sizeof(dp));

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		if (dp[i] == 0) {
			dp[i] = 1;
		}

		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(dp[i], ans);
	}

	cout << ans;

	return 0;
}