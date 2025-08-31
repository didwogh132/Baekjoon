#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main() {
	double n;
	double arr[1010];
	double m = 0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > m) {
			m = arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		arr[i] = (arr[i] / m) * 100;
		sum += arr[i];
	}
	cout << sum / n;

	return 0;
}