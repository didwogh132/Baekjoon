#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n;
int arr[300001];
int sum;

int main() {
	
	
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int s = round(0.15 * n);
	for (int i = s; i < n - s; i++) {
		sum += arr[i];
	}
	int cnt = n - (2 * s);
	int ans = round((double)sum / cnt);

	cout << ans;
	return 0;
}