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
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int left = 0;
		int right = arr.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == num) {
				cout << "1 ";
				break;
			}
			if (arr[mid] < num) {
				left = mid + 1;
			}
			else if (arr[mid] > num) {
				right = mid - 1;
			}
		}
		if (left < right) {
			continue;
		}
		else if(left > right) {
			cout << "0 ";
		}
	}

	return 0;
}