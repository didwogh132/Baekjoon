#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, s;
int arr[21];
int visited[21];
int path[21];
int cnt;
int sum;

void func(int now, int sum) {
	if (now == n) {
		if (sum == s) cnt++;
		return;
	}

	func(now + 1, sum + arr[now]);

	func(now + 1, sum);
}

int main() {
	
	cin >> n >> s;


	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0, 0);
	if (s == 0) cnt--;

	cout << cnt;
	return 0;
}