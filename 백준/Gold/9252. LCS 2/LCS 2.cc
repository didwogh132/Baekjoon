#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i -1] == b[j -1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int x = a.size();
	int y = b.size();

	int i = x;
	int j = y;
	string ans = "";

	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--;
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else {
			j--;
		}
	}

	cout << dp[x][y] << "\n";

	for (i = ans.size() -1; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}