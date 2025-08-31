#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

int n;
int arr[8];
int used[8];
int Max;
int sum;

void func(int num, int next) {
	if (num >= n -1) {
		if (sum > Max) {
			Max = sum;
		}
		return;
	}

	for (int j = 0; j < n; j++) {
		if (used[j] == 1) continue;
		used[j] = 1;
		sum += abs(arr[next] - arr[j]);
		func(num + 1, j);
		used[j] = 0;
		sum -= abs(arr[next] - arr[j]);
	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		used[i] = 1;
		func(0, i);
		used[i] = 0;
	}

	cout << Max;
	return 0;
}