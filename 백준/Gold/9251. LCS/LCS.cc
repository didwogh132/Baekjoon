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

	cout << dp[x][y];

	return 0;
}