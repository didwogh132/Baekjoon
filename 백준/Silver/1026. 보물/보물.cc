#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


int main() {
	int arr[51] = {};
	int arr2[51] = {};
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	sort(arr, arr + n);
	sort(arr2, arr2 + n, greater<>());

	for (int i = 0; i < n; i++) {
		sum += arr[i] * arr2[i];
	}
	cout << sum;

	return 0;
}