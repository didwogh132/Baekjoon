#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int ans[11];
int n;


void func(int now) {
	if (n == 1) return;
	if (n == 2) return;
	if (n == 3) return;
	for (int i = 4; i <=n; i++) {
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
	}
}

int main() {
	int T;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;

		func(n);
		cout << ans[n] << "\n";
	}

	return 0;
}