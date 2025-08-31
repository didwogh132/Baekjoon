#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int arr[9];
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
		if (now > 0 && arr[i] < path[now - 1]) continue;
		path[now] = arr[i];
		func(now + 1);
		path[now] = 0;
	}
}

int main() {
	
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	func(0);


	return 0;
}