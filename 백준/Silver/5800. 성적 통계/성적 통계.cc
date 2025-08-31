#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	int arr[51];
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		int min, max, maxgap;
		min = 21e8;
		max = 0;
		maxgap = 0;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		min = arr[0];
		max = arr[n - 1];
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1] > maxgap) {
				maxgap = arr[i] - arr[i - 1];
			}
		}
		cout << "Class" << " " << tc << "\n";
		cout << "Max " << max << ", Min " << min << ", Largest gap " << maxgap << "\n";
	}

	return 0;
}