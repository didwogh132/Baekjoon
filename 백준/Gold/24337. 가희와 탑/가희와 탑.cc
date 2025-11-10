#include <iostream>

using namespace std;

int n, a, b;
int arr[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> a >> b;

	int maxh = (a > b) ? a : b;

	if ((a + b - 1) > n) {
		cout << -1;
		return 0;
	}

	for (int i = 1; i < a; i++) {
		arr[i] = arr[i - 1] + 1;
	}
	for (int i = a + b - 3; i >= a - 1; i--) {
		arr[i] = arr[i + 1] + 1;
	}
	arr[a - 1] = maxh - 1;

	if (!arr[0]) {
		for (int i = 0; i < n - (a + b - 1); i++) {
			cout << 1 << " ";
		}
	}

	for (int i = 0; i < a; i++) {
		cout << arr[i] + 1 << " ";
	}

	if (arr[0]) {
		for (int i = 0; i < n - (a + b - 1); i++) {
			cout << 1 << " ";
		}
	}

	for (int i = a; i < a + b - 1; i++) {
		cout << arr[i] + 1 << " ";
	}

	return 0;
}