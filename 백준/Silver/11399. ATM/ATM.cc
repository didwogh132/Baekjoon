#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;


int main() {
	int n;
	int arr[1010] = {};
	int arr2[1010] = {};
	int sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	arr2[0] = arr[0];
	sum = arr2[0];
	for (int i = 1; i < n; i++) {
		arr2[i] = arr[i] + arr2[i - 1];
		sum += arr2[i];
	}
	cout << sum;
}