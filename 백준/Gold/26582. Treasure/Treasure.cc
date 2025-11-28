#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int n, iw;
		cin >> n >> iw;
		vector<int> value(n + 1, 0);
		vector<int> weight(n + 1, 0);
		vector<int> dp(iw + 1, 0);

		for (int i = 1; i <= n; i++) cin >> value[i] >> weight[i];

		for (int i = 1; i <= n; i++) {
			for (int j = iw; j >= weight[i]; j--) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}

		int ans = 0;
		for (int i = 1; i <= iw; i++) {
			ans = (dp[i] > ans) ? dp[i] : ans;
		}

		cout << ans << "\n";
	}
	return 0;
}