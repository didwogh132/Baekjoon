#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int num[9];
int used[10001];
int path[9];


void func(int now) {
	if (now >= m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[num[i]] == 1) continue;
		if (now > 0 && path[now - 1] > num[i]) continue;

		used[num[i]] = 1;
		path[now] = num[i];
		func(now + 1);
		used[num[i]] = 0;
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