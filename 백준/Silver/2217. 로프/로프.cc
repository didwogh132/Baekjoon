#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int cost;
		cin >> cost;
		arr.push_back(cost);
	}
	sort(arr.begin(), arr.end(), greater<>());

	int sum = 0;
	int cnt = 0;
	int num = 1;
	int Max = 0;
	while (true) {
		if (cnt >= arr.size()) break;
		sum = arr[cnt] * num;
		cnt++;
		num++;
		if (Max < sum) {
			Max = sum;
		}
	}
	cout << Max;
}