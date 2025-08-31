#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		int low = 0;
		int high = arr.size() - 1;
		while(low <= high){
			int mid = (low + high) / 2;
			if (target == arr[mid]) {
				cout << 1 << "\n";
				break;
			}

			if (target < arr[mid]) {
				high = mid -1;
			}
			else if (target > arr[mid]) {
				low = mid + 1;
			}
		}
		if (low > high) cout << 0 << "\n";
	}

	return 0;
}