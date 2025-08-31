#include <iostream>
#include <bitset>

using namespace std;

int main() {
	int arr[25] = { 1 };
	for (int i = 1; i < 25; i++) {
		arr[i] = arr[i - 1] * 2;
	}
	int n;
	cin >> n;
	bitset<32> bits(n);
	int num = 0;
	for (int i = 0; i < 25; i++) {
		if (n < arr[i]) {
			num = i;
			break;
		}
		else if (n == arr[i]) {
			num = i;
			break;
		}
	}
	int size = arr[num];
	int result = 0;
	int cnt = 0;
	while (size > 0) {
		if (size > n) {
			size /= 2;
			cnt++;
		}
		else if (size <= n) {
			n -= size;
			result += cnt;
			cnt = 0;
		}
	}

	cout << arr[num] << " " << result;
	return 0;
}