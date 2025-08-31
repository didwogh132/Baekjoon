#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;



bool cmp(string a, string b) {
	if (a < b) return true;
	if (a > b) return false;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<string> sorted_arr = arr;
	sort(sorted_arr.begin(), sorted_arr.end());
	if (arr == sorted_arr) {
		cout << "INCREASING";
	}
	else {
		sort(sorted_arr.begin(), sorted_arr.end(), greater<>());
		if (arr == sorted_arr) {
			cout << "DECREASING";
		}
		else {
			cout << "NEITHER";
		}
	}


	return 0;
}