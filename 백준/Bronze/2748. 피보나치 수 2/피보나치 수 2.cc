#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	vector<long long> arr;
	long long num0 = 0;
	long long num1 = 1;
	arr.push_back(num0);
	arr.push_back(num1);
	for (int i = 2; i <= 90; i++) {
		long long num = arr[i - 1] + arr[i - 2];
		arr.push_back(num);
	}
	cin >> n;

	cout << arr[n];
	return 0;
}