#include <iostream>
#include <memory.h>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;

	long long BASE = 1000000000000000000LL; // 10^18
	long long high_dp[1001];
	long long low_dp[1001];

	memset(high_dp, 0, sizeof(high_dp));
	memset(low_dp, 0, sizeof(low_dp));

	cin >> n >> k;

	low_dp[0] = 1;
	for (int coin = 1; coin <= k; coin++) {
		for (int j = coin; j <= n; j++) {
			long long newLow = low_dp[j] + low_dp[j - coin];
			long long carry = newLow / BASE;
			newLow = newLow % BASE;

			long long newHigh = high_dp[j] + high_dp[j - coin] + carry;

			low_dp[j] = newLow;
			high_dp[j] = newHigh;
		}
	}

	if (high_dp[n] == 0) {
		cout << low_dp[n];
	}
	else {
		cout << high_dp[n];
		cout << setw(18) << setfill('0') << low_dp[n];

	}

	return 0;
}