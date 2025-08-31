#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int used[9];
int path[9];
int num[9];

void func(int now) {
	if (now >= m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == 1) continue;

		used[i] = 1;
		path[now] = num[i-1];
		func(now + 1);
		used[i] = 0;
		path[now] = 0;
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);

	func(0);

	return 0;
}