#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int d, k;
	int dp[31];
	memset(dp, 0, sizeof(dp));

	cin >> d >> k;
	dp[d] = k;
	int ans_a, ans_b;
	bool flag = false;
	for (int a = 1; a <= k; a++) {
		dp[1] = a;
		for (int b = 1; b <= k; b++) {
			dp[2] = b;
			for (int i = 3; i <= d; i++) {
				if (i == d) {
					if (dp[i - 1] + dp[i - 2] == dp[i]) {
						ans_a = a;
						ans_b = b;
						flag = true;
						break;
					}
				}
				else {
					dp[i] = dp[i - 1] + dp[i - 2];
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}

	cout << ans_a << "\n" << ans_b;

	return 0;
}