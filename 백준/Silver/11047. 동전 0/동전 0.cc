#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

bool cmp(int left, int right) {
	return left > right;
}

int main() {
	int n, k;
	int arr[10];
	int cnt = 0;
	int x = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);


	while (k > 0) {
		if (k < arr[x]) {
			x++;
		}
		else {
			k = k - arr[x];
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}