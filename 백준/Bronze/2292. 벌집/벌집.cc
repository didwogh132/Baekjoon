#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	int arr[20000] = {1,};
	cin >> n;
	int num = 0;
	for (int i = 1; i < 20000; i++) {
		arr[i] = arr[i-1] + 6 * i;
	}
	for (int i = 0; i < 20000; i++) {
		if (arr[i] >= n) {
			num = i + 1;
			break;
		}
	}
	cout << num;

	return 0;
}