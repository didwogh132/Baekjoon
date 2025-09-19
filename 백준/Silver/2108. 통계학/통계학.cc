#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[500010];
int used[8010];
int Max = -4010, Min = 4010;
int sum, avg, cnt_num;

int main() {
	cin >> n;

	int c = n / 2;

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		arr[i] = b;
		if (b > Max) Max = b;
		if (b < Min) Min = b;
		sum += b;
		used[b + 4000]++;
	}

	sort(arr, arr + n);

	avg = round((double)sum / n);

	int maxused = 0;
	int cnt = 0;
	int ans = 0;

	for (int i = 0; i <= 8000; i++) {
		if (used[i] > maxused) maxused = used[i];
	}

	for (int i = 0; i <= 8000; i++) {
		if (used[i] == maxused) {
			ans = i - 4000;
			cnt++;
			if (cnt == 2) break;
		}
	}
	

	cout << avg << "\n" << arr[c] << "\n" << ans << "\n" << Max - Min;

	return 0;
}