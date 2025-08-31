#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int arr[200010];
int arr2[200010];

int main() {
	int n, m;
	cin >> n >> m;
	memset(arr, -1, sizeof(arr));
	memset(arr2, -1, sizeof(arr2));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		int low, high, num;
		low = 0;
		high = n - 1;
		num = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (arr2[i] > arr[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		if (low < n && arr[low] == arr2[i]) {
			cout << low << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
	return 0;
}