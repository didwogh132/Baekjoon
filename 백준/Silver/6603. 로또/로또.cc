#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int k;
int arr[50];
int path[6];
int used[50];

void func(int now) {
	if (now >= 6) {
		for (int i = 0; i < 6; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++) {
		if (used[i] == 1) continue;
		if (now > 0 && path[now - 1] > arr[i]) continue;
		used[i] = 1;
		path[now] = arr[i];
		func(now + 1);
		used[i] = 0;
		path[now] = 0;
	}
}

int main() {
	
	
	while (cin >> k) {
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + k);

		func(0);

		cout << "\n";
	}
	return 0;
}