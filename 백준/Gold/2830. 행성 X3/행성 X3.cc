#include <iostream>
#include <cmath>

using namespace std;

int arr[1000000];
long long cnt1[30];
long long cnt0[30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	long long sum = 0;
	int Max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > Max) Max = arr[i];
	}
	for (int i = 0; i < n; i++) {
		int p = Max;
		int a = arr[i];
		int k = 0;
		while (a >= 0) {
			if (a % 2 == 0) {
				cnt0[k]++;
				k++;
			}
			else {
				cnt1[k]++;
				k++;
			}
			a >>= 1;
			p >>= 1;
			if (p == 0) break;
		}
	}

	for (int i = 0; cnt1[i] != 0 || cnt0[i] != 0; i++) {
		sum += (1LL << i) * cnt1[i] * cnt0[i];
	}
	cout << sum;
	return 0;
}